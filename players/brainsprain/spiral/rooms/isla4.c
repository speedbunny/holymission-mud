inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
int randomizer;
void reset(int arg){

  short_desc = "Swaying Palm Trees";
  long_desc =
"A recent tropical storm has blown several palm trees into the path.  "+
"Someone has chopped a path through the trees.  The ground is littered "+
"with shards of bark and wood.  The smell of sulfur is crisp in the air.\n";
  set_light(1);
  dest_dir = ({
    sr+"/isla5","north",
    sr+"/isla3","south",
  });
  items = ({
    "path",
    "A path through the jungle",
    "bark",
    "Bark off of the fallen trees",
    "wood",
    "Pieces of the recently fallen trees",
    "trees",
    "Palm trees",
  });
randomizer = random(6);
if (randomizer ==4){
clone_list = ({ 1, 1, "monster", sm+"/badger.c", 0 });
}
if (randomizer == 5){
clone_list = ({ 1, 1, "monster", sm+"/goblin.c", 0 });
}
if (randomizer == 3){
clone_list = ({ 1, 1, "monster", sm+"/orc_guard.c", 0 });
}

   ::reset(arg);
    replace_program("room/room");

}

