

/* Tegerl, 22.3.1995 */
/* rooms/castle/way1 */


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
    "The closer you are, the more you can see how desolate this castle really is.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/castle/yard", "west",
    "players/tegerl/jabberwocky/rooms/castle/way2", "east",
  });

items=({
    "castle","It is a very old castle and it is in a very bad contition",
});

smell = "You smell waste and dump.";
  
  }

