#include "/players/goldsun/stand.h"

#define EAST TP->move_player("west#players/goldsun/lank/room/forest5");
#define SOUTH TP->move_player("south#players/goldsun/lank/room/forest8");
#define SE TP->move_player("southeast#players/goldsun/lank/room/forest7");

inherit "/players/goldsun/lank/room/genForest";
reset(arg) {
 if (!arg){
  clone_list=({1,1,"dragon","/players/goldsun/lank/monster/red_dragon",0});
 }
 ::reset(arg);
 
}

 init() {
  ::init();
  add_action("edge","edge");
  add_action("south","south");
  add_action("east","east");
  add_action("southeast","southeast");
  }

int southeast(){
 if (is_se){
  SE
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


int east(){
 if (is_e){
  EAST
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

  if (str=="east" || str=="e"){
    if (!is_e){
      add_exit("east");
      "/players/goldsun/lank/room/forest5"->add_exit("west");
    }
     else write(info);
    write(info2);
    say(info3);
    east();
   return 1;
  }
  if (str=="south" || str=="s"){
    if (!is_s){
       add_exit("south");
       "/players/goldsun/lank/room/forest8"->add_exit("north");
    }
     else write(info);
    write(info2);
    say(info3);
    south();
  return 1;
  }
  if (str=="southeast" || str=="se"){
    if (!is_se){
      add_exit("southeast");
      "/players/goldsun/lank/room/forest7"->add_exit("northwest");
    }
	else  write(info);
    write(info2);
    say(info3);
    southeast();
    return 1;
   }
  write("How strange direction.\n");
  write("There is a huge tree this way.\n");
  return 1;
}

