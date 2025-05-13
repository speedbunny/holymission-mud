inherit "obj/alco_drink";

reset( arg )
{
   ::reset( arg );
   
   if ( arg )
      return;
      
   set_name( "weak rice beer" );
   set_alias( "weak beer" );
   set_alt_name( "rice beer" );
   set_short( "a weak rice beer" );
   set_long( "A bottle of weak rice beer.\n" );
   set_drinker_mess( "Glugugugugugugugugugug\n" );
   set_value( 2 );
   set_strength( 2 );
   set_weight( 1 );
}
