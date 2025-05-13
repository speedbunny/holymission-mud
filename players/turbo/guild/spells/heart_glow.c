#include "bard.h"
#define HEART_COST 60
#define HEART_LEVEL 7

int main( string str ) {
    object target;
    int health;

    CHK_LVL( HEART_LEVEL );
    CHK_SP( HEART_COST );
    if( !str ) 
	target = this_player();
    else
	target = present( str, environment( this_player() ) );
    if( !target || !living( target ) ) {
	write( "Cast Heart Glow at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    printf( "You finish your performance with a slow, romantic movement.\n" );
    say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
      " performance, with a slow, romantic movement.\n" );
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - HEART_COST );
    health = target->query_max_hp() / 10;
    if( health + target->query_hp() > target->query_max_hp() )
	health = target->query_max_hp() - target->query_hp();
    target->reduce_hit_point( - health );
    tell_object( target, "You feel your heart glow!\n" );
    return ( 1 );
}
