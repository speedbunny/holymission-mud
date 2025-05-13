#include "/players/tatsuo/guild/ndef.h"

/* --- Karate the opponent ------------------------------------------------------ */
main (arg)
{
    object who;
    string att_obj_name;
    int    damage;

        
    if ( attack_blocked ) {
        write( "Have patience, you are just preparing for an attack.\n" );
        return( 1 );
    }

    if ( attackCon < MAX_ATTACK_CON/4 ) {
        write( "You are too exhausted to karate somebody.\n" );
        return( 1 );
    }
    if ( query_to_heavy() ) {
        write( "You feel to heavy to karate somebody.\n" );
        return( 1 );
    }

    if ( check_armour() ) {
        write( "Your unusual armour hinders you to karate somebody.\n" );
        return( 1 );

    }

    if ( !arg ) {
        if ( !MY_ATTACKER || !(living(MY_ATTACKER)) ) {
            write( "Karate whom ?\n" );
            return( 1 );
        }
    }

    if ( !attack_blocked && attack_func != "_karate" ) {        /* atta in this hb ? */
        attack_func = "_karate";
        attack_arg = arg;
        attack_blocked = TRUE;
        return( 1 );
    }

    attackCon -= KARATE_COST;

    who = MY_ATTACKER;
    if ( !who ) {
        who = present( arg, environment( TP ) );
        if ( !who || !living(who) ) {
            write( "You only can karate somebody, who you can see and who is alive.\n" );
            return( 1 );
        }
    }
    if ( !living( who ) || who->query_ghost() )
        return( 1 );

    if ( random( 100 ) < actKarateSkill ) {                 /* successfull */
        if ( who->query_level() < ALL_STAT_AV )
            advance_skill( TP, KARATE_SKILL, 1, 100 );
        else
            advance_skill( TP, KARATE_SKILL, 1, 50 );
        damage = random( KARATE_HIT*4 ) + 5;
    }
    else {
        advance_skill( TP, KARATE_SKILL, 1, 20 );
        damage = 0;
    }

    att_obj_name = who->query_name();
    damage = who->hit_player( damage );
    CalcKarateDam( who, att_obj_name, damage );

    return( 1 );
}


