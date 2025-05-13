#include "../monkway.h"
inherit "room/room";
  object rat,leaf;
  int i;

reset(arg) {
  i=0;

  if (arg) return;
  set_light(1);
  short_desc = "In a ravine";
  long_desc =
    "You are standing in a ravine. There are big rocks to\n"+
    "the north and south. A small path is leading further to the\n"+
    "east and west. There are some heavy stones lying on the bottom.\n";
  items =
    ({
     "rocks","Big grey rocks",
     "rock","A big grey rock",
     "path","A small path leading further to the east and west",
     "stone","A big grey stone",
     "stones","Big grey stones",
     "bottom","A grey stony bottom",
     "sky","A clear blue sky" });
  dest_dir =
     ({
     PATH+"ravine4","east", 
     PATH+"ravine6","west" });

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

   switch(arg) {
    case "rock":
    case "rocks":
    write("You search under the rocks, but find nothing.\n");
    say(TPN+" searches under the rocks, but finds nothing.\n");
    break;
    case "stone":
    case "stones":
      if (i<1) {
       write("You search under the stones and finds a small leaf.\n");
       say(TPN+" searches under the stones and finds a small leaf.\n");
       leaf=clone_object("obj/treasure");
       leaf->set_id("leaf");
       leaf->set_alias("oak leaf");
       leaf->set_short("An oak leaf");
       leaf->set_long("A small green oak leaf.\n");
       leaf->set_weight(1);
       leaf->set_value(1);
       move_object(leaf,TO);
       }
       else {
       write("You search under the stones, but finds nothing.\n");
       say(TPN+" searches under the stones, but finds nothing.\n");
       }
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
    

  
   
