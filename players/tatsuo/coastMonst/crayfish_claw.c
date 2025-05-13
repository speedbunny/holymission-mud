#define PPATH ("/players/tatsuo/eastMonst/")
inherit "obj/weapon";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "claw of a crayfish" );
   set_alias( "clayfishclaw" );
   set_alt_name( "claw" );
   set_class( 1 );
   set_value( 10 );
   set_weight( 1 );
   set_short( "a claw of a crayfish" );
   set_long( "The tiny claw of a crayfish.\n" );
}
