#ifndef _ninja_communicate_
#define _ninja_communicate_

#include "/players/topaz/defs.h"

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

   if ( !(TP->query_wizard()) && TP->query_sp() < 20)
      write( "You don't have enough spellpoints.\n" );
   else {
      if ( str == "gender" ) {
         write( "Shout what to all of your gender ?\n" );
         return( 1 );
      }
      
      if ( explode( str, " " ) && explode( str, " " )[0] == "gender" ) {
         str = extract( str, strlen("gender")+1, strlen( str )-1 );
         write( "You shout to all of your gender:\n   " + str + "\n" );
         
         log_file( "SHOUTS", TP->query_real_name()+": "+TP->query_name() + 
                             " shouts to all " + _gender + ":\n  " + str + "!\n\n" );
         
	 u = users();
         for ( i = 0; i < sizeof( u ); i++ ) {
            if ( u[i]->query_guild() == 8 && u[i] != TP ) {
               if ( TP->query_level() >= 25 )
                  tell_object( u[i],
                        TP->query_name() + "-san shouts to all " + _gender + ":\n  " + str + "!\n" );
               else
                  tell_object( u[i],
                        TP->query_name() + " shouts to all " + _gender + ":\n  " + str + "!\n" );
            }
            else if ( TP != u[i] )
               tell_object( u[i],
                            TP->query_name() + " shouts something to all " + _gender ".\n" );
         }
         
      }
      else {
         write( "You shout:\n  " + str + "!\n" );
         shout( TP->query_name() + " shouts: " + str + "!\n" );
      }
      if ( !TP->query_wizard() )
        TP->restore_spell_points(-20);
   }
   
   return( 1 );
}
