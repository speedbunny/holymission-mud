#define MISSILE_COST 20
#define MISSILE_FAIL 15
#define MISSILE_FAIL_COST 10

int main( string str ) {
    object target;
    int damage, i, level;

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
    if( this_player()->query_spell_points() < MISSILE_COST ) {
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
	write( "Cast Magic Missile at whom?\n" );
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
      this_player()->query_wis() + random( 40 ) < MISSILE_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - MISSILE_FAIL_COST );
	return ( 1 );
    }

    /* Rock and Roll Baby! */
    target->attacked_by( this_player() );
    level = ( this_player()->query_level() + 1 ) / 2;
    if( level > 10 )
	level = 10;
    damage = 0;
    for( i = 0; i < level; i++ ) 
	damage += random( 20 ) + 6;
    printf( "You raise your hand and point at %s, as %d bolts of energy shoot out at %s!\n", 
      target->query_name(), level, target->query_objective() );
    tell_object( target, this_player()->query_name() + " raises " +
      this_player()->query_possessive() + " hand, and points at YOU!!\n"+
      "Suddenly several bolts of energy shoot out at you!\n" );
    say( this_player()->query_name() + " raises " + this_player()->query_possessive() +
      " hand, and points at " + target->query_name() + ", suddenly several bolts of energy " +
      "shoot out at " + target->query_objective() + "!\n", ({ this_player(), target }) );

    /* Is our target protected by a shield spell? */
    if( target->shielded() ) {
	printf( "But the bolts pass through %s harmlessly!\n", target->query_objective() );
	say( "But the bolts pass through " + target->query_objective() + " harmlessly!\n",
	  ({ this_player(), target }) );
	tell_object( target, "The bolts pass through you harmlessly!\n" );
	target->attack_object( this_player() );
	damage = 0;
    }

    /* Do we kill our target? */
    if( damage >= target->query_hp() ) {
	printf( "Your missiles totally annihilate %s!\n", target->query_name() );
	say( target->query_name() + " reels from the force of the missiles and collapses!\n", target );
	tell_object( target, " The missiles blast you back into oblivion!\n" );
    }

    /* Ok...time to hurt our target. */
    this_player()->add_xp( target->hit_player( damage, 7, ({ 5, 12 }) ) );

    /* Are we a wizard?  If so, keep our SP and tell us the damage. */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - MISSILE_COST );
    else
	printf( "WIZINFO:  Damage %d.\n", damage );

    /* Spell is done! */
    return ( 1 );
}
