
/* female orc */

inherit "/obj/npc";
#include "../caves.h"
#include "enemy.h"

void reset(int arg) 
{
     ::reset(arg);
     if (!arg) 
     { 
        set_name("female orc");
        set_alt_name("orc");
        set_short(query_name());
        set_race("orc");
        set_long("An orc female feeding her baby.\n");
        set_gender(2);
        set_aggressive(1);
        set_level(6);
        set_whimpy(20);
        load_a_chat(20,
        ({
           query_name()+" growls: Grrrrz shrzz\n",
           query_name()+" growls: Snrzlfrzzz jumm\n",
           query_name()+" growls: Ranzrkrkzzz\n",
        }));
        set_al(-100);
        add_money(200+random(50));
        set_attacks(1);
        set_attacks_change(80);
        move_object(clone_object(OBJ+"dagger"),this_object());
        command("wield dagger");
      }
}

