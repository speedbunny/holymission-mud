inherit "/boards/board";

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   set_name( "Ninja guild board" );
   my_env = "players/tatsuo/ezo/empty";
}
