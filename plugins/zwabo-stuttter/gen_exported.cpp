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
	Data m_RIGHT_11;
	Data m_LEFT_17;
	Delay m_delay_19;
	Delay m_delay_10;
	Delay m_delay_20;
	Delay m_delay_13;
	Delay m_delay_16;
	Delay m_delay_14;
	Delta __m_delta_78;
	Delta __m_delta_52;
	PlusEquals __m_pluseq_55;
	PlusEquals __m_pluseq_81;
	Sah __m_sah_36;
	Sah __m_sah_34;
	Sah __m_sah_35;
	int vectorsize;
	int __exception;
	t_sample __m_latch_54;
	t_sample __m_carry_47;
	t_sample __m_latch_53;
	t_sample __m_count_43;
	t_sample __m_count_45;
	t_sample __m_count_57;
	t_sample m_BPM_33;
	t_sample __m_latch_82;
	t_sample __m_latch_80;
	t_sample __m_count_83;
	t_sample __m_carry_85;
	t_sample __m_latch_56;
	t_sample __m_latch_79;
	t_sample __m_count_71;
	t_sample __m_carry_73;
	t_sample __m_carry_59;
	t_sample __m_count_69;
	t_sample m_Filter_R_32;
	t_sample m_Div_R_28;
	t_sample m_RANGE_30;
	t_sample m_history_6;
	t_sample m_history_5;
	t_sample m_history_7;
	t_sample m_history_8;
	t_sample m_history_9;
	t_sample m_history_4;
	t_sample m_history_2;
	t_sample m_history_3;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample m_reverse_31;
	t_sample m_history_12;
	t_sample m_history_18;
	t_sample m_dry_wet_27;
	t_sample m_DOUBLE_26;
	t_sample __m_latch_89;
	t_sample m_ztutter_29;
	t_sample m_history_15;
	t_sample m_speed_25;
	t_sample m_Tail_23;
	t_sample m_Div_L_24;
	t_sample m_RANDOM_21;
	t_sample m_ENV_ms_22;
	t_sample __m_latch_90;
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
		m_delay_10.reset("m_delay_10", samplerate);
		m_RIGHT_11.reset("RIGHT", ((int)192000), ((int)1));
		m_history_12 = ((int)0);
		m_delay_13.reset("m_delay_13", ((int)48000));
		m_delay_14.reset("m_delay_14", samplerate);
		m_history_15 = ((int)0);
		m_delay_16.reset("m_delay_16", samplerate);
		m_LEFT_17.reset("LEFT", ((int)192000), ((int)1));
		m_history_18 = ((int)0);
		m_delay_19.reset("m_delay_19", ((int)48000));
		m_delay_20.reset("m_delay_20", samplerate);
		m_RANDOM_21 = 0;
		m_ENV_ms_22 = 20;
		m_Tail_23 = 0;
		m_Div_L_24 = 1;
		m_speed_25 = 1;
		m_DOUBLE_26 = 0;
		m_dry_wet_27 = 0.5;
		m_Div_R_28 = 3;
		m_ztutter_29 = 0;
		m_RANGE_30 = 5;
		m_reverse_31 = 0;
		m_Filter_R_32 = 0;
		m_BPM_33 = 120;
		__m_sah_34.reset(0);
		__m_sah_35.reset(0);
		__m_sah_36.reset(0);
		__m_count_43 = 0;
		__m_count_45 = 0;
		__m_carry_47 = 0;
		__m_delta_52.reset(0);
		__m_latch_53 = 0;
		__m_latch_54 = 0;
		__m_pluseq_55.reset(0);
		__m_latch_56 = 0;
		__m_count_57 = 0;
		__m_carry_59 = 0;
		__m_count_69 = 0;
		__m_count_71 = 0;
		__m_carry_73 = 0;
		__m_delta_78.reset(0);
		__m_latch_79 = 0;
		__m_latch_80 = 0;
		__m_pluseq_81.reset(0);
		__m_latch_82 = 0;
		__m_count_83 = 0;
		__m_carry_85 = 0;
		__m_latch_89 = 0;
		__m_latch_90 = 0;
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
		t_sample sub_389 = (m_dry_wet_27 - ((t_sample)0.5));
		t_sample scale_386 = ((safepow((sub_389 * ((t_sample)2)), ((int)1)) * ((int)-1)) + ((int)1));
		t_sample scale_378 = scale_386;
		t_sample min_377 = ((((int)1) < scale_378) ? ((int)1) : scale_378);
		t_sample sub_393 = (m_dry_wet_27 - ((int)0));
		t_sample scale_390 = ((safepow((sub_393 * ((t_sample)2)), ((int)1)) * ((int)1)) + ((int)0));
		t_sample scale_277 = scale_390;
		t_sample min_380 = ((((int)1) < scale_277) ? ((int)1) : scale_277);
		t_sample tail_256 = m_Tail_23;
		t_sample tail_255 = tail_256;
		t_sample stutt_46 = m_ztutter_29;
		t_sample stutt_384 = stutt_46;
		t_sample add_383 = (stutt_384 + ((int)1));
		t_sample stutt_365 = stutt_46;
		t_sample add_364 = (stutt_365 + ((int)1));
		t_sample stutt_257 = stutt_46;
		t_sample speed_68 = m_speed_25;
		t_sample speed_3 = speed_68;
		t_sample stutt_280 = stutt_46;
		t_sample add_66 = (m_reverse_31 + ((int)1));
		t_sample reverse_2 = add_66;
		t_sample reverse_67 = reverse_2;
		t_sample stutt_278 = stutt_46;
		t_sample add_283 = (m_DOUBLE_26 + ((int)1));
		t_sample add_187 = (m_RANDOM_21 + ((int)1));
		t_sample randomsel_242 = add_187;
		t_sample randomsel_247 = randomsel_242;
		t_sample randomsel_244 = randomsel_242;
		t_sample stutt_188 = stutt_46;
		int not_186 = (!stutt_188);
		t_sample add_208 = (((int)0) + m_RANGE_30);
		t_sample orange_400 = (add_208 - ((int)0));
		t_sample mul_192 = (((t_sample)0.5) * m_RANGE_30);
		t_sample orange_408 = (mul_192 - ((t_sample)0.5));
		t_sample add_224 = (((int)0) + m_RANGE_30);
		t_sample orange_416 = (add_224 - ((int)0));
		t_sample choice_37 = int(randomsel_247);
		t_sample choice_39 = int(randomsel_242);
		t_sample add_266 = (stutt_257 + ((int)1));
		t_sample choice_40 = int(add_266);
		t_sample add_259 = (stutt_257 + ((int)1));
		t_sample choice_41 = int(add_259);
		t_sample selector_260 = ((choice_41 >= 2) ? ((int)1) : ((choice_41 >= 1) ? ((t_sample)0.45) : 0));
		int not_69 = (!stutt_257);
		int LEFT_dim = m_LEFT_17.dim;
		int LEFT_channels = m_LEFT_17.channels;
		t_sample choice_49 = int(reverse_67);
		t_sample sub_425 = (m_ENV_ms_22 - ((int)0));
		t_sample scale_422 = ((safepow((sub_425 * ((t_sample)0.00033333333333333)), ((int)1)) * ((t_sample)-0.0099)) + ((t_sample)0.01));
		t_sample scale_348 = scale_422;
		t_sample mul_325 = (m_ENV_ms_22 * ((int)2));
		int eq_344 = (stutt_280 == ((int)0));
		t_sample choice_61 = int(add_383);
		int min_62 = (-1);
		t_sample choice_63 = int(randomsel_244);
		t_sample choice_65 = int(add_283);
		t_sample add_55 = (stutt_46 + ((int)1));
		t_sample choice_66 = int(add_55);
		t_sample add_48 = (stutt_46 + ((int)1));
		t_sample choice_67 = int(add_48);
		t_sample selector_49 = ((choice_67 >= 2) ? ((int)1) : ((choice_67 >= 1) ? ((t_sample)0.45) : 0));
		int not_4 = (!stutt_46);
		int RIGHT_dim = m_RIGHT_11.dim;
		int RIGHT_channels = m_RIGHT_11.channels;
		t_sample choice_75 = int(reverse_2);
		t_sample sub_433 = (m_ENV_ms_22 - ((int)0));
		t_sample scale_430 = ((safepow((sub_433 * ((t_sample)0.00033333333333333)), ((int)1)) * ((t_sample)-0.0099)) + ((t_sample)0.01));
		t_sample scale_323 = scale_430;
		t_sample mul_300 = (m_ENV_ms_22 * ((int)2));
		int eq_319 = (stutt_278 == ((int)0));
		t_sample choice_87 = int(add_364);
		int min_88 = (-1);
		int lte_111 = (m_Filter_R_32 <= ((int)0));
		int not_110 = (!lte_111);
		__m_latch_89 = ((not_110 != 0) ? m_Filter_R_32 : __m_latch_89);
		t_sample latch_112 = __m_latch_89;
		t_sample sub_437 = (latch_112 - ((int)0));
		t_sample scale_434 = ((safepow((sub_437 * ((t_sample)0.01)), ((int)1)) * ((int)995)) + ((int)5));
		t_sample scale_116 = scale_434;
		int gte_114 = (m_Filter_R_32 >= ((int)0));
		int not_113 = (!gte_114);
		__m_latch_90 = ((not_113 != 0) ? m_Filter_R_32 : __m_latch_90);
		t_sample latch_115 = __m_latch_90;
		t_sample sub_441 = (latch_115 - (-100));
		t_sample scale_438 = ((safepow((sub_441 * ((t_sample)0.01)), ((int)1)) * ((int)22500)) + ((int)500));
		t_sample scale_117 = scale_438;
		t_sample min_154 = ((scale_117 < ((int)0)) ? ((int)0) : scale_117);
		t_sample omega = safediv((min_154 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn = sin(omega);
		t_sample cs = cos(omega);
		t_sample alpha = ((sn * ((t_sample)0.5)) * ((int)2));
		t_sample b0 = safediv(((int)1), (((int)1) + alpha));
		t_sample a2 = (((((int)1) - cs) * ((t_sample)0.5)) * b0);
		t_sample a1 = ((((int)1) - cs) * b0);
		t_sample b1 = ((((int)-2) * cs) * b0);
		t_sample b2 = ((((int)1) - alpha) * b0);
		t_sample expr_170 = a2;
		t_sample expr_171 = a1;
		t_sample expr_172 = a2;
		t_sample expr_173 = b1;
		t_sample expr_174 = b2;
		t_sample min_126 = ((scale_116 < ((int)0)) ? ((int)0) : scale_116);
		t_sample omega_178 = safediv((min_126 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn_182 = sin(omega_178);
		t_sample cs_181 = cos(omega_178);
		t_sample alpha_183 = ((sn_182 * ((t_sample)0.5)) * ((t_sample)2));
		t_sample b_176 = safediv(((int)1), (((int)1) + alpha_183));
		t_sample a_184 = (((((int)1) + cs_181) * ((t_sample)0.5)) * b_176);
		t_sample a_180 = ((-(((int)1) + cs_181)) * b_176);
		t_sample b_179 = ((((int)-2) * cs_181) * b_176);
		t_sample b_177 = ((((int)1) - alpha_183) * b_176);
		t_sample expr_142 = a_184;
		t_sample expr_143 = a_180;
		t_sample expr_144 = a_184;
		t_sample expr_145 = b_179;
		t_sample expr_146 = b_177;
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample mul_382 = (in1 * min_377);
			t_sample mul_363 = (in2 * min_377);
			t_sample noise_216 = noise();
			t_sample noise_218 = noise();
			t_sample noise_219 = noise();
			t_sample wrap_217 = wrap(noise_219, noise_216, noise_218);
			t_sample irange_395 = (noise_218 - noise_216);
			t_sample sub_397 = (wrap_217 - noise_216);
			t_sample scale_394 = ((safepow(safediv(sub_397, irange_395), ((int)1)) * ((int)1)) + ((int)0));
			t_sample scale_215 = scale_394;
			t_sample sub_401 = (scale_215 - ((int)0));
			t_sample scale_398 = ((safepow((sub_401 * ((t_sample)1)), ((int)1)) * orange_400) + ((int)0));
			t_sample scale_211 = scale_398;
			t_sample ceil_206 = ceil(scale_211);
			t_sample sah_205 = __m_sah_34(ceil_206, not_186, ((int)0));
			t_sample gen_220 = sah_205;
			t_sample gen_238 = gen_220;
			t_sample noise_200 = noise();
			t_sample noise_202 = noise();
			t_sample noise_203 = noise();
			t_sample wrap_201 = wrap(noise_203, noise_200, noise_202);
			t_sample irange_403 = (noise_202 - noise_200);
			t_sample sub_405 = (wrap_201 - noise_200);
			t_sample scale_402 = ((safepow(safediv(sub_405, irange_403), ((int)1)) * ((int)1)) + ((int)0));
			t_sample scale_199 = scale_402;
			t_sample sub_409 = (scale_199 - ((int)0));
			t_sample scale_406 = ((safepow((sub_409 * ((t_sample)1)), ((int)1)) * orange_408) + ((t_sample)0.5));
			t_sample scale_195 = scale_406;
			t_sample ceil_190 = ceil(scale_195);
			t_sample sah_189 = __m_sah_35(ceil_190, not_186, ((int)0));
			t_sample gen_204 = sah_189;
			t_sample gen_239 = gen_204;
			t_sample noise_232 = noise();
			t_sample noise_234 = noise();
			t_sample noise_235 = noise();
			t_sample wrap_233 = wrap(noise_235, noise_232, noise_234);
			t_sample irange_411 = (noise_234 - noise_232);
			t_sample sub_413 = (wrap_233 - noise_232);
			t_sample scale_410 = ((safepow(safediv(sub_413, irange_411), ((int)1)) * ((int)1)) + ((int)0));
			t_sample scale_231 = scale_410;
			t_sample sub_417 = (scale_231 - ((int)0));
			t_sample scale_414 = ((safepow((sub_417 * ((t_sample)1)), ((int)1)) * orange_416) + ((int)0));
			t_sample scale_227 = scale_414;
			t_sample ceil_222 = ceil(scale_227);
			t_sample sah_221 = __m_sah_36(ceil_222, not_186, ((int)0));
			t_sample gen_236 = sah_221;
			t_sample gen_237 = gen_236;
			t_sample Div_248 = gen_237;
			t_sample selector_249 = ((choice_37 >= 2) ? Div_248 : ((choice_37 >= 1) ? m_Div_L_24 : 0));
			t_sample choice_38 = int(selector_249);
			t_sample selector_375 = ((choice_38 >= 10) ? ((t_sample)0.090909) : ((choice_38 >= 9) ? ((t_sample)0.111111) : ((choice_38 >= 8) ? ((t_sample)0.142857) : ((choice_38 >= 7) ? ((t_sample)0.2) : ((choice_38 >= 6) ? ((t_sample)0.25) : ((choice_38 >= 5) ? ((t_sample)0.3335) : ((choice_38 >= 4) ? ((t_sample)0.5) : ((choice_38 >= 3) ? ((t_sample)0.667) : ((choice_38 >= 2) ? ((t_sample)0.75) : ((choice_38 >= 1) ? ((int)1) : 0))))))))));
			t_sample MultBPM_241 = gen_239;
			t_sample mul_240 = (m_BPM_33 * MultBPM_241);
			t_sample selector_243 = ((choice_39 >= 2) ? mul_240 : ((choice_39 >= 1) ? m_BPM_33 : 0));
			t_sample rdiv_356 = safediv(((int)60), selector_243);
			t_sample mul_370 = (rdiv_356 * selector_375);
			t_sample mul_355 = (mul_370 * ((int)1000));
			t_sample mstosamps_376 = (mul_355 * (samplerate * 0.001));
			t_sample pass_251 = mstosamps_376;
			t_sample timesamples_L_281 = pass_251;
			t_sample timesamples_L_252 = timesamples_L_281;
			t_sample tap_274 = m_delay_20.read_linear(timesamples_L_252);
			t_sample fold_271 = fold(tap_274, (-1), ((int)1));
			t_sample mul_262 = (fold_271 * ((int)1));
			t_sample tap_264 = m_delay_19.read_step(((int)48000));
			t_sample selector_267 = ((choice_40 >= 2) ? tap_264 : ((choice_40 >= 1) ? ((int)1) : 0));
			t_sample add_265 = (selector_267 + ((int)1));
			t_sample mul_272 = (m_history_18 * selector_260);
			t_sample choice_42 = int(add_265);
			t_sample selector_269 = ((choice_42 >= 2) ? mul_272 : ((choice_42 >= 1) ? in1 : 0));
			t_sample history_270_next_275 = fixdenorm(fold_271);
			t_sample mul_254 = (mul_262 * tail_256);
			__m_count_43 = (not_69 ? 0 : (fixdenorm(__m_count_43 + ((int)1))));
			int counter_104 = __m_count_43;
			int counter_105 = ((int)0);
			int counter_106 = ((int)0);
			int clamp_102 = ((counter_104 <= ((int)0)) ? ((int)0) : ((counter_104 >= ((int)191999)) ? ((int)191999) : counter_104));
			bool index_ignore_44 = ((clamp_102 >= LEFT_dim) || (clamp_102 < 0));
			if ((!index_ignore_44)) {
				m_LEFT_17.write(in1, clamp_102, 0);
				
			};
			__m_count_45 = (not_69 ? 0 : (fixdenorm(__m_count_45 + speed_68)));
			int carry_46 = 0;
			if ((not_69 != 0)) {
				__m_count_45 = 0;
				__m_carry_47 = 0;
				
			} else if (((timesamples_L_252 > 0) && (__m_count_45 >= timesamples_L_252))) {
				int wraps_48 = (__m_count_45 / timesamples_L_252);
				__m_carry_47 = (__m_carry_47 + wraps_48);
				__m_count_45 = (__m_count_45 - (wraps_48 * timesamples_L_252));
				carry_46 = 1;
				
			};
			t_sample counter_97 = __m_count_45;
			int counter_98 = carry_46;
			int counter_99 = __m_carry_47;
			t_sample clamp_96 = ((counter_97 <= ((int)0)) ? ((int)0) : ((counter_97 >= ((int)191999)) ? ((int)191999) : counter_97));
			t_sample irange_419 = (timesamples_L_252 - ((int)0));
			t_sample orange_420 = (((int)0) - timesamples_L_252);
			t_sample sub_421 = (clamp_96 - ((int)0));
			t_sample scale_418 = ((safepow(safediv(sub_421, irange_419), ((int)1)) * orange_420) + timesamples_L_252);
			t_sample selector_92 = ((choice_49 >= 2) ? scale_418 : ((choice_49 >= 1) ? clamp_96 : 0));
			int index_trunc_50 = fixnan(floor(selector_92));
			bool index_ignore_51 = ((index_trunc_50 >= LEFT_dim) || (index_trunc_50 < 0));
			// samples LEFT channel 1;
			t_sample sample_LEFT_100 = (index_ignore_51 ? 0 : m_LEFT_17.read(index_trunc_50, 0));
			t_sample index_LEFT_101 = selector_92;
			t_sample tap_327 = m_delay_16.read_linear(m_ENV_ms_22);
			t_sample delta_337 = __m_delta_52(tap_327);
			__m_latch_53 = ((delta_337 != 0) ? m_history_15 : __m_latch_53);
			t_sample latch_332 = __m_latch_53;
			__m_latch_54 = ((delta_337 != 0) ? tap_327 : __m_latch_54);
			t_sample latch_334 = __m_latch_54;
			t_sample plusequals_336 = __m_pluseq_55.post(((int)1), delta_337, 0);
			__m_latch_56 = ((delta_337 != 0) ? scale_348 : __m_latch_56);
			t_sample latch_331 = __m_latch_56;
			t_sample mul_335 = (plusequals_336 * latch_331);
			t_sample clamp_333 = ((mul_335 <= ((int)0)) ? ((int)0) : ((mul_335 >= ((int)1)) ? ((int)1) : mul_335));
			t_sample anon_338 = linear_interp(clamp_333, latch_332, latch_334);
			t_sample gen_340 = anon_338;
			t_sample history_329_next_339 = fixdenorm(anon_338);
			t_sample sub_342 = (timesamples_L_281 - mul_325);
			__m_count_57 = (eq_344 ? 0 : (fixdenorm(__m_count_57 + ((int)1))));
			int carry_58 = 0;
			if ((eq_344 != 0)) {
				__m_count_57 = 0;
				__m_carry_59 = 0;
				
			} else if (((timesamples_L_281 > 0) && (__m_count_57 >= timesamples_L_281))) {
				int wraps_60 = (__m_count_57 / timesamples_L_281);
				__m_carry_59 = (__m_carry_59 + wraps_60);
				__m_count_57 = (__m_count_57 - (wraps_60 * timesamples_L_281));
				carry_58 = 1;
				
			};
			int counter_345 = __m_count_57;
			int counter_346 = carry_58;
			int counter_347 = __m_carry_59;
			int gte_341 = (counter_345 >= sub_342);
			int not_328 = (!gte_341);
			t_sample mul_368 = (sample_LEFT_100 * gen_340);
			t_sample selector_385 = ((choice_61 >= 2) ? mul_368 : ((choice_61 >= 1) ? mul_254 : 0));
			t_sample mul_379 = (selector_385 * min_380);
			t_sample add_381 = (mul_382 + mul_379);
			t_sample clamp_358 = ((add_381 <= min_62) ? min_62 : ((add_381 >= ((int)1)) ? ((int)1) : add_381));
			t_sample out1 = clamp_358;
			t_sample rdiv_291 = safediv(((int)60), selector_243);
			t_sample Div_245 = gen_238;
			t_sample selector_246 = ((choice_63 >= 2) ? Div_245 : ((choice_63 >= 1) ? m_Div_R_28 : 0));
			t_sample choice_64 = int(selector_246);
			t_sample selector_298 = ((choice_64 >= 10) ? ((t_sample)0.090909) : ((choice_64 >= 9) ? ((t_sample)0.111111) : ((choice_64 >= 8) ? ((t_sample)0.142857) : ((choice_64 >= 7) ? ((t_sample)0.2) : ((choice_64 >= 6) ? ((t_sample)0.25) : ((choice_64 >= 5) ? ((t_sample)0.3335) : ((choice_64 >= 4) ? ((t_sample)0.5) : ((choice_64 >= 3) ? ((t_sample)0.667) : ((choice_64 >= 2) ? ((t_sample)0.75) : ((choice_64 >= 1) ? ((int)1) : 0))))))))));
			t_sample mul_293 = (rdiv_291 * selector_298);
			t_sample mul_290 = (mul_293 * ((int)1000));
			t_sample mstosamps_299 = (mul_290 * (samplerate * 0.001));
			t_sample pass_250 = mstosamps_299;
			t_sample selector_284 = ((choice_65 >= 2) ? pass_250 : ((choice_65 >= 1) ? pass_251 : 0));
			t_sample timesamples_selected_279 = selector_284;
			t_sample timesamples_selected_45 = timesamples_selected_279;
			t_sample tap_63 = m_delay_14.read_linear(timesamples_selected_45);
			t_sample fold_60 = fold(tap_63, (-1), ((int)1));
			t_sample mul_51 = (fold_60 * ((int)1));
			t_sample gen_65 = mul_51;
			t_sample tap_53 = m_delay_13.read_step(((int)48000));
			t_sample selector_56 = ((choice_66 >= 2) ? tap_53 : ((choice_66 >= 1) ? ((int)1) : 0));
			t_sample add_54 = (selector_56 + ((int)1));
			t_sample mul_61 = (m_history_12 * selector_49);
			t_sample choice_68 = int(add_54);
			t_sample selector_58 = ((choice_68 >= 2) ? mul_61 : ((choice_68 >= 1) ? in2 : 0));
			t_sample history_59_next_64 = fixdenorm(fold_60);
			t_sample mul_253 = (gen_65 * tail_255);
			__m_count_69 = (not_4 ? 0 : (fixdenorm(__m_count_69 + ((int)1))));
			int counter_39 = __m_count_69;
			int counter_40 = ((int)0);
			int counter_41 = ((int)0);
			int clamp_37 = ((counter_39 <= ((int)0)) ? ((int)0) : ((counter_39 >= ((int)191999)) ? ((int)191999) : counter_39));
			bool index_ignore_70 = ((clamp_37 >= RIGHT_dim) || (clamp_37 < 0));
			if ((!index_ignore_70)) {
				m_RIGHT_11.write(in2, clamp_37, 0);
				
			};
			__m_count_71 = (not_4 ? 0 : (fixdenorm(__m_count_71 + speed_3)));
			int carry_72 = 0;
			if ((not_4 != 0)) {
				__m_count_71 = 0;
				__m_carry_73 = 0;
				
			} else if (((timesamples_selected_45 > 0) && (__m_count_71 >= timesamples_selected_45))) {
				int wraps_74 = (__m_count_71 / timesamples_selected_45);
				__m_carry_73 = (__m_carry_73 + wraps_74);
				__m_count_71 = (__m_count_71 - (wraps_74 * timesamples_selected_45));
				carry_72 = 1;
				
			};
			t_sample counter_32 = __m_count_71;
			int counter_33 = carry_72;
			int counter_34 = __m_carry_73;
			t_sample clamp_31 = ((counter_32 <= ((int)0)) ? ((int)0) : ((counter_32 >= ((int)191999)) ? ((int)191999) : counter_32));
			t_sample irange_427 = (timesamples_selected_45 - ((int)0));
			t_sample orange_428 = (((int)0) - timesamples_selected_45);
			t_sample sub_429 = (clamp_31 - ((int)0));
			t_sample scale_426 = ((safepow(safediv(sub_429, irange_427), ((int)1)) * orange_428) + timesamples_selected_45);
			t_sample scale_30 = scale_426;
			t_sample selector_27 = ((choice_75 >= 2) ? scale_30 : ((choice_75 >= 1) ? clamp_31 : 0));
			int index_trunc_76 = fixnan(floor(selector_27));
			bool index_ignore_77 = ((index_trunc_76 >= RIGHT_dim) || (index_trunc_76 < 0));
			// samples RIGHT channel 1;
			t_sample sample_RIGHT_35 = (index_ignore_77 ? 0 : m_RIGHT_11.read(index_trunc_76, 0));
			t_sample index_RIGHT_36 = selector_27;
			t_sample gen_44 = sample_RIGHT_35;
			t_sample tap_302 = m_delay_10.read_linear(m_ENV_ms_22);
			t_sample delta_312 = __m_delta_78(tap_302);
			__m_latch_79 = ((delta_312 != 0) ? m_history_9 : __m_latch_79);
			t_sample latch_307 = __m_latch_79;
			__m_latch_80 = ((delta_312 != 0) ? tap_302 : __m_latch_80);
			t_sample latch_309 = __m_latch_80;
			t_sample plusequals_311 = __m_pluseq_81.post(((int)1), delta_312, 0);
			__m_latch_82 = ((delta_312 != 0) ? scale_323 : __m_latch_82);
			t_sample latch_306 = __m_latch_82;
			t_sample mul_310 = (plusequals_311 * latch_306);
			t_sample clamp_308 = ((mul_310 <= ((int)0)) ? ((int)0) : ((mul_310 >= ((int)1)) ? ((int)1) : mul_310));
			t_sample anon_313 = linear_interp(clamp_308, latch_307, latch_309);
			t_sample gen_315 = anon_313;
			t_sample history_304_next_314 = fixdenorm(anon_313);
			t_sample gen_324 = gen_315;
			t_sample sub_317 = (timesamples_selected_279 - mul_300);
			__m_count_83 = (eq_319 ? 0 : (fixdenorm(__m_count_83 + ((int)1))));
			int carry_84 = 0;
			if ((eq_319 != 0)) {
				__m_count_83 = 0;
				__m_carry_85 = 0;
				
			} else if (((timesamples_selected_279 > 0) && (__m_count_83 >= timesamples_selected_279))) {
				int wraps_86 = (__m_count_83 / timesamples_selected_279);
				__m_carry_85 = (__m_carry_85 + wraps_86);
				__m_count_83 = (__m_count_83 - (wraps_86 * timesamples_selected_279));
				carry_84 = 1;
				
			};
			int counter_320 = __m_count_83;
			int counter_321 = carry_84;
			int counter_322 = __m_carry_85;
			int gte_316 = (counter_320 >= sub_317);
			int not_303 = (!gte_316);
			t_sample envelop_R_359 = gen_324;
			t_sample mul_360 = (gen_44 * envelop_R_359);
			t_sample selector_366 = ((choice_87 >= 2) ? mul_360 : ((choice_87 >= 1) ? mul_253 : 0));
			t_sample mul_361 = (selector_366 * min_380);
			t_sample add_362 = (mul_363 + mul_361);
			t_sample clamp_357 = ((add_362 <= min_88) ? min_88 : ((add_362 >= ((int)1)) ? ((int)1) : add_362));
			t_sample mul_164 = (clamp_357 * expr_170);
			t_sample mul_161 = (m_history_6 * expr_171);
			t_sample mul_159 = (m_history_7 * expr_172);
			t_sample mul_155 = (m_history_8 * expr_174);
			t_sample mul_157 = (m_history_5 * expr_173);
			t_sample sub_163 = (((mul_159 + mul_161) + mul_164) - (mul_157 + mul_155));
			t_sample gen_169 = sub_163;
			t_sample history_156_next_165 = fixdenorm(m_history_5);
			t_sample history_160_next_166 = fixdenorm(m_history_6);
			t_sample history_162_next_167 = fixdenorm(clamp_357);
			t_sample history_158_next_168 = fixdenorm(sub_163);
			t_sample gen_175 = gen_169;
			t_sample mul_136 = (gen_175 * expr_142);
			t_sample mul_133 = (m_history_2 * expr_143);
			t_sample mul_131 = (m_history_4 * expr_144);
			t_sample mul_127 = (m_history_3 * expr_146);
			t_sample mul_129 = (m_history_1 * expr_145);
			t_sample sub_135 = (((mul_131 + mul_133) + mul_136) - (mul_129 + mul_127));
			t_sample gen_141 = sub_135;
			t_sample history_132_next_137 = fixdenorm(m_history_2);
			t_sample history_128_next_138 = fixdenorm(m_history_1);
			t_sample history_134_next_139 = fixdenorm(gen_175);
			t_sample history_130_next_140 = fixdenorm(sub_135);
			t_sample out2 = gen_141;
			m_delay_20.write(selector_269);
			m_history_18 = history_270_next_275;
			m_delay_19.write(stutt_257);
			m_delay_16.write(not_328);
			m_history_15 = history_329_next_339;
			m_delay_14.write(selector_58);
			m_history_12 = history_59_next_64;
			m_delay_13.write(stutt_46);
			m_delay_10.write(not_303);
			m_history_9 = history_304_next_314;
			m_history_8 = history_156_next_165;
			m_history_1 = history_130_next_140;
			m_history_2 = history_134_next_139;
			m_history_3 = history_128_next_138;
			m_history_4 = history_132_next_137;
			m_history_5 = history_158_next_168;
			m_history_6 = history_162_next_167;
			m_history_7 = history_160_next_166;
			m_delay_10.step();
			m_delay_13.step();
			m_delay_14.step();
			m_delay_16.step();
			m_delay_19.step();
			m_delay_20.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			
		};
		return __exception;
		
	};
	inline void set_RIGHT(void * _value) {
		m_RIGHT_11.setbuffer(_value);
	};
	inline void set_LEFT(void * _value) {
		m_LEFT_17.setbuffer(_value);
	};
	inline void set_RANDOM(t_param _value) {
		m_RANDOM_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ENV_ms(t_param _value) {
		m_ENV_ms_22 = (_value < 0 ? 0 : (_value > 3000 ? 3000 : _value));
	};
	inline void set_Tail(t_param _value) {
		m_Tail_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_Div_L(t_param _value) {
		m_Div_L_24 = (_value < 1 ? 1 : (_value > 10 ? 10 : _value));
	};
	inline void set_speed(t_param _value) {
		m_speed_25 = (_value < 0.01 ? 0.01 : (_value > 23 ? 23 : _value));
	};
	inline void set_DOUBLE(t_param _value) {
		m_DOUBLE_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_dry_wet(t_param _value) {
		m_dry_wet_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_Div_R(t_param _value) {
		m_Div_R_28 = (_value < 1 ? 1 : (_value > 10 ? 10 : _value));
	};
	inline void set_ztutter(t_param _value) {
		m_ztutter_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_RANGE(t_param _value) {
		m_RANGE_30 = (_value < 1 ? 1 : (_value > 10 ? 10 : _value));
	};
	inline void set_reverse(t_param _value) {
		m_reverse_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_Filter_R(t_param _value) {
		m_Filter_R_32 = (_value < -100 ? -100 : (_value > 100 ? 100 : _value));
	};
	inline void set_BPM(t_param _value) {
		m_BPM_33 = (_value < 20 ? 20 : (_value > 240 ? 240 : _value));
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
int num_params() { return 15; }

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
		case 0: self->set_BPM(value); break;
		case 1: self->set_DOUBLE(value); break;
		case 2: self->set_Div_L(value); break;
		case 3: self->set_Div_R(value); break;
		case 4: self->set_ENV_ms(value); break;
		case 5: self->set_Filter_R(value); break;
		case 6: self->set_LEFT(ref); break;
		case 7: self->set_RANDOM(value); break;
		case 8: self->set_RANGE(value); break;
		case 9: self->set_RIGHT(ref); break;
		case 10: self->set_Tail(value); break;
		case 11: self->set_dry_wet(value); break;
		case 12: self->set_reverse(value); break;
		case 13: self->set_speed(value); break;
		case 14: self->set_ztutter(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_BPM_33; break;
		case 1: *value = self->m_DOUBLE_26; break;
		case 2: *value = self->m_Div_L_24; break;
		case 3: *value = self->m_Div_R_28; break;
		case 4: *value = self->m_ENV_ms_22; break;
		case 5: *value = self->m_Filter_R_32; break;
		
		case 7: *value = self->m_RANDOM_21; break;
		case 8: *value = self->m_RANGE_30; break;
		
		case 10: *value = self->m_Tail_23; break;
		case 11: *value = self->m_dry_wet_27; break;
		case 12: *value = self->m_reverse_31; break;
		case 13: *value = self->m_speed_25; break;
		case 14: *value = self->m_ztutter_29; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(15 * sizeof(ParamInfo));
	self->__commonstate.numparams = 15;
	// initialize parameter 0 ("m_BPM_33")
	pi = self->__commonstate.params + 0;
	pi->name = "BPM";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_BPM_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 20;
	pi->outputmax = 240;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_DOUBLE_26")
	pi = self->__commonstate.params + 1;
	pi->name = "DOUBLE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_DOUBLE_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_Div_L_24")
	pi = self->__commonstate.params + 2;
	pi->name = "Div_L";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Div_L_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 10;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_Div_R_28")
	pi = self->__commonstate.params + 3;
	pi->name = "Div_R";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Div_R_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 10;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_ENV_ms_22")
	pi = self->__commonstate.params + 4;
	pi->name = "ENV_ms";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ENV_ms_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 3000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_Filter_R_32")
	pi = self->__commonstate.params + 5;
	pi->name = "Filter_R";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Filter_R_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -100;
	pi->outputmax = 100;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_LEFT_17")
	pi = self->__commonstate.params + 6;
	pi->name = "LEFT";
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
	// initialize parameter 7 ("m_RANDOM_21")
	pi = self->__commonstate.params + 7;
	pi->name = "RANDOM";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_RANDOM_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_RANGE_30")
	pi = self->__commonstate.params + 8;
	pi->name = "RANGE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_RANGE_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 10;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_RIGHT_11")
	pi = self->__commonstate.params + 9;
	pi->name = "RIGHT";
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
	// initialize parameter 10 ("m_Tail_23")
	pi = self->__commonstate.params + 10;
	pi->name = "Tail";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Tail_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_dry_wet_27")
	pi = self->__commonstate.params + 11;
	pi->name = "dry_wet";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_dry_wet_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_reverse_31")
	pi = self->__commonstate.params + 12;
	pi->name = "reverse";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_reverse_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_speed_25")
	pi = self->__commonstate.params + 13;
	pi->name = "speed";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_speed_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.01;
	pi->outputmax = 23;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_ztutter_29")
	pi = self->__commonstate.params + 14;
	pi->name = "ztutter";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ztutter_29;
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
