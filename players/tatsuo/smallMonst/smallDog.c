#define PPATH ("/players/tatsuo/smallMonst/")
inherit "obj/monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "dog" );
   set_level( 5 );
   set_size( 2 );
   set_short( "a little dog" );
   set_long( "A little brown dog with sharp teeth.\n" );
}
