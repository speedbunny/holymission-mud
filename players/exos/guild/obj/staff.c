inherit "obj/weapon";
#define STAFF_TIME 1
#define STAFF_RATE 3

object owner;
int heal_count;

void reset(int arg) {
    ::reset(arg);
    if (arg == 0) {
	owner = this_player();
	set_name( "staff" );
	set_short( "A Mage's Staff" );
	set_long( "It seems to be an interesting wand with lots of runes graved into its surface.\n" );
	set_class( 4 );
	set_value( 0 );
	set_weight( 1 );
	set_alias( "mage staff" );
	set_alt_name( "mage_guild_staff" );
	set_read( "You fail to read the runes on the staff.\n");
	set_hit_func( this_object() );
	enable_commands();
	heal_count = 0;
    }
}

int wield( string str ) {
    if( id( str ) && !query_wielded() && this_player()->query_guild() == 5
      && this_player()->query_hands_free() ) {
	write( "The power of the wand pulses through your body.\n" );
	say( this_player()->query_name() + " emits a soft blue glow.\n" );
	owner = this_player();
	set_heart_beat( 1 );
    }
    return( ::wield(str) );
}

int un_wield() {
    if( this_player()->query_guild() == 5 ) {
	write( "A foreign energy seems to leave your body.\n" );
	say( this_player()->query_name() + " stops glowing.\n" );
    }
    set_heart_beat( 0 );
    return( ::un_wield() );
}

void heart_beat() {
    if( owner && objectp( wielded_by ) && wielded_by == owner ) {
	if( !heal_count ) {
	    owner->heal_self( STAFF_RATE * 2 );
	    if( heal_count == STAFF_TIME )
		heal_count = 0;
	    else 
		heal_count++; 
	}
    }
}

int throw_out_transfer() { return( 1 ); }

int drop() {
    this_player()->stop_wielding();
    write( "As you drop the staff it starts to fade.\n" );
    call_out( "dest_wand", 1 );
    return( 1 );
}

int dest_wand() {
    destruct( this_object() );
    return( 1 );
}

int weapon_hit( object victim ) {
    int power;

    power = this_player()->query_int() / 3;
    if( this_player()->query_guild() == 5 )
	return( power );
    return( 0 );
}
