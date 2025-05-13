
/* orc shaman */

inherit "/obj/npc";
#include "../caves.h"

#include "enemy.h"
object shad;

void reset(int arg) 
{
     ::reset(arg);
     if (!arg) 
     {
        set_name("orc chiefshaman");
        set_alt_name("orc");
        set_short(query_name());
        set_race("orc");
        set_long("A wise looking orc.\n");
        set_gender(1+random(2));
        set_aggressive(1);
        set_level(30);
        load_a_chat(20,
        ({
           query_name()+" growls: Grrrrz shrzz\n",
           query_name()+" growls: Snrzlfrzzz jumm\n",
           query_name()+" growls: Ranzrkrkzzz\n",
        }));
        set_al(-4000);
        add_money(3000+random(50));
        set_attacks(2);
        set_attacks_change(60);
        move_object(clone_object("/players/whisky/obj/haste_potion"),
                    this_object());
        move_object(clone_object(OBJ+"mace"),this_object());
        command("wield mace");
        move_object(clone_object("/players/whisky/obj/ruby_bracelet"),
                    this_object());
        command("wear bracelet");
        move_object(clone_object(OBJ+"robe"),this_object());
        command("wear robe");
        set_spell_mess1("The Orc shaman casts a flamestrike !\n");
        set_spell_mess2("You are hit by a flamestrike !\n");
        set_chance(50);
        set_spell_dam(100+random(90));
        shad = clone_object("/obj/shadows/sanct_shad");
        shad->start_shadow(this_object(),0);
        shad = clone_object("/obj/shadows/fireshield_shad");
        shad->start_shadow(this_object(),0);
      }
}

int detect_invis()
{
    return 1;
}
