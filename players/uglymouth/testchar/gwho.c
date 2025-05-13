inherit "/obj/thing";

void reset( int arg ) {
  ::reset( arg );
  set_name( "gwho" );
  set_short( "A Ghwo" );
  set_long( "A Gwho is a small Nosibean artefact that is claimed to "
    + "have magical properties. What they are is unclear.\n" );
}

void init() {
  ::init();
  add_action( "do_gwho", "gwho" );
  add_action( "do_shad", "shad" );
}

int do_gwho() {
  object *u;

  u = users();
  printf( "%-=20s %-=20s\n",
    implode( map_array( u, "which_name", this_object() ), "\n" ),
    implode( map_array( u, "which_guild", this_object() ), "\n" ) );
  return 1;
}

string which_name( object user ) {
  return user->query_short_name();
}

string which_guild( object user ) {
  return call_other( "/guild/master", "query_name", user->query_guild() );
}

int do_shad( string who ) {
  object shadow_ob, player;

  if( !who ) player = this_player();
  else player = find_player( who );
  if( !player ) {
    notify_fail( "No such player around right now.\n" );
    return 0;
  }
  printf( "You have the following shadows:\n" );
  shadow_ob = shadow( player, 0 );
  while( shadow_ob ) {
  printf( "%O\n", shadow_ob );
    shadow_ob = shadow( shadow_ob, 0 );
  }
  printf( "Done.\n" );
  return 1;
}
