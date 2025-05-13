
/* orc kitchenboy */

inherit "/obj/npc";
#include "../caves.h"
#include "enemy.h"

void reset(int arg) 
{
     ::reset(arg);
     if (!arg) 
     {
        set_name("orc kitchenhelper");
        set_alt_name("orc");
        set_short(query_name());
        set_race("orc");
        set_long("A busy orc.\n");
        set_gender(1+random(2));
        set_aggressive(1);
        set_level(5);
        load_a_chat(20,
        ({
           query_name()+" growls: Grrrrz shrzz\n",
           query_name()+" growls: Snrzlfrzzz jumm\n",
           query_name()+" growls: Ranzrkrkzzz\n",
        }));
        set_al(-100);
        add_money(80+random(50));
        set_attacks(1);
        set_attacks_change(20);
        move_object(clone_object(OBJ+"dagger"),this_object());
        command("wield dagger");
      }
}

