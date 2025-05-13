

/* Coded by Tegerl, 8.3.1995 */
/* rooms/town/street1 */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"

void reset(int arg) 
{

if (!arg);
{
clone_list=({1,2,"guard",PATH+"monsters/guard",0,
            2,1,"inhabitant",PATH+"monsters/sman",0,
            3,1,"woman",PATH+"monsters/swoman",0,
            4,3,"child",PATH+"monsters/schild",0});
set_light(1);
short_desc="At the city entrance";

long_desc=
    "You have passed the door and you are now in the town. " +
    "To leave town, just go south. To the north, the west and the east " +
    "are roads. And along the roads you can see houses, many houses, and shops. " +
    "There are people on the street and they seem to be busy.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/town/wall1", "west",
    "players/tegerl/jabberwocky/rooms/town/street2", "north",
    "players/tegerl/jabberwocky/rooms/town/wall7", "east",
    "players/tegerl/jabberwocky/rooms/out/door", "south",
  });

items=({
    "city-wall","The wall is very old and needs to be repaired. It seems to be very desolate",
    "wall","The wall is very old and needs to be repaired. It seems to be very desolate",
    "entrance","The entrance is heavily guarded. There is one tower left and right of the door",
    "door","The big door is made of wood, but it has metal fittings",
    "people","There are people, and they all seem to be very busy",
    "houses","Along the roads there are many houses, some are shops",
});

smell = "The air could be fresh and clean, if that town wouldn't be there. So you can only smell waste and dump.";
  
  }

::reset(arg);
replace_program("room/room");
}