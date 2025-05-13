/* Coded by Jewel of Holy Mission */
/* /players/jewel/poe/bridge.c */
 
#include "/players/jewel/defs.h"
 
inherit "room/room";
 
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Bridge";
  long_desc = 
  "You are on a crumbling stone bridge.  Pieces of it fall into the\n"
+ "moat below as you pass by.  Watch your footing very carefully!\n";
  items = ({ 
"bridge","It is in shambles.  You hope to make it across",
"moat","Looking over the side you see a moat filled with black liquid",
"stone","Gray stones.  They look very old and are crumbling",
"stones","Gray stones.  They look very old and are crumbling",
             });
  dest_dir = ({
        POE+"porch", "north",
        POE+"badlands", "south",
                });
  smell = "It smells quite foul here.";
}
 
init()
{
  ::init();
  add_action("jump","jump");
}
 
jump()
{
  write("You take a daring leap and jump into the moat.\n");
  MOVEP("jumps into the moat#players/jewel/poe/moat");
  return 1;
}

