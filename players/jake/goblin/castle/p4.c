inherit "room/room";

#include "/players/jake/defs.h"

object pon;
reset(arg) {
 if(!pon) {
 pon=clone_object("/obj/monster");
 pon->set_name("Small pony");
 pon->set_short("A small pony");
 pon->set_alias("pony");
 pon->set_level(3);
 pon->set_hp(100);
 pon->set_align(1000);
 pon->set_long("A small brown pony with a long brown mane.\n");
 pon->add_money(25);
 move_object(pon,this_object());
}
if(arg) return;
 set_light(1);
 short_desc = "Northwest corner of the pasture";
 long_desc  = "You have come to the northwestern corner of the horse pasture.\n" +
              "Wooden fences prevent any passage west or north, and come together\n" +
              "at a dead tree.  Be careful not to step in any horse patties!\n";
 items = ({
  "tree","A dead tree",
  "fence","A wooden fence that keeps the horses in the pasture",
  "fences","Wooden fences that keeps the horses in the pasture",
 });
 DD = ({
  CAS + "p2","south",
  });

::reset();
replace_program("room/room");
}
