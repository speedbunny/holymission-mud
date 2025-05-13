inherit "obj/treasure";
  
reset( arg )
{
   if ( arg )
      return;
   
   set_name( "red pepper" );
   set_alias( "pepper" );
   set_alt_name( "red" );
   set_value( 25 );
   set_weight(1);
   
   set_short( "some red pepper" );
   set_long( "It is a rare spice, but very common at Ezo.\n"+
             "People there use it for their delicious hot dishes.\n" );
}
