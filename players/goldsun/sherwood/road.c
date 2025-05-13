    /* road to the sherwood forest */

inherit "room/room";
#include "../dig.h"
#include "../tear.h"

reset(arg){
 object sol,sign;
  ::reset(arg);
/*
   sol=clone_object("/players/goldsun/sherwood/monster/soldier");
   transfer(sol,this_object());

   sol=clone_object("/players/goldsun/sherwood/monster/soldier");
   transfer(sol,"/room/church");
*/
 if (arg) return;
 set_light(1);
 short_desc="Long dusty road";
 long_desc="You are walking on the long dusty road. There are some trees to"
                     +" the north \n"
          +"and to the south. From the east you can hear a strange sound"
                     +" but you \n"
          +"know that the sound is created by the sea. Something in"
                     +" your mind \n"
          +"tells you that you should go to the west.\n";
smell="The air is damp and dusty."; 
dest_dir=({"/players/goldsun/sherwood/room/shwood1", "west",
                                    "/room/shore/s02","east"
   	   });

items=({"road", "The road is very dusty with several footprints pointed to"
                     +" the west",
	"long road","The road is very long and dusty",
	"long dusty road","The road is very long and dusty",
	"dusty road","The road is very dusty and long",
	"footprint","It is a medium footprint",
	"footprints","They are different",
        "tree","A common large tree",
        "tree", "A common large tree",
	"animals","There are no animals here",
	"large trees","They are near the road. The trees are large",
        "trees", "There are not many trees but they are large"});

if (!sign){
 sign=clone_object("/players/goldsun/sherwood/obj/sign");
 move_object(sign, this_object());
 }  

  }
init(){
 ::init();
 add_action("listen","listen");
 add_action("climb","climb");
 add_action("dig","dig");
 add_action("tear","tear");
 add_action("shake","shake");
 }

shake(str){
 if (str=="tree"){
  write("You shake the tree but nothing happens.\n");
  say(OPN+" shakes the tree.\n");
  return 1;
  }
   else{
    notify_fail("Shake what ?\n");
    return 0;
    }
}

climb(str){
 if (str=="tree" || str=="large tree"){
  write("You don't think you could climb this tree.\n");
  say(OPN+" looks confused.\n");
  }
   else{
     write("What do you want to climb ?\n");
    say(OPN+" looks around.\n");
   }
 return 1;
}
listen(){
 write("You can hear a strange sound coming from the east.\n");
 say(OPN+" listens.\n");
 return 1;
}
