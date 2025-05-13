#include "/players/tatsuo/guild/nmess.h"
#include "/players/tatsuo/guild/ndef.h"

main(arg)
{
    object who;
    string att_obj_name;
    int    damage;

   if(TPL < 3 ) return printf("You have not mastered the art of karate as of yet.\n"),1;


  if(present("heart_beat",TP)) return printf("You are just preparing the next attack.\n"),1;
        

    if ( TP->query_sp()< KARATE_COST ) {
        write( "You are too exhausted to use karate skills.\n" );
        return( 1 );
    }
    
           if ( !arg ) {
        if ( !MY_ATTACKER || !(living(MY_ATTACKER)) ) {
            write( "Karate whom ?\n" );
            return( 1 );
        }
    }

        
    TP->restore_spell_points(- KARATE_COST);
   move_object(clone_object("/players/tatsuo/guild/heart_beat"),TP);

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

   if( random(85) < KARATESKILL ) {                /* successfull */
       damage = random( KARATE_HIT*4 ) + 5;
    }
    else {
                damage = 0;
    }

    att_obj_name = who->query_name();
    damage = who->hit_player( damage );
    CalcKarateDam( who, att_obj_name, damage );

    return( 1 );
}



