inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
int randomizer;

enter(arg){
  if(arg!="portal" && arg!="orb"){
    write ("Enter What?\n");
  }
  if(arg == "portal" || arg == "orb"){
    write ("You have arrived in Towpath.\n");
    this_player()->move_player("enter#/players/brainsprain/bis/rooms/tran.c");
    return 1;
  }
}

void reset(int arg){
  
  short_desc = "Dead end";
  long_desc =
    "The huge trunk of a palm tree has fallen into the path and extends as far "+
    "as you can see into the forest.  Several other logs make it impossible "+
    "to use the path.  The brush on either side of the path is so thick that "+
    "any attempts to bushwack are doomed to fail.  A glowing orb about seven "+
    "feet in diameter floats above the ground.\n";
  set_light(1);
  dest_dir = ({
    sr+"/isla4","south",
  });
  items = ({
    "ground",
    "It is littered with broken pieces of tree",
    "jungle",
    "It is impassable on all sides of the path",
    "path",
    "A path through the jungle",
    "orb",
    "A floating portal, why don't you try entering it",
    "trunk",
    "A huge tree trunk in the middle of the path",
    "logs",
    "Mediums size dead-falls",
    "brush",
    "Thick pricker-bushes and nettles",
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
  
}
void init(){
  ::init();
  add_action("enter","enter");
}
