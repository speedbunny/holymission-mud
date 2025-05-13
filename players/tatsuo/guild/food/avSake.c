inherit "obj/alco_drink";

reset( arg )
{
   ::reset( arg );
   
   if ( arg )
      return;
      
   set_name( "average sake" );
   set_alt_name( "sake" );
   set_short( "an average sake" );
   set_long( "A bottle of average sake.\n" );
   set_drinker_mess( "Glug gloing glorp  aaaaahhhh !!!\n" );
   set_value( 9 );
   set_strength( 6 );
   set_weight( 1 );
}
