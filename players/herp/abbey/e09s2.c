#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;

  if (!arg) {
     set_light(1);
     short_desc="Pig Stye";
     long_desc=
"You step over a low gate into the pig pen.  The piglets have made\n"+
"a reeking, muddy mess of the pen.\n";
     dest_dir=({ PATH+"/e09s1","west",
		 PATH+"/e09s3","east" });
  }
  if (!(ob=present("piglet")) || !living(ob)) {
     for(i=0;i<5;i++) {
	ob=clone_object("obj/monster");
	ob->set_name("piglet");
	ob->set_short("A piglet");
	ob->load_chat(10,
	({ "The piglet squeals.\n",
	   "The piglet snuffles in the dirt.\n" }) );
	move_object(ob,this_object());
     }
  }
}
