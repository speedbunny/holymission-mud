#include "/players/sargon/define.h"
inherit "/obj/std_shadow";

int attacks;
object room;

varargs int start_shadow( object ob, int time, object here, int att ) {
    attacks = att;
    room = here;
    return ::start_shadow( ob, time, "berzerk_shad", 0 );
}

void end_shadow( object ob ) {
    write( "You feel calmer.\n" );
    ::end_shadow( ob );
}

status do_berzerk() {
    int i;

    if( environment( this_player() ) != room ) {
	end_shadow( this_object() );
    }
    i = attacks;
    while( i ) {
	this_player() -> attack();
	i--;
    }
    return( 1 );
}

int berzerk_shad() {
    return ( 1 );
}

void stop_berzerk() {
    end_shadow( this_object() );
    return;
}
