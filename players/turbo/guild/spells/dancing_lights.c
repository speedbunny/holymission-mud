#include "bard.h"
#define DANCING_COST 5
#define DANCING_LEVEL 1

int main( string str ) {
    object globe;
    int i, count;

    CHK_ATT();
    CHK_LVL( DANCING_LEVEL );
    CHK_SP( DANCING_COST );
    if( !this_player()->query_immortal() ) 
       this_player()->restore_spell_points( - DANCING_COST );
    count = ( this_player()->query_level() / 6 ) + 1;
    if (count > 7 ) count = 7;
    if (count == 1 ) {
	printf( "As you conclude your performance, a colored light appears \
and dances around.\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
            " performance.\nSuddenly, a colored light appears and dances around!\n" );
    }
    else {
	printf( "As you conclude your performance, %d \
colored lights appear and dance around.\n", count );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
           " performance.\nSuddenly, " + count + " colored lights appear and dance around!\n");
    }
    i = 0;
    while( i < count ) {
	globe = clone_object( "/players/turbo/guild/obj/globe" );
	globe->set_time( ( this_player()->query_wis() * 5 ) + ( this_player()->query_level() * 2 ) );
	move_object( globe, environment( this_player() ) );
        i++;
    }
    return ( 1 );
}
