inherit "/obj/thing";

#include "/players/matt/defs.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("large seed");
  set_alias("seed");
  set_short("Large seed");
  set_long("A large, pure green seed that throbs with life.\n");
}

drop() {
  write("You drop the seed. It crumbles to pieces.\n");
  say(TP->SNAME + " drops seed. It crumbles.\n");
  destruct(TO);
  return 1;
}
