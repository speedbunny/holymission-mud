

/* Coded by Tegerl, 8.3.1995 */
/* rooms/out/place1 */


inherit "room/room";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_light(1);
short_desc="At the city-wall";

long_desc=
    "This is an open place south of a city. " +
    "To the south lies a forest and to the southwest leads a path. " +
    "To the north you can see a city-wall.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/out/path9", "southwest",
    "players/tegerl/jabberwocky/rooms/out/place2", "east",
    });

items=({
    "path","The ground is muddy and you can see that it has been used lately",
    "footprints","Yes, footprints, and they are human",
    "city-wall","The wall is very old and needs to be repaired. It seems to be very desolate",
    "wall","The wall is very old and needs to be repaired. It seems to be very desolate",
    "walls","Those walls are very old city-walls, and they need to be repaired",
    "town","You can't see the town because the walls are in between, but can almost feel that it is here",
});

smell = "The air could be fresh and clean, if that town wouldn't be there. So you can only smell waste and dump.";
  
  }

