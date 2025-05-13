#ifndef _ninja_communicate_
#define _ninja_communicate_

int noff;

/* --- the shout -------------------------------------------------------------- */
_shout( str )
{
   object *u;
   int    i;

   if ( !str ) {
      write( "Shout what ?\n" );
      return( 1 );
   } 

   if ( !(TP->query_wizard()) && TP->query_sp() < TP->query_max_sp()/5 )
      write( "You don't have enough spellpoints.\n" );
   else {
      if ( str == "nihonese" ) {
         write( "Shout what in nihonese ?\n" );
         return( 1 );
      }
      
      if ( explode( str, " " ) && explode( str, " " )[0] == "nihonese" ) {
         str = extract( str, strlen("nihonese")+1, strlen( str )-1 );
         write( "You shout in nihonese:\n   " + str + "\n" );
         
         log_file( "SHOUTS", TP->query_real_name()+": "+TP->query_name() + 
                             " shouts in nihonese:\n  " + str + "!\n\n" );
         
	 u = users();
         for ( i = 0; i < sizeof( u ); i++ ) {
            if ( u[i]->query_guild() == 8 && u[i] != TP ) {
               if ( TP->query_level() >= 25 )
                  tell_object( u[i],
                        TP->query_name() + "-san shouts in nihonese:\n  " + str + "!\n" );
               else
                  tell_object( u[i],
                        TP->query_name() + " shouts in nihonese:\n  " + str + "!\n" );
            }
            else if ( TP != u[i] )
               tell_object( u[i],
                            TP->query_name() + " shouts something in nihonese.\n" );
         }
         
      }
      else {
         write( "You shout:\n  " + str + "!\n" );
         shout( TP->query_name() + " shouts: " + str + "!\n" );
      }
      if ( !TP->query_wizard() )
         TP->restore_spell_points( -1 * (TP->query_max_sp()/5) );
   }
   
   return( 1 );
}

/* --- say -------------------------------------------------------------------- */
_say( what )
{
   int    i;
   object inv;
   string name;

   if ( !what ) {
      write( "Say what ?\n" );
      return( 1 );
   }
   else if ( what == "nihonese" ) {
      write( "Say what in nihonese ?\n" );
      return( 1 );   
   }
   if ( TP->query_level() > 24 )
      name = TP->query_name() + "-san says";
   else
      name = TP->query_name() + " says";

   if ( explode( what, " " ) && explode( what, " " )[0] == "nihonese" ) {
      what = extract( what, strlen("nihonese")+1, strlen( what )-1 );
      write( "You say in nihonese: " + what + "\n" );
      inv = all_inventory( environment( this_player() ) );
      for ( i = 0; i < sizeof(inv); i++ ) {
         if ( living( inv[i] ) ) {
            if ( inv[i]->query_guild() == 8 && inv[i] != TP ) {
               tell_object( inv[i], name + 
                               " in nihonese:\n  " + what + "\n" );
            }
            else if ( inv[i] != TP )
               tell_object( inv[i], name + 
                                    " something in nihonese.\n" );
         }
      }
   }
   else {
      say( name +": " + what + "\n" );
      write( "You say: " + what + "\n" );
   }
      
   return( 1 );
}
