#  Xfade1to2st
##  lv2 plugin utility , crossfade L R  input to 2 L R outputs

Two parameters.

MIX:
- mix the input to the two outputs
 
RANGE :
- at 0 , when mix is in the middle position, the output gain is 0.5 x the input gain for each output.
- at 1,  when mix is in the middle position, the output gain is 1x the input gain for each output. You can choose in between according to your needs. 

A slight smoothing is implemented in order to avoid scale effects. 

--------------------------

Mod devices installation 

• Copy the zwabo-xfade1to2st.lv2 folder to your Mod: 
```
scp -rp <path to zwabo-xfade1to2st.lv2> root@192.168.51.1:/root/.lv2
```
• Enter password "mod"

• Reboot Mod
