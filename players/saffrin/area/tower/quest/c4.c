/* 971010, Uglymouth: Recoded to use /room/doorroom.c now.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

#include "/players/saffrin/area/tower/quest/cellar.h"

int ok;

void reset( int arg ) {
  ok = 1;
  clone_list = ({
    1, 3, "spider", MONST + "spider", 0,
  });
  ::reset( arg );
  if( arg ) return;
  set_light( 0 );
  short_desc = "In a cellar";
  long_desc = "You are in the cold and musty cellar of the Mage Tower.  "
    + "The smell of fresh cheese fills the room, tempting you nose.   "
    + "Drops of water drip on your neck.  There is a wooden barrel tucked away "
    + "in the corner of the room.  The cellar door is east from here.\n";
  dest_dir = ({
    ROOM + "c2", "east",
  });
  items = ({
    "vault","An old oak-wooden vault",
    "wall","A grey stone wall",
    "walls","Grey stone walls",
    "bottom","A dark stone bottom",
    "barrel","An old wooden barrel",
    "door", "Try using cellar door..",
    "cellar door", "dummy door description",
  });
  set_door( "cellar door" );
  set_door_dependent( "cellar door",
    "/players/saffrin/area/tower/quest/c2");
} 

void init() {
  ::init();
  add_action( "do_search", "search" );
}

int do_search( string str ) {
  object key;

  if( str != "barrel" ) return 0;
  if( !ok ) {
    notify_fail( "You find nothing of interest.\n" );
    return 0;
  }
  printf( "You find a rusty iron key.\n" );
  key = clone_object( "/obj/thing" );
  key->set_name( "iron key" );
  key->set_alias( "key" );
  key->set_alt_name( "cellardoor" );
  key->set_short( "An iron key" );
  key->set_long( "This is the iron key from the cellar.\n" );
  key->set_value( 10 );
  if( transfer( key, this_player() ) ) {
    printf( "You are carrying too much and drop the key.\n" );
    move_object( key, this_object() );
  }
  ok=0;
  return 1;
}
