#include "/players/gareth/define.h"

inherit "room/room";
int opened, searched;

void reset(int arg){
  ::reset(arg);
  if(!arg) {

  set_light(1);
  short_desc = "Kitchen and dining room";
  long_desc = 
   "Four Tables, each with four chairs are spaced evenly in the\n"+
   "center of the room, there's larger table, with half a dozen \n"+ 
   "chairs around it. One third of the room is taken up with cup-\n"+ 
   "boards that most likely contain dishes. Other cabinets looks \n"+
   "as though they may contain food.  There are metals pans hanging\n"+
   "from the ceiling, as well as a glowing rock.\n";
  
  items = ({
    "tables","normal tables for eating on",
    "large table","A large table covered with a dark linen cloth",
    "linen cloth","dark piece of cloth used to cover tables",
    "cupboards","place where dishes are stored",
    "rock","it's glowing and hang from the ceiling by a chain",
    "chain","chain that connects rock to cieling, it's made of metal",
           });
    
  dest_dir = ({
    ETOWN+"lvl4c","east",
    ETOWN+"lvl4a","south",
             });

}
}
  void init() {
    ::init();
    AA("_search","search");
    AA("_open","open");
  }

  status _open(string str){
      if(str!="cabinet" && str!="cabinets")
          return 0;

      if(!opened) {
          write("There's some nourishment in here.\n");
          TR(CO(ITEM+"cola"), TP);

          opened = 1;
          return 1;
}       
          write("The cabinet is already opened.\n");
          return 1;
}

  status _search(string str){
      if(!str || str!="pan"){
          NF("search what?\n");
          return 0;
      }
      if(!searched){
          write("You find some food.\n");
          TR(CO(ITEM+"burger"), TP);
          searched = 1;
          return  1;
}
  
  write("the pan is empty.\n");
     return 1;

}
  string pan() {
    if(!searched)
        return "The looks like there's something in the pan";
    else
        return "A hungry person came before you did";
}

  string cabinet() {
    if(!opened)
        return "The cabinet is closed";
    else
        return "The cabinet has been open prior to your arrival";
}

