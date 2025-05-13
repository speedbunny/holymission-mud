

/* Coded by Tegerl, 8.3.1995 */
/* rooms/out/path9 */


inherit "room/room";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_light(1);
short_desc="End of forest";

long_desc=
    "You have reached the end of the forest now. " +
    "In the distance you can see the grey walls of a town. " +
    "Maybe you can find some protection there.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/out/path8", "southwest",
    "players/tegerl/jabberwocky/rooms/out/place1", "northeast",
    });

items=({
    "forest","The forest ends here",
    "path","The ground is muddy and you can see that it has been used lately",
    "footprints","Yes, footprints, and they are human",
    "town","You can't see the town from here, the walls are in between",
    "walls","The walls are to far away to have a good look",
    "wall","The wall is to far away to have a good look",
});

smell = "The air is damp and you can smell rotten trees.";
  
  }


