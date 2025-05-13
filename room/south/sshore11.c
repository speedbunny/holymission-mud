/* sshore11 */

inherit "/room/south/shore";
#include "_defs.h"

object scroll;

string add_long() {
  return("This looks like a good place to swim. " +
         "The shore of Crescent Lake continues east and west\n");
}

string *add_dirs() {
  return ({
    PATH+"sshore10","east",
    PATH+"sshore12","west",
  });
}

void reset(int arg) {
  scroll = 0;
  ::reset(arg);

}

void init() {
  ::init();
  add_action("_swim", "swim");
}

int _swim() {

  if(!scroll) {
    write("As you frolic in the clear water, your knee bumps something.\n" +
          "Reaching down and uncovering the rest of the object, you discern\n" +
          "it to be a very old scroll.\n");

    scroll = clone_object("players/whisky/quest/obj/scroll");
    if(objectp(scroll)) {
      if(transfer(scroll, this_player())) {
        move_object(scroll, this_object());
      }
      else {
        write("You decide to stick it in your inventory.\n");
      }
    }
  }
  else {
    write("You frolic in the clear waters.\n");
  }
  return 1;
}
