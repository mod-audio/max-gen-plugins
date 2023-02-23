# MIRRORZ
Plugin lv2   build with Max Gen~   for the Mod Dwarf

Audio IN is permanently recorded in a 32 seconds buffer (normal speed)
the TRIGGER function of MIRRORZ allows you to play backward the last chords/ melody you just played, same for the LOOP function but looped.

Control Ports:

TRIGGER : Default 0, Min 0, Max 1
LOOP : Default 0, Min 0, Max 1
DRY/WET : Default 0.25, Min 0, Max 1.
FILTER : Default 0, Min -100, Max +100
SPEED : Default 1, Min 0.5, Max 2

How it works:

Pressing TRIGGER (momentary ON ) start reading audio backward from the last sampled position within the data/buffer, releasing TRIGGER stop reading audio.

Pressing LOOP (momentary ON ) reads audio backward from the last sampled position within the data/buffer, releasing "LOOP" loop the buffer segment just read. Pressing TRIGGER stop the loop (if you keep TRIGGER pressed, it reads audio backward from the last sampled position within the data/buffer)

Dry/wet obvious

Filter   0 → -100 Low pass , 0 → 100 High pass

Speed   0.5 = half speed, 1 octave down  1= normal speed     2= double speed, 1 octave up


