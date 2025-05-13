/* BELL00.C - Programmed by Colossus */
/* 230993: Ethereal Cashimor: Should be /obj/thing, and ungettable. */

#include "/obj/lw.h"
inherit "obj/thing";

void init(){
    add_action("ring", "pull");
    add_action("ring", "ring");
}

void reset(int arg){
    ::reset(arg);
    if(!arg) {
	set_name("bell");
	set_alias("boat bell");
	set_short("Bell attached to a post");
	set_long(lw("This is a small copper bell attached to a post. If the boat"
	    + " is not here, you can 'ring' the bell to call it back.\n"));
	set_can_get(0);
    }
}

int ring(string str){
    object temp, boat, there, bon;

    if(!str) return 0;
    temp=clone_object("obj/treasure");
    move_object(temp, "/players/colossus/mearth/shire/island1");
    there=environment(temp);
    destruct(temp);
    boat=present("boat", there);
    if(!boat){
	write("The boat is already here!\n");
	return 1;
    }
    temp=clone_object("/obj/treasure");
    move_object(temp, "/players/colossus/mearth/shire/boat");
    there=environment(temp);
    destruct(temp);
    bon=present("bonn", there);
    if(!bon) return 1;
    tell_room(environment(),
      this_player()->query_name()+" rings the bell.\n");
    tell_room(there,
      "You hear the ringing of a bell in the distance.\n");
    bon->set_dest_file("/players/colossus/mearth/shire/pier2");
    bon->set_boat(boat);
    bon->set_sail();
    return 1;
}
