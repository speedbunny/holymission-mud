#include "../monkway.h"
inherit "room/room";
    object rat;
    int rope;
    int i; 

reset(arg) {
  i=0;

  if (arg) return;
  set_light(1);
  short_desc = "In a ravine";
  long_desc =
    "You are standing in a ravine. There are big rocks to\n"+
    "the east and west. A small path is leading to the north.\n"+
    "There are some heavy stones lying on the bottom.\n"+
    "On the eastern side you see a small pillar and to the\n"+
    "north you see a dark pit. As you look at the pit, you think\n"+
    "it would be better to have and use some ropes !\n";
  items =
    ({
     "rocks","Big grey rocks",
     "rock","A big grey rock",
     "stone","A big grey stone",
     "stones","Big grey stones",
     "bottom","A grey stony bottom",
     "pillar","You see a small pillar",
     "hole","You see a big dark hole", 
     "pit","You see a big dark pit, it seems impossible to pass", 
     "sky","A clear blue sky" });
  dest_dir =
     ({
     PATH+"ravine7","south"
     });
  }

  init() {
    add_action("search","search");
    add_action("pass","pass");
    add_action("pass","climb");
    add_action("tie","tie");
    add_action("untie","untie"); 
    add_action("north","north");
    add_action("north","n");
    add_action("down","down");
    add_action("down","d");
    add_action("jump","jump");
    ::init();
   }
  tie(str) {
    if (str!="pillar")  return 0;
    rope=1;
   return 1;
  }
 untie(str) {
   rope=0;
   return 1;
  }
query_rope() { return rope; }
  
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
       write("You search under the stones, but finds nothing.\n");
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
  down() {
    TP->move_player("into the pit#players/whisky/quest/room/pit");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("A U T C H you hurt yourself badly.\n");
    TP->hit_player(random(80));
   return 1; 
  }
  north() {
    TP->move_player("into the pit#players/whisky/quest/room/pit");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("A U T C H you hurt yourself badly.\n");
    TP->hit_player(random(80));
   return 1; 
  }
  jump() {
    if (present("mring",TP) && (TP->query_weight()< 2+TPST/4)) {
       write("You make a big jump over the pit.\n");
       say(TPN+" makes a big jump over the pit.\n");
       TP->move_player("into the pit#players/whisky/quest/room/ravine9");
      return 1;
     }

    TP->move_player("into the pit#players/whisky/quest/room/pit");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("A U T C H you hurt yourself badly.\n");
    TP->hit_player(random(80));
   return 1; 
  }
  
   
