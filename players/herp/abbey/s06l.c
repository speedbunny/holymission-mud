#include "abbey.h"
inherit "room/room";

object iq,di;		/* Has to be global for the wield_func */

reset(arg) {
object ob;

  if (!arg) {
     set_light(1);
     short_desc="The Inquisitor's room";
     long_desc=
"You have entered a large room, filled with tables and chairs.\n"+
"It seems to be where the inquisition will be held.\n";
     dest_dir=({ PATH+"/s06","east" });
  }
  if (!(ob=present("inquisitor")) || !living(ob)) {
	iq=clone_object("obj/monster");
	iq->set_name("inquisitor");
	iq->set_level(25);
	iq->set_no_steal();
	iq->set_short("The Holy Inquisitor");
	iq->set_long("The Inquisitor wears austere black robes.\n");
	iq->load_chat(30,
	({ "The Inquisitor says: You will soon BEG to tell me!\n",
	   "The Inquisitor says: Sir William cannot save you now.\n",
	   "The Inquisitor says: How long have you been a Penitenziagite?\n"
	}) );
	di=clone_object("obj/weapon");
	di->set_name("discipliner");
	di->set_value(1000);
	di->set_wield_func(this_object());
	move_object(di,iq);
	ob=clone_object("obj/treasure");
	ob->set_id("relic");
	ob->set_short("A Most Holy Relic");
	ob->set_long("An ornate box with a lock of hair inside.\n");
	ob->set_value(10000);
	move_object(ob,iq);
	ob=clone_object("obj/armour");
	ob->set_name("platemail");
	ob->set_alias("mail");
	ob->set_short("Finely polished black platemail");
	ob->set_value(5000);
	ob->set_weight(4);
	ob->set_ac(5);
	move_object(ob,iq);
	move_object(iq,this_object());
	command("wield weapon",iq);
	command("wear armour",iq);
     }
}

wield(ob) {
  if (environment(ob)==iq) di->set_class(35);
  else di->set_class(19);
  return 1;
}

