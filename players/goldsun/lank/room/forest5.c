#include "/players/goldsun/stand.h"

#define WEST TP->move_player("west#players/goldsun/lank/room/forest6");
#define SOUTH TP->move_player("south#players/goldsun/lank/room/forest7");
#define SW TP->move_player("southwest#players/goldsun/lank/room/forest8");
#define NE TP->move_player("northeast#players/goldsun/lank/room/coast19");

inherit "/players/goldsun/lank/room/genForest";
reset(arg) {
 ::reset(arg);
}

 init() {
  ::init();
  add_action("edge","edge");
  add_action("south","south");
  add_action("west","west");
  add_action("southwest","southwest");
  add_action("northeast","northeast");
  }

int northeast(){
 if (is_ne){
  NE
  return 1;
  }
 return 0;
}

int southwest(){
 if (is_sw){
  SW
  return 1;
 }
 return 0;
}

int west(){
 if (is_w){
  WEST
  return 1;
 }
 return 0;
}


int south(){
 if (is_s){
  SOUTH
  return 1;
  }
 return 0;
}




int edge(string str){

string info,info2,info3;

  if (!str){
   write("Edge where ?");
   return 1;
  }
  info="But there is already a passage this way.\n";
  info2="Crack\n"
	+"Crack\n"
	+"You are edging to the "+str+".\n";
  info3="Crack\n"
	+"Crack"
	+OPN+" is edging to the "+str+".\n";

  if (str=="west" || str=="w") { 
     if (!is_w){
        add_exit("west");
        "/players/goldsun/lank/room/forest6"->add_exit("east");
     }
      else write(info);
     write(info2);
     say(info3);
     west();
   return 1;
   }
  if (str=="south" || str=="s"){
    if (!is_s){
        add_exit("south");
 	"/players/goldsun/lank/room/forest7"->add_exit("north");
    }
     else write(info);
    write(info2);
    say(info3);
    south();
  return 1;
  }
  if (str=="southwest" || str=="sw"){
    if (!is_sw){
      add_exit("southwest");
      "/players/goldsun/lank/room/forest8" ->add_exit("northeast");
       }
	else   write(info);
    write(info2);
    say(info3);
    southwest();
    return 1;
    }
   if (str=="northeast" || str=="ne"){
    if (!is_ne){
      add_exit("northeast");
       }
	else  write(info);
    write(info2);
    say(info3);
    northeast();
    return 1;
   }
  write("How strange direction.\n");
  write("There is a huge tree this way.\n");
  return 1;
}

