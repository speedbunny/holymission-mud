#include "/players/gareth/define.h"

inherit "room/room";
int searched;

void reset(int arg){
  ::reset(arg);
  if(!arg) {

  set_light(1);
  short_desc = "Common room";
  long_desc = 
   "Woven Rugs cover most of the floor in this room. There's a \n"+
   "large bookcase, filled with books, leaning against the \n"+ 
   "southern wall. Several large, padded chairs sit up against\n"+ 
   "the rest of the walls. A few large over stuffed pillows lie\n"+
   "on the floor. The Room is painted in dark purple and gray.\n"+
   "There are paintings hanging up on each wall.\n";
  
  items = ({
    "paintings","Violent depictions of dark elves kill dragons",
    "pillows","Large over stuffed pillow - It looks rather comfortable",
    "rug","A large blue woven rug",
    "bookcase","large bookcase filled with many books",
    "shelf","Brown wooden shelf",
    });
    
  dest_dir = ({
    ETOWN+"lvl4b","north",
    ETOWN+"lvl4d","west",
    ETOWN+"lvl3d","down",
             });

}
}
  void init() {
    ::init();
    AA("_search","search");
  }


  status _search(string str){
      if(!str || str!="bookcase"){
          NF("search what?\n");
          return 0;
      }
      if(!searched){
          write("You find a books what else?.\n");
          TR(CO(ITEM+"book"), TP);
          searched = 1;
          return  1;
}
  
  write("You search but the bookcase is bare.\n");
     return 1;

}
  string bookcase() {
    if(!searched)
        return "There are old books on in the bookcase";
    else
        return "The books appear to be in disorder";
}

