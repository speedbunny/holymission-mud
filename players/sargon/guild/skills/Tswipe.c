#include "/include/defs.h"

int swipe(string arg) {

  int    swipe, enemys, dam, i;
  object *ob,   sword,  *gr;
    
  if(!(sword=TP->query_weapon()[TP->query_wep_types("sword")])) {
    write("You a sword to swipe!\n");
    return 1;
  }

  if(TP->query_ghost()) {
    write("You feel that something is terribly wrong!\n");
    return 0;
  }
  enemys = 0;
  ob = all_inventory(ENV(TP));
  gr = TP->grmems_in_room();
  if((ob[i]->query_npc() || ob[i]->query_player())
         && ob[i]->query_guild() != 3
         && ob[i]!=TP
         && member_array(ob[i], gr) == -1) {
    enemys++;
  }

  if(!enemys)
    dam=0;
  else
    dam=3/enemys/2+random(7);

    
  if((ob[i]->query_npc() || ob[i]->query_player())
       && ob[i]->query_guild()!=3 && ob[i]!=TP && member_array(ob[i],gr)==-1) {
    if((ENV(ob[i]))->query_property("no_fight")) {
      write("You are not allowed to fight here!\n");
      return 1;
    }
  }
  return 0;
}
