/* -*- c++ -*- */

#define MSZLEARNING_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "mszlearning_swig_doc.i"

%{
#include "mszlearning/gen1.h"
%}

%include "mszlearning/gen1.h"
GR_SWIG_BLOCK_MAGIC2(mszlearning, gen1);
