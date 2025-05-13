#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;

  if (!arg) {
     set_light(1);
     short_desc="The Butchery";
     long_desc=
"You see a dying pig, whose throat is cut to bleed him, tied over a huge\n" +
"five-foot deep, narrow cauldron.  A monk is upended in the foul vat of\n" +
"offal.  The stench of this place and the din from the screaming pig are\n" +
"overwhelming.  It is obvious the monk is dead as his feet are motionless.\n";
     dest_dir=({ PATH+"/e11s1","west" });
  }
  if (!(ob=present("spirit")) || !living(ob)) {
	ob=clone_object("obj/monster");
	ob->set_name("spirit");
	ob->set_level(5);
	ob->set_short("A bloody spirit");
	ob->set_long("The spirit wails: release me!!\n");
	ob->load_a_chat(10,
	({ "The spirit wails: Find the secret door.\n" }) );
	move_object(ob,this_object());
  }
}
