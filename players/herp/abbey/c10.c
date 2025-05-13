#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;
  if (!arg) {
     set_light(1);
     short_desc="Bath";
     long_desc=
"You have entered a bath chamber.  A large empty wooden tub nearly fills\n"+
"this room.\n";
     dest_dir=({ PATH+"/c09","south" });
  }
  if (!(ob=present("rat")) || !living(ob))
     for(i=0;i<2;i++) {
	ob=clone_object("obj/monster");
	ob->set_name("rat");
	ob->set_short("A rat");
	ob->set_level(3);
	move_object(ob,this_object());
     }
}
