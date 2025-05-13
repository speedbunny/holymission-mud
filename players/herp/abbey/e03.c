#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="Further South";
     long_desc=
  "You climb into the broken foothills, through cold and rugged country.\n";
     dest_dir=({ PATH+"/e02","north",
		 PATH+"/e04","south" });
  }
  if (!(ob=present("raven")) || !living(ob)) {
	ob=clone_object("obj/monster");
	ob->set_name("raven");
	ob->set_short("A black raven");
	ob->set_long("The raven seems to watch you intently.\n");
	ob->set_level(3);
	ob->load_a_chat(10,
	({ "The rave beats at you with his strong wings.\n" }) );
	move_object(ob,this_object());
  }
}
