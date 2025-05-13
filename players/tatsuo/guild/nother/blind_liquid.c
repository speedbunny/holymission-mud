inherit "obj/treasure";
  
reset( arg )
{
   if ( arg )
      return;
   
   set_name( "liquid" );
   set_alias( "blinding liquid" );
   set_value( 0 );
   set_weight( 2 );
   
   set_short( "some blinding liquid" );
   set_long( "As you look at the blinding liquid, you cannot see anything for a moment.\n" );
}

get( arg )
{
   write( "As you trie to get the liquid, it runs through your fingers.\n" );

   return( 0 );
}
