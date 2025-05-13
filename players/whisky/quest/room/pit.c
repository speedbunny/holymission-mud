#include "../monkway.h"
inherit "room/room";
    object spider;
    string rope;
    int i,num; 

reset(arg) {
  num=0;

  if (arg) return;
  set_light(1);
  short_desc = "In a dark pit"; 
  items =
    ({
     "rocks","Big grey rocks",
     "rock","A big grey rock",
     "stone","A big grey stone",
     "stones","Big grey stones",
     "bottom","A grey stony bottom",
     "pillow","You see a small pillow",
     "hole","You see a big dark hole", 
     "pit","You see a big dark pit", 
     "sky","A clear blue sky" });
  }

  init() {
    if (!present("spider")) {
    call_out("spider",1);
    }
    add_action("search","search");
    add_action("pass","pass");
    add_action("pass","climb");
    ::init();
   }
  long() {
  write("You are standing in a dark pit. There are big rocks\n"+
    "the east and west north and south. It seems like you\n"+
    "never come out here. There are some heavy stones lying\n"+
    "on the bottom.\n");
    if (call_other("players/whisky/quest/room/ravine8","query_rope")) {
       write("There is a rope hanging down from the south.\n");
    }
    if (call_other("players/whisky/quest/room/ravine9","query_rope")) {
       write("There is a rope hanging down from the north.\n");
    }
   return 1;
 }
  spider() {
    object ob;
    ob=all_inventory();
    for (i=0;i<sizeof(ob);i++)
     if (ob[i]->query_name()=="spider") {
      num++;
      return 1;
     }
    if(num<4) {
     call_out("can_come",1);
    }
   return 1;
  }
     
  can_come() { 
    int snum;
     snum=2+random(5);
       write("You can hear a strange noise under the stones.\n");
       for (i=0;i<snum;i++)
       spider=clone_object(MONST+"spider");
       move_object(spider,TO);
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
     write("You try to pass the rocks, but you stumble and fall down.\n");
     say(TPN+" tries to pass the rocks, but falls down on "+TPP+" ass.\n");
     TP->hit_player(random(80));
     break;
     case "rope":
     if (call_other("players/whisky/quest/room/ravine8","query_rope")) {
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        TP->move_player("up the rope#players/whisky/quest/room/ravine8");
      }
     else if (call_other("players/whisky/quest/room/ravine9","query_rope")) {
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        TP->move_player("up the rope#players/whisky/quest/room/ravine9");
      }
     else {
      write("There is no rope hanging down.\n");
     }
     break;
     case "rope 1":
     case "south rope":
     if (call_other(PATH+"ravine8","query_rope")) {
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        TP->move_player("up the rope#players/whisky/quest/room/ravine8");
      }
     break;
     case "rope 2":
     case "north rope":
     if (call_other(PATH+"ravine9","query_rope")) {
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        write("******* U F F  you are climbing up the rope. ********\n");
        TP->move_player("up the rope#players/whisky/quest/room/ravine9");
      }
     break;
     default:
     write("You can't do that.\n");
     return 1;
    }
   return 1;
  } 

  
   
