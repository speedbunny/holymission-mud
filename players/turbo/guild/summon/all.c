// this is going to cost all a bards SP,but will summon an orb capable of doing more damage
#include "bard.h"
#define LEVEL 29
#define COST 150
#define COLOR "a black"
#define DAMAGE 800

int main( string str ) {
    if( !this_player()->query_immortal() &&
      this_player()->query_legend_level() < 1 ) {
	return ( 0 );
    }
    return ( ORB->hurl_orb( str, LEVEL, COST, COLOR, DAMAGE ) );
}
