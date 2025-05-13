/* 970915, Uglymouth: using /room/doorroom.c and replace_program() now.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_light(1);
  short_desc = "The Mayor's garden.";
  long_desc = "This is a lush beautiful place full of flowers "
    + "and shrubberies. There is a cobblestone path that leads "
    + "from the main road east to the door of the mayor's house. "
    + "There is another path that leads around the mayor's "
    + "house as well.\n";
  dest_dir = ({
    "players/kelly/rooms/vill/road1", "west",
    "players/kelly/rooms/vill/mayorpath", "southeast",
  });
  hidden_dir = ({
    "players/kelly/rooms/vill/mayorhouse", "east",
  });
  items = ({
    "door","dummy door description",
    "flowers","A wide variety of garden flowers are in this area",
    "shrubberies","The shrubs make intricate pattrerns on the lawn",
    "path","It seems that the path hasn't been used for a long time",
    "house","It's the mayor's house. It's very big and splendid",
    "cobblestone","A nice cobblestone path leads to the house",
  });
  property = ({ "no_clean_up" });

  set_door( "door" );
  set_door_desc( "door",
    "A wooden door without a lock, leading into the house of the mayor" );
  set_door_direction( "door", "east" );
  set_door_reset( "door", ({
    "set_door_status", DOOR_CLOSED,
  }) );
  set_door_reset_msg( "door", "The door swings shut.\n" );
  set_other_door( "door" );
  replace_program( DOOR_ROOM );
}

