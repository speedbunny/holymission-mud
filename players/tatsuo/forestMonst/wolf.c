#define PPATH ("/players/tatsuo/forestMonst/")
inherit "obj/monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "wolf" );
   set_alias( "big wolf" );
   set_level( 8 );
   set_size( 2 );
   set_short( "a big black wolf" );
   set_long( "A big black wolf. It looks very aggressive and nasty.\n" );
   
   set_aggressive( 1 );
   
   set_chance( 15 );
   set_spell_mess1( "The wolf bites !!!" );
   set_spell_mess2( "The wolf bites in your feet !!!" );
   set_spell_dam( 15 );

   set_dead_ob( "/players/tatsuo/eastMonst/monst_died" );
}
