
/* ################################################################
   #								  #
   #    		    Mage pose                             #
   #                                          		          #
   ###############################################(C) Llort######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
   return 0;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "pose" );
   set_kind( NON_AGGRESSIVE );
   set_syntax( "cast 'pose' [message]" );
   set_guild_allowed( 5, 15 );
   set_save_vs( NO_SAVE );
   set_cost( 150 );
   set_player_help(
"Nothing is known about this ancient spell. Maybe you could discover its \n"+
"function if you tested it.");
}

void release_spell( string arg, int act_skill, int max_skill )
{
   if ( check_success( act_skill, max_skill ) )
   {
      say(TPNT+" makes some magical gestures.\n",0,TP,"");
      if(TPL<25) {
	 shout(TPN+" sends a fireball in the sky.\n");
	 write("You send a fireball in the sky.\n");
      } else if(TPL<29) {
	 if(arg) {
	    shout(TPN+" summons a firework, writing "+arg+" in the sky.\n");
	    write("You summon a firework, writing "+arg+" in the sky.\n");
	 } else {
	    shout(TPN+" summons a firework in the sky.\n");
	    write("You summon a firework in the sky.\n");
	 }
      } else {
	 if(arg) {
	    shout(TPN+" rises towards the sky, inside of a gigantic torrent"+
		      " of fire.\n" + capitalize(TPPRO) +
		      " burns the world with the words: "+arg+"\n");
	    write("You rise towards the sky, inside of a gigantic torrent"+
	          " of fire.\nYou burn the world with the words: "+arg+"\n");
	 } else {
	    shout(TPN+" rises towards the sky, inside of a gigantic torrent"+
		      " of fire.\nAs " + TPPRO +
		      " points to heaven lightning springs out"+
		      " from "+TPPOS+" hands.\n");
	    write("You rise towards the sky, inside of a gigantic torrent"+
	          " of fire.\nAs you point to heaven lightning springs out"+
	          " from your hands.\n");
	 }
      }
   }
}
