
/* orc peasant */

inherit "/obj/npc";
#include "../caves.h"
#include "enemy.h"

void reset(int arg) 
{
     ::reset(arg);
     if (!arg) 
     { 
        set_name("orc peasant");
        set_alt_name("orc");
        set_short(query_name());
        set_race("orc");
        set_long("An harmless looking orc.\n");
        set_gender(1+random(2));
        set_aggressive(1);
        set_level(3);
        set_whimpy(20);
        load_a_chat(20,
        ({
           query_name()+" growls: Grrrrz shrzz\n",
           query_name()+" growls: Snrzlfrzzz jumm\n",
           query_name()+" growls: Ranzrkrkzzz\n",
        }));
        set_al(-100);
        add_money(150+random(50));
        set_attacks(1);
        set_attacks_change(20);
        move_object(clone_object(OBJ+"dagger"),this_object());
        command("wield dagger");
      }
}

