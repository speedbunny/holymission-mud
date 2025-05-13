

/* Coded by Tegerl, 8.3.1995 */
/* rooms/town/street9 */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"
void reset(int arg) 
{

if (!arg);
{
clone_list=({1,2,"guard",PATH+"monsters/guard",0,
            2,3,"inhabitant",PATH+"monsters/sman",0});

set_light(1);
short_desc="In the city";

long_desc=
    "You are on a road in town. " +
    "The street leads further west and east. " +
    "To the north is a pub and to the south you can see a house entrance. " +
    "There are people on the street and they seem to be busy.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/town/street4", "west",
    "players/tegerl/jabberwocky/rooms/town/pub", "north",
    "players/tegerl/jabberwocky/rooms/town/street10", "east",
    "players/tegerl/jabberwocky/rooms/town/house9", "south",
  });

items=({
  
    "people","There are people, and they all seem to be very busy",
    "houses","Along the roads there are many houses, some are shops",
});

smell = "The air could be fresh and clean, if that town wouldn't be there. So you can only smell waste and dump.";
  
  }


::reset(arg);
replace_program("room/room");
}