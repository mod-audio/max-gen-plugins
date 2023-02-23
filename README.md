max-gen-plugins
===============

Collection of MAX gen~ based audio plugins used in MOD Audio.  
Stored in a single source code repository to make it easy for contributors and MOD staff to add and maintain these plugins.

This source code repository has the following contents:

- **dpf** - the plugin framework used to get CLAP, LV2, VST2, VST3 formats from a single implementation; for MOD we only care about the LV2 format for now
- **max-gen** - custom code that integrates the gen~ exported code in DPF
- **plugins** - gen~ exported plugins, each including the exported code plus a custom `DistrhoPluginInfo.h` for plugin meta-data and a README supplied by the author
- **presets** - optional, LV2 presets to be included on the MOD plugin store builds of each plugin

### BUILDING

For building you will need a POSIX-compliant compiler (GCC or Clang) plus GNU Make.  
Building is a simple as running `make` after cloning this repository, assuming you have the needed tools installed.

Note that this repository uses git submodules, so cloning with `git clone --recursive` is required.

After building you will find CLAP, LV2, VST2 and VST3 plugin builds in a newly created `./bin` directory.  
Alternatively you can download nightly builds from the [generated GitHub actions](https://github.com/moddevices/max-gen-plugins/actions/build).

#### BUILDING FOR MOD

If you already have "bootstrapped" [mod-plugin-builder](https://github.com/moddevices/mod-plugin-builder) before, building for e.g. MOD Dwarf is as simple as:

```
make moddwarf
```

Change `moddwarf` to `modduo` or `modduox` if applicable.

After building, you can directly push the bundle into a MOD unit over USB by running:

```sh
make modpush
```
