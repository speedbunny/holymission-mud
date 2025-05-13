#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="The Library";
     long_desc=
"You seem to have entered the library.\n"+
"There are many books here, lying in tumbled heaps.\n";
     dest_dir=({ PATH+"/r06","north",
		 PATH+"/r08","east" });
  }
  if(!present("book")) {
	ob=clone_object("obj/treasure");
	ob->set_name("book");
	ob->set_alias("blue book");
	ob->set_short("A blue book");
	ob->set_value(45);
	move_object(ob,this_object());
  } 
}
