
/* orc chef de la cuisine */

inherit "/obj/npc";
#include "../caves.h"
#include "enemy.h"

void reset(int arg) 
{
     ::reset(arg);
     if (!arg) 
     {
        set_name("orc chef de la cuisine");
        set_alt_name("orc");
        set_short(query_name());
        set_race("orc");
        set_long("A strong busy orc.\n");
        set_gender(1+random(2));
        set_aggressive(1);
        set_level(20);
        load_a_chat(20,
        ({
           query_name()+" growls: Grrrrz shrzz\n",
           query_name()+" growls: Snrzlfrzzz jumm\n",
           query_name()+" growls: Ranzrkrkzzz\n",
        }));
        set_al(-300);
        add_money(3000+random(50));
        set_attacks(2);
        set_attacks_change(60);
        move_object(clone_object(OBJ+"dagger"),this_object());
        command("wield dagger");
        move_object(clone_object(OBJ+"jacket"),this_object());
        command("wear jacket");
        move_object(clone_object(OBJ+"boots"),this_object());
        command("wear boots");
      }
}

int query_dex()
{
    return 40;
}

