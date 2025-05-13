#define PPATH ("/players/tatsuo/coastMonst/")
inherit "obj/monster";

reset(arg)
{
   object claw;

   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "crayfish" );
   set_level( 1 );
   set_size( 1 );
   set_short( "a crayfish" );
   set_long( "A small brown crayfish.\n" );

   set_no_ears();

   claw = clone_object( PPATH + "crayfish_claw" );
   transfer( claw, this_object() );
   command( "wield claw" );
}
