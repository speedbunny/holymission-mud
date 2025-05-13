#include "../monkway.h"
inherit "room/room";
    object rat;

reset(arg) {

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
     PATH+"ravine16","north", 
     PATH+"ravine14","south"
     });
   }
  init() {
    if (rat=present("rat")) call_out("run",2,rat);
    add_action("search","search");
    add_action("pass","pass");
    add_action("pass","climb");
    ::init();
   }

  run(arg) {
    if(arg) arg->run_away();
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
    

  
   
