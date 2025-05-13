
/* orc watchman */

inherit "/obj/npc";
#include "../caves.h"

void reset(int arg) 
{
     ::reset(arg);
     if (!arg) 
     {
        set_name("orc watchman");
        set_alt_name("orc");
        set_short(query_name());
        set_race("orc");
        set_long("An orc watchman looking around for victims.\n");
        set_gender(1+random(2));
        set_aggressive(1);
        set_level(19);
        set_whimpy(20);
        load_a_chat(20,
        ({
           query_name()+" growls: Grrrrz shrzz\n",
           query_name()+" growls: Snrzlfrzzz jumm\n",
           query_name()+" growls: Ranzrkrkzzz\n",
        }));
        set_al(-400);
        add_money(150+random(50));
        set_attacks(2);
        set_attacks_change(20);
        move_object(clone_object("/players/whisky/obj/cure_potion"),
                    this_object());
        move_object(clone_object(OBJ+"dagger"),this_object());
        command("wield dagger");
      }
}

int chk_attack(object food)
{
    string race;

    race = apply(call,food,"query_race");

    if (interactive(food) && race!= "orc" && race!= "giant" && race!="troll")
        return 1;
    return 0;
}

