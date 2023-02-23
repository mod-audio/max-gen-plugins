#!/usr/bin/make -f
# Makefile for max-gen-plugins #
# ---------------------------- #
# Created by falkTX
#

include dpf/Makefile.base.mk

# ---------------------------------------------------------------------------------------------------------------------
# helper macros

PLUGINS = $(subst plugins/,,$(wildcard plugins/*))

# ---------------------------------------------------------------------------------------------------------------------
# build rules

all: plugins gen

plugins:
	$(foreach p,$(PLUGINS),$(MAKE) all -f max-gen/Makefile.common.mk NAME=${p})

ifneq ($(CROSS_COMPILING),true)
gen: plugins dpf/utils/lv2_ttl_generator
	@$(CURDIR)/dpf/utils/generate-ttl.sh

dpf/utils/lv2_ttl_generator:
	$(MAKE) -C dpf/utils/lv2-ttl-generator
else
gen:
endif

# ---------------------------------------------------------------------------------------------------------------------
# cleanup

clean:
	$(foreach p,$(PLUGINS),$(MAKE) clean -f max-gen/Makefile.common.mk NAME=${p})
	$(MAKE) clean -C dpf/utils/lv2-ttl-generator
	rm -rf bin build

# ---------------------------------------------------------------------------------------------------------------------

.PHONY: plugins
