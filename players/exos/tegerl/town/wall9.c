

/* Coded by Tegerl, 8.3.1995 */
/* rooms/town/wall9 */


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
short_desc="Southeastern corner of town";

long_desc=
    "This is the southeastern corner of town. " +
    "To the southeast is the city-wall, to the northwest you can see a house entrance " +
    "There are people on the street and they seem to be busy.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/town/house5", "northwest",
    "players/tegerl/jabberwocky/rooms/town/wall10", "northeast",
    "players/tegerl/jabberwocky/rooms/town/wall8", "west",
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
