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
     dest_dir=({ PATH+"/r03","north",
		 PATH+"/r09","south",
		 PATH+"/r05","east" });
  }
  if(!present("book")) {
	ob=clone_object("obj/treasure");
	ob->set_name("book");
	ob->set_alias("red book");
	ob->set_short("A red book");
	ob->set_value(40);
	move_object(ob,this_object());
  } 
}
