#include "bard.h"
#define CREAM_COST 20
#define CREAM_LEVEL 3
#define CREAM_DAMAGE ( random( this_player()->query_chr() ) + 1 )

int main( string str ) {
    object target;
    int dam;

    CHK_LVL( CREAM_LEVEL );
    CHK_SP( CREAM_COST );
    if( !str && !this_player()->query_attack() ) {
	write( "Cast Cream Pie at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( !str ) 
	target = this_player()->query_attack();
    else
	target = present( str, environment( this_player() ) );
    if( !target || !living( target ) ) {
	write( "Cast Cream Pie at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
	  " performance.\n" );
	return ( 1 );
    }
    if( target == this_player() ) {
	write( "You slow your performance and pull a pie out of thin air, then \
slam it into your own face to the cheers of the crowd!\n" );
	say( this_player()->query_name() + " slows " + this_player()->query_possessive() +
	  " performance, as " + this_player()->query_pronoun() + " slams a cream " +
	  "pie into " + this_player()->query_possessive() + " face!\n" );
	return ( 1 );
    }
    printf( "You slow your performance and pull a pie out of thin air, then \
slam it into %s's face!\n", target->query_name() );
    say( this_player()->query_name() + " slows " + this_player()->query_possessive() +
      " performance, as " + this_player()->query_pronoun() + " slams a cream " +
      "pie into " + target->query_name() + "'s face!\n", target );
    tell_object( target, this_player()->query_name() + " slows " +
      this_player()->query_possessive() + " performance, and suddenly slams " +
      "a cream pie into your face, temporarily blinding you!\n" );
    target->hold( this_player(), 1 + random( 3 ) );
    this_player()->add_xp( target->hit_player( CREAM_DAMAGE ) );
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - CREAM_COST );
    else
	printf( "WIZINFO:  Damage %d.\n", CREAM_DAMAGE );
    return ( 1 );
}
