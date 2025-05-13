#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;

  if (!arg) {
     set_light(1);
     short_desc="The Bath";
     long_desc=
"You see a hugely corpulent, dead monk floating in a large wooden tub of\n"+
"cold, scummy water.  A large quantity of soggy herbs float in the water.\n"+
"He has obviously been dead sometime.  His right forefinger and tongue are\n"+
"black as coal.\n";
     dest_dir=({ PATH+"/c05","south" });
  }
  if (!(ob=present("spirit")) || !living(ob))
	ob=clone_object("obj/monster");
	ob->set_name("spirit");
	ob->set_short("A huge spirit");
	ob->set_long("The spirit wails: release me!!\n");
	ob->set_level(15);
	ob->load_a_chat(10,
	({ "The spirit wails: press the fourth and seventh above\n" }) );
	move_object(ob,this_object());
}
