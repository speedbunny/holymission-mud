#define HAND_COST 200
#define HAND_FAIL 130
#define HAND_FAIL_COST 100

int main( string str ) {
    object target, crusher;
    int level, time;

    /* Are we alive? */
    if( this_player()->query_ghost() ) {
	write( "That just is not possible...\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Are we in a no_fight zone? */
    if( environment( this_player() )->query_property( "no_fight" ) ) {
	write( "You are not allowed to cast this here!\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return( 1 );
    }

    /* Do we have the Spell Points to cast? */
    if( this_player()->query_spell_points() < HAND_COST ) {
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
	target = this_player()->query_attack();
    else
	target = present( str, environment( this_player() ) );
    if( !target || !living( target ) ) {
	write( "Cast Crushing Hand at whom?\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Is our target already effected? */
    if( target->crush_shad() ) {
	printf( "%s is already being crushed!\n", target->query_name() );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return( 1 );
    }

    /* Do not hurt ourself! */
    if( target == this_player() ) {
	write( "You aren't suicidal.\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }              

    /* Do we successfully cast the spell? */
    if( this_player()->query_level() * 2 + this_player()->query_int() * 2 +
      this_player()->query_wis() + random( 40 ) < HAND_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - HAND_FAIL_COST );
	return ( 1 );
    }

    /* Rock and Roll Baby! */
    target->attacked_by( this_player() );
    time = ( this_player()->query_level() / 2 );
    if( time > 15 )
	time = 15;
    printf( "You make a grabbing motion towards %s.  A translucent hand surrounds %s!\n", 
      target->query_name(), target->query_objective() );
    say( this_player()->query_name() + " makes a grabbing motion towards " + 
      target->query_name() + ".  A translucent hand surrounds " +
      target->query_objective() + "!\n", ({ target, this_player() }) );
    tell_object( target, this_player()->query_name() + " makes a grabbing motion at you!\n" );
    crusher = clone_object( "/players/exos/mage/shadows/crush_shad" );
    crusher->start_shadow( target, time );

    /* Are we a wizard?  If so, keep our SP and tell us the duration. */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - HAND_COST );
    else
	printf( "WIZINFO:  Time %d.\n", time );

    /* Spell is done! */
    return ( 1 );
} 
