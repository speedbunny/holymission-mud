inherit "obj/monster";

/* 1632 hps */

#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("wolfen scribe");
	set_race("wolfen");
	set_alias("scribe");
	set_level(15);
	set_al(200);
        set_gender(1);
	set_short("wolfen scribe");
    set_long("A wolfen scribe who looks small compared to the guards.\n"+
             "He glances at you for a moment, then goes back to his\n"+
	     "paperwork.\n");
	add_money(100);
	set_ac(12);
	set_wc(20);
	set_aggressive(0);
	set_chance(25);
set_spell_mess1("The scribe growls as he hits his opponent with stunning force.");
set_spell_mess2("You hear the scribe growl as he hits you with a stunning blow.");
set_spell_dam(40);
    }
}


