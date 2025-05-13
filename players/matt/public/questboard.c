inherit "/obj/board";

#include "/players/matt/defs.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_file(PATH + "public/questboard");
  set_name("questboard");
  set_short("The Quest Board");
}
