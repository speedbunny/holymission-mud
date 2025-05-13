#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;

  if (!arg) {
     set_light(1);
     short_desc="Secret Passage";
     long_desc=
"You stand in an underground passage which extends further east.  To\n"+
"your west you see a stairwell going up.\n";
     dest_dir=({ PATH+"/g08","west",
		 PATH+"/g06","east" });
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
