inherit "obj/treasure";
  
reset( arg )
{
   if ( arg )
      return;
   
   set_name( "bark" );
   set_alias( "birch-bark" );
   set_value( 5 );
   
   set_short( "a piece of birch-bark" );
   set_long( "This is piece of bark from a birch-tree.\n" );
}
