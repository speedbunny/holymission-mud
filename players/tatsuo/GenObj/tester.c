#include "/players/patience/GenObj/move_blocked.h"

inherit "obj/treasure";
  
reset( arg )
{
    
  if ( arg )
     return;
  
  set_id("tester");
  set_short("Tester");
  set_long("Tester.\n");
}

init( arg ) {
   add_action( "_throw", "testx" );
}

_throw( arg )
{
   object ob;
   
   if ( !arg )
      return;
      
   ob = present( arg, this_player() );
   if ( !ob ) {
      write( "You dont have a " + arg + ".\n" );
      return;
   }
   
   move_blocked( ob, environment(this_player()), this_player()->query_attack() );
   write( "OK.\n" );
   return( 1 );
}
