inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

int get(string arg){
  if(arg=="shirt" || arg == "t-shirt"){
    write("As you try to take a shirt the protective aura zaps you!\n");
    this_player()->hit_player(10);
    return 1;
  }
}

void reset(int arg) {
  ::reset(arg);
  if(arg) return;  
  short_desc = "Bismarck Hall";
  long_desc =
    "Here sits the stand of Origard, the only liscensed solicitor in the "+
    "castle.  On racks are shirts of various sizes, all with the slogan "+
    "'I Love the Count'.  However, Origard is not in right now, so the "+
    "stand is closed.  The aura of a protection spell crackles as you step "+
    "near the stand.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-13.c","north",
    br+"/ch-11.c","south",
  });
  items = ({
    "origard",
    "He is not here",
    "racks",
    "They are covered in shirts",
    "stand",
    "A tee-shirt stand",
    "shirts",
    "'I love the Count'",
    "aura",
    "The aura of a protection spell",
  });
}
void init(){
  ::init();
  add_action("get","get");
  }

