#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;
  if (!arg) {
     set_light(1);
     short_desc="Mouse House";
     long_desc=
"You have found your way to a small mouse nest.  The monks believe\n"+
"mice are lucky, or they would have exterminated them.\n";
     dest_dir=({ PATH+"/e09s3","north",
		 PATH+"/e11s3","south",
		 PATH+"/e10s4","east" });
  }
  if (!(ob=present("mouse")) || !living(ob)) {
     for(i=0;i<5;i++) {
	ob=clone_object("obj/monster");
	ob->set_name("mouse");
	ob->set_short("A mouse");
	ob->set_long("You see a little furry, brown mouse.\n");
	ob->set_level(1);
	ob->set_whimpy();
	ob->load_chat(10,
	({ "A mouse twitches his whiskers at you.\n",
	   "Squeak, squeak!\n" }) );
	move_object(ob,this_object());
     }
  }
}
