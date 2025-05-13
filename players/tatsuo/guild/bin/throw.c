#include "/players/tatsuo/guild/ndef.h"
#include "/players/tatsuo/guild/move_blocked.h"
#include "/players/tatsuo/guild/nmess.h"

main(arg)
{

    object ob, who, throw_dest, blocker;
    string what, swho, arr;
    int    i, damage, transRet;                              /* don-t change i !!! */

   if(environment(TP)->query_property("no_fight")) 
   return printf("This is not a place of violence.\n"),1;

  if(TPL < 10) return 0;
    if ( !arg )
        return;

    ob = who = 0;

       
    if ( this_player()->query_wielded_weapon() ) {
        write( "You don't have a hand free to throw something !!!\n" );
        return( 1 );
    }

    if ( TP->query_sp() < THROW_COST ) {
        write( "You are too exhausted to throw things.\n" );
        return( 1 );
    }

    
    arr = explode( arg, " " );
    if ( !sizeof( arr ) )
        return;

    i = 0;
    what = "";
    while( (i < sizeof(arr)) && (arr[i] != "at") ) {            /* get the what   */
        if ( arr[i] != "the" )
            what = what + arr[i] + " ";
        i++;
    }
    if ( strlen(what) > 0 )
        what = extract( what, 0, strlen( what ) - 2 );             /* remove blank */

    ob = present( what, this_player() );                      /* is it present ?  */
    if ( !ob ) {
        write( "You only can throw things you have.\n" );
        return( 1 );
    }

    swho = "";
    i++;
    while ( i < sizeof(arr)) {                                /* get the opponent */
        if ( arr[i] != "the" )
            swho = swho + arr[i] + " ";
        i++;
    }
    if ( strlen(swho) > 0 ) {
        swho = explode( swho, " " )[0];                            /* remove blank  */
        who = present( swho, environment(this_player()) );         /* is opponent present */
        if ( !who || who->query_ghost() ) {
            write( "You can't throw items at things, which aren't present.\n" );
            return( 1 );
        }
    }

    /* ----- and now throw it ----------------------------------- */
    if ( !who ) {
        if ( MY_ATTACKER && living( MY_ATTACKER ) )
            who = MY_ATTACKER;
    }

    if ( who ) {
        if ( living( who ) ) {
           
            if ( ob->query_npowder_throw() ) {                      /* ninja-powder      */
                ob->throw_powder( who );                             /* let the powder do it*/
                return( 1 );
            }
            else if ( ob->query_weapon() ) {                      /* weapon - throw    */
                if ( ob->query_info() == "ninja_weapon" && ob->query_can_throw() ) {

                    damage = ob->query_nin_dam() * THROW_DAM;
                    damage = damage / 2 + random( damage / 2 + 1 );
                }
                else
                    damage = random( ob->query_weight() + ob->weapon_class() ) ;

                throw_dest = who;
                blocker = 0;
            } 
            else {                                                  /* no weapon - throw */
                damage = random( ob->query_weight() );
                throw_dest = environment( this_player() );
                blocker = who;
            }

            if ( (random(100) >= THROWSKILL) ) {                 /* too unskillfull ? */                             /* miss              */
             damage = 0;
            }

            transRet = move_blocked( ob, throw_dest, blocker );     /* transfer object   */
            if ( transRet == 2 || transRet == 3 || transRet < 0 ) {
                write( "Somehow you don't manage it to throw this item.\n" );
                return( 1 );
            }
            else if ( transRet )
                transfer( ob, environment( this_player() ) );

            TP->restore_spell_points(- THROW_COST );

           
            CalcThrowDam( who, who->query_name(), ob, damage );

            if ( damage > 0 ) {         
                damage = who->hit_player( damage );
            }
            else {
                who->attacked_by( TP );
            }
        }
        else {
            if ( transfer( ob, environment(this_player()) ) ) {
                write( "Somehow you don't manage it to throw this item.\n" );
                return( 1 );
            }
            tell_object(this_player(),
              "You throw a " + ob->query_name() + " at " + swho + ".\n" );
            say( TPN + " throws a " + ob->query_name() + " at " + swho + ".\n" );
                    }
    }
    else {
        if ( transfer( ob, environment(this_player()) ) ) {
            write( "Somehow you don't manage it to throw this item.\n" );
            return( 1 );
        }
        write( "You throw the " + ob->query_name() + " high up in the air.\n" );
        say( TPN + " throws a " + ob->query_name() + " high up in the air.\n" );
        
    }

    return( 1 );
}

