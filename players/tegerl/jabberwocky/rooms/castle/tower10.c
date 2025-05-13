

/* Tegerl, 22.3.1995 */
/* rooms/castle/tower10 */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"

void reset(int arg) 
{
if (!arg);
{
clone_list=({1,1,"chancellor",PATH+"monsters/canc",0,
             2,1,"pillow",PATH+"obj/pillow",0});
set_light(1);
short_desc="In a tower";

long_desc=
    "You are in the highest room of the tower. " +
    "The chancellor of this country lives here. It is said that he is not very loyal.  " +
    "There is a window and stairs are leading down.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/castle/tower9", "down",
  });

items=({
    "castle","It is a very old castle and it is in a very bad contition",
    "walls","The walls look very ugly and they seem to be very weak",
    "wall","The wall looks very ugly and it seems to be very weak",
    "stairs","The stairs are very narrow, take care",
    "stair","The stairs are very narrow, take care",
    "window","It is a small window, but it offers a great view",
    "view","You can see the town",
    "town","It is a really dirty town",
});

smell = "The air is a bit fresher up here.";
  
  }

::reset(arg);
replace_program("room/room");
}