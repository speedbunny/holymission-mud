
/* ################################################################
   #								  #
   #    		Mage Fireball                             #
   #                                          		          #
   ###############################################(C) Llort######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
   if(lev<10) return 3;
   if(lev<20) return 2;
   return 1;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "fireball" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'fireball'" );
   set_save_vs( FIRE );
   set_save_vs_info( "for half damage" );
   set_damage_info( "level*d30 up to 20d30" );
   set_guild_allowed( 5, 9 );
   set_cost( 80 );
   set_player_help(
"This spell will bring a magical explosion into existence which inflicts\n"+
"fire damage on living beings within its area of effect.");
}

void release_spell( string arg, int act_skill, int max_skill )
{
    object *inv, oppo;
    int    dice,i,j,sz,max,damage, odam;
    string oppo_name;

    if ( !check_success( act_skill, max_skill ) ) return;

    inv = all_inventory( environment(TP) ) - TP->grmems_in_room();
    dice = ( TPL > 20 ? 20 : TPL); 

    say("A red hot globe of fire explodes in the area!\n");
    write("A red hot globe of fire explodes in the area!\n");

    sz=sizeof( inv );
    max = TPL/2;

    for ( i = j = 0; i < sz && j < max; i++ )
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
                      "The heat of the explosion warms your body.\n");
             }
             else 
                 tell_object( oppo, "You are burned by the explosion!\n");
             SHOWDAM(odam, damage);
             apply( call, oppo, "hit_by_spell", damage ); 
             j++;
         }
    }
}
