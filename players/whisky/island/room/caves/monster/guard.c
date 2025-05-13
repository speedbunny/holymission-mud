
/* orc guard */

inherit "/obj/npc";
#include "../caves.h"
#include "enemy.h"

void reset(int arg) 
{
     ::reset(arg);
     if (!arg) 
     {
        set_name("orc guard");
        set_alt_name("orc");
        set_short(query_name());
        set_race("orc");
        set_long("An orc guard protecting the cave.\n");
        set_gender(1+random(2));
        set_aggressive(1);
        set_level(15);
        load_a_chat(20,
        ({
           query_name()+" growls: Grrrrz shrzz\n",
           query_name()+" growls: Snrzlfrzzz jumm\n",
           query_name()+" growls: Ranzrkrkzzz\n",
        }));
        set_al(-800);
        add_money(800+random(50));
        set_attacks(2);
        set_attacks_change(60);
        move_object(clone_object("/players/whisky/obj/crit_potion"),
                    this_object());
        move_object(clone_object(OBJ+"axe"),this_object());
        command("wield waraxe");
        move_object(clone_object(OBJ+"jacket"),this_object());
        command("wear jacket");
        move_object(clone_object("/obj/torch"),this_object());
      }
}

