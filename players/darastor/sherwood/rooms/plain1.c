inherit "/room/room";
#include "../tear2.h"
#include "../light.h"
#include "items_edge.h"

reset(arg){
 set_light(1);
 short_desc=("The edge of Sherwood");
 long_desc=("You are on a large hill. There are small bushes and green moss"
		+" around you.\n"
           +"In front of you there is a small cave. You have a peaceful feeling"
            + " here.\n"
           +"From time to time you can hear an animal sound from"
                 +" the forest.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood23", "down"});
        
 items=({"green moss","The moss is really green",
	 "soft moss","The moss is soft and green",
  	 "small bush","The bush is dense and small",
	 "small bushes","The bushes are dense and small",
	 "bush","Small and dense bush",
	 "grass","The grass is waving in the wind",
	 "cave","The cave is small and not dark",
         "hill", "The hill is covered with moss and bushes. It is possible"
                      +" to climb up\n"+
                 "and down from here",
         "bushes", "The bushes are small and dense"})+ITEMS;
 ::reset(arg);

}

 init(){
  ::init();
  add_action("lsten","listen");
  add_action("climb","climb");
  add_action("light","light");
  add_action("pass","pass");
  add_action("enter","enter");
  add_action("tear2","tear");
  }

 lsten(){
   if (random(5)<=1) {
      write("You can hear an animal sound at this moment.\n"); }
      else write("You can hear a slight breeze in the branches above.\n");
  return 1;
  }              

climb(str){
    if (str=="down" || str=="hill down"){
     write("You climb down the hill.\n");
     this_player()->move_player("down#/players/goldsun/sherwood/room/shwood23");
    }
    else {
    write("Where do you want to climb ?\n");
     say(OPN+" looks around.\n");
     }
 return 1;
}

pass(str){
 if (str=="bush" || str=="small bush" || str=="dense bush"){
  write("You don't think you could pass this bush.\n");
  say(OPN+" looks confused.\n");
  }
  else{
   write("What do you want to pass ?\n");
   say(OPN+" looks around.\n");
  }
 return 1;
}
enter(str){
 if (str=="cave" || str=="small cave"){
  write("You enter the cave.\n");
  this_player()->move_player("into the cave#/players/goldsun/religion/quercus_cave");
  }
  else{
   write("What do you want to enter ?\n");
   say(OPN+"looks around.\n");
  }
return 1;
}
