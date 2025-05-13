#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;
  if (!arg) {
     set_light(1);
     short_desc="Lamb Pen";
     long_desc=
"You step over a low style into the lamb pen.  The lambs crowd\n" +
"around you looking for food.\n";
     dest_dir=({ PATH+"/e10s3","north",
		 PATH+"/e12s3","south",
		 PATH+"/e11s4","east" });
  }
  if (!(ob=present("lamb")) || !living(ob)) {
     for(i=0;i<5;i++) {
	ob=clone_object("obj/monster");
	ob->set_name("lamb");
	ob->set_short("A lamb");
	ob->set_long("A fluffy white lamb, with soft brown eyes.\n");
	ob->set_level(1);
	ob->set_whimpy();
	ob->load_chat(10,
	({ "The lamb bleats forlornly at you.\n",
	   "The lamb munches a tuft of hay.\n" }) );
	move_object(ob,this_object());
     }
  }
}
