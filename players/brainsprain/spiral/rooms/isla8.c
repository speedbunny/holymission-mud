inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
int randomizer;
void reset(int arg){
  
  short_desc = "Clearing";
  long_desc =
    "A clearing opens up providing a better view of the volcano.  The smoke "+
    "does not come from the volcano itself but from a bonfire halfway up "+
    "its side.  In fact, the volcano seems to be extinct.  A yellow rock "+
    "structure that is in the shape of a face sits on the side of the mountain.\n";
  set_light(1);
  dest_dir = ({
    sr+"/isla7","west",
    sr+"/isla9","north",
  });
  items = ({
    "clearing",
    "A clearing in the path",
    "path",
    "A path through the jungle",
    "volcano",
    "An extinct volcano",
    "bonfire",
    "Someone is celebrating on the side of the volcano",
    "structure",
    "A carving of the face of some man",
    "smoke",
    "The smoke rising from a campfire",
    "face",
    "You do not recognize the face",
    "yellow rock",
    "it could be a massive sulfur deposit",
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
