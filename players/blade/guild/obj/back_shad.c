inherit "/players/obj/std_shadow";

int LEV;

void end_shadow() {
    destruct(this_object());
}

int back_shad() {
    return 1;
}

object back_object() {
    return this_object();
}

void set_lev(int notice) {
  LEV=notice;
}

int query_no_stab_it(int notice) {
  if (notice <= LEV)
    return 1;
  else
    return 0;
}
