#include "gen_exported.h"

namespace gen_exported {

/****************************************************************************************
Copyright (c) 2023 Cycling '74

The code that Max generates automatically and that end users are capable of
exporting and using, and any associated documentation files (the “Software”)
is a work of authorship for which Cycling '74 is the author and owner for
copyright purposes.

This Software is dual-licensed either under the terms of the Cycling '74
License for Max-Generated Code for Export, or alternatively under the terms
of the General Public License (GPL) Version 3. You may use the Software
according to either of these licenses as it is most appropriate for your
project on a case-by-case basis (proprietary or not).

A) Cycling '74 License for Max-Generated Code for Export

A license is hereby granted, free of charge, to any person obtaining a copy
of the Software (“Licensee”) to use, copy, modify, merge, publish, and
distribute copies of the Software, and to permit persons to whom the Software
is furnished to do so, subject to the following conditions:

The Software is licensed to Licensee for all uses that do not include the sale,
sublicensing, or commercial distribution of software that incorporates this
source code. This means that the Licensee is free to use this software for
educational, research, and prototyping purposes, to create musical or other
creative works with software that incorporates this source code, or any other
use that does not constitute selling software that makes use of this source
code. Commercial distribution also includes the packaging of free software with
other paid software, hardware, or software-provided commercial services.

For entities with UNDER 200k USD in annual revenue or funding, a license is hereby
granted, free of charge, for the sale, sublicensing, or commercial distribution
of software that incorporates this source code, for as long as the entity's
annual revenue remains below 200k USD annual revenue or funding.

For entities with OVER 200k USD in annual revenue or funding interested in the
sale, sublicensing, or commercial distribution of software that incorporates
this source code, please send inquiries to licensing (at) cycling74.com.

The above copyright notice and this license shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Please see
https://support.cycling74.com/hc/en-us/articles/360050779193-Gen-Code-Export-Licensing-FAQ
for additional information

B) General Public License Version 3 (GPLv3)
Details of the GPLv3 license can be found at: https://www.gnu.org/licenses/gpl-3.0.html
****************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Change __m_change_49;
	Change __m_change_60;
	Data m_BOUL_25;
	Data m_BILL_31;
	Data m_urn_20;
	Delay m_delay_13;
	Delay m_delay_12;
	Delta __m_delta_103;
	PlusEquals __m_pluseq_106;
	Sah __m_sah_44;
	Sah __m_sah_74;
	int __exception;
	int vectorsize;
	t_sample __m_slide_75;
	t_sample __m_carry_72;
	t_sample __m_count_70;
	t_sample __m_count_45;
	t_sample __m_count_56;
	t_sample __m_carry_47;
	t_sample __m_carry_58;
	t_sample __m_count_78;
	t_sample __m_carry_84;
	t_sample __m_count_82;
	t_sample __m_count_114;
	t_sample __m_latch_112;
	t_sample __m_carry_116;
	t_sample __m_latch_127;
	t_sample __m_latch_126;
	t_sample __m_carry_80;
	t_sample __m_carry_110;
	t_sample __m_latch_107;
	t_sample __m_count_86;
	t_sample __m_count_108;
	t_sample __m_carry_88;
	t_sample __m_latch_105;
	t_sample __m_latch_104;
	t_sample __m_latch_42;
	t_sample __m_count_32;
	t_sample __m_carry_34;
	t_sample m_history_8;
	t_sample m_history_7;
	t_sample m_history_9;
	t_sample m_history_11;
	t_sample m_history_10;
	t_sample m_value_14;
	t_sample m_history_6;
	t_sample m_history_4;
	t_sample samplerate;
	t_sample m_history_5;
	t_sample m_history_1;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample __m_slide_39;
	t_sample m_count_15;
	t_sample m_clear_17;
	t_sample m_RandSpeed_28;
	t_sample m_filter_27;
	t_sample m_dry_wet_29;
	t_sample __m_latch_129;
	t_sample m_speed_30;
	t_sample m_history_16;
	t_sample m_trigger_26;
	t_sample m_ENV_23;
	t_sample m_value_18;
	t_sample m_RandSpdOn_24;
	t_sample m_count_19;
	t_sample m_loop_22;
	t_sample m_clear_21;
	t_sample __m_latch_130;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_history_11 = ((int)0);
		m_delay_12.reset("m_delay_12", samplerate);
		m_delay_13.reset("m_delay_13", ((int)8000));
		m_value_14 = ((int)0);
		m_count_15 = ((int)0);
		m_history_16 = ((int)0);
		m_clear_17 = ((int)0);
		m_value_18 = ((int)0);
		m_count_19 = ((int)0);
		m_urn_20.reset("urn", ((int)1024), ((int)1));
		m_clear_21 = ((int)0);
		m_loop_22 = 0;
		m_ENV_23 = 99;
		m_RandSpdOn_24 = 0;
		m_BOUL_25.reset("BOUL", ((int)7200000), ((int)2));
		m_trigger_26 = 0;
		m_filter_27 = 0;
		m_RandSpeed_28 = 0.7;
		m_dry_wet_29 = 0.5;
		m_speed_30 = 1;
		m_BILL_31.reset("BILL", ((int)7200000), ((int)2));
		__m_count_32 = 0;
		__m_carry_34 = 0;
		__m_slide_39 = 0;
		__m_latch_42 = 0;
		__m_sah_44.reset(0);
		__m_count_45 = 0;
		__m_carry_47 = 0;
		__m_change_49.reset(0);
		__m_count_56 = 0;
		__m_carry_58 = 0;
		__m_change_60.reset(0);
		__m_count_70 = 0;
		__m_carry_72 = 0;
		__m_sah_74.reset(0);
		__m_slide_75 = 0;
		__m_count_78 = 0;
		__m_carry_80 = 0;
		__m_count_82 = 0;
		__m_carry_84 = 0;
		__m_count_86 = 0;
		__m_carry_88 = 0;
		__m_delta_103.reset(0);
		__m_latch_104 = 0;
		__m_latch_105 = 0;
		__m_pluseq_106.reset(0);
		__m_latch_107 = 0;
		__m_count_108 = 0;
		__m_carry_110 = 0;
		__m_latch_112 = 0;
		__m_count_114 = 0;
		__m_carry_116 = 0;
		__m_latch_126 = 0;
		__m_latch_127 = 0;
		__m_latch_129 = 0;
		__m_latch_130 = 0;
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		int BOUL_dim = m_BOUL_25.dim;
		int BOUL_channels = m_BOUL_25.channels;
		int dim_4043 = BOUL_dim;
		int BILL_dim = m_BILL_31.dim;
		int BILL_channels = m_BILL_31.channels;
		int dim_3992 = BILL_dim;
		t_sample sub_4261 = (m_dry_wet_29 - ((t_sample)0.5));
		int dim_4013 = BOUL_dim;
		int gte_3786 = (m_speed_30 >= ((t_sample)1.9));
		int lt_3784 = (m_speed_30 < ((t_sample)1.9));
		int lte_3783 = (m_speed_30 <= ((t_sample)0.6));
		int gt_3781 = (m_speed_30 > ((t_sample)0.6));
		int dim_4039 = BOUL_dim;
		int dim_4007 = BOUL_dim;
		int dim_4026 = BOUL_dim;
		t_sample sub_4269 = (m_RandSpeed_28 - ((t_sample)0.1));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			__m_count_32 = (((int)0) ? 0 : (fixdenorm(__m_count_32 + ((int)1))));
			int carry_33 = 0;
			if ((((int)0) != 0)) {
				__m_count_32 = 0;
				__m_carry_34 = 0;
				
			} else if (((dim_4043 > 0) && (__m_count_32 >= dim_4043))) {
				int wraps_35 = (__m_count_32 / dim_4043);
				__m_carry_34 = (__m_carry_34 + wraps_35);
				__m_count_32 = (__m_count_32 - (wraps_35 * dim_4043));
				carry_33 = 1;
				
			};
			int counter_4044 = __m_count_32;
			int counter_4045 = carry_33;
			int counter_4046 = __m_carry_34;
			bool index_ignore_36 = ((counter_4044 >= BOUL_dim) || (counter_4044 < 0));
			if ((!index_ignore_36)) {
				m_BOUL_25.write(in1, counter_4044, 0);
				
			};
			bool chan_ignore_37 = ((((int)1) < 0) || (((int)1) >= BOUL_channels));
			bool index_ignore_38 = ((counter_4044 >= BOUL_dim) || (counter_4044 < 0));
			if ((!(chan_ignore_37 || index_ignore_38))) {
				m_BOUL_25.write(in2, counter_4044, ((int)1));
				
			};
			t_sample scale_4258 = ((safepow((sub_4261 * ((t_sample)2)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample min_3795 = ((((int)1) < scale_4258) ? ((int)1) : scale_4258);
			t_sample mul_3958 = (in1 * min_3795);
			t_sample mul_3957 = (in2 * min_3795);
			t_sample sub_4265 = (m_dry_wet_29 - ((int)0));
			t_sample scale_4262 = ((safepow((sub_4265 * ((t_sample)2)), ((int)1)) * ((int)1)) + ((int)0));
			t_sample min_3799 = ((((int)1) < scale_4262) ? ((int)1) : scale_4262);
			t_sample round_3961 = (round((m_trigger_26 * ((t_sample)1))) * ((int)1));
			t_sample resetcountloop_3972 = round_3961;
			t_sample resetcountloop_3975 = resetcountloop_3972;
			t_sample round_3962 = (round((m_loop_22 * ((t_sample)1))) * ((int)1));
			t_sample startstoploop_4001 = round_3962;
			t_sample startstoploop_3982 = startstoploop_4001;
			t_sample add_3688 = (m_RandSpdOn_24 + ((int)1));
			t_sample ramp_3734 = (round_3961 + round_3962);
			t_sample iup_40 = (1 / maximum(1, abs(((int)4800))));
			t_sample idown_41 = (1 / maximum(1, abs(((int)480))));
			__m_slide_39 = fixdenorm((__m_slide_39 + (((ramp_3734 > __m_slide_39) ? iup_40 : idown_41) * (ramp_3734 - __m_slide_39))));
			t_sample slide_3735 = __m_slide_39;
			int mul_3785 = (gte_3786 * ((int)3));
			int mul_3787 = (lt_3784 * ((int)2));
			int mul_3782 = (lte_3783 * ((int)1));
			int mul_3780 = (gt_3781 * ((int)2));
			__m_latch_42 = (((((gt_3781 + lte_3783) + lt_3784) + gte_3786) != 0) ? (((mul_3787 + mul_3780) + mul_3782) + mul_3785) : __m_latch_42);
			int latch_3792 = __m_latch_42;
			int sub_3779 = (latch_3792 - ((int)2));
			int choice_43 = sub_3779;
			t_sample selector_3791 = ((choice_43 >= 3) ? ((int)2) : ((choice_43 >= 2) ? ((int)1) : ((choice_43 >= 1) ? ((t_sample)0.5) : 0)));
			t_sample gen_3793 = selector_3791;
			t_sample Potspeed_3729 = gen_3793;
			int count_4040 = counter_4044;
			int sah_4031 = __m_sah_44(count_4040, (round_3961 + round_3962), ((int)0));
			int sah_4014 = sah_4031;
			int sah_4015 = sah_4014;
			t_sample scale_4266 = ((safepow((sub_4269 * ((t_sample)0.3448275862069)), ((int)2)) * ((int)3)) + ((int)0));
			t_sample scale_3687 = scale_4266;
			__m_count_45 = (((int)0) ? 0 : (fixdenorm(__m_count_45 + m_history_16)));
			int carry_46 = 0;
			if ((((int)0) != 0)) {
				__m_count_45 = 0;
				__m_carry_47 = 0;
				
			} else if (((((int)48000) > 0) && (__m_count_45 >= ((int)48000)))) {
				int wraps_48 = (__m_count_45 / ((int)48000));
				__m_carry_47 = (__m_carry_47 + wraps_48);
				__m_count_45 = (__m_count_45 - (wraps_48 * ((int)48000)));
				carry_46 = 1;
				
			};
			t_sample counter_3710 = __m_count_45;
			int counter_3711 = carry_46;
			int counter_3712 = __m_carry_47;
			int size = ((((int)3) <= ((int)1)) ? ((int)1) : ((((int)3) >= ((int)1024)) ? ((int)1024) : ((int)3)));
			if ((((m_count_19 == ((int)0)) || __m_change_49(size)) || m_clear_21)) {
				m_count_19 = size;
				m_clear_21 = ((int)0);
				
			};
			if (counter_3711) {
				t_sample r = floor((fabs(noise()) * m_count_19));
				int urn_dim = m_urn_20.dim;
				int urn_channels = m_urn_20.channels;
				int index_trunc_50 = fixnan(floor(r));
				bool index_ignore_51 = ((index_trunc_50 >= urn_dim) || (index_trunc_50 < 0));
				// samples urn channel 1;
				int chan_52 = ((int)0);
				bool chan_ignore_53 = ((chan_52 < 0) || (chan_52 >= urn_channels));
				m_value_18 = ((chan_ignore_53 || index_ignore_51) ? 0 : m_urn_20.read(index_trunc_50, chan_52));
				m_count_19 = (m_count_19 - ((int)1));
				int index_trunc_54 = fixnan(floor(r));
				bool index_ignore_55 = ((index_trunc_54 >= urn_dim) || (index_trunc_54 < 0));
				if ((!index_ignore_55)) {
					m_urn_20.write(m_count_19, index_trunc_54, 0);
					
				};
				
			};
			t_sample expr_3716 = m_value_18;
			t_sample gen_3718 = expr_3716;
			t_sample gen_3728 = gen_3718;
			t_sample add_3698 = (gen_3718 + ((t_sample)0.1));
			__m_count_56 = (((int)0) ? 0 : (fixdenorm(__m_count_56 + add_3698)));
			int carry_57 = 0;
			if ((((int)0) != 0)) {
				__m_count_56 = 0;
				__m_carry_58 = 0;
				
			} else if (((((int)48000) > 0) && (__m_count_56 >= ((int)48000)))) {
				int wraps_59 = (__m_count_56 / ((int)48000));
				__m_carry_58 = (__m_carry_58 + wraps_59);
				__m_count_56 = (__m_count_56 - (wraps_59 * ((int)48000)));
				carry_57 = 1;
				
			};
			t_sample counter_3700 = __m_count_56;
			int counter_3701 = carry_57;
			int counter_3702 = __m_carry_58;
			int size_3723 = ((((int)260) <= ((int)1)) ? ((int)1) : ((((int)260) >= ((int)1024)) ? ((int)1024) : ((int)260)));
			if ((((m_count_15 == ((int)0)) || __m_change_60(size_3723)) || m_clear_17)) {
				m_count_15 = size_3723;
				m_clear_17 = ((int)0);
				
			};
			if (counter_3701) {
				t_sample r_3720 = floor((fabs(noise()) * m_count_15));
				int urn_dim = m_urn_20.dim;
				int urn_channels = m_urn_20.channels;
				int index_trunc_61 = fixnan(floor(r_3720));
				bool index_ignore_62 = ((index_trunc_61 >= urn_dim) || (index_trunc_61 < 0));
				// samples urn channel 1;
				int chan_63 = ((int)0);
				bool chan_ignore_64 = ((chan_63 < 0) || (chan_63 >= urn_channels));
				m_value_14 = ((chan_ignore_64 || index_ignore_62) ? 0 : m_urn_20.read(index_trunc_61, chan_63));
				m_count_15 = (m_count_15 - ((int)1));
				int index_trunc_65 = fixnan(floor(r_3720));
				bool index_ignore_66 = ((index_trunc_65 >= urn_dim) || (index_trunc_65 < 0));
				if ((!index_ignore_66)) {
					m_urn_20.write(m_count_15, index_trunc_65, 0);
					
				};
				
			};
			t_sample expr_3706 = m_value_14;
			t_sample gen_3708 = expr_3706;
			t_sample sub_4273 = (gen_3708 - ((int)1));
			t_sample scale_4270 = ((safepow((sub_4273 * ((t_sample)0.0038610038610039)), ((int)1)) * ((t_sample)-6.98)) + ((int)7));
			t_sample scale_3697 = scale_4270;
			t_sample mul_3696 = (scale_3697 * scale_3687);
			t_sample history_3695_next_3727 = fixdenorm(mul_3696);
			t_sample add_3690 = (gen_3728 + ((int)1));
			t_sample choice_67 = int(add_3690);
			t_sample selector_3694 = ((choice_67 >= 3) ? ((int)2) : ((choice_67 >= 2) ? ((int)1) : ((choice_67 >= 1) ? ((t_sample)0.5) : 0)));
			t_sample choice_68 = int(add_3688);
			t_sample selector_3689 = ((choice_68 >= 2) ? selector_3694 : ((choice_68 >= 1) ? Potspeed_3729 : 0));
			t_sample speed_3998 = selector_3689;
			t_sample speed_3964 = speed_3998;
			t_sample choice_69 = int(startstoploop_3982);
			t_sample selector_3963 = ((choice_69 >= 1) ? speed_3964 : 0);
			__m_count_70 = (resetcountloop_3975 ? 0 : (fixdenorm(__m_count_70 + selector_3963)));
			int carry_71 = 0;
			if ((resetcountloop_3975 != 0)) {
				__m_count_70 = 0;
				__m_carry_72 = 0;
				
			} else if (((dim_3992 > 0) && (__m_count_70 >= dim_3992))) {
				int wraps_73 = (__m_count_70 / dim_3992);
				__m_carry_72 = (__m_carry_72 + wraps_73);
				__m_count_70 = (__m_count_70 - (wraps_73 * dim_3992));
				carry_71 = 1;
				
			};
			t_sample counter_3993 = __m_count_70;
			int counter_3994 = carry_71;
			int counter_3995 = __m_carry_72;
			t_sample speed_4000 = speed_3998;
			t_sample speed_3740 = speed_3998;
			t_sample speed_3999 = speed_3998;
			t_sample startstoploop_3980 = startstoploop_4001;
			t_sample resetcountloop_3973 = resetcountloop_3972;
			t_sample startstoploop_4002 = startstoploop_4001;
			t_sample speed_3966 = speed_3998;
			int not_3974 = (!startstoploop_3980);
			t_sample sah_3981 = __m_sah_74(counter_3993, not_3974, ((int)0));
			t_sample sahloop_3745 = sah_3981;
			t_sample div_3741 = safediv(sahloop_3745, speed_3740);
			t_sample sahloop_3794 = sahloop_3745;
			t_sample speed_3983 = speed_3998;
			t_sample tap_3960 = m_delay_13.read_step(((int)8000));
			t_sample trig_3737 = tap_3960;
			t_sample iup_76 = (1 / maximum(1, abs(((int)0))));
			t_sample idown_77 = (1 / maximum(1, abs(((int)4800))));
			__m_slide_75 = fixdenorm((__m_slide_75 + (((trig_3737 > __m_slide_75) ? iup_76 : idown_77) * (trig_3737 - __m_slide_75))));
			t_sample slide_3733 = __m_slide_75;
			int gte_3732 = (slide_3733 >= ((t_sample)0.0005));
			int not_3736 = (!gte_3732);
			t_sample trig_4016 = trig_3737;
			int eq_4017 = ((startstoploop_4002 + trig_4016) == ((int)0));
			__m_count_78 = (eq_4017 ? 0 : (fixdenorm(__m_count_78 + speed_3999)));
			int carry_79 = 0;
			if ((eq_4017 != 0)) {
				__m_count_78 = 0;
				__m_carry_80 = 0;
				
			} else if (((sah_4015 > 0) && (__m_count_78 >= sah_4015))) {
				int wraps_81 = (__m_count_78 / sah_4015);
				__m_carry_80 = (__m_carry_80 + wraps_81);
				__m_count_78 = (__m_count_78 - (wraps_81 * sah_4015));
				carry_79 = 1;
				
			};
			t_sample counter_4020 = __m_count_78;
			int counter_4021 = carry_79;
			int counter_4022 = __m_carry_80;
			int endcountpart_4004 = counter_4022;
			int endcountpart_4005 = endcountpart_4004;
			int add_4019 = (endcountpart_4005 + ((int)1));
			int eq_4006 = (endcountpart_4004 == ((int)0));
			__m_count_82 = (eq_4006 ? 0 : (fixdenorm(__m_count_82 + speed_4000)));
			int carry_83 = 0;
			if ((eq_4006 != 0)) {
				__m_count_82 = 0;
				__m_carry_84 = 0;
				
			} else if (((dim_4007 > 0) && (__m_count_82 >= dim_4007))) {
				int wraps_85 = (__m_count_82 / dim_4007);
				__m_carry_84 = (__m_carry_84 + wraps_85);
				__m_count_82 = (__m_count_82 - (wraps_85 * dim_4007));
				carry_83 = 1;
				
			};
			t_sample counter_4008 = __m_count_82;
			int counter_4009 = carry_83;
			int counter_4010 = __m_carry_84;
			int irange_4275 = (dim_4013 - ((int)0));
			int orange_4276 = (((int)0) - dim_4013);
			t_sample sub_4277 = (counter_4008 - ((int)0));
			t_sample scale_4274 = ((safepow(safediv(sub_4277, irange_4275), ((int)1)) * orange_4276) + dim_4013);
			t_sample scale_4012 = scale_4274;
			t_sample countpart_4003 = scale_4012;
			t_sample trig_4018 = trig_3737;
			int eq_4025 = ((startstoploop_4001 + trig_4018) == ((int)0));
			__m_count_86 = (eq_4025 ? 0 : (fixdenorm(__m_count_86 + speed_3998)));
			int carry_87 = 0;
			if ((eq_4025 != 0)) {
				__m_count_86 = 0;
				__m_carry_88 = 0;
				
			} else if (((dim_4026 > 0) && (__m_count_86 >= dim_4026))) {
				int wraps_89 = (__m_count_86 / dim_4026);
				__m_carry_88 = (__m_carry_88 + wraps_89);
				__m_count_86 = (__m_count_86 - (wraps_89 * dim_4026));
				carry_87 = 1;
				
			};
			t_sample counter_4027 = __m_count_86;
			int counter_4028 = carry_87;
			int counter_4029 = __m_carry_88;
			int irange_4279 = (dim_4039 - ((int)0));
			int orange_4280 = (((int)0) - dim_4039);
			t_sample sub_4281 = (counter_4027 - ((int)0));
			t_sample scale_4278 = ((safepow(safediv(sub_4281, irange_4279), ((int)1)) * orange_4280) + dim_4039);
			t_sample scale_4038 = scale_4278;
			t_sample sub_4023 = (scale_4038 - ((int)7200000));
			t_sample add_4024 = (sub_4023 + sah_4014);
			int choice_90 = add_4019;
			t_sample selector_4030 = ((choice_90 >= 2) ? countpart_4003 : ((choice_90 >= 1) ? add_4024 : 0));
			int index_trunc_91 = fixnan(floor(selector_4030));
			bool index_ignore_92 = ((index_trunc_91 >= BOUL_dim) || (index_trunc_91 < 0));
			// samples BOUL channel 1;
			int chan_93 = ((int)0);
			bool chan_ignore_94 = ((chan_93 < 0) || (chan_93 >= BOUL_channels));
			// samples BOUL channel 2;
			int chan_95 = (((int)0) + 1);
			bool chan_ignore_96 = ((chan_95 < 0) || (chan_95 >= BOUL_channels));
			t_sample sample_BOUL_4032 = ((chan_ignore_94 || index_ignore_92) ? 0 : m_BOUL_25.read(index_trunc_91, chan_93));
			t_sample sample_BOUL_4033 = ((chan_ignore_96 || index_ignore_92) ? 0 : m_BOUL_25.read(index_trunc_91, chan_95));
			t_sample index_BOUL_4034 = selector_4030;
			t_sample recloop_3773 = sample_BOUL_4033;
			t_sample recloop_3990 = recloop_3773;
			bool chan_ignore_97 = ((((int)1) < 0) || (((int)1) >= BILL_channels));
			int index_trunc_98 = fixnan(floor(counter_3993));
			bool index_ignore_99 = ((index_trunc_98 >= BILL_dim) || (index_trunc_98 < 0));
			if ((!(chan_ignore_97 || index_ignore_99))) {
				m_BILL_31.write(recloop_3990, index_trunc_98, ((int)1));
				
			};
			t_sample mul_3778 = (recloop_3773 * slide_3735);
			t_sample recloop_3776 = sample_BOUL_4032;
			t_sample recloop_3991 = recloop_3776;
			int index_trunc_100 = fixnan(floor(counter_3993));
			bool index_ignore_101 = ((index_trunc_100 >= BILL_dim) || (index_trunc_100 < 0));
			if ((!index_ignore_101)) {
				m_BILL_31.write(recloop_3991, index_trunc_100, 0);
				
			};
			t_sample mul_3777 = (recloop_3776 * slide_3735);
			int bool_3968 = (counter_3993 != 0);
			int openreset_3969 = bool_3968;
			int openreset_3967 = openreset_3969;
			int choice_102 = openreset_3967;
			t_sample selector_3965 = ((choice_102 >= 1) ? speed_3966 : 0);
			t_sample startloopramp_3744 = selector_3965;
			int gt_3742 = (startloopramp_3744 > ((int)0));
			t_sample tap_3762 = m_delay_12.read_linear(m_ENV_23);
			t_sample sub_4285 = (m_ENV_23 - ((int)0));
			t_sample scale_4282 = ((safepow((sub_4285 * ((t_sample)0.00033333333333333)), ((int)1)) * ((t_sample)-0.0099)) + ((t_sample)0.01));
			t_sample scale_3771 = scale_4282;
			t_sample delta_3755 = __m_delta_103(tap_3762);
			__m_latch_104 = ((delta_3755 != 0) ? m_history_11 : __m_latch_104);
			t_sample latch_3750 = __m_latch_104;
			__m_latch_105 = ((delta_3755 != 0) ? tap_3762 : __m_latch_105);
			t_sample latch_3752 = __m_latch_105;
			t_sample plusequals_3754 = __m_pluseq_106.post(((int)1), delta_3755, 0);
			__m_latch_107 = ((delta_3755 != 0) ? scale_3771 : __m_latch_107);
			t_sample latch_3749 = __m_latch_107;
			t_sample mul_3753 = (plusequals_3754 * latch_3749);
			t_sample clamp_3751 = ((mul_3753 <= ((int)0)) ? ((int)0) : ((mul_3753 >= ((int)1)) ? ((int)1) : mul_3753));
			t_sample anon_3756 = linear_interp(clamp_3751, latch_3750, latch_3752);
			t_sample gen_3758 = anon_3756;
			t_sample history_3746_next_3757 = fixdenorm(anon_3756);
			t_sample gen_3772 = gen_3758;
			t_sample mul_3760 = (m_ENV_23 * ((int)2));
			t_sample sub_3765 = (div_3741 - mul_3760);
			int eq_3767 = (gt_3742 == ((int)0));
			__m_count_108 = (eq_3767 ? 0 : (fixdenorm(__m_count_108 + ((int)1))));
			int carry_109 = 0;
			if ((eq_3767 != 0)) {
				__m_count_108 = 0;
				__m_carry_110 = 0;
				
			} else if (((div_3741 > 0) && (__m_count_108 >= div_3741))) {
				int wraps_111 = (__m_count_108 / div_3741);
				__m_carry_110 = (__m_carry_110 + wraps_111);
				__m_count_108 = (__m_count_108 - (wraps_111 * div_3741));
				carry_109 = 1;
				
			};
			int counter_3768 = __m_count_108;
			int counter_3769 = carry_109;
			int counter_3770 = __m_carry_110;
			int gte_3764 = (counter_3768 >= sub_3765);
			int not_3763 = (!gte_3764);
			t_sample envelop_Loop_3743 = gen_3772;
			__m_latch_112 = ((openreset_3969 != 0) ? resetcountloop_3972 : __m_latch_112);
			t_sample latch_3971 = __m_latch_112;
			int not_3970 = (!latch_3971);
			int choice_113 = not_3970;
			t_sample selector_3977 = ((choice_113 >= 2) ? speed_3983 : ((choice_113 >= 1) ? ((int)0) : 0));
			__m_count_114 = ((resetcountloop_3973 + startstoploop_3980) ? 0 : (fixdenorm(__m_count_114 + (selector_3965 + selector_3977))));
			int carry_115 = 0;
			t_sample count_reset_117 = (resetcountloop_3973 + startstoploop_3980);
			if ((count_reset_117 != 0)) {
				__m_count_114 = 0;
				__m_carry_116 = 0;
				
			} else if (((sahloop_3794 > 0) && (__m_count_114 >= sahloop_3794))) {
				int wraps_118 = (__m_count_114 / sahloop_3794);
				__m_carry_116 = (__m_carry_116 + wraps_118);
				__m_count_114 = (__m_count_114 - (wraps_118 * sahloop_3794));
				carry_115 = 1;
				
			};
			t_sample counter_3984 = __m_count_114;
			int counter_3985 = carry_115;
			int counter_3986 = __m_carry_116;
			int index_trunc_119 = fixnan(floor(counter_3984));
			bool index_ignore_120 = ((index_trunc_119 >= BILL_dim) || (index_trunc_119 < 0));
			// samples BILL channel 1;
			int chan_121 = ((int)0);
			bool chan_ignore_122 = ((chan_121 < 0) || (chan_121 >= BILL_channels));
			// samples BILL channel 2;
			int chan_123 = (((int)0) + 1);
			bool chan_ignore_124 = ((chan_123 < 0) || (chan_123 >= BILL_channels));
			t_sample sample_BILL_3987 = ((chan_ignore_122 || index_ignore_120) ? 0 : m_BILL_31.read(index_trunc_119, chan_121));
			t_sample sample_BILL_3988 = ((chan_ignore_124 || index_ignore_120) ? 0 : m_BILL_31.read(index_trunc_119, chan_123));
			t_sample index_BILL_3989 = counter_3984;
			int choice_125 = not_3736;
			t_sample selector_3739 = ((choice_125 >= 1) ? sample_BILL_3987 : 0);
			t_sample loop_3979 = selector_3739;
			t_sample mul_3801 = (envelop_Loop_3743 * loop_3979);
			t_sample add_3775 = (mul_3801 + mul_3777);
			int lte_4070 = (m_filter_27 <= ((int)0));
			int not_4069 = (!lte_4070);
			__m_latch_126 = ((not_4069 != 0) ? m_filter_27 : __m_latch_126);
			t_sample latch_4071 = __m_latch_126;
			t_sample sub_4289 = (latch_4071 - ((int)0));
			t_sample scale_4286 = ((safepow((sub_4289 * ((t_sample)0.01)), ((int)1)) * ((int)995)) + ((int)5));
			t_sample scale_4075 = scale_4286;
			int gte_4073 = (m_filter_27 >= ((int)0));
			int not_4072 = (!gte_4073);
			__m_latch_127 = ((not_4072 != 0) ? m_filter_27 : __m_latch_127);
			t_sample latch_4074 = __m_latch_127;
			t_sample sub_4293 = (latch_4074 - ((int)0));
			t_sample scale_4290 = ((safepow((sub_4293 * ((t_sample)-0.01)), ((int)1)) * ((int)1)) + ((int)0));
			t_sample scale_4059 = scale_4290;
			t_sample sub_4297 = (latch_4074 - (-100));
			t_sample scale_4294 = ((safepow((sub_4297 * ((t_sample)0.01)), ((int)1)) * ((int)1500)) + ((int)500));
			t_sample scale_4076 = scale_4294;
			t_sample abs_4061 = fabs(scale_4076);
			t_sample mul_4063 = (abs_4061 * safediv((-6.2831853071796), samplerate));
			t_sample exp_4065 = exp(mul_4063);
			t_sample clamp_4066 = ((exp_4065 <= ((int)0)) ? ((int)0) : ((exp_4065 >= ((int)1)) ? ((int)1) : exp_4065));
			t_sample mix_4298 = (add_3775 + (clamp_4066 * (m_history_10 - add_3775)));
			t_sample mix_4062 = mix_4298;
			t_sample gen_4068 = mix_4062;
			t_sample history_4064_next_4067 = fixdenorm(mix_4062);
			t_sample mix_4299 = (add_3775 + (scale_4059 * (gen_4068 - add_3775)));
			t_sample mix_4060 = mix_4299;
			t_sample min_4084 = ((scale_4075 < ((int)0)) ? ((int)0) : scale_4075);
			t_sample omega = safediv((min_4084 * ((t_sample)6.2831853071796)), samplerate);
			t_sample sn = sin(omega);
			t_sample cs = cos(omega);
			t_sample alpha = ((sn * ((t_sample)0.5)) * ((t_sample)2));
			t_sample b0 = safediv(((int)1), (((int)1) + alpha));
			t_sample a2 = (((((int)1) + cs) * ((t_sample)0.5)) * b0);
			t_sample a1 = ((-(((int)1) + cs)) * b0);
			t_sample b1 = ((((int)-2) * cs) * b0);
			t_sample b2 = ((((int)1) - alpha) * b0);
			t_sample expr_4100 = a2;
			t_sample expr_4101 = a1;
			t_sample expr_4102 = a2;
			t_sample expr_4103 = b1;
			t_sample expr_4104 = b2;
			t_sample mul_4094 = (mix_4060 * expr_4100);
			t_sample mul_4091 = (m_history_7 * expr_4101);
			t_sample mul_4089 = (m_history_8 * expr_4102);
			t_sample mul_4085 = (m_history_9 * expr_4104);
			t_sample mul_4087 = (m_history_6 * expr_4103);
			t_sample sub_4093 = (((mul_4089 + mul_4091) + mul_4094) - (mul_4087 + mul_4085));
			t_sample gen_4099 = sub_4093;
			t_sample history_4086_next_4095 = fixdenorm(m_history_6);
			t_sample history_4090_next_4096 = fixdenorm(m_history_7);
			t_sample history_4092_next_4097 = fixdenorm(mix_4060);
			t_sample history_4088_next_4098 = fixdenorm(sub_4093);
			t_sample mul_3798 = (gen_4099 * min_3799);
			t_sample add_3803 = (mul_3958 + mul_3798);
			t_sample out1 = add_3803;
			int choice_128 = not_3736;
			t_sample selector_3738 = ((choice_128 >= 1) ? sample_BILL_3988 : 0);
			t_sample loop_3978 = selector_3738;
			t_sample mul_3802 = (envelop_Loop_3743 * loop_3978);
			t_sample add_3774 = (mul_3802 + mul_3778);
			int lte_4130 = (m_filter_27 <= ((int)0));
			int not_4129 = (!lte_4130);
			__m_latch_129 = ((not_4129 != 0) ? m_filter_27 : __m_latch_129);
			t_sample latch_4131 = __m_latch_129;
			t_sample sub_4303 = (latch_4131 - ((int)0));
			t_sample scale_4300 = ((safepow((sub_4303 * ((t_sample)0.01)), ((int)1)) * ((int)995)) + ((int)5));
			t_sample scale_4135 = scale_4300;
			int gte_4133 = (m_filter_27 >= ((int)0));
			int not_4132 = (!gte_4133);
			__m_latch_130 = ((not_4132 != 0) ? m_filter_27 : __m_latch_130);
			t_sample latch_4134 = __m_latch_130;
			t_sample sub_4307 = (latch_4134 - ((int)0));
			t_sample scale_4304 = ((safepow((sub_4307 * ((t_sample)-0.01)), ((int)1)) * ((int)1)) + ((int)0));
			t_sample scale_4119 = scale_4304;
			t_sample sub_4311 = (latch_4134 - (-100));
			t_sample scale_4308 = ((safepow((sub_4311 * ((t_sample)0.01)), ((int)1)) * ((int)1500)) + ((int)500));
			t_sample scale_4136 = scale_4308;
			t_sample abs_4121 = fabs(scale_4136);
			t_sample mul_4123 = (abs_4121 * safediv((-6.2831853071796), samplerate));
			t_sample exp_4125 = exp(mul_4123);
			t_sample clamp_4126 = ((exp_4125 <= ((int)0)) ? ((int)0) : ((exp_4125 >= ((int)1)) ? ((int)1) : exp_4125));
			t_sample mix_4312 = (add_3774 + (clamp_4126 * (m_history_5 - add_3774)));
			t_sample mix_4122 = mix_4312;
			t_sample gen_4128 = mix_4122;
			t_sample history_4124_next_4127 = fixdenorm(mix_4122);
			t_sample mix_4313 = (add_3774 + (scale_4119 * (gen_4128 - add_3774)));
			t_sample mix_4120 = mix_4313;
			t_sample min_4144 = ((scale_4135 < ((int)0)) ? ((int)0) : scale_4135);
			t_sample omega_4196 = safediv((min_4144 * ((t_sample)6.2831853071796)), samplerate);
			t_sample sn_4195 = sin(omega_4196);
			t_sample cs_4194 = cos(omega_4196);
			t_sample alpha_4193 = ((sn_4195 * ((t_sample)0.5)) * ((t_sample)2));
			t_sample b_4192 = safediv(((int)1), (((int)1) + alpha_4193));
			t_sample a_4191 = (((((int)1) + cs_4194) * ((t_sample)0.5)) * b_4192);
			t_sample a_4190 = ((-(((int)1) + cs_4194)) * b_4192);
			t_sample b_4189 = ((((int)-2) * cs_4194) * b_4192);
			t_sample b_4188 = ((((int)1) - alpha_4193) * b_4192);
			t_sample expr_4160 = a_4191;
			t_sample expr_4161 = a_4190;
			t_sample expr_4162 = a_4191;
			t_sample expr_4163 = b_4189;
			t_sample expr_4164 = b_4188;
			t_sample mul_4154 = (mix_4120 * expr_4160);
			t_sample mul_4151 = (m_history_2 * expr_4161);
			t_sample mul_4149 = (m_history_4 * expr_4162);
			t_sample mul_4145 = (m_history_3 * expr_4164);
			t_sample mul_4147 = (m_history_1 * expr_4163);
			t_sample sub_4153 = (((mul_4149 + mul_4151) + mul_4154) - (mul_4147 + mul_4145));
			t_sample gen_4159 = sub_4153;
			t_sample history_4150_next_4155 = fixdenorm(m_history_2);
			t_sample history_4146_next_4156 = fixdenorm(m_history_1);
			t_sample history_4152_next_4157 = fixdenorm(mix_4120);
			t_sample history_4148_next_4158 = fixdenorm(sub_4153);
			t_sample mul_3797 = (gen_4159 * min_3799);
			t_sample add_3804 = (mul_3957 + mul_3797);
			t_sample out2 = add_3804;
			m_history_16 = history_3695_next_3727;
			m_delay_13.write(round_3961);
			m_delay_12.write(not_3763);
			m_history_11 = history_3746_next_3757;
			m_history_10 = history_4064_next_4067;
			m_history_6 = history_4088_next_4098;
			m_history_7 = history_4092_next_4097;
			m_history_8 = history_4090_next_4096;
			m_history_9 = history_4086_next_4095;
			m_history_5 = history_4124_next_4127;
			m_history_1 = history_4148_next_4158;
			m_history_2 = history_4152_next_4157;
			m_history_3 = history_4146_next_4156;
			m_history_4 = history_4150_next_4155;
			m_delay_12.step();
			m_delay_13.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			
		};
		return __exception;
		
	};
	inline void set_urn(void * _value) {
		m_urn_20.setbuffer(_value);
	};
	inline void set_loop(t_param _value) {
		m_loop_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ENV(t_param _value) {
		m_ENV_23 = (_value < 0 ? 0 : (_value > 2900 ? 2900 : _value));
	};
	inline void set_RandSpdOn(t_param _value) {
		m_RandSpdOn_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_BOUL(void * _value) {
		m_BOUL_25.setbuffer(_value);
	};
	inline void set_trigger(t_param _value) {
		m_trigger_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_filter(t_param _value) {
		m_filter_27 = (_value < -100 ? -100 : (_value > 100 ? 100 : _value));
	};
	inline void set_RandSpeed(t_param _value) {
		m_RandSpeed_28 = (_value < 0.01 ? 0.01 : (_value > 3 ? 3 : _value));
	};
	inline void set_dry_wet(t_param _value) {
		m_dry_wet_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_speed(t_param _value) {
		m_speed_30 = (_value < 0.5 ? 0.5 : (_value > 2 ? 2 : _value));
	};
	inline void set_BILL(void * _value) {
		m_BILL_31.setbuffer(_value);
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 2;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 11; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2" };

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
		case 0: self->set_BILL(ref); break;
		case 1: self->set_BOUL(ref); break;
		case 2: self->set_ENV(value); break;
		case 3: self->set_RandSpdOn(value); break;
		case 4: self->set_RandSpeed(value); break;
		case 5: self->set_dry_wet(value); break;
		case 6: self->set_filter(value); break;
		case 7: self->set_loop(value); break;
		case 8: self->set_speed(value); break;
		case 9: self->set_trigger(value); break;
		case 10: self->set_urn(ref); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		
		
		case 2: *value = self->m_ENV_23; break;
		case 3: *value = self->m_RandSpdOn_24; break;
		case 4: *value = self->m_RandSpeed_28; break;
		case 5: *value = self->m_dry_wet_29; break;
		case 6: *value = self->m_filter_27; break;
		case 7: *value = self->m_loop_22; break;
		case 8: *value = self->m_speed_30; break;
		case 9: *value = self->m_trigger_26; break;
		
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(11 * sizeof(ParamInfo));
	self->__commonstate.numparams = 11;
	// initialize parameter 0 ("m_BILL_31")
	pi = self->__commonstate.params + 0;
	pi->name = "BILL";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_BOUL_25")
	pi = self->__commonstate.params + 1;
	pi->name = "BOUL";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_ENV_23")
	pi = self->__commonstate.params + 2;
	pi->name = "ENV";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ENV_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2900;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_RandSpdOn_24")
	pi = self->__commonstate.params + 3;
	pi->name = "RandSpdOn";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_RandSpdOn_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_RandSpeed_28")
	pi = self->__commonstate.params + 4;
	pi->name = "RandSpeed";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_RandSpeed_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.01;
	pi->outputmax = 3;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_dry_wet_29")
	pi = self->__commonstate.params + 5;
	pi->name = "dry_wet";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_dry_wet_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_filter_27")
	pi = self->__commonstate.params + 6;
	pi->name = "filter";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_filter_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -100;
	pi->outputmax = 100;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_loop_22")
	pi = self->__commonstate.params + 7;
	pi->name = "loop";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_loop_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_speed_30")
	pi = self->__commonstate.params + 8;
	pi->name = "speed";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_speed_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.5;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_trigger_26")
	pi = self->__commonstate.params + 9;
	pi->name = "trigger";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_trigger_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_urn_20")
	pi = self->__commonstate.params + 10;
	pi->name = "urn";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
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
