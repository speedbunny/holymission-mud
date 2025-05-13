

/* Coded by Tegerl, 8.3.1995 */
/* rooms/town/street3 */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"
void reset(int arg) 
{
if (!arg);
{
clone_list=({1,1,"fasstaubis",PATH+"monsters/fass",0,
            2,3,"inhabitant",PATH+"monsters/sman",0,
            3,1,"woman",PATH+"monsters/swoman",0,
            4,1,"child",PATH+"monsters/schild",0});
set_light(1);
short_desc="A road in town";

long_desc=
    "You are on a road in town. " +
    "The street leads further north and south. " +
    "To the west is a shop and to the east you can see a house entrance. " +
    "There are people on the street and they seem to be busy.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/town/shop", "west",
    "players/tegerl/jabberwocky/rooms/town/street4", "north",
    "players/tegerl/jabberwocky/rooms/town/house1", "east",
    "players/tegerl/jabberwocky/rooms/town/street2", "south",
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