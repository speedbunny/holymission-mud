#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;

  if (!arg) {
     set_light(1);
     short_desc="Sea Of Rats";
     long_desc=
"You stand in an underground passage that extends east and west.\n";
     dest_dir=({ PATH+"/g07","west",
		 PATH+"/g05","east" });
  }

  if (!(ob=present("rat")) || !living(ob))
     for (i=0;i<4;i++) {
	ob=clone_object("obj/monster");
	ob->set_name("rat");
	ob->set_level(5);
	ob->set_short("A rat");
	ob->set_aggressive(1);
	move_object(ob,this_object());
     }
}
