

/* Coded by Tegerl, 9.3.1995 */
/* rooms/town/street7 */


inherit "room/room";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_light(1);
short_desc="A road in town";

long_desc=
    "You are on a road in town. " +
    "There are not that many people, so it is almost quit here. " +
    "The road leads in east west direction, but there is also a house " +
    "entrance to the south.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/town/street8", "west",
    "players/tegerl/jabberwocky/rooms/town/street4", "east",
    "players/tegerl/jabberwocky/rooms/town/house16", "south",
  });

items=({
    "people","There are only very few people",
    "houses","Along the roads there are many houses, some are shops",
});

smell = "The air could be fresh and clean, if that town wouldn't be there. So you can only smell waste and dump.";
  
  }

