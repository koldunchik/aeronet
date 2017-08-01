/*
 * Copyright (c) 2017, Ivan
 * 
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of ofp-pfe nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef TG_CELL_OBJECT_H
#define TG_CELL_OBJECT_H

#include "tg_types.h"

#include <ostream>

//!
//! \brief The CellObject class Common cell type
//!
class CellObject
{
public:
    //!
    //! \brief The Type enum types of cells
    //!
    enum class Type
    {
        BoardCell,  //!< Board cell, can contain holes
        Ball        //!< Ball, can collide with other cell objects
    };

    //!
    //! \brief CellObject create cell with cpecific type
    //! \param t type of the objecct
    //!
    CellObject(Type t) : type_(t) {}
    ~CellObject() {}

    //!
    //! \brief GetType returns type of the object
    //! \return object type
    //!
    Type GetType() const { return type_; }

protected:
    //!
    //! \brief type_ Object type
    //!
    Type type_;
};

#endif // TG_CELL_OBJECT_H
