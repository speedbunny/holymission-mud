#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;
  if (!arg) {
     set_light(1);
     short_desc="Clifftop Clearing";
     long_desc=
"You have entered a clearing at the top of a cliff further east.  You see\n"+
"the torn and partially devoured remains of a young peasant girl.\n";
     dest_dir=({ PATH+"/o02","east" });
  }
  if (!(ob=present("dog")) || !living(ob)) {
     for (i=0;i<4;i++) {
	ob=clone_object("obj/monster");
	ob->set_name("dog");
	ob->set_short("A wild, starving dog");
	ob->set_level(7);
	ob->load_chat(0,
	({ "The snake hisses!\n",
	   "The snake strikes at your face!\n" }) ); 
	ob->set_aggressive(1);
	move_object(ob,this_object());
     }
  }
}
