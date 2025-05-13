#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;
  if (!arg) {
     set_light(1);
     short_desc="Camp";
     long_desc=
"You come across a group of peasants, suffering from cold and\n" +
"starvation, trying to set up a campsite for the night.\n";
     dest_dir=({ PATH+"/o07","south" });
  }
  if (!(ob=present("peasant")) || !living(ob)) {
     for (i=0;i<3;i++) {
	ob=clone_object("obj/monster");
	ob->set_level(4);
	ob->set_name("peasant");
	ob->set_short("A peasant");
	ob->set_long("A silently suffering peasant.\n");
	ob->set_level(4);
	ob->load_a_chat(60,
	({ "The peasant says: Please don't kill me!\n",
	   "The peasant says: Where is your mercy?\n" }) );
	move_object(ob,this_object());
     }
  }
}
