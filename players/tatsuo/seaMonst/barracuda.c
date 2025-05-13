inherit "obj/monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "barracuda" );
   set_alias( "nasty barracuda" );
   set_level( 10 );
   set_size( 3 );
   set_short( "A nasty barracuda" );
   set_long( "This is long barracuda. It looks like a long, giant boa.\n" );
   
   set_chance( 10 );
   set_spell_mess1( "The barracuda bites around !!!" );
   set_spell_mess2( "The barracuda BITES you !!!" );
   set_spell_dam( 20 );

   set_no_ears();
   set_has_gills();
   set_aggressive( 1 );

   set_dead_ob( "/players/tatsuo/eastMonst/monst_died" );
}
