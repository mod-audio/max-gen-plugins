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
	Data m_BOUL_28;
	Data m_BILL_21;
	Delay m_delay_19;
	Delay m_delay_18;
	Delta __m_delta_71;
	Delta __m_delta_44;
	PlusEquals __m_pluseq_74;
	PlusEquals __m_pluseq_45;
	Sah __m_sah_69;
	Sah __m_sah_43;
	int __exception;
	int vectorsize;
	t_sample __m_count_56;
	t_sample __m_carry_54;
	t_sample m_history_9;
	t_sample __m_carry_58;
	t_sample m_history_1;
	t_sample __m_count_52;
	t_sample __m_count_48;
	t_sample m_history_2;
	t_sample __m_carry_50;
	t_sample __m_latch_46;
	t_sample __m_latch_47;
	t_sample m_history_3;
	t_sample samplerate;
	t_sample __m_latch_73;
	t_sample __m_carry_84;
	t_sample __m_latch_91;
	t_sample __m_latch_92;
	t_sample __m_latch_72;
	t_sample __m_count_82;
	t_sample __m_carry_78;
	t_sample __m_latch_80;
	t_sample __m_latch_75;
	t_sample __m_count_76;
	t_sample m_history_8;
	t_sample m_history_4;
	t_sample __m_count_39;
	t_sample m_history_16;
	t_sample m_history_15;
	t_sample m_history_17;
	t_sample m_history_7;
	t_sample m_history_6;
	t_sample m_history_14;
	t_sample m_history_12;
	t_sample m_history_13;
	t_sample m_history_10;
	t_sample m_history_11;
	t_sample __m_carry_41;
	t_sample m_history_20;
	t_sample m_trigger_22;
	t_sample __m_count_29;
	t_sample __m_latch_94;
	t_sample __m_carry_31;
	t_sample __m_latch_36;
	t_sample m_history_5;
	t_sample m_loop_27;
	t_sample m_ENV_25;
	t_sample m_dry_wet_26;
	t_sample m_filter_23;
	t_sample m_speed_24;
	t_sample __m_latch_95;
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
		m_history_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_delay_18.reset("m_delay_18", samplerate);
		m_delay_19.reset("m_delay_19", ((int)400));
		m_history_20 = ((int)0);
		m_BILL_21.reset("BILL", ((int)15336000), ((int)2));
		m_trigger_22 = 0;
		m_filter_23 = 0;
		m_speed_24 = 1;
		m_ENV_25 = 20;
		m_dry_wet_26 = 0.5;
		m_loop_27 = 0;
		m_BOUL_28.reset("BOUL", ((int)15336000), ((int)2));
		__m_count_29 = 0;
		__m_carry_31 = 0;
		__m_latch_36 = 0;
		__m_count_39 = 0;
		__m_carry_41 = 0;
		__m_sah_43.reset(0);
		__m_delta_44.reset(0);
		__m_pluseq_45.reset(0);
		__m_latch_46 = 0;
		__m_latch_47 = 0;
		__m_count_48 = 0;
		__m_carry_50 = 0;
		__m_count_52 = 0;
		__m_carry_54 = 0;
		__m_count_56 = 0;
		__m_carry_58 = 0;
		__m_sah_69.reset(0);
		__m_delta_71.reset(0);
		__m_latch_72 = 0;
		__m_latch_73 = 0;
		__m_pluseq_74.reset(0);
		__m_latch_75 = 0;
		__m_count_76 = 0;
		__m_carry_78 = 0;
		__m_latch_80 = 0;
		__m_count_82 = 0;
		__m_carry_84 = 0;
		__m_latch_91 = 0;
		__m_latch_92 = 0;
		__m_latch_94 = 0;
		__m_latch_95 = 0;
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
		int BILL_dim = m_BILL_21.dim;
		int BILL_channels = m_BILL_21.channels;
		int dim_4097 = BILL_dim;
		int BOUL_dim = m_BOUL_28.dim;
		int BOUL_channels = m_BOUL_28.channels;
		int dim_4148 = BOUL_dim;
		t_sample round_4066 = round(m_trigger_22);
		t_sample resetcountloop_4080 = round_4066;
		bool chan_ignore_34 = ((((int)1) < 0) || (((int)1) >= BOUL_channels));
		t_sample sub_4165 = (m_dry_wet_26 - ((t_sample)0.5));
		t_sample scale_4162 = ((safepow((sub_4165 * ((t_sample)2)), ((int)1)) * ((int)-1)) + ((int)1));
		t_sample min_3900 = ((((int)1) < scale_4162) ? ((int)1) : scale_4162);
		t_sample sub_4169 = (m_dry_wet_26 - ((int)0));
		t_sample scale_4166 = ((safepow((sub_4169 * ((t_sample)2)), ((int)1)) * ((int)1)) + ((int)0));
		t_sample min_3904 = ((((int)1) < scale_4166) ? ((int)1) : scale_4166);
		t_sample round_4067 = round(m_loop_27);
		t_sample startstoploop_4085 = round_4067;
		t_sample startstoploop_4087 = startstoploop_4085;
		int gte_3891 = (m_speed_24 >= ((t_sample)1.9));
		int mul_3890 = (gte_3891 * ((int)3));
		int lt_3889 = (m_speed_24 < ((t_sample)1.9));
		int mul_3892 = (lt_3889 * ((int)2));
		int lte_3888 = (m_speed_24 <= ((t_sample)0.6));
		int mul_3887 = (lte_3888 * ((int)1));
		int gt_3886 = (m_speed_24 > ((t_sample)0.6));
		int mul_3885 = (gt_3886 * ((int)2));
		__m_latch_36 = (((((gt_3886 + lte_3888) + lt_3889) + gte_3891) != 0) ? (((mul_3892 + mul_3885) + mul_3887) + mul_3890) : __m_latch_36);
		int latch_3897 = __m_latch_36;
		int sub_3884 = (latch_3897 - ((int)2));
		int choice_37 = sub_3884;
		t_sample selector_3896 = ((choice_37 >= 3) ? ((int)2) : ((choice_37 >= 2) ? ((int)1) : ((choice_37 >= 1) ? ((t_sample)0.5) : 0)));
		t_sample gen_3898 = selector_3896;
		t_sample speed_4104 = gen_3898;
		t_sample speed_4069 = speed_4104;
		t_sample choice_38 = int(startstoploop_4087);
		t_sample selector_4068 = ((choice_38 >= 1) ? speed_4069 : 0);
		int dim_4118 = BOUL_dim;
		int dim_4144 = BOUL_dim;
		t_sample speed_4105 = speed_4104;
		int dim_4112 = BOUL_dim;
		t_sample ramp_3882 = (round_4066 + round_4067);
		t_sample startstoploop_4107 = startstoploop_4085;
		t_sample speed_4103 = speed_4104;
		int dim_4131 = BOUL_dim;
		t_sample startstoploop_4106 = startstoploop_4085;
		t_sample speed_3830 = speed_4104;
		int irange_4171 = (dim_4118 - ((int)0));
		int orange_4172 = (((int)0) - dim_4118);
		int irange_4175 = (dim_4144 - ((int)0));
		int orange_4176 = (((int)0) - dim_4144);
		bool chan_ignore_63 = ((1 < 0) || (1 >= BOUL_channels));
		bool chan_ignore_66 = ((((int)1) < 0) || (((int)1) >= BILL_channels));
		t_sample resetcountloop_4078 = resetcountloop_4080;
		t_sample speed_4071 = speed_4104;
		int not_4079 = (!startstoploop_4085);
		t_sample speed_4088 = speed_4104;
		t_sample sub_4181 = (m_ENV_25 - ((int)0));
		t_sample scale_4178 = ((safepow((sub_4181 * ((t_sample)0.00033333333333333)), ((int)1)) * ((t_sample)-0.0099)) + ((t_sample)0.01));
		t_sample scale_3861 = scale_4178;
		t_sample mul_3836 = (m_ENV_25 * ((int)2));
		t_sample resetcountloop_4077 = resetcountloop_4080;
		t_sample count_reset_85 = (resetcountloop_4078 + startstoploop_4085);
		bool chan_ignore_89 = ((1 < 0) || (1 >= BILL_channels));
		int lte_3911 = (m_filter_23 <= ((int)0));
		int not_3910 = (!lte_3911);
		__m_latch_91 = ((not_3910 != 0) ? m_filter_23 : __m_latch_91);
		t_sample latch_3912 = __m_latch_91;
		t_sample sub_4185 = (latch_3912 - ((int)0));
		t_sample scale_4182 = ((safepow((sub_4185 * ((t_sample)0.01)), ((int)1)) * ((int)995)) + ((int)5));
		t_sample scale_3916 = scale_4182;
		int gte_3914 = (m_filter_23 >= ((int)0));
		int not_3913 = (!gte_3914);
		__m_latch_92 = ((not_3913 != 0) ? m_filter_23 : __m_latch_92);
		t_sample latch_3915 = __m_latch_92;
		t_sample sub_4189 = (latch_3915 - (-100));
		t_sample scale_4186 = ((safepow((sub_4189 * ((t_sample)0.01)), ((int)1)) * ((int)22500)) + ((int)500));
		t_sample scale_3917 = scale_4186;
		t_sample min_3954 = ((scale_3917 < ((int)0)) ? ((int)0) : scale_3917);
		t_sample omega = safediv((min_3954 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn = sin(omega);
		t_sample cs = cos(omega);
		t_sample alpha = ((sn * ((t_sample)0.5)) * ((int)2));
		t_sample b0 = safediv(((int)1), (((int)1) + alpha));
		t_sample a2 = (((((int)1) - cs) * ((t_sample)0.5)) * b0);
		t_sample a1 = ((((int)1) - cs) * b0);
		t_sample b1 = ((((int)-2) * cs) * b0);
		t_sample b2 = ((((int)1) - alpha) * b0);
		t_sample expr_3970 = a2;
		t_sample expr_3971 = a1;
		t_sample expr_3972 = a2;
		t_sample expr_3973 = b1;
		t_sample expr_3974 = b2;
		t_sample min_3926 = ((scale_3916 < ((int)0)) ? ((int)0) : scale_3916);
		t_sample omega_3980 = safediv((min_3926 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn_3983 = sin(omega_3980);
		t_sample cs_3979 = cos(omega_3980);
		t_sample alpha_3984 = ((sn_3983 * ((t_sample)0.5)) * ((t_sample)2));
		t_sample b_3976 = safediv(((int)1), (((int)1) + alpha_3984));
		t_sample a_3977 = (((((int)1) + cs_3979) * ((t_sample)0.5)) * b_3976);
		t_sample a_3982 = ((-(((int)1) + cs_3979)) * b_3976);
		t_sample b_3981 = ((((int)-2) * cs_3979) * b_3976);
		t_sample b_3978 = ((((int)1) - alpha_3984) * b_3976);
		t_sample expr_3942 = a_3977;
		t_sample expr_3943 = a_3982;
		t_sample expr_3944 = a_3977;
		t_sample expr_3945 = b_3981;
		t_sample expr_3946 = b_3978;
		int lte_3987 = (m_filter_23 <= ((int)0));
		int not_3986 = (!lte_3987);
		__m_latch_94 = ((not_3986 != 0) ? m_filter_23 : __m_latch_94);
		t_sample latch_3988 = __m_latch_94;
		t_sample sub_4193 = (latch_3988 - ((int)0));
		t_sample scale_4190 = ((safepow((sub_4193 * ((t_sample)0.01)), ((int)1)) * ((int)995)) + ((int)5));
		t_sample scale_3992 = scale_4190;
		int gte_3990 = (m_filter_23 >= ((int)0));
		int not_3989 = (!gte_3990);
		__m_latch_95 = ((not_3989 != 0) ? m_filter_23 : __m_latch_95);
		t_sample latch_3991 = __m_latch_95;
		t_sample sub_4197 = (latch_3991 - (-100));
		t_sample scale_4194 = ((safepow((sub_4197 * ((t_sample)0.01)), ((int)1)) * ((int)22500)) + ((int)500));
		t_sample scale_3993 = scale_4194;
		t_sample min_4030 = ((scale_3993 < ((int)0)) ? ((int)0) : scale_3993);
		t_sample omega_4159 = safediv((min_4030 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn_4160 = sin(omega_4159);
		t_sample cs_4158 = cos(omega_4159);
		t_sample alpha_4157 = ((sn_4160 * ((t_sample)0.5)) * ((int)2));
		t_sample b_4154 = safediv(((int)1), (((int)1) + alpha_4157));
		t_sample a_4152 = (((((int)1) - cs_4158) * ((t_sample)0.5)) * b_4154);
		t_sample a_4156 = ((((int)1) - cs_4158) * b_4154);
		t_sample b_4155 = ((((int)-2) * cs_4158) * b_4154);
		t_sample b_4153 = ((((int)1) - alpha_4157) * b_4154);
		t_sample expr_4046 = a_4152;
		t_sample expr_4047 = a_4156;
		t_sample expr_4048 = a_4152;
		t_sample expr_4049 = b_4155;
		t_sample expr_4050 = b_4153;
		t_sample min_4002 = ((scale_3992 < ((int)0)) ? ((int)0) : scale_3992);
		t_sample omega_4055 = safediv((min_4002 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn_4058 = sin(omega_4055);
		t_sample cs_4060 = cos(omega_4055);
		t_sample alpha_4059 = ((sn_4058 * ((t_sample)0.5)) * ((t_sample)2));
		t_sample b_4052 = safediv(((int)1), (((int)1) + alpha_4059));
		t_sample a_4053 = (((((int)1) + cs_4060) * ((t_sample)0.5)) * b_4052);
		t_sample a_4057 = ((-(((int)1) + cs_4060)) * b_4052);
		t_sample b_4056 = ((((int)-2) * cs_4060) * b_4052);
		t_sample b_4054 = ((((int)1) - alpha_4059) * b_4052);
		t_sample expr_4018 = a_4053;
		t_sample expr_4019 = a_4057;
		t_sample expr_4020 = a_4053;
		t_sample expr_4021 = b_4056;
		t_sample expr_4022 = b_4054;
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			__m_count_29 = (((int)0) ? 0 : (fixdenorm(__m_count_29 + ((int)1))));
			int carry_30 = 0;
			if ((((int)0) != 0)) {
				__m_count_29 = 0;
				__m_carry_31 = 0;
				
			} else if (((dim_4148 > 0) && (__m_count_29 >= dim_4148))) {
				int wraps_32 = (__m_count_29 / dim_4148);
				__m_carry_31 = (__m_carry_31 + wraps_32);
				__m_count_29 = (__m_count_29 - (wraps_32 * dim_4148));
				carry_30 = 1;
				
			};
			int counter_4149 = __m_count_29;
			int counter_4150 = carry_30;
			int counter_4151 = __m_carry_31;
			bool index_ignore_33 = ((counter_4149 >= BOUL_dim) || (counter_4149 < 0));
			if ((!index_ignore_33)) {
				m_BOUL_28.write(in1, counter_4149, 0);
				
			};
			bool index_ignore_35 = ((counter_4149 >= BOUL_dim) || (counter_4149 < 0));
			if ((!(chan_ignore_34 || index_ignore_35))) {
				m_BOUL_28.write(in2, counter_4149, ((int)1));
				
			};
			t_sample mul_4062 = (in2 * min_3900);
			t_sample mul_4063 = (in1 * min_3900);
			__m_count_39 = (resetcountloop_4080 ? 0 : (fixdenorm(__m_count_39 + selector_4068)));
			int carry_40 = 0;
			if ((resetcountloop_4080 != 0)) {
				__m_count_39 = 0;
				__m_carry_41 = 0;
				
			} else if (((dim_4097 > 0) && (__m_count_39 >= dim_4097))) {
				int wraps_42 = (__m_count_39 / dim_4097);
				__m_carry_41 = (__m_carry_41 + wraps_42);
				__m_count_39 = (__m_count_39 - (wraps_42 * dim_4097));
				carry_40 = 1;
				
			};
			t_sample counter_4098 = __m_count_39;
			int counter_4099 = carry_40;
			int counter_4100 = __m_carry_41;
			int count_4145 = counter_4149;
			int sah_4136 = __m_sah_43(count_4145, (round_4066 + round_4067), ((int)0));
			int sah_4119 = sah_4136;
			int sah_4120 = sah_4119;
			t_sample delta_3877 = __m_delta_44(ramp_3882);
			t_sample plusequals_3872 = __m_pluseq_45.post(((int)1), delta_3877, 0);
			t_sample sub_3873 = (ramp_3882 - m_history_20);
			__m_latch_46 = ((delta_3877 != 0) ? sub_3873 : __m_latch_46);
			t_sample latch_3875 = __m_latch_46;
			__m_latch_47 = ((delta_3877 != 0) ? ((int)400) : __m_latch_47);
			t_sample latch_3867 = __m_latch_47;
			int lt_3869 = (plusequals_3872 < latch_3867);
			t_sample div_3876 = safediv(latch_3875, latch_3867);
			t_sample mul_3870 = (lt_3869 * div_3876);
			t_sample add_3871 = (mul_3870 + m_history_20);
			t_sample gen_3879 = add_3871;
			t_sample history_3874_next_3878 = fixdenorm(add_3871);
			t_sample tap_4065 = m_delay_19.read_step(((int)400));
			t_sample trig_3827 = tap_4065;
			t_sample trig_4121 = trig_3827;
			int eq_4122 = ((startstoploop_4107 + trig_4121) == ((int)0));
			__m_count_48 = (eq_4122 ? 0 : (fixdenorm(__m_count_48 + speed_4104)));
			int carry_49 = 0;
			if ((eq_4122 != 0)) {
				__m_count_48 = 0;
				__m_carry_50 = 0;
				
			} else if (((sah_4120 > 0) && (__m_count_48 >= sah_4120))) {
				int wraps_51 = (__m_count_48 / sah_4120);
				__m_carry_50 = (__m_carry_50 + wraps_51);
				__m_count_48 = (__m_count_48 - (wraps_51 * sah_4120));
				carry_49 = 1;
				
			};
			t_sample counter_4125 = __m_count_48;
			int counter_4126 = carry_49;
			int counter_4127 = __m_carry_50;
			int endcountpart_4110 = counter_4127;
			int add_4124 = (endcountpart_4110 + ((int)1));
			int endcountpart_4109 = endcountpart_4110;
			int eq_4111 = (endcountpart_4109 == ((int)0));
			__m_count_52 = (eq_4111 ? 0 : (fixdenorm(__m_count_52 + speed_4105)));
			int carry_53 = 0;
			if ((eq_4111 != 0)) {
				__m_count_52 = 0;
				__m_carry_54 = 0;
				
			} else if (((dim_4112 > 0) && (__m_count_52 >= dim_4112))) {
				int wraps_55 = (__m_count_52 / dim_4112);
				__m_carry_54 = (__m_carry_54 + wraps_55);
				__m_count_52 = (__m_count_52 - (wraps_55 * dim_4112));
				carry_53 = 1;
				
			};
			t_sample counter_4113 = __m_count_52;
			int counter_4114 = carry_53;
			int counter_4115 = __m_carry_54;
			t_sample sub_4173 = (counter_4113 - ((int)0));
			t_sample scale_4170 = ((safepow(safediv(sub_4173, irange_4171), ((int)1)) * orange_4172) + dim_4118);
			t_sample scale_4117 = scale_4170;
			t_sample countpart_4108 = scale_4117;
			int not_3826 = (!trig_3827);
			t_sample trig_4123 = trig_3827;
			int eq_4130 = ((startstoploop_4106 + trig_4123) == ((int)0));
			__m_count_56 = (eq_4130 ? 0 : (fixdenorm(__m_count_56 + speed_4103)));
			int carry_57 = 0;
			if ((eq_4130 != 0)) {
				__m_count_56 = 0;
				__m_carry_58 = 0;
				
			} else if (((dim_4131 > 0) && (__m_count_56 >= dim_4131))) {
				int wraps_59 = (__m_count_56 / dim_4131);
				__m_carry_58 = (__m_carry_58 + wraps_59);
				__m_count_56 = (__m_count_56 - (wraps_59 * dim_4131));
				carry_57 = 1;
				
			};
			t_sample counter_4132 = __m_count_56;
			int counter_4133 = carry_57;
			int counter_4134 = __m_carry_58;
			t_sample sub_4177 = (counter_4132 - ((int)0));
			t_sample scale_4174 = ((safepow(safediv(sub_4177, irange_4175), ((int)1)) * orange_4176) + dim_4144);
			t_sample scale_4143 = scale_4174;
			t_sample sub_4128 = (scale_4143 - ((int)15336000));
			t_sample add_4129 = (sub_4128 + sah_4119);
			int choice_60 = add_4124;
			t_sample selector_4135 = ((choice_60 >= 2) ? countpart_4108 : ((choice_60 >= 1) ? add_4129 : 0));
			int index_trunc_61 = fixnan(floor(selector_4135));
			bool index_ignore_62 = ((index_trunc_61 >= BOUL_dim) || (index_trunc_61 < 0));
			// samples BOUL channel 1;
			// samples BOUL channel 2;
			t_sample sample_BOUL_4137 = (index_ignore_62 ? 0 : m_BOUL_28.read(index_trunc_61, 0));
			t_sample sample_BOUL_4138 = ((chan_ignore_63 || index_ignore_62) ? 0 : m_BOUL_28.read(index_trunc_61, 1));
			t_sample index_BOUL_4139 = selector_4135;
			t_sample recloop_4096 = sample_BOUL_4137;
			int index_trunc_64 = fixnan(floor(counter_4098));
			bool index_ignore_65 = ((index_trunc_64 >= BILL_dim) || (index_trunc_64 < 0));
			if ((!index_ignore_65)) {
				m_BILL_21.write(recloop_4096, index_trunc_64, 0);
				
			};
			t_sample recloop_3866 = recloop_4096;
			t_sample mul_3881 = (recloop_3866 * gen_3879);
			t_sample recloop_3863 = sample_BOUL_4138;
			t_sample recloop_4095 = recloop_3863;
			int index_trunc_67 = fixnan(floor(counter_4098));
			bool index_ignore_68 = ((index_trunc_67 >= BILL_dim) || (index_trunc_67 < 0));
			if ((!(chan_ignore_66 || index_ignore_68))) {
				m_BILL_21.write(recloop_4095, index_trunc_67, ((int)1));
				
			};
			t_sample mul_3883 = (recloop_3863 * gen_3879);
			t_sample sah_4086 = __m_sah_69(counter_4098, not_4079, ((int)0));
			t_sample sahloop_3835 = sah_4086;
			t_sample div_3831 = safediv(sahloop_3835, speed_3830);
			t_sample sahloop_3899 = sahloop_3835;
			int bool_4073 = (counter_4098 != 0);
			int openreset_4072 = bool_4073;
			int choice_70 = openreset_4072;
			t_sample selector_4070 = ((choice_70 >= 1) ? speed_4071 : 0);
			t_sample startloopramp_3834 = selector_4070;
			int gt_3832 = (startloopramp_3834 > ((int)0));
			t_sample tap_3838 = m_delay_18.read_linear(m_ENV_25);
			t_sample delta_3849 = __m_delta_71(tap_3838);
			__m_latch_72 = ((delta_3849 != 0) ? m_history_17 : __m_latch_72);
			t_sample latch_3844 = __m_latch_72;
			__m_latch_73 = ((delta_3849 != 0) ? tap_3838 : __m_latch_73);
			t_sample latch_3846 = __m_latch_73;
			t_sample plusequals_3848 = __m_pluseq_74.post(((int)1), delta_3849, 0);
			__m_latch_75 = ((delta_3849 != 0) ? scale_3861 : __m_latch_75);
			t_sample latch_3843 = __m_latch_75;
			t_sample mul_3847 = (plusequals_3848 * latch_3843);
			t_sample clamp_3845 = ((mul_3847 <= ((int)0)) ? ((int)0) : ((mul_3847 >= ((int)1)) ? ((int)1) : mul_3847));
			t_sample anon_3850 = linear_interp(clamp_3845, latch_3844, latch_3846);
			t_sample gen_3852 = anon_3850;
			t_sample history_3840_next_3851 = fixdenorm(anon_3850);
			t_sample gen_3862 = gen_3852;
			t_sample sub_3855 = (div_3831 - mul_3836);
			int eq_3857 = (gt_3832 == ((int)0));
			__m_count_76 = (eq_3857 ? 0 : (fixdenorm(__m_count_76 + ((int)1))));
			int carry_77 = 0;
			if ((eq_3857 != 0)) {
				__m_count_76 = 0;
				__m_carry_78 = 0;
				
			} else if (((div_3831 > 0) && (__m_count_76 >= div_3831))) {
				int wraps_79 = (__m_count_76 / div_3831);
				__m_carry_78 = (__m_carry_78 + wraps_79);
				__m_count_76 = (__m_count_76 - (wraps_79 * div_3831));
				carry_77 = 1;
				
			};
			int counter_3858 = __m_count_76;
			int counter_3859 = carry_77;
			int counter_3860 = __m_carry_78;
			int gte_3854 = (counter_3858 >= sub_3855);
			int not_3839 = (!gte_3854);
			t_sample envelop_Loop_3833 = gen_3862;
			int openreset_4074 = openreset_4072;
			__m_latch_80 = ((openreset_4074 != 0) ? resetcountloop_4077 : __m_latch_80);
			t_sample latch_4076 = __m_latch_80;
			int not_4075 = (!latch_4076);
			int choice_81 = not_4075;
			t_sample selector_4082 = ((choice_81 >= 2) ? speed_4088 : ((choice_81 >= 1) ? ((int)0) : 0));
			__m_count_82 = ((resetcountloop_4078 + startstoploop_4085) ? 0 : (fixdenorm(__m_count_82 + (selector_4070 + selector_4082))));
			int carry_83 = 0;
			if ((count_reset_85 != 0)) {
				__m_count_82 = 0;
				__m_carry_84 = 0;
				
			} else if (((sahloop_3899 > 0) && (__m_count_82 >= sahloop_3899))) {
				int wraps_86 = (__m_count_82 / sahloop_3899);
				__m_carry_84 = (__m_carry_84 + wraps_86);
				__m_count_82 = (__m_count_82 - (wraps_86 * sahloop_3899));
				carry_83 = 1;
				
			};
			t_sample counter_4089 = __m_count_82;
			int counter_4090 = carry_83;
			int counter_4091 = __m_carry_84;
			int index_trunc_87 = fixnan(floor(counter_4089));
			bool index_ignore_88 = ((index_trunc_87 >= BILL_dim) || (index_trunc_87 < 0));
			// samples BILL channel 1;
			// samples BILL channel 2;
			t_sample sample_BILL_4092 = (index_ignore_88 ? 0 : m_BILL_21.read(index_trunc_87, 0));
			t_sample sample_BILL_4093 = ((chan_ignore_89 || index_ignore_88) ? 0 : m_BILL_21.read(index_trunc_87, 1));
			t_sample index_BILL_4094 = counter_4089;
			int choice_90 = not_3826;
			t_sample selector_3828 = ((choice_90 >= 1) ? sample_BILL_4093 : 0);
			t_sample loop_4083 = selector_3828;
			t_sample mul_3907 = (envelop_Loop_3833 * loop_4083);
			t_sample add_3864 = (mul_3907 + mul_3883);
			t_sample mul_3964 = (add_3864 * expr_3970);
			t_sample mul_3961 = (m_history_14 * expr_3971);
			t_sample mul_3959 = (m_history_15 * expr_3972);
			t_sample mul_3955 = (m_history_16 * expr_3974);
			t_sample mul_3957 = (m_history_13 * expr_3973);
			t_sample sub_3963 = (((mul_3959 + mul_3961) + mul_3964) - (mul_3957 + mul_3955));
			t_sample gen_3969 = sub_3963;
			t_sample history_3956_next_3965 = fixdenorm(m_history_13);
			t_sample history_3960_next_3966 = fixdenorm(m_history_14);
			t_sample history_3962_next_3967 = fixdenorm(add_3864);
			t_sample history_3958_next_3968 = fixdenorm(sub_3963);
			t_sample gen_3975 = gen_3969;
			t_sample mul_3936 = (gen_3975 * expr_3942);
			t_sample mul_3933 = (m_history_10 * expr_3943);
			t_sample mul_3931 = (m_history_11 * expr_3944);
			t_sample mul_3927 = (m_history_12 * expr_3946);
			t_sample mul_3929 = (m_history_9 * expr_3945);
			t_sample sub_3935 = (((mul_3931 + mul_3933) + mul_3936) - (mul_3929 + mul_3927));
			t_sample gen_3941 = sub_3935;
			t_sample history_3928_next_3937 = fixdenorm(m_history_9);
			t_sample history_3932_next_3938 = fixdenorm(m_history_10);
			t_sample history_3934_next_3939 = fixdenorm(gen_3975);
			t_sample history_3930_next_3940 = fixdenorm(sub_3935);
			t_sample mul_3902 = (gen_3941 * min_3904);
			t_sample add_3909 = (mul_4062 + mul_3902);
			t_sample out2 = add_3909;
			int choice_93 = not_3826;
			t_sample selector_3829 = ((choice_93 >= 1) ? sample_BILL_4092 : 0);
			t_sample loop_4084 = selector_3829;
			t_sample mul_3906 = (envelop_Loop_3833 * loop_4084);
			t_sample add_3865 = (mul_3906 + mul_3881);
			t_sample mul_4040 = (add_3865 * expr_4046);
			t_sample mul_4037 = (m_history_6 * expr_4047);
			t_sample mul_4035 = (m_history_7 * expr_4048);
			t_sample mul_4031 = (m_history_8 * expr_4050);
			t_sample mul_4033 = (m_history_5 * expr_4049);
			t_sample sub_4039 = (((mul_4035 + mul_4037) + mul_4040) - (mul_4033 + mul_4031));
			t_sample gen_4045 = sub_4039;
			t_sample history_4032_next_4041 = fixdenorm(m_history_5);
			t_sample history_4036_next_4042 = fixdenorm(m_history_6);
			t_sample history_4038_next_4043 = fixdenorm(add_3865);
			t_sample history_4034_next_4044 = fixdenorm(sub_4039);
			t_sample gen_4051 = gen_4045;
			t_sample mul_4012 = (gen_4051 * expr_4018);
			t_sample mul_4009 = (m_history_2 * expr_4019);
			t_sample mul_4007 = (m_history_4 * expr_4020);
			t_sample mul_4003 = (m_history_3 * expr_4022);
			t_sample mul_4005 = (m_history_1 * expr_4021);
			t_sample sub_4011 = (((mul_4007 + mul_4009) + mul_4012) - (mul_4005 + mul_4003));
			t_sample gen_4017 = sub_4011;
			t_sample history_4008_next_4013 = fixdenorm(m_history_2);
			t_sample history_4004_next_4014 = fixdenorm(m_history_1);
			t_sample history_4010_next_4015 = fixdenorm(gen_4051);
			t_sample history_4006_next_4016 = fixdenorm(sub_4011);
			t_sample mul_3903 = (gen_4017 * min_3904);
			t_sample add_3908 = (mul_4063 + mul_3903);
			t_sample out1 = add_3908;
			m_history_20 = history_3874_next_3878;
			m_delay_19.write(round_4066);
			m_delay_18.write(not_3839);
			m_history_17 = history_3840_next_3851;
			m_history_16 = history_3956_next_3965;
			m_history_9 = history_3930_next_3940;
			m_history_10 = history_3934_next_3939;
			m_history_11 = history_3932_next_3938;
			m_history_12 = history_3928_next_3937;
			m_history_13 = history_3958_next_3968;
			m_history_14 = history_3962_next_3967;
			m_history_15 = history_3960_next_3966;
			m_history_8 = history_4032_next_4041;
			m_history_1 = history_4006_next_4016;
			m_history_2 = history_4010_next_4015;
			m_history_3 = history_4004_next_4014;
			m_history_4 = history_4008_next_4013;
			m_history_5 = history_4034_next_4044;
			m_history_6 = history_4038_next_4043;
			m_history_7 = history_4036_next_4042;
			m_delay_18.step();
			m_delay_19.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			
		};
		return __exception;
		
	};
	inline void set_BILL(void * _value) {
		m_BILL_21.setbuffer(_value);
	};
	inline void set_trigger(t_param _value) {
		m_trigger_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_filter(t_param _value) {
		m_filter_23 = (_value < -100 ? -100 : (_value > 100 ? 100 : _value));
	};
	inline void set_speed(t_param _value) {
		m_speed_24 = (_value < 0.5 ? 0.5 : (_value > 2 ? 2 : _value));
	};
	inline void set_ENV(t_param _value) {
		m_ENV_25 = (_value < 0 ? 0 : (_value > 2900 ? 2900 : _value));
	};
	inline void set_dry_wet(t_param _value) {
		m_dry_wet_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loop(t_param _value) {
		m_loop_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_BOUL(void * _value) {
		m_BOUL_28.setbuffer(_value);
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
int num_params() { return 8; }

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
		case 3: self->set_dry_wet(value); break;
		case 4: self->set_filter(value); break;
		case 5: self->set_loop(value); break;
		case 6: self->set_speed(value); break;
		case 7: self->set_trigger(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		
		
		case 2: *value = self->m_ENV_25; break;
		case 3: *value = self->m_dry_wet_26; break;
		case 4: *value = self->m_filter_23; break;
		case 5: *value = self->m_loop_27; break;
		case 6: *value = self->m_speed_24; break;
		case 7: *value = self->m_trigger_22; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(8 * sizeof(ParamInfo));
	self->__commonstate.numparams = 8;
	// initialize parameter 0 ("m_BILL_21")
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
	// initialize parameter 1 ("m_BOUL_28")
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
	// initialize parameter 2 ("m_ENV_25")
	pi = self->__commonstate.params + 2;
	pi->name = "ENV";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ENV_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2900;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_dry_wet_26")
	pi = self->__commonstate.params + 3;
	pi->name = "dry_wet";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_dry_wet_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_filter_23")
	pi = self->__commonstate.params + 4;
	pi->name = "filter";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_filter_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -100;
	pi->outputmax = 100;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_loop_27")
	pi = self->__commonstate.params + 5;
	pi->name = "loop";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_loop_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_speed_24")
	pi = self->__commonstate.params + 6;
	pi->name = "speed";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_speed_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.5;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_trigger_22")
	pi = self->__commonstate.params + 7;
	pi->name = "trigger";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_trigger_22;
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


} // MIRRORZ::
