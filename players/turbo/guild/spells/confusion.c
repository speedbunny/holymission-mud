#include "bard.h"
#define CONFUSION_COST 60
#define CONFUSION_LEVEL 15

int main( string str ) {
    object target, confuser;
    int time;

    if( !str && !this_player()->query_attack() ) {
	write( "Cast Confusion at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
	  " performance.\n" );
	return ( 1 );
    }
    CHK_SP( CONFUSION_COST );
    CHK_LVL( CONFUSION_LEVEL );
    if( !str ) 
	target = this_player()->query_attack();
    else 
	target = present( str, environment( this_player() ) );
    if( !target || !living( target ) ) {
	write( "Cast Confusion at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( target == this_player() ) {
	write( "You do not want to confuse yourself!\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
	  " performance.\n" );
	return ( 1 );
    }
    if( target->confusion_shad() ) {
	printf( "%s is already confused.\n", target->query_name() );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
	  " performance.\n" );
	return ( 1 );
    }
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - CONFUSION_LEVEL );
    time = this_player()->query_chr() * 3;
    write( "You finish your performance with chaotic chords.\n" );
    say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
      " performance with a series of totally chaotic chords.\n", target );
    tell_object( target, this_player()->query_name() + " finishes " + this_player()->query_possessive() +
      " performance with a series of strangely alluring notes...\n" );
    if( target->query_chr() > this_player()->query_chr() * 2 ) {
	printf( "%s isn't confused!\n", target->query_name() );
	tell_object( target, "You are not fooled by the stupid bard!\n" );
	return ( 1 );
    }
    if( target->query_immortal() ) {
	write( "Ya right...\n" );
	return ( 1 );
    }
    confuser = clone_object( "/players/turbo/guild/obj/confusion_shad" );
    confuser->start_shadow( target, time );
    return ( 1 );
}
