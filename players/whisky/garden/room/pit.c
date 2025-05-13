#define TP this_player()
#define TPN TP->query_name()
#define TPP TP->query_possessive()

inherit "room/room";
#include "../garden.h"
    string rope;
    int i,num; 

reset(arg) {
  num=0;

  if (arg) return;
  set_light(0);
  property = "no_teleport";
  short_desc = "In a dark pit"; 
  items =
    ({
     "rocks","Big grey rocks",
     "rock","A big grey rock",
     "stone","A big grey stone",
     "stones","Big grey stones",
     "bottom","A grey stony bottom",
     "hole","You see a big dark hole", 
     "pit","You see a big dark pit", 
     "sky","You see the dark sky"});
  }

  init() {
    add_action("search","search");
    add_action("pass","pass");
    add_action("pass","climb");
    ::init();
   }
  long() {
  write("You are standing in a dark pit. There are big rocks to\n"+
    "the east, west, north, and south. It seems like you\n"+
    "will never make it out of here. There are some heavy stones\n"+
    "lying on the bottom.\n");
    if (call_other("players/whisky/garden/room/forest7","query_rope")) {
       write("There is a rope hanging down from the south.\n");
    }
    if (call_other("players/whisky/garden/room/forest8","query_rope")) {
       write("There is a rope hanging down from the north.\n");
    }
   return 1;
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
       write("You search under the stones, but find nothing.\n");
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
     write("You try to get out, but you fall and hurt yourself!\n");
     say(TPN+" tries to get out, but falls and hurts themselves.\n");
     TP->hit_player(random(20));
     break;
     case "rope":
     if (call_other("players/whisky/garden/room/forest7","query_rope")) {
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        TP->move_player("up the rope#players/whisky/garden/room/forest7");
      }
     else if (call_other("players/whisky/garden/room/forest8","query_rope")) {
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        TP->move_player("up the rope#players/whisky/garden/room/forest8");
      }
     else {
      write("There is no rope hanging down.\n");
     }
     break;
     case "rope 1":
     case "south rope":
     if (call_other(PATH+"forest7","query_rope")) {
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        TP->move_player("up the rope#players/whisky/garden/room/forest7");
      }
     break;
     case "rope 2":
     case "north rope":
     if (call_other(PATH+"forest8","query_rope")) {
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        TP->move_player("up the rope#players/whisky/garden/room/forest8");
      }
     break;
     default:
     write("You can't do that.\n");
     return 1;
    }
   return 1;
  } 
