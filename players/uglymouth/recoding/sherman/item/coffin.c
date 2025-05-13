#include "../defs.h"

inherit "obj/container";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;

  set_name( "coffin" );
  set_short( "A black coffin" );
  set_long( "This is a simple black coffin, made of oak. You notice a bit "
    + "of sand between its silk linings and the wood.\n" );
  set_can_get( 0 );
  can_put_and_get( 0 );
  set_only_for( "vampire" );
  set_can_close( 1 );
  set_closed();
  set_lid_name( "lid" );
}

void init() {
  ::init();
  if( previous_object()->id( "vampire" ) )
    call_out( "revive_vampire", 900 );
  add_action( "do_destroy_coffin", "burn" );
  add_action( "do_destroy_coffin", "destroy" );
  add_action( "go_get", "get" );
  add_action( "go_get", "take" );
}

int do_destroy_coffin( string str ) {
  string verb;
  object owner;

  verb = query_verb();
  if( !id( str ) ) {
    notify_fail( capitalize( verb ) + " what?\n" );
    return 0;
  }
  printf( "You %s the coffin.\n", verb );
  say( sprintf( "%s %ss the coffin.\n", this_player()->query_name(), verb ),
    this_player() );
  if( owner = present( "vampire", this_object() ) ) {
    tell_room( environment(), sprintf( "%s screams in terror as %s is "
      + "being %s while laying paralyzed in %s coffin.\n",
      owner->query_name(), owner->query_pronoun(),
      verb == "burn" ? "burnt" : "destroyed", owner->query_possessive() );
    destruct( owner );
  }
  environment()->set_coffin_destroyed();
  if( find_call_out( "revive_vampire" ) != -1 )
    remove_call_out( "revive_vampire" );
  destruct( this_object() );
  return 1;
}

int do_get( string str ) {
  if( !str ) return 0;
  if( sscanf( str, "%s from %s", what, where ) != 2 ) return 0;
  if( !id( where ) ) return 0;
  printf( "You cannot take that out of the coffin.\n" );
  return 1;
}

void revive_vampire() {
  object owner, target;

  owner = present( "vampire", this_object() );
  if( !owner ) return;
  owner->heal_self( 10000 );
  if( target = find_player( owner->query_killer() ) &&
      strstr( file_name( environment( target ) ), PATH ) != -1 )
    owner->move_player( "X#" + file_name( environment( target ) ) );
  }
  else owner->move_player( "X#" + owner->query_create_room() );
  tell_room( environment(), "Suddenly the lid of the coffin flies "
    + "wide open and from it dark interior a bat flies away swiftly "
    + "into the dusky sky.\n" );
}

