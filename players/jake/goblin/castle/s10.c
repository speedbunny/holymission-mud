inherit "room/room";
#include "/players/jake/defs.h"
object ho;
reset(arg) {
 if(!ho) {
ho=clone_object("obj/monster");
ho->set_name("Work horse");
ho->set_alias("horse");
ho->set_short("A work horse");
ho->set_long("A large work horse.\n");
ho->set_level(5);
ho->set_hp(200);
ho->set_align(1000);
ho->add_money(100);
move_object(ho,this_object());
}
if(arg) return;
set_light(1);
short_desc = "Work horse stable";
long_desc  = "The stable in which you are standing is rather large in size.  The\n" +
  "feed trough is empty, and the water pail has but a few drops of water left\n" +
  "in it.  Some of the boards that make up the stable are splintered, indicating\n" +
  "that something has kicked through them.  Probably just a large or horse.\n";
items = ({
 "trough","An empty feed trough",
 "pail","The water bucket is empty",
 "board","They appear to have been kicked by some large animal",
});
DD = ({
 CAS + "s9","west",
});
::reset();
replace_program("room/room");
}
