/* clean up */

#define DEBUG_CLEAN  0

// the docu is wrong !  inheritancde is 2 or higher !
clean_up(arg) 
{
  int i, sz;
  object *inv;

#if DEBUG_CLEAN
  log_it( "ROOM: "+file_name(this_object())+", arg="+arg+", " );
#endif

  if ( arg > 1 ) {                 // used for inheritance, never clean up
#if DEBUG_CLEAN
     log_it( "EXIT: inheritance\n" );
#endif
     return( 0 );
  }

  if (this_object()->query_property("no_clean_up")) {
#if DEBUG_CLEAN
      log_it( "EXIT: property\n" );
#endif
      return 1; 
  }

  inv=deep_inventory(this_object());

  for(sz = sizeof(inv),i=0; i < sz; i++) 
  {
/*
    if ( (living(inv[i]) && (inv[i]->query_hp() < inv[i]->query_max_hp()))
          || inv[i]->query_player() || interactive(inv[i]) || 
          inv[i]->no_clean_up() )
*/
    if ( interactive(inv[i]) || inv[i]->no_clean_up() )
    {
#if DEBUG_CLEAN
        log_it( "EXIT: inv_check\n" );
#endif
        return 1;
    }
  }
  /* now we can clean up */

  for(sz = sizeof(inv),i=0; i < sz; i++) 
  {
     if(inv[i])
        destruct( inv[i] );
   }
#if DEBUG_CLEAN
   log_it( "CLEARED !\n" );
#endif
   destruct( this_object() );
}

#if DEBUG_CLEAN
log_it( arg )
{
   log_file( "CLEAN_UP", arg );
}
#endif
