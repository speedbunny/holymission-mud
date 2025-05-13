#define KNOCK_COST 40
#define KNOCK_FAIL 30
#define KNOCK_FAIL_COST 20

int main( string str ) {
    object door;

    /* Are we alive? */
    if( this_player()->query_ghost() ) {
	write( "That just is not possible...\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Do we have the Spell Points to cast? */
    if( this_player()->query_spell_points() < KNOCK_COST ) {
	write( "You are too tired...\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Which door are we unlocking? */
    if( !str ) {
	write( "Cast Knock at which door?\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Do we successfully cast the spell? */
    if( this_player()->query_level() * 2 + this_player()->query_int() * 2 +
      this_player()->query_wis() + random( 40 ) < KNOCK_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - KNOCK_FAIL_COST );
	return ( 1 );
    }

    /* Is the door here? */
    door = present( str, environment( this_player() ) );
    if( !door || !door->number_of_doors() ) {
	write( "That door isn't here!\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return( 1 );
    }

    /* Rock and Roll Baby! */
    printf( "You point at the lock, and it glows briefly.\n" );
    say( sprintf( "%s points at the lock on %s, causing it to glow briefly.\n",
	this_player()->query_name(), str ), this_player() );
    if( !door->query_locked() )
	write( "You realize the door wasn't locked!\n");
    else {
	door->set_locked( 0 );
	door->query_partner_door()->set_locked( 0 );
    }

    /* Are we a wizard?  If so, keep our SP. */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - KNOCK_COST );

    /* Spell is done! */
    return ( 1 );
}
