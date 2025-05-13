inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
int randomizer;
void reset(int arg){
  
  short_desc = "Swaying Palm Trees";
  long_desc =
    "The wind is beginning to pick up and the trees are thrashing back and "+
    "forth.  Along the sides of the path several flowers grow, they are like "+
    "nothing you have ever seen.  There is a small hole in the ground along "+
    "the eastern side of the path.\n";
  set_light(1);
  dest_dir = ({
    sr+"/isla2","north",
    sr+"/isla7","east",
  });
  items = ({
    "path",
    "A path through the jungle",
    "jungle",
    "It is impassable on all sides",
    "trees",
    "Huge oak trees",
    "ground",
    "It is littered with garbage",
    "garbage",
    "You can not tell what it is",
    "flowers",
    "Beautiful, red flowers with yellow centers",
    "hole",
    "A badger hole"
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
