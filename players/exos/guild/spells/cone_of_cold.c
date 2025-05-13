#define CONE_COST 100
#define CONE_FAIL 95
#define CONE_FAIL_COST 50

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
    if( this_player()->query_spell_points() < CONE_COST ) {
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
	write( "Cast Cone of Cold at whom?\n" );
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
      this_player()->query_wis() + random( 40 ) < CONE_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - CONE_FAIL_COST );
	return ( 1 );
    }

    /* Rock and Roll Baby! */
    target->attacked_by( this_player() );
    level = ( this_player()->query_level() );
    if( level > 20 )
	level = 20;
    damage = 0;
    for( i = 0; i < level; i++ ) 
	damage += random( 10 ) + 15;
    printf( "You spread your palms towards %s.  A cone of frost shoots out towards %s.\n",
      target->query_name(), target->query_objective() );
    tell_object( target, this_player()->query_name() + " opens " + 
      this_player()->query_possessive() + " hands.\nSuddenly a cone of frost shoots at you!\n" );
    say( this_player()->query_name() + " opens " + this_player()->query_objective() +
      " hands.\nSuddenly a cone of frost shoots at " + target->query_name() + "!\n" );  

    /* Do we kill our target? */
    if( damage >= target->query_hp() ) {
	printf( "The cone of cold freezes %s solid!\n", target->query_name() );
	say( "The cone of frost freezes " + target->query_name() + " solid!\n", target );
	tell_object( target, "You feel your body numbing from the cold and fall to the ground!\n" );
    }

    /* Ok...time to hurt our target. */
    this_player()->add_xp( target->hit_player( damage, 7, ({ 3, 12 }) ) );

    /* Are we a wizard?  If so, keep our SP and tell us the damage. */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - CONE_COST );
    else
	printf( "WIZINFO:  Damage %d.\n", damage );

    /* Spell is done! */
    return ( 1 );
}
