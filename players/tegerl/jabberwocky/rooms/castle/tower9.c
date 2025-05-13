

/* Tegerl, 22.3.1995 */
/* rooms/castle/tower9 */


inherit "room/room";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_light(0);
short_desc="In a tower";

long_desc=
    "You are in a tower, somewhere between ground floor and top. " +
    "are stairs leading up and down. From above you can see a light, maybe the top of the tower.  " +
    "There are no windows and it is cold in here.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/castle/tower8", "down",
    "players/tegerl/jabberwocky/rooms/castle/tower10", "up",
  });

items=({
    "castle","It is a very old castle and it is in a very bad contition",
    "walls","The walls look very ugly and they seem to be very weak",
    "wall","The wall looks very ugly and it seems to be very weak",
    "stairs","The stairs are very narrow, take care",
    "stair","The stairs are very narrow, take care",
});

smell = "You smell waste and dump.";
  
  }

