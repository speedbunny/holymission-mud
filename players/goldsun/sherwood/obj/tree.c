inherit "/obj/treasure";
#include "/players/goldsun/stand.h"
status i;
reset(arg){
 ::reset(arg);
if (arg) return;
 set_id("tree");
 i=1;
 set_alias("tree");
 set_short("An old small tree");
 set_long("Someone has cut down this tree.\n");
 set_weight("50");
 set_value(300);    /* good tree for wood */
 }

init(){
 ::init();
add_action("search","search");
}

get(){
 return 0;
      }

search(str){
 object ob;
 if (str=="tree" || str=="old tree" || str=="huge tree"){
  if (i==1){
   i=0;
   write("You search the "+str+" and find ");
   say(OPN+" searches the "+str+" and finds ");
   switch(random(3)){
   
    case 0:
     write("nothing special.\n");
     say("nothig special.\n");
     return 1;
    case 1:
     write("the huzel nut.\n");
     say("a huzel nut.\n");
     ob=clone_object("/players/goldsun/sherwood/obj/hnut");
     transfer(ob,TP);
     return 1;
    case 2:
     write("the egg.\n");
     say("an egg.\n");
     ob=clone_object("/players/goldsun/sherwood/obj/egg");
     transfer(ob,TP);
     return 1;
    }
   }   /* i==1 */
  else{
   write("Someone has already searched this tree before you.\n");
   say(OPN+" searches the tree");
   return 1;
  }
 }
 else{
  write("Search what ?\n");
  say(OPN+" looks around.\n");
  return 1;
  }
}

