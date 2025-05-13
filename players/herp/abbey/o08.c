#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;
  if (!arg) {
     set_light(1);
     short_desc="Jumbled Rocks";
     long_desc=
"You scramble over jumbled boulders at the top of a steep cliff.\n";
     dest_dir=({ PATH+"/o07","west" });
  }
  if (!(ob=present("snake")) || !living(ob)) {
     for (i=0;i<3;i++) {
	ob=clone_object("obj/monster");
	ob->set_name("snake");
	ob->set_short("A snake");
	ob->set_level(4);
	ob->load_chat(10,
	({ "The snake hisses!\n",
	   "The snake strikes at your face!\n" }) ); 
	move_object(ob,this_object());
     }
  }
}
