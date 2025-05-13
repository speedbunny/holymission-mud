
/* orc hunter */

inherit "/obj/npc";
#include "../caves.h"
#include "enemy.h"

void reset(int arg) 
{
     ::reset(arg);
     if (!arg) 
     {
        set_name("orc hunter");
        set_alt_name("orc");
        set_short(query_name());
        set_race("orc");
        set_long("A hungry orc hunting animals.\n");
        set_gender(1+random(2));
        set_aggressive(1);
        set_level(11);
        set_whimpy(10);
        load_a_chat(20,
        ({
           query_name()+" growls: Grrrrz shrzz\n",
           query_name()+" growls: Snrzlfrzzz jumm\n",
           query_name()+" growls: Ranzrkrkzzz\n",
        }));
        set_al(-400);
        add_money(300+random(50));
        set_attacks(2);
        set_attacks_change(30);
        move_object(clone_object(OBJ+"axe"),this_object());
        command("wield axe");
      }
}

