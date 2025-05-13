

/* Tegerl, 22.3.1995 */
/* rooms/castle/dung5 */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"

void reset(int arg) 
{

if (!arg);
{
clone_list=({1,5,"prisoner",PATH+"monsters/pris",0});

set_light(0);
short_desc="In prison";

long_desc=
    "You are in the prison now. The walls seem to be very old. " +
    "The air is wet and cold in here. " +
    "It is a very lousy place.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/castle/dung6", "south",
    "players/tegerl/jabberwocky/rooms/castle/dung4", "up",
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