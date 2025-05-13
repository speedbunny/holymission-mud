#include "bard.h"
#define IRRESISTABLE_COST 50
#define IRRESISTABLE_LEVEL 22

int main( string str ) {
    object target, dancer;
    int time;

    CHK_LVL( IRRESISTABLE_LEVEL );
    CHK_SP( IRRESISTABLE_COST );
    if( !str && !this_player()->query_attack() ) {
	write( "Cast Irresistable Dance at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( !str ) 
	target = this_player()->query_attack();
    else 
	target = present( str, environment( this_player() ) );
    if( !target || !living( target ) ) {
	write( "Cast Irresistable Dance at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( target == this_player() ) {
	write( "You cannot cast Irresistable Dance at yourself!\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( target->irresistable_shad() ) {
	printf( "%s is already dancing.\n", target->query_name() );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - IRRESISTABLE_COST );
    time = this_player()->query_chr() * 3;
    printf( "You finish your irresistable dance tune.\n\
You direct the magical energies at %s.\n", target->query_name() );
    say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
      " performance.\n" + target->query_name() + " starts to dance uncontrollably!\n", target );
    tell_object( target, this_player()->query_name() + " finishes " + this_player()->query_possessive() +
      " performance.\nYou cannot fight the urge to dance any longer!\n" );
    if( target->query_chr() > this_player()->query_chr() * 2 ) {
	printf( "%s isn't charmed!\n", target->query_name() );
	tell_object( target, "You are not effected by the stupid bard!\n" );
	return ( 1 );
    }
    if( target->query_immortal() ) {
	write( "Ya right...\n" );
	return ( 1 );
    }
    dancer = clone_object( "/players/turbo/guild/obj/irresistable_shad" );
    dancer->start_shadow( target, time );
    return ( 1 );
}
