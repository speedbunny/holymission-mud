#define GATE_COST 200
#define GATE_FAIL 150
#define GATE_FAIL_COST 100

int main( string str ) {
    object target, gate;

    /* Are we alive? */
    if( this_player()->query_ghost() ) {
	write( "That just is not possible...\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Do we have the Spell Points to cast? */
    if( this_player()->query_spell_points() < GATE_COST ) {
	write( "You are too tired...\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Do we have a target? */
    if( !str ) {
	write( "Who do you wish to send a gate to?\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Who is our target? */
    target = find_living( str );
    if( !target ) {
	write( "Cast Gate to whom?\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* No Gates to NPCs and Wizards! */
    if( target->query_npc() || target->query_immortal() ) {
	write( "You can only send a gate to players!\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* No gates in no_teleport areas. */
    if( environment( target )->query_property( "no_teleport" ) ||
      environment( this_player() )->query_property( "no_teleport" ) ) {
	write( "A strange magical force seems to block the spell.\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return( 1 );
    }

    /* Do we successfully cast the spell? */
    if( this_player()->query_level() * 2 + this_player()->query_int() * 2 +
      this_player()->query_wis() + random( 40 ) < GATE_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - GATE_FAIL_COST );
	return ( 1 );
    }

    /* Rock and Roll Baby! */
    printf( "You slowly seperate your hands, creating a gate for %s.\n", target->query_name() );
    say( sprintf( "%s slowly seperates %s hands while in deep concentration.\n", 
	this_player()->query_name(), this_player()->query_possessive() ) );
    gate = clone_object( "/players/exos/guild/obj/gate" );
    move_object( gate, environment( target ) );
    gate->set_gate( this_player() );

    /* Are we a wizard?  If so, keep our SP. */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - GATE_COST );

    /* Spell is done! */
    return ( 1 );
}               
