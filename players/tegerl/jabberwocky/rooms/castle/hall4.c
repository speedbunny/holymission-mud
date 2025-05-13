

/* Tegerl, 22.3.1995 */
/* rooms/castle/hall4 */


inherit "/players/tegerl/jabberwocky/rooms/castle/mortar";

void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_light(1);
short_desc="A large hall in the castle";

long_desc=
    "This is a very large hall. " +
    "It is very dim and dusty here. Dust and mortar lies on the ground. " +
    "This castle seems to be even more desolate than you thought. " +
    "To the southwest you can enter a tower, but to the east and the north the hall continues.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/castle/tower1", "southwest",
    "players/tegerl/jabberwocky/rooms/castle/hall5", "east",
    "players/tegerl/jabberwocky/rooms/castle/hall1", "north",
});

items=({
    "castle","It is a very old castle and it is in a very bad contition",
    "walls","The walls look very ugly and they seem to be very weak",
    "wall","The wall looks very ugly and it seems to be very weak",
    "ceiling","The ceiling looks very ugly and there is almost no mortar left on it",
    "ground","You think that the floor is made of stone, but you are not sure because there lies a lot of mortar and dust on the ground",
});

smell = "You smell waste and dump.";
  
  }

