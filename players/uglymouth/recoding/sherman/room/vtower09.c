#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  clone_list = ({
    1, 3, "vampire guard", MON_DIR + "vguard", 0,
  });
  ::reset( arg );
  if( arg ) return;

  set_light( 0 );
  short_desc = "In the anteroom of vampire lord's hall.";
  long_desc = "You have arrived in what seems to be the anteroom to the "
    + "room the vampire lord has chosen to be his new hall. A black velvet "
    + "curtain hangs in the doorway to the hall. Muffled sounds come from "
    + "beyond it. Two obsidian statues of bats border the entrance. In the "
    + "south wall, you see the outlines of a sliding panel.\n";
  dest_dir = ({
    ROOM_DIR + "vtower10", "north",
  });
  items=({
    "anteroom", "Just a bare room where unimportant guests are kept waiting",
    "hall", "You cannot see it through the curtain",
    "curtain", "Thick, expensive black velvet, bordered with gold thread",
    "doorway", "A square hole in the wall. Nothing special about it",
    "statues", "Detailed statues of a couple of vampire bats",
    "bats", "Forged by a skilled craftsman, but boy, are they ugly",
    "wall", "A thick stone wall. There's a sliding panel in it",
    "panel", "You can push it to go to the area at the other side",
    "sliding panel", "You can push it to go to the area at the other side",
  });
}

void init() {
  ::init();
  add_action( "do_push", "push" );
}

// Guards won't block players passing through. They're easier prey when (if)
//   they return...
int do_push( string str ) {
  if( member_array( str, ({ "sliding panel", "panel", "wall" }) ) == -1 )
    return 0;
  printf( "As you push the sliding panel, it turns and sweeps you into "
    + "the space beyond.\n" );
  say( "A sudden gust of chilly air blows into your face.\n", TP );
  TP->move_player( "through the sliding panel#" + ROOM_DIR + "vtower08" );
  return 1;
}

