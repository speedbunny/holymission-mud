#include "ansi.h"
inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  set_name(RED+"red monster"+NORMAL);
  set_alias("monster");
  set_alt_name("red monster");
  set_short("A "+RED+" red looking "+NORMAL+"monster");
  set_long("This monster looks awfully "+RED+"red "+NORMAL+".\n");
  set_level(3);
  set_hp(300);
  set_ep(0);
}

