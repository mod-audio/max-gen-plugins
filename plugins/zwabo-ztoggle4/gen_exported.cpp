#include "gen_exported.h"

namespace gen_exported {

/*******************************************************************************************************************
Cycling '74 License for Max-Generated Code for Export
Copyright (c) 2016 Cycling '74
The code that Max generates automatically and that end users are capable of exporting and using, and any
  associated documentation files (the “Software”) is a work of authorship for which Cycling '74 is the author
  and owner for copyright purposes.  A license is hereby granted, free of charge, to any person obtaining a
  copy of the Software (“Licensee”) to use, copy, modify, merge, publish, and distribute copies of the Software,
  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The Software is licensed to Licensee only for non-commercial use. Users who wish to make commercial use of the
  Software must contact the copyright owner to determine if a license for commercial use is available, and the
  terms and conditions for same, which may include fees or royalties. For commercial use, please send inquiries
  to licensing (at) cycling74.com.  The determination of whether a use is commercial use or non-commercial use is based
  upon the use, not the user. The Software may be used by individuals, institutions, governments, corporations, or
  other business whether for-profit or non-profit so long as the use itself is not a commercialization of the
  materials or a use that generates or is intended to generate income, revenue, sales or profit.
The above copyright notice and this license shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.
*******************************************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Change __m_change_12;
	Delta __m_delta_4;
	int __exception;
	int vectorsize;
	t_sample __m_carry_7;
	t_sample m_diff_10;
	t_sample m_prev_9;
	t_sample __m_count_5;
	t_sample m_Cycle_3;
	t_sample m_val_11;
	t_sample m_Select_1;
	t_sample m_Killswitch_2;
	t_sample samplerate;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_Select_1 = 0;
		m_Killswitch_2 = 0;
		m_Cycle_3 = 2;
		__m_delta_4.reset(0);
		__m_count_5 = 0;
		__m_carry_7 = 0;
		m_prev_9 = ((int)0);
		m_diff_10 = ((int)0);
		m_val_11 = ((int)0);
		__m_change_12.reset(0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		t_sample * __out4 = __outs[3];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample add_1961 = (m_Cycle_3 + ((int)1));
		t_sample add_1949 = (m_Killswitch_2 + ((int)1));
		int neq_2398 = (m_Select_1 != ((int)1));
		t_sample rsr = safediv(((int)1), (((int)50) * (samplerate * 0.001)));
		t_sample choice_13 = int(add_1949);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			int delta_1964 = __m_delta_4(neq_2398);
			int lt_1963 = (delta_1964 < ((int)0));
			__m_count_5 = (((int)0) ? 0 : (fixdenorm(__m_count_5 + lt_1963)));
			int carry_6 = 0;
			if ((((int)0) != 0)) {
				__m_count_5 = 0;
				__m_carry_7 = 0;
				
			} else if (((add_1961 > 0) && (__m_count_5 >= add_1961))) {
				int wraps_8 = (__m_count_5 / add_1961);
				__m_carry_7 = (__m_carry_7 + wraps_8);
				__m_count_5 = (__m_count_5 - (wraps_8 * add_1961));
				carry_6 = 1;
				
			};
			int counter_1965 = __m_count_5;
			int counter_1966 = carry_6;
			int counter_1967 = __m_carry_7;
			int add_1962 = (counter_1965 + ((int)1));
			t_sample expr_2392 = ramp0_i_d(neq_2398, rsr);
			t_sample selector_1951 = ((choice_13 >= 2) ? expr_2392 : ((choice_13 >= 1) ? ((int)1) : 0));
			t_sample mul_1972 = (in1 * selector_1951);
			int choice_14 = add_1962;
			t_sample gate_1968 = (((choice_14 >= 1) && (choice_14 < 2)) ? mul_1972 : 0);
			t_sample gate_1969 = (((choice_14 >= 2) && (choice_14 < 3)) ? mul_1972 : 0);
			t_sample gate_1970 = (((choice_14 >= 3) && (choice_14 < 4)) ? mul_1972 : 0);
			t_sample gate_1971 = ((choice_14 >= 4) ? mul_1972 : 0);
			t_sample out3 = gate_1970;
			t_sample out4 = gate_1971;
			t_sample out2 = gate_1969;
			t_sample out1 = gate_1968;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			
		};
		return __exception;
		
	};
	inline void set_Select(t_param _value) {
		m_Select_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_Killswitch(t_param _value) {
		m_Killswitch_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_Cycle(t_param _value) {
		m_Cycle_3 = (_value < 0 ? 0 : (_value > 3 ? 3 : _value));
	};
	inline t_sample ramp0_i_d(int in1, t_sample rsr) {
		if ((__m_change_12(in1) != ((int)0))) {
			m_diff_10 = ((in1 - m_prev_9) * rsr);
			m_prev_9 = in1;
			
		};
		if ((((m_diff_10 > ((int)0)) && (m_val_11 > m_prev_9)) || ((m_diff_10 < ((int)0)) && (m_val_11 < m_prev_9)))) {
			m_val_11 = in1;
			m_diff_10 = ((int)0);
			
		} else {
			m_val_11 = (m_val_11 + m_diff_10);
			
		};
		return m_val_11;
		
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 1;
int gen_kernel_numouts = 4;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 3; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1" };
const char *gen_kernel_outnames[] = { "out1", "out2", "out3", "out4" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_Cycle(value); break;
		case 1: self->set_Killswitch(value); break;
		case 2: self->set_Select(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_Cycle_3; break;
		case 1: *value = self->m_Killswitch_2; break;
		case 2: *value = self->m_Select_1; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(3 * sizeof(ParamInfo));
	self->__commonstate.numparams = 3;
	// initialize parameter 0 ("m_Cycle_3")
	pi = self->__commonstate.params + 0;
	pi->name = "Cycle";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Cycle_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 3;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_Killswitch_2")
	pi = self->__commonstate.params + 1;
	pi->name = "Killswitch";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Killswitch_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_Select_1")
	pi = self->__commonstate.params + 2;
	pi->name = "Select";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Select_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // gen_exported::
