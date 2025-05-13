#define PPATH ("/players/tatsuo/coastMonst/")
inherit "obj/monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "gull" );
   set_level( 2 );
   set_size( 2 );
   set_short( "a gull" );
   set_long( "A dirty looking gull.\n" );

   set_dead_ob( "/players/tatsuo/eastMonst/monst_died" );
}
