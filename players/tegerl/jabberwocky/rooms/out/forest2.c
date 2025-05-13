

/* Tegerl, 8.3.1995 */
/* rooms/out/forest2 */


inherit "room/room";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_light(0);
short_desc="A dark forest";

long_desc=
    "You are now deep in the forest. " +
    "The footprints end here, there is no other way out than the one you came from. " +
    "The forest almost overwhelms you with its dark damp thicket. " +
    "There is a very ugly corpse lying on the floor.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/out/forest1", "north",
    });

items=({
    "forest","The forest is very dark and surrounds you. You are lost here",
    "footprints","The footprints end here",
    "corpse","This is a very ugly corpse.\n"
           + "It isn't dead that long, because\n"
           + "you can still realize a face, but\n"
           + "there is no meat on the bones anymore.\n"
           + "A horrible monster must have done this.\n"
           + "Was it Jabberwocky ???\n"
});

smell = "The air is damp and you can smell rotten trees.";
  
  }

