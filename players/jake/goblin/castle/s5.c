inherit "room/room";

#include "/players/jake/defs.h"

object ho;
reset (arg) {
if(!ho) {
 ho = clone_object("obj/monster");
 ho->set_name("Black horse");
 ho->set_alias("horse");
 ho->set_short("A black horse");
 ho->set_long("A large black horse.\n");
 ho->set_level(4);
 ho->set_align(1000);
 ho->set_aggressive(0);
 ho->set_hp(150);
 ho->add_money(30);
 move_object(ho,this_object());
}
 if(arg) return;
 set_light(1);
 short_desc = "Black horse stable";
 long_desc  = "You are standing on a bed of hay in a stable.  A trough of oats\n" +
    "and a metal pail of water are nailed against the western wall.\n";
 items = ({
 "pail","A metal pail full of water",
 "trough","A wooden trough full of oats",
 });
 DD = ({
      CAS + "s3","east",
});
}
