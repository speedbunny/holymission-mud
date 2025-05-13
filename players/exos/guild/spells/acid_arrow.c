#define ARROW_COST 50
#define ARROW_FAIL 30
#define ARROW_FAIL_COST 25

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
    if( this_player()->query_spell_points() < ARROW_COST ) {
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
	write( "Cast Acid Arrow at whom?\n" );
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
      this_player()->query_wis() + random( 40 ) < ARROW_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - ARROW_FAIL_COST );
	return ( 1 );
    }

    /* Rock and Roll Baby! */
    target->attacked_by( this_player() );
    damage = random( 40 ) + this_player()->query_level();
    printf( "You point both hands at %s.  A green bolt shoots out at %s.\n",
      target->query_name(), target->query_objective() );
    tell_object( target, this_player()->query_name() + " points " + 
      this_player()->query_possessive() + " hands at you.\n" +
      "Suddenly a green bolt shoots out at you!\n" );
    say( this_player()->query_name() + " points " + this_player()->query_objective() +
      " hands at " + target->query_name() + ".\nSuddenly a green bolt shoots out at " + 
      target->query_objective() + "!\n" );  

    /* Do we kill our target? */
    if( damage >= target->query_hp() ) {
	printf( "The green bolt burns clear through %s!\n", target->query_name() );
	say( "The green bolt burns clear through " + target->query_name() + "!\n", target );
	tell_object( target, "The green bolt burns deep into your body!\n" );
    }

    /* Let's do a little acid shadow damage. */
    else {
	level = ( this_player()->query_level() ) / 3;
	if( level > 10 )
	    level = 10;
    }

    /* Ok...time to hurt our target. */
    this_player()->add_xp( target->hit_player( damage, 7, ({ 4, 12 }) ) );

    /* Are we a wizard?  If so, keep our SP and tell us the damage. */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - ARROW_COST );
    else
	printf( "WIZINFO:  Damage %d.\n", damage );

    /* Spell is done! */
    return ( 1 );
}
