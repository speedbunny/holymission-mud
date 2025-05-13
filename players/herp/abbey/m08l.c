#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob,mo;
  if (!arg) {
     set_light(1);
     short_desc="A Monk's Cell";
     long_desc=
"You have entered an austere room containing few furnishings, and those\n"+
"are of inferior quality.  The owner of this room takes his practice of\n"+
"poverty seriously.\n";
     dest_dir=({ PATH+"/m08","east" });
  }
  if (!(ob=present("prelate")) || !living(ob)) {
	mo=clone_object("obj/monster");
	mo->set_name("prelate");
	mo->set_alias("monk");
	mo->set_level(17);
	mo->set_short("A prelate");
	mo->set_long("A prelate sits here, lost in mediation.\n");
	ob=clone_object("obj/weapon");
	ob->set_name("sword");
	ob->set_short("A sword");
	ob->set_value(550);
	ob->set_class(15);
	move_object(ob,mo);
	ob=clone_object("obj/armour");
	ob->set_name("robe");
	ob->set_type("cloak");
	ob->set_value(210);
	ob->set_short("A soft, black robe");
	ob->set_ac(1);
	move_object(ob,mo);
	ob=clone_object("obj/armour");
	ob->set_name("helmet"); ob->set_alias("helm");
	ob->set_type("helmet");
	ob->set_short("A silver helm");
	ob->set_value(200);
	ob->set_ac(1);
	move_object(ob,mo);
	move_object(mo,this_object());
	command("wield sword",mo);
	command("wear helmet",mo);
	command("wear robe",mo);
  }
}
