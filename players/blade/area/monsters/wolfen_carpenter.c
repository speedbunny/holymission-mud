inherit "obj/monster";

#include "/players/blade/area/blade_defs.h"

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("wolfen carpenter");
	set_race("wolfen");
	set_alias("carpenter");
	set_level(random(3)+20);
	set_al(0);
        set_gender(1);
	set_short("wolfen carpenter");
    set_long("A strong looking wolfen carpenter.  He is currently working\n"+
	     "on constructing something.\n");
	add_money(250);
	move_object(clone_object(WPATH+"lumber"), this_object());
	command("wield wood");
	set_ac(10);
	set_wc(25);
	set_aggressive(0);
	set_chance(25);
set_spell_mess1("The carpenter hits your head with a piece of lumber!");
set_spell_mess2("The carpenter hits your head with a piece of lumber!.");
set_spell_dam(random(20));
    }
}


