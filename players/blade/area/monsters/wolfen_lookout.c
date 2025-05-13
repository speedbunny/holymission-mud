inherit "obj/monster";

#include "/players/blade/area/blade_defs.h"

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("wolfen lookout");
	set_race("wolfen");
	set_alias("lookout");
	set_level(20);
	set_al(200);
        set_gender(1);
	set_short("wolfen lookout");
    set_long("A wolfen lookout who is about 6'5ft in height.  He looks\n"+
	     "less fit than his archer counterparts, because of his cushy\n"+
	     "job.  He is covered in grey fur.\n");
	add_money(250);
	move_object(clone_object(WPATH+"wolfen_sword.c"), this_object());
	command("wield sword");
	move_object(clone_object(APATH+"wolfen_chainmail.c"), this_object());
	command("wear chainmail");
	set_ac(12);
	set_wc(25);
	set_aggressive(0);
	set_chance(25);
set_spell_mess1("The guard growls as he hits his opponent with stunning force.");
set_spell_mess2("You hear the guard growl as he hits you with a stunning blow.");
set_spell_dam(20);
    }
}


