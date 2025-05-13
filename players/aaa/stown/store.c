
/* Completed 12.02.1995 */

#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";

void reset(int arg) {
    object ob;
    ::reset(arg);
    if (!present("torch")) {
        ob=clone_object("/obj/torch");
        move_object(ob,this_object());
    } 
    if (!present("match")) {
        ob=clone_object("/players/cashimor/objects/match.c");
        move_object(ob,this_object());
    }
    if (!present("rod")) {
        ob=clone_object(PA+"stown/rod.c");
        move_object(ob,this_object());
    }
    if (!present("sword")) {
        ob=clone_object("/obj/weapon.c");
        ob->set_name("sword");
        ob->set_short("a sword");
        ob->set_long("This sword is worn a bit, that's why it's so cheap.\n");
        ob->set_class(10);
        ob->set_value(200);
        ob->set_weight(1);
        move_object(ob,this_object());
    }
    if (!present("chainmail")) {
        ob=clone_object("/obj/armour.c");
        ob->set_name("chainmail");
        ob->set_short("a chainmail");
        ob->set_long("Looks to be practical in battle.\n");
        ob->set_type("armour");
        ob->set_ac(2);
        ob->set_weight(4);
        ob->set_value(1000);
        move_object(ob,this_object());
    }
    if(arg) return;
    set_light(1);
    short_desc="Storeroom of Greedy's shop";
    long_desc="Storeroom of Greedy's shop";
/* Players normally don't see this room */
    dest_dir=({});
    items=({ });   
}

void init() {
    ::init();
}

