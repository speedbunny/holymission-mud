id( arg )
{
   return( arg == "tester" );
}
query_name() { return( "tester" ); }
short()      { return( "tester" ); }
long()       { write( "tester\n" ); }
get()        { return( 1 ); }
init()
{
   add_action( "do_freeze", "freeze" );
}

do_freeze( arg )
{
   return( "/players/patience/guild/sorcerer_spells/freeze"->do_freeze(arg) );
}
