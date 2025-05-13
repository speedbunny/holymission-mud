
/* Gambit - Barbarian Guild */

inherit "obj/monster";

#include "/players/apollo/guild/barb.h"

object weapon;

reset(arg) {
 ::reset(arg);
 if(arg) return;

    set_name("conan");
    set_short("Conan the Barbarian");
    set_long("Conan the barbarian is the watcher and keeper of the whole\n"+
      "barbarian guild. He keeps track of all the barbarians and watches far\n"+
      "and wide for all intruders. He is not one to mess with. He stands\n"+
      "at about six foot and wears only bear fur around his waist but his\n"+
      "muscles make him look like a god.\n");
 
    set_level( 60 + random(10) );
    set_gender(1);
    set_race("human");
  set_ac(45);
   set_wc(80);
    set_number_of_arms(3);
    set_hp(15000);

    weapon = CO( GWEAPONS+"c_sword" );
	    transfer( weapon,this_object() );

    add_property("has_answers",([
	"area": "The area is huge and has many weapons and treasures...",
	"crom": "Crom is my god .. He will destroy all...",
	"guild": "This is the barbarians guild...", ]));
    load_chat(3,({
	("Conan watches over the guild.\n"),
	("Conan says: Crush your enemies, Drive them before you, \n"+
	  "and listen to the lamintations of the women.\n"),
	("Conan cleans his weapon with oil to make it shine.\n"),
	("Conan says: Steel is only as strong as the hand that wields it.\n"),
      }));
    load_a_chat (22,({
	("Conan growls and starts bashing you hard !\n"),
	("Conan cracks his knuckles on your face !\n"),
         ("Conan growls: I kill you bastard!\n"),
      }));

}
