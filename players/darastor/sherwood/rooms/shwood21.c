inherit "/room/room";
#include "items.h"
#include "../climb.h"
#include "../listen.h"
#include "../dig.h"
#include "../tear.h"
#include "../shake.h"
#include "../pass.h"
#include "../light.h"


reset(arg){
 if (!arg) {
 clone_list=({1,1,"termit","/players/goldsun/sherwood/monster/termit",0});
 set_light(0);
 short_desc=("Sherwood");
 long_desc=
("You are in the dark Sherwood forest. A tangle of shadowy bushes\n"
 +"lie in the darknees of this forest. The trees are huge and old.\n"
 +"One of them is full of holes. You cannot see anything else. \n");


 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood22", "south",
           "/players/goldsun/sherwood/room/shwood29", "west",
           "/players/goldsun/sherwood/room/shwood20", "north",
           "/players/goldsun/sherwood/room/shwood17", "east"});
        
 items=({"tree", "The tree is old and full of holes",
	 "huge tree","The tree is huge and full of holes",
	 "old tree","The tree is very old and full of holes",
	 "shadowy bushes","The bushes are dnese and huge"})+ITEMS;
 }
  ::reset();
}

init(){
 ::init();
add_action("climb","climb");
add_action("listen","listen");
add_action("dig","dig");
add_action("pass","pass");
add_action("light","light");
add_action("cut","cut");
add_action("shake","shake");
add_action("cut","chop");
add_action("tear","tear");
}

cut(str){
 int i;
 object axe,ter,ttre,branch;

 if (present("axe",TP)){
  if (random(6)<=1){
  if (str=="tree" || str=="old tree" || str=="huge tree"){
    write("You start chopping down the tree.\n");
    write("You are almost there.\n");
    write("With a loud CRAAACK the tree falls down.\n");
    say("With a loud CRAAACK a tree falls down.\n");
    say(OPN+" chops down a tree.\n");
    ttre=clone_object("/players/goldsun/sherwood/obj/tree");
    transfer(ttre,this_object());
    for(i=1;i<random(7);++i){
     ter=clone_object("/players/goldsun/sherwood/monster/termit");
     transfer(ter,this_object());
     write("Termit arrives.\n");
     say("Termit arrives.\n");
      }
     items -=({"tree"});
     items +=({"tree","Someone has cut down this tree"});
    }
    else
     if (str=="bush" || str=="dense bush"){
      write("You harm the bush with a loud BANG.\n");
      write("You chop down a branch.\n");
      say("BANG\n");
      say(OPN+" chops down a branch.\n");
      branch=clone_object("players/goldsun/sherwood/obj/branch");
      transfer(branch,TP);
    }
    else{
     write("What do you want to cut ?\n");
     say(OPN+" looks around.\n");
    }
   }
    else{
    axe=(present("axe",TP));
    destruct(axe);
    write("You try to use your axe to harm the "+str+" but fail.\n");
    write("Your axe breaks with a loud SNAPP.\n");
    say(OPN+" tries to break down a "+str+".\n");
    say("But "+TP->query_pronoun()+" fails.\n");
    }
    }
  else{
   write("You look around but see no axe to cut the tree.\n");
   say(OPN+" looks around.\n");
   }
 return 1;
}  
