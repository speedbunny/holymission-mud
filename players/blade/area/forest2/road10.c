/* 971014, Uglymouth: Using /room/doorroom.c now + general code upgrade.
 */
#include <doorroom.h>
#include "/players/blade/area/blade_defs.h"

inherit DOOR_ROOM;

int opening;

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_light( 1 );
  short_desc = "A road in front of a large gate",
  long_desc =   "This road is well worn with the grooves of cart tracks. "
    + "The road is fairly level, making for easy travelling. The road "
    + "turns north here, and enters a large gate in the palisade. The gate "
    + "is made of reinforced steel and opens inward. You notice a lookout "
    + "and two bowmen looking at you from atop the gate.\n";
  dest_dir = ({
    CAMPPATH + "encampment1", "north",
    F2PATH + "road9", "east", 
    F1PATH + "forest44", "south",
    F1PATH + "forest48", "west",
  });
  items = ({ 
    "road", "A long dusty road that looks well used",
    "tracks", "There are many deep gouges in the road",
    "palisade", "A large 18ft wall which encircles the encampment. "
      + "A wolfen guard stands on top",
    "guard", "A large burly wolfen guard who eyes you warily",
    "gate", "A strong gate which can be held shut by a large wooden beam",
    "lookout", "He is in charge of who enters the gate and who does not",
    "bowmen", "They are ready to shoot arrows into anyone trying to gain "
      + "unauthorized access to the encampment",
    "steel", "It looks very strong, you don't think you could break it",
    "valley", "Mountains rise up on either side of a small valley",
    "mountains", "Steep mountains that rise in the north and the south",
  });
  smell = "You smell dust from the road.";

  set_door( "gate" );
  set_door_desc( "gate",
    "A strong gate which can be held shut by a large wooden beam" );
  set_door_direction( "gate", "north" );
  set_lock_status( "gate", DOOR_LOCKED );
  set_door_key( "gate", "nothing" );
  set_door_reset( "gate", ({
    "gate_closed", 0,
  }) );
  set_other_door( "gate" );
  enable_commands();
}

void catch_tell( string str_arg ) {
  string player_name, krap;
  
  if( sscanf( str_arg, "%s says: open %s", player_name, krap ) != 2 )
    return;
  if( opening ) {
    call_out( "wait", 1 );
    return;
  }
  else {
    call_other( CAMPPATH + "encampment1.c", "control" );
    write( "Gatekeeper says: Closed for construction!\n" );
    /*      call_out("control",0); */
    return;
  }
}

void wait() {
  tell_room( this_object(),
    "Gatekeeper says: I'm working as fast as I can.\n" );
}

void control(){
  opening = 1;
  call_out( "open_gate", 2 );
  call_out( "gate_opened", 3 );
  call_out( "gate_closed", 10 );
}

void open_gate() {
  set_lock_status( "gate", DOOR_UNLOCKED );
  tell_room( this_object(),
    "You hear someone straining under pressure.\n" );
}

void gate_opened() {
  set_door_status( "gate", DOOR_OPEN );
  tell_room( this_object(),
    "The gate swings wide open and the Gatekeeper beckons "
    + "for you to enter.\n" );
}

void gate_closed(){
  set_door_status( "gate", DOOR_CLOSED );
  set_lock_status( "gate", DOOR_LOCKED );
  opening = 0;
  tell_room( this_object(),
    "The Gatekeeper pulls the gate closed.\n" );
}

