inherit "obj/armour";

void reset( int arg ) {
    ::reset( arg );
    if ( arg ) 
       return;
    set_name( "armour_of_ithan" );
    set_size( "any" );
    set_short( "Armour of Ithan" );
    set_long( "This is a glowing aura that gives you awesome protection\n" );
    set_type( "guild" );
    set_ac( 0 );
    set_weight( 0 );
    set_value( 0 );
}

int drop( string str ) { return ( 1 ); }
int query_weight() { return ( 0 ); }

int set_timer( int time ) {
    call_out( "dest_me", time + random( 100 ) );
    return ( 1 );
}

dest_me() {
    write( "Your armour of Ithan fades away\n" );
    say( this_player()->query_name() + "'s glowing aura fades away.\n" );
    this_player()->command( "remove armour_of_ithan" );
    destruct( this_object() );
    return ( 1 );
}
