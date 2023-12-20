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
MODGUIS = $(subst custom-ttl/,,$(subst /modgui,,$(wildcard custom-ttl/*/modgui)))

# ---------------------------------------------------------------------------------------------------------------------
# build rules

all: pregen
	$(foreach p,$(CUSTOM_TTL),cp custom-ttl/${p}/*.ttl bin/${p}.lv2/;)
	$(foreach p,$(MODGUIS),cp -r custom-ttl/${p}/modgui bin/${p}.lv2/;)

pregen: plugins dpf/utils/lv2_ttl_generator
	@$(CURDIR)/dpf/utils/generate-ttl.sh

plugins: plugins/*/DistrhoPluginInfo.h plugins/*/gen_exported.*
	$(foreach p,$(PLUGINS),$(MAKE) all -f max-gen/Makefile.common.mk NAME=${p};)

dpf/utils/lv2_ttl_generator$(APP_EXT):
	$(MAKE) -C dpf/utils/lv2-ttl-generator

# ---------------------------------------------------------------------------------------------------------------------
# cleanup

clean:
	$(foreach p,$(PLUGINS),$(MAKE) clean -f max-gen/Makefile.common.mk NAME=${p};)
	$(MAKE) clean -C dpf/utils/lv2-ttl-generator
	rm -rf bin build

# ---------------------------------------------------------------------------------------------------------------------

.PHONY: plugins
