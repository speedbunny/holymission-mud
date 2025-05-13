inherit "/room/room";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"
#include "/players/goldsun/stand.h"


void reset(int arg){
if (!arg){
 set_light(1);
 short_desc=("The coast of Topaz Island");
 long_desc=
  "You are standing on the coast of Topaz Island.  To the north you can "+
  "see tall cliff.  It is too steep to climb it.  The ground consists of "+
  "sand.  Small waves are rolling towards the island.\n";
 smell="You smell fresh, damp and salt air.";
 property=({"has_water"});
 items=({"sea","The sea is blue",
         "water","The water looks very clear",
         "coast",long_desc,
         "island",long_desc,
         "ground","The ground consists of sand",
         "sand","The sand is light yellow",
         "wave","The small wave is rolling towards the coast",
         "small wave","The wave is rolling towards the coast",
         "waves","The small waves are rolling towards the coast",
         "small waves","The waves are rolling towards the coast",
         "cliff","A very steep cliff to the north"
         });
}
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
   move_object(clone_object(ii+"/stomachache"),TP);
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
