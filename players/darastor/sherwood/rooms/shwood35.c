inherit "/room/room";
#include "../cut.h"
#include "../tear2.h"
#include "../shake.h"
#include "../dig.h"
#include "../light.h"
#include "items_edge.h"

reset(arg){
 set_light(1);
 short_desc=("The edge of Sherwood");
 long_desc=("You are at the edge of the Sherwood forest. The trees and bushes"
                 +" are\n"
           +"everywhere. From time to time you can hear an animal sound from"
                 +" the forest.\n"
           +"To the west you can see a steep hill covered with moss and"
                 +" bushes.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood36", "south",
           "/players/goldsun/sherwood/room/shwood30", "northeast",
           "/players/goldsun/sherwood/room/shwood31", "east"});
        
 items=({
	 "grass","The grass is waving in the wind",
	 "green moss","The mopss is really green",
	 "soft moss","The moss is soft and green",
  	 "small bush","The bush is dense and small",
	 "small bushes","The bushes are dense and small",
         "hill", "The hill is covered with moss and bushes. It is possible"
                      +" to climb up\n"+
                 "from here",
         "steep hill","The hill is not so steep. You can climb it"})+ITEMS;
 ::reset(arg);

}

 init(){
  ::init();
  add_action("lsten","listen");
  add_action("climb","climb");
  add_action("pass","pass");
  add_action("light","light");
  add_action("cut","cut");
  add_action("dig","dig");
  add_action("tear2","tear");
  add_action("shake","shake");
  add_action("cut","chop");

  }

 lsten(){
   if (random(5)<=1) {
      write("You can hear an animal sound at this moment.\n"); }
      else write("You can hear a slight breeze in the branches above.\n");
  return 1;
  }              

climb(str){
   if (str=="tree" || str=="old tree" || str=="huge tree"){
    write("You don't think you could climb this tree.\n");
    say(OPN+" looks confused.\n");
   }
    else
   if (str=="hill" || str=="up" || str=="up hill" || str=="up the hill"){
   write("Uf.\n");
   write("Uf.\n");
   write("You climb up the hill.\n");
   this_player()->move_player("up the hill#/players/goldsun/sherwood/room/shwood38");
    return 1;
   }
    else {
    write("What do you want to climb ?\n");
     say(OPN+" looks around.\n");
     }
 return 1;
}

pass(str){
 if (str=="bush" || str=="huge bush" || str=="dense bush"){
  write("You don't think you could pass this bush.\n");
  say(OPN+" looks confused.\n");
  }
  else{
   write("What do you want to pass ?\n");
   say(OPN+" looks around.\n");
  }
 return 1;
}
