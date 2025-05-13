inherit "obj/treasure";
  
reset( arg )
{
   if ( arg )
      return;
   
   set_name( "liquid" );
   set_alias( "reflecting liquid" );
   set_value( 0 );
   set_weight( 1 );
   
   set_short( "some reflecting liquid" );
   set_long( "This is some strange reflection liquid. You can see yourself in it.\n" );
}

get( arg )
{
   write( "As you trie to get the liquid, it runs through your fingers.\n" );

   return( 0 );
}
