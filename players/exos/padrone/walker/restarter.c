#include "walker.h"

void restart_castle() {
  call_out("load_walker", 10);
}

/*  This function will destruct the walking castle and load it.
 *  Then it will move it back to the place where it was.
 */
load_walker() {

  object the_castle, the_castle_env, new_castle;

/* The mover has already been destructed, from the castle itself. */

  the_castle = find_object(CASTLE);
  if (the_castle) {
    the_castle_env = environment(the_castle);
    destruct(the_castle);
    call_other(CASTLE, "short");	/* This loads the walking castle. */
    new_castle = find_object(CASTLE);
    if (the_castle_env) {
      move_object(new_castle, the_castle_env);
      tell_room(the_castle_env, "The walking castle malfunctions!\n");
      tell_room(the_castle_env, "It shimmers strangely, but then " +
                                "it seems to be all right again.\n");
    }
  }

  destruct(this_object());
}
