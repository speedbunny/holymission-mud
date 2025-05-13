inherit "obj/alco_drink";

reset( arg )
{
   ::reset( arg );
   
   if ( arg )
      return;
      
   set_name( "shochu" );
   set_short( "a shochu" );
   set_long( "A bottle of shochu.\n" );
   set_drinker_mess( "ooooohhhhhhh hot !!! You spit fire !!!!\n" );
   set_value( 25 );
   set_strength( 18 );
   set_weight( 2 );
}
