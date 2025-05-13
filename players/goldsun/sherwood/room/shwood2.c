inherit "/room/room";
#include "items.h"
#include "../climb.h"
#include "../dig.h"
#include "../cut.h"
#include "../light.h"
#include "../listen.h"
#include "../pass.h"
#include "../shake.h"
#include "../tear.h"


reset(arg){

 if (!arg) {
 clone_list=({1,1,"wasp","/players/goldsun/sherwood/monster/wasp",0});
 set_light(1);
 short_desc=("Sherwood entrance");
 long_desc=("You are at the entrance to the forest. The trees around you are"
                  +" high and\n"
          +"the bushes are thin. You feel safe here although you hear"
                 +" animal sounds\n"
          +"echoing from within the forest. The road leads to the east.\n");
 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood1", "east",
           "/players/goldsun/sherwood/room/shwood4", "south",
           "/players/goldsun/sherwood/room/shwood8", "west",
           "/players/goldsun/sherwood/room/shwood3", "north"});
 items=({"road", "The road leads further to the forest",
         "forest","The Sherwood forest",
	 "bush","One of the bushes in the wood",
         "thiny bushes","The bushes are green",
         "low bushes","The bushes are green",
         "low bush","The bush is green too",
         "thin bush","The bush is green too",
	 "grass","The grass is waving in the wind",
         "entrance","A forest entrance with thin bushes",
         "bushes", "The bushes are low and thin"})+ITEMS;
 }
 ::reset();
 }

init(){
 ::init();
 add_action("climb","climb");
 add_action("tear","tear");
 add_action("shake","shake");
 add_action("listen","listen");
 add_action("cut","cut");
 add_action("cut","chop");
 add_action("light","light");
 add_action("dig","dig");
 add_action("pass","pass");
}  
