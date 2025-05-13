

/* Coded by Tegerl, 28.3.1995 */
/* rooms/castle/crowd */


inherit "room/room";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_light(1);
short_desc="A crowd near tournament place";

long_desc=
    "You are now south of the tournament place. " +
    "There is a big crowd here that prevents you from seeing " +
    "what happens to the north. You only can hear the noise of " +
    "lances meeting shields and crushing bones and the cries " +
    "of the defeated knights.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/castle/tourn", "north",  
    "players/tegerl/jabberwocky/rooms/town/street6", "south",
  });

items=({
    "crowd","There are a lot of people, they all came here to see the tournament",
    "people","They all seem to watch the tournament",
    });

smell = "The air could be fresh and clean, if that town wouldn't be there. So you can only smell waste and dump.";
  
  }

