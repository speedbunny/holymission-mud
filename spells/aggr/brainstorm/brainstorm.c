inherit "/spells/spell";
#include "/spells/spell.h"

void reset(int arg) {

    ::reset(arg);
    if(arg) return;
    set_name("Brainstorm");
    set_syntax("cast 'brainstorm' [opponent]");
    set_kind( AGGRESSIVE );
    set_save_vs( MINDEFFECTIVE );
    set_save_vs_info( "to negate" );
    set_damage_info( "Reduced to please some people.");
    set_cost( 30 );
    set_speed( NEXT_HB );
    set_guild_allowed( 4, 20 );
    set_player_help(
        "By concentrating the powers of the force into a mighty blow\n" +
        "to the mind of you opponent, you may cause them to believe\n" +
        "that they have suffered a mortal blow to the extent that thier\n" +
        "brain shuts down and actual death occurs.");
}

void release(string arg, int act_skill, int max_skill) {

    object  att;
    int     dam;
    string  att_name, tp_name;

    att = check_target(arg);
    if(!att) return;
    if( !valid_living(att) ) return;

    if((att->query_hp()*100)/(att->query_max_hp()) > 40) {
        write("Your opponent is too strong to effect.\n");
        return;
    }

    if(check_success(act_skill,max_skill)) {
        switch(att->do_save(Skind,Ssave,0,0,this_object())) {
            case IMMUNE:        dam = 500; break;
            case SAVED:         dam = 0; break;
            case SAVE_FAILED:   dam = 10000; break;
            default:            dam = 500;
        }
        att_name = att->query_name();
        tp_name  = TPN;

        printf("You concentrate on you oppenent.\n");
        say(tp_name+" stares into "+att_name+"'s eyes.\n",
                TP,att);
        tell_object(att,"You feel strange.\n");

        att->hit_by_spell(dam);
    }
}

