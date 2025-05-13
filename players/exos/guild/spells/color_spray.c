#define SPRAY_COST 20
#define SPRAY_FAIL 15
#define SPRAY_FAIL_COST 10

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
    if( this_player()->query_spell_points() < SPRAY_COST ) {
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
	write( "Cast Color Spray at whom?\n" );
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
      this_player()->query_wis() + random( 40 ) < SPRAY_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - SPRAY_FAIL_COST );
	return ( 1 );
    }

    /* Rock and Roll Baby! */
    target->attacked_by( this_player() );
    damage = ( this_player()->query_int() + this_player()->query_wis() );
    printf( "You move your hands in intricate patterns.  A rainbow of energy sprays at %s's eyes.\n",
      target->query_name() );
    tell_object( target, this_player()->query_name() + " moves " + 
      this_player()->query_possessive() + " hands in an intricate pattern.\n" +
      "Suddenly a rainbow splash of energy blinds you and burns at your eyes!\n" );
    say( this_player()->query_name() + " moves " + this_player()->query_objective() +
      " hands in an intricate pattern.\nSuddenly a rainbow splash of energy sprays at " + 
      target->query_name() + "'s eyes!\n" );  

    /* Do we kill our target? */
    if( damage >= target->query_hp() ) {
	printf( "The splash of energy bores through %s's eyes!\n", target->query_name() );
	say( "The energy splash burns into " + target->query_name() + "'s eyes!\n", target );
	tell_object( target, "Your eyes burn with intense heat and pain!\n" );
    }

    /* Let's confuse our target a little */
    else {
	level = ( this_player()->query_level() ) / 5;
	if( level > 4 )
	    level = 4;
	this_player()->attacked_by( target );
	target->hold( this_player(), level );
    }

    /* Ok...time to hurt our target. */
    this_player()->add_xp( target->hit_player( damage, 7, ({ 12 }) ) );

    /* Are we a wizard?  If so, keep our SP and tell us the damage. */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - SPRAY_COST );
    else
	printf( "WIZINFO:  Damage %d.\n", damage );

    /* Spell is done! */
    return ( 1 );
}
