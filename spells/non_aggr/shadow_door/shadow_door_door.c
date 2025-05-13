// the door for the shadow door
// used for the shadow door - spell
// patience, 050295
// -------------------------------------------------------------------------

object dest;            // where the door leads to

int id( string str )
{
   return( str == "shadow door" || str == "shadow-door" ||
           str == "shadowy door" || str == "door" );
}

string query_name()
{
   return( "shadowy door" );
}

string short()
{
  return( "A shadowy door" );
}

string long()
{
   write( "A shadowy door. Looking inside, you can see only shadows.\n"+
          "You can remember, that you have heard of these door before\n"+
          "and do not want to enter it at all !!!\n" );
}

init_door( )
{
   dest = clone_object( "/spells/non_aggr/shadow_door/shadow_door_room" );
   dest->init_room( this_object() );
}

dest_door( )
{
   if ( environment(this_object()) )
      tell_room( environment(this_object()),
                 "The shadowy door faints into the shadows.\n" );
   destruct(this_object());
}

void init()
{
   add_action( "do_enter", "enter" );
}

int do_enter( string what )
{
   if ( !id(what) ) return( 0 );

   if ( !dest ) {
      destruct( this_object() );
      return( 0 );
   }

   write( "You have the feeling like stepping into a different plane !\n" );
   this_player()->move_player( "into the door#"+file_name(dest) );

   return( 1 );
}
