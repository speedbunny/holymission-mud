void clean_up() { destruct(this_object() ); }
int query_prevent_shadow() { return 1; }
void create() { seteuid( getuid() ); }
