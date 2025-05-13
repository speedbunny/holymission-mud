#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="The Latrine";
     long_desc=
"The stench of raw sewage is overwhelming here, causing your eyes to water.\n"+
"You can barely breathe.  You see a long stone bench with many holes along\n"+
"the east wall.\n";
     dest_dir=({ PATH+"/c03","south",
		 PATH+"/c01","north" });
  }
  if (!(ob=present("rat")) || !living(ob)) {
	ob=clone_object("obj/monster");
	ob->set_name("rat");
	ob->set_short("A huge rat");
	ob->set_long("The rat sits up and glares at you.\n");
	ob->set_level(7);
	move_object(ob,this_object());
  }
}
