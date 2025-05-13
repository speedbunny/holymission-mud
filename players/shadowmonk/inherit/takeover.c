inherit "/players/shadowmonk/inherit/path_daemon";
#include "/players/shadowmonk/include/defs.h"

#define ALLOWED ({ "say", "tell", "who", "score", "look", "rwhere", \
                   "alias", "l","exa", "chat", "chat/", "release" })

#define prison  HOME+"area1/tower/t001"

int     curhp;
object  pl, *players;
status  init, captured, block, last;
string *prisonpath, file;

status id(string arg) {
    return arg == "takeover";
}
status drop(string arg) { 
    return 1; 
}
status get(string arg) {
    return 0;
}
int query_weight() {
    return 0;
}

void init() {
    if( !living( ENV() ) )
        return;
    if( !init ) {
        init = 1;
        pl = ENV();
        captured = 0;
        prisonpath = ({});
        add_path( ( file = HOME+"etc/prisonpath."+pl->RNAME ) );
    }
    add_action( "_allowed", "", 1 );
    if( pl->query_immortal() ) 
        add_action( "_release", "release" );
    set_heart_beat(1);
}

void remove() {
    destruct( TO );
}

status _release() {
    remove();
    return 1;
}

status _allowed(string arg) {
    if( ENV() != pl || captured == 0 || member_array( query_verb(), ALLOWED ) != -1 ) 
        return 0;
    TTP("The guards hold you nice and tight, and there is nothing you can do!" );
    return 1;
}

status fighting() {
    int     i;
    object *ob;
    ob = all_inventory( ENV( pl ) );
    for( i=sizeof(ob)-1; i>=0; i-- )
        if( living( ob[i] ) && ob[i]->query_attack() )
            return 1;
    return 0;
}

status guards() {
    int     i;
    object *ob;
    ob = all_inventory( ENV( pl ) );
    for( i=sizeof(ob)-1; i>=0; i-- )
        if( living( ob[i] ) )
            if( ob[i]->RNAME == "guard" )
                return 1;
    return 0;
}

status check_last() {
    int     i, nmb, tnmb;
    object *ob, tob;
    string  name;
    nmb = 0;
    ob = all_inventory( ENV( pl ) );
    for( i=sizeof(ob)-1, players=({}); i>=0; i-- )
        if( living( ob[i] ) )
            if( ( tob=present( "takeover", ob[i] ) ) )
                if( sscanf( (string)tob+"#", "%s#%d#", name, tnmb ) == 2 ) {
                    players += ({ ENV( tob ) });
                    if( tnmb > nmb )
                        nmb=tnmb;
                }
    sscanf( (string)TO+"#", "%s#%d#", name, tnmb );
    if( tnmb == nmb )
        return 1;
    return 0;
}

status perform_noattack() {
    object *ob;
    int i;
    ob = all_inventory( ENV( pl ) );
    for( i=sizeof(ob)-1; i>=0; i-- )
        if( living( ob[i] ) && pl == ob[i]->query_attack() ) {
            ob[i]->stop_fight();
            ob[i]->stop_fight();
            ob[i]->stop_hunter(1);
        }
// if pl is getting attacked by something other then guards.. the guards should attack those
// maybe by calling a function in guard.c do_attack( object player )
    pl->stop_fight();
    TELL( pl, "The guards surround you, and you give up the fight.",
              "The guards surround "+ CNM( pl ) +", and "+pl->QPRO+" gives up the fight." );
    return 1;
}

void make_prison_path() {
    add_pathvars( ({ file_name( ENV( pl ) ), prison, 0, 20, ({}), 
                     ({ HOME+"area1/road/r002", HOME+"area1/road/r012" }),
    }) );
}

void to_prison() {
    int     i, j, index;
    string *exits;
    if( block ) {
        call_out( "await_path", 5, ({ 10, 0, 0 }) );
        return;
    }
    if( pl && sizeof( prisonpath ) ) {
        exits = call_other( ENV( pl ), "query_dest_dirs" );
        for( i=sizeof( exits )-2, index=-1; i>=0; i-=2 )
            if( ( index = member_array( exits[i], prisonpath ) ) >= 0 )
                break;
        if( index >= 0 ) {
            for( j=sizeof(players)-1; j>=0; j-- ) {
                TELL( players[j], "The guards lead you "+exits[i+1]+" towards the prison.",
                      "Some guards lead "+CNM(players[j])+" "+exits[i+1]+" to the prison." );
                MOVE( players[j], prisonpath[index] );
                MOVE( TO, players[j] );
                command( "look", players[j] );
                TELL( players[j], "", "Some guards come in, leading "+CNM(players[j])+
                                " to the prison.");
            }
            prisonpath = del_array( prisonpath, index );
        }
        else prisonpath = ({});
        call_out( "to_prison", 4 );
        return;
    }
    if( ENV( pl ) != find_object( prison ) )
        for( i=sizeof(players)-1; i>=0; i-- ) {
            TELL( players[i], "The guards throw you in a cell a chain you to the wall.",
                            "Some guards lead "+CNM(players[i])+" into the cell, and "+
                            "chain "+players[i]->QPRO+"." );
            MOVE( players[i], prison );
            command( "look", players[i] );
        }
}

