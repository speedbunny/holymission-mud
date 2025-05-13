#include "/players/saffrin/guild/defs.h"
#include "/sys/levels.h"

int main(string str) {

  object *victims;
  int i, dam, cost;

  victims = ALL(ENV(TP));
  i = sizeof(victims) - 1;

  dam = TP->LEVEL/4 + TP->WIS/3 + TP->INT/4;
  cost = dam * 3;

  if(TP->SP < cost) {
    write("You are too weak to cast that spell!.\n");
    return 1;
  }
  say(TP->NAME + " chants words that are intangible..\n");
  while(i >= 0) {
    if(living(victims[i])
           && victims[i]!=TP
           && !TP->query_immortal()
           && member_array(victims[i],str)==-1) {
      victims[i]->hit_player(1);
      victims[i]->hit_player((dam,5,({2,12})));
    }
    i--;
  }

  return 1;
}

