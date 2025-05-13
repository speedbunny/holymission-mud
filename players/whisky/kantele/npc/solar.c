
/* solar */

inherit "obj/monster";
#include "../defs.h"

object shad;

reset(arg)
{
   object pot;

   ::reset( arg );
   
   if ( arg )
      return;

   set_race( "angel" ) ;
   set_name( "solar" );
   set_level( 100 );
   set_size( 3 );
   set_short( query_name() );
   set_long(
   "A beautiful solar, prisoned by a magic forcefield.\n");
   set_gender( 2 );
   set_al( 5000 );
   set_number_of_arms( 2 );
   set_n_wc( 200 );
   shad = clone_object("/obj/shadows/sanct_shad");
   shad->start_shadow(this_object(),0);
   change_spell( "lightning bolt", 99, 99, 20);
}

int detect_invis()
{
   return( 1 );
}

int infravision()
{
   return( 1 );
}

int is_prisoned()
{
     return 1;
}

string look_info()
{
     return " (prisoned in a forcefield) ";
}

int set_free(object mob)
{
    tell_object(mob,"The beautiful Solar thanks you !\n");
    tell_room(environment(),"The Solar vanishes !\n");
    shout("You hear a voice from heaven: "+
           mob->query_name()+" set me free !\n");
    mob->add_experience(50000);
// Mangla please replace this.  quest name was and should
//    still be "free_solar" This is not a new quest.
//    effected players will be fixed.
    mob->set_quest("free_solar");
    call_out("dest_me",0);
    return 1;
}

void dest_me()
{
     destruct(this_object());
     return;
}


int cast_spell( object vic )
{
   int rnd;

/*
   if ( !query_casting() ) 
   {
*/
      rnd = random( 100 );
      if ( rnd < 50 )
         npc_process_spell( "lightning bolt", vic );
// }
   return( 1 );
}


