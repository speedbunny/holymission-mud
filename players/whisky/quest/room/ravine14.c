#include "../monkway.h"
inherit "room/room";
    object rat;
    object g1,g2,g3;

reset(arg) {
  if(!g1) {
    g1=clone_object(MONST+"brave_golem");
    move_object(g1,TO);
   }
  if (!g2) {
     g2=clone_object(MONST+"golem2");
     move_object(g2,TO);
   }
  if (!g3) {
     g3=clone_object(MONST+"fear_golem");
     move_object(g3,TO);
   }

  if (arg) return;
  set_light(1);
  short_desc = "In a ravine";
  long_desc =
    "You are standing in a ravine. There are big rocks to\n"+
    "the east and west. A small path is leading to the north.\n"+
    "There are some heavy stones lying on the bottom.\n";
  items =
    ({
     "rocks","Big grey rocks",
     "rock","A big grey rock",
     "stone","A big grey stone",
     "stones","Big grey stones",
     "bottom","A grey stony bottom",
     "sky","A clear blue sky" });
  dest_dir =
     ({
     PATH+"ravine13","south"
     });
   }
  init() {    
    add_action("search","search");
    add_action("pass","pass");
    add_action("pass","climb");
    add_action("north","north");
    add_action("north","n");
    ::init();
   }


  search(arg) {
   object stick;

   switch(arg) {
    case "rock":
    case "rocks":
    write("You search under the rocks, but find nothing.\n");
    say(TPN+" searches under the rocks, but finds nothing.\n");
    break;
    case "stone":
    case "stones":
    write("You search under the stomes, but find nothing.\n");
    say(TPN+" searches under the stones, but finds nothing.\n");
    break;
    case "bottom":
    write("You search on the bottom, but find nothing.\n");
    say(TPN+" searches on the bottom, but finds nothing.\n");
    break;
    default:
    write("You search around, but you find nothing.\n");
    say(TPN+" searches around, but you finds nothing.\n");
    return 1;
    }
   return 1;
  }
  pass(arg) {
    switch(arg) {
     case "rock":
     case "rocks":
     write("You try to climb the rocks.\n");
     write("OUCH! You fall and hurt yourself.\n");
     say(TPN+" tries to pass the rocks, but falls down.\n");
     TP->hit_player(random(80));
     break;
     default:
     write("You can't do that.\n");
     return 1;
    }
   return 1;
  } 

  north() {
   if (present("golem")) {
      write("The stone golem bars you the way !\n");
   return 1;
   }
   TP->move_player("north#players/whisky/quest/room/ravine15");
  return 1;
  }
    
    

  
   
