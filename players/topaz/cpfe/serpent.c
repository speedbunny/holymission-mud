inherit "/obj/treasure";
#include "/players/exos/defs.h"

reset (arg) {
   ::reset(arg);
   if (arg) return;
   set_id("serpent");
   set_short("A dead serpent");
   set_long("This is the serpent given to you by the Shan Sao.\n");
   set_value(0);
}   

init () {
   ::init();
}

drop() {
   DEST(TO);
   return 1;
}

