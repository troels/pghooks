#include "postgres.h"

#include "pglogical_output/hooks.h"

#include "access/xact.h"

#include "catalog/pg_type.h"

PG_MODULE_MAGIC;

PGDLLEXPORT extern Datum pglo_nzhooks_setup_fn(PG_FUNCTION_ARGS);
PG_FUNCTION_INFO_V1(pglo_nzhooks_setup_fn);

bool
pglo_nzhooks_row_filter(struct PGLogicalRowFilterArgs *rowfilter_args);

bool
pglo_nzhooks_row_filter(struct PGLogicalRowFilterArgs *rowfilter_args)
{
  Relation rel = rowfilter_args->changed_rel;
  char *relName = RelationGetRelationName(rel);
  
  elog(WARNING, "Warning: relName: %s", relName);
  return !strcmp(relName, "nzmagic");
}

Datum
pglo_nzhooks_setup_fn(PG_FUNCTION_ARGS)
{
  struct PGLogicalHooks *hooks = (struct PGLogicalHooks*) PG_GETARG_POINTER(0);
  elog(WARNING, "HELLO THERE!");
  hooks->row_filter_hook = pglo_nzhooks_row_filter;
  PG_RETURN_VOID();
}
