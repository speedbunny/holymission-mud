#include "bard.h"
#define MOONBEAM_COST 250
#define MOONBEAM_LEVEL 29

int main( string str ) {
    object *all;
    int i, j;

    CHK_SP( MOONBEAM_COST );
    CHK_LVL( MOONBEAM_LEVEL );
    CHK_ATT();
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - MOONBEAM_COST );
    write( "You finish your performance, causing a moonbeam to engulf the room.\n" );
    say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
      " performance.\nSuddenly, the room is engulfed in a warm beam of moonlight!\n" );
    all = all_inventory( environment( this_player() ) );
    j = sizeof( all );
    if( j > 20 ) 
	j = 20;
    while( i < j ) {
	if( living( all[i] ) ) {
	    if( !all[i]->query_npc() ) {
		if( !this_player()->query_immortal() ) 
		    all[i]->heal_self( 25 + random( 25 ) );
	    }
	    else 
		this_player()->add_exp( all[i]->hit_player( 100 ) );
	}
	i++;
    }
    return ( 1 );
}
