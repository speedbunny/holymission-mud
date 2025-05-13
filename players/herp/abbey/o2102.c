#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;
  if (!arg) {
     set_light(1);
     short_desc="Cliff Overlook";
     long_desc=
"You stand on the brink of a rocky hilltop, southwest of the abbey.\n"+
"You find a group of freezing peasants, huddled over a small fire.\n";
     dest_dir=({ PATH+"/o21","east" });
  }
  if (!(ob=present("peasant")) || !living(ob)) {
     for(i=0;i<4;i++) {
	ob=clone_object("obj/monster");
	ob->set_level(3);
	ob->set_name("peasant");
	ob->set_short("A peasant");
	ob->set_long("A filthy, freezing peasant.\n");
	ob->load_chat(10,
	({ "The peasant says: Can you spare a coin?\n",
	   "The peasant says: Please help us.\n",
	   "The peasant adds a small stick to the fire.\n",
	   "The peasant shivers and holds his hands out to the fire.\n" }) );
	move_object(ob,this_object());
     }
  }
	
}
