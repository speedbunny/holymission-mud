

/* Coded by Tegerl, 8.3.1995 */
/* rooms/town/street6 */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"

void reset(int arg) 
{
if (!arg);
{
clone_list=({1,2,"guard",PATH+"monsters/guard2",0});
set_light(1);
short_desc="Northern end of town";

long_desc=
    "This is the northern end of the town. " +
    "Further north is only the tournament place and to the " +
    "east you can see a big castle.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/castle/crowd", "north",
    "players/tegerl/jabberwocky/rooms/castle/yard", "east",
    "players/tegerl/jabberwocky/rooms/town/street5", "south",
  });

items=({
    "castle","It is a big old castle, but it is in a very bad condition",   
    "place","You are to far away, come closer to see it",
});

smell = "The air could be fresh and clean, if that town wouldn't be there. So you can only smell waste and dump.";
  
  }

::reset(arg);
replace_program("room/room");
}