#define TELEPORT_COST 150
#define TELEPORT_FAIL 95
#define TELEPORT_FAIL_COST 75

int main( string str ) {
    object robe, memory;
    string target;

    /* Are we alive? */
    if( this_player()->query_ghost() ) {
	write( "That just is not possible...\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Are we in a no_teleport zone? */
    if( environment( this_player() )->query_property( "no_teleport" ) ) {
	write( "You are not allowed to cast this here!\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return( 1 );
    }

    /* Do we have the Spell Points to cast? */
    if( this_player()->query_spell_points() < TELEPORT_COST ) {
	write( "You are too tired...\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Do we successfully cast the spell? */
    if( this_player()->query_level() * 2 + this_player()->query_int() * 2 +
      this_player()->query_wis() + random( 40 ) < TELEPORT_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - TELEPORT_FAIL_COST );
	return ( 1 );
    }

    /* Make sure we have our robe!!! */
    robe = present( "magesoul", this_player() );
    if( !robe ) {
	write( "There is a problem!  Please mail Exos!\n" );
	return( 1 );
    }

    /* Where are we teleporting to? */
    if( str == "guild" )
	target = "/players/exos/guild/room";
    else if( str == "church" )
	target = "/room/church";

    /* Do we have a memorized site? */
    else if( str == "memory" ) {
	memory = robe->query_memorized();
	if( !memory ) {
	    write( "You haven't memorized a location!\n" );
	    say( this_player()->query_name() + " stops casting.\n", this_player() );
	    return( 1 );
	}
	target = file_name( memory );
    }

    /* Have we teleported before? */
    else if( str == "back" ) {
	memory = robe->query_back();
	if( !memory ) {
	    write( "You haven't teleported from anywhere!\n" );
	    say( this_player()->query_name() + " stops casting.\n", this_player() );
	    return( 1 );
	}
	target = file_name( memory );
    }

    else {
	write( "Where do you want to teleport to?\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return( 1 );
    }

    /* Rock and Roll Baby! */
    robe->set_back( environment( this_player() ) );
    printf( "You make some magical gestures, then vanish in a puff of smoke.\n" );
    say( this_player()->query_name() + " makes some magical gestures.\n", this_player() );
    this_player()->move_player( "in a puff of smoke#" + target );

    /* Are we a wizard?  If so, keep our SP. */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - TELEPORT_COST );

    /* Spell is done! */
    return ( 1 );
}
