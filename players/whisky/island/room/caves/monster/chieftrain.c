
/* orc chieftrain */

inherit "/obj/npc";
#include "../caves.h"
#include "enemy.h"

void reset(int arg) 
{
     ::reset(arg);
     if (!arg) 
     {
        set_name("orc chieftrain");
        set_alt_name("orc");
        set_short(query_name());
        set_race("orc");
        set_long("A strong looking orc warrior.\n");
        set_gender(1+random(2));
        set_aggressive(1);
        set_level(35);
        load_a_chat(20,
        ({
           query_name()+" growls: Grrrrz shrzz\n",
           query_name()+" growls: Snrzlfrzzz jumm\n",
           query_name()+" growls: Ranzrkrkzzz\n",
        }));
        set_al(-800);
        add_money(2000+random(50));
        set_attacks(3);
        set_attacks_change(80);
        move_object(clone_object(OBJ+"morningstar"),this_object());
        command("wield morningstar");
        move_object(clone_object(OBJ+"jacket"),this_object());
        command("wear jacket");
        move_object(clone_object(OBJ+"helmet"),this_object());
        command("wear helmet");
        move_object(clone_object(OBJ+"boots"),this_object());
        command("wear boots");
        move_object(clone_object("/obj/torch"),this_object());
      }
}

