#define GUILD "mage"                  /* mage guild */
#define GM "guild/master"

inherit "guild/guild_room";
int guild;

void reset( int arg ) {
    if( arg ) return;
    guild = GM->query_number( GUILD );
    set_guild( guild );
    short_desc = "Mages guild";
    long_desc = "\
Mages guild. The place is dominated by lots of mirrors covering the walls.\n\
To the west you can see a hallway leading deeper into the Tower. The doorway\n\
emits a lightblue glow. You notice a sign on the wall saying:\n\
          You can 'start' here now if you like.\n\
Commands: advance, list, list [number], list all or join.\n";
    property = ({ "no_fight" });
    dest_dir = ({ "room/mount_top2", "south",
      "/players/saffrin/area/tower/room/hall1", "west" });
    clone_list=({ 1, 1, "yorel", "/players/saffrin/area/tower/npc/oldyorel", 0 });
    ::reset( arg );
}

init() {
    ::init();
    add_action( "startroom","start" );
}

int do_advance( string arg ) {
    ::do_advance( arg );
    return( 1 );
}

int do_join() {
    if( ::do_join() )
	return( 1 );
    if( this_player()->query_int() < 4 ) {
	write( "Mage-Master Yorel tells you: You are too dull to learn spells.\n" );
	return( 1 );
    }  
    if( this_player()->query_money() < 100 ) {
	write( "Mage-Master Yorel tells you: You don't have enough gold coins.\n\
Mage-Master Yorel tells you: You need to pay 100 gold coins for your mage's robe!\n");
	return( 1 );
    }
    this_player()->add_money( -100 );
    this_player()->set_guild( guild );
    write( "You pay your fee for joining.\nMage-Master Yorel tells you: Now you are a mage!\n" );
    say( this_player()->query_name() + " has joined the mages guild.\n" );
    log_file( "GUILD.JOIN", this_player()->query_name() + " joins the " + GUILD + "'s guild at " +
      ctime() + "\n" );
    return( 1 );
}

int query_maxsp( int lvl, int ll ) {
    int max;

    max = 90 + ( lvl * 17 );
    while( lvl > 0 ) {
	max += ( lvl / 2 );
	lvl--; 
    }
    return( max + ( ll * 10 ) );
}

int query_maxhp( int lvl, int ll ) {
    int _hp;

    _hp = 40;
    switch(lvl) {
    case 11..20:
	_hp += 140;
	_hp += ( lvl - 10 ) * 13;
	break;
    case 21..30:
	_hp += 270;
	_hp += ( lvl - 20 ) * 11;
	break;
    case 31..40:
	_hp += 380;
	_hp += ( lvl - 30 ) * 9;
	break;
    default:
	_hp += lvl * 14;
	break;
    }
    if( ll < 11 )
	_hp += ll * lvl / 3;
    else
	_hp += 10 * lvl / 3 + ( ll - 10 ) * lvl / 4;
    return( _hp );
}

int query_mage_guild() { return( 1 ); }

int startroom( string str ) {
    if( this_player()->query_guild() != 5 ) {
	write( "You have to go to your own guild.\n" );
	return( 1 );
    }
    if( !str ) {
	write( "Where do you want to start?  Church or guild?\n" );
	return( 1 );
    }
    str = lower_case( str );
    switch( str ) { 
    case "guild":
	this_player()->start_in_guild( 1 );
	write( "You will start in the guild from now on.\n" );
	this_player()->save_me( 1 );
	break;
    case "church":
	this_player()->start_in_guild( 0 );
	write( "You will start in the church from now on.\n" );
	this_player()->save_me( 1 );
	break;
    default:
	write( "You have to start in the guild or the church!\n" );
    }
    return( 1 );
}
