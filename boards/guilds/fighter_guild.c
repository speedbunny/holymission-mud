inherit "/boards/board";

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   set_name( "Fighter Guild Board" );
}

int valid_remove( object who, int no )
{
   if ( who->query_real_name() == "guild/master"->query_wiz(3) )
      return ( 1 );
   return( ::valid_remove(who,no) );
}
