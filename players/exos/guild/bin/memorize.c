#include "mage.h"
#define MEMORIZE_COST 100

int main( string str ) {
    object robe, here;

    if( str )
	return ( 0 );

    /* Do we have the spell points to memorize? */
    if( this_player()->query_sp() < MEMORIZE_COST ) {
	write( "You are too tired to concentrate that hard!\n" );
	return( 1 );
    }

    /* Can we see our surroundings? */
    if( this_player()->test_dark() ) {
	write( "It is too dark to familiarize yourself with this area!\n" );
	return( 1 );
    }
    here = environment( this_player() );

    /* Do we have an environment? */
    if( !here ) {
	write( "You do not seem to be ANYWHERE!\n" );
	return( 1 );
    }

    /* Is this a no_teleport zone? */
    if( here->query_property( "no_teleport" ) ) {
	write( "You sense a magic force at work, stopping you!\n" );
	return( 1 );
    }
    robe = present( "magesoul", this_player() );

    /* Make sure we have a magesoul */
    if( !robe ) {
	write( "You feel funny.  You should mail Exos.\n" );
	return( 1 );
    }
    robe->set_memorized( here );
    write( "You focus your mind and memorize your surroundings.\n" );
    say( sprintf( "%s looks deep in though.\n", this_player()->query_name() ), this_player() );

    /* Are we a wizard?  If so keep our SP */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - MEMORIZE_COST );
    return ( 1 );
}
