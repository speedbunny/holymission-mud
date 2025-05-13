inherit "guild/guild_room";

string *allowed;

void reset( int arg ) {
    ::reset( arg );
    if( !arg ) {
set_guild( 6 );
set_light( 1 );
short_desc = "Bard Guild Room";
long_desc = "This is the bard guild room.\n\
All functions are called through Taliesin.\n";
allowed = ({ "human", "elf", "half-elf", "gnome", "hobbit" });
    }
}

void add_init() {
    if( !this_player()->query_immortal() ) {
this_player()->start_at_guild( 0 );
this_player()->move_player( "church#/room/church" );
    }
}

status do_join() {
    if( ::do_join() ) 
return ( 1 );
    if( member_array( this_player()->query_race(), allowed ) == -1 ) {
write( "You are not artistic enough to be a real Bard!\n" );
return ( 1 );
    }
    if( this_player()->query_alignment() < 0 ) {
write( "You're too nasty to be a real Bard!\n" );
return ( 1 );
    }
    if( this_player()->query_chr() < 7 ) {
write( "You are not charismatic enough to be a real Bard!\n" );
return ( 1 );
    }
    write( "Welcome to the Guild of Bards.\n" );
    this_player()->set_guild( 6 );
    this_player()->start_at_guild( 0 );
    write_file( "/players/turbo/guild/log/join", capitalize( this_player()->query_real_name() ) + 
      " joined at " + ctime( time() ) + "!\n");
    log_file( "GUILD.JOIN", capitalize( this_player()->query_real_name() ) + 
      " joined the bard guild at " + ctime( time() ) + ".\n");
    return ( 1 );
} 

int query_maxhp( int lvl ) {
    return ( 100 + (lvl * 20 ) + ( this_player()->query_legend_level() * 7 ) );
}

int query_maxsp( int lvl ) {
    return ( 125 + ( lvl * 25 ) + ( this_player()->query_legend_level() * 10 ) );
}

int numberer( string str ) {
    int number;

    if( !str ) 
return ( 0 );
    if( sscanf( str, "%d", number) == 1) 
return ( number );
    return ( 0 );
} 
