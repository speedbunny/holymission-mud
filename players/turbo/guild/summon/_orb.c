#include "bard.h"

int hurl_orb( string str, int lvl, int sp, string color, int dam ) {
    object target;
    string name;
    int real_dam;

    CHK_LVL( lvl );
    CHK_SP( sp );
    if( !str && !this_player()->query_attack() ) {
	write( "Summon an Orb at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( !str ) 
	target = this_player()->query_attack();
    else 
	target = present( str, environment( this_player() ) );
    if( !target || !living( target ) ) {
	write( "Summon an Orb at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
	  " performance.\n" );
	return ( 1 );
    }
    if( target == this_player() ) {
	write( "You think this may be very stupid and PAINFUL.\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
	  " performance.\n" );
	return ( 1 );
    }
    target->attacked_by( this_player() );
    name = target->query_name();
    printf( "Your performance creates %s orb, which flies off at %s.\n", color, name );
    say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
      " performance.\nSuddenly " + color + " orb appears and flies towards " + name + "!\n", target );
    tell_object( target, this_player()->query_name() + " finishes " + this_player()->query_possessive() +
      " performance.\nSuddenly " + color + " orb appears and flies right at you!\n" );
    /*
	if( !target->query_npc() )
	    dam = dam / 2;
    */
    /* Fighter parries type 7, but not 5. */
    real_dam = target->hit_player( dam, 5 );
    this_player()->add_xp( dam );
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - sp );
    else
	printf( "WIZINFO:  Damage: %d  Cost: %d  Actual: %d.\n", dam, sp, real_dam );
    return ( 1 );
}

