inherit "obj/treasure";
  
reset( arg )
{
   ::reset();

   if ( arg )
      return;
      
   set_name( "mukade blood" );
   set_alias( "blood" );
   set_short( "Some blood of a mukade" );
   set_long( "This is some greenish blood of a mukade.\n" );
   
   set_value( 25 );
}

init( )
{
   ::init();
}
