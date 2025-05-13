#include "bard.h"
#define NIGHTMARE_COST 65
#define NIGHTMARE_LEVEL 17

int main( string str ) {
    object target, dreamer;
    int time;

    if( !str && !this_player()->query_attack() ) {
	write( "Cast Nightmare at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
	  " performance.\n" );
	return ( 1 );
    }
    CHK_SP( NIGHTMARE_COST );
    CHK_LVL( NIGHTMARE_LEVEL );
    if( !str ) 
	target = this_player()->query_attack();
    else 
	target = present( str, environment( this_player() ) );
    if( !target || !living( target ) ) {
	write( "Cast Nightmare at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( target == this_player() ) {
	write( "You do not want to scare yourself!\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
	  " performance.\n" );
	return ( 1 );
    }
    if( target->confusion_shad() ) {
	printf( "%s is already scared.\n", target->query_name() );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
	  " performance.\n" );
	return ( 1 );
    }
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - NIGHTMARE_LEVEL );
    time = this_player()->query_chr() * 3 / 2;
    write( "You finish your performance with spooky chords.\n" );
    say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
      " performance with a series of very spooky chords.\n", target );
    tell_object( target, this_player()->query_name() + " finishes " + this_player()->query_possessive() +
      " performance with a series of extremely frightening notes...\n" );
    if( target->query_chr() > this_player()->query_chr() * 2 ) {
	printf( "%s isn't scared!\n", target->query_name() );
	tell_object( target, "You are not fooled by the stupid bard!\n" );
	return ( 1 );
    }
    if( target->query_immortal() ) {
	write( "Ya right...\n" );
	return ( 1 );
    }
    dreamer = clone_object( "/players/turbo/guild/obj/nightmare_shad" );
    dreamer->start_shadow( target, time );
    return ( 1 );
}
