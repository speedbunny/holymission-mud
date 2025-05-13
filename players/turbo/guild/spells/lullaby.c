#include "bard.h"
#define LULLABY_COST 50
#define LULLABY_LEVEL 10

int main( string str ) {
    object target;

    if( !str && !this_player()->query_attack() ) {
	write( "Cast Lullaby at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    CHK_SP( LULLABY_COST );
    CHK_LVL( LULLABY_LEVEL );
    if( !str ) 
	target = this_player()->query_attack();
    else 
	target = present( str, environment( this_player() ) );
    if( !target || !living( target ) ) {
	write( "Cast Lullaby at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( target == this_player() ) {
	write( "You do not want to fall asleep!\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - LULLABY_COST );
    write( "You complete your performance, slowing the tempo down to a gentle lullaby.\n" );
    say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
      " performance softly.\n", target );
    tell_object( target, this_player()->query_name() + " finishes " +
      this_player()->query_possessive() + " performance softly.\nYou feel sleepy...\n" );
    if( target->query_chr() > this_player()->query_chr() * 3 ) {
	printf( "%s isn't effected!\n", target->query_name() );
	tell_object( target, "You are not fooled by the stupid bard!\n" );
	return ( 1 );
    }
    target->hold( this_player(), ( this_player()->query_chr() / 2 ) + ( random( 
	  this_player()->query_chr() / 2 ) ) );
    return ( 1 );
}
