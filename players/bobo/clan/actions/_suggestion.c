
int _suggestion(string str) {
    if( !str )
	return ( 0 );
    write("Thanks, your suggestion has been noted.\n");
    write_file("/players/bobo/clan/log/suggestion",
      this_player()->query_name() + " at " + ctime( time() ) + 
      ":\n" + str + "\n\n" );
    return ( 1 );
}
