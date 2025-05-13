

/* Coded by Tegerl, 8.3.1995 */
/* rooms/out/place3 */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"

void reset(int arg) 
{
if (!arg);
{
clone_list=({1,1,"prophet",PATH+"monsters/cman",0,
            2,1,"catapult",PATH+"obj/cat",0});


set_light(1);
short_desc="At the city-wall";

long_desc=
    "This is an open place south of a city. " +
    "To the south lies a forest and to the west you can see the entrance to the " +
    "town. There seems to be a big crowd in front of the entrance door. To the north " +
    "you can see a city-wall.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/out/place2", "west",
    "players/tegerl/jabberwocky/rooms/out/door", "east",
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

::reset(arg);
replace_program("room/room");
}

