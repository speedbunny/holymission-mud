

/* Coded by Tegerl, 6.3.1995 */
/* rooms/out/cott1 */


inherit "room/room";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_light(1);
short_desc="A small cottage";

long_desc=
    "Your eyes slowly get used to the dim light. " +
    "This is the first room of a cottage. It is equipped as workshop. " +
    "You are sure that this is the place where those barrels are made. " +
    "To the southwest you can hear voices.\n";

/* exits */
dest_dir=({
    "players/tegerl/jabberwocky/rooms/out/clear", "east",
    "players/tegerl/jabberwocky/rooms/out/cott2", "southwest",
    });

/* descriptions */
items=({
    "cottage","It is a very small and dirty cottage",
    "workshop","In this workshop is everything you need to make barrels",
    "barrels","You can see various barrels, completed and unfinished ones",  
});

/* no proberties */

/* smell */
smell = "You smell work, be quick and go before you have to work too.";
  
  }

