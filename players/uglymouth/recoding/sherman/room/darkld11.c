#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 1 );
  short_desc = "At the top of the third dark hill in a dark land.";
  long_desc = "You stand at the top of the third dark hill. Down the east "
    + "slope you see the ruins of a farm and the black tower looming "
    + "beyond. The hill top is covered with some heather shrubs and patches "
    + "of tall, grey grass. There are more hills to the south. To the north "
    + "lies a huge impenetrable forest. You can only leave this place by "
    + "the same route that brought you here.\n";
  hidden_dir = ({
    ROOM_DIR + "darkld10", "southeast",
  });
  items=({ 
    "top", "From the top you see other hills to the south. It looks like a "
      + "good place to build your last defense, if the need would arise",
    "ruins", "Big piles of rubble. One structure seems to parthly have "
      + "survived the destruction",
    "farm", "Big piles of rubble. One structure seems to parthly have "
      + "survived the destruction",
    "shrubs", "The same dark brown heather shrubs see all over these lands",
    "grass", "Tall dry grass. You wouldn't even feed it to your horse",
    "hills", "They look even more desolate than this place",
    "forest", "From here it looks like a big dark green ground fog",
  });
  ::reset( arg );
  replace_program( "room/room" );
}
