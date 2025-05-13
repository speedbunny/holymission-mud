/*
 * druid spell firestorm
 * (c) sourcer
 * The spell is similar to the mage spell fireball only the damage
 * is not that great at low levels, but increasing till level 30
 * and so the damage at lv 30 is the same as fireball
 */

inherit "/spells/spell";
#include "/spells/spell.h"


void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "firestorm" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'firestorm'" );
   set_save_vs( FIRE );
   set_save_vs_info( "for half damage" );
   set_damage_info( "level*d20 " );
   set_guild_allowed( 2, 13 );
   set_cost( 80 );
   set_speed( 2 );
   set_player_help(
"The spell calls forth the element of fire which sweeps through\n"+
"the room and burns everything in it.\n");
}

void release_spell( string arg, int act_skill, int max_skill )
{
    object *inv, oppo;
    int    dice,i,j,sz,max,damage, odam;
    string oppo_name;

    if ( !check_success( act_skill, max_skill ) ) return;

    inv = all_inventory( environment(TP) ) - TP->grmems_in_room();
    dice =  TPL ; 

	write("\nSuddenly the sky turns red and everything is on fire.\n");
	say("\nSuddenly the sky turns red and everything is on fire.\n");

    sz=sizeof( inv );
    max = TPL/2;

    for ( i = j = 0; i < sz && j < max; i++ )
    {
        if ( living( inv[i] ) )
        {   
             oppo=inv[i];
             odam = damage = roll_dice(dice,30,0);

             switch( oppo->do_save(Skind,Ssave,0,0,this_object()))
             {
                 case IMMUNE:      damage = 0; break;
                 case SAVED:       damage /= 2; break;
                 case SAVE_FAILED: break;
                 default:          damage = 0;
             }
             oppo_name = oppo->query_name( );

             if ( damage == 0 ) {
                 write("Strange, but "+oppo_name+ " seems to ignore it.\n");
                 say( "But "+oppo_name+"seems to be unharmed.\n",oppo);
                 tell_object( oppo,
                      "The heat of the fire storm warms your body.\n");
             }
             else 
                 tell_object( oppo, "You are burned by the fire storm!\n");
             SHOWDAM(odam, damage);
             WINFO("Damage inflicted on <"+oppo_name+">: "+damage);
             oppo->hit_by_spell(damage ); 
             j++;
         }
    }
}
