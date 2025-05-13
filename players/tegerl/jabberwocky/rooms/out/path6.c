/* Coded by Tegerl, 7.3.1995 */
/* rooms/out/path6 */

inherit "room/room";
void reset(int arg)
{
::reset(arg);

if (arg) return;
set_light(1);
short_desc="A path";

long_desc=
    "The area is much friendlier here. The sun shines through " +
    "the few trees and to the west you can see a lake. " +
    "To the east lies a dim forest.\n";

dest_dir=({
    "players/tegerl/jabberwocky/rooms/out/lake1", "west",
    "players/tegerl/jabberwocky/rooms/out/path5", "east",
    });

items=({
    "forest","There is no forest, only a few trees are here",
    "path","The ground is muddy and you can see that it has been used lately",
    "footprints","Yes, footprints, and they are human",
    "trails","As you look at the trails you think that maybe a carriage used this path",
    "trees","Those trees belong to the forest that lies to the east",
    "lake","It is to far away, you should be closer to have a good look",
});

smell = "The air is a bit fresher here but you can still smell damp rotten trees.";
  
  }


