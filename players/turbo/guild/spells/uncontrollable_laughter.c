#include "bard.h"
#define UNCONTROLLABLE_COST 75
#define UNCONTROLLABLE_LEVEL 25

int main( string str ) {
    object target, laugher;
    int time;

    CHK_LVL( UNCONTROLLABLE_LEVEL );
    CHK_SP( UNCONTROLLABLE_COST );
    if( !str && !this_player()->query_attack() ) {
	write( "Cast Uncontrollable Laughter at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
	  " performance.\n" );
	return ( 1 );
    }
    if( !str ) 
	target = this_player()->query_attack();
    else 
	target = present( str, environment( this_player() ) );
    if( !target || !living( target ) ) {
	write( "Cast Uncontrollable Laughter at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( target == this_player() ) {
	write( "You do not want to do this!\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( target->uncontrollable_shad() ) {
	printf( "%s is already laughing.\n", target->query_name() );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - UNCONTROLLABLE_COST );
    time = this_player()->query_chr() * 3;
    write( "You complete your stand-up comedy.\n" );
    say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
      " stand-up comedy performance.\n" );
    tell_object( target, "You feel ready to burst in laughter!\n" );
    if( target->query_chr() > this_player()->query_chr() * 2 ) {
	printf( "%s isn't amused!\n", target->query_name() );
	tell_object( target, "You are not amused by the stupid bard!\n" );
	return ( 1 );
    }
    if( target->query_immortal() ) {
	write( "Ya right...\n" );
	return ( 1 );
    }
    laugher = clone_object( "/players/turbo/guild/obj/uncontrollable_shad" );
    laugher->start_shadow( target, time );
    return ( 1 );
}
