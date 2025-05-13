#include "/players/gareth/define.h"
inherit "room/room";
int ring;
object drow;

void reset(int arg){
  ::reset(arg);
  ring = 0;
  if(!arg) {

  set_light(1);
  short_desc = "Temple of Chaos";
  long_desc = 
    "This room has an arched ceiling at a great height. The floor\n"+
    "is of polished black stone which has swirling patterns of red\n"+ 
    "veins through it. The walls behind the draperies and ceiling,\n"+ 
    "are of dull black rock, while the west wall is of translucent\n"+
    "red stone which is seemingly one piece, polished to a mirror\n"+
    "like smoothness. A huge black bell stands near the entrance\n"+
    "point, with a pair of mallets beside its supports. To the south\n"+
    "are several long benches or pews. To the east there are three\n"+ 
    "stone alters: the northeast alter of pure black, the middle one\n"+
    "of grey, the last of red with black flakes. There are white chairs\n"+
    "lining the southern wall. The walls are covered with draperies\n"+
    "of dark purple, done in crimson and gold thread.\n";
  
  items = ({ 
    "alter","which alter do you mean?",
    "black alter","An alter made of obsidian",
    "alter 1","an alter made of obsidian",
    "grey alter","an alter made of rough granite",
    "alter 2","an alter made of rough granite",
    "red alter","An alter made of unusual substance",
    "alter 3","a crimson colored alter, it's made of strange stuff",
    "bell","A bell made of black iron - looks like it it's used alot",
    "walls","made of poloshed rock - it reflects an image",
    "mallets","mallets used for ringing the bell",
    "benches","long and grey, used for praying",
    "pews","used for praying",
    "chairs","made of white ivory",
    "draperies","seems to be dedicated to the Evil Goddess Lolth",
          });
	MO((CO(MON+"drow_w")),TO);
    
  dest_dir = ({
    ETOWN+"tr3","west",
             });

}
}
  void init(){
       ::init();
       AA("ring", "ring");
}
  int ring(string str){
      if(!str || str!="bell"){
        NF("Ring what?\n");
        return 0;
  }
  write("You ring the bell and a hidden door opens to the east.\n");
  dest_dir = ({
    ETOWN+"pb","east",
    ETOWN+"tr3","west",
                });
  AA("east", "east");
  return 1;
}    
  int east() {
      TP->move_player("east#/players/gareth/evil/town/pb");
      return 1;
}
