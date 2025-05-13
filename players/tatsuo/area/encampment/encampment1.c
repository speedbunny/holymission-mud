/* 971014, Uglymouth: Using /room/doorroom.c now + general code upgrade.
 */
#include <doorroom.h>
#include "/players/tatsuo/area/tatsuo_defs.h"

inherit DOOR_ROOM;

#include ROOM_FUNCTS

int opening;

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_light( 1 );
  short_desc= "The courtyard";
  long_desc = "The courtyard ahead is swarming with activity. You see "
    + "wolfen carrying parcels here and there.  The steel reinforced "
    + "gate to the encampment lies directly to the south. You think "
    + "you had better move before you get in the way of the gate opening "
    + "or closing.  A platform is directly above you, and is supported "
    + "by four thick wooden legs. Stairs lead upwards to the east and "
    + "the west.\n";
  dest_dir = ({
    CAMPPATH + "encampment2", "north",
    F2PATH + "road10", "south", 
    CAMPPATH + "palisade1", "eastup",
    CAMPPATH + "palisade11", "westup",
  });
  items = ({ 
    "palisade", "A large 18ft wall which encircles the encampment. "
      + "A wolfen guard stands on top.",
    "wolfen", "A large burly wolfen guard who eyes you warily",
    "gate", "A strong gate which can be held shut by a large wooden beam",
    "steel", "It looks very strong, you don't think you could break it",
    "packages", "Parcels that are being carried to a building in the north",
    "platform", "That is were the lookout and the guards stand",
    "eastern stairs", "These lead up to the palisade",
    "western stairs", "These lead up to the palisade",
    "stairs", "Which set of stairs?",
    "legs", "Large wooden beams that support the platform above",
  });
  smell = "You don't smell anything special.";

  set_door( "gate" );
  set_door_dependent( "gate", F2PATH + "road10" );
  enable_commands();
  clone_x_of_y( ( 1 - filter_live( this_object(), "gatekeeper" ) ),
    MPATH + "gatekeeper.c" );
}

void catch_tell( string str_arg ) {
  string player_name, krap;

  if( sscanf( str_arg, "%s says: open %s", player_name, krap) != 2 )
    return;
  if( opening ) {
    call_out( "wait", 1 );
    return;
  }
  this_object()->control();
}

void wait() {
  tell_room( this_object(),
    "Gatekeeper says:  I'm working as fast as I can.\n" );
}

void control() {
  opening = 1;
  call_out( "open_gate", 2 );
  call_out( "gate_opened", 3 );
  call_out( "gate_closed", 10 );
  call_other( F2PATH + "road10.c", "control" );
}

void open_gate() {
  set_lock_status( "gate", DOOR_UNLOCKED );
  tell_room( this_object(),
    "You see the gatekeeper straining under pressure.\n" );
}

void gate_opened() {
  set_door_status( "gate", DOOR_OPEN );
  tell_room( this_object(),
    "The gate swings wide open and the Gatekeeper motions "
    + "for you to exit.\n" );
}

void gate_closed() {
  set_door_status( "gate", DOOR_CLOSED );
  set_lock_status( "gate", DOOR_LOCKED );
  opening = 0;
  tell_room( this_object(), "The Gatekeeper pulls the gate closed.\n" );
}

