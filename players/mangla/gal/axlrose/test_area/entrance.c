inherit "/players/sauron/inherit/border_room";

#include "/players/sauron/include/virtual.h"

int do_ser(string str) {
  if(str=="room") {
    write("You search the room.\n");
    say(this_player()->query_real_name(1)+" searches the room.\n");
    if(!random(2))
      write("You found yourself!\n");
    return 1;
  }
  else if(str=="floor") {
    write("You search the floor.\n");
    say(this_player()->query_real_name(1)+" searches the floor.\n");
    if(!random(2))
      write("You found some dust, but it slipped through your fingers \
as you tried to take it!\n");
    return 1;
  }
  else {
    return 0;
  }
}

void reset(int arg ) {
  if(!arg) {
    set_light(1);
    short_desc="Axl's test area entrance.";
    long_desc="\
This room is the entrance to the test virtual area managed by the \
master.c in this directory. If you have not entered this room \
from my workroom, and the virtual area is not initialised, you will \
get an error. The answer is to update everything in this directory, \
and enter from my workroom as you are supposed to. :)\n";
    add_exit("up","/players/axlrose/workroom");
    add_exit("down","/players/axlrose/test_area/master,3,3,0");
  }
  ::reset(arg);
}
