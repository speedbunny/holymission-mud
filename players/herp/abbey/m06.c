#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;

  if (!arg) {
     set_light(1);
     short_desc="Cemetery";
     long_desc=
"You walk through a deserted cemetary.  The wind sighs through the\n" +
"barren graves, each marked by a plain wooden cross.  You see one fresh\n"+
"grave. As you walk up to it, you see the name is Fra. Andalmo.\n";
     dest_dir=({ PATH+"/m05","east" });
  }
  if (!(ob=present("raven")) || !living(ob))
     for (i=0;i<3;i++) {
	ob=clone_object("obj/monster");
	ob->set_name("raven");
	ob->set_level(3);
	ob->set_short("A raven");
	ob->set_long("The raven tries to peck you in the eye!\n");
	ob->load_chat(10,
	({ "The raven caws loudly!\n",
	   "The raven tries to peck you in the eye!\n" }) );
	move_object(ob,this_object());
     } 
}
