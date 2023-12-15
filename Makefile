#!/usr/bin/make -f
# Makefile for max-gen-plugins #
# ---------------------------- #
# Created by falkTX
#

include dpf/Makefile.base.mk

# ---------------------------------------------------------------------------------------------------------------------
# helper macros

PLUGINS = $(subst plugins/,,$(wildcard plugins/*))

CUSTOM_TTL = $(subst custom-ttl/,,$(wildcard custom-ttl/*))

# ---------------------------------------------------------------------------------------------------------------------
# build rules

all: plugins gen

plugins:
	$(foreach p,$(PLUGINS),$(MAKE) all -f max-gen/Makefile.common.mk NAME=${p};)

gen: plugins pregen
	$(foreach p,$(CUSTOM_TTL),cp custom-ttl/${p}/*.ttl bin/${p}.lv2/;)

ifneq ($(CROSS_COMPILING),true)
pregen: plugins dpf/utils/lv2_ttl_generator
	@$(CURDIR)/dpf/utils/generate-ttl.sh

dpf/utils/lv2_ttl_generator:
	$(MAKE) -C dpf/utils/lv2-ttl-generator
else
pregen:
endif

# ---------------------------------------------------------------------------------------------------------------------
# cleanup

clean:
	$(foreach p,$(PLUGINS),$(MAKE) clean -f max-gen/Makefile.common.mk NAME=${p};)
	$(MAKE) clean -C dpf/utils/lv2-ttl-generator
	rm -rf bin build

# ---------------------------------------------------------------------------------------------------------------------

.PHONY: plugins
