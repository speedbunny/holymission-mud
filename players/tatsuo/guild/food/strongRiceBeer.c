inherit "obj/alco_drink";

reset( arg )
{
   ::reset( arg );
   
   if ( arg )
      return;
      
   set_name( "strong rice beer" );
   set_alias( "strong beer" );
   set_alt_name( "rice beer" );
   set_short( "a strong rice beer" );
   set_long( "A bottle of strong rice beer.\n" );
   set_drinker_mess( "Glugugugugugugugugugug  aaaaahhhh !!!\n" );
   set_value( 3 );
   set_strength( 3 );
   set_weight( 1 );
}
