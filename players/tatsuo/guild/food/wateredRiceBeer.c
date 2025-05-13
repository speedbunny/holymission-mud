inherit "obj/alco_drink";

reset( arg )
{
   ::reset( arg );
   
   if ( arg )
      return;
      
   set_name( "watered rice beer" );
   set_alias( "watered beer" );
   set_alt_name( "rice beer" );
   set_short( "a watered rice beer" );
   set_long( "A bottle of watered rice beer.\n" );
   set_drinker_mess( "Glugugugugugug\n" );
   set_value( 1 );
   set_strength( 1 );
   set_weight( 1 );
}
