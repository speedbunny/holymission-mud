inherit "obj/treasure";
  
reset( arg )
{
   if ( arg )
      return;
   
   set_name( "poison" );
   set_alt_name( "dart-poison" );
   
   set_short( "some dart-poison. You can dip darts in it" );
   set_long( "Some dart-poison. You can dip darts in it.\n" );
}

get( arg )
{
   return( 0 );
}
