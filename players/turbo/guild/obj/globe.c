inherit "obj/thing";
string color;

int get() {
    write( "The globe dances away from your hands.\n" );
    return ( 0 );
}

string get_color() {
    switch( random( 10 ) ) {
    case 0:   return "A blue";    break;
    case 1:   return "A red";     break;
    case 2:   return "A yellow";  break;
    case 3:   return "An orange"; break;
    case 4:   return "A violet";  break;
    case 5:   return "A white";   break;
    case 6:   return "A pink";    break;
    case 7:   return "A green";   break;
    case 8:   return "An indigo"; break;
    case 9:   return "A purple";  break;
    default:  return "A mauve";   break;
    }
}

void reset( int arg ) {
    ::reset( arg );
    if( arg ) 
       return;
    set_light( 1 );
    color = get_color();
    set_name( "light" );
    set_short( color + " light" );
    set_long( "This is " + lower_case( color ) + " dancing light.  It flutters around.\n" );
    set_weight( 0 );
    set_value( 0 );
}

void set_time( int tim ) { call_out( "end_light", tim ); }

status end_light() {
    tell_room( environment(), lower_case( color ) + " light winks out.\n" );
    if( !set_light( 0 ) ) 
       tell_room( environment(), "The room darkens...\n" );
    destruct( this_object() );
    return ( 1 );
}
