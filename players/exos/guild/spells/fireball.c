#define FIREBALL_COST 80
#define FIREBALL_FAIL 45
#define FIREBALL_FAIL_COST 40

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
    if( this_player()->query_spell_points() < FIREBALL_COST ) {
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

    /* Remember fireball is not targetted. */
    if( str ) 
	write( "You can't target a fireball!  It works on its own!\n" );

    /* Do we successfully cast the spell? */
    if( this_player()->query_level() * 2 + this_player()->query_int() * 2 +
      this_player()->query_wis() + random( 40 ) < FIREBALL_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - FIREBALL_FAIL_COST );
	return ( 1 );
    }

    /* Rock and Roll Baby! */
    target = all_inventory( environment( this_player() ) );
    level = this_player()->query_level();
    if( level > 20 )
	level = 20;
    damage = 0;
    for( i = 0; i < level; i++ ) 
	damage += random( 20 ) + 1;
    printf( "You make a throwing motion, throwing a ball of fire into the room!\n" );
    say( this_player()->query_name() + " throws a ball of fire into the room!\n" );
    for ( i = j = 0; i < sizeof( target ) && j < ( level / 2 ); i++ ) {
	if( living( target[i] ) && target[i]->query_npc() ) {
	    tell_object( target[i], "You are burned by the explosion!\n");
	    this_player()->add_xp( target[i]->hit_player( damage, 5, ({ 5, 12 }) ) ); 
	    j++;
	}
    }

    /* Are we a wizard?  If so, keep our SP and tell us the damage. */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - FIREBALL_COST );
    else
	printf( "WIZINFO:  Damage %d.\n", damage );

    /* Spell is done! */
    return ( 1 );
}
