/* -*- c++ -*- */
/*
 * Copyright 2020 Mario Schulz.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_MSZLEARNING_GEN1_H
#define INCLUDED_MSZLEARNING_GEN1_H

#include <mszlearning/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace mszlearning {

    /*!
     * \brief <+description of block+>
     * \ingroup mszlearning
     *
     */
    class MSZLEARNING_API gen1 : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<gen1> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of mszlearning::gen1.
       *
       * To avoid accidental use of raw pointers, mszlearning::gen1's
       * constructor is in a private implementation
       * class. mszlearning::gen1::make is the public interface for
       * creating new instances.
       */
      static sptr make(float in_i=0.3, float in_q=0.7);

      /*
       * GUI parameter interface
       */

      virtual void set_i(float i) = 0;
      virtual void set_q(float q) = 0;
    };

  } // namespace mszlearning
} // namespace gr

#endif /* INCLUDED_MSZLEARNING_GEN1_H */

