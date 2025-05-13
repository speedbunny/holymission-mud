inherit "obj/weapon";
#include "/players/shadowmonk/include/defs.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return 0;
    set_name
        ("lil knife");
    set_alias
        ("knife");
    set_short
        ("Lil Knife");
    set_long
        ("A very little knife. Seemingly it is nothing more then a bread-knife.\n");
    set_class(20);
    set_value(2000);
    set_weight(1);
    set_hit_func(TO);
}

int weapon_hit(object attacker)
{
   if( TP->HP < ((TP->MAXHP/3)*2) )
       TP->heal_self( (TP->MAXHP) - (TP->HP) );
   if( TP->SP < TP->MAXSP )
       TP->ADDSP( (TP->MAXSP) - (TP->SP) );
   return 1;
}
