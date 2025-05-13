inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int found;

int d_g(string arg){
  if(!arg || arg != "tome"){
    write("Get what?\n");
    return 1;
  }
  if(!present("#QGLOVES#",TP)){
    write("You burn your hands!\n");
    TP->hit_player(20);
    return 1;
  }
  else if(found != 1){
    write("You grab the tome!\n");
    move_object((clone_object("/players/brainsprain/bis/quest/qtome.c")),TP);
    long_desc =
      "A long rotting altar sits in the center of the room, with an old, "+
      "yellowing altar cloth on it.  A pillar of flame rises from the "+
      "floor and to the ceiling along the northern wall.  Sooty handprints "+
      "dot the wall in several places.\n";
    found =1;
    return 1;
  }
  if (found == 1){
    write("There is no tome here.\n");
    return 1;
  }
}

void reset(int arg) {
  ::reset(arg);
  if(arg) return;  
  short_desc = "A secret chapel";
  long_desc =
    "A long, rotting altar sits in the center of the room with a massive, "+
    "golden tome floating mysteriously above the altar.  A pillar of flame "+
    "rises from the floor and to the ceiling along the northern wall. "+
    "Sooty handprints dot the wall in several places.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-23.c","north",
  });
  items = ({
    "room",
    "A secret chapel",
    "floor",
    "It is marked by scorches",
    "wall",
    "the northern wall",
    "ceiling",
    "The pillar of flame rises up to it",
    "altar",
    "A stone altar",
    "tome",
    "A magic tome",
    "pillar",
    "A pillar of fire",
    "handprints",
    "Sooty handprints on the wall",
  });
  found = 100;
}
void init(){
  ::init();
  add_action("d_g","get");
}

