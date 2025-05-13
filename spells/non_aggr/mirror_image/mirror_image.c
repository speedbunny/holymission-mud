
/* ################################################################
   #								  #
   #    		Mage Mirror Image                         #
   #                                          		          #
   ###############################################(C) Llort######## */


inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
   if(lev > 21) return 0;
   return 1;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "mirror image" );
   set_kind( NON_AGGRESSIVE );
   set_syntax( "cast 'mirror image'" );
   set_guild_allowed( 5, 5 );
   set_save_vs( NO_SAVE );
   set_cost( 40 );
   set_player_help(
"When a mirror image spell is invoked, the spellcaster causes several exact\n"+
"duplicates of himself to come into being around him. These images do exactly\n"+
"what the mage does. Since the spell causes a blurring and slight distortion\n"+
"when it is cast, it is impossible for opponents to be certain which are the\n"+
"illusions and which is the actual mage. When an image is struck by any kind\n"+
"of attack it disappears, but any other existing images remain intact until\n"+
"struck. At the end of the spell duration, all surviving images wink out.");
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object sh;

   if ( !valid_living( TP ) ) {
      return;
   }

   if ( check_success( act_skill, max_skill ) )
   {
        write("Ok.\n");
        if(TP->shad_id("mirror_image"))
        {
            write("Nothing seems to happen.\n");
        }
        else
        {
           say( TPNT + " blurrs and seems to duplicate!\n", TP, TP, "");
           sh=clone_object("/spells/non_aggr/mirror_image/mirror_image_shad");
           sh->start_shadow(TP, TPL+30, TPL/5+2+random(4));
        };
     
   }
}
