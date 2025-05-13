#define RAY_COST 40
#define RAY_FAIL 30
#define RAY_FAIL_COST 20

int main( string str ) {
    object target, enfeebler;
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
    if( this_player()->query_spell_points() < RAY_COST ) {
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
	write( "Cast Ray of Enfeeblement at whom?\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Is our target already effected? */
    if( target->enfeeble_shad() ) {
	printf( "%s is already enfeebled!\n", target->query_name() );
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
      this_player()->query_wis() + random( 40 ) < RAY_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - RAY_FAIL_COST );
	return ( 1 );
    }

    /* Rock and Roll Baby! */
    target->attacked_by( this_player() );
    level = ( this_player()->query_level() );
    if( level > 30 )
	level = 30;
    time = level * 3;
    printf( "You aim your palm at %s.  A grey beam shoots at %s!\n", target->query_name(),
      target->query_objective() );
    say( this_player()->query_name() + " aims " + this_player()->query_possessive() + 
      " open palm at " + target->query_name() + ".  A grey beam shoots out at " +
      target->query_objective() + "!\n", target );
    tell_object( target, this_player()->query_name() + " points " +
      this_player()->query_possessive() + " open palm at you.  A grey beam shoots out " +
      " at you!.\n" );
    enfeebler = clone_object( "/players/exos/mage/shadows/enfeeble_shad" );
    enfeebler->start_shadow( target, time );

    /* Are we a wizard?  If so, keep our SP and tell us the duration. */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - RAY_COST );
    else
	printf( "WIZINFO:  Time %d.\n", time );

    /* Spell is done! */
    return ( 1 );
}
