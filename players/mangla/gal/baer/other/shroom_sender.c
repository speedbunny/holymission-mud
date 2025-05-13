inherit "/obj/treasure";
#include "/players/exos/defs.h"
reset(arg) {
   if(!arg) {
   set_weight(1);
   set_id("shroom_sender");
}
}

init() {
   ::init();
   AA("_give","shroomto");
}

_give(arg) {
   object who, ob;

   if (!arg) {
      ME("ERROR:  No argument\n");
      return 1;
   }
   who=find_player(arg);
   if (!who) {
      ME("ERROR: No such player.\n");
      return 1;
   }
   transfer(CLONE("/players/baer/shroom.c"),who);
   ME("Ok.\n");
   return 1;
}
      
