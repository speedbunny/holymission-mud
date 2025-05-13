#include "/obj/door.h"
inherit "/obj/monster";
#define TO this_object()

reset(arg){
    object key, mail, hammer;
    ::reset(arg);
    if(!arg) {
	set_name("skeleton");
	set_alias("warrior");
	set_short("Skeleton Warrior");
	set_long("The Skeleton Warrior is a notorious killer.\n");
	set_race("skeleton");
	set_level(12);
	set_aggressive(1);
	set_no_steal(1);
	/*
	    MAKE_KEY(key, "skeleton","ob1");
	    move_object(key, "this_object");

	    hammer=transfer(clone_object("/players/emerald/lakmir/hammer"),TO);
	    init_command("wield hammer");

	    mail=transfer(clone_object("/players/emerald/lakmir/mail"),TO);
	    init_command("wear mail");
	*/
    }
}
