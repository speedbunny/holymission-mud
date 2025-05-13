#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;

  if (!arg) {
     set_light(1);
     short_desc="The Dispensary Intersection";
     long_desc=
"To your west is a small building.  You see two monks leaving the building\n"+
"carrying a dead body on a stretcher. They wear kerchiefs over their noses\n"+
"to dispell the odor. To the south you see a cemetery.\n";
     dest_dir=({ PATH+"/m02","north",
		 PATH+"/m04","west",
		 PATH+"/m05","south" });
  }
  if (!(ob=present("monk")) || !living(ob)) {
	ob=clone_object("obj/monster");
	ob->set_name("monk");
	ob->set_level(3);
	ob->set_short("A very sick monk");
	ob->set_long("The monk vomits in a bowl.\n");
	ob->load_chat(10,
	({ "The sick monk looks deathly ill.\n",
	   "The monk says: The devil has given me this sickness.\n" }) );
	move_object(ob,this_object());
  } 
}
