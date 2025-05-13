#include "mage.h"
#define POSE_COST 150
#define POSE_LEVEL 15

int main( string str ) {
    int lvl;

    if( !this_player()->query_immortal() )
	this_player()->restore_spell_points( - POSE_COST );
    lvl = this_player()->query_level();
    if( lvl < 25 ) {
	"sys/chatd"->do_chat( -1, sprintf( "%s sends a fireball into the sky.\n",
	    this_player()->query_name() ) );
	return( 1 );
    }
    if( lvl < 29 ) {
	if( str ) {
	    "sys/chatd"->do_chat( -1, sprintf( "%s summons a firework that writes: %s in the sky.\n",
		this_player()->query_name(), str ) );
	}
	else {
	    "sys/chatd"->do_chat( -1, sprintf( "%s summons a firework that explodes high in the sky.\n",
		this_player()->query_name() ) );
	}
	return( 1 );
    }
    if( str ) {
	"sys/chatd"->do_chat( -1, 
	  sprintf( "%s rises towards the sky, inside of a gigantic torrent of fire.\n\
%s burns the world with the words: %s\n", this_player()->query_name(), 
	    capitalize( this_player()->query_pronoun() ), str ) );
    }
    else {
	"sys/chatd"->do_chat( -1, 
	  sprintf( "%s rises towards the sky, inside of a gigantic torrent of fire.\n\
As %s points to heaven lightning springs out from %s hands.\n", this_player()->query_name(),
	    this_player()->query_pronoun(), this_player()->query_possessive() ) );
    }
    return( 1 );
}
