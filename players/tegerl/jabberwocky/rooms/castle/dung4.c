

/* Tegerl, 22.3.1995 */
/* rooms/castle/dung4 */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"

void reset(int arg) 
{

if (!arg);
{
clone_list=({1,2,"guard",PATH+"monsters/guard1",0});

set_light(0);
short_desc="In a dungeon";

long_desc=
    "You are in a dungeon. The walls seem to be very old. " +
    "The air is wet and cold in here. " +
    "This seems to be the way to the castle's prison.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/castle/dung5", "down",
    "players/tegerl/jabberwocky/rooms/castle/dung3", "south",
  });

items=({
    "castle","It is a very old castle and it is in a very bad contition",
    "walls","The walls look very ugly",
    "wall","The wall looks very ugly",
   
});

smell = "You smell waste and dump.";
  
  }

::reset(arg);
replace_program("room/room");
}