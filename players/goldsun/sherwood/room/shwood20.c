inherit "/room/room";
#include "items.h"
#include "../climb.h"
#include "../cut.h"
#include "../light.h"
#include "../pass.h"
#include "../shake.h"
#include "../tear.h"
#include "../listen.h"


reset(arg){

 if (!arg) {
  clone_list=({1,1,"shadow","/players/goldsun/sherwood/monster/shadow",0});
 set_light(0);
 short_desc=("Sherwood");
 long_desc=
 ("You are in the Sherwood forest. This place is very shadowy.\n"
 +"The trees and bushes are everywhere. You cannot see anything else.\n"
 +"Something in your mind tells you that you should leave \n"
 +"this place as soon as possible.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood21", "south",
           "/players/goldsun/sherwood/room/shwood28", "west",   
           "/players/goldsun/sherwood/room/shwood16", "east"});
        
 items=({"grass","The grass is waving in the wind",
	 "place","This place is not very safe for you.\n"
			+"It looks very dangerous"})+ITEMS;
  }
  ::reset();
}

init(){
 ::init();
add_action("climb","climb");
add_action("listen","listen");
add_action("tear","tear");
add_action("pass","pass");
add_action("shake","shake");
add_action("tear","tear");
add_action("light","light");
add_action("dig","dig");
add_action("cut","cut");
add_action("cut","chop");
}

dig(str){
 if (str=="down"){
  write("You start to dig down...\n");
  write("\nOUCH\n\n");
  write("You fall down into a cave.\n");
  TP->move_player("down#/players/goldsun/sherwood/room/dcave3");
  }
 else{
  write("Where do you want to dig ?\n");
  say(OPN +" looks around.\n");
  }
return 1;
}
