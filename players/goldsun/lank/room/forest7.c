#include "/players/goldsun/stand.h"

#define WEST TP->move_player("east#players/goldsun/lank/room/forest8");
#define NORTH TP->move_player("north#players/goldsun/lank/room/forest5");
#define NW TP->move_player("northwest#players/goldsun/lank/room/forest6");

inherit "/players/goldsun/lank/room/genForest";
reset(arg) {
 if (!arg){
  clone_list=({1,1,"dragon","/players/goldsun/lank/monster/white_dragon",0});
 }
 ::reset(arg);
}

 init() {
  ::init();
  add_action("edge","edge");
  add_action("north","north");
  add_action("west","west");
  add_action("northwest","northwest");
  }


int northwest(){
 if (is_nw){
  NW
  return 1;
 }
 return 0;
 }


int north(){
 if (is_n){
  NORTH
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
	 "/players/goldsun/lank/room/forest8"->add_exit("east");
     }
      else write(info);
     write(info2);
     say(info3);
     west();
   return 1;
   }
  if (str=="north" || str=="n"){
    if (!is_n){
      add_exit("north");
      "/players/goldsun/lank/room/forest5"->add_exit("south");
    }
     else write(info);
    write(info2);
    say(info3);
    north();
  return 1;
  }
  if (str=="northwest" || str=="nw"){
    if (!is_nw){
      add_exit("northwest");
      "/players/goldsun/lank/room/forest6"->add_exit("southeast");
       }
	else   write(info);
    write(info2);
    say(info3);
    northwest();
    return 1;
   }
  write("How strange direction.\n");
  write("There is a huge tree this way.\n");
  return 1;
}

