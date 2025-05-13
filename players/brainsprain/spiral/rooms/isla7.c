inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
int randomizer;
void reset(int arg){
  
  short_desc = "Swaying Palm Trees";
  long_desc =
    "The forest begins to clear out here and you can see the smoke rise in "+
    "the distance.  The air is becoming hazy and the smell of sulfur is "+
    "distinct.  The few trees that still line the path are swaying madly "+
    "in the wind.\n";
  set_light(1);
  dest_dir = ({
    sr+"/isla6","west",
    sr+"/isla8","east",
  });
  items = ({
    "forest",
    "It is filled with massive palm trees",
    "path",
    "A path through the jungle",
    "smoke",
    "The smoke rising from a volcano",
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
