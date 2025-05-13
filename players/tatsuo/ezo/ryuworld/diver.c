object *diver;

id( str )
{
   return( str == "diver" );
}

query_name()
{
   return( "diver" );
}

get( )
{
   return( 1 );
}

start_dive( who )
{
   remove_call_out( "dive" );
   call_out( "dive", 30, 1 );
   diver = who;
}

dive( arg )
{
   if ( environment(diver) && 
        environment(diver)->query_water() )
   {
      switch( arg ) {
      case 1:
         tell_object( diver, 
                      "YOU HAVE TO BREATH SOON !!!\n" );
         call_out( "dive", 15, 2 );
         break;
      case 2:
         tell_object( diver,
                      "YOU HAVE TO BREATH REALLY SOON !!!\n" );
         call_out( "dive", 20, 3 );
         break;
      case 3:
         tell_object( diver,
             "YOU HAVE AN URGENT FEELING TO BREATH AND TAKE A DEEP BREATH.\n"+
             "IMMEDIATELLY YOUR LOUNG FILLS WITH WATER and ...\n" );
             this_player()->hit_player( 100000 );
          destruct( this_object() );
          return;
      default: break;
      }
   }
   else
      destruct( this_object() );
} 
