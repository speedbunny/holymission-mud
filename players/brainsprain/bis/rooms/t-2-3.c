inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

int climb(string arg){
  if (arg != "down"){
    write("Climb where?\n");
    return 1;
  }
  else{
    write("You climb down to the second floor.\n");
    this_player()->move_player("down#/players/brainsprain/bis/rooms/t-2-2.c");
    return 1;
  }
}

int jump(){
  if(this_player()->query_dex() >= random(30)){
    write("You jump up and pull yourself through the trapdoor.\n");
    this_player()->move_player("jumps up#/players/brainsprain/bis/rooms/t-2-4.c");
    return 1;
  }
  else {
    write("You miss the opening and fall hard on your butt.\n");
    this_player()->hit_player(random(5));
    return 1;
  }
}


void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  
  short_desc = "Third floor of southwestern tower";
  long_desc =
    "A trapdoor hangs open from the ceiling, however, there is no ladder "+
    "leading to it.  From above, the sound of a forge are evident.  A massive "+
    "shadow staggers across the light filtering through the trapdoor.\n";
  set_light(1);
  items = ({
    "ceiling",
    "There is a trapdoor hanging open in the middle of it",
    "light",
    "It casts a deformed shadow through the trapdoor",
    "ladder",
    "A ladder leading down to the next floor",
    "trapdoor",
    "A door hanging open from the ceiling, you might be able to 'jump' to it",
    "shadow",
    "A hugely deformed shadow",
  });
}
void init(){
  ::init();
  add_action("jump","jump");
  add_action("climb","climb");
  }
