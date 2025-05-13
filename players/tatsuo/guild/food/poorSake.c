inherit "obj/alco_drink";

reset( arg )
{
   ::reset( arg );
   
   if ( arg )
      return;
      
   set_name( "poor sake" );
   set_alt_name( "sake" );
   set_short( "a poor sake" );
   set_long( "A bottle of poor sake.\n" );
   set_drinker_mess( "Glug gloing glorp  aahh !!!\n" );
   set_value( 5 );
   set_strength( 3 );
   set_weight( 1 );
}
