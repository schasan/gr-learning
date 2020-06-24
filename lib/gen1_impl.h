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

#ifndef INCLUDED_MSZLEARNING_GEN1_IMPL_H
#define INCLUDED_MSZLEARNING_GEN1_IMPL_H

#include <mszlearning/gen1.h>
#include <volk/volk.h>

namespace gr {
  namespace mszlearning {

    class gen1_impl : public gen1
    {
     private:
      float m_i=0.0, m_q=0.0;
      static const int m_buffersize = 2000;

     public:
      gen1_impl(float in_i, float in_q);
      ~gen1_impl();
      void set_i(float i) { m_i = i; };
      void set_q(float q){ m_q = q; };

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace mszlearning
} // namespace gr

#endif /* INCLUDED_MSZLEARNING_GEN1_IMPL_H */

