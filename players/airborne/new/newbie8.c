/* 971014, Uglymouth: uses /room/doorroom.c now + general code upgrade.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

status searched;

void reset( int arg ){
  ::reset( arg );
  if( arg ) return ;
  set_light( 0 );
  short_desc = "Complete newbie area";
  long_desc = "    You will notice there is a door to the north and "
    + "it is dark here without a light source. You will have to find "
    + "the way to the exit to lesson 7 using some of your newly "
    + "learned skills.\n";
  dest_dir = ({
    "players/airborne/new/newbie8b", "north",
  });
  items = ({
    "door", "dummy door description",
  });
  property = ({
    "no_tport_in",
    "no_tport_out",
    "no_steal",
  });
  searched = 0;

  set_door( "door" );
  set_door_desc( "door", "An iron door" );
  set_door_direction( "door", "north" );
  set_lock_status( "door", DOOR_LOCKED );
//  set_door_key( "door", "newbiedoor" );
  set_door_key( "door", "iron key" );
  set_door_reset( "door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "door",
    "An avatar of Airborne comes in and locks the door.\n" );
  set_other_door( "door" );
}

void init(){
  ::init();
  add_action( "search", "search");
  add_action("leave", "leave");
}

int search( string str ){
  object key;

  if( searched ) {
    notify_fail( "Someone must have been here before you.\n"
      + "There doesn't seem to be anything around.\n" );
    return 0;
  }
  key = clone_object( "/obj/thing" );
  key->set_name( "iron key" );
  key->set_alias( "key" );
  key->set_alt_name( "newbiedoor" );
  key->set_short( "An iron key" );
  key->set_long( "This is an iron key. It is such a simple key "
    + "even complete newbie will know how to use it.\n" );
  key->set_value( 10 );
  transfer( key, this_player() );
  searched=1;
  printf( "You found a key!\n" );
  say( this_player()->query_name() + " has found something!\n",
    this_player() );
  return 1;
}

int leave() {
  printf( "You have stopped the newbie lesson.\n"
   + "Mail Airborne with any comments or suggestions.\n" );
  this_player()->move_player("after stopping the lessons#"
    + "players/airborne/new/station" );
  return 1;
}

