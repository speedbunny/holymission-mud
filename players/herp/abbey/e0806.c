#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;

  if (!arg) {
     set_light(1);
     short_desc="Duck Yard";
     long_desc=
"You step over a low style into the duckling pen.  The ducklings waddle\n"+
"to the far side, away from you.\n";
     dest_dir=({ PATH+"/e0805","west",
		 PATH+"/e09s3","south",
		 PATH+"/e0807","east" });
  }
  if (!(ob=present("duckling")) || !living(ob)) {
     for(i=0;i<3;i++) {
	ob=clone_object("obj/monster");
	ob->set_name("duckling");
	ob->set_short("A duckling");
	ob->set_level(1);
	ob->set_whimpy();
	ob->load_chat(10,
	({ "A duckling flaps it's little wings.\n",
	   "Peep, peep!\n" }) );
	move_object(ob,this_object());
     }
  }
}
