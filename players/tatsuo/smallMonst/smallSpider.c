#define PPATH ("/players/tatsuo/smallMonst/")
inherit "obj/monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "spider" );
   set_level( 2 );
   set_size( 2 );
   set_short( "a spider" );
   set_long( "A brown hairy spider, looking frightened at you.\n" );

   set_no_ears();
}
