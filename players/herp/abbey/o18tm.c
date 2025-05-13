#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob,tw;
  if (!arg) {
     set_light(1);
     short_desc="The Burning of the Innocent";
     long_desc=
"You stand before a mound of earth.  Atop is a horrific sight.\n"+
"Writhing in the flames above burning sticks, is a poor wretch, tied\n"+
"to a stake.  He shrieks and howls, then sings loudly.  He tries with\n"+
"pityful foolishness to blow the flames out.\n";
     dest_dir=({ PATH+"/o18t1","north" });
  }
  if (!(ob=present("idiot")) || !living(ob)) {
	ob=clone_object("obj/monster");
	ob->set_name("idiot");
	ob->set_level(4);
	ob->set_long("A snag-toothed, balding moron.\n");
	ob->set_short("A miserable hunchbacked village idiot");
	ob->load_chat(60,
	({ "The idiot sings: La morte is supremos.\n",
	   "The idiot sings: Ugly Consalvatori, eh??\n",
	   "The idiot sings: Nolo so magnifico.\n" }) );
	ob->load_a_chat(60,
	({ "The idiot says: Si,si, domini belissimi.\n",
	   "The idiot says: Savvy nada, me stupido.\n" }) );
	tw=clone_object("obj/treasure");
	tw->set_id("twine");
	tw->set_short("A twine");
	tw->set_long("A ball of soft brown twine.\n");
	tw->set_value(100);
	move_object(tw,ob);
	move_object(ob,this_object());
  }
}
