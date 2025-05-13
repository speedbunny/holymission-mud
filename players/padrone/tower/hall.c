// 02-17-93: This room changed by Cashimor
// 03-09-93: Cashimor: Changed once again
// 11-27-94: Mangla: Changed to make hacks by several people more reasonable.
// 11-27-94: Cannot go up in the room at all. Could not see where the
//               complain on the code change board came from. If you
//               wish for the up to go back in so that the dragon can
//               clone then please let me know and I will change.
//  09-13-97: Uglymouth: Changed to use /room/doorroom.c and improved old code.
#include <doorroom.h>

inherit DOOR_ROOM;

object the_dragon;
status no_dragon;

void reset( int arg ) {
  if( !the_dragon ) no_dragon = 1;
  else if(environment(the_dragon)!=this_object())
    the_dragon->move_player( "X#" + file_name( this_object() ) );
  ::reset( arg );
  if( arg ) return;

  set_light( 1 );
  short_desc= "The Tower Hall";
  long_desc = "You are in the hall of Padrone's private tower. This is a big "
    + "and spacious hall, so the interior of the tower must have been "
    + "expanded using magic. Several doors lead to other rooms. A "
    + "small ladder in one corner leads up, and a stone stairway "
    + "leads down into the tower. There is a small note on the door "
    + "leading north.\n";
  dest_dir = ({
    "players/padrone/tower/bedroom", "south",
    "players/padrone/tower/lab", "east",
    "players/padrone/tower/poolroom", "west",
    "players/padrone/tower/tower4", "down",
    "players/padrone/tower/tower_top", "up",
  });
  hidden_dir = ({
    "players/padrone/tower/rambo_room", "north",
  });
  items = ({
    "tower", "It looks vast and magnificent",
    "hall", "It has a very magical look",
    "doors", "They are exquisitely carved",
    "door", "north door dumy description",
    "ladder", "A small rickety ladder in one corner of the room. It"
      +" doesn't look that strong now, but it should be safe",
    "stairway", "It looks very solid",
    "note", "It has only recently been put up",
  });

  set_door( "door" );
  set_door_desc( "door",
    "This is a stout wooden door, several inches thick. "
    + "It has a moderate-security lock in the centre. "
    + "There is a small note nailed to it:\n"
    + "\t'Don't go in here. The guards have gone crazy again.'" );
  set_door_direction( "door", "north" );
  set_lock_status( "door", DOOR_LOCKED );
  set_door_key( "door", "treasurydoor" );
  set_door_reset( "door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "door", "The stout wooden door slams shut.\n" );
  set_other_door( "door" );
}

void init() {
  ::init();
  add_action( "do_read", "read" );
}

void make_dragon() {
  object key;

  the_dragon = clone_object( "players/whisky/obj/std_dragon" );
  the_dragon->set_colour( "steel" );
  the_dragon->set_age( 5 );
  the_dragon->set_silent( 1 );
  the_dragon->set_no_follow();
  the_dragon->set_no_steal();
  the_dragon->set_match( this_object(),
    /* function              type             match */
    ({ "ticket_check" }), ({ "arrives" }), ({ "" }) );
  key = clone_object( "obj/thing" );
  key->set_name( "moderate-security key" );
  key->set_alias( "key" );
  key->set_alt_name( "treasurydoor" );
  key->set_short( "A moderate-security key" );
  key->set_long( "This is a moderate-security key. "
    + "You wonder where it fits...\n" );
  key->set_value( 10 );
  transfer( key, the_dragon );
  move_object( the_dragon, this_object() );
} 

status move( string str ) {
  string name;

  if( !stringp( str ) ) str = query_verb();

// Mangla: Moved query_name up here since it was used in the first if
//      but not defined until INTO the else.
// Uglymouth: changed query_name() to query_short_name()
  name = this_player()->query_short_name();
  if( str != "up" ) return ::move( str );
// Note that the presence of ANY dragon will prevent moving up...
  if(!present("dragon",this_object())) {
    if(no_dragon) {
      printf( "As you try to climb the ladder, an alarm sounds!\n\
A giant steel dragon shows up to investigate!\n");
      say(sprintf("As %s tries to climb the ladder, an alarm sounds!\n\
A giant steel dragon shows up to investigate!\n",name));
      make_dragon();
      no_dragon=0;
      return 1;
    }
    else
      return ::move(str);
  }
  else {
    printf( "You cannot pass the dragon.\n" );
    say( sprintf( "%s tries to climb the ladder, but the dragon bars the way.\n",
      name ) );
    return 1;
  }
}

int do_read( string str ) {
  if( str != "note" && str != "small note" && str != "door note" ) {
    notify_fail("Read what?\n");
    return 0;
  }
  printf( "The small note on the north door says:\n"
    + "\t'Don't go in here. The guards have gone crazy again.'\n" );
  return 1;
}


void ticket_check( string str ) {
  string who, rest;
  object suspect;

  /* Some strange error or wizard entering! */
  if( sscanf( str, "%s arrives%s", who, rest ) != 2 ) return;
  suspect = present( lower_case( who ), this_object() );
  if( !suspect ) return;  /* Already gone! */
  if( present( "castle ticket", suspect ) ) return;  /* everything ok */

//  The dragon was to attack any player without a ticket at this point.
//      This was changed to not happen. The say was also redone to reflect
//      what would actually happen in a circumstance like this. As it was
//      before the player was not told anything.
  tell_room( this_object(), sprintf( "The dragon notices that %s "
    + "does not have a ticket. From deep in his stomach he rumbles:\n"
    + "\tYou would be wise to get a ticket!\n", who ) );
  /* the_dragon->attacked_by(suspect); */
}

