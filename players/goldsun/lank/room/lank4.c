inherit "/room/room";
#include "/players/goldsun/stand.h"
#include "/players/whisky/genesis/sys/filter_live.h"
#define PPATH "/players/goldsun/lank/room/"

object sheep;
int i;

reset(arg){
       
 if (filter_live(this_object())<5) {
   for (i=1;i<6;i++){
   sheep=clone_object("/players/goldsun/lank/monster/sheep.c");
   transfer(sheep,this_object());
   }
  }
            
if (arg) return;
 set_light(1);
 short_desc=("In the valley");
 long_desc=
  ("You are in the beatuful valley covered with waving grass. On the slope\n"
  +"you can see a dark hole. You don't feel very safely near it.\n"
  +"To the west you can see tall peak of Lankbourg mountains.\n"
  );

 smell="You smell common fresh sea air.";

 dest_dir=({PPATH + "lank1.c" , "west",
       	    PPATH + "lank5.c" , "south",
	    PPATH + "lank3.c" , "east",
	    PPATH + "lank2.c" , "north" });

 items=({"grass","The grass is waving in the wind",
	 "hill","The large hill is covered by grass",
	 "valley","The valley is very beautiful",
         "dark hole","It is entrance to the cyclop cave",
	 "hole","A dark hole. It is entrance to the cyclop cave",
	 "entrance","An entrance to the cyclop cave",
	 "peak","A peak to the west.\n"+
	        "It is named Lankpeak and it is very tall",
	 "tall peak","A peak to the west.\n"+
		   "It is named Lankpeak",
	 "Lankpeak","The peak is very tall",
	 "tall Lankpeak","A peak to the west",
	 "mountains","The Lankbourg mountains to the west",
	 "Lankbourg mountains","The mountains to the west"
       });

 ::reset(arg);

}

 init(){
  ::init();
  add_action("lsten","listen");
  add_action("cut","cut");
  add_action("cut","tear");
  add_action("enter","enter");
  }

 int cut(string str){

  object grass;

  if (str=="grass"){

    if (present("grass",TP)) write("You already have a tuft of grass.\n");
     else{
      write("You tear a tuft of grass.\n");
      say(OPN+" tears a tuft of grass.\n");
      grass=clone_object("/players/goldsun/lank/obj/grass");
      transfer(grass,TP);}
    }
    else write("Tear what ?\n");
  return 1;
 }

 int enter(string str){
  if (str=="hole" || str=="cave"){
   TP->move_player("into the cave#/players/goldsun/lank/room/cyclop_cave");
   return 1;
  }
  return 0;
 }

 lsten(){
   if (random(5)<=1) {
      write("You can hear an animal sound at this moment.\n"); }
      else write("You can hear a slight breeze in the branches.\n");
  return 1;
  }              

