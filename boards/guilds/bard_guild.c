inherit "/boards/board";

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   set_name( "Bard Guild Board" );
   my_env = "players/turbo/guild/rooms/bard1";
}
