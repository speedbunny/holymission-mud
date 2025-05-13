

/* Coded by Tegerl, 8.3.1995 */
/* rooms/town/wall12 */


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
short_desc="Southern wall";

long_desc=
    "This is the northeastern part of the town. " +
    "To the east and north is the city-wall, there is a road to the west and the south. " +
    "There are people on the street and they seem to be busy.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/town/street10", "west",
    "players/tegerl/jabberwocky/rooms/town/wall11", "south",
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
