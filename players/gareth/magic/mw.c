// 061197: Sauron: Added check to make sure that the wielder is carrying the
//                 item.

inherit "/obj/weapon";
#include "/players/gareth/define.h"


    wield(arg) {
      if(environment(this_object()) != this_player())
            return ::wield(arg);
      if(TP->query_real_guild() != 3 && !TP->query_npc()) {
       write("Ouch!! You feel searing heat and intense pain as you try to \n"+
             "wield this marvelous weapon\n\n"+
             "Vulcan tells you: this weapon was created for Noble Fighters!\n");
             TP->reduce_hit_point(300);
             return 1;
     }
    else {
    say("An Olympian sword glows with a magical aura as "+TPN+" wields it!\n");
   }
            return ::wield(arg);
}
