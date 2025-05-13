#include "bard.h"
#define WEARINESS_COST 35
#define WEARINESS_LEVEL 7

int main( string str ) {
    object target;

    if( !str && !this_player()->query_attack() ) {
	write( "Cast Weariness at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
	  " performance.\n" );
	return ( 1 );
    }
    CHK_SP( WEARINESS_COST );
    CHK_LVL( WEARINESS_LEVEL );
    if( !str ) 
	target = this_player()->query_attack();
    else 
	target = present( str, environment( this_player() ) );
    if( !target || !living( target ) ) {
	write( "Cast Weariness at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( target == this_player() ) {
	write( "You do not want to tire yourself!\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
	  " performance.\n" );
	return ( 1 );
    }
    if( target->query_wimpy() < 1 ) {
	printf( "%s is already weary.\n", target->query_name() );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
	  " performance.\n" );
	return ( 1 );
    }
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - WEARINESS_LEVEL );
    write( "You finish your performance with lethargic chords.\n" );
    say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
      " performance with a series of totally lethargic chords.\n", target );
    tell_object( target, this_player()->query_name() + " finishes " + this_player()->query_possessive() +
      " performance with a series of strangely tiring chords...\n" );
    if( target->query_chr() > this_player()->query_chr() * 2 ) {
	printf( "%s isn't effected!\n", target->query_name() );
	tell_object( target, "You are not fooled by the stupid bard!\n" );
	return ( 1 );
    }
    target->set_wimpy( 0 );
    return ( 1 );
}
