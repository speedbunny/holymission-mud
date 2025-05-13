inherit "/room/room";
#include "/players/goldsun/stand.h"
reset(arg){
if (arg) return;
 set_light(1);
 short_desc=("At the foot of Langbourg mountains");
 long_desc=
  ("You are standing at the foot of Langbourg mountains. Far above your head\n"
  +"you can see the tall, snow-topped peak of Langbourg mountains. A tall\n"
  +"vine is growing up the mountains. The ground consists of sand and rocks.\n"
  +"Huge waves are rolling towards rocks.\n"
                 );

 smell="You smell fresh, damp and salt air.";
 dest_dir=({"/players/goldsun/lank/room/coast9","northeast",
           "/players/goldsun/lank/room/coast14","southeast",
	   "/players/goldsun/lank/room/forest1","east"});

 items=({"sea","The sea is blue",
 	 "water","The water looks clear",
	 "rock","The rock is dark",
	 "rocks","The rocks are from the Lankpeak. They are dark",
    	 "coast",long_desc,
	 "island",long_desc,
	 "vine","The vine is tall. There is a way to climb up it",
 	 "ground","The ground consists of sand",
	 "sand","The sand is light yellow",
	 "light yellow sand","The sand is pleasant warm",
	 "warm sand","The sand is light yellow",
	 "wave","The huge wave is rolling towards the coast",
	 "huge wave","The wave is rolling towards the coast",
	 "waves","The huge waves are rolling towards the coast",
	 "huge waves","The waves are rolling towards the coast"
	 "tall peak","It is named Lankpeak",
	 "peak","It is named Lankpeak and it is very tall",
	 "tall Lankpeak","A snow-topped peak",
	 "Lankpeak","The peak is very tall",
	 "mountains","The Lankbourg mountains are very high and rocky",
	 "Lankbourg mountains","The mountains are very high and rocky"
         });
 ::reset(arg);

}

 init(){
  ::init();
  add_action("lsten","listen");
  add_action("do_get","get");
  add_action("drink","drink");
  add_action("climb","climb");
  add_action("swim","swim");
  add_action("enter","enter");
  add_action("g_east","east");
  }

 g_east(){
  "/players/goldsun/lank/room/forest1"->add_exit("west");
 return ::move("east");
}

 swim(){
  write("You jump into the water and swim around for a while.\n");
  say(OPN+" jumps into the water and swims around for a while.\n");
  return 1;
  }


 enter(arg){
  if (!arg) return;
  if (arg=="sea" || arg=="clear sea" || arg=="water"){ return swim(); }
  return 0;
  }

 drink(arg){
  if (!arg) return;
  if (arg=="water from sea" || arg=="salt water" || arg=="salt water from sea"
	   || arg=="blue water" || arg=="water"){
  write("As you drink some salty water from the sea, you get a bad feeling.\n");
  say(OPN+" drinks some water.\n");
  TP->add_poison(3);
  return 1;
 }
}


 do_get(str){
  if (str=="sand"){
   write("The sand slips through your fingers.\n");
   say(OPN + "tries to take the sand.\n");
   return 1;
  }
 }

 lsten(){
      write("You can hear the sea waves.\n"); 
  return 1;
  }              


climb(arg){
 if (!arg) return;
 if (arg=="vine" || arg=="up vine" || arg=="up the vine" || arg=="up"){
  write("You start to climb up the vine.\n");
  say(OPN+" starts to climb up the vine.\n");
  TP->move_player("up#/players/goldsun/lank/room/peak2");
  return 1;
  }
 }



