inherit "/obj/thing";

mapping wiz_info;

void reset( int arg ) {
  if( arg ) return;
  set_name( "archer" );
  set_short( "An Archer" );
  set_long( "An Archer.\n" );
}

void init() {
  ::init();
/*
  if( !this_player()->query_archwiz() ) destruct( this_object() );
*/
  add_action( "cmd_archer", "archer" );
}

int get() { return 1; }

int cmd_archer( string str ) {
  string *wizzes;
  int wizlvl, i, so;

  sscanf( str, "%d", wizlvl );
  restore_object( "/secure/WIZSAVE" );
  wizzes = m_indices( wiz_info );
  for( i=0, so=sizeof( wizzes ); i<so; i++ ) {
    if( wiz_info[ wizzes[i] ][0] == wizlvl )
      write( wizzes[i] + ".\n" );
  }
  return 1;
}
