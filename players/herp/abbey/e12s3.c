#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;

  if (!arg) {
     set_light(1);
     short_desc="Goslings Pen";
     long_desc=
"This is where the geese are kept.  The parents are away at the moment.\n" +
"But watch out if they return!\n";
     dest_dir=({ PATH+"/e11s3","north",
		 PATH+"/e12s2","west",
		 PATH+"/e12s4","east" });
  }
  if (!(ob=present("gosling")) || !living(ob)) {
     for(i=0;i<5;i++) {
	ob=clone_object("obj/monster");
	ob->set_name("gosling");
	ob->set_short("A gosling");
	ob->set_long("A downy soft, fuzzy gosling with red feet.\n");
	ob->set_level(1);
	ob->set_whimpy();
	ob->load_chat(10,
	({ "A gosling peers bright eyed at you.\n",
	   "Peep, peep!\n" }) );
	move_object(ob,this_object());
     }
  }
}
