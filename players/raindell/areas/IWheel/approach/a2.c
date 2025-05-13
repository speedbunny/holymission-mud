#include "/include/defs.h"
inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="A cramped, overgrowtn path"; 
  long_desc="\nThe path here might as well not exist, considering the close\n"
            "press of trees on either side. In fact, the only way you're sure\n"
            "that you're still on the path, is that you haven't run head-on into\n" 
            "a tree. Through the bushes to the south, you can hear the distinct\n"
            "sound of flowing water.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a1","north",      
           });

  items=({"trees","If you ever wished for an extreme close-up of a tree, this is where to see it", 
          "path","It is completely obscured from sight",
          "bushes","Though the bushes are thick, you think you could 'part' them",
         });
}


void init() {

   ::init();

   add_action("_part","part");
 }
     int _part(string str) {
     if(str!="bushes") return 0;
     write("You push your way through the bushes.\n");
     MP("into the bushes carefully.#players/raindell/areas/IWheel/approach/a3.c");

   return 1;

   }

