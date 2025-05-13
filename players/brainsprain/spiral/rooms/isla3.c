inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
int randomizer;
void reset(int arg){

  short_desc = "Swaying Palm Trees";
  long_desc =
"Vines hang down into the path as it winds through the dense jungle.  A "+
"monkey swings in the trees high overhead and screeches as he smells "+
"food.  A deep, rumbling sound can be heard in the distance.  A strange "+
"sulfurous scent fills the air.\n";
  set_light(1);
  dest_dir = ({
    sr+"/isla4","north",
    sr+"/isla2","south",
  });
items = ({
  "trees",
  "Huge, old growth, trees",
  "path",
  "A path leading through the jungle",
  "jungle",
  "The jungles of spiral island",
  "island",
  "Spiral Island",
  "spiral island",
  "The island you are on",
  "vines",
  "These vines are as thick as a human arm",
  "monkey",
  "A gibbering gibbon",
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
