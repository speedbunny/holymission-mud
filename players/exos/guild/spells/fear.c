#define FEAR_COST 80
#define FEAR_FAIL 60
#define FEAR_FAIL_COST 40

int main( string str ) {
    object target;

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
    if( this_player()->query_spell_points() < FEAR_COST ) {
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
	write( "Cast Fear at whom?\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Do we successfully cast the spell? */
    if( this_player()->query_level() * 2 + this_player()->query_int() * 2 +
      this_player()->query_wis() + random( 40 ) < FEAR_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - FEAR_FAIL_COST );
	return ( 1 );
    }

    /* Rock and Roll Baby! */
    printf( "You make some magical gestures at %s.\n", target->query_name() );
    say( this_player()->query_name() + " makes some magical gestures at " +
      target->query_name() + ".\n", ({ this_player(), target }) );
    tell_object( target, this_player()->query_name() + 
      " makes some magical gestures at you!\n" );
    if( this_player()->query_level() < target->query_level() &&
      random( target->query_level() - this_player()->query_level() -
	this_player()->query_chr() ) ) {
	printf( "%s isn't scared!\n", target->query_name() );
	tell_object( target, this_player()->query_name() + " tried to scare you!\n" );
	if( target->query_npc() ) {
	    say( target->query_name() + " attacks " + this_player()->query_name() + "!\n",
	      ({ this_player(), target }) );
	    printf( "%s attacks you!\n", target->query_name() );
	    target->attack_object( this_player() );
	}
    }
    else {
	tell_object( target, "You feel a sudden fear overcome you!\n" );
	target->run_away();
	if( !present( target, environment( this_player() ) ) ) {
	    say( target->query_name() + " runs away in panic.\n" );
	    printf( "You scare %s away!\n", target->query_objective() );
	}
	else {
	    say( target->query_name() + " cowers in the corner.\n" );
	    tell_object( target, "You fail to run away and cower in the corner.\n" );
	    printf( "%s cowers in the corner.\n", target->query_name() );
	}

	/* Are we a wizard?  If so, keep our SP. */
	if( !this_player()->query_immortal() ) 
	    this_player()->restore_spell_points( - FEAR_COST );

	/* Spell is done! */
	return ( 1 );
    }
}
