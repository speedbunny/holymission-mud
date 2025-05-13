#define INVISIBILITY_COST 50
#define INVISIBILITY_FAIL 30
#define INVISIBILITY_FAIL_COST 25

int main( string str ) {
    object target, inviser;
    int level, time;

    /* Are we alive? */
    if( this_player()->query_ghost() ) {
	write( "That just is not possible...\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Do we have the Spell Points to cast? */
    if( this_player()->query_spell_points() < INVISIBILITY_COST ) {
	write( "You are too tired...\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Can we see our target? */
    if( this_player()->test_dark() ) {
	write( "It is much too dark!\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return( 1 );
    }

    /* Who is our target? */
    if( !str ) 
	target = this_player();
    else
	target = present( str, environment( this_player() ) );
    if( !target || !living( target ) ) {
	write( "Cast Invisibility at whom?\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Is our target already effected? */
    if( target->invisibility_shad() ) {
	printf( "%s is already invisible!\n", target->query_name() );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return( 1 );
    }

    /* Do we successfully cast the spell? */
    if( this_player()->query_level() * 2 + this_player()->query_int() * 2 +
      this_player()->query_wis() + random( 40 ) < INVISIBILITY_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - INVISIBILITY_FAIL_COST );
	return ( 1 );
    }

    /* Rock and Roll Baby! */
    level = ( this_player()->query_level() );
    if( level > 30 )
	level = 30;
    time = 600;
    if( target == this_player() ) {
	write( "You perform delicate hand motions...\n" );
	say( this_player()->query_name() + " performs some delicate hand motions.\n" );
    }
    else {
	printf( "You perform delicate hand motions over %s.\n", target->query_name() );
	say( this_player()->query_name() + " performs some delicate hand motions over " +
	  target->query_name() + ".\n", target );
	tell_object( target, this_player()->query_name() +
	  " performs some delicate hand motions over your head.\n" );
    }
    inviser = clone_object( "/players/exos/mage/shadows/invisibility_shad" );
    inviser->start_shadow( target, time );

    /* Are we a wizard?  If so, keep our SP and tell us the duration. */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - INVISIBILITY_COST );
    else
	printf( "WIZINFO:  Time %d.\n", time );

    /* Spell is done! */
    return ( 1 );
}
