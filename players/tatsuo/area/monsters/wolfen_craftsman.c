inherit "obj/monster";

/* 1632 hps */

#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("wolfen guard");
	set_race("wolfen");
	set_alias("guard");
	set_level(30);
	set_al(200);
        set_gender(1);
	set_short("wolfen guard");
    set_long("A wolfen craftsman.  He is covered all over with soot from\n"+
             "the fires.  He is concentrating on crafting silver ingots.\n");
	add_money(250);
	move_object(clone_object(WPATH+"poker.c"), this_object());
	command("wield poker");
	set_ac(12);
	set_wc(25);
	set_aggressive(0);
	set_chance(25);
set_spell_mess1("The craftsman.");
set_spell_mess2("You hear the guard growl as he hits you with a stunning blow.");
set_spell_dam(50);
    }
}


