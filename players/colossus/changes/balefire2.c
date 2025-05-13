inherit "/spells/spell";
#include "/spells/spell.h"

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("Balefire");
    set_syntax("cast 'balefire' [opponent]");
    set_kind( AGGRESSIVE );
    set_save_vs( DEATHMAGIC );
    set_save_vs_info( "for 3/4 damage" );
    set_damage_info( 85 + random(LVL/10 ) )
    set_cost( 50 + LVL/10 );
    set_speed ( INSTANT );
    set_guild_allowed( 10, 13 );
    set_player_help(
    );
}

void release(arg, act_skill, max_skill) {
    object attacker;
    int d, dam;
    string attacker_name, tp_name;
    att = check_target(arg);
    if(!att) return;
    if(!valid_living(att) ) return;
    if(check_success(act_skill,max_skill)) {
	switch(att->do_save(Skind,Ssave,0,0,this_object())) {
	case IMMUNE:        dam = 0; break;
	case SAVED:         dam = 3*(roll_dice(d,4,0)/4); break;
	case SAVE_FILED     dam = roll_dice(d,4,0); break;
	default:            dam = 10;
	}
	attacker_name = attacker->query_name();
	tp_name = TP->query_name();
    }
}
