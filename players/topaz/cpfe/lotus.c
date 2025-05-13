inherit "/obj/treasure";
#include "/players/exos/defs.h"

reset (arg) {
   ::reset(arg);
   if (arg) return;
   set_id("lotus");
   set_short("A lotus blossom");
   set_long("This is the lotus given to you by the Crane.\n");
   set_value(0);
}   

init () {
   ::init();
}

drop() {
   DEST(TO);
   return 1;
}

