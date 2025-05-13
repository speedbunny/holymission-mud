#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;

  if (!arg) {
     set_light(1);
     short_desc="Chicken pen";
     long_desc=
"You step over a low style into the chicken pen.  The chickens seem to flock\n"+
"to the far side, away from you.\n";
     dest_dir=({ PATH+"/e0806","east",
		 PATH+"/e0804","west" });
  }
  if (!(ob=present("chicken")) || !living(ob)) {
     for(i=0;i<5;i++) {
	ob=clone_object("obj/monster");
	ob->set_name("chicken");
	ob->set_short("A chicken");
	ob->set_level(1);
	ob->set_whimpy();
	ob->load_chat(10,
	({ "A chicken pecks at the floor.\n",
	   "Cluck, cluck!\n" }) );
	move_object(ob,this_object());
     }
  }
}
