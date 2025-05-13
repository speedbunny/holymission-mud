inherit "room/room";

#include "/players/tamina/defs.h"

object dragon;

void reset(int arg) 
{
  if (!arg) 
  {
    set_light(1);
    short_desc = "Ice Filled Cave";
    long_desc =
"This cold cave is made of ice. Huge ice stalagtites\n"+
"hang from the ceiling. Large gouge marks can be seen\n"+
"on the walls and floor. A strange rumbling comes from\n"+
"the west.\n";

    dest_dir = ({
  TCOLD + "ice_cave", "east"
    });

    items = ({
  "west wall",
"There would appear to be a small opening which you could pass through..",
  "wall",
"There is a gap in the west wall which you might be able to go through",
  });

  }
  if (!present("snow dragon")) 
  {
    dragon = clone_object("obj/monster");

    dragon->set_name("snow dragon");
    dragon->set_race("dragon");
    dragon->set_gender(2);
    dragon->set_long(
      "This huge beast has massive silver claws, and huge white fangs.\n");
    dragon->set_level(19);
    dragon->set_wc(23);
    dragon->set_ac(8);
    dragon->set_aggressive(1);
    dragon->set_al(-500);

    call_other("/players/tamina/teds/random_treasure","make_item", dragon, 19);
    call_other("/players/tamina/teds/random_magic", "make_item", dragon, 19);
    move_object(dragon, this_object());
  }
}

void init() 
{
  ::init();
  add_action("west", "west");
}

int west() 
{
  if (present("snow dragon", this_object())) 
  {
    write("The dragon keeps you from going west.\n");
    dragon->attack_object(TP);
    return 1;
  }
  write("You pass through a small opening in the west wall...\n");
  MPL("west#/players/tamina/teds/cold/steel_drag");
  return 1;
}
