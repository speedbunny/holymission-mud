inherit "/spells/spell";
#include "/spells/spell.h"

void reset(int arg) {

    ::reset(arg);
    if(arg) return;
    set_name("Lightning Bolt");
    set_syntax("cast 'free lightning' [opponent]");
    set_kind( AGGRESSIVE );
    set_save_vs( ELECTRICITY );
    set_save_vs_info( "for three-quarter damage" );
    set_damage_info( "LVLd6 + 50");
    set_cost( 50 );
    set_speed( 4 );
    set_guild_allowed( 4, 10 );
    set_player_help(
        "Concentrating the energies of the force through your\n" +
        "hands, and building it up a bank of energy. Upon its release\n" +
        "a bolt of lightning streaks out to strike the target.\n");
}

void release(string arg, int act_skill, int max_skill) {

    object  att;
    int     d, dam;
    string  att_name, tp_name;

    att = check_target(arg);
    if(!att) return;
    if( !valid_living(att) ) return;

    d = TP->query_level();

    if(check_success(act_skill,max_skill)) {
        switch(att->do_save(Skind,Ssave,0,0,this_object())) {
            case IMMUNE:        dam = 20; break;
            case SAVED:         dam = (roll_dice(d,6,0)/2) + 25; break;
            case SAVE_FAILED:   dam = (roll_dice(d,6,0)) + 50; break;
            default:            dam = 20;
        }
        att_name = att->query_name();
        tp_name  = TPN;

        printf("You stretch forth your hands and release an energy bolt.\n");
        say(tp_name+" stretches out hands that release a stream of lightning\n"+
                "striking "+att_name+".\n",TP,att);
        tell_object(att,"You are hit by a stream of lightning from "
                +tp_name+".\n");

        att->hit_by_spell(dam);
    }
}

