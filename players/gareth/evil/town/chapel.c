#include "/players/gareth/define.h"

inherit "room/room";
int searched;

void reset(int arg){
  ::reset(arg);
  if(!arg) {

  set_light(1);
  short_desc = "Chapel of Evil";
  long_desc = 
   "This place is made of red stone, the floor being a mosaic\n"+
   "checker board of black and red.  The east wall is covered by\n"+ 
   "a dark tapestry. The other three walls are decorated by a\n"+ 
   "mural which depicts a black landscape, barren trees and\n"+
   "unidentifiable but horrid black shapes in silhouette - maybe\n"+
   "demons of some sort - holding a struggling baby silver dragon,\n"+
   "The sky is gray and torn by wisps of purple clouds and a bloody\n"+
   "moon with a skull-like face looking down on the scene. There\n"+ 
   "are four black pillars that support the dome ceiling overhead.\n"+
   "Between the columns, just in front of the eastern wall, is a\n"+
   "stone altar of red veined black rock.\n";
  
  items = ({
    "altar","Black and red, covered in blood and other things",
    "tapestry","A dark depiction of the killing of good dragons",
    "pillars","Large, thick columns made of black and red stone",
    "columns","Large, red and black that hold up the dome top",
          });
    
  dest_dir = ({
    ETOWN+"tr9","east",
    ETOWN+"summon","southwest",
             });

}
}
  void init() {
    ::init();
    add_action("search","search");
  }

  status search(string str){
      if(!str || str!="alter"){
          notify_fail("search what?\n");
          return 0;
      }
      if(!searched){
          write("You find a goblet on the alter which you quickly take.\n");
          transfer(CO(ITEM+"goblet"), TP);
          searched = 1;
          return  1;
}
  
  write("You search but the alter, but all you see is dried blood.\n");
     return 1;

}
  string alter() {
    if(!searched)
        return "The looks like there's something on the alter";
    else
        return "The alter appears to have been disrupted recently";
}
