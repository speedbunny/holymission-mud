inherit "/spells/spell";
#include "/spells/spell.h"

void reset(int arg) {

    ::reset(arg);
    if(arg) return;
    set_name("Energy Bolt");
    set_syntax("cast 'bolt' [opponent]");
    set_kind( AGGRESSIVE );
    set_save_vs( ELECTRICITY );
    set_save_vs_info( "for half damage" );
    set_damage_info( "LVLd4" );
    set_cost( 30 );
    set_speed( INSTANT );
    set_guild_allowed( 4, 1 );
    set_player_help(
        "Concentrating the energies of the force through your\n" +
        "hands, and projecting it in a physical manifestation of\n" +
        "electricity at your opponent, this bolt will cause damage\n" +
        "related to your level of mastery of the force.");
}

void release(string arg, int act_skill, int max_skill) {

    object  att;
    int     d, dam, sprest;
    string  att_name, tp_name;

    att = check_target(arg);
    if(!att) return;
    if( !valid_living(att) ) return;

    d = TPL;

    if(check_success(act_skill,max_skill)) {
        switch(att->do_save(Skind,Ssave,0,0,this_object())) {
            case IMMUNE:        dam = 0; break;
            case SAVED:         dam = roll_dice(d,4,0)/2; break;
            case SAVE_FAILED:   dam = roll_dice(d,4,0); break;
            default:            dam = 5;
        }
        att_name = att->query_name();
        tp_name  = TP->query_name();

        printf("You stretch forth your hands and release an energy bolt.\n");
        say(tp_name+" stretches out hands that release a bolt of energy.\n",
                TP,att);
        tell_object(att,"You are hit by a force bolt from "+tp_name+".\n");
        if(!dam) {
            printf("Your opponent shrugs off the attack!\n");
            tell_object(att,"You suffer only minor burns from the bolt.\n");
        }

        sprest = 29 - (TPL);
        if(sprest > 20 || sprest < 0) sprest = 20;
        TP->restore_spell_points(sprest);
        att->hit_by_spell(dam);
    }
}

