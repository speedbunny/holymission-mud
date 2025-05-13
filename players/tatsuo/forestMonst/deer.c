#define PPATH ("/players/tatsuo/forestMonst/")
inherit "obj/monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "deer" );
   set_level( 7 );
   set_size( 2 );
   set_short( "a deer" );
   set_long( "A deer with very shy eyes.\n" );
   
   set_chance( 10 );
   set_spell_mess1( "The deer hits with his antlers !!!" );
   set_spell_mess2( "The deer hits you with its antlers !!!" );
   set_spell_dam( 10 );
   
   set_whimpy( 30 );

   set_dead_ob( "/players/tatsuo/eastMonst/monst_died" );
}
