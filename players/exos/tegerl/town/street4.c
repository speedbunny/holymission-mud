

/* Coded by Tegerl, 8.3.1995 */
/* rooms/town/street4 */


inherit "room/room";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_light(1);
short_desc="A crossing in town";

long_desc=
    "Here is a crossing of two streets. " +
    "To the north is the king's castle and tournament place. " +
    "To the south you will come back to the entrance door. " +
    "The crossing road leads to other parts of the town.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/town/street7", "west",
    "players/tegerl/jabberwocky/rooms/town/street5", "north",
    "players/tegerl/jabberwocky/rooms/town/street9", "east",
    "players/tegerl/jabberwocky/rooms/town/street3", "south",
  });

items=({
    "entrance","The entrance is heavily guarded. There is one tower left and right of the door",
    "door","The big door is made of wood, but it has metal fittings",
    "people","There are people, and they all seem to be very busy",
    "houses","Along the roads there are many houses, some are shops",
});

smell = "The air could be fresh and clean, if that town wouldn't be there. So you can only smell waste and dump.";
  
  }

