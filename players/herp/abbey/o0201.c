#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;

  if (!arg) {
     set_light(1);
     short_desc="Hilltop";
     long_desc=
"You find a group of starving peasants, fighting over garbage.\n";
     dest_dir=({ PATH+"/o02","south" });
  }

  if (!(ob=present("peasant")) || !living(ob)) {
     for (i=0;i<5;i++) {
	ob=clone_object("obj/monster");
	ob->set_name("peasant");
	ob->set_short("A peasant");
	ob->set_long("A silently suffering peasant.\n");
	ob->set_level(4);
	ob->load_chat(60,
	({ "The peasant says: Have mercy on us.\n",
	   "The peasant says: I'm hungry!\n",
	   "The peasant brandishes a rock.\n",
	   "The peasant says: Give me some food.\n" }) );
	move_object(ob,this_object());
     }
  }
}
