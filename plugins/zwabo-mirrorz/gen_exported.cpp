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
	Data m_BILL_25;
	Data m_BOUL_22;
	Delay m_delay_17;
	Delta __m_delta_40;
	PlusEquals __m_pluseq_41;
	Sah __m_sah_44;
	Sah __m_sah_45;
	int __exception;
	int vectorsize;
	t_sample __m_latch_80;
	t_sample __m_latch_79;
	t_sample __m_carry_38;
	t_sample __m_count_36;
	t_sample __m_latch_33;
	t_sample __m_carry_72;
	t_sample __m_carry_28;
	t_sample __m_latch_68;
	t_sample __m_latch_42;
	t_sample __m_count_70;
	t_sample __m_carry_52;
	t_sample __m_count_54;
	t_sample __m_latch_43;
	t_sample __m_count_50;
	t_sample __m_count_46;
	t_sample __m_carry_48;
	t_sample __m_count_26;
	t_sample __m_carry_56;
	t_sample m_trigger_23;
	t_sample __m_latch_81;
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
	t_sample m_dry_wet_24;
	t_sample m_history_10;
	t_sample m_history_12;
	t_sample m_filter_19;
	t_sample m_speed_20;
	t_sample m_loop_21;
	t_sample m_history_11;
	t_sample m_history_18;
	t_sample m_history_15;
	t_sample m_history_16;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample __m_latch_82;
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
		m_delay_17.reset("m_delay_17", ((int)5));
		m_history_18 = ((int)0);
		m_filter_19 = 0;
		m_speed_20 = 1;
		m_loop_21 = 0;
		m_BOUL_22.reset("BOUL", ((int)15336000), ((int)2));
		m_trigger_23 = 0;
		m_dry_wet_24 = 0.5;
		m_BILL_25.reset("BILL", ((int)15336000), ((int)2));
		__m_count_26 = 0;
		__m_carry_28 = 0;
		__m_latch_33 = 0;
		__m_count_36 = 0;
		__m_carry_38 = 0;
		__m_delta_40.reset(0);
		__m_pluseq_41.reset(0);
		__m_latch_42 = 0;
		__m_latch_43 = 0;
		__m_sah_44.reset(0);
		__m_sah_45.reset(0);
		__m_count_46 = 0;
		__m_carry_48 = 0;
		__m_count_50 = 0;
		__m_carry_52 = 0;
		__m_count_54 = 0;
		__m_carry_56 = 0;
		__m_latch_68 = 0;
		__m_count_70 = 0;
		__m_carry_72 = 0;
		__m_latch_79 = 0;
		__m_latch_80 = 0;
		__m_latch_81 = 0;
		__m_latch_82 = 0;
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
		int BILL_dim = m_BILL_25.dim;
		int BILL_channels = m_BILL_25.channels;
		int dim_580 = BILL_dim;
		int BOUL_dim = m_BOUL_22.dim;
		int BOUL_channels = m_BOUL_22.channels;
		int dim_631 = BOUL_dim;
		bool chan_ignore_31 = ((((int)1) < 0) || (((int)1) >= BOUL_channels));
		t_sample round_549 = round(m_trigger_23);
		t_sample resetcountloop_561 = round_549;
		t_sample resetcountloop_563 = resetcountloop_561;
		t_sample sub_648 = (m_dry_wet_24 - ((t_sample)0.5));
		t_sample scale_645 = ((safepow((sub_648 * ((t_sample)2)), ((int)1)) * ((int)-1)) + ((int)1));
		t_sample min_369 = ((((int)1) < scale_645) ? ((int)1) : scale_645);
		t_sample sub_652 = (m_dry_wet_24 - ((int)0));
		t_sample scale_649 = ((safepow((sub_652 * ((t_sample)2)), ((int)1)) * ((int)1)) + ((int)0));
		t_sample min_373 = ((((int)1) < scale_649) ? ((int)1) : scale_649);
		t_sample round_550 = round(m_loop_21);
		t_sample startstoploop_590 = round_550;
		t_sample startstoploop_570 = startstoploop_590;
		int gte_360 = (m_speed_20 >= ((t_sample)1.9));
		int mul_359 = (gte_360 * ((int)3));
		int lt_358 = (m_speed_20 < ((t_sample)1.9));
		int mul_361 = (lt_358 * ((int)2));
		int lte_357 = (m_speed_20 <= ((t_sample)0.6));
		int mul_356 = (lte_357 * ((int)1));
		int gt_355 = (m_speed_20 > ((t_sample)0.6));
		int mul_354 = (gt_355 * ((int)2));
		__m_latch_33 = (((((gt_355 + lte_357) + lt_358) + gte_360) != 0) ? (((mul_361 + mul_354) + mul_356) + mul_359) : __m_latch_33);
		int latch_366 = __m_latch_33;
		int sub_353 = (latch_366 - ((int)2));
		int choice_34 = sub_353;
		t_sample selector_365 = ((choice_34 >= 3) ? ((int)2) : ((choice_34 >= 2) ? ((int)1) : ((choice_34 >= 1) ? ((t_sample)0.5) : 0)));
		t_sample gen_367 = selector_365;
		t_sample speed_587 = gen_367;
		t_sample speed_552 = speed_587;
		t_sample choice_35 = int(startstoploop_570);
		t_sample selector_551 = ((choice_35 >= 1) ? speed_552 : 0);
		int dim_601 = BOUL_dim;
		t_sample ramp_348 = (round_549 + round_550);
		int dim_627 = BOUL_dim;
		t_sample speed_588 = speed_587;
		int dim_595 = BOUL_dim;
		t_sample speed_586 = speed_587;
		int dim_614 = BOUL_dim;
		t_sample startstoploop_568 = startstoploop_590;
		int not_562 = (!startstoploop_568);
		int irange_654 = (dim_601 - ((int)0));
		int orange_655 = (((int)0) - dim_601);
		t_sample startstoploop_589 = startstoploop_590;
		int irange_658 = (dim_627 - ((int)0));
		int orange_659 = (((int)0) - dim_627);
		bool chan_ignore_61 = ((1 < 0) || (1 >= BOUL_channels));
		bool chan_ignore_64 = ((((int)1) < 0) || (((int)1) >= BILL_channels));
		t_sample speed_571 = speed_587;
		t_sample speed_554 = speed_587;
		t_sample resetcountloop_560 = resetcountloop_561;
		t_sample count_reset_73 = (resetcountloop_561 + startstoploop_568);
		bool chan_ignore_78 = ((1 < 0) || (1 >= BILL_channels));
		int lte_470 = (m_filter_19 <= ((int)0));
		int not_469 = (!lte_470);
		__m_latch_79 = ((not_469 != 0) ? m_filter_19 : __m_latch_79);
		t_sample latch_471 = __m_latch_79;
		t_sample sub_668 = (latch_471 - ((int)0));
		t_sample scale_665 = ((safepow((sub_668 * ((t_sample)0.01)), ((int)1)) * ((int)995)) + ((int)5));
		t_sample scale_475 = scale_665;
		int gte_473 = (m_filter_19 >= ((int)0));
		int not_472 = (!gte_473);
		__m_latch_80 = ((not_472 != 0) ? m_filter_19 : __m_latch_80);
		t_sample latch_474 = __m_latch_80;
		t_sample sub_672 = (latch_474 - (-100));
		t_sample scale_669 = ((safepow((sub_672 * ((t_sample)0.01)), ((int)1)) * ((int)22500)) + ((int)500));
		t_sample scale_476 = scale_669;
		t_sample min_513 = ((scale_476 < ((int)0)) ? ((int)0) : scale_476);
		t_sample omega = safediv((min_513 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn = sin(omega);
		t_sample cs = cos(omega);
		t_sample alpha = ((sn * ((t_sample)0.5)) * ((int)2));
		t_sample b0 = safediv(((int)1), (((int)1) + alpha));
		t_sample a2 = (((((int)1) - cs) * ((t_sample)0.5)) * b0);
		t_sample a1 = ((((int)1) - cs) * b0);
		t_sample b1 = ((((int)-2) * cs) * b0);
		t_sample b2 = ((((int)1) - alpha) * b0);
		t_sample expr_529 = a2;
		t_sample expr_530 = a1;
		t_sample expr_531 = a2;
		t_sample expr_532 = b1;
		t_sample expr_533 = b2;
		t_sample min_485 = ((scale_475 < ((int)0)) ? ((int)0) : scale_475);
		t_sample omega_539 = safediv((min_485 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn_542 = sin(omega_539);
		t_sample cs_538 = cos(omega_539);
		t_sample alpha_543 = ((sn_542 * ((t_sample)0.5)) * ((t_sample)2));
		t_sample b_535 = safediv(((int)1), (((int)1) + alpha_543));
		t_sample a_536 = (((((int)1) + cs_538) * ((t_sample)0.5)) * b_535);
		t_sample a_541 = ((-(((int)1) + cs_538)) * b_535);
		t_sample b_540 = ((((int)-2) * cs_538) * b_535);
		t_sample b_537 = ((((int)1) - alpha_543) * b_535);
		t_sample expr_501 = a_536;
		t_sample expr_502 = a_541;
		t_sample expr_503 = a_536;
		t_sample expr_504 = b_540;
		t_sample expr_505 = b_537;
		int lte_394 = (m_filter_19 <= ((int)0));
		int not_393 = (!lte_394);
		__m_latch_81 = ((not_393 != 0) ? m_filter_19 : __m_latch_81);
		t_sample latch_395 = __m_latch_81;
		t_sample sub_676 = (latch_395 - ((int)0));
		t_sample scale_673 = ((safepow((sub_676 * ((t_sample)0.01)), ((int)1)) * ((int)995)) + ((int)5));
		t_sample scale_399 = scale_673;
		int gte_397 = (m_filter_19 >= ((int)0));
		int not_396 = (!gte_397);
		__m_latch_82 = ((not_396 != 0) ? m_filter_19 : __m_latch_82);
		t_sample latch_398 = __m_latch_82;
		t_sample sub_680 = (latch_398 - (-100));
		t_sample scale_677 = ((safepow((sub_680 * ((t_sample)0.01)), ((int)1)) * ((int)22500)) + ((int)500));
		t_sample scale_400 = scale_677;
		t_sample min_437 = ((scale_400 < ((int)0)) ? ((int)0) : scale_400);
		t_sample omega_644 = safediv((min_437 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn_640 = sin(omega_644);
		t_sample cs_637 = cos(omega_644);
		t_sample alpha_636 = ((sn_640 * ((t_sample)0.5)) * ((int)2));
		t_sample b_639 = safediv(((int)1), (((int)1) + alpha_636));
		t_sample a_638 = (((((int)1) - cs_637) * ((t_sample)0.5)) * b_639);
		t_sample a_643 = ((((int)1) - cs_637) * b_639);
		t_sample b_642 = ((((int)-2) * cs_637) * b_639);
		t_sample b_635 = ((((int)1) - alpha_636) * b_639);
		t_sample expr_453 = a_638;
		t_sample expr_454 = a_643;
		t_sample expr_455 = a_638;
		t_sample expr_456 = b_642;
		t_sample expr_457 = b_635;
		t_sample min_409 = ((scale_399 < ((int)0)) ? ((int)0) : scale_399);
		t_sample omega_465 = safediv((min_409 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn_466 = sin(omega_465);
		t_sample cs_462 = cos(omega_465);
		t_sample alpha_467 = ((sn_466 * ((t_sample)0.5)) * ((t_sample)2));
		t_sample b_459 = safediv(((int)1), (((int)1) + alpha_467));
		t_sample a_460 = (((((int)1) + cs_462) * ((t_sample)0.5)) * b_459);
		t_sample a_464 = ((-(((int)1) + cs_462)) * b_459);
		t_sample b_463 = ((((int)-2) * cs_462) * b_459);
		t_sample b_461 = ((((int)1) - alpha_467) * b_459);
		t_sample expr_425 = a_460;
		t_sample expr_426 = a_464;
		t_sample expr_427 = a_460;
		t_sample expr_428 = b_463;
		t_sample expr_429 = b_461;
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			__m_count_26 = (((int)0) ? 0 : (fixdenorm(__m_count_26 + ((int)1))));
			int carry_27 = 0;
			if ((((int)0) != 0)) {
				__m_count_26 = 0;
				__m_carry_28 = 0;
				
			} else if (((dim_631 > 0) && (__m_count_26 >= dim_631))) {
				int wraps_29 = (__m_count_26 / dim_631);
				__m_carry_28 = (__m_carry_28 + wraps_29);
				__m_count_26 = (__m_count_26 - (wraps_29 * dim_631));
				carry_27 = 1;
				
			};
			int counter_632 = __m_count_26;
			int counter_633 = carry_27;
			int counter_634 = __m_carry_28;
			bool index_ignore_30 = ((counter_632 >= BOUL_dim) || (counter_632 < 0));
			if ((!index_ignore_30)) {
				m_BOUL_22.write(in1, counter_632, 0);
				
			};
			bool index_ignore_32 = ((counter_632 >= BOUL_dim) || (counter_632 < 0));
			if ((!(chan_ignore_31 || index_ignore_32))) {
				m_BOUL_22.write(in2, counter_632, ((int)1));
				
			};
			t_sample mul_546 = (in1 * min_369);
			t_sample mul_545 = (in2 * min_369);
			__m_count_36 = (resetcountloop_563 ? 0 : (fixdenorm(__m_count_36 + selector_551)));
			int carry_37 = 0;
			if ((resetcountloop_563 != 0)) {
				__m_count_36 = 0;
				__m_carry_38 = 0;
				
			} else if (((dim_580 > 0) && (__m_count_36 >= dim_580))) {
				int wraps_39 = (__m_count_36 / dim_580);
				__m_carry_38 = (__m_carry_38 + wraps_39);
				__m_count_36 = (__m_count_36 - (wraps_39 * dim_580));
				carry_37 = 1;
				
			};
			t_sample counter_581 = __m_count_36;
			int counter_582 = carry_37;
			int counter_583 = __m_carry_38;
			t_sample delta_343 = __m_delta_40(ramp_348);
			t_sample plusequals_338 = __m_pluseq_41.post(((int)1), delta_343, 0);
			t_sample sub_339 = (ramp_348 - m_history_18);
			__m_latch_42 = ((delta_343 != 0) ? sub_339 : __m_latch_42);
			t_sample latch_341 = __m_latch_42;
			__m_latch_43 = ((delta_343 != 0) ? ((int)250) : __m_latch_43);
			t_sample latch_333 = __m_latch_43;
			int lt_335 = (plusequals_338 < latch_333);
			t_sample div_342 = safediv(latch_341, latch_333);
			t_sample mul_336 = (lt_335 * div_342);
			t_sample add_337 = (mul_336 + m_history_18);
			t_sample gen_345 = add_337;
			t_sample history_340_next_344 = fixdenorm(add_337);
			int count_628 = counter_632;
			int sah_619 = __m_sah_44(count_628, (round_549 + round_550), ((int)0));
			int sah_602 = sah_619;
			int sah_603 = sah_602;
			t_sample sah_569 = __m_sah_45(counter_581, not_562, ((int)0));
			t_sample sahloop_375 = sah_569;
			t_sample sahloop_368 = sahloop_375;
			t_sample mul_352 = (sahloop_368 * ((t_sample)0.00125));
			t_sample mul_351 = (mul_352 * (-1));
			t_sample tap_548 = m_delay_17.read_step(((int)8));
			t_sample trig_604 = tap_548;
			int eq_605 = ((startstoploop_590 + trig_604) == ((int)0));
			__m_count_46 = (eq_605 ? 0 : (fixdenorm(__m_count_46 + speed_587)));
			int carry_47 = 0;
			if ((eq_605 != 0)) {
				__m_count_46 = 0;
				__m_carry_48 = 0;
				
			} else if (((sah_603 > 0) && (__m_count_46 >= sah_603))) {
				int wraps_49 = (__m_count_46 / sah_603);
				__m_carry_48 = (__m_carry_48 + wraps_49);
				__m_count_46 = (__m_count_46 - (wraps_49 * sah_603));
				carry_47 = 1;
				
			};
			t_sample counter_608 = __m_count_46;
			int counter_609 = carry_47;
			int counter_610 = __m_carry_48;
			int endcountpart_593 = counter_610;
			int add_607 = (endcountpart_593 + ((int)1));
			int endcountpart_592 = endcountpart_593;
			int eq_594 = (endcountpart_592 == ((int)0));
			__m_count_50 = (eq_594 ? 0 : (fixdenorm(__m_count_50 + speed_588)));
			int carry_51 = 0;
			if ((eq_594 != 0)) {
				__m_count_50 = 0;
				__m_carry_52 = 0;
				
			} else if (((dim_595 > 0) && (__m_count_50 >= dim_595))) {
				int wraps_53 = (__m_count_50 / dim_595);
				__m_carry_52 = (__m_carry_52 + wraps_53);
				__m_count_50 = (__m_count_50 - (wraps_53 * dim_595));
				carry_51 = 1;
				
			};
			t_sample counter_596 = __m_count_50;
			int counter_597 = carry_51;
			int counter_598 = __m_carry_52;
			t_sample sub_656 = (counter_596 - ((int)0));
			t_sample scale_653 = ((safepow(safediv(sub_656, irange_654), ((int)1)) * orange_655) + dim_601);
			t_sample scale_600 = scale_653;
			t_sample countpart_591 = scale_600;
			t_sample trig_606 = trig_604;
			int eq_613 = ((startstoploop_589 + trig_606) == ((int)0));
			__m_count_54 = (eq_613 ? 0 : (fixdenorm(__m_count_54 + speed_586)));
			int carry_55 = 0;
			if ((eq_613 != 0)) {
				__m_count_54 = 0;
				__m_carry_56 = 0;
				
			} else if (((dim_614 > 0) && (__m_count_54 >= dim_614))) {
				int wraps_57 = (__m_count_54 / dim_614);
				__m_carry_56 = (__m_carry_56 + wraps_57);
				__m_count_54 = (__m_count_54 - (wraps_57 * dim_614));
				carry_55 = 1;
				
			};
			t_sample counter_615 = __m_count_54;
			int counter_616 = carry_55;
			int counter_617 = __m_carry_56;
			t_sample sub_660 = (counter_615 - ((int)0));
			t_sample scale_657 = ((safepow(safediv(sub_660, irange_658), ((int)1)) * orange_659) + dim_627);
			t_sample scale_626 = scale_657;
			t_sample sub_611 = (scale_626 - ((int)15336000));
			t_sample add_612 = (sub_611 + sah_602);
			int choice_58 = add_607;
			t_sample selector_618 = ((choice_58 >= 2) ? countpart_591 : ((choice_58 >= 1) ? add_612 : 0));
			int index_trunc_59 = fixnan(floor(selector_618));
			bool index_ignore_60 = ((index_trunc_59 >= BOUL_dim) || (index_trunc_59 < 0));
			// samples BOUL channel 1;
			// samples BOUL channel 2;
			t_sample sample_BOUL_620 = (index_ignore_60 ? 0 : m_BOUL_22.read(index_trunc_59, 0));
			t_sample sample_BOUL_621 = ((chan_ignore_61 || index_ignore_60) ? 0 : m_BOUL_22.read(index_trunc_59, 1));
			t_sample index_BOUL_622 = selector_618;
			t_sample recloop_332 = sample_BOUL_620;
			t_sample recloop_579 = recloop_332;
			int index_trunc_62 = fixnan(floor(counter_581));
			bool index_ignore_63 = ((index_trunc_62 >= BILL_dim) || (index_trunc_62 < 0));
			if ((!index_ignore_63)) {
				m_BILL_25.write(recloop_579, index_trunc_62, 0);
				
			};
			t_sample mul_347 = (recloop_332 * gen_345);
			t_sample recloop_329 = sample_BOUL_621;
			t_sample recloop_578 = recloop_329;
			int index_trunc_65 = fixnan(floor(counter_581));
			bool index_ignore_66 = ((index_trunc_65 >= BILL_dim) || (index_trunc_65 < 0));
			if ((!(chan_ignore_64 || index_ignore_66))) {
				m_BILL_25.write(recloop_578, index_trunc_65, ((int)1));
				
			};
			t_sample mul_349 = (recloop_329 * gen_345);
			int bool_556 = (counter_581 != 0);
			int openreset_557 = bool_556;
			int openreset_555 = openreset_557;
			int choice_67 = openreset_555;
			t_sample selector_553 = ((choice_67 >= 1) ? speed_554 : 0);
			__m_latch_68 = ((openreset_557 != 0) ? resetcountloop_560 : __m_latch_68);
			t_sample latch_559 = __m_latch_68;
			int not_558 = (!latch_559);
			int choice_69 = not_558;
			t_sample selector_565 = ((choice_69 >= 2) ? speed_571 : ((choice_69 >= 1) ? ((int)0) : 0));
			__m_count_70 = ((resetcountloop_561 + startstoploop_568) ? 0 : (fixdenorm(__m_count_70 + (selector_553 + selector_565))));
			int carry_71 = 0;
			if ((count_reset_73 != 0)) {
				__m_count_70 = 0;
				__m_carry_72 = 0;
				
			} else if (((sahloop_368 > 0) && (__m_count_70 >= sahloop_368))) {
				int wraps_74 = (__m_count_70 / sahloop_368);
				__m_carry_72 = (__m_carry_72 + wraps_74);
				__m_count_70 = (__m_count_70 - (wraps_74 * sahloop_368));
				carry_71 = 1;
				
			};
			t_sample counter_572 = __m_count_70;
			int counter_573 = carry_71;
			int counter_574 = __m_carry_72;
			t_sample sub_388 = (counter_572 - mul_351);
			t_sample irange_662 = (sahloop_375 - ((int)0));
			t_sample sub_664 = (sub_388 - ((int)0));
			t_sample scale_661 = ((safepow(safediv(sub_664, irange_662), ((int)1)) * ((int)1)) + ((int)0));
			t_sample scale_379 = scale_661;
			t_sample mod_383 = safemod(scale_379, ((int)1));
			t_sample window = ((int)0);
			t_sample pointer = mod_383;
			if ((((int)0) == ((int)0))) {
				t_sample v_75 = (mod_383 * ((int)500));
				pointer = ((v_75 <= ((int)0)) ? ((int)0) : ((v_75 >= ((int)1)) ? ((int)1) : v_75));
				t_sample scaled = (pointer * ((t_sample)6.2831853071796));
				window = ((((int)1) - cos(scaled)) * ((t_sample)0.5));
				
			};
			t_sample expr_385 = window;
			t_sample mul_381 = (expr_385 * (-1));
			t_sample add_380 = (mul_381 + ((int)1));
			t_sample gen_386 = add_380;
			int index_trunc_76 = fixnan(floor(counter_572));
			bool index_ignore_77 = ((index_trunc_76 >= BILL_dim) || (index_trunc_76 < 0));
			// samples BILL channel 1;
			// samples BILL channel 2;
			t_sample sample_BILL_575 = (index_ignore_77 ? 0 : m_BILL_25.read(index_trunc_76, 0));
			t_sample sample_BILL_576 = ((chan_ignore_78 || index_ignore_77) ? 0 : m_BILL_25.read(index_trunc_76, 1));
			t_sample index_BILL_577 = counter_572;
			t_sample loop_567 = sample_BILL_575;
			t_sample mul_389 = (gen_386 * loop_567);
			t_sample add_331 = (mul_389 + mul_347);
			t_sample mul_523 = (add_331 * expr_529);
			t_sample mul_520 = (m_history_14 * expr_530);
			t_sample mul_518 = (m_history_16 * expr_531);
			t_sample mul_514 = (m_history_15 * expr_533);
			t_sample mul_516 = (m_history_13 * expr_532);
			t_sample sub_522 = (((mul_518 + mul_520) + mul_523) - (mul_516 + mul_514));
			t_sample gen_528 = sub_522;
			t_sample history_519_next_524 = fixdenorm(m_history_14);
			t_sample history_515_next_525 = fixdenorm(m_history_13);
			t_sample history_521_next_526 = fixdenorm(add_331);
			t_sample history_517_next_527 = fixdenorm(sub_522);
			t_sample gen_534 = gen_528;
			t_sample mul_495 = (gen_534 * expr_501);
			t_sample mul_492 = (m_history_10 * expr_502);
			t_sample mul_490 = (m_history_11 * expr_503);
			t_sample mul_486 = (m_history_12 * expr_505);
			t_sample mul_488 = (m_history_9 * expr_504);
			t_sample sub_494 = (((mul_490 + mul_492) + mul_495) - (mul_488 + mul_486));
			t_sample gen_500 = sub_494;
			t_sample history_487_next_496 = fixdenorm(m_history_9);
			t_sample history_491_next_497 = fixdenorm(m_history_10);
			t_sample history_493_next_498 = fixdenorm(gen_534);
			t_sample history_489_next_499 = fixdenorm(sub_494);
			t_sample mul_372 = (gen_500 * min_373);
			t_sample add_391 = (mul_546 + mul_372);
			t_sample out1 = add_391;
			t_sample loop_566 = sample_BILL_576;
			t_sample mul_390 = (gen_386 * loop_566);
			t_sample add_330 = (mul_390 + mul_349);
			t_sample mul_447 = (add_330 * expr_453);
			t_sample mul_444 = (m_history_6 * expr_454);
			t_sample mul_442 = (m_history_7 * expr_455);
			t_sample mul_438 = (m_history_8 * expr_457);
			t_sample mul_440 = (m_history_5 * expr_456);
			t_sample sub_446 = (((mul_442 + mul_444) + mul_447) - (mul_440 + mul_438));
			t_sample gen_452 = sub_446;
			t_sample history_439_next_448 = fixdenorm(m_history_5);
			t_sample history_443_next_449 = fixdenorm(m_history_6);
			t_sample history_445_next_450 = fixdenorm(add_330);
			t_sample history_441_next_451 = fixdenorm(sub_446);
			t_sample gen_458 = gen_452;
			t_sample mul_419 = (gen_458 * expr_425);
			t_sample mul_416 = (m_history_2 * expr_426);
			t_sample mul_414 = (m_history_4 * expr_427);
			t_sample mul_410 = (m_history_3 * expr_429);
			t_sample mul_412 = (m_history_1 * expr_428);
			t_sample sub_418 = (((mul_414 + mul_416) + mul_419) - (mul_412 + mul_410));
			t_sample gen_424 = sub_418;
			t_sample history_415_next_420 = fixdenorm(m_history_2);
			t_sample history_411_next_421 = fixdenorm(m_history_1);
			t_sample history_417_next_422 = fixdenorm(gen_458);
			t_sample history_413_next_423 = fixdenorm(sub_418);
			t_sample mul_371 = (gen_424 * min_373);
			t_sample add_392 = (mul_545 + mul_371);
			t_sample out2 = add_392;
			m_history_18 = history_340_next_344;
			m_delay_17.write(round_549);
			m_history_16 = history_519_next_524;
			m_history_9 = history_489_next_499;
			m_history_10 = history_493_next_498;
			m_history_11 = history_491_next_497;
			m_history_12 = history_487_next_496;
			m_history_13 = history_517_next_527;
			m_history_14 = history_521_next_526;
			m_history_15 = history_515_next_525;
			m_history_8 = history_439_next_448;
			m_history_1 = history_413_next_423;
			m_history_2 = history_417_next_422;
			m_history_3 = history_411_next_421;
			m_history_4 = history_415_next_420;
			m_history_5 = history_441_next_451;
			m_history_6 = history_445_next_450;
			m_history_7 = history_443_next_449;
			m_delay_17.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			
		};
		return __exception;
		
	};
	inline void set_filter(t_param _value) {
		m_filter_19 = (_value < -100 ? -100 : (_value > 100 ? 100 : _value));
	};
	inline void set_speed(t_param _value) {
		m_speed_20 = (_value < 0.5 ? 0.5 : (_value > 2 ? 2 : _value));
	};
	inline void set_loop(t_param _value) {
		m_loop_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_BOUL(void * _value) {
		m_BOUL_22.setbuffer(_value);
	};
	inline void set_trigger(t_param _value) {
		m_trigger_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_dry_wet(t_param _value) {
		m_dry_wet_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_BILL(void * _value) {
		m_BILL_25.setbuffer(_value);
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
int num_params() { return 7; }

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
		case 2: self->set_dry_wet(value); break;
		case 3: self->set_filter(value); break;
		case 4: self->set_loop(value); break;
		case 5: self->set_speed(value); break;
		case 6: self->set_trigger(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		
		
		case 2: *value = self->m_dry_wet_24; break;
		case 3: *value = self->m_filter_19; break;
		case 4: *value = self->m_loop_21; break;
		case 5: *value = self->m_speed_20; break;
		case 6: *value = self->m_trigger_23; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(7 * sizeof(ParamInfo));
	self->__commonstate.numparams = 7;
	// initialize parameter 0 ("m_BILL_25")
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
	// initialize parameter 1 ("m_BOUL_22")
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
	// initialize parameter 2 ("m_dry_wet_24")
	pi = self->__commonstate.params + 2;
	pi->name = "dry_wet";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_dry_wet_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_filter_19")
	pi = self->__commonstate.params + 3;
	pi->name = "filter";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_filter_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -100;
	pi->outputmax = 100;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_loop_21")
	pi = self->__commonstate.params + 4;
	pi->name = "loop";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_loop_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_speed_20")
	pi = self->__commonstate.params + 5;
	pi->name = "speed";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_speed_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.5;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_trigger_23")
	pi = self->__commonstate.params + 6;
	pi->name = "trigger";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_trigger_23;
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
