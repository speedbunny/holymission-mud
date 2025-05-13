inherit "/room/room";
#include "../cut.h"
#include "../dig.h"
#include "../light.h"
#include "../shake.h"
#include "../tear.h"
#include "items.h"

reset(arg){
 if (arg) return;
 set_light(0);
 short_desc=("Sherwood mystical place");
 long_desc=
 ("You are in the Sherwood forest. The forest is dark. Dense bushes\n"
 +"and huge trees are everywhere. You don't feel very safe here.\n"
+"This place looks very strange and mystically. Something in your mind \n"
+"tells you there are dangerous animals near you.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood27", "south",
           "/players/goldsun/sherwood/room/shwood32", "west",
           "/players/goldsun/sherwood/room/shwood25", "north",
           "/players/goldsun/sherwood/room/shwood19", "east"
           });
        
 items=({"place","This place looks holy",
         "mystical place","You heared about this place from a story....",
	 "grass","The grass is waving in the wind",
         "strange bush","The bush looks passable",
         "bush", "There are many bushes here, but one of them is\n"
                 +"strange. Maybe you could pass it" ,
         "bushes", "The bushes are huge and dense and one is strange"})+ITEMS;
 ::reset(arg);
}

init(){
 ::init();
 add_action("pass","pass");
 add_action("listen","listen");
 add_action("climb","climb");
 add_action("cut","cut");
 add_action("cut","chop");
 add_action("dig","dig");
 add_action("shake","shake");
 add_action("tear","tear");
 add_action("light","light");
}

pass(str){
 if (str=="bush"){
  write("\nYou are hacking the bush.\n");
  this_player()->move_player("and enters the dense forest#players/goldsun/sherwood/room/Robin");
 }
 else write("What do you want to pass ?\n");
 return 1;
}  

listen(){
 write("You can hear a slight breeze in the branches above.\n");
 say(this_player()->query_name()+" listens.\n");
 return 1;
 }

climb(str){
 if (str=="tree" || str=="old tree" || str=="huge tree"){
  write("You don't think you could climb this tree.\n");
  say(this_player()->query_name()+" looks confused.\n");
  }
  else {
    write("What do you want to climb ?\n");
    say(this_player()->query_name()+" looks around.\n");
   }
 return 1;
}
