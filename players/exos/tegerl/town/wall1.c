

/* Coded by Tegerl, 8.3.1995 */
/* rooms/town/wall1 */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"
void reset(int arg) 
{
if (!arg);
{
clone_list=({1,2,"guard",PATH+"monsters/guard",0,
            2,2,"inhabitant",PATH+"monsters/sman",0,
            3,1,"woman",PATH+"monsters/swoman",0,
            4,1,"child",PATH+"monsters/schild",0});
set_light(1);
short_desc="Southern wall";

long_desc=
    "This is the southern part of the town. " +
    "To the south is the city-wall, to the north you can see a house entrance " +
    "The entrance door is to the southeast. " +
    "There are people on the street and they seem to be busy.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/town/wall2", "west",
    "players/tegerl/jabberwocky/rooms/town/house10", "north",
    "players/tegerl/jabberwocky/rooms/town/street1", "east",
  });

items=({
    "city-wall","The wall is very old and needs to be repaired. It seems to be very desolate",
    "wall","The wall is very old and needs to be repaired. It seems to be very desolate",
    "people","There are people, and they all seem to be very busy",
    "houses","Along the roads there are many houses, some are shops",
});

smell = "The air could be fresh and clean, if that town wouldn't be there. So you can only smell waste and dump.";
  
  }


::reset(arg);
replace_program("room/room");
}