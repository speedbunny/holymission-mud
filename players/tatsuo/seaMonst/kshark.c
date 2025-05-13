inherit "obj/monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "shark" );
   set_alias( "killer-shark" );
   set_level( 20 );
   set_size( 4 );
   set_short( "A killer-shark" );
   set_long( "The killer-shark looks very aggressive. You fear its teeth.\n" );
   
   set_chance( 20 );
   set_spell_mess1( "The killer-shark bites around !!!" );
   set_spell_mess2( "The killer-shark BITES you !!!" );
   set_spell_dam( 20 + random(20) );

   set_no_ears();
   set_has_gills();
   set_aggressive( 1 );

   set_dead_ob( "/players/tatsuo/eastMonst/monst_died" );
}
