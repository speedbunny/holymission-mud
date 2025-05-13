#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;

  if (!arg) {
     set_light(1);
     short_desc="The Boar Pen";
     long_desc=
"The stench of raw manure is overwhelming here, causing your eyes to water.\n"+
"You hear the sounds of farm animals all around you.\n";
     dest_dir=({ PATH+"/e09s4","south",
		 PATH+"/e0806","west" });
  }
  if (!(ob=present("boar")) || !living(ob)) {
	ob=clone_object("obj/monster");
	ob->set_name("boar");
	ob->set_short("A vicious boar");
	ob->set_long("The boar roots in the dirt, and snorts at you.\n");
	ob->set_level(4);
	move_object(ob,this_object());
  }
}
