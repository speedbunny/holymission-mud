#include "../defs.h"

inherit "room/room";

status coffin_destroyed, empty_grave;
object coffin;

void reset( int arg ) {
  ::reset( arg );
  coffin_destroyed = 0;
  if( arg ) return;
  set_light( 1 );
}

void init() {
  ::init();
  add_action( "do_dig", "dig" );
}

int do_dig( string str ) {
  if( !str || ( str && member_array( str, ({ "grave", "ground", "soil",
      "clay", "dirt", "hole" }) ) == -1 ) ) {
    notify_fail( "Dig what?\n" );
    return 0;
  }
  if( empty_grave ) {
    printf( "You dig a grave. Maybe it will prove to have been a "
      + "useful exercise later...\n" );
    say( this_player()->query_name() + " digs a grave.\n", this_player() );
    return 1;
  }
  if( !coffin || !present( coffin, this_object() ) ) {
    if( !coffin ) coffin = clone_object( ITEM_DIR + "coffin" );
    coffin->set_read( "R.I.P. " + query_room( "property" ) + "\n" );
    move_object( coffin, this_object() );
    printf( "You dig up a coffin.\n" );
    say( TPSHORTN + " digs up a coffin.\n", TP );
    return 1;
  }
  this_player()->set_smell( sprintf( "%s smells like a zombie that's taken "
    + "a bath in a swamp.\n", capitalize( TPPRN ) ) );
  printf( "You dig into the dirt until you are covered in mud and smell "
    + "like a zombie.\n" );
  say( sprintf( "%s digs into the dirty clay. After a while %s looks and "
    + "smells like your worst zombie!\n", TPSHORTN, TPPRN ), TP );
  return 1;
}

void set_empty_grave( status i ) {
  empty_grave = i;
}

status query_empty_grave() {
  return empty_grave;
}

void set_coffin( object ob ) {
  coffin = ob;
}

object query_coffin() {
  return coffin;
}

void set_coffin_destroyed( status i ) {
  coffin_destroyed = i;
}

status query_coffin_destroyed() {
  return coffin_destroyed;
}

