/* 971010, Uglymouth: Recoded to use /room/doorroom.c now.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

#include "../cellar.h"
#define HOLE    ROOM + "c7"

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_light( 0 );
  short_desc = "In a cellar";
  long_desc = "You are in the dark cellar of the Mages Tower. "
    + "It's cold and wet here and the smell of cheese "
    + "gets stronger and stronger. There is a little "
    + "hole in the eastern wall. The corridor leads "
    + "further to the north and a door leads west.\n";
  dest_dir = ({
    ROOM+"c1","north",
    ROOM+"c5","west"
  });
  items = ({
    "vault", "An old oak-wooden vault",
    "hole",
      "A little dark hole in the eastern wall looking like a rat hole",
    "wall", "A grey stone wall",
    "walls", "Grey stone walls",
    "bottom", "A dark stone bottom",
    "door", "door dummy description",
  });
  set_door( "door" );
  set_door_desc( "door", "It looks like a normal wooden cellar door.\n"
    + "It has an iron lock in it" );
  set_door_direction( "door", "west" );
  set_lock_status( "door", DOOR_LOCKED );
  set_door_key( "door", "cellardoor" );
  set_door_reset( "door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "door", "The cellar door slams shut.\n" );
  set_other_door( "door" );
} 

void init() {
  ::init();
  if( this_player()->query_npc() && this_player()->id( "rat" ) ) 
    add_action( "east","east" );
  else add_action( "enter","enter" );
  add_action( "use","use" );
}

int enter( string str ) {
  if( str != "hole") return 0;
  if( (int)this_player()->query_size() != 1 ) {
    printf( "You're much too fat to enter the rathole.\n" );
    say( this_player()->query_name()
      + " foolishly tries to squeeze into the rathole.\n" );
    return 1;
  }
  printf( "You squeeze yourself into to rathole.\n" );
  this_player()->move_player( "into the rathole#" + ROOM + "c7" );
  return 1;
}

int east() {
  return enter("hole"); 
}

int chk_cheese() {
  if( !present( "cheese", this_player() ) ) {
    printf( "You have no cheese.\n" );
    return 0;
  }
  return 1;
}

int use( string str ) {
  object it,*rats,hole;
  string item;
  int i,rnr;

  if( str == "cheese" ) {
    if( !chk_cheese() ) return 1;
    printf( "On What ?\n" );
    return 1;
  }
  if( str == "cheese on rathole" || str == "cheese on hole" ) {
    if( !chk_cheese() ) return 1;
    if( hole = find_object( HOLE ) )
      rats = all_inventory( hole );
    for( i = rnr = 0; i < sizeof( rats ); i++ )
      if( rats[i]->query_npc() ) rnr++;
    if( rnr < 1 ) {
      printf( "Nothing happens.\n" );
      say( this_player()->query_name()
        + " uses some cheese on the rathole but nothing happens.\n" );
    }
    else {
      tell_room( this_object(), "You hear some squeeking.\n" );
      for( i = 0; i < sizeof( rats ); i++ ) {
        if( random( 2 ) && rats[i]->query_npc() )
          rats[i]->move_player( "west#" + ROOM + "c6" );
      }
    }
    return 1;
  }
  if( str && sscanf( str, "%s on rathole", item ) != 1 ) {
    notify_fail( "You cannot do that here.\n" );
    return 0;
  }
  if( !( it = present( item, this_player() ) ) ) {
    printf( "You don't have the " + item + ".\n" );
    return 1;
  }
  printf( "You can't use the " + it->short() + " on the rathole.\n" );
  say( this_player()->query_name()
    + " tries in vain to use the " + it->short() + " on the rathole.\n" );
  return 1;
}
