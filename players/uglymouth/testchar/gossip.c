inherit "/obj/monster";

int busy_catching;
string *rumour;

void reset( int flag ) {
    ::reset( flag );

    if( flag ) return;
    set_name( "juan the rumourmonger" );
    set_alias( "gossip" );
    set_level( 4 );
    set_race( "human" );
    set_short( "Juan the Rumourmonger" );
    set_long( "This is Juan. Don't tell him your secrets.\n" );
rumour = allocate( 2 );
}

void catch_tell( string str ) {
string who, what;
    if( busy_catching ) return;
    busy_catching = 1;
    if( sscanf( str, "%s says: %s", who, what ) == 2 && !random( 20 ) ) {
	rumour = what;
	rumour = ({ who, what });
    }
    busy_catching = 0;
}
