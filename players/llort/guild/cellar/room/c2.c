/* 971010, Uglymouth: recoded to use /room/doorroom.c now.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

#include "../cellar.h"

void reset( int arg ) {
  clone_list = ({
    1, 3, "bat", MONST + "bat", 0,
  });
  set_light( 0 );
  short_desc = "In a cellar";
  long_desc = "You are in the dark cellar of the Mages Tower. "
    + "It's cold and wet here, but the smell of fresh cheese "
    + "really makes you hungry. The vault smells after bad wood. "
    + "There is a wall to the east and north. The corridor "
    + "leads further to the south. A door leads west\n";
  dest_dir = ({
    ROOM + "c4", "west",
    ROOM + "c1", "south",
  });
  items = ({
    "vault","An old oak-wooden vault",
    "wall","A grey stone wall",
    "walls","Grey stone walls",
    "bottom","A dark stone bottom",
    "door", "You mean the cellar door?",
    "cellar door", "dummy door description",
  });
  ::reset( arg );
  set_door( "cellar door" );
  set_door_desc( "cellar door", "It looks like a normal cellar door. "
    + "It has an iron lock on it" );
  set_door_direction( "cellar door", "west" );
  set_lock_status( "cellar door", DOOR_LOCKED );
  set_door_key( "cellar door", "cellardoor" );
  set_door_reset( "cellar door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "cellar door", "The cellar door slams shut.\n" );
  set_other_door( "cellar door" );
  replace_program( DOOR_ROOM );
}       
