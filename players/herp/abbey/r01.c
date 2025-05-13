#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="The Library";
     long_desc=
"You have finally found the REAL library.  There are thousands of very\n"+
"valuable books here, carelessly strewn about.  To the north is a\n"+
"labyrinth, so be warned.\n";
     dest_dir=({ PATH+"/l27","north",
		 PATH+"/r02","west",
		 PATH+"/r04","south" });
  }
  if(!present("book")) {
	ob=clone_object("obj/treasure");
	ob->set_name("book");
	ob->set_alias("blue book");
	ob->set_short("A blue book");
	ob->set_value(5);
	move_object(ob,this_object());
	ob=clone_object("obj/treasure");
	ob->set_name("book");
	ob->set_alias("red book");
	ob->set_short("A red book");
	ob->set_value(10);
	move_object(ob,this_object());
	ob=clone_object("obj/treasure");
	ob->set_name("book");
	ob->set_alias("black book");
	ob->set_short("A dark black book");
	ob->set_value(200);
	move_object(ob,this_object());
  } 
}
