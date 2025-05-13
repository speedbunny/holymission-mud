inherit "/obj/treasure";
#include "/players/exos/defs.h"

reset (arg) {
   ::reset(arg);
   if (arg) return;
   set_id("gem");
   set_short("The owl's gem");
   set_long("This is the gem given to you by the Owl.\n");
   set_value(0);
}   

init () {
   ::init();
}

drop() {
   DEST(TO);
   return 1;
}

