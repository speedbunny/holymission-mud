#include "/players/gareth/define.h"

inherit "room/room";
int searched;

void reset(int arg){
  ::reset(arg);
  if(!arg) {

  set_light(1);
  short_desc = "mage's room";
  long_desc = 
   "This room is lavishly decorated in purple and black. A grand\n"+
   "bed is covered with a patchwork quilt of violet and blue strips\n"+ 
   "At the foot of the bed is a dark grey rug. Beside the bed is a \n"+ 
   "large desk with an oil lamp burning. The painting hanging on the\n"+
   "wall is the only thing that covers this bare room.\n";
   
  items = ({
    "desk","large desk made of polished ivory",
    "rug","large dark grey rug",
    "bed","large king sized bed, looks very comfortable",
    "lamp","ordinary oil burning lamp",
    "oil lamp","an ordinary oil burning lamp",
    "painting","large painting showing drow killing grey elves",
          });
    
  dest_dir = ({
    ETOWN+"lvl3d","west",
    ETOWN+"lvl3a","north",
             });

}
}
  void init() {
    ::init();
    AA("_search","search");
}

  status _search(string str){
      if(!str || str!="desk"){
          NF("search what?\n");
          return 0;
      }
      if(!searched){
          write("You find a scroll on the desk which you pocket.\n");
          TR(CO(ITEM+"ident"), TP);
          searched = 1;
          return  1;
}
  
  write("You desk is cleared.\n");
     return 1;

}
  string shelf() {
    if(!searched)
        return "There are objects on the desk.";
    else
        return "The desk has been cleared before your arrival";
}
