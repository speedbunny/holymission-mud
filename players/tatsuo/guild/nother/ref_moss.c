inherit "obj/treasure";
  
reset( arg )
{
   if ( arg )
      return;
   
   set_name( "moss" );
   set_alias( "fluorescent moss" );
   set_value( 2 );
   set_weight( 1 );
   
   set_short( "some fluorescent moss" );
   set_long( "This is some flourescent moss. It looks somehow strange,\n" +
             "but useful in its own way.\n" );
}
