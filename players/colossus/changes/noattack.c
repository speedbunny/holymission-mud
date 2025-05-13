inherit "/spells/spell";
#include "/spells/spell.h"

reset(int arg) {

    ::reset(arg);
    if(arg) return;
    set_name("noattack");
    set_syntax("cast 'noattack'");
    set_kind( NON_AGGRESSIVE );
    set_save_vs( MINDEFFECTIVE );
    set_save_vs_info( "to negate" );
    set_damage_info( 0 );
    set_cost( 0 );
    set_speed( NEXT_HB );
    set_guild_allowed( 4, 1 );
    set_player_help(
        "Place a calming influence on all those in the room.");
}

release_spell(arg, act_skill, max_skill) {

    object  att,*inv;
    int     d, i, dam;
    string  att_name, tp_name;

    att = check_target(arg);
    if(!att) return;

    inv = all_inventory(environment(TP));
    d = sizeof(inv);

    if(check_success(act_skill,max_skill)) {
      for ( i=1; i<d; i++) {
        att = inv[i];
        if(!valid_living(att)) continue;
        switch(att->do_save(Skind,Ssave,0,0,this_object())) {
            case IMMUNE:        dam = 0; break;
            case SAVED:         dam = 0; break;
            case SAVE_FAILED:   dam = 1; break;
            default:            dam = 1;
        }
        if ( dam ) {
            att->stop_fight();
            att->stop_fight();
            att->stop_hunter(1);
            tell_object(att,"You feel peaceful.\n");
        }
      }
      printf("You begin to concentrate on serenity.\n");
    }
}
