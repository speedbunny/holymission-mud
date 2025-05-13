

/* Tegerl, 8.3.1995 */
/* rooms/out/forest1 */


inherit "room/room";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_light(0);
short_desc="A dark forest";

long_desc=
    "You dared to enter the forest. " +
    "There is no path anymore, you can only follow the footprints. " +
    "The forest surrounds you and you can't even see where you came " +
    "from.\n";
  
/* exits */
dest_dir=({
    "players/tegerl/jabberwocky/rooms/out/path7", "northwest",
    "players/tegerl/jabberwocky/rooms/out/forest2", "south",

    });

/* descriptions */
items=({
    "forest","The forest is very dark and surrounds you. You are lost here",
    "footprints","There are only footprints leading into the forest, but none leading out again",
});

/* no proberties */

/* smell */
smell = "The air is damp and you can smell rotten trees.";
  
  }

