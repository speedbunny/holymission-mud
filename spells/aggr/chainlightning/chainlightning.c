
/* ################################################################
   #								  #
   #    		Mage Chainlightning                       #
   #                                          		          #
   ###############################################(C) Llort######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
   if(lev<10) return 5;
   if(lev<15) return 4;
   if(lev<20) return 3;
   if(lev<25) return 2;
   return 1;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "chainlightning" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'chainlightning'" );
   set_save_vs( ELECTRICITY );
   set_save_vs_info( "for half damage" );
   set_damage_info( "level*d30 up to 25d30" );
   set_guild_allowed( 5, 16 );
   set_cost( 100 );
   set_player_help(
"This spell will unleash a powerful lightning bolt which will leap from foe to\n"+
"foe, electrocuting as many as it can. However, the bolt becomes weaker as it\n"+
"rips through each foe, reducing damage down by a die per foe. Once the spell\n"+
"decreases to 0d30 it will dissipate.");
}

void release_spell( string arg, int act_skill, int max_skill )
{
    object *inv, oppo;
    int    dice,i,sz,damage, odam;
    string oppo_name;

    if ( !check_success( act_skill, max_skill ) ) return;

    inv = all_inventory( environment(TP) ) - TP->grmems_in_room();
    dice = ( TPL > 25 ? 25 : TPL);

    write("A lightning bolt shoots from your hand toward your enemies,\n"+
          "bouncing wildly between them.\n");
    say(TPNT+" raises "+TPPOS+" hands and the area fills with lightning!\n",
        0,TP,"Suddenly the area is filled with lightning!\n");

    sz=sizeof( inv );
    for ( i = 0; i < sz && dice > 0; i++ )
    {
        if ( living( inv[i] ) )
        {   
             oppo=inv[i];
             odam = damage = roll_dice(dice,30,0);

             switch( apply(call,oppo,"do_save",Skind,Ssave,0,0,this_object()))
             {
                 case IMMUNE:      damage = 0; break;
                 case SAVED:       damage /= 2; break;
                 case SAVE_FAILED: break;
                 default:          damage = 0;
             }
             oppo_name = apply( call, oppo, "query_name" );

             if ( damage == 0 ) {
                 write("Strange, but "+oppo_name+ " seems to ignore it.\n");
                 say( "But "+oppo_name+"seems to be unharmed.\n",oppo);
                 tell_object( oppo,
                      "You really like this electrifying feeling.\n");
             }
             else 
                 tell_object(oppo,"You are zapped by the electric storm.\n");
             SHOWDAM(odam, damage);
             apply( call, oppo, "hit_by_spell", damage );
             dice--;
         }
    }
}
