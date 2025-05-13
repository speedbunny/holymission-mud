inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  if (!arg) 
  {
    set_light(1);
    short_desc = "Cold Path";
    long_desc =
"This path becomes colder the farther west you\n"+
"travel. Buildings can be seen both to the north\n"+
"and to the south.\n";

    dest_dir = ({
  TCOLD + "cold_path2", "west",
  TPATH + "wierd_path", "east"
    });
  }
}

void init() 
{
  ::init();
  add_action("north", "north");
  add_action("south", "south");
}

int north() 
{
  if (this_player()->query_level() <= 10) 
  {
    write("You leave north.\n");
    this_player()->move_player("north#players/tamina/teds/cold/cold_dwarf");
    return 1;
  }
  write("You are above the tenth level.....you are to high a level.\n");
  return 1;
}

int south() 
{
  if (this_player()->query_level() <= 10) 
  {
    write("You leave south.\n");
    this_player()->move_player("south#players/tamina/teds/cold/cold_orc");
    return 1;
  }
  write("You are above tenth level.....you are to high a level.\n");
  return 1;
}
