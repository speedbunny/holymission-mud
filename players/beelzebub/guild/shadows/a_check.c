int KILLER;

id(str) { return (str == "a_check"); }

query_value() { return 0; }

query_weight() { return 0; }

drop() {
  destruct(this_object());
  return 1;
}

get() { return 1; }

set_stab_it(int stren) { KILLER=stren; return 1; }

int query_stab_it() { return KILLER; }

