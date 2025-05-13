inherit "/room/room";
#include "/players/goldsun/stand.h"

reset(arg){
if (arg) return;
 set_light(1);
 short_desc=("At the coast");
 long_desc=
  ("You are standing on the coast of the island of Lank. The ground\n"
  +"consists of sand. Huge waves are rolling towards the island and you\n"
  +"get a peaceful feeling. Far to the east you can see tall peak of\n" 
  +"Lankbourg mountains.\n"
                 );

 smell="You smell fresh, damp and salt air.";
 property=({"has_water"});
 items=({"sea","The sea is blue",
	 "water","The water looks very clear",
    	 "coast",long_desc,
	 "island",long_desc,
 	 "ground","The ground consists of sand",
	 "sand","The sand is light yellow",
	 "light yellow sand","The sand is pleasant warm",
	 "warm sand","The sand is light yellow",
	 "wave","The huge wave is rolling towards the coast",
	 "huge wave","The wave is rolling towards the coast",
	 "waves","The huge waves are rolling towards the coast",
	 "huge waves","The waves are rolling towards the coast",
	 "tall peak","A peak to the east.\n"
		  +"It is named Lankpeak and it is very tall",
	 "peak","A peak to the east.\n"
	      +"It is named Lankpeak and it is very tall",
	 "tall Lankpeak","A peak to the east",
	 "Lankpeak","The peak is very tall",
	 "mountains","The Lankbourg mountains to the east",
	 "Lankbourg mountains","The mountains to the east"
         });
 ::reset(arg);

}

 init(){
  ::init();
  add_action("lsten","listen");
  add_action("do_get","get");
  add_action("swim","swim");
  add_action("enter","enter");
  add_action("drink","drink");
  }

 enter(arg){
  if (!arg) return;
  if (arg=="sea" || arg=="blue sea" || arg=="water") return  swim();
  return 0;
  }

 drink(arg){
  if (!arg) return;
  if (arg=="water" || arg=="salt water" || arg=="clear water" ||
   	 arg=="clear salt water" || arg=="water from sea"){
   write("As you drink some salty water from the sea, you get a bad"
    +"feeling.\n");
   TP->add_poison(3);
   say(OPN+" drinks some water.\n");
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

 swim(){
  write("You jump into the water and swim around for a while.\n");
  say(OPN+" jumps into the water and swims around for a while.\n");
  return 1;
 }
  
