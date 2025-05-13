#include "../defs.h"

inherit "room/room";

void bat_attack();

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;

  set_light( 1 );
  short_desc = "At the gate of a black tower.";
  long_desc = "You have arrived at the gate of the black tower. The tower "
    + "was once built for defense and looks like it can still be used for "
    + "that purpose. Around its spire hundreds of big black bats are flying "
    + "even in the dim light of day. A field of crackling, lightning filled "
    + "magic energy bars the gate, preventing you from entering the tower. "
    + "The road leads southwest from here.\n";
  dest_dir = ({
    ROOM_DIR + "darkld10", "southwest",
  });
  items=({
    "gate", "Where you would expect a portcullis, you see a magic field",
    "tower", "This must be the tower of the lord of this county. ",
    "spire", "Upon the battlements a steep spire has been placed",
    "bats", "A dark cloud of swirling bats obscures the sky",
    "field", "It's a deep black field filled with bolts of lightning",
    "road", "This last part of the road is made of brown bricks",
  });
}

void init() {
  ::init();
  bat_attack();
  add_action( "do_enter", "enter" );
}

int do_enter( string str ) {
  object key;

  if( str != "tower" ) {
    notify_fail( "Enter what?\n" );
    return 0;
  }
  if( !( key = present( "vampire_tower_field_negator", TP ) ) ||
      explode( file_name( key ), "#" )[0] != ITEM_DIR + "vampkey" ) {
    TP->reduce_hit_point( random( 15 ) + 10 );
    printf( "As you try to move through the magic energy field, you are "
      + "struck by several bolts of lightning and thrown back!\n" );
    say( sprintf( "As %s tries to move through the magic energy field "
      + "%s is struck by several bolts of lightning and thrown back upon "
      + "the road.\n", TPSHORTN, TPPRN ) );
    return 1;
  }
  TP->move_player( "into the tower#" + ROOM_DIR + "vtower2" );
  return 1;
}

void bat_attack() {
  int i;
  object ob;

  if( present( "vampire bat" ) ) return;
  if( random( 2 ) ) {
    tell_room( this_object(), "Several bats fly over low to examine what goes on down "
      + " below in there territory.\n" );
    return;
  }
  for( i = 0; i < random( 5 ) + 5; i++ )
    move_object( clone_object( MON_DIR + "vampbat" ), this_object() );
  tell_room( this_object(),
    sprintf( "From the sky %d bats swop down to attack!\n", i ) );
}

