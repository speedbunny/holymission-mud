

/* Tegerl, 22.3.1995 */
/* rooms/castle/way2 */


inherit "room/room";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_light(1);
short_desc="A way to the castle";

long_desc=
    "You are on the way between the yard and the castle. " +
    "To the west is the yard and to the east all you can see is the castle. " +
    "Now you are standing directly in front of this castle. " +
    "The walls are very ugly and the wooden door is rotten and can't be closed any more.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/castle/way1", "west",
    "players/tegerl/jabberwocky/rooms/castle/hall1", "east",
  });

items=({
    "castle","It is a very old castle and it is in a very bad contition",
    "walls","The walls look very ugly and they seem to be very weak",
    "wall","The wall looks very ugly and it seems to be very weak",
    "door","The wooden door, the entrance to the castle is rotten and it is impossible to close it",
});

smell = "You smell waste and dump.";
  
  }

