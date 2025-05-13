#define PPATH ("/players/tatsuo/smallMonst/")
inherit "obj/monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "snake" );
   set_alias( "greenish snake" );
   set_level( 4 );
   set_size( 2 );
   set_short( "a snake" );
   set_long( "A greenish snake.\n" );

   set_no_ears();
}
