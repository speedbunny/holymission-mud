int _petition(string str) {
   if( !str )
   return (0);
   write("Thanks, your petition has been accepted.\n");
   write_file("/players/bobo/clan/log/petition",
   this_player()->query_name() + " at " + ctime( time() ) + 
      ":\n" + str + "\n\n" );
    return ( 1 );
}
