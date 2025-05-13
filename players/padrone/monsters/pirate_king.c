/* Uglymouth, 970821: typedef'd; fixed bag to reappear each reset; 
 *   removed door/key macro.
 */
inherit "obj/monster";

void reset( int flag ) {
    object ob;

    ::reset( flag );
    if( !present( "bag", this_object() ) ) {
	transfer( clone_object( "obj/bag" ), this_object() );
	transfer( ob = clone_object( "obj/money" ), 
	  present( "bag", this_object() ) );
	ob->set_money( 100 + random( 300 ) );
	transfer( ob = clone_object( "obj/thing" ), 
	  present( "bag", this_object() ) );
	ob->set_name( "bullet-proof key" );
	ob->set_alias( "key" );
	ob -> set_alt_name( "walkervault" );
	ob->set_short( "A bullet-proof key" );
	ob->set_long( "This is a bullet-proof key. "
	  + "You wonder where it fits.\n" );
	ob->set_value( 10 );
    }
    if( flag ) return;
    set_name( "pirate king" );
    set_alias( "king" );
    set_short( "The pirate king" );
    set_long( "This is the pirate king. He is big and very very ugly.\n" );
    set_level( 12 );
    set_gender( 1 );
    set_hp( 200 );
    set_al( -200 );
    set_aggressive( 1 );
}
