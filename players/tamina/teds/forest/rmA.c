inherit "room/room";

#include "/players/tamina/defs.h"

object griffon;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return 0;

  set_light(1);
  short_desc = "Petrified Forest";
  long_desc =
"Under some conceiling bushes sits what can only be\n"+
"described as a nest. A rather large nest, but a\n"+
"nest none the less. As you look closer you can see\n"+
"fragments of bleached white bone and shredded clothes\n"+
"line the nest.\n";

    dest_dir = ({
    TFOREST + "rmD", "north",
    });

  griffon = present("griffon");
  if (!griffon) 
  {
    griffon = clone_object("obj/monster");

    griffon->set_name("griffon");
    griffon->set_race("griffon");
    griffon->set_long(
  "This creature has the body of a lion, and the head of a bird.\n");
    griffon->set_level(18);
    griffon->set_wc(24);
    griffon->set_ac(9);
    griffon->set_al(-100);
    griffon->set_aggressive(1);

    "/players/tamina/teds/random_treasure"->make_item(griffon, 18);
    "/players/tamina/teds/random_magic"->make_item(griffon, 18);
    "/players/tamina/teds/random_armor"->make_item(griffon, 18);
    move_object(griffon, this_object());
  }
}
