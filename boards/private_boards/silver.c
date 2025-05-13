inherit "/boards/board";

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   set_name( "Silver's IQ raising board" );
}

int valid_remove( object who, int no )
{
   if ( who->query_real_name() == "silver" ) return( 1 );
   return( ::valid_remove(who,no) );
}
