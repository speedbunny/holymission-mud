inherit "/room/room";
#include "../dig.h"

reset(arg){

if (!arg){
 clone_list=({1,4,"bear","/players/goldsun/sherwood/monster/hbear",0});
 set_light(0);
 short_desc=("A bear's cave");
 long_desc=("You are in the dark bear cave.\n"
	   +"This place is not save for you.\n");
 smell="You smell bear's smell";

 dest_dir=({"/players/goldsun/sherwood/room/shwood10","up"});
 items=({"cave","Dark bear cave",
         "dark cave","This is bear cave",
	 "bear cave","The cave is dark",
	 "place","You see some dry grass and branches",
	 "grass","The grass is dry",
	 "branches","The branches are dry",
	 "branch","Dry branch",
	 "dry grass","The grass is dry. Maybe the bears sleep on that",
	 "dry branches","Dry oak branches",
	 "oak branches","The branches are dry",
         "dry branch","This branch is broken",
	 "broken branch","Dry broken branch",
	 "oak branch","This branch is very dry"});
  }
 ::reset();
 }
 
init(){
 ::init();
add_action("dig","dig");
add_action("do_it","get");
add_action("do_it","take");
}

int do_it(string str){
 if (str=="branch" || str=="grass"){
  write("You don't want it.\n");
  return 1;
 }
 return 0;
}

