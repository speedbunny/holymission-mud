inherit "obj/treasure";
  
reset( arg )
{
   if ( arg )
      return;
   
   set_name( "fugu" );
   set_value( 20 );
   
   set_short( "some fugu" );
   set_long( "It looks very poisonous.\n" );
}
