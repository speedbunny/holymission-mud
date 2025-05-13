inherit "/room/room";
#include "items.h"
#include "../cut.h"
#include "../dig.h"
#include "../tear.h"
#include "../shake.h"
#include "../light.h"

reset(arg){
 if (!arg) {
  clone_list=({1,1,"robin","/players/goldsun/sherwood/monster/RobinHood",0});
 set_light(1);
 no_castle_flag=1;
 no_obvious_msg="";
 short_desc=("Center of the Sherwood");
 long_desc=("You are in the center of the Sherwood forest. The trees"
                +" and bushes\n"
            +"are everywhere but this clearing is sunny. There is a small"
               +" hill\n"
	    +"with a beautiful mystical oak tree here.\n"
            +"In the rocky hill you can see a cave entrance.\n");
 no_obvious_msg = "";
 smell="You smell common damp forest air.";
        
 items=({"tree", "The tree is old and huge. Maybe you could climb it",
	 "oak tree","The oak tree is very beautiful and mystical.\n"
	              +"You have never seen such an oak tree.",
	 "mystical tree","The oak tree is very beautiful and mystical.\n"
		      +"You have never seen such an oak tree.",
	 "mystical oak tree","The oak tree is very beautiful and mystical.\n"
	            +"You have never seen such an oak tree.\n"
         "cave", "The cave looks like Robin's home",
         "hill", "A small rocky hill with a cave entrance",
	 "small hill","A small rocky hill with a cave entrance",
	 "rocky hill","A small rocky hill with a cave entrance",
	 "small rocky hill","A small rocky hill with a cave entrance",
         "entrance", "It is small entrance to the cave",
	 "small entrance","It is the entrance to the cave",
         "bush", "There are many bushes in the forest and one\n"
                 +"of them is strange. Maybe you could pass it",
         "bushes", "The bushes are huge and dense and one\n"
                      +"of them is strange"})+ITEMS;
 }
::reset();
}            

 init(){
  ::init();
 add_action("pass","pass");
 add_action("enter","enter");
 add_action("climb","climb");
 add_action("listen","listen");
 add_action("dig","dig");
 add_action("light","light");
 add_action("cut","chop");
 add_action("shake","shake");
 add_action("tear","tear");
 add_action("cut","cut");
 }

pass(str){
 if (str=="bush" || str=="huge bush" || str=="dense bush"){
  write("You are hacking through the dense bush.\n");
  TP->move_player("into the dense forest#/players/goldsun/sherwood/room/shwood26");
 }
  else {
   write("What do you want to pass ?\n");
   say(OPN+" looks around.\n");
   }
 return 1;
 }

enter(str){
 if (str=="cave"){
  write("You enter the cave.\n");
  TP->move_player("into the cave#/players/goldsun/sherwood/room/cave");
   }
  else{
   write("What do you want to enter ?\n");
   say(OPN+" looks around.\n");}
 return 1;
 }

listen(){
 if (random(5)<=1){
  write("You can hear an animal sound at this moment.\n");
  say(OPN+" listens.\n");
  }
  else {
   write("You can hear a slight breeze in the branches above.\n");
   say(OPN+" listens.\n");
  }
 return 1;
}

climb(str){
 if (str=="old tree" || str=="tree" || str=="huge tree"){
  write("You don't think you could climb this tree.\n"
	 +"Try to climb oak tree.\n");
  say(OPN+" looks around.\n");
 }
  else 
   if (str=="oak tree" || str=="mystical tree" || str=="oak"){
    write("You catch the branches and climb up the tree.\n");
    TP->move_player("up the tree#/players/goldsun/sherwood/room/tree1");
       }
  else{
   write("What do you want to climb ?\n");
   say(OPN+" looks around.\n");
   }
 return 1;
}
