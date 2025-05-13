inherit "obj/alco_drink";

reset( arg )
{
   ::reset( arg );
   
   if ( arg )
      return;
      
   set_name( "best sake" );
   set_alt_name( "sake" );
   set_short( "a best sake" );
   set_long( "A bottle of best sake.\n" );
   set_drinker_mess( "Glug gloing glorp  aaaaaaaaaahhhhhhhhhhh fine !!!\n" );
   set_value( 13 );
   set_strength( 9 );
   set_weight( 2 );
}
