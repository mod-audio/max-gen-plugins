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
	Data m_delay_46;
	Data m_delay_50;
	Data m_delay_62;
	Data m_delay_47;
	Delay m_delay_13;
	int __exception;
	int vectorsize;
	t_sample m_Disto_54;
	t_sample m_time_56;
	t_sample m_double_58;
	t_sample m_Filter_57;
	t_sample m_reset_55;
	t_sample m_REC_53;
	t_sample m_mix_51;
	t_sample m_speed_59;
	t_sample m_history_43;
	t_sample m_history_42;
	t_sample m_feedback_52;
	t_sample m_history_44;
	t_sample m_Filter_On_48;
	t_sample m_history_45;
	t_sample m_reverse_49;
	t_sample m_crossfeed_60;
	t_sample m_FadeOut_61;
	t_sample __m_count_63;
	t_sample __m_latch_93;
	t_sample __m_latch_92;
	t_sample __m_latch_90;
	t_sample __m_latch_96;
	t_sample __m_slide_99;
	t_sample __m_latch_97;
	t_sample __m_latch_102;
	t_sample m_history_41;
	t_sample __m_latch_89;
	t_sample __m_count_83;
	t_sample __m_count_67;
	t_sample __m_carry_65;
	t_sample __m_carry_85;
	t_sample __m_carry_69;
	t_sample __m_count_77;
	t_sample __m_latch_75;
	t_sample __m_carry_79;
	t_sample m_history_40;
	t_sample m_history_39;
	t_sample m_history_38;
	t_sample m_history_12;
	t_sample m_history_11;
	t_sample m_history_10;
	t_sample m_history_9;
	t_sample m_history_14;
	t_sample m_history_16;
	t_sample m_history_15;
	t_sample m_history_17;
	t_sample m_history_18;
	t_sample m_history_8;
	t_sample m_history_6;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample m_history_7;
	t_sample m_history_2;
	t_sample m_history_4;
	t_sample m_history_3;
	t_sample m_history_5;
	t_sample __m_latch_103;
	t_sample m_history_19;
	t_sample m_history_21;
	t_sample m_history_33;
	t_sample m_history_32;
	t_sample m_history_31;
	t_sample m_history_34;
	t_sample m_history_36;
	t_sample m_history_35;
	t_sample m_history_37;
	t_sample m_history_20;
	t_sample m_history_30;
	t_sample m_history_28;
	t_sample m_history_23;
	t_sample m_history_22;
	t_sample m_history_29;
	t_sample m_history_24;
	t_sample m_history_26;
	t_sample m_history_25;
	t_sample m_history_27;
	t_sample __m_latch_105;
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
		m_delay_13.reset("m_delay_13", ((int)24000));
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		m_history_22 = ((int)0);
		m_history_23 = ((int)0);
		m_history_24 = ((int)0);
		m_history_25 = ((int)0);
		m_history_26 = ((int)0);
		m_history_27 = ((int)0);
		m_history_28 = ((int)0);
		m_history_29 = ((int)0);
		m_history_30 = ((int)0);
		m_history_31 = ((int)0);
		m_history_32 = ((int)0);
		m_history_33 = ((int)0);
		m_history_34 = ((int)0);
		m_history_35 = ((int)0);
		m_history_36 = ((int)0);
		m_history_37 = ((int)0);
		m_history_38 = ((int)0);
		m_history_39 = ((int)0);
		m_history_40 = ((int)0);
		m_history_41 = ((int)0);
		m_history_42 = ((int)0);
		m_history_43 = ((int)0);
		m_history_44 = ((int)0);
		m_history_45 = ((int)0);
		m_delay_46.reset("delay3", ((int)480010), ((int)1));
		m_delay_47.reset("delay4", ((int)480010), ((int)1));
		m_Filter_On_48 = 0;
		m_reverse_49 = 0;
		m_delay_50.reset("delay1", ((int)480010), ((int)1));
		m_mix_51 = 1;
		m_feedback_52 = 1;
		m_REC_53 = 0;
		m_Disto_54 = 0;
		m_reset_55 = 0;
		m_time_56 = 2500;
		m_Filter_57 = 0;
		m_double_58 = 0;
		m_speed_59 = 1;
		m_crossfeed_60 = 0;
		m_FadeOut_61 = 1000;
		m_delay_62.reset("delay2", ((int)480010), ((int)1));
		__m_count_63 = 0;
		__m_carry_65 = 0;
		__m_count_67 = 0;
		__m_carry_69 = 0;
		__m_latch_75 = 0;
		__m_count_77 = 0;
		__m_carry_79 = 0;
		__m_count_83 = 0;
		__m_carry_85 = 0;
		__m_latch_89 = 0;
		__m_latch_90 = 0;
		__m_latch_92 = 0;
		__m_latch_93 = 0;
		__m_latch_96 = 0;
		__m_latch_97 = 0;
		__m_slide_99 = 0;
		__m_latch_102 = 0;
		__m_latch_103 = 0;
		__m_latch_105 = 0;
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
		int delay4_dim = m_delay_47.dim;
		int delay4_channels = m_delay_47.channels;
		int dim_507 = delay4_dim;
		int delay3_dim = m_delay_46.dim;
		int delay3_channels = m_delay_46.channels;
		int dim_605 = delay3_dim;
		t_sample choice_71 = int(m_REC_53);
		t_sample choice_73 = int(m_REC_53);
		int delay1_dim = m_delay_50.dim;
		int delay1_channels = m_delay_50.channels;
		int dim_812 = delay1_dim;
		int delay2_dim = m_delay_62.dim;
		int delay2_channels = m_delay_62.channels;
		int dim_708 = delay2_dim;
		int gte_835 = (m_speed_59 >= ((t_sample)1.9));
		int mul_834 = (gte_835 * ((int)3));
		int lt_833 = (m_speed_59 < ((t_sample)1.9));
		int mul_836 = (lt_833 * ((int)2));
		int lte_832 = (m_speed_59 <= ((t_sample)0.6));
		int mul_831 = (lte_832 * ((int)1));
		int gt_830 = (m_speed_59 > ((t_sample)0.6));
		int mul_829 = (gt_830 * ((int)2));
		__m_latch_75 = (((((gt_830 + lte_832) + lt_833) + gte_835) != 0) ? (((mul_836 + mul_829) + mul_831) + mul_834) : __m_latch_75);
		int latch_841 = __m_latch_75;
		int sub_828 = (latch_841 - ((int)2));
		int choice_76 = sub_828;
		t_sample selector_840 = ((choice_76 >= 3) ? ((int)2) : ((choice_76 >= 2) ? ((int)1) : ((choice_76 >= 1) ? ((t_sample)0.5) : 0)));
		t_sample gen_842 = selector_840;
		t_sample speed_827 = gen_842;
		t_sample speed_721 = speed_827;
		t_sample crossfeed_482 = m_crossfeed_60;
		t_sample crossfeed_495 = crossfeed_482;
		t_sample crossfeed_485 = crossfeed_482;
		t_sample mul_466 = (crossfeed_482 * ((t_sample)0.6));
		t_sample crossfeed_479 = crossfeed_482;
		t_sample mul_467 = (crossfeed_479 * ((t_sample)0.6));
		t_sample add_826 = (m_Filter_On_48 + ((int)1));
		t_sample filterOn_802 = add_826;
		t_sample filterOn_596 = filterOn_802;
		t_sample filterOn_498 = filterOn_802;
		t_sample filter_700 = m_Filter_57;
		t_sample filter_597 = filter_700;
		int lte_616 = (filter_597 <= ((int)0));
		int not_615 = (!lte_616);
		__m_latch_89 = ((not_615 != 0) ? filter_597 : __m_latch_89);
		t_sample latch_617 = __m_latch_89;
		t_sample sub_8293 = (latch_617 - ((int)0));
		t_sample scale_8290 = ((safepow((sub_8293 * ((t_sample)0.01)), ((int)1)) * ((int)995)) + ((int)5));
		t_sample scale_621 = scale_8290;
		int gte_619 = (filter_597 >= ((int)0));
		int not_618 = (!gte_619);
		__m_latch_90 = ((not_618 != 0) ? filter_597 : __m_latch_90);
		t_sample latch_620 = __m_latch_90;
		t_sample sub_8297 = (latch_620 - (-100));
		t_sample scale_8294 = ((safepow((sub_8297 * ((t_sample)0.01)), ((int)1)) * ((int)22500)) + ((int)500));
		t_sample scale_622 = scale_8294;
		t_sample min_659 = ((scale_622 < ((int)0)) ? ((int)0) : scale_622);
		t_sample omega = safediv((min_659 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn = sin(omega);
		t_sample cs = cos(omega);
		t_sample alpha = ((sn * ((t_sample)0.5)) * ((int)2));
		t_sample b0 = safediv(((int)1), (((int)1) + alpha));
		t_sample a2 = (((((int)1) - cs) * ((t_sample)0.5)) * b0);
		t_sample a1 = ((((int)1) - cs) * b0);
		t_sample b1 = ((((int)-2) * cs) * b0);
		t_sample b2 = ((((int)1) - alpha) * b0);
		t_sample expr_675 = a2;
		t_sample expr_676 = a1;
		t_sample expr_677 = a2;
		t_sample expr_678 = b1;
		t_sample expr_679 = b2;
		t_sample min_631 = ((scale_621 < ((int)0)) ? ((int)0) : scale_621);
		t_sample omega_685 = safediv((min_631 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn_688 = sin(omega_685);
		t_sample cs_684 = cos(omega_685);
		t_sample alpha_689 = ((sn_688 * ((t_sample)0.5)) * ((t_sample)2));
		t_sample b_681 = safediv(((int)1), (((int)1) + alpha_689));
		t_sample a_682 = (((((int)1) + cs_684) * ((t_sample)0.5)) * b_681);
		t_sample a_687 = ((-(((int)1) + cs_684)) * b_681);
		t_sample b_686 = ((((int)-2) * cs_684) * b_681);
		t_sample b_683 = ((((int)1) - alpha_689) * b_681);
		t_sample expr_647 = a_682;
		t_sample expr_648 = a_687;
		t_sample expr_649 = a_682;
		t_sample expr_650 = b_686;
		t_sample expr_651 = b_683;
		t_sample choice_91 = int(filterOn_596);
		t_sample filter_499 = filter_700;
		int lte_518 = (filter_499 <= ((int)0));
		int not_517 = (!lte_518);
		__m_latch_92 = ((not_517 != 0) ? filter_499 : __m_latch_92);
		t_sample latch_519 = __m_latch_92;
		t_sample sub_8301 = (latch_519 - ((int)0));
		t_sample scale_8298 = ((safepow((sub_8301 * ((t_sample)0.01)), ((int)1)) * ((int)995)) + ((int)5));
		t_sample scale_523 = scale_8298;
		int gte_521 = (filter_499 >= ((int)0));
		int not_520 = (!gte_521);
		__m_latch_93 = ((not_520 != 0) ? filter_499 : __m_latch_93);
		t_sample latch_522 = __m_latch_93;
		t_sample sub_8305 = (latch_522 - (-100));
		t_sample scale_8302 = ((safepow((sub_8305 * ((t_sample)0.01)), ((int)1)) * ((int)22500)) + ((int)500));
		t_sample scale_524 = scale_8302;
		t_sample min_561 = ((scale_524 < ((int)0)) ? ((int)0) : scale_524);
		t_sample omega_8203 = safediv((min_561 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn_8206 = sin(omega_8203);
		t_sample cs_8201 = cos(omega_8203);
		t_sample alpha_8202 = ((sn_8206 * ((t_sample)0.5)) * ((int)2));
		t_sample b_8208 = safediv(((int)1), (((int)1) + alpha_8202));
		t_sample a_8199 = (((((int)1) - cs_8201) * ((t_sample)0.5)) * b_8208);
		t_sample a_8205 = ((((int)1) - cs_8201) * b_8208);
		t_sample b_8204 = ((((int)-2) * cs_8201) * b_8208);
		t_sample b_8200 = ((((int)1) - alpha_8202) * b_8208);
		t_sample expr_577 = a_8199;
		t_sample expr_578 = a_8205;
		t_sample expr_579 = a_8199;
		t_sample expr_580 = b_8204;
		t_sample expr_581 = b_8200;
		t_sample min_533 = ((scale_523 < ((int)0)) ? ((int)0) : scale_523);
		t_sample omega_587 = safediv((min_533 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn_589 = sin(omega_587);
		t_sample cs_586 = cos(omega_587);
		t_sample alpha_590 = ((sn_589 * ((t_sample)0.5)) * ((t_sample)2));
		t_sample b_583 = safediv(((int)1), (((int)1) + alpha_590));
		t_sample a_584 = (((((int)1) + cs_586) * ((t_sample)0.5)) * b_583);
		t_sample a_591 = ((-(((int)1) + cs_586)) * b_583);
		t_sample b_588 = ((((int)-2) * cs_586) * b_583);
		t_sample b_585 = ((((int)1) - alpha_590) * b_583);
		t_sample expr_549 = a_584;
		t_sample expr_550 = a_591;
		t_sample expr_551 = a_584;
		t_sample expr_552 = b_588;
		t_sample expr_553 = b_585;
		t_sample choice_94 = int(filterOn_498);
		t_sample add_822 = (m_Disto_54 + ((int)1));
		t_sample disto_801 = add_822;
		t_sample sub_8309 = (disto_801 - ((int)1));
		t_sample scale_8306 = ((safepow((sub_8309 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.32)) + ((int)1));
		t_sample scale_821 = scale_8306;
		t_sample disto_698 = disto_801;
		t_sample sub_8313 = (disto_698 - ((int)1));
		t_sample scale_8310 = ((safepow((sub_8313 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.32)) + ((int)1));
		t_sample scale_717 = scale_8310;
		t_sample pass_7925 = m_reset_55;
		t_sample add_462 = (pass_7925 + ((int)1));
		t_sample choice_95 = int(add_462);
		t_sample selector_465 = ((choice_95 >= 2) ? ((int)0) : ((choice_95 >= 1) ? m_feedback_52 : 0));
		t_sample fdback_463 = selector_465;
		t_sample fdback_464 = fdback_463;
		t_sample fdback_461 = fdback_463;
		t_sample fdback_460 = fdback_463;
		t_sample filterOn_699 = filterOn_802;
		int lte_723 = (filter_700 <= ((int)0));
		int not_722 = (!lte_723);
		__m_latch_96 = ((not_722 != 0) ? filter_700 : __m_latch_96);
		t_sample latch_724 = __m_latch_96;
		t_sample sub_8317 = (latch_724 - ((int)0));
		t_sample scale_8314 = ((safepow((sub_8317 * ((t_sample)0.01)), ((int)1)) * ((int)995)) + ((int)5));
		t_sample scale_728 = scale_8314;
		int gte_726 = (filter_700 >= ((int)0));
		int not_725 = (!gte_726);
		__m_latch_97 = ((not_725 != 0) ? filter_700 : __m_latch_97);
		t_sample latch_727 = __m_latch_97;
		t_sample sub_8321 = (latch_727 - (-100));
		t_sample scale_8318 = ((safepow((sub_8321 * ((t_sample)0.01)), ((int)1)) * ((int)22500)) + ((int)500));
		t_sample scale_729 = scale_8318;
		t_sample min_766 = ((scale_729 < ((int)0)) ? ((int)0) : scale_729);
		t_sample omega_8213 = safediv((min_766 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn_8216 = sin(omega_8213);
		t_sample cs_8211 = cos(omega_8213);
		t_sample alpha_8212 = ((sn_8216 * ((t_sample)0.5)) * ((int)2));
		t_sample b_8218 = safediv(((int)1), (((int)1) + alpha_8212));
		t_sample a_8209 = (((((int)1) - cs_8211) * ((t_sample)0.5)) * b_8218);
		t_sample a_8215 = ((((int)1) - cs_8211) * b_8218);
		t_sample b_8214 = ((((int)-2) * cs_8211) * b_8218);
		t_sample b_8210 = ((((int)1) - alpha_8212) * b_8218);
		t_sample expr_782 = a_8209;
		t_sample expr_783 = a_8215;
		t_sample expr_784 = a_8209;
		t_sample expr_785 = b_8214;
		t_sample expr_786 = b_8210;
		t_sample min_738 = ((scale_728 < ((int)0)) ? ((int)0) : scale_728);
		t_sample omega_792 = safediv((min_738 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn_795 = sin(omega_792);
		t_sample cs_791 = cos(omega_792);
		t_sample alpha_796 = ((sn_795 * ((t_sample)0.5)) * ((t_sample)2));
		t_sample b_788 = safediv(((int)1), (((int)1) + alpha_796));
		t_sample a_789 = (((((int)1) + cs_791) * ((t_sample)0.5)) * b_788);
		t_sample a_794 = ((-(((int)1) + cs_791)) * b_788);
		t_sample b_793 = ((((int)-2) * cs_791) * b_788);
		t_sample b_790 = ((((int)1) - alpha_796) * b_788);
		t_sample expr_754 = a_789;
		t_sample expr_755 = a_794;
		t_sample expr_756 = a_789;
		t_sample expr_757 = b_793;
		t_sample expr_758 = b_790;
		t_sample choice_98 = int(filterOn_699);
		t_sample mstosamps_4919 = (m_FadeOut_61 * (samplerate * 0.001));
		t_sample add_806 = (m_reverse_49 + ((int)1));
		t_sample reverse_805 = add_806;
		t_sample reverse_702 = reverse_805;
		t_sample reverse_599 = reverse_805;
		t_sample reverse_501 = reverse_805;
		int not_444 = (!pass_7925);
		t_sample iup_100 = (1 / maximum(1, abs(((int)100))));
		t_sample idown_101 = (1 / maximum(1, abs(mstosamps_4919)));
		t_sample filter_803 = filter_700;
		int lte_844 = (filter_803 <= ((int)0));
		int not_843 = (!lte_844);
		__m_latch_102 = ((not_843 != 0) ? filter_803 : __m_latch_102);
		t_sample latch_845 = __m_latch_102;
		t_sample sub_8325 = (latch_845 - ((int)0));
		t_sample scale_8322 = ((safepow((sub_8325 * ((t_sample)0.01)), ((int)1)) * ((int)995)) + ((int)5));
		t_sample scale_849 = scale_8322;
		int gte_847 = (filter_803 >= ((int)0));
		int not_846 = (!gte_847);
		__m_latch_103 = ((not_846 != 0) ? filter_803 : __m_latch_103);
		t_sample latch_848 = __m_latch_103;
		t_sample sub_8329 = (latch_848 - (-100));
		t_sample scale_8326 = ((safepow((sub_8329 * ((t_sample)0.01)), ((int)1)) * ((int)22500)) + ((int)500));
		t_sample scale_850 = scale_8326;
		t_sample min_887 = ((scale_850 < ((int)0)) ? ((int)0) : scale_850);
		t_sample omega_8222 = safediv((min_887 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn_8228 = sin(omega_8222);
		t_sample cs_8220 = cos(omega_8222);
		t_sample alpha_8221 = ((sn_8228 * ((t_sample)0.5)) * ((int)2));
		t_sample b_8226 = safediv(((int)1), (((int)1) + alpha_8221));
		t_sample a_8219 = (((((int)1) - cs_8220) * ((t_sample)0.5)) * b_8226);
		t_sample a_8224 = ((((int)1) - cs_8220) * b_8226);
		t_sample b_8223 = ((((int)-2) * cs_8220) * b_8226);
		t_sample b_8227 = ((((int)1) - alpha_8221) * b_8226);
		t_sample expr_903 = a_8219;
		t_sample expr_904 = a_8224;
		t_sample expr_905 = a_8219;
		t_sample expr_906 = b_8223;
		t_sample expr_907 = b_8227;
		t_sample min_859 = ((scale_849 < ((int)0)) ? ((int)0) : scale_849);
		t_sample omega_912 = safediv((min_859 * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn_915 = sin(omega_912);
		t_sample cs_917 = cos(omega_912);
		t_sample alpha_916 = ((sn_915 * ((t_sample)0.5)) * ((t_sample)2));
		t_sample b_909 = safediv(((int)1), (((int)1) + alpha_916));
		t_sample a_910 = (((((int)1) + cs_917) * ((t_sample)0.5)) * b_909);
		t_sample a_914 = ((-(((int)1) + cs_917)) * b_909);
		t_sample b_913 = ((((int)-2) * cs_917) * b_909);
		t_sample b_911 = ((((int)1) - alpha_916) * b_909);
		t_sample expr_875 = a_910;
		t_sample expr_876 = a_914;
		t_sample expr_877 = a_910;
		t_sample expr_878 = b_913;
		t_sample expr_879 = b_911;
		t_sample choice_104 = int(filterOn_802);
		t_sample choice_106 = int(reverse_805);
		int min_115 = (-1);
		t_sample choice_116 = int(reverse_599);
		int min_125 = (-1);
		int min_126 = (-1);
		t_sample choice_127 = int(reverse_702);
		int min_136 = (-1);
		t_sample choice_137 = int(reverse_501);
		int min_146 = (-1);
		int min_147 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample add_491 = (m_history_11 + m_history_6);
			__m_count_63 = (((int)0) ? 0 : (fixdenorm(__m_count_63 + ((int)1))));
			int carry_64 = 0;
			if ((((int)0) != 0)) {
				__m_count_63 = 0;
				__m_carry_65 = 0;
				
			} else if (((dim_507 > 0) && (__m_count_63 >= dim_507))) {
				int wraps_66 = (__m_count_63 / dim_507);
				__m_carry_65 = (__m_carry_65 + wraps_66);
				__m_count_63 = (__m_count_63 - (wraps_66 * dim_507));
				carry_64 = 1;
				
			};
			int counter_508 = __m_count_63;
			int counter_509 = carry_64;
			int counter_510 = __m_carry_65;
			t_sample add_492 = (m_history_12 + m_history_2);
			__m_count_67 = (((int)0) ? 0 : (fixdenorm(__m_count_67 + ((int)1))));
			int carry_68 = 0;
			if ((((int)0) != 0)) {
				__m_count_67 = 0;
				__m_carry_69 = 0;
				
			} else if (((dim_605 > 0) && (__m_count_67 >= dim_605))) {
				int wraps_70 = (__m_count_67 / dim_605);
				__m_carry_69 = (__m_carry_69 + wraps_70);
				__m_count_67 = (__m_count_67 - (wraps_70 * dim_605));
				carry_68 = 1;
				
			};
			int counter_606 = __m_count_67;
			int counter_607 = carry_68;
			int counter_608 = __m_carry_69;
			t_sample selector_925 = ((choice_71 >= 1) ? in2 : 0);
			t_sample add_514 = (selector_925 + add_491);
			bool index_ignore_72 = ((counter_508 >= delay4_dim) || (counter_508 < 0));
			if ((!index_ignore_72)) {
				m_delay_47.write(add_514, counter_508, 0);
				
			};
			t_sample selector_924 = ((choice_73 >= 1) ? in1 : 0);
			t_sample add_612 = (selector_924 + add_492);
			bool index_ignore_74 = ((counter_606 >= delay3_dim) || (counter_606 < 0));
			if ((!index_ignore_74)) {
				m_delay_46.write(add_612, counter_606, 0);
				
			};
			t_sample add_494 = (m_history_9 + m_history_3);
			t_sample add_819 = (selector_924 + add_494);
			t_sample add_493 = (m_history_10 + m_history_7);
			t_sample add_715 = (selector_925 + add_493);
			__m_count_77 = (((int)0) ? 0 : (fixdenorm(__m_count_77 + speed_827)));
			int carry_78 = 0;
			if ((((int)0) != 0)) {
				__m_count_77 = 0;
				__m_carry_79 = 0;
				
			} else if (((dim_812 > 0) && (__m_count_77 >= dim_812))) {
				int wraps_80 = (__m_count_77 / dim_812);
				__m_carry_79 = (__m_carry_79 + wraps_80);
				__m_count_77 = (__m_count_77 - (wraps_80 * dim_812));
				carry_78 = 1;
				
			};
			t_sample counter_813 = __m_count_77;
			int counter_814 = carry_78;
			int counter_815 = __m_carry_79;
			int index_trunc_81 = fixnan(floor(counter_813));
			bool index_ignore_82 = ((index_trunc_81 >= delay1_dim) || (index_trunc_81 < 0));
			if ((!index_ignore_82)) {
				m_delay_50.write(add_819, index_trunc_81, 0);
				
			};
			__m_count_83 = (((int)0) ? 0 : (fixdenorm(__m_count_83 + speed_721)));
			int carry_84 = 0;
			if ((((int)0) != 0)) {
				__m_count_83 = 0;
				__m_carry_85 = 0;
				
			} else if (((dim_708 > 0) && (__m_count_83 >= dim_708))) {
				int wraps_86 = (__m_count_83 / dim_708);
				__m_carry_85 = (__m_carry_85 + wraps_86);
				__m_count_83 = (__m_count_83 - (wraps_86 * dim_708));
				carry_84 = 1;
				
			};
			t_sample counter_709 = __m_count_83;
			int counter_710 = carry_84;
			int counter_711 = __m_carry_85;
			int index_trunc_87 = fixnan(floor(counter_709));
			bool index_ignore_88 = ((index_trunc_87 >= delay2_dim) || (index_trunc_87 < 0));
			if ((!index_ignore_88)) {
				m_delay_62.write(add_715, index_trunc_87, 0);
				
			};
			t_sample mul_669 = (m_history_5 * expr_675);
			t_sample mul_666 = (m_history_43 * expr_676);
			t_sample mul_664 = (m_history_45 * expr_677);
			t_sample mul_660 = (m_history_44 * expr_679);
			t_sample mul_662 = (m_history_42 * expr_678);
			t_sample sub_668 = (((mul_664 + mul_666) + mul_669) - (mul_662 + mul_660));
			t_sample gen_674 = sub_668;
			t_sample history_665_next_670 = fixdenorm(m_history_43);
			t_sample history_661_next_671 = fixdenorm(m_history_42);
			t_sample history_667_next_672 = fixdenorm(m_history_5);
			t_sample history_663_next_673 = fixdenorm(sub_668);
			t_sample gen_680 = gen_674;
			t_sample mul_641 = (gen_680 * expr_647);
			t_sample mul_638 = (m_history_39 * expr_648);
			t_sample mul_636 = (m_history_41 * expr_649);
			t_sample mul_632 = (m_history_40 * expr_651);
			t_sample mul_634 = (m_history_38 * expr_650);
			t_sample sub_640 = (((mul_636 + mul_638) + mul_641) - (mul_634 + mul_632));
			t_sample gen_646 = sub_640;
			t_sample history_637_next_642 = fixdenorm(m_history_39);
			t_sample history_633_next_643 = fixdenorm(m_history_38);
			t_sample history_639_next_644 = fixdenorm(gen_680);
			t_sample history_635_next_645 = fixdenorm(sub_640);
			t_sample gen_652 = gen_646;
			t_sample gen_690 = gen_652;
			t_sample selector_613 = ((choice_91 >= 2) ? gen_690 : ((choice_91 >= 1) ? m_history_5 : 0));
			t_sample mul_571 = (m_history_1 * expr_577);
			t_sample mul_568 = (m_history_35 * expr_578);
			t_sample mul_566 = (m_history_36 * expr_579);
			t_sample mul_562 = (m_history_37 * expr_581);
			t_sample mul_564 = (m_history_34 * expr_580);
			t_sample sub_570 = (((mul_566 + mul_568) + mul_571) - (mul_564 + mul_562));
			t_sample gen_576 = sub_570;
			t_sample history_563_next_572 = fixdenorm(m_history_34);
			t_sample history_567_next_573 = fixdenorm(m_history_35);
			t_sample history_569_next_574 = fixdenorm(m_history_1);
			t_sample history_565_next_575 = fixdenorm(sub_570);
			t_sample gen_582 = gen_576;
			t_sample mul_543 = (gen_582 * expr_549);
			t_sample mul_540 = (m_history_31 * expr_550);
			t_sample mul_538 = (m_history_32 * expr_551);
			t_sample mul_534 = (m_history_33 * expr_553);
			t_sample mul_536 = (m_history_30 * expr_552);
			t_sample sub_542 = (((mul_538 + mul_540) + mul_543) - (mul_536 + mul_534));
			t_sample gen_548 = sub_542;
			t_sample history_535_next_544 = fixdenorm(m_history_30);
			t_sample history_539_next_545 = fixdenorm(m_history_31);
			t_sample history_541_next_546 = fixdenorm(gen_582);
			t_sample history_537_next_547 = fixdenorm(sub_542);
			t_sample gen_554 = gen_548;
			t_sample gen_592 = gen_554;
			t_sample selector_515 = ((choice_94 >= 2) ? gen_592 : ((choice_94 >= 1) ? m_history_1 : 0));
			t_sample mul_776 = (m_history_4 * expr_782);
			t_sample mul_773 = (m_history_27 * expr_783);
			t_sample mul_771 = (m_history_28 * expr_784);
			t_sample mul_767 = (m_history_29 * expr_786);
			t_sample mul_769 = (m_history_26 * expr_785);
			t_sample sub_775 = (((mul_771 + mul_773) + mul_776) - (mul_769 + mul_767));
			t_sample gen_781 = sub_775;
			t_sample history_768_next_777 = fixdenorm(m_history_26);
			t_sample history_772_next_778 = fixdenorm(m_history_27);
			t_sample history_774_next_779 = fixdenorm(m_history_4);
			t_sample history_770_next_780 = fixdenorm(sub_775);
			t_sample gen_787 = gen_781;
			t_sample mul_748 = (gen_787 * expr_754);
			t_sample mul_745 = (m_history_23 * expr_755);
			t_sample mul_743 = (m_history_25 * expr_756);
			t_sample mul_739 = (m_history_24 * expr_758);
			t_sample mul_741 = (m_history_22 * expr_757);
			t_sample sub_747 = (((mul_743 + mul_745) + mul_748) - (mul_741 + mul_739));
			t_sample gen_753 = sub_747;
			t_sample history_744_next_749 = fixdenorm(m_history_23);
			t_sample history_740_next_750 = fixdenorm(m_history_22);
			t_sample history_746_next_751 = fixdenorm(gen_787);
			t_sample history_742_next_752 = fixdenorm(sub_747);
			t_sample gen_759 = gen_753;
			t_sample gen_797 = gen_759;
			t_sample selector_720 = ((choice_98 >= 2) ? gen_797 : ((choice_98 >= 1) ? m_history_4 : 0));
			t_sample mul_718 = (selector_720 * disto_698);
			t_sample tanh_719 = tanh(mul_718);
			t_sample mul_716 = (tanh_719 * scale_717);
			__m_slide_99 = fixdenorm((__m_slide_99 + (((not_444 > __m_slide_99) ? iup_100 : idown_101) * (not_444 - __m_slide_99))));
			t_sample slide_6058 = __m_slide_99;
			t_sample pass_6711 = slide_6058;
			t_sample mul_897 = (m_history_8 * expr_903);
			t_sample mul_894 = (m_history_19 * expr_904);
			t_sample mul_892 = (m_history_21 * expr_905);
			t_sample mul_888 = (m_history_20 * expr_907);
			t_sample mul_890 = (m_history_18 * expr_906);
			t_sample sub_896 = (((mul_892 + mul_894) + mul_897) - (mul_890 + mul_888));
			t_sample gen_902 = sub_896;
			t_sample history_893_next_898 = fixdenorm(m_history_19);
			t_sample history_889_next_899 = fixdenorm(m_history_18);
			t_sample history_895_next_900 = fixdenorm(m_history_8);
			t_sample history_891_next_901 = fixdenorm(sub_896);
			t_sample gen_908 = gen_902;
			t_sample mul_869 = (gen_908 * expr_875);
			t_sample mul_866 = (m_history_15 * expr_876);
			t_sample mul_864 = (m_history_16 * expr_877);
			t_sample mul_860 = (m_history_17 * expr_879);
			t_sample mul_862 = (m_history_14 * expr_878);
			t_sample sub_868 = (((mul_864 + mul_866) + mul_869) - (mul_862 + mul_860));
			t_sample gen_874 = sub_868;
			t_sample history_861_next_870 = fixdenorm(m_history_14);
			t_sample history_865_next_871 = fixdenorm(m_history_15);
			t_sample history_867_next_872 = fixdenorm(gen_908);
			t_sample history_863_next_873 = fixdenorm(sub_868);
			t_sample gen_880 = gen_874;
			t_sample gen_918 = gen_880;
			t_sample selector_825 = ((choice_104 >= 2) ? gen_918 : ((choice_104 >= 1) ? m_history_8 : 0));
			t_sample mul_823 = (selector_825 * disto_801);
			t_sample tanh_824 = tanh(mul_823);
			t_sample mul_820 = (tanh_824 * scale_821);
			t_sample tap_470 = m_delay_13.read_step(((int)24000));
			int eq_471 = (m_time_56 == tap_470);
			__m_latch_105 = ((eq_471 != 0) ? m_time_56 : __m_latch_105);
			t_sample latch_468 = __m_latch_105;
			t_sample mstosamps_472 = (latch_468 * (samplerate * 0.001));
			t_sample time_489 = mstosamps_472;
			t_sample time_804 = time_489;
			t_sample sub_810 = (counter_813 - time_804);
			t_sample sub_811 = (time_804 - counter_813);
			t_sample selector_809 = ((choice_106 >= 2) ? sub_811 : ((choice_106 >= 1) ? sub_810 : 0));
			int index_trunc_107 = fixnan(floor(selector_809));
			double index_fract_108 = (selector_809 - index_trunc_107);
			int index_trunc_109 = (index_trunc_107 + 1);
			int index_wrap_110 = ((index_trunc_107 < 0) ? ((delay1_dim - 1) + ((index_trunc_107 + 1) % delay1_dim)) : (index_trunc_107 % delay1_dim));
			int index_wrap_111 = ((index_trunc_109 < 0) ? ((delay1_dim - 1) + ((index_trunc_109 + 1) % delay1_dim)) : (index_trunc_109 % delay1_dim));
			// samples delay1 channel 1;
			double read_delay_112 = m_delay_50.read(index_wrap_110, 0);
			double read_delay_113 = m_delay_50.read(index_wrap_111, 0);
			double readinterp_114 = linear_interp(index_fract_108, read_delay_112, read_delay_113);
			t_sample sample_delay_816 = readinterp_114;
			t_sample index_delay_817 = selector_809;
			t_sample clamp_921 = ((sample_delay_816 <= min_115) ? min_115 : ((sample_delay_816 >= ((int)1)) ? ((int)1) : sample_delay_816));
			t_sample mul_920 = (clamp_921 * fdback_464);
			t_sample mul_497 = (clamp_921 * crossfeed_495);
			t_sample mul_598 = (time_489 * ((t_sample)0.419));
			t_sample sub_603 = (counter_606 - mul_598);
			t_sample sub_604 = (mul_598 - counter_606);
			t_sample selector_602 = ((choice_116 >= 2) ? sub_604 : ((choice_116 >= 1) ? sub_603 : 0));
			int index_trunc_117 = fixnan(floor(selector_602));
			double index_fract_118 = (selector_602 - index_trunc_117);
			int index_trunc_119 = (index_trunc_117 + 1);
			int index_wrap_120 = ((index_trunc_117 < 0) ? ((delay3_dim - 1) + ((index_trunc_117 + 1) % delay3_dim)) : (index_trunc_117 % delay3_dim));
			int index_wrap_121 = ((index_trunc_119 < 0) ? ((delay3_dim - 1) + ((index_trunc_119 + 1) % delay3_dim)) : (index_trunc_119 % delay3_dim));
			// samples delay3 channel 1;
			double read_delay_122 = m_delay_46.read(index_wrap_120, 0);
			double read_delay_123 = m_delay_46.read(index_wrap_121, 0);
			double readinterp_124 = linear_interp(index_fract_118, read_delay_122, read_delay_123);
			t_sample sample_delay_609 = readinterp_124;
			t_sample index_delay_610 = selector_602;
			t_sample clamp_693 = ((sample_delay_609 <= min_125) ? min_125 : ((sample_delay_609 >= ((int)1)) ? ((int)1) : sample_delay_609));
			t_sample mul_481 = (clamp_693 * mul_467);
			t_sample mul_692 = (clamp_693 * fdback_461);
			t_sample mul_477 = (clamp_693 * ((t_sample)0.45));
			t_sample mul_478 = (m_double_58 * mul_477);
			t_sample mix_8330 = (clamp_921 + (((t_sample)0.5) * (mul_478 - clamp_921)));
			t_sample clamp_696 = ((mix_8330 <= min_126) ? min_126 : ((mix_8330 >= ((int)1)) ? ((int)1) : mix_8330));
			t_sample mul_447 = (clamp_696 * pass_6711);
			t_sample mix_8331 = (in1 + (m_mix_51 * (mul_447 - in1)));
			t_sample out1 = mix_8331;
			t_sample time_490 = time_489;
			t_sample mul_701 = (time_490 * ((t_sample)0.881));
			t_sample sub_706 = (counter_709 - mul_701);
			t_sample sub_707 = (mul_701 - counter_709);
			t_sample selector_705 = ((choice_127 >= 2) ? sub_707 : ((choice_127 >= 1) ? sub_706 : 0));
			int index_trunc_128 = fixnan(floor(selector_705));
			double index_fract_129 = (selector_705 - index_trunc_128);
			int index_trunc_130 = (index_trunc_128 + 1);
			int index_wrap_131 = ((index_trunc_128 < 0) ? ((delay2_dim - 1) + ((index_trunc_128 + 1) % delay2_dim)) : (index_trunc_128 % delay2_dim));
			int index_wrap_132 = ((index_trunc_130 < 0) ? ((delay2_dim - 1) + ((index_trunc_130 + 1) % delay2_dim)) : (index_trunc_130 % delay2_dim));
			// samples delay2 channel 1;
			double read_delay_133 = m_delay_62.read(index_wrap_131, 0);
			double read_delay_134 = m_delay_62.read(index_wrap_132, 0);
			double readinterp_135 = linear_interp(index_fract_129, read_delay_133, read_delay_134);
			t_sample sample_delay_712 = readinterp_135;
			t_sample index_delay_713 = selector_705;
			t_sample clamp_800 = ((sample_delay_712 <= min_136) ? min_136 : ((sample_delay_712 >= ((int)1)) ? ((int)1) : sample_delay_712));
			t_sample mul_799 = (clamp_800 * fdback_463);
			t_sample mul_487 = (clamp_800 * crossfeed_485);
			t_sample time_488 = time_489;
			t_sample mul_500 = (time_488 * ((t_sample)0.179));
			t_sample sub_505 = (counter_508 - mul_500);
			t_sample sub_506 = (mul_500 - counter_508);
			t_sample selector_504 = ((choice_137 >= 2) ? sub_506 : ((choice_137 >= 1) ? sub_505 : 0));
			int index_trunc_138 = fixnan(floor(selector_504));
			double index_fract_139 = (selector_504 - index_trunc_138);
			int index_trunc_140 = (index_trunc_138 + 1);
			int index_wrap_141 = ((index_trunc_138 < 0) ? ((delay4_dim - 1) + ((index_trunc_138 + 1) % delay4_dim)) : (index_trunc_138 % delay4_dim));
			int index_wrap_142 = ((index_trunc_140 < 0) ? ((delay4_dim - 1) + ((index_trunc_140 + 1) % delay4_dim)) : (index_trunc_140 % delay4_dim));
			// samples delay4 channel 1;
			double read_delay_143 = m_delay_47.read(index_wrap_141, 0);
			double read_delay_144 = m_delay_47.read(index_wrap_142, 0);
			double readinterp_145 = linear_interp(index_fract_139, read_delay_143, read_delay_144);
			t_sample sample_delay_511 = readinterp_145;
			t_sample index_delay_512 = selector_504;
			t_sample clamp_595 = ((sample_delay_511 <= min_146) ? min_146 : ((sample_delay_511 >= ((int)1)) ? ((int)1) : sample_delay_511));
			t_sample mul_484 = (clamp_595 * mul_466);
			t_sample mul_594 = (clamp_595 * fdback_460);
			t_sample mul_474 = (clamp_595 * ((t_sample)0.45));
			t_sample mul_475 = (m_double_58 * mul_474);
			t_sample mix_8332 = (clamp_800 + (((t_sample)0.5) * (mul_475 - clamp_800)));
			t_sample clamp_697 = ((mix_8332 <= min_147) ? min_147 : ((mix_8332 >= ((int)1)) ? ((int)1) : mix_8332));
			t_sample mul_446 = (clamp_697 * pass_6711);
			t_sample mix_8333 = (in2 + (m_mix_51 * (mul_446 - in2)));
			t_sample out2 = mix_8333;
			t_sample history_611_next_8230 = fixdenorm(selector_613);
			t_sample history_513_next_8231 = fixdenorm(selector_515);
			t_sample history_714_next_8232 = fixdenorm(mul_716);
			t_sample history_818_next_8233 = fixdenorm(mul_820);
			t_sample history_919_next_8234 = fixdenorm(mul_920);
			t_sample history_496_next_8235 = fixdenorm(mul_497);
			t_sample history_480_next_8236 = fixdenorm(mul_481);
			t_sample history_691_next_8237 = fixdenorm(mul_692);
			t_sample history_798_next_8238 = fixdenorm(mul_799);
			t_sample history_486_next_8239 = fixdenorm(mul_487);
			t_sample history_483_next_8240 = fixdenorm(mul_484);
			t_sample history_593_next_8241 = fixdenorm(mul_594);
			m_history_45 = history_665_next_670;
			m_history_38 = history_635_next_645;
			m_history_39 = history_639_next_644;
			m_history_40 = history_633_next_643;
			m_history_41 = history_637_next_642;
			m_history_42 = history_663_next_673;
			m_history_43 = history_667_next_672;
			m_history_44 = history_661_next_671;
			m_history_37 = history_563_next_572;
			m_history_30 = history_537_next_547;
			m_history_31 = history_541_next_546;
			m_history_32 = history_539_next_545;
			m_history_33 = history_535_next_544;
			m_history_34 = history_565_next_575;
			m_history_35 = history_569_next_574;
			m_history_36 = history_567_next_573;
			m_history_29 = history_768_next_777;
			m_history_22 = history_742_next_752;
			m_history_23 = history_746_next_751;
			m_history_24 = history_740_next_750;
			m_history_25 = history_744_next_749;
			m_history_26 = history_770_next_780;
			m_history_27 = history_774_next_779;
			m_history_28 = history_772_next_778;
			m_history_21 = history_893_next_898;
			m_history_14 = history_863_next_873;
			m_history_15 = history_867_next_872;
			m_history_16 = history_865_next_871;
			m_history_17 = history_861_next_870;
			m_history_18 = history_891_next_901;
			m_history_19 = history_895_next_900;
			m_history_20 = history_889_next_899;
			m_delay_13.write(m_time_56);
			m_history_12 = history_611_next_8230;
			m_history_11 = history_513_next_8231;
			m_history_10 = history_714_next_8232;
			m_history_9 = history_818_next_8233;
			m_history_8 = history_919_next_8234;
			m_history_7 = history_496_next_8235;
			m_history_6 = history_480_next_8236;
			m_history_5 = history_691_next_8237;
			m_history_4 = history_798_next_8238;
			m_history_3 = history_486_next_8239;
			m_history_2 = history_483_next_8240;
			m_history_1 = history_593_next_8241;
			m_delay_13.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			
		};
		return __exception;
		
	};
	inline void set_delay3(void * _value) {
		m_delay_46.setbuffer(_value);
	};
	inline void set_delay4(void * _value) {
		m_delay_47.setbuffer(_value);
	};
	inline void set_Filter_On(t_param _value) {
		m_Filter_On_48 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_reverse(t_param _value) {
		m_reverse_49 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_delay1(void * _value) {
		m_delay_50.setbuffer(_value);
	};
	inline void set_mix(t_param _value) {
		m_mix_51 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_feedback(t_param _value) {
		m_feedback_52 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_REC(t_param _value) {
		m_REC_53 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_Disto(t_param _value) {
		m_Disto_54 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_reset(t_param _value) {
		m_reset_55 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_time(t_param _value) {
		m_time_56 = (_value < 100 ? 100 : (_value > 10000 ? 10000 : _value));
	};
	inline void set_Filter(t_param _value) {
		m_Filter_57 = (_value < -100 ? -100 : (_value > 100 ? 100 : _value));
	};
	inline void set_double(t_param _value) {
		m_double_58 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_speed(t_param _value) {
		m_speed_59 = (_value < 0.5 ? 0.5 : (_value > 2 ? 2 : _value));
	};
	inline void set_crossfeed(t_param _value) {
		m_crossfeed_60 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_FadeOut(t_param _value) {
		m_FadeOut_61 = (_value < 0 ? 0 : (_value > 10000 ? 10000 : _value));
	};
	inline void set_delay2(void * _value) {
		m_delay_62.setbuffer(_value);
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
int num_params() { return 17; }

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
		case 0: self->set_Disto(value); break;
		case 1: self->set_FadeOut(value); break;
		case 2: self->set_Filter(value); break;
		case 3: self->set_Filter_On(value); break;
		case 4: self->set_REC(value); break;
		case 5: self->set_crossfeed(value); break;
		case 6: self->set_delay1(ref); break;
		case 7: self->set_delay2(ref); break;
		case 8: self->set_delay3(ref); break;
		case 9: self->set_delay4(ref); break;
		case 10: self->set_double(value); break;
		case 11: self->set_feedback(value); break;
		case 12: self->set_mix(value); break;
		case 13: self->set_reset(value); break;
		case 14: self->set_reverse(value); break;
		case 15: self->set_speed(value); break;
		case 16: self->set_time(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_Disto_54; break;
		case 1: *value = self->m_FadeOut_61; break;
		case 2: *value = self->m_Filter_57; break;
		case 3: *value = self->m_Filter_On_48; break;
		case 4: *value = self->m_REC_53; break;
		case 5: *value = self->m_crossfeed_60; break;
		
		
		
		
		case 10: *value = self->m_double_58; break;
		case 11: *value = self->m_feedback_52; break;
		case 12: *value = self->m_mix_51; break;
		case 13: *value = self->m_reset_55; break;
		case 14: *value = self->m_reverse_49; break;
		case 15: *value = self->m_speed_59; break;
		case 16: *value = self->m_time_56; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(17 * sizeof(ParamInfo));
	self->__commonstate.numparams = 17;
	// initialize parameter 0 ("m_Disto_54")
	pi = self->__commonstate.params + 0;
	pi->name = "Disto";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Disto_54;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_FadeOut_61")
	pi = self->__commonstate.params + 1;
	pi->name = "FadeOut";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_FadeOut_61;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 10000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_Filter_57")
	pi = self->__commonstate.params + 2;
	pi->name = "Filter";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Filter_57;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -100;
	pi->outputmax = 100;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_Filter_On_48")
	pi = self->__commonstate.params + 3;
	pi->name = "Filter_On";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Filter_On_48;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_REC_53")
	pi = self->__commonstate.params + 4;
	pi->name = "REC";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_REC_53;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_crossfeed_60")
	pi = self->__commonstate.params + 5;
	pi->name = "crossfeed";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_crossfeed_60;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_delay_50")
	pi = self->__commonstate.params + 6;
	pi->name = "delay1";
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
	// initialize parameter 7 ("m_delay_62")
	pi = self->__commonstate.params + 7;
	pi->name = "delay2";
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
	// initialize parameter 8 ("m_delay_46")
	pi = self->__commonstate.params + 8;
	pi->name = "delay3";
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
	// initialize parameter 9 ("m_delay_47")
	pi = self->__commonstate.params + 9;
	pi->name = "delay4";
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
	// initialize parameter 10 ("m_double_58")
	pi = self->__commonstate.params + 10;
	pi->name = "double";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_double_58;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_feedback_52")
	pi = self->__commonstate.params + 11;
	pi->name = "feedback";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_feedback_52;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_mix_51")
	pi = self->__commonstate.params + 12;
	pi->name = "mix";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_mix_51;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_reset_55")
	pi = self->__commonstate.params + 13;
	pi->name = "reset";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_reset_55;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_reverse_49")
	pi = self->__commonstate.params + 14;
	pi->name = "reverse";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_reverse_49;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_speed_59")
	pi = self->__commonstate.params + 15;
	pi->name = "speed";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_speed_59;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.5;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_time_56")
	pi = self->__commonstate.params + 16;
	pi->name = "time";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_time_56;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 100;
	pi->outputmax = 10000;
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
