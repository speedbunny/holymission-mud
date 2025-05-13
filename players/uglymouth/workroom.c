inherit "room/room";
 
void reset( int arg )  {
  string msg;

  ::reset( arg );
  if( !present( "model" ) )
    call_other( "/players/uglymouth/castle", "reset" );
  if( arg ) return;

  set_light( 1 );
  short_desc = "Uglymouth's workroom";
  long_desc = "Uglymouth's workroom is not very spacious.\n"
    + "All over the place linger papers.\n"
    + "You have to make your own way through them.\n";
  dest_dir=({
    "room/church","church",
    "room/wiz/general","inner",
    "/players/uglymouth/testchar/testlab","lab",
    "/players/uglymouth/appr/appr1", "west",
  });
  msg = "They are all yellowed parchments, full with undecipherable runes on them";
  items = ({
    "papers", msg,
    "paper",msg,
    "parchment",msg,
    "parchments",msg,
  });
  smell = "The smell of dried out, old yellow parchments fill every corner.\n";
}

void init() {
  ::init();
  if( this_player() )
  say( sprintf( "%s makes %s way through the papers.\n",
    this_player()->query_short_name(),
    this_player()->query_possessive() ), this_player() );
  if( (string)this_player()->query_real_name() == "debbie" )
    add_action( "do_boots", "boots" );
}

void exit() {
  if( this_player() )
  say( sprintf( "%s walks away through the papers.\n",
    this_player()->query_short_name() ), this_player() );
}

int do_boots() {
  transfer( clone_object( "/tools/bboots" ), this_player() );
  write( "You wear your new pair of bboots.\n" );
  return 1;
}
