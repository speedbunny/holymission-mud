#include "/players/sargon/define.h"
inherit PG+"inherit/armour";


    wear(arg) {
  if(!id(arg) || environment()!=this_player())    return 0;
      if(TP->query_real_guild() != 3 && !TP->query_npc()) {
       write("Ouch!! You realize that this armour is only for Fighters!!\n\n"+
             "You hear Ares, the God of War laughing at you!\n");
            TP->reduce_hit_point(100);
             return 1;
     }
            return ::wear(arg);
}
