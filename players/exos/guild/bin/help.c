int main( string str ) {
    string *file, path;
    int i, j;

    if( !str )
	return ( 0 );
    if( str == "levels" ) {
	"guild/master"->list_levels( 5, this_player()->query_gender() );
	return ( 1 );
    }
    file = explode( str, " " );
    i = 1;
    path = file[0];
    j = sizeof( file );
    while( i < j ) {
	path += "_" + file[i];
	i++;
    }
    path = "/players/exos/guild/docs/" + path;
    if( file_size( path ) >= 0 )
	cat ( path );
    else
	return ( 0 );
    return ( 1 );
}
