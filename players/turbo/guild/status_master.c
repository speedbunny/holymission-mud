#define LIST "/players/turbo/guild/status_list"
string *guildmaster, *conductor;

void reset( int arg ) {
    if( arg ) 
       return;
    restore_object( LIST );
    if( !guildmaster ) 
       guildmaster=({ ({}) });
    if( !conductor ) 
       conductor=({ ({}) });
}

status query_guildmaster( string str ) {
    int i, j;

    i = 0;
    j = sizeof( guildmaster );
    while( i < j ) {
	if( guildmaster[i] == str ) 
           return ( 1 );
        i++;
    }
    return ( 0 );
}

status query_conductor( string str ) {
    int i, j;

    i = 0;
    j = sizeof( conductor );
    while( i < j ) {
	if( conductor[i] == str ) 
        return ( 1 );
        i++;
    }
    return ( 0 );
}

status add_status( string who, string what ) {
    if( what == "guildmaster" ) 
       guildmaster += ({ who });
    if( what == "conductor" ) 
       conductor += ({ who });
    save_object( LIST );
    return ( 1 );
}

status remove_status( string who, string what ) {
    int i, j;

    if( what == "guildmaster" ) {
	i = 0;
        j = sizeof( guildmaster );
        while( i < j ) {
	    if( guildmaster[i] == who ) {
		guildmaster -= ({ guildmaster[i] });
	    }
            i++;
	}
    }
    if( what == "conductor" ) {
        i = 0;
        j = sizeof( conductor );
	while( i < j ) {
	    if( conductor[i] == who ) {
		conductor -= ({ conductor[i] });
	    }
            i++;
	}
    }
    save_object( LIST );
    return ( 1 );
}
