

/* Coded by Tegerl, 8.3.1995 */
/* rooms/town/street2 */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"
void reset(int arg) 
{

if (!arg);
{
clone_list=({1,1,"guard",PATH+"monsters/guard",0,
            2,3,"inhabitant",PATH+"monsters/sman",0,
            3,2,"woman",PATH+"monsters/swoman",0,
            4,1,"child",PATH+"monsters/schild",0});
set_light(1);
short_desc="In the city";

long_desc=
    "You are on a road in town. " +
    "The street leads further north and south. " +
    "To the west is a pub and to the east you can see a house entrance. " +
    "There are people on the street and they seem to be busy.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/town/pub2", "west",
    "players/tegerl/jabberwocky/rooms/town/street3", "north",
    "players/tegerl/jabberwocky/rooms/town/house2", "east",
    "players/tegerl/jabberwocky/rooms/town/street1", "south",
  });

items=({
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