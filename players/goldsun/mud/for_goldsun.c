#include "/players/goldsun/stand.h"
#define PPATH "/players/goldsun/lank/room/"

string msgs,first;
status is_n,is_s,is_w,is_e,is_ne,is_se,is_nw,is_sw,is_first;
int num;

inherit "/room/room";
reset(arg) {
  if (arg) return;
    set_light(1);
    short_desc="In the deep, gloomy forest";
    long_desc=
 "You are in the deep gloom of the forest. Massive trees wrap themselves\n"
+"close about you. A tangle of shadows and murky darkness, screened away\n"
+"from the world outside by trees and scrub that are twisted and interwoven.\n"
+"The sun here shines in long steamers through cracks in the heavy branches.\n"
+"You have to 'edge' through dense murky bushes.\n";

   msgs="\n";
   is_first=1;
   num=0;
   is_n=0;
   is_e=0;
   is_s=0;
   is_w=0;
   is_ne=0;
   is_se=0;
   is_nw=0;
   is_sw=0;
   no_obvious_msg=msgs;
    smell="You feel common fresh sea air.";
    items=({
         "grass","The grass is waving in the wind",
	 "shadow","A shadow of huge gnarled tree",
	 "cracks","A cracks in the heavy branches",
	 "crack","A crack in the heavy branches",
	 "branches","The branches of trees with spiny leaves",
	 "leaf","A spiny leaf from gnarled oak tree",
	 "leaves","A spiny leaves from many trees",
	 "sun","The sun here shines in long steamers through cracks"
		+" in the branches ",
	 "tree","An unknown tree. You have never seen such one",
	 "trees","The unknown trees. You have never seen such heavy and vast"
				+" trees",
	 "several trees","The unknown trees. You have never seen such trees",
	 "peak","A peak to the east.\n"+
	        "It is named Lankpeak and it is very tall",
	 "tall peak","A peak to the west.\n"+
		   "It is named Lankpeak",
	 "Lankpeak","The peak is very tall",
	 "tall Lankpeak","A peak to the west",
	 "mountains","The Lankbourg mountains to the west",
	 "Lankbourg mountains","The mountains to the west"
       });

 ::reset(arg);

}

 init() {
  ::init();
  add_action("_listen","listen");
  add_action("climb","climb");
  add_action("cut","cut");
  add_action("cut","chop");
  add_action("edge","edge");

  add_action("north","north");
  add_action("north","n");
  add_action("south","s");
  add_action("south","south");
  add_action("east","east");
  add_action("east","e");
  add_action("west","west");
  add_action("west","w");
  add_action("northeast","ne");
  add_action("northeast","northeast");
  add_action("northwest","northwest");
  add_action("northwest","nw");
  add_action("southwest","southwest");
  add_action("southwest","sw");
  add_action("southeast","southeast");
  add_action("southeast","se");
  }

int southeast(){
 if (is_se){
  this_player()->move_player("southeast#players/goldsun/lank/room");
  return 1;
  }
 return 0;
}

int soutwest(){
 if (is_sw){
  this_player()->move_player("southwest#players/goldsun/lank/room");
  return 1;
 }
 return 0;
}

int northwest(){
 if (is_nw){
  this_player()->move_player("nortwest#players/goldsun/lank/room");
  return 1;
 }
 return 0;
 }

int northeast(){
 if (is_ne){
  this_player()->move_player("northeast#players/goldsun/lank/room/forest2");
  return 1;
 }
 return 0;
}

int south(){
 if (is_s){
  this_player()->move_player("south#players/goldsun/lank/room/");
  return 1;
  }
 return 0;
}


int north(){
 if (is_n){
  this_player()->move_player("north#players/goldsun/lank/room/coast9");
  return 1;
 }
 return 0;
 }
int west(){
 if (is_w){
  this_player()->move_player("west#players/goldsun/lank/room/coast15");
  return 1;
 }
 return 0;
}

int east(){
 if (is_e){
  this_player()->move_player("east#players/goldsun/lank/room/");
  return 1;
 }
 return 0;
}


int set_exit(string dir){

 if (is_first){ 
   is_first=0;
   first=dir;
   num+=1;
  }

 switch(dir){

  case "north":
        is_n=1;
        break;
  case "east":
	is_e=1;
	break;
  case "west":
	is_w=1;
	break;
  case "northwest":
   	is_nw=1;
	break;
  case "northeast":
	is_ne=1;
	break;
  case "southeast":
	is_se=1;
	break;
  case "southwest":
	is_sw=1;
	break;
  }
 return 1;
 }


