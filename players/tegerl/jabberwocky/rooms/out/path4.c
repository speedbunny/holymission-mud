/* Coded by Tegerl, 6.3.1995 */
/* rooms/out/path4 */

inherit "room/room";
void reset(int arg)
{
object ff;
::reset(arg);

if (!present("fishfinger",this_object())) {
  ff=clone_object("/players/tegerl/jabberwocky/monsters/ff");
  move_object(ff,this_object());
}

if (arg) return;
set_light(1);
short_desc="A dim path in forest";

long_desc=
    "You are still on a dim path in forest. " +
    "To path continues to the north and the south. But which way to go? " +
    "There are only a few footprints and you wonder why people don't travel " +
    "that much in this area.\n";

dest_dir=({
    "players/tegerl/jabberwocky/rooms/out/path3", "south",
    "players/tegerl/jabberwocky/rooms/out/cross", "north",
    });

items=({
    "forest","The forest dark here and weird, so you decide to stay away",
    "path","The ground is muddy and you can see that it is barely used",
    "footprints","Yes, footprints, and they are human",
    
});

smell = "You can still smell damp rotten trees.";
  
  }


