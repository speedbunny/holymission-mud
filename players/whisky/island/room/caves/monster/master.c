
/* master */

inherit "/obj/npc";
#include "../caves.h"
#include "enemy.h"

void reset(int arg) 
{
     ::reset(arg);
     if (!arg) 
     {
        set_name("elder orc");
        set_alt_name("orc");
        set_short(query_name());
        set_race("orc");
        set_long("A strong, wise looking.\n");
        set_gender(1+random(2));
        set_aggressive(1);
        set_level(50);
        load_a_chat(20,
        ({
           query_name()+" growls: Grrrrz shrzz\n",
           query_name()+" growls: Snrzlfrzzz jumm\n",
           query_name()+" growls: Ranzrkrkzzz\n",
        }));
        set_al(-4000);
        add_money(8000+random(50));
        set_attacks(3);
        CO("ring");
        set_attacks_change(80);
        move_object(clone_object("/players/whisky/obj/hearo_potion"),
                    this_object());
        move_object(clone_object("/players/whisky/obj/sanct_potion"),
                    this_object());
        move_object(clone_object(OBJ+"morningstar2"),this_object());
        command("wield morningstar");
        move_object(clone_object(OBJ+"boots"),this_object());
      }
}

