/* Coded by Tegerl, 7.3.1995 */
/* rooms/out/path5 */

inherit "room/room";
void reset(int arg)
{
::reset(arg);

if (arg) return;
set_light(1);
short_desc="A dim path in forest";

long_desc=
    "You are still on a dim path in the forest. " +
    "But you can almost feel, that the forest ends soon. It isn't that weird " +
    "anymore. It is the first time that you hear birds sing in this wood.\n";

dest_dir=({
    "players/tegerl/jabberwocky/rooms/out/path6", "west",
    "players/tegerl/jabberwocky/rooms/out/cross", "east",
    });

items=({
    "forest","The forest is not that dark here, but you decide to stay away anyway",
    "path","The ground is muddy and you can see that it has been used lately",
    "footprints","Yes, footprints, and they are human",
    "trails","As you look at the trails you think that maybe a carriage used this path",
});

smell = "The air is a bit fresher here but you can still smell damp rotten trees.";
  
  }


