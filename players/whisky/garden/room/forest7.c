#define TP this_player()
#define TPN TP->query_name()
#define TPP TP->query_possessive()

inherit "room/room";
#include "../garden.h"
    object rat;
    string rope;
    int i; 

void reset(int arg) 
{
  i=0;

  if (arg) return;
  set_light(0);
  property = "no_teleport";
  short_desc = "In the dark forest";
  long_desc = BS(
   "You are standing in the northern part of the dark forest. "+
    "There is a hug old spruce tree growing here. To the west "+
    "and east the forest is incredibly dark, it appears to be "+
    "impenetrable. There is a deep pit to the north which seems "+
    "nearly impossible to pass.");

  items =
    ({
     "bottom","A brown earthy bottom",
     "spruce","This spruce could hold any human, a large branch\n"+
              "hangs over the pit",
     "pillow","You see a small pillow",
     "hole","You see a big dark hole", 
    "pit","You see a big dark pit, it seems impossible to pass,\n"+
           "but maybe there is a logical way ?",
     "sky","You see the dark sky" });
  dest_dir =
     ({
     PATH+"forest6","south"
     });
  }

  init() {
    add_action("search","search");
    add_action("tie","tie");
    add_action("untie","untie"); 
    add_action("north","north");
    add_action("north","n");
    add_action("down","down");
    add_action("down","d");
    add_action("jump","jump");
    ::init();
   }
search(arg) {
  write("You search and search, but find nothing.\n");
  say(TPN+" searches around, but finds nothing.\n");
  return 1;
 }
  tie(str) {
    if (str!="spruce") return 0;
    rope=1;
   return 1;
  }
 untie(str) {
   rope=0;
   return 1;
  }
query_rope() { return rope; }
  
  down() {
    TP->move_player("into the pit#players/whisky/garden/room/pit");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("A U T C H you hurt yourself badly.\n");
    TP->hit_player(random(20));
   return 1; 
  }
  north() {
    TP->move_player("into the pit#players/whisky/garden/room/pit");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("A U T C H you hurt yourself badly.\n");
    TP->hit_player(random(20));
   return 1; 
  }
  jump() {
    if (TP->query_weight()<6) {
       write("You make a big jump over the pit.\n");
       say(TPN+" makes a big jump over the pit.\n");
      TP->move_player("over the pit#players/whisky/garden/room/forest8");
      return 1;
     }

    TP->move_player("into the pit#players/whisky/garden/room/pit");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("\n\n***********   You are falling   ***************\n\n");
    write("A U T C H you hurt yourself badly.\n");
    TP->hit_player(random(20));
   return 1; 
  }
