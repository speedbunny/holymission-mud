#include "/players/gareth/define.h"
inherit "room/room";
int opened, searched, moved;
object drow;

void reset(int arg){
  ::reset(arg);
  moved = 0;
  if(!arg) {

  set_light(1);
  short_desc = "commander's room";
  long_desc = 
   "This room is paneled with wood, and a dusty carpet covers\n"+
   "the floor. It contains a bed, table, and a large heavy desk\n"+ 
   "sits in the center of the room. Several wooden chairs are grouped\n"+ 
   "north of the desk. Behind the desk is a large plush chair, while\n"+
   "behind the chair on the south wall is a mounted dragon's head.\n"+
   "Four large painted urns stand in the corners of the room. On\n"+
   "both sides of the desk are stone pedestals with stone statues of\n"+
   "of some type of winged beasts.\n";
  
  items = ({
    "bed","An ordinary bed, used for sleeping on",
    "table","table used for eating on, it's covered with linen",
    "carpet","It's large and dusty",
    "desk","A very large wooden desk, it looks like it weighs tons",
    "chair","A large plush chair, it look comfortable",
    "chairs","ordinary wooden chairs that are grouped together",
    "head","The mounted head of a gold dragon",
    "pedestals","Stone pedestals that are the base of statues",
    "statues","Statues of dragons, one has its head pointed DOWN",
    "urns","simple urns made of gold, copper, silver and bronze",
    });

	MO((CO(MON+"drow_w")),TO);
    
  dest_dir = ({
    ETOWN+"lvl4d","down",
             });

}
}
  void init() {
    ::init();
    AA("_search","search");
    AA("_open","open");
    AA("_move","move");
  }

  status _open(string str){
      if(str!="desk" && str!="desk")
          return 0;

      if(!opened) {
          write("The desk drawer is opened.\n");
          TR(CO(ITEM+"comp_heal_potion"), TP);

          opened = 1;
          return 1;
}       
          write("The desk drawer is already opened.\n");
          return 1;
}

  status table(string str){
      if(!str || str!="table"){
          NF("search what?\n");
          return 0;
      }
      if(!searched){
          write("You find some food.\n");
          TR(CO(ITEM+"burger"), TP);
          searched = 1;
          return  1;
}
  
  write("You search but the table is clear.\n");
     return 1;

}

  string desk() {
    if(!opened)
        return "The drawer is closed";
    else
        return "The drawer has been open prior to your arrival";
}
  int _move(string str) {
      if(!str || str!="statues") {
          NF("move what?\n");
          return 0;
     }
     if(moved){
        write("The head has head has already been moved, sorry\n");
        return 1;
     }
     write(" There's a grinding sound, a hidden exit appears to the north.\n");
     dest_dir = ({
       ETOWN+"tr1","north",
       ETOWN+"lvl4d","down",
                });

    moved = 1;
    AA("north","north");
    return 1;
}
    int north() {
        TP->move_player("north#/players/gareth/evil/town/tr1");
        return 1;
}
