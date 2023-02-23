#!/usr/bin/make -f
# Makefile for max-gen-plugins #
# ---------------------------- #
# Created by falkTX
#

# NOTE NAME must be defined before including this file!

# ---------------------------------------------------------------------------------------------------------------------
# Files to build

FILES_DSP = ./max-gen/DistrhoPluginMaxGen.cpp

# ---------------------------------------------------------------------------------------------------------------------
# Do some magic

include ./dpf/Makefile.plugins.mk

# ---------------------------------------------------------------------------------------------------------------------
# Extra flags

BUILD_CXX_FLAGS += -I./max-gen
BUILD_CXX_FLAGS += -I./max-gen/gen_dsp
BUILD_CXX_FLAGS += -I./plugins/$(NAME)
BUILD_CXX_FLAGS += -Wno-unused-parameter
BUILD_CXX_FLAGS += -Wno-unused-variable

# ---------------------------------------------------------------------------------------------------------------------
# Enable all useful plugin types

ifeq ($(MOD_BUILD),true)
all: lv2_dsp
else
all: lv2_sep vst2 vst3 clap
endif

# ---------------------------------------------------------------------------------------------------------------------
