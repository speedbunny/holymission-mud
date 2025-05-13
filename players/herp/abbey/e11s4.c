#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="The Bull Pen";
     long_desc=
"You see a comfortable, hay-lined stall, made of wood. It has a\n" +
"strong odor of cattle.\n";
     dest_dir=({ PATH+"/e10s4","north",
		 PATH+"/e12s4","south",
		 PATH+"/e11s3","west" });
  }
  if (!(ob=present("bull")) || !living(ob)) {
	ob=clone_object("obj/monster");
	ob->set_name("bull");
	ob->set_alias("sylvius");
	ob->set_short("A bull named Sylvius");
	ob->set_long("The bull flicks his tail and bawls loudly at you.\n");
	ob->set_level(10);
	move_object(ob,this_object());
  }
}
