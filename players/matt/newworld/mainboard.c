inherit "/obj/board";

#include "/players/matt/defs.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_file(LOGS + "mainboard");
  set_name("main board");
  set_short("The Board of the New World");
}
