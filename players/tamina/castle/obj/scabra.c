#include "/players/tamina/defs.h"

inherit "/obj/weapon";
  object p;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return 0;
  
    set_name("sword");
    set_alias("scabra");
    set_short("Scabra, the Sword");
    set_long(
"This is the wondrous blade of the powerful knight, Sir Mordred.\n"+
"It was crafted for him by the finest smiths of Arthur's realm.\n"+
"By its wonderfully light weight, and strange glowing metal, you\n"+
"definitely think that there is a great deal of Magic imbued in this\n"+
"Sword.\n");
    set_class(16);
    set_value(4500);
    set_weight(3);
    set_type(3);
    set_hit_func(TO);

}

wield (str) 
{
  int w;
 
  if (w = ::wield (str)) 
  {
    p = TP;
    TRM(E(p),""+p->NAME+"'s sword begins to radiate with a strange glow.\n");
  } 
  return w;
}

int weapon_hit(object victim) 
{
  if ((victim = p->query_attack()) && E(p) == E(victim)) 
  {
    TRM(E(p),""+p->NAME+"'s glowing sword flashes at "+victim->NAME+" !\n");
    return 7;
  }
}

