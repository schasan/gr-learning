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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "gen1_impl.h"

namespace gr {
  namespace mszlearning {

    gen1::sptr
    gen1::make(float in_i, float in_q)
    {
      return gnuradio::get_initial_sptr
        (new gen1_impl(in_i, in_q));
    }


    /*
     * The private constructor
     */
    gen1_impl::gen1_impl(float in_i, float in_q)
      : gr::sync_block("gen1",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(1, 1, sizeof(gr_complex)))
    {
        m_i = in_i;
        m_q = in_q;
        set_max_noutput_items(m_buffersize);
    }

    /*
     * Our virtual destructor.
     */
    gen1_impl::~gen1_impl()
    {
    }

    int
    gen1_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      gr_complex *out = (gr_complex *) output_items[0];
      float iv[m_buffersize], qv[m_buffersize];

      // Do <+signal processing+>
      for (int i=0; i < noutput_items; i++) {
          iv[i] = m_i;
          qv[i] = m_q;
      }
      volk_32f_x2_interleave_32fc(out, iv, qv, noutput_items);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }
  } /* namespace mszlearning */
} /* namespace gr */

