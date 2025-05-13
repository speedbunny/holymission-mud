inherit "obj/treasure";
  
reset( arg )
{
   if ( arg )
      return;
   
   set_name( "white pepper" );
   set_alias( "pepper" );
   set_alt_name( "white" );
   set_value( 25 );
   set_weight( 1 );
   
   set_short( "some white pepper" );
   set_long( "It is a rare spice, but very common at Ezo.\n"+
             "People there use it for their delicious hot dishes.\n" );
}
