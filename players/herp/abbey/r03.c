#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="The Library";
     long_desc=
"There are many books here, lying in tumbled heaps.\n";
     dest_dir=({ PATH+"/r02","east",
		 PATH+"/r06","south" });
  }
  if(!present("book")) {
	ob=clone_object("obj/treasure");
	ob->set_name("book");
	ob->set_alias("blue book");
	ob->set_short("A blue book");
	ob->set_value(10);
	move_object(ob,this_object());
  } 
}
