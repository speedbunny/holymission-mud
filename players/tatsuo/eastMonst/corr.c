inherit "obj/monster";

#include "/players/tatsuo/guild/skill_id.h"

#define TP   (this_player())

reset( arg )
{
   ::reset( arg );

   set_name( "imtatsuo" );
   set_short( "Imtatsuo" );
   set_long( "Imtatsuo, the ki-corrector.\n" );
}

init( arg )
{
   object *nsoul;

   ::init( arg );

   if ( TP->query_guild() == 8 ) {
      if ( TP->query_religion() == "ZEN" ||
           TP->query_religion() == "Amaterasu" ) {
        return;
      }
      nsoul = present( "ninja_soul", TP );
      if ( nsoul->query_max_assass_skill() < 90 ) {
         nsoul->advance_skill_max( TP, KARATE_SKILL, 
                max( nsoul->query_karate_skill(), 100), 1 );
         nsoul->advance_skill_max( TP, THROW_SKILL, 
                max( nsoul->query_throw_skill(), 100), 1 );
         nsoul->advance_skill_max( TP, PARRY_SKILL, 
                max( nsoul->query_parry_skill(), 100), 1 );
         nsoul->advance_skill_max( TP, THC_SKILL, 
                max( nsoul->query_thc_skill(), 100), 1 );
         nsoul->advance_skill_max( TP, ACC_SKILL,
                max( nsoul->query_acc_skill(), 100), 1 );
         nsoul->advance_skill_max( TP, CAMOU_SKILL, 
                max( nsoul->query_camou_skill(), 100), 1 );
         nsoul->advance_skill_max( TP, ASSASS_SKILL, 
                max( nsoul->query_assass_skill(), 100), 1 );

         tell_object( TP, "*************************************************\n"+
                     "Imtatsuo says: Your kis has been corrected" + 
                     " corresponding to the\nold ki-system.\n" + 
                      "****************************************************\n");
      }
   }
}

max( a, b )
{
   if ( a > b )
      return( a );
   return( b );
}