void await_path( int *data ) {
    int i, sz, times, storylevel;
    string tstr, ttstr;
    times = data[0];
    storylevel = data[1];
    if( !guards() )
        return;
    if( block || !check_last() ) {
        call_out( "await_path", 5, ({ times, 0 }) );
        return;
    }
    if( times < 0 ) {
        to_prison();
        return;
    }
    if( captured == 2 && ( sscanf( file_name( ENV( pl ) ), 
                                        "%sowmonk/area1/villa%s", tstr, ttstr ) )== 2 ) {
        if( file_size( file ) > 0 && storylevel > 4 ) {
            prisonpath = explode( read_file( file ), " " );
            if( ( times = member_array( file_name( ENV( pl ) ), prisonpath ) ) != -1 )
                prisonpath = del_array( prisonpath, times );
            to_prison();
            return;
        }
        tstr = "The captain of the guard says: ";
        if( sizeof( players ) > 1 )
            switch( storylevel ) {
                case 0 :
                    TRM( tstr+"I see we can resume after this short delay... ", ENV(pl) );
                    break;
                case 1 : 
                    TRMN( tstr, ENV(pl) );
                    for( i=2, sz=sizeof(players); i<sz; i++ )
                        TRMN( CNM(FP(players[i]))+", ", ENV( pl ) );
                    TRM( CNM(players[0])+" and "+CNM(players[1])+" have been "+
                         "captured for the crimes commited to the people of this "+
                         "community.", ENV(pl) );
                    break;
                case 2 :
                    TRM( tstr+"For these crimes they will be imprisoned.", ENV(pl) );
                    break;
                case 3 :
                    TRM( tstr+"They will remain imprisoned until the people of this "+
                         "village find them redeemed.", ENV(pl) );
                    break;
                case 4 :
                    TRM( tstr+"We will now escort them to the prison!", ENV(pl) );
                    break;
            }
        else 
            switch( storylevel ) {
                case 0 :
                    TRM( tstr+"I see we can resume after this short delay... ", ENV(pl) );
                    break;
                case 1 : 
                    TRM( tstr+CNM(pl)+", you have been captured for the "+
                         "crimes commited to the people of this community.", ENV(pl) );
                    break;
                case 2 :
                    TRM( tstr+"For these crimes you will be imprisoned.", ENV(pl) );
                    break;
                case 3 :
                    TRM( tstr+"You will remain imprisoned until the people of this "+
                         "village find you redeemed.", ENV(pl) );
                    break;
                case 4 :
                    TRM( tstr+"We will now escort you to the prison!", ENV(pl) );
                    break;
            }
    }
    call_out( "await_path", 5, ({ times-1, storylevel+1 }) );
}

void heart_beat() {
    status hp;
    object ob;
    if( ENV( pl ) == find_object( prison ) || ENV() != pl || !living( ENV() ) ||
        ( sscanf( file_name( ENV( pl ) ), "%sowmonk/area1%s", tstr, ttstr ) )!= 2 ) {
        remove();
        return;
    }
//  Have to clone a captain of the guard
//  also have to do something .. like first time just get kicked out of village... if not a 
//  kill but only hurt.  that means differetn path and different await_path
    if( ( hp=pl->query_hp() ) < ( pl->query_max_hp()/2 ) && captured == 0 ) {
        captured = 1; // really captured now.
        curhp = hp;
        make_prison_path();
    }
    if( !fighting() && captured == 1 ) {
        captured = 2; // lets go read the 'rights'.
        call_out( "await_path", 1, ({ 10, 1 }) );
        return;
    }
    if( captured > 0 ) {
        if( pl->query_attack() )
            perform_noattack();
        if( ( hp = pl->HP ) < curhp )
            pl->heal_self( curhp - hp );
        if( pl->query_immortal() ) 
            TOB( "Type 'release' to be released!", pl );
    }
    if( !guards() ) {
        TOB( "There are no guards, and you are a free though wanted man now!", pl );
        remove();
        return;
    }
    if( fighting() && captured > 0 ) 
        block == 1;
    else block == 0;
}
