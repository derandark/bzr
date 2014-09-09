/*
 * Bael'Zharon's Respite
 * Copyright (C) 2014 Daniel Skorupski
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#include "physics/Space.h"
#include "physics/LineSegment.h"
#include <algorithm>

static const auto GRAVITY_ACCEL = fp_t(-9.81);
static const auto TERMINAL_VELOCITY = fp_t(-54.0);
static const auto REST_EPSILON = fp_t(0.002);

static fp_t getBoundValueX(ilist<Body>::iterator it)
{
    if(it.on_hook<BodyHooks::BeginX>())
    {
        return it->bounds().min.x;
    }
    
    if(it.on_hook<BodyHooks::EndX>())
    {
        return it->bounds().max.x;
    }
    
    assert(!"Iterator for X axis associated with unknown hook");
    return 0.0;
}

static fp_t getBoundValueY(ilist<Body>::iterator it)
{
    if(it.on_hook<BodyHooks::BeginY>())
    {
        return it->bounds().min.y;
    }

    if(it.on_hook<BodyHooks::EndY>())
    {
        return it->bounds().max.y;
    }

    assert(!"Iterator for Y axis associated with unknown hook");
    return 0.0;
}

static bool compareByX(ilist<Body>::iterator a, ilist<Body>::iterator b)
{
    auto aValue = a->location().offset.x + getBoundValueX(a);
    auto bValue = b->location().offset.x + getBoundValueX(b);
    auto blockDiff = static_cast<int>(b->location().landcell.x()) - static_cast<int>(a->location().landcell.x());
    return aValue < bValue + blockDiff * fp_t(192.0);
}

static bool compareByY(ilist<Body>::iterator a, ilist<Body>::iterator b)
{
    auto aValue = a->location().offset.y + getBoundValueY(a);
    auto bValue = b->location().offset.y + getBoundValueY(b);
    auto blockDiff = static_cast<int>(b->location().landcell.y()) - static_cast<int>(a->location().landcell.y());
    return aValue < bValue + blockDiff * fp_t(192.0);
}

template<class Compare>
static void insertionSort(ilist<Body>& container, ilist<Body>::iterator bodyIt, Compare comp)
{
    // a < b, compare(a, b)
    // a >= b, !compare(a, b)
    // a > b, compare(b, a)
    // a <= b, !compare(b, a)
    // FIXME make sure this is correct

    auto nextIt = container.erase(bodyIt);

    while(nextIt != container.end())
    {
        if(comp(nextIt, bodyIt))
        {
            --nextIt;
            break;
        }
    }

    while(nextIt != container.end() && !comp(nextIt, bodyIt)) // bodyIt <= nextIt
    {
        ++nextIt;
    }

    // now bodyIt > nextIt, one past bodyIt <= nextIt
    --nextIt;
    // now bodyIt <= nextIt

    //while(nextIt != container.begin() && ) // bodyIt > nextIt
    //{
    //    --nextIt;
    //}

    container.insert(nextIt, bodyIt);
}

Space::Space()
{}

void Space::step(fp_t dt)
{
    for(auto it = _activeList.begin(); it != _activeList.end(); ++it)
    {
        if(step(dt, *it))
        {
            ++it;
        }
        else
        {
            it = _activeList.erase(it);
        }
    }
}

void Space::insert(Body& body)
{
    _xAxisList.push_back(_xAxisList.iterator_for<BodyHooks::BeginX>(body));
    _xAxisList.push_back(_xAxisList.iterator_for<BodyHooks::EndX>(body));
    _yAxisList.push_back(_yAxisList.iterator_for<BodyHooks::BeginY>(body));
    _yAxisList.push_back(_yAxisList.iterator_for<BodyHooks::EndY>(body));

    if(!(body.flags() & BodyFlags::Static))
    {
        _activeList.push_back(_activeList.iterator_for<BodyHooks::Active>(body));
    }
    
    resort(body);
}

bool Space::step(fp_t dt, Body& body)
{
    if(body.flags() & BodyFlags::HasGravity)
    {
        auto velocity = body.velocity();

        velocity.z = max(velocity.z + GRAVITY_ACCEL * dt, TERMINAL_VELOCITY);

        body.setVelocity(velocity);
    }

    if(glm::length(body.velocity()) < REST_EPSILON)
    {
        body.setVelocity(glm::vec3());
        return false;
    }

    auto oldLocation = body.location();

    auto newLocation = body.location();
    newLocation.offset += body.velocity() * dt;

    body.setLocation(newLocation);
    resort(body);

    //auto beginXIt = decltype(_beginXList)::iterator(&body);

    //while(beginXIt != _beginXList.end())
    //{
        // exit condition
    //    ++beginXIt;
    //}

    //auto segment = LineSegment();
    //segment.begin = body.location().normalize();
    //segment.end = segment.begin + body.velocity() * dt;

    return true;
}

void Space::resort(Body& body)
{
    insertionSort(_xAxisList, _xAxisList.iterator_for<BodyHooks::BeginX>(body), compareByX);
    insertionSort(_xAxisList, _xAxisList.iterator_for<BodyHooks::EndX>(body), compareByX);
    insertionSort(_yAxisList, _yAxisList.iterator_for<BodyHooks::BeginY>(body), compareByY);
    insertionSort(_yAxisList, _yAxisList.iterator_for<BodyHooks::EndY>(body), compareByY);
}
