#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;
  if (!arg) {
     set_light(1);
     short_desc="Jumbled Rocks";
     long_desc=
"You scramble over jumbled boulders at the top of a steep cliff.\n";
     dest_dir=({ PATH+"/o25","east" });
  }
  if (!(ob=present("raven")) || !living(ob)) {
     for (i=0;i<3;i++) {
	ob=clone_object("obj/monster");
	ob->set_name("raven");
	ob->set_short("A shiny black raven");
	ob->set_long("The raven looks warily at you.\n");
	ob->set_level(4);
	ob->load_a_chat(10,
	({ "The raven tries to peck you in the eye!\n",
	   "The raven caws loudly.\n" }) );
	move_object(ob,this_object());
     }
  }
}
