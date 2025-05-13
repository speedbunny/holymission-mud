#define CONTINUAL_COST 60
#define CONTINUAL_FAIL 45
#define CONTINUAL_FAIL_COST 30

int main( string str ) {
    object target;
    int level;

    /* Are we alive? */
    if( this_player()->query_ghost() ) {
	write( "That just is not possible...\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Do we have the Spell Points to cast? */
    if( this_player()->query_spell_points() < CONTINUAL_COST ) {
	write( "You are too tired...\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* What is our target? */
    if( !str ) {
	write( "Cast Continual Light at what?\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }
    target = present( str, this_player() );
    if( !target )
	target = present( str, environment( this_player() ) );
    if( !target ) {
	write( "Cast Continual Light at what?\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Do we successfully cast the spell? */
    if( this_player()->query_level() * 2 + this_player()->query_int() * 2 +
      this_player()->query_wis() + random( 40 ) < CONTINUAL_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - CONTINUAL_FAIL_COST );
	return ( 1 );
    }

    /* Is the item already lighted? */
    level = ( target->_light_level() );
    if( level > 0 ) {
	printf( "%s is already lighted.\n", target->query_name() );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return( 1 );
    };


    /* Rock and Roll Baby! */
    if( level < 0 )
	target->_set_light_level( level + 1 );
    target->_set_light_level( 1 );
    if( !target->_light_level() ) {
	printf( "%s appears to be resistant to your spell!\n", target->query_name() );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return( 1 );
    }
    target->set_short( target->short() + "(glowing)" );
    printf( "You rub your palm over %s.  It starts to glow brightly!\n", target->query_name() );
    say( sprintf( "%s rubs %s palm over %s.  It starts to glow brightly!\n", 
	this_player()->query_name(), this_player()->query_possessive(), target->query_name() ), 
      this_player() );

    /* Are we a wizard?  If so, keep our sp. */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - CONTINUAL_COST );

    /* Spell is done! */
    return ( 1 );
}
