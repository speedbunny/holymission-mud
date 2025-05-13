inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
int randomizer;
void reset(int arg){
  
  short_desc = "Cave entrance";
  long_desc =
    "A mountainside rises up to the north.  On the side of the mountain is "+
    "a cave.  The dark opening is much taller than the average human and "+
    "is easily passable.  The trees have gotten thick here and it is impossible "+
    "to see more than ten feet into the trees.\n";
  set_light(1);
  items = ({
    "mountainside",
    "A huge mountainside rises up to the north",
    "mountain",
    "A huge mountainside rises up to the north",
    "cave",
    "A cave leading into the mountain",
    "opening",
    "A cave leading into the mountain",
    "trees",
    "Palm trees",
  });
  dest_dir = ({
    sr+"/room101","enter",
    sr+"/isla8","south",
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
