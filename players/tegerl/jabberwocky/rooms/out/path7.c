

/* Coded by Tegerl, 7.3.1995 */
/* rooms/out/path7 */


inherit "room/room";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_light(1);
short_desc="A dim forest";

long_desc=
    "The path continues, the forest gets darker. " +
    "As you look into the depths of the forest you can see footprints leading " +
    "southeast, straight into the weird woods.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/out/path8", "northeast",
    "players/tegerl/jabberwocky/rooms/out/forest1","southeast",
    "players/tegerl/jabberwocky/rooms/out/cross","southwest",

    });

items=({
    "forest","The forest is very dark, you wonder what creatures could live in it. You decide to stay away",
    "path","The ground is muddy and you can see that it has been used lately",
    "footprints","The footprints only lead into the forest, but none out",
    "trails","As you look at the trails you think that maybe a carriage used this path",
    "footprint","The footprint is one of many leading into the forest",
    "trail","As you look at the trail you think that maybe a carriage used this path",
});

smell = "The air is damp and you can smell rotten trees.";
  
  }


