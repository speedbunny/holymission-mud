#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 0 );
  short_desc = "Half-way in a damp tunnel, dug out in the clay soil.";
  long_desc = "You are walking along a tunnel dug out in the clay soil of "
    + "a hill. Its walls and ceiling are scattered with patches of slimes "
    + "and moulds. Further east in the distance you see dim daylight.\n";
  dest_dir = ({
    ROOM_DIR + "tunnel1","west",
    ROOM_DIR + "tunnel3","east",
  });
  items=({
    "tunnel", "A clay tunnel under a hill running east and west from here",
    "soil", "Dried dark brown clay gone humid again",
    "clay", "Dirty, sticky clay of the darkest brown you've ever seen",
    "hill", "You feel its heavy presence all around you",
    "walls", 
      "Cold, humid, dark brown walls of dried clay. Slimes cover most of it",
    "ceiling", "The water condensating on it fertile clay soil make it "
      + "a mould's heaven",
    "slimes", "Disgustingly brown and grey slimes seem to be doing well "
      + "in this climate",
    "moulds", "Dirty blueish moulds grow everywhere, in particular on "
      + "the ceiling",
    "daylight", "The light coming from the end of the tunnel",
  });
  smell = "The air is filled with the rotting smell the moulds and "
    + "slimes produce.\n";
  clone_list = ({
    1, 1, "sign", ITEM_DIR + "warnsign", 0,
  });
  ::reset( arg );
  replace_program( "room/room" );
}
