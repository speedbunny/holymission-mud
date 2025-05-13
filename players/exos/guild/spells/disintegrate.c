#define DISINTEGRATE_COST 150
#define DISINTEGRATE_FAIL 110
#define DISINTEGRATE_FAIL_COST 75

int main( string str ) {
    object target;
    int damage, level;

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
    if( this_player()->query_spell_points() < DISINTEGRATE_COST ) {
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
	write( "Cast Disintegrate at whom?\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Do not hurt ourself! */
    if( target == this_player() ) {
	write( "You aren't suicidal.\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Do we successfully cast the spell? */
    if( this_player()->query_level() * 2 + this_player()->query_int() * 2 +
      this_player()->query_wis() + random( 40 ) < DISINTEGRATE_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - DISINTEGRATE_FAIL_COST );
	return ( 1 );
    }

    /* Rock and Roll Baby! */
    target->attacked_by( this_player() );
    level = ( this_player()->query_level() );
    damage = ( this_player()->query_int() + this_player()->query_wis() ) * 12;
    if( damage > 800 )
	damage = 800;
    printf( "You clench your fists tightly.  A black beam fires at %s.\n",
      target->query_name() );
    tell_object( target, this_player()->query_name() + " clenches " + 
      this_player()->query_possessive() + " fists.\nSuddenly a black beam of light shoots at you!\n" );
    say( this_player()->query_name() + " clenches " + this_player()->query_objective() +
      " fists.\nSuddenly a beam of black light shoots at " + target->query_name() + "!\n" );  

    /* Do we kill our target? */
    if( damage >= target->query_hp() ) {
	printf( "The beam begins to atomize %s!\n", target->query_name() );
	say( "The beam begins to atomize " + target->query_name() + "!\n", target );
	tell_object( target, "You feel your body begin to dissolve into nothingness!\n" );
    }

    /* Ok...time to hurt our target. */
    this_player()->add_xp( target->hit_player( damage, 7, ({ 11, 12 }) ) );

    /* Are we a wizard?  If so, keep our SP and tell us the damage. */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - DISINTEGRATE_COST );
    else
	printf( "WIZINFO:  Damage %d.\n", damage );

    /* Spell is done! */
    return ( 1 );
}
