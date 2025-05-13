#include "/room/room_defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 1 );
  short_desc = "The beginning of Oaks Lane";
  long_desc = "You walk along the beautiful Oaks Lane, so called because "
    + "of the four big oaks growing along it. The area around Oaks Lane "
    + "is mostly a residential quarter. To the north and south you see "
    + "some nice wooden houses. To the east lies Rich Men's Road.\n";

  dest_dir = ({
    HM_VILLAGE + "road5", "east",
    HM_VILLAGE + "lane2", "west",
  });

  items = ({
    "rich men's road","The brick road through the richer part of "+
      "the village",
    "oaks lane", "A red brick road leading through a residential quarter",
    "oaks", "Four big, green oaks. They are as old as this village is",
    "houses", "To the north lies a yellow house, to the south a green one",
    "yellow house", "It looks well maintained, but it's void of decorations",
    "green house", "It could use a new paint, but it looks pleasant enough",
  });

  ::reset( arg );
  replace_program( "room/room" );
}

