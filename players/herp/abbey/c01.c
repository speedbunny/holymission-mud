#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="The Garbage-Sluice";
     long_desc=
"You stand in a heap of filth.  Rotted vegetables, moldy fruit, and the\n"+
"foul effluent from the latrines and baths are gathered here to be\n"+
"pushed out the sluice to the waiting peasants below.\n";
     dest_dir=({ PATH+"/o02","down",
		 PATH+"/c18","southeast",
		 PATH+"/c02","south" });
  }

  if (!(ob=present("girl")) || !living(ob)) {
	ob=clone_object("obj/monster");
	ob->set_name("girl");
	ob->set_short("A beggar girl");
	ob->set_long("A small gruby beggar girl.\n");
	ob->set_level(13);
	ob->load_a_chat(40,
	({ "The poor beggar girl smells like she needs a bath.\n",
	   "The beggar girl puts a surprisingly pretty hand on your arm.\n"
	}) );
	move_object(ob,this_object());
  }
}
