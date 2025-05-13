/* TRASHCAN.C - Programmed? by Whisky */
/* 230993: Ethereal Cashimor: Should be /obj/thing and ungettable */
/* 041096: Saffrin: spruced, edited and recoded a bit */

#include "/obj/lw.h"
inherit "obj/thing";
#include "/players/saffrin/defs.h"

reset(arg) {
    ::reset(arg);
    if(!arg) {

	set_name("wastebasket");

	set_alias("basket");

	set_short("A waste basket");

	set_long(lw("A small waste basket where you can put items that have "
	    + "no value in to help keep the store clean.  Just type <trash> "
	    + "<item> to dispose of the unwanted item.\n"));

	set_can_get(0);
    }
}

init() {
    add_action("trash","trash");
    ::init();
}

trash(arg) {
    object ob;
    int i;
    if(!arg) {
	write("Trash what ??\n");
	return 1;
    }
    if(!(ob=present(arg,this_player()))) {
	write("You don't have that object.\n");
	return 1;
    }
    if(transfer(ob, environment())) {
	write("You can't trash that!\n");
	return 1;
    }
    destruct(ob);
    write("Suddenly, a coin flips out from the trashcan "+
      "into your pocket.\n");
    this_player()->add_money(1); 
    return 1;
}


