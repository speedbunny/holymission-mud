#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob,rb;
  if (!arg) {
     set_light(1);
     short_desc="An empty room";
     long_desc="You are in an empty storage room.  The dust is thick here.\n";
     dest_dir=({ PATH+"/s04","east" });
  }
  if (!(ob=present("rat")) || !living(ob)) {
	ob=clone_object("obj/monster");
	ob->set_name("rat");
	ob->set_level(3);
	ob->set_short("A rat");
	ob->set_long("Small and furry.\n");
	ob->load_chat(10,  ({ "The rat squeaks.\n" }) );
	ob->load_a_chat(10,({ "The rat bites you!\n" }) );
	rb=clone_object("obj/treasure");
	rb->set_id("ruby");
	rb->set_short("A small ruby");
	rb->set_value(100);
	move_object(rb,ob);
	move_object(ob,this_object());
  }
}
