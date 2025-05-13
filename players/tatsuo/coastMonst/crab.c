#define PPATH ("/players/tatsuo/coastMonst/")
inherit "obj/monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "crab" );
   set_level( 1 );
   set_size( 1 );
   set_short( "a crab" );
   set_long( "A small dark brown crayfish.\n" );

   set_no_ears();
}
