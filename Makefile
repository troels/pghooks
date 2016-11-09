MODULES = pglogical_output_nzhooks
EXTENSION = pglogical_output_nzhooks
DATA = pglogical_output_nzhooks--1.0.sql

PGLOGICAL_OUTPUT_DIR=../pglogical/pglogical_output
ifdef USE_PGXS
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
PG_CPPFLAGS = -I$(PGLOGICAL_OUTPUT_DIR)
include $(PGXS)
else
subdir = contrib/pglogical_output/examples/hooks
top_builddir = ../../../..
include $(top_builddir)/src/Makefile.global
include $(top_srcdir)/contrib/contrib-global.mk

# Allow the hook plugin to see the pglogical_output headers
# Necessary because !PGXS builds don't respect PG_CPPFLAGS
override CPPFLAGS := $(CPPFLAGS) -I../..
endif
