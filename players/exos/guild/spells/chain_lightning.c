#define CHAIN_COST 150
#define CHAIN_FAIL 75
#define CHAIN_FAIL_COST 75

int main( string str ) {
    object *target;
    int damage, level, i, j;

    /* Are we alive? */
    if( this_player()->query_ghost() ) {
	write( "That just is not possible...\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Do we have the Spell Points to cast? */
    if( this_player()->query_spell_points() < CHAIN_COST ) {
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

    /* Remember chain lightning is not targetted. */
    if( str ) 
	write( "You can't target chain lightning!  It'll hit everything on its own!\n" );

    /* Do we successfully cast the spell? */
    if( this_player()->query_level() * 2 + this_player()->query_int() * 2 +
      this_player()->query_wis() + random( 40 ) < CHAIN_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - CHAIN_FAIL_COST );
	return ( 1 );
    }

    /* Rock and Roll Baby! */
    target = all_inventory( environment( this_player() ) );
    level = this_player()->query_level();
    damage = 0;
    for( i = 0; i < level; i++ ) 
	damage += random( 30 ) + 1;
    if( damage > 400 )
	damage = 400;
    printf( "You clench both fists and spread out your arms, sending lightning out in all directions!\n" );
    say( this_player()->query_name() + " clenches " + this_player()->query_possessive() +
      " fists and spreads out " + this_player()->query_possessive() + 
      " arms.  Suddenly lightning spreads out in all directions from " + 
      this_player()->query_objective() + " !\n" );
    for ( i = j = 0; i < sizeof( target ) && j < ( level / 2 ); i++ ) {
	if ( living( target[i] ) && target[i]->query_npc() ) {
	    tell_object( target[i], "You are zapped by the lightning!\n");
	    this_player()->add_xp( target[i]->hit_player( damage, 7, ({ 2, 12 }) ) ); 
	    j++;
	}
    }

    /* Are we a wizard?  If so, keep our SP and tell us the damage. */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - CHAIN_COST );
    else
	printf( "WIZINFO:  Damage %d.\n", damage );

    /* Spell is done! */
    return ( 1 );
}
