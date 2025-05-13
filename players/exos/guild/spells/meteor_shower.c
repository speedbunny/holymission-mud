#define SHOWER_COST 250
#define SHOWER_FAIL 150
#define SHOWER_FAIL_COST 125

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
    if( this_player()->query_spell_points() < SHOWER_COST ) {
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

    /* Remember meteor shower is not targetted. */
    if( str ) 
	write( "You can't target a meteor shower!  It'll hit everything on its own!\n" );

    /* Do we successfully cast the spell? */
    if( this_player()->query_level() * 2 + this_player()->query_int() * 2 +
      this_player()->query_wis() + random( 40 ) < SHOWER_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - SHOWER_FAIL_COST );
	return ( 1 );
    }

    /* Rock and Roll Baby! */
    target = all_inventory( environment( this_player() ) );
    level = this_player()->query_level();
    damage = 0;
    for( i = 0; i < level; i++ ) 
	damage += random( 50 ) + 1;
    if( damage > 600 )
	damage = 600;
    printf( "You spread out your arms, calling forth a shower of meteors!\n" );
    say( this_player()->query_name() + " spreads out " + this_player()->query_possessive() +
      " arms.  Suddenly large meteors begin to shower the room!\n" );
    for ( i = j = 0; i < sizeof( target ) && j < ( level / 2 ); i++ ) {
	if ( living( target[i] ) && target[i]->query_npc() ) {
	    tell_object( target[i], "You are pummeled by the meteors!\n");
	    this_player()->add_xp( target[i]->hit_player( damage, 7, ({ 15 }) ) ); 
	    j++;
	}
    }

    /* Are we a wizard?  If so, keep our SP and tell us the damage. */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - SHOWER_COST );
    else
	printf( "WIZINFO:  Damage %d.\n", damage );

    /* Spell is done! */
    return ( 1 );
}
