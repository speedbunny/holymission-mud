#include "../monkway.h"
inherit "room/room";
  object rat,snake,ring;

reset(arg) {

  if (!snake) {
     snake=clone_object(MONST+"snake");
     move_object(snake,TO);
    }
   if ((snake=present("snake")) && (!present("ring"))) {
     ring=clone_object(OBJ+"ring");
     move_object(ring,TO);
    }

  if (arg) return;
  set_light(1);
  short_desc = "In a ravine";
  long_desc =
    "You are standing in a ravine. There are big rocks to\n"+
    "the north and south. A small path is leading further to.\n"+
    "the east and west. There are some stones lying on the bottom.\n";
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
     "players/kawai/areas/link","south",
     PATH+"ravine3","east", 
     PATH+"ravine5","west" });

  }
  init() {
    add_action("search","search");
    add_action("pass","pass");
    add_action("pass","climb");
    add_action("get","get");
    add_action("get","take");
    ::init();
   }

  eat(arg) {
    object snake;
    if(arg) {
     if(snake=present("snake",TO)) {
       say("Suddenly the snake snaps after the rat and eats it.\n");
       write("Suddenly the snake snaps after the rat and eats it.\n");
       destruct(rat); 
     }
    }
   }
  get(arg) {
     if (arg!="ring" && arg!="glowing ring" && arg!="all") return;
     if (!present("snake")) return;
     write("The snake hinders you from getting anything.\n");
    return 1;
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
    

  
   
