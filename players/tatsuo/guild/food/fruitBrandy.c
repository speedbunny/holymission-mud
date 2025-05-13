inherit "obj/alco_drink";

reset( arg )
{
   ::reset( arg );
   
   if ( arg )
      return;
      
   set_name( "fruit brandy" );
   set_alias( "brandy" );
   set_short( "a fruit brandy" );
   set_long( "A bottle of fruit brandy\n" );
   set_drinker_mess( "Glug gloing glorp  ooooohhhhhhh hot !!!\n" );
   set_value( 18 );
   set_strength( 12 );
   set_weight( 2 );
}
