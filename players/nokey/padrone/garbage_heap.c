/* 031393 changed to room/room by Llort */
/* 030794 Nokey: making it strict types. */
#pragma strict_types
#pragma save_types


inherit "room/room";

#include "/players/padrone/config.h"

void reset(int arg) {
    if(!arg) {
        set_light(1);
	short_desc="Garbage heap";
	long_desc=
  "You are standing in an example of what unchecked pollution\n" +
  "can do to the environment - the garbage heap behind Padrone's Castle!\n" +
  "All sorts of useless junk has been dumped here, and the smell is\n" +
  "horrible. This is NOT a nice place, and you only want to get outta here!\n";
        dest_dir=({ 
            "players/padrone/vdb1", "west",
                 });
    }

    if (!present("garbage", this_object())) {
	object p1;

	p1 = clone_object("obj/treasure");
	p1->set_id("piece of garbage");
	p1->set_alias("garbage");
	p1->set_short("A piece of garbage");
	p1->set_long("This is a worthless piece of garbage.\n");
	p1->set_weight(1);
	p1->set_value(0);
	move_object(p1, this_object());
    }
    if (!present("junk", this_object())) {
	object p2;

	p2 = clone_object("obj/treasure");
	p2->set_id("piece of junk");
	p2->set_alias("junk");
	p2->set_short("A piece of junk");
	p2->set_long("This is a worthless piece of junk.\n");
	p2->set_weight(1);
	p2->set_value(0);
	move_object(p2, this_object());
    }
}
