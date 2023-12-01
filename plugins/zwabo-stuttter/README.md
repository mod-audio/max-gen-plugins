# Stuttter
Double Stutter effect (L/R) with time division 1/4 note, 1/8 note , etc...
but also odd division 5tuplet, 7tuplet, 9tuplet, 11tuplet which could give interesting polyrythmic effects at slow tempo. An ambiant soft and harsh tool in one plugin..


Max gen~ plugin compiled with Christosku docker container

BPM : time between 20 and 240 bpm

DIV_L  and  DIV_R : Independant time division for channel left and right  1/4 note, dotted1/8 note , 1/4 note triplets, 1/8 note, etc ….and also odd division 5tuplet, 7tuplet, 9tuplet, 11tuplet which could give interesting polyrythmic effects at slow tempo

DOUBLE: when engaged, left and right are active, disengaged only DIV_L is active in mono.

FILTER_R :  when Double is engaged, allow filtering for channel right (interesting when playing on a mono source)

ZTUTTER :  record and trig the stutter effect

Dry/Wet:  mix dry/wet

RANDOM: when engaged, random tempo/division on each ZTUTTER trig

RANGE : random range 1 (random time longer) to 10 (random time shorter)

TAIL : add a tail when stopping stutter (artifacts with random…)

ENV : add an envelop to avoid clicks and/or tweak the loop


