int BACKER;

id(str) { return (str == "back_check"); }

query_value() { return 0; }

query_weight() { return 0; }

drop() {
  destruct(this_object());
  return 1;
}

get() { return 1; }

set_stab_it(int stren) { BACKER=stren; return 1; }

int query_stab_it() { return BACKER; }

