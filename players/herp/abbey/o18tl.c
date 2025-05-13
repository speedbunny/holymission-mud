#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="The Burning Monk";
     long_desc=
"You stand before a mound of earth, on top of which is a large bundle of\n"+
"burning sticks.  Atop the burning heap is a fat monk, tied to a stake.\n"+
"The reeking smoke blows wildly around the stake, mercifully obscuring\n"+
"his face.  His tortured screams echo around you.\n";

     dest_dir=({ PATH+"/o18t1","northeast" });
  }
  if (!(ob=present("monk")) || !living(ob)) {
	ob=clone_object("obj/monster");
	ob->set_name("monk");
	ob->set_short("A fat monk, whose clothes are on fire");
	ob->set_long("The monk burns merrily with a crackling sound.\n");
	ob->set_level(5);
	ob->load_a_chat(10,
	({ "The monk waves a burning arm at you.\n",
	   "The monk drips burning fat at you.\n" }) );
	move_object(ob,this_object());
  }
}
