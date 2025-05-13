#include "/players/sargon/define.h"
inherit "/obj/std_shadow";
#define MASTER "race/master"
#define DEX me->query_dex()
#define STR me->query_str()/4

varargs mixed hit_player(int ouch, int kind, mixed elem) {
  string name, attacker;
  int dex,dk,enc,what,max,wt;

  dex = (DEX + me->query_level() + STR)-(TP->query_dex()+(TP->query_level()/2));
  wt = me->query_weight(); 
  enc = wt * 40 / me->query_str();
  name = me->N;
  attacker = TPN;

  if (!kind || kind == 0 || kind==1 || kind == 2 || kind == 6 || kind == 7)
    dk = 0;
  if (dk || dex < 1 || enc > 100) {
// 280198: Sauron: Added elem var to funcall.
    return me->hit_player(ouch, kind, elem);
 }
  if (! (max = MASTER->query_max_stat(me->query_race(), 1)) )
    max = 30;

  what = dex * (100 - dex)/ max;
    if (random(100) < what) {               
    write(name + " blocks your attack.\n");
   say(name+" skillfully parries the blow of "+attacker+".\n",me);
    tell_object(me, "You parry " + attacker + "'s blow.\n");
// 280198: Sauron: Changed from simply returning 0 so that important code
//                 is processed in hit_player() in player.c
    return me->hit_player(0, kind, elem);
  }

  what = random(100 - what) / 2 + 30; 
  ouch = ouch * what / 100;
  what = me->hit_player(ouch, kind, elem);
  write(me->N +" tried to parry the blow.\n");
  if (what)  
    say(me->N +" tried to parry "+ attacker +" 's attack.\n",me);
  tell_object(me, "You tried parry the attack of "+ attacker +".\n");
  return what;
}

  int parry_shad() {
    return 1;
}

