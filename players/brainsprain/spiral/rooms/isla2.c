inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
int randomizer;
void reset(int arg){

  short_desc = "Swaying Palm trees";
  long_desc =
"  Palm trees sway back and forth.  A gentle breeze caresses your cheek\n"+
"  and cools the otherwise humid air.  The sounds of some strange bird can\n"+
"  be heard from the trees overhead.  The grass is about knee high and very\n"+
"  green.\n"+
"\n";
  set_light(1);
  dest_dir = ({
    sr+"/isla1","west",
    sr+"/isla3","north",
    sr+"/isla6","south",
  });
  items = ({
    "grass",
    "It is about knee high",
    "bird",
    "A sea bird",
    "breeze",
    "A cool breeze blows through your hair",
    "trees",
    "Palm trees",
    "pools",
    "All sorts of life teem in these pools",
    "crabs",
    "Aren't they cute!",
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
