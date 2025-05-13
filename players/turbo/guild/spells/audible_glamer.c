#include "bard.h"
#define AUDIBLE_COST 10
#define AUDIBLE_LEVEL 5

int main( string str ) {
    object att;

    att = this_player()->query_attack();
    if( !att ) {
	write( "You are not fighting anyone!\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
        " performance.\n" );
	return ( 1 );
    }
    CHK_SP( AUDIBLE_COST );
    CHK_LVL( AUDIBLE_LEVEL );
    if( !this_player()->query_immortal() ) 
       this_player()->restore_spell_points( - AUDIBLE_COST );
    printf( "The magic of your tune distracts %s.\n", att->query_name() );
    say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
        " performance.\nYou are startled by a sudden noise!\n", att );
    tell_object( att, this_player()->query_name() + " finishes " +
       this_player()->query_possessive() + " performance.\n" +
       "You jump at a sharp noise behind you!\n" );
    this_player()->attack();
    if( this_player()->query_level() > 20 && random( this_player()->query_dex() ) > 27 ) 
       this_player()->attack();
    return ( 1 );
}
