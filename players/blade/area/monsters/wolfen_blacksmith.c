inherit "obj/monster";

#include "/players/blade/area/blade_defs.h"

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("wolfen blacksmith");
	set_race("wolfen");
	set_alias("blacksmith");
	set_level(23);
	set_al(0);
        set_gender(1);
	set_short("wolfen blacksmith");
    set_long("A tired looking wolfen blacksmith who is about 6ft in height.\n"+
             "He is very muscular, and covered all over in grey fur.  He is\n"+
	     "slightly hunched over.\n");
	add_money(250);
/* 6-12-97 Kryll - commented out because no hammer file
	move_object(clone_object(WPATH+"hammer.c"), this_object());
	command("wield hammer");
*/
	set_ac(5);
	set_wc(25);
	set_aggressive(0);
	set_chance(25);
set_spell_mess1("The blacksmith grins as he hits you with a glowing coal.");
set_spell_mess2("You see the blacksmith grin as he throws a coal at his attacker.");
set_spell_dam(15);
    }
}


