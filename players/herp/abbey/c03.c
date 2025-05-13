#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;

  if (!arg) {
     set_light(1);
     short_desc="Bath Hallway";
     long_desc=
"You are in an empty hallway.  The stench of sew is overpowering.\n";
     dest_dir=({ PATH+"/c02","north",
		 PATH+"/c04","south" });
  }
  if (!(ob=present("rat")) || !living(ob))
     for(i=0;i<4;i++) {
	ob=clone_object("obj/monster");
	ob->set_name("rat");
	ob->set_short("A rat");
	ob->set_level(3);
	move_object(ob,this_object());
     }
}
