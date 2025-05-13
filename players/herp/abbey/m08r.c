inherit "room/room";
/* Galadriel: 120893: room didnt load.
new parser doesn't take ';' at end of #include. */
#include "abbey.h"

reset(arg) {
object ob,mo;

  if (!arg) {
     set_light(1);
     short_desc="Small Bedroom";
     long_desc=
"You are in a barren cell, used for mediation and the consideration of\n"+
"their self-discipline and spiritual growth by the monks.\n";
     dest_dir=({ PATH+"/m08","west" });
  }
  if (!(ob=present("bishop")) || !living(ob)) {
	mo=clone_object("obj/monster");
	mo->set_name("bishop");
	mo->set_alias("monk");
	mo->set_level(17);
	mo->set_short("A bishop");
	mo->set_long("A bishop is praying before an icon.\n");
	ob=clone_object("obj/weapon");
	ob->set_name("sword");
	ob->set_short("A sword");
	ob->set_value(650);
	ob->set_class(15);
	move_object(ob,mo);
	ob=clone_object("obj/armour");
	ob->set_name("ring");
	ob->set_type("ring");
	ob->set_short("A platinum ring");
	ob->set_long("A solid platinum ring with carnelian chip.\n");
	ob->set_value(1500);
	ob->set_weight(3);
	ob->set_ac(1);
	move_object(ob,mo);
	ob=clone_object("obj/armour");
	ob->set_name("shield");
	ob->set_type("shield");
	ob->set_short("A black shield");
	ob->set_long("A black shield with a large crimson cross.\n");
	ob->set_value(1000);
	ob->set_weight(2);
	ob->set_ac(1);
	move_object(ob,mo);
	move_object(mo,this_object());
	command("wield sword",mo);
	command("wear ring",mo);
	command("wear shield",mo);
  }
}
