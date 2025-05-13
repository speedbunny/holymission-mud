inherit "/boards/board";

#define MIN_LEVEL 0

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   set_name( "Vagabond Guild Board" );
}

int valid_remove( object who, int no )
{
   if ( who->query_real_name() == "guild/master"->query_wiz(10))
      return ( 1 );
   return( ::valid_remove(who,no) );
}
