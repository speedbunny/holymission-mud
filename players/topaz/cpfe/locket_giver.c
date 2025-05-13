inherit "/obj/treasure";
#include "/players/exos/defs.h"
reset(arg) {
   if(!arg) {
   set_weight(1);
   set_id("locket_giver");
}
}

init() {
   ::init();
   AA("_give","newlocket");
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
   ob=HERE("locket",who);
   if (!ob) {
      ME("ERROR: Player does not have a locket!\n");
      return 1;
   }
   DEST(ob);
   transfer(CLONE(XOBJ+"/locket"),who);
   ME("Ok.\n");
   return 1;
}
      
