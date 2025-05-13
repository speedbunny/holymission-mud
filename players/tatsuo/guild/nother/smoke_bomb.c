inherit "obj/treasure";
  
reset( arg )
{
   if ( arg )
      return;
   
   set_name( "smoke bomb" );
   set_alias( "bomb" );
   set_alt_name( "smoke" );
   set_value( 35 );
   set_weight(1);
   
   set_short( "A smoke bomb" );
   set_long( "A small fragile metal ball, which the ninja masters have\n"+
             "designed to burst into a smoke cloud when broken while\n"+
             "vanishing.\n");

}

