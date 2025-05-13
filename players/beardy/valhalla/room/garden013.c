#define WAYS ({ ROOM + "garden018","north",ROOM + "garden012","west",ROOM + "garden014","east",ROOM + "garden008","south"})
#define SPEC_DESC "Now you are in the center and near the well. It looks very new\nand perhaps you can climb down it.\n"
#include "garden"

void init()
{ ::init();
  add_action("myclimb","climb");
}

int myclimb(string str)
{ if(!str) return 0;
  if(str!="down")
  { write("Where do you want to climb ?");
    return 1;
  }
  else
  transfer(this_player(),"/players/beardy/valhalla/room/well001");
  command("look",TP);
  tell_room(TO,TP->query_name()+" leaves down.\n");

  return 1;
}
