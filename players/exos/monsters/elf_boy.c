inherit "obj/monster";

void reset( int arg ) {
    ::reset( arg );
    set_name( "elfboy" );
    set_race( "elf" );
    set_alias( "boy", "elf" );
set_short( "A young elven boy" );
    set_level( 5 + random( 2 ) );
    set_al( 100 );
    set_gender( 1 );
}
