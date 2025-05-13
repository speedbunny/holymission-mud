inherit "/room/room";
#include "/players/goldsun/stand.h"
#define PPATH "/players/goldsun/lank/room/"

int tree_num;

reset(arg){
if (arg) return;
 set_light(1);
 tree_num=(random(9)+2);
 short_desc=("On a hill");
 long_desc=
  ("You are on a large hill covered with waving grass with several trees.\n"
  +"You have never seen such trees. They are not too high but looks like\n"
  +"trees on the Avalon iceland. To the east you can see tall peak \n"
  +"of Lankbourg mountains.\n"
  );

 smell="You smell common fresh sea air.";

 dest_dir=({PPATH + "coast1.c" , "west",
       	    PPATH + "coast5.c" , "south",
	    PPATH + "coast2.c" , "north",
	    PPATH + "lank4.c"  , "east",
	    PPATH + "lank2.c"  , "northeast",
	    PPATH + "lank5.c"  , "southeast"});

 items=({"grass","The grass is waving in the wind",
	 "tree","An unknown tree. You have never seen such one",
	 "hill","The large hill is covered by grass",
	 "trees","The unknown trees. You have never seen such trees",
	 "several trees","The unknown trees. You have never seen such trees",
	 "peak","A peak to the east.\n"+
	        "It is named Lankpeak and it is very tall",
	 "tall peak","A peak to the east.\n"+
		   "It is named Lankpeak",
	 "Lankpeak","The peak is very tall",
	 "tall Lankpeak","A peak to the east",
	 "mountains","The Lankbourg mountains to the east",
	 "Lankbourg mountains","The mountains to the east"
       });

 ::reset(arg);

}

 init(){
  ::init();
  add_action("lsten","listen");
  add_action("climb","climb");
  add_action("cut","cut");
  add_action("cut","chop");
  }

 cut(str){
 object axe,gtree;

  if (str=="tree"){
  if ( present("axe",TP) ) {
   if (tree_num > 0 ) {
    if (random(4)<1){                   /* success */
     write("You harm the tree with a loud BANG.\n");
     write("\nCraaaaaack.\n\n");
     write("You chop down the tree.\n");
     say("\nCraaaaaack.\n\n");
     say(OPN+" chops down a tree.\n");
     gtree=clone_object("/players/goldsun/sherwood/obj/tree");
     transfer(gtree,this_object());
     items -= ({"tree"});
     items += ({"tree","Someone has cut down this tree"});
     tree_num -= 1;
    }
    else{                              /* no success  */
     axe=present("axe",TP);
     destruct(axe);
     write("You break your axe with a loud SNAP.\n");
     say(OPN+" tries to chop down a tree.\n");
     say("But "+TP->query_pronoun()+" fails.\n");
    }
    }
    else write("There is no tree to cut it.\n");
   }    /* end of present("axe",TP) */
   else
    write("You have no axe to cut this tree.\n");
   } 
  else write("Cut what ?\n");
  return 1;
 }


 lsten(){
   if (random(5)<=1) {
      write("You can hear an animal sound at this moment.\n"); }
      else write("You can hear a slight breeze in the branches.\n");
  return 1;
  }              

 climb(str){
  if (str=="hill"){
   write("You can't climb it because you are on it.\n");
    return 1;
   }
  if  (str=="tree") {
   if  (tree_num>0) {
     write("You start to climb up this tree.\n");
     write("OUCH !\n");
     write("You fall down and hurt yourself.\n");
     this_player()->hit_player(1,7);
     say(OPN+" tries to climb up a tree.\n");
     say(OPN+" falls down and hurts himself.\n");
    }
    else{
     write("There is no tree to climb it.\n");
     say(OPN+" looks around.\n");
     }}
   else write("Climb what ?\n");
 return 1;
 }

