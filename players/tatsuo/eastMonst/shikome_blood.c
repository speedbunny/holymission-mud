inherit "obj/treasure";
  
reset( arg )
{
   ::reset();

   if ( arg )
      return;
      
   set_name( "shikome blood" );
   set_alias( "blood" );
   set_short( "Some blood of a shikome" );
   set_long( "This is some dark-red blood of a shikome.\n" );
   
   set_value( 16 );
}

init( )
{
   ::init();
}
