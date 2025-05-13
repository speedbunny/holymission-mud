#define PPATH ("/players/patience/coastMonst/")
inherit "obj/monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "gull" );
   set_level( 5 );
   set_size( 2 );
   set_short( "a gull" );
   set_long( "A dirty looking gull.\n" );

   set_dead_ob( "/players/patience/eastMonst/monst_died" );
}
