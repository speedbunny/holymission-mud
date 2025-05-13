inherit "obj/monster";

#include "/players/blade/area/blade_defs.h"

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("wolfen cook");
	set_race("wolfen");
	set_alias("cook");
	set_level(15);
	set_al(200);
        set_gender(1);
	set_short("wolfen cook");
    set_long("A fat wolfen cook.  He wears a stained apron that barely\n"+
             "reaches around his waist, and his matted fur is covered\n"+
	     "in grease.\n");
	add_money(250);
	move_object(clone_object(WPATH+"wolfen_pan.c"), this_object());
	command("wield pan");
	move_object(clone_object(APATH+"wolfen_apron.c"), this_object());
	command("wear apron");
	set_ac(12);
	set_wc(25);
	set_aggressive(0);
	set_chance(25);
set_spell_mess1("You see the cook throw hot grease in his opponent's face.");
set_spell_mess2("The cook throws hot grease in your face!");
set_spell_dam(20);
    }
}


