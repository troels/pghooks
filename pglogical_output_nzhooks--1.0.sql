\echo Use "CREATE EXTENSION pglogical_output_nzhooks" to load this file. \quit

CREATE FUNCTION pglo_nzhooks_setup_fn(internal)
RETURNS void
STABLE
LANGUAGE c AS 'MODULE_PATHNAME';
