#define NAME "airborne"
#define DEST "/players/airborne/workroom"

object hellfire, newbie, mentor;

id(str) { return str == "bridge"; }

short() { return "A rope bridge leads north"; }

long() { write("An old yet sturdy rope bridge.\n"); }

init() { add_action("north", "north"); }

north(str) {
 this_player()->move_player("walks north#players/airborne/temple/entrance/bridge1");
   return 1;
}

reset(arg) {
  if (arg) return;
  move_object(this_object(), DEST);
	}

make_quest() {

  hellfire = clone_object("obj/quest_obj");     
  hellfire-> set_name("hellfire");
  hellfire-> set_short_hint("Quench the great Hellfire.");
  hellfire-> set_weight(30);
  hellfire-> set_killing(9);
  hellfire-> set_hint(
     "Rumors claim that a demon lord is in control of one of the most\n"+
     "powerful forces known - the Hellfire.  The demon lord is worshiped\n"+
     "at a distant temple. If you can find him, quench the hellfire and\n"
     "make the world a safer place.\n");
  hellfire-> add_quest();

  newbie = clone_object("obj/quest_obj");
  newbie-> set_name("total_newbie");
  newbie-> set_short_hint("Get to the end of the complete newbie area");
  newbie-> set_weight(1);
  newbie-> set_killing(2);
  newbie-> set_hint("Just south then down from the main shop is the entrance\n"+
	"to the complete newbie area. Learn all you need to know\n"+
	"about adventuring and get to the end. This quest is for\n"+
	"complete newbies level 5 and under only!\n");
  newbie-> add_quest();

  mentor= clone_object("obj/quest_obj");
  mentor-> set_name("mentor");
  mentor-> set_short_hint("Find a Wizard to be your mentor");
  mentor-> set_weight(0);
  mentor-> set_killing(0);
  mentor-> set_compulsory(1);
  mentor-> set_hint("Every Apprentice will need a mentor, and so is true "+
	"with Wizards.\nFind a Wizard of Holy Mission who will be your "+
	"mentor and guide\nyou on the proper steps you must take.\n");
  mentor-> add_quest();

	return 1;
}
