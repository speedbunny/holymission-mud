#define PR "players/bobo/krooms/mountains/suspension"
#include "/players/mangla/defs.h"

reset(arg) {
  if (!arg) {
    set_light(1);
  }
} /* reset */

init() {
  add_action("east","east");
  add_action("west","west");
  add_action("climb","climb");
} /* init */

short() {
    return "On a path";
}

long(str) {
   object all; 
   int count,i;

   if(!str) {
     write("You are standing on an path in the mountains.\n" +
           "The path runs east-west. High above you leads a suspension bridge over this\n" +
           "valley.\n");
     if(PR->query_rope())
       write("There is a rope hanging down from the bridge.\n");
     write("    There are two obvious exits: east and west\n");
     return;
   }
   if(str=="bridge") {
     write("It's is a long way down, so don't try to jump.\n"+ 
           "You cannot make out anything special at the bridge.\n");
     all=all_inventory(PR->query_me());
     count=0;
     for(i=0;i<sizeof(all);i++) 
       if(living(all[i])) count++;
     if(count==1) 
       write("Except one creature.\n");
     else if(count>1) 
       write("Except some creatures.\n");
     return;
   }
   if(str=="rope") {
     if(PR->query_rope())
       write("Never seen a rope before?\n");
     else
       write("There is no rope here.\n");
     return;
   }

} /* long */

id(str) { return !str || str=="bridge" || str=="rope"; }

east() {
   TP->MOVEP("east#players/bobo/krooms/mounatins/path10");
  return 1;
}

west() {
   TP->MOVEP("west#players/bobo/krooms/mountains/path11");
  return 1;
}

climb() {
  if(PR->query_rope()) {
    write("Fortunately a rope is hanging down from above.\n"+ 
          "You grab the rope and climb up.\n");
    TP->MOVEP("up#players/bobo/krooms/mountains/suspension");
    return 1; 
  }
  write("There's no way of climbing up, the rocks are to steep.\n");
  return 1;
}

query_me() { return this_object(); }
