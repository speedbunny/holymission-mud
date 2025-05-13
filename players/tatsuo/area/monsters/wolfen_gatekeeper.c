inherit "obj/monster";

/* 1632 hps */

#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("wolfen gatekeeper");
	set_race("wolfen");
	set_alias("gatekeeper");
	set_level(30);
	set_al(200);
        set_gender(1);
	set_short("wolfen gatekeeper");
   set_long("A wolfen guard who stands by the gate.  His orders are only to\n"+
	    "open the gate when the lookout orders him to.  He stands at\n"+
	    "attention, awaiting orders.  If given any reason to suspect\n"+
	   "that enemies of the state are entering the encampment he would\n"+
	    "immediately call for reinforcements to defend the gate.\n");
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
set_spell_dam(50);
    }
}


