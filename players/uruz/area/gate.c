#include <doorroom.h>
#include "/players/trout/defs.h"

inherit DOOR_ROOM;

void reset( int arg ) {
  clone_list = ({
    1, 3, "guard", MM+"/guard1", 0,
    2, 1, "captain", MM+"/guard2", 0,
   -2, 1, "key", YY+"/obj/key2", 0,
  });

  set_light( 1 );
  short_desc = "Honno Ji Gate";
  long_desc = "This is the gate to Honno Ji. The temple is surrounded "
    + "by a high stone wall. The 12 foot iron gate is usually heavily "
    + "guarded. This appears to be the only way in.\n";
  dest_dir = ({
    ZZ+"/mroad3", "north",
    ZZ+"/ward4", "south",
  });
  items= ({
    "gate", "It looks pretty solid",
    "wall", "A tall stone wall",
    "Honno Ji", "The temple towers above you, coming gradually to a point",
  });
  ::reset(arg);

  set_door( "gate" );
  set_door_desc( "gate", "This tall, iron gate looks very strong. " );
  set_door_direction( "gate", "south" );
  set_lock_status( "gate", DOOR_LOCKED );
  set_door_key( "gate", "gatekey" );
  set_door_reset( "gate", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "gate", "The gate swings shut.\n" );
  set_other_door( "gate" );

  replace_program( DOOR_ROOM );
}
