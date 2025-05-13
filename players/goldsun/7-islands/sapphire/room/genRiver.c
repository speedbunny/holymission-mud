inherit "/room/room";
#include "/players/goldsun/stand.h"
 

void reset(int arg){
if (!arg){
 set_light(1);
 short_desc=("On the Sapphire Island");
 long_desc=
  "You are wading in one of several rivers on the Sapphire Island.\n"+
  "Cold crystal water ripples around your legs. On the rocky banks\n"+
  "are few spruce trees.\n";

 smell="You smell cold damp air.";
 property=({"has_water"});
 items=({"river","Blue river with crystal water in it",
	 "water","The water looks very clear",
	 "island",long_desc,
 	 "ground","The ground consists of rocks",
         "bank","It is rocky bank with several spruce trees",
         "banks","You can see a few trees on them",
	 "tree","A spruce tree on the left bank"
         });
}
 ::reset(arg);

}

 init(){
  ::init();
  add_action("lsten","listen");
  add_action("do_get","get");
  add_action("swim","swim");
  add_action("enter","enter");
  add_action("swim","dive");
  add_action("drink","drink");
  }

 enter(arg){
  if (!arg) return;
  if (arg=="river" || arg=="blue river" || arg=="water"){
   write("You are already in the river.\n");
   return 1;
  }
  return 0;
  }

 drink(arg){
  if (!arg) return;
  if (arg=="water" || arg=="crystal water" || arg=="clear water" ||
   	 arg=="cold water" || arg=="water from river"){
   write("Ahhhhhh.... It is fresh and cold.\n");
   say(OPN+" drinks some water.\n");
   return 1;
   }
  }


 do_get(str){
  if (str=="rock" || str=="boulder"){
   write("The "+str+" is too heavy.\n");
   say(OPN + "tries to take the "+str+".\n");
   return 1;
  }
 }

 lsten(){
      write("You can hear the sea waves.\n"); 
  return 1;
  }              

 swim(){
  write("You jump into the water and swim around for a while.\n");
  say(OPN+" jumps into the water and swims around for a while.\n");
  return 1;
 }
  
