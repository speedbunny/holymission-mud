#include "../monkway.h"
inherit "room/room";
    object rat;
    int i; 

reset(arg) {
  i=0;

  if (arg) return;
  set_light(1);
  short_desc = "In a ravine";
  long_desc =
    "You are standing in a ravine. There are big rocks to\n"+
    "the north and south. A small path is leading further to the.\n"+
    "west and east. There are some heavy stones lying on the bottom.\n"+
    "To the north you see a tiny grey gravestone.\n";
  items =
    ({
     "rocks","Big grey rocks",
     "rock","A big grey rock",
     "path","A small path leading further to the west and east",
     "stone","A big grey stone",
     "stones","Big grey stones",
     "bottom","A grey stony bottom",
     "gravestone",
       "          *********************    \n"+
       "         *                     *   \n"+
       "        *    REST IN PEACE !    *  \n"+
       "       *                         * \n"+
       "       *    Mario, Joe, Jack     * \n"+ 
       "       *    Sandra, David, Kim   * \n"+
       "       *    Betty, Kurt, Tim     * \n"+
       "       *    Ann, Cindi, Sandra   * \n"+
       "       *    Gorg, Ern, Patric    * \n"+
       "     * *                          * *\n"+
       "     *   And all the rest of the    *\n"+
       "     *   1000 heros who tried to    *\n"+
       "     *   go this way !              *\n"+
       "     *                              *\n"+
       "   ************************************\n",
     "sky","A clear blue sky" });
  dest_dir =
     ({
     PATH+"ravine1","east", 
     PATH+"ravine3","west" });

  }
  init() {
    if (rat=present("rat")) call_out("run",8,rat);
    add_action("search","search");
    add_action("pass","pass");
    add_action("pass","climb");
    ::init();
   }

  run(arg) {
    if (arg) command("west",arg);
    }

  search(arg) {
   object rope;

   switch(arg) {
    case "rock":
    case "rocks":
    write("You search under the rocks, but find nothing.\n");
    say(TPN+" searches under the rocks, but finds nothing.\n");
    break;
    case "stone":
    case "stones":
    if (i < 1) {
       rope=clone_object("obj/rope");
       move_object(rope,E(TP));
       write("You search under the stones, and find a rope.\n");
       say(TPN+" searches under the stones, and finds a rope.\n");
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
    

  
   
