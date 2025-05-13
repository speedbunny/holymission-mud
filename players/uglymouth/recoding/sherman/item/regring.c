inherit "obj/armour"; 

status busy_regenerating;

void reset( int arg ) {
  ::reset(arg);
  if( arg ) return;
  set_name( "gold ring" );
  set_alias( "ring" );
  set_alias( "ring of regeneration" ); 
  set_short( "A gold ring with magic runes" );
  set_long( "It seems to be an interesting ring with lots of runes graved "
    + "into its otherwise smooth gold surface.\n" );
  set_type( "ring" );
  set_ac( 0 );
  set_value( 10000 );
  set_weight( 3 );
  busy_regenerating = 0;
  enable_commands();
}

void init() {
  ::init();
  add_action( "do_twist", "twist" );
}

int do_twist( string str ) {
  if( !id( str ) ) return 0;
  busy_regenerating = !busy_regenerating;
  if( busy_regenerating ) set_heart_beat( 1 );
  else set_heart_beat( 0 );
  printf( "You twist the gold ring. Its runes flare for a moment.\n");
  return 1;
}

int wear( string str ) {
  if !random( 4 )
    printf( "You feel a sudden urge to twist the ring.\n" );
  return ::wear( str );
}

int remove(str) {
  busy_regenerating = 0;
  set_heart_beat( 0 );
  return ::remove( str );
}

void heart_beat() {
  environment()->heal_self( 1 );
}

int drop( int silently ) {
  busy_regenerating = 0;
  set_heart_beat( 0 );
  return ::drop( silently );
}
