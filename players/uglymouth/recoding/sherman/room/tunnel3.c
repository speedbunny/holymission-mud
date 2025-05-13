#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 0 );
  short_desc = "At the entrance of a damp tunnel, dug out in clay soil.";
  long_desc = "You are standing just inside the entrance of a tunnel at "
    + "the eastern foot of a gloomy hill. The tunnel has been dug in the "
    + "clay soil of the hill. On its walls and ceiling moulds and slimes "
    + "grow abundantly. To the east you notice some graves.\n";
  dest_dir = ({
    ROOM_DIR + "tunnel2", "west",
    ROOM_DIR + "cemetry1", "east",
  });
  items=({
    "tunnel", "A clay tunnel runs west from here into the darkness "
      + "of the hill's heart",
    "entrance", "The entrance of the tunnel has been reinforced with stones",
    "stones", "Plain reddish brown bricks covered with slimes",
    "hill", "It doesn't look all that impressive, but a feeling of "
      + "doom surrounds it",
    "soil", "Dried dark brown clay gone humid again",
    "clay", "Dirty, sticky clay of the darkest brown you've ever seen",
    "walls", "The dark brown clay walls are hardly visible underneath "
      + "their coat of slimes",
    "ceiling", "Long strands of hairy moulds hang down from it, getting "
      + "tangled in your hair",
    "slimes", "The bright orange slimes with dark red spots make you "
      + "feel uneasy",
    "moulds", "The sticky purple moulds go nicely with the colour of your "
      + "hair, which by now contains lots of it",
    "graves", "It looks like a small cemetery from here",
  });
  smell = "The air is filled with the rotting smell the moulds and "
    + "slimes produce.\n";
  clone_list = ({
    1, 1, "ghoul", MON_DIR + "ghoul", 0,
  });
  ::reset( arg );
  replace_program( "room/room" );
}
