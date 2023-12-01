# Ztoggle4
Lv2 plugin created for the Mod Dwarf

Ztoggle4 gets one audio stream as input and chooses one of four outputs to route the audio. When the SELECT switch is activated (MIDI and CV assignable) the audio stream pass to the next output .

The CYCLE selector has four modes :
1) 1  (only usefull if KILLSWITCH is engaged)
2) 1-2 
3) 1-2-3
4) 1-2-3-4

When the KILLSWITCH is engaged , the SELECT switch cuts audio when it’s on.

Dwarf installation on a Mac:
- Open Terminal

  ```
  scp -rp <path to zwabo-ztoggle4.lv2> root@192.168.51.1:/root/.lv2
  ```

- Enter password "mod"

- Reboot Mod
