inherit "room/room";

#include "/players/jake/defs.h"

object gob,ho;

reset(arg) {
 if(!gob) {
 gob=clone_object("obj/monster");
 gob->set_name("Small goblin");
 gob->set_alias("goblin");
 gob->set_level(3);
 gob->set_hp(100);
 gob->set_align(500);
 gob->set_aggressive(0);
 gob->set_short("A small goblin");
 gob->set_long("This is a small goblin.  He likes to pet his horse.\n");
 gob->add_money(25);
move_object(gob,this_object());
}
 if(!ho) {
 ho=clone_object("obj/monster");
 ho->set_name("Grey horse");
 ho->set_alias("horse");
 ho->set_level(4);
 ho->set_hp(150);
 ho->set_align(1000);
 ho->set_aggressive(0);
 ho->set_short("A grey horse");
 ho->set_long("A grey horse.\n");
 ho->add_money(30);
move_object(ho,this_object());
}
if(arg) return;
set_light(1);
 short_desc = "Grey horse stable";
 long_desc = "There are ribbons of various colors draped around this stable.\n" +
             "The bed of hay has been neatly fluffed up, and the water in the\n" +
             "pail is crystal clear.  A trough filled with oats is nailed to\n" +
             "the eastern wall.\n";
 items = ({
  "ribbons","Ribbons of various colors",
  "bed","A bed of hay",
  "hay","A bed of hay",
  "trough","A trough of oats",
  "pail","A pail of crystal clear water",
  "water","It's crystal clear",
  });
 DD = ({
   CAS + "s6","west",
  });
::reset();
replace_program("room/room");
}