int add_exit(string dir){

 if (is_first){
  msgs="    There is one obvious exit: "+dir+"\n";
  is_first=0;
  first=dir;
  num=1;
  set_exit(dir);
  no_obvious_msg=msgs;
  return 1;
  }
  num+=1;
  switch(num){
   case 2:
       msgs="    There are two obvious exits: ";
       break;
   case 3:
       msgs="    There are three obvious exits: ";
       break;	
   case 4:
       msgs="    There are four obvious exits: ";
       break;	
   case 5:
       msgs="    There are five obvious exits: ";
       break;	
   case 6:
       msgs="    There are six obvious exits: ";
       break;	
   case 7:
       msgs="    There are seven obvious exits: ";
       break;
   case 8:
       msgs="    There are eight obvious exits: ";
       break;
   }
  msgs+=first;
  
   if (is_w && (first!="west"))  msgs+=", west"; 
   if (is_n && (first!="north")) msgs+=", north";
   if (is_e && (first!="east"))  msgs+=", east"; 
   if (is_s && (first!="south")) msgs+=", south";
   if (is_ne && (first!="northeast")) msgs+=", northeast";
   if (is_nw && (first!="northwest")) msgs+=", northwest";
   if (is_sw && (first!="southwest")) msgs+=", southwest";
   if (is_se && (first!="southeast")) msgs+=", southeast";
  
 msgs+=" and "+dir+"\n";
 no_obvious_msg=msgs;
 set_exit(dir);
 return 1;
 }

int edge(string str){

string info;
status had_brief;
  if (!str){
   write("Edge where ?");
   return 1;
  }
  info="But there is already a passage this way.\n";

  if (str=="west" || str=="w") { 
     if (!is_w) add_exit("west");
      else write(info);
     this_player()->move_player("west#players/goldsun/lank/room/coast15");
   }
  if (str=="north" || str=="n") {
    if (!is_n)  add_exit("north");
     else write(info);
    this_player()->move_player("north#players/goldsun/lank/room/coast9");
   }
  if (str=="east" || str=="e"){
    if (!is_e) add_exit("east");
     else write(info);
    this_player()->move_player("east#players/goldsun/lank/room/coast12");
  }
  if (str=="south" || str=="s"){
    if (!is_s) add_exit("south");
     else write(info);
    this_player()->move_player("south#players/goldsun/lank/room");
  }
  if (str=="northeast" || str=="ne"){
    if (!is_ne) add_exit("northeast");
	else write(info);
/*    had_brief=1;
    if (!this_player()->query_brief()){
       command("brief",this_player()); 
       had_brief=0;*/
      }
    this_player()->move_player("northeast#players/goldsun/lank/room/forest2");
    "/players/goldsun/lank/room/forest2"->add_exit("southwest");
/*    if (!had_brief){
      command("look",this_player());
      command("brief",this_player()); 
     } */
    }
  if (str=="southeast" || str=="se"){
    if (!is_se) add_exit("southeast");
	else write(info);
/*    had_brief=1;
    if (!this_player()->query_brief()){
        command("brief",this_player());
  	had_brief=0;
     }   */
    this_player()->move_player("southeast#players/goldsun/lank/room/forest4");
/*    if (!had_brief){
     command("look",this_player());
     command("brief",this_player());
    }  */
   }

  return 1;
}



cut(str){
 object axe,gtree;

  if (str=="tree"){
  if ( present("axe",TP) ) {
    if (random(20)<5) {                   /* success */
     write("You harm the tree with a loud BANG.\n");
     write("\nCraaaaaack.\n\n");
     write("You chop down the tree.\n");
     say("\nCraaaaaack.\n\n");
     say(OPN+" chops down a tree.\n");
     gtree=clone_object("/players/goldsun/sherwood/obj/tree");
     transfer(gtree,this_object());
     items -= ({"tree"});
     items += ({"tree","Someone has cut down this tree"});
    }
    else{                              /* no success  */
     axe=present("axe",TP);
     destruct(axe);
     write("You break your axe with a loud SNAP.\n");
     say(OPN+" tries to chop down a tree.\n");
     say("But "+TP->query_pronoun()+" fails.\n");
    }
   }    /* end of present("axe",TP) */
   else
    write("You have no axe to cut this tree.\n");
   } 
  else write("Cut what ?\n");
  return 1;
 }


 _listen(){
   if (random(5)<=1) {
      write("You can hear an animal sound at this moment.\n"); }
      else write("You can hear a slight breeze in the branches.\n");
  return 1;
  }              

 climb(str){
  if  (str=="tree") {
     write("You start to climb up this tree.\n");
     write("OUCH !\n");
     write("You fall down and hurt yourself.\n");
     this_player()->hit_player(1);      /*no point in type for hit_player() */
     say(OPN+" tries to climb up a tree.\n");
     say(OPN+" falls down and hurts himself.\n");
    }
   else write("Climb what ?\n");
 return 1;
 }


