#include "/players/goldsun/stand.h"

#define EAST TP->move_player("west#players/goldsun/lank/room/forest7");
#define WEST TP->move_player("east#players/goldsun/lank/room/merlintower");
#define NORTH TP->move_player("north#players/goldsun/lank/room/forest6");
#define NE TP->move_player("northeast#players/goldsun/lank/room/forest5");

inherit "/players/goldsun/lank/room/genForest";
reset(arg) {
 ::reset(arg);
}

 init() {
  ::init();
  add_action("edge","edge");
  add_action("north","north");
  add_action("east","east");
  add_action("west","west");
  add_action("northeast","northeast");
  }


int northeast(){
 if (is_ne){
  NE
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

  if (str=="west" || str=="w") { 
     if (!is_w) add_exit("west");
      else write(info);
     write(info2);
     say(info3);
     west();
   return 1;
   }
  if (str=="north" || str=="n") {
    if (!is_n){
	  add_exit("north");
	  "/players/goldsun/lank/room/forest6"->add_exit("south");
    }
     else write(info);
    write(info2);
    say(info3);
    north();
   return 1;
   }
  if (str=="east" || str=="e"){
    if (!is_e){
        add_exit("east");
	"/players/goldsun/lank/room/forest7"->add_exit("west");
    }
     else write(info);
    write(info2);
    say(info3);
    east();
   return 1;
  }
  if (str=="northeast" || str=="ne"){
    if (!is_ne){
      add_exit("northeast");
      "/players/goldsun/lank/room/forest5"->add_exit("southwest");
       }
	else   write(info);
    write(info2);
    say(info3);
    northeast();
    return 1;
    }
  write("How strange direction.\n");
  write("There is a huge tree this way.\n");
  return 1;
}

