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

#ifndef TG_MOVE_GRAPH_H
#define TG_MOVE_GRAPH_H

#include "tg_types.h"
#include <vector>
#include <ostream>

//!
//! \brief The GraphItem class node of possible movement graph
//!
class GraphItem
{
public:
    GraphItem();
    ~GraphItem() = default;

    //!
    //! \brief GetNeigbour Gives the next node at cpecific direction
    //! \param at direction
    //! \return cell coordinates where ball would be if go to specified direction
    //!
    const coordinates_t & GetNeigbour(Direction at) const;

    //!
    //! \brief GetHolesOnWayTo Between node and its neighbour can be holes
    //! and ball can fall there
    //! \param to direction
    //! \return vector of holes between node and its neigbour
    //!
    const std::vector <coordinates_t> & GetHolesOnWayTo (Direction to) const;

    //!
    //! \brief AddNeighbour adds node as a neigbour on specific direction
    //! \param at direction
    //! \param cell neighbour cell address
    //!
    void AddNeighbour (Direction at, coordinates_t cell);

    //!
    //! \brief AddHole adds hole between node and its neighbour on specific direction
    //! \param at direction
    //! \param cell hole cell address
    //!
    void AddHole      (Direction at, coordinates_t cell);

private:
    //! \brief neighbour_north_ Northen neigbour
    coordinates_t neighbour_north_;

    //! \brief neighbour_north_ Western neigbour
    coordinates_t neighbour_west_;

    //! \brief neighbour_north_ Southen neigbour
    coordinates_t neighbour_south_;

    //! \brief neighbour_north_ Easten neigbour
    coordinates_t neighbour_east_;


    //! \brief holes on way north between node and its neigbour
    std::vector<coordinates_t> holes_north_;

    //! \brief holes on way west between node and its neigbour
    std::vector<coordinates_t> holes_west_;

    //! \brief holes on way south between node and its neigbour
    std::vector<coordinates_t> holes_south_;

    //! \brief holes on way east between node and its neigbour
    std::vector<coordinates_t> holes_east_;

    //! dummy data to keep compiller happy
    const coordinates_t invalid_coordinates_;

    //! dummy data to keep compiller happy
    const std::vector<coordinates_t> invalid_vector_;
};

std::ostream &
operator<< (std::ostream & os, const GraphItem & gi);

#endif //TG_MOVE_GRAPH_H
