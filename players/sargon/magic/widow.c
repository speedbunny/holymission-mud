#include "/players/sargon/define.h"
inherit "/players/sargon/magic/mw";
  object p;

reset(arg) {
  ::reset(arg);
  
    set_name("Widowmaker");
    set_alias("sword");
    set_alt_name("widowmaker");
   set_short("Widowmaker, The Sword of Force");
    set_long("Even in dim light this weapon radiates a polished look. The\n"+
             "sword gives off an aura of power, not only from the magic,\n"+
             "but from the metla itself. There is a fine mottled pattern\n"+
             "along the blade, but it seems to run deep into the metal,\n"+
             "though the surface is flawlessly smooth. On the black handle\n"+
	     "there is a simple symbol: .\n");
    set_class(20);
    set_value(10000);
    set_weight(5);
    set_type(1);
    set_hit_func(TO);

}

hit (attacker) 
{
  int time;
  
  time = ::hit(attacker);
  set_heart_beat(1);
  return time;
}
/*

wield (str) 
{
  int w;
 
  if (w = ::wield (str)) 
  {
    p = TP;
    tell_room(E(p),""+p->N+"'s sword begins to radiate with a strange glow.\n");
   } 
  return w;
}


*/
heart_beat() 
{
  object victim;
   p = TP;
   if ((victim = p->query_attack()) && E(p) == E(victim)) 
   {
     tell_room(E(p),""+p->N+"'s glowing sword blinds "+victim->N+" for a moment.\n");
     victim->hit_player(35+random(100));
     p->attack();
   }
   else 
   {  
     set_heart_beat(0);
   }
}

