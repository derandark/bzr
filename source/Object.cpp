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
#include "Object.h"
#include "Camera.h"
#include "Core.h"
#include "LandcellManager.h"
#include "Log.h"
#include "ObjectManager.h"

Object::Object(ObjectId id) : id_(id)
{}

void Object::setProperty(BoolProperty property, bool value)
{
    //LOG(Misc, Debug) << " bool " << getBoolPropertyName(property) << " = " << (value ? "true" : "false") << "\n";
    boolProperties_[property] = value;
}

void Object::setProperty(StringProperty property, string value)
{
    //LOG(Misc, Debug) << " string " << getStringPropertyName(property) << " = " << value << "\n";
    stringProperties_[property] = value;
}

void Object::setProperty(IntProperty property, uint32_t value)
{
    //LOG(Misc, Debug) << " int " << getIntPropertyName(property) << " = " << value << "\n";
    intProperties_[property] = value;
}

void Object::setProperty(Int64Property property, uint64_t value)
{
    //LOG(Misc, Debug) << " int64 " << getInt64PropertyName(property) << " = " << value << "\n";
    int64Properties_[property] = value;
}

void Object::setProperty(FloatProperty property, double value)
{
    //LOG(Misc, Debug) << " float " << getFloatPropertyName(property) << " = " << value << "\n";
    floatProperties_[property] = value;
}

void Object::setProperty(PositionProperty property, Position value)
{
    //LOG(Misc, Debug) << " location " << getPositionPropertyName(property) << "\n";
    positionProperties_[property] = value;
}

void Object::setProperty(IIDProperty property, uint32_t value)
{
    //LOG(Misc, Debug) << " IID " << getIIDPropertyName(property) << " = " << hexn(value) << "\n";
    iidProperties_[property] = value;
}

void Object::setProperty(DIDProperty property, uint32_t value)
{
    //LOG(Misc, Debug) << " DID " << getDIDPropertyName(property) << " = " << hexn(value) << "\n";
    didProperties_[property] = value;
}

void Object::setModel(ResourcePtr model)
{
    model_ = model;
}

void Object::setLandcellId(const LandcellId& landcellId)
{
    if(id_ == Core::get().objectManager().playerId())
    {
        Core::get().landcellManager().setCenter(landcellId);
    }

    landcellId_ = landcellId;
}

void Object::setLocation(const Location& location)
{
    if(id_ == Core::get().objectManager().playerId())
    {
        Core::get().camera().setPosition(location.position);
    }

    location_ = location;
}

ObjectId Object::id() const
{
    return id_;
}

const ResourcePtr& Object::model() const
{
    return model_;
}

const LandcellId& Object::landcellId() const
{
    return landcellId_;
}

const Location& Object::location() const
{
    return location_;
}
