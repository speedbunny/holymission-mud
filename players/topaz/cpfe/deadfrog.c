inherit "/obj/treasure";
#include "/players/exos/defs.h"

reset (arg) {
   ::reset(arg);
   if (arg) return;
   set_id("deadfrog");
   set_short("A dead frog");
   set_long("This is the frog given to you by the Monkey.\n");
   set_value(0);
}   

init () {
   ::init();
}

drop() {
   DEST(TO);
   return 1;
}

