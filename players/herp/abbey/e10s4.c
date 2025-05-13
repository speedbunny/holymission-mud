#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="The walkway";
     long_desc=
"You are walking between the various pens.\n";
     dest_dir=({ PATH+"/e09s4","north",
		 PATH+"/e11s4","south",
		 PATH+"/e10s3","west" });
  }
  if (!(ob=present("rooster")) || !living(ob)) {
	ob=clone_object("obj/monster");
	ob->set_name("rooster");
	ob->set_short("A large, pesky rooster");
	ob->set_long("The rooster struts around proudly and crows.\n");
	ob->set_level(5);
	move_object(ob,this_object());
  }
}
