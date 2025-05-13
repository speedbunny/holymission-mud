/* 970915, Uglymouth: getting rid of  ONE_EXIT and MAKE_KEY macro's
 */
inherit "room/room";

void reset( int arg ) {
  object ob;

  if( !present( "iron key" ) ) {
    ob = clone_object( "/obj/thing" );
    ob->set_name( "iron key" );
    ob->set_alias( "key" );
    ob->set_alt_name( "dungeondoor" );
    ob->set_short( "An iron key" );
    ob->set_long( "An iron key to unlock the cellars.\n" );
    ob->set_value( 10 );
    move_object( ob, this_object() );
  }
  if( !present( "mirror" ) ) {
    ob = clone_object( "/players/padrone/maze/magic_mirror" );
    ob->setup( "players/kelly/rooms/castle/tower21bureau",
      "players/padrone/maze/maze11", "north" );
  }
  ::reset( arg );
  if( arg ) return;
  set_light( 0 );
  short_desc = " In a bureau";
  long_desc = "You are in a bureau of the castle.\n";
  dest_dir = ({
    "players/kelly/rooms/castle/tower21", "west",
  });
}
