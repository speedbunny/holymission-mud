inherit "room/room";

#include "/players/jake/defs.h"

object ho;

reset(arg) {
if(!ho) {
 ho=clone_object("obj/monster");
 ho->set_name("White horse");
 ho->set_alias("horse");
 ho->set_short("A white horse");
 ho->set_long("A white horse.\n");
 ho->set_level(4);
 ho->set_hp(150);
 ho->set_aligh(1000);
 ho->set_aggressive(0);
 ho->add_money(30);
move_object(ho,this_object());
}
if(arg) return;
 set_light(1);
 short_desc = "White horse stable";
 long_desc  = "This stable is incredibly clean.  The hay used for bedding is\n" +
              "neatly laid out, and almost looks like it is woven together.\n" +
              "The feed trough is filled, without a single grain out of place\n" +
              "and the water in the pail is crystal clear.  You wonder what\n" +
              "kind of horse deserves such treatment.\n";
 items = ({
  "hay","The hay has a woven appearance",
  "bedding","The hay has a woven appearance",
  "trough","The feed trough is clean",
  "pail","The pail is filled with crystal clear water",
  "water","You can see your reflection in it",
  "grain","Not a single grain is out of place",
});
 DD = ({
  CAS + "s6","east"
});
replace_program("room/room");
}
