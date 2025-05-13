#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="The Library";
     long_desc=
"You have entered a vast room filled with the illuminators' desks and high\n"+
"stools.  There are large windows admitting good light for them to do their\n"+
"work.  On each desk is a work in progress, a huge book with colorful illu-\n"+
"mination partially completed.  You see a dead monk slumped over one desk.\n"+
"His right forefinger and tongue are black as coal.\n";
     dest_dir=({ PATH+"/l01","north",
		 PATH+"/l03","south" });
  }
  if (!(ob=present("spirit")) || !living(ob)) {
	ob=clone_object("obj/monster");
	ob->set_name("spirit");
	ob->set_short("A spirit of the librarian");
	ob->set_long("The spirit wails: release me!!\n");
	ob->set_level(15);
	ob->load_a_chat(10,
	({ "The spirit wails: Touch the skull\n" }) );
	move_object(ob,this_object());
  }
}
