
/* troll guard */

inherit "/obj/npc";
#include "../caves.h"
#include "enemy.h"

void reset(int arg) 
{
     ::reset(arg);
     if (!arg) 
     {
        set_name("cave troll guard");
        set_alt_name("troll");
        set_short(query_name());
        set_race("troll");
        set_long("A strong brown creature, with glowing red eyes.\n"+
                 "It's height is so 30 feet and it's whole body\n"+
                 "consists of skin, muscles and single dark hairs\n");
        set_gender(1+random(2));
        set_aggressive(1);
        set_level(30);
        load_a_chat(20,
        ({
           query_name()+" thunders: Grrrrz shrzz\n",
           query_name()+" thunders: Snrzlfrzzz jumm\n",
           query_name()+" thunders: Ranzrkrkzzz\n",
        }));
        set_al(-1200);
        add_money(500+random(50));
        set_attacks(1);
        set_attacks_change(30);
        move_object(clone_object("/players/whisky/obj/crit_potion"),
                    this_object());
        move_object(clone_object(OBJ+"club"),this_object());
        command("wield club");
      }
}

int query_str()
{
    return 50;
}

int query_dex()
{
    return 10;
}

int enhanced_dam()
{
    return 20;
}


