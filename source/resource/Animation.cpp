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
#include "resource/Animation.h"
#include "BinReader.h"

enum AnimationFlags
{
    kHasPosFrames = 0x1,
    kHasHooks = 0x2
};

Animation::Animation(uint32_t id, const void* data, size_t size) : ResourceImpl{id}
{
    BinReader reader(data, size);

    uint32_t resourceId = reader.readInt();
    assert(resourceId == id);
    UNUSED(resourceId);

    uint32_t flags = reader.readInt();
    uint32_t numModels = reader.readInt();
    uint32_t numFrames = reader.readInt();

    if(flags & kHasPosFrames)
    {
        for(uint32_t i = 0; i < numFrames; i++)
        {
            Location posFrame;
            read(reader, posFrame);
        }
    }

    frames.resize(numFrames);

    for(AnimationFrame& frame : frames)
    {
        read(reader, frame, numModels);
    }

    assert(reader.remaining() == 0);
}
