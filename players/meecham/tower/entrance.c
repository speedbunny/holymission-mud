inherit "room/room";
#include "/players/meecham/def.h"
reset(arg)
{
  CLONE("demon","col_demon");
  if(!arg)
  {
    set_light(1);
    short_desc="clearing";
    long_desc=
      "You come to a clearing in the woods.  A magnificent tower stands\n"+
      "before you.  However, it is starting to fall into disrepair.\n"+
      "There is a bazaar being setup to the west.\n";
    items=({
      "tower","You see a magnificent grey tower rising from the ground\n"+
      "before you.  This must be where Meecham and Kitty live!",
    });
    dest_dir=({
      "room/forest12", "east",
      "room/south/sforst5", "south",
      PM+"tower/hole/path_to_col","down",
      PM+"tower/bazaar","west",
    });
  }
}
init()
{
  ::init();
  add_action("enter","enter");
}
enter(str)
{
  if((!str) || (str !="tower"))
    return 0;
  write("Sorry, the tower is being repaired right now :*)\n");
/*
  this_player()->move_player("into the tower#/players/meecham/tower/b25.c");
*/
  return 1;
}
