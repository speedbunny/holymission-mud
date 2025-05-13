#include "/players/shadowmonk/include/defs.h"
#include "/players/shadowmonk/include/stanfeeling.h"
#include "/players/shadowmonk/include/stanadverb.h"

status   ALONE;
string  *ADVERBS;
mapping  FEELINGS;

status word_match( string adverb, string player_typed_arg ) { 
    return ( strstr( adverb, player_typed_arg ) != -1 ); 
}

status do_mapping( string *arr ) {
    if( sizeof( arr ) != 4 ) 
        return 0;
    FEELINGS += ([ arr[0] : ({ (int)arr[1], arr[2], arr[3] }) ]);
    return 1;
}

void get_feelings() {
    int     i;
    string *tarr, file;

    file = "/players/shadowmonk/inherit/feelings/" + TPN + ".adverb";
    ADVERBS = SADVERBS;
    if( file_size( file ) > 0 )
        ADVERBS += explode( read_file( file ), " " );
    file = "/players/shadowmonk/inherit/feelings/" + TPN + ".feelings";
    FEELINGS = SFEELINGS;
    if( file_size( file ) > 0 )
        map_array( explode( read_file( file ), "@@" ), "do_mapping", TO );
    for( i = sizeof( tarr = m_indices( FEELINGS ) )-1; i>=0; i-- ) {
        add_action( "feelings", tarr[i] );    
        add_action( "feelings", CAP(tarr[i]) );    
    }
    add_action( "feelhelp", "feelhelp" );    
    add_action( "adverbhelp", "adverbhelp" );    
    add_action( "addfeeling", "addfeeling" );    
    add_action( "addadverb", "addadverb" );    
    add_action( "deladverb", "deladverb" );    
    add_action( "delfeeling", "delfeeling" );
}

status feelings( string arg ) {
    int     i, sz;
    string  feel, *adverb, *temp;
    string  mstr, ustr, ostr, a, b, c;
    object  towho, *inv;

    adverb = ({});
    if( !feel )
        feel = query_verb();
    if( feel != lower_case( feel ) ) {
        ALONE = 1;
        feel=lower_case( feel );
    }
    else ALONE = 0;
    if( member_array( feel, m_indices( FEELINGS ) ) == -1 ) {
        TTP("Can't find feeling: "+feel+".");
        return 0;
    }
    if( arg != 0 && arg != "" ) {
        temp = explode( arg, " " );
        for( i=( sz=sizeof( temp ) )-1; i>=0; i-- ) {
            if( temp[i] == "") {
                sz--;
                continue;
            }
            if( !towho )
                if( ( towho = find_living( temp[i] ) ) != 0 )
                    continue;
            if( !sizeof( adverb ) )
                adverb = filter_array( ADVERBS, "word_match", TO, temp[i] );
        }
        if( !towho && !sizeof( adverb ) ) {
            TTP("Can't parse '"+arg+"'.");
            return 1;
        }
        if( sz>1 )
            if( !towho && ( i=sizeof( adverb ) ) > 0 ) {
                TTP("Can't find living.");
                return 1;
            }
            else if( towho !=0 && !( i=sizeof( adverb ) ) ) {
                TTP("Can't find adverb.");
                return 1;
            }
        if( ( sz=sizeof( adverb ) ) >= 2 ) {
            for( mstr="", i=0 ; i<sz; i++)
                mstr+=" "+adverb[i];
            TTP("Mutiple matching adverbs found: "+mstr+".");
            return 1;
        }
    }
    if( FEELINGS[feel][0] == 1 && towho != 0 ) {
                TTP( "You can only " + feel + " alone!" );
                return 1;
            }
    else if( FEELINGS[feel][0] == 2 && !towho ) {
                TTP( "You can not " + feel + " alone!" );
                return 1;
             }
    else if( ALONE == 1 && !towho ) {
                TTP( "You can not " + CAP( feel ) + " alone! You need some "+
                     "else to do something secret!" );
                return 1;
             }
    if( !sizeof( adverb ) )
        adverb += ({ "" });
    else adverb[0] = " "+adverb[0];
    if( strstr( FEELINGS[feel][1], "&" ) != -1 ) {
        temp = explode( FEELINGS[feel][1], "&" );
        if( FEELINGS[feel][0] == 0 && !towho ) 
                mstr = temp[0];
        else mstr = temp[0] + " " + temp[1];
    }
    else if( strstr( FEELINGS[feel][1], "|" ) != -1 ) {
        temp = explode( FEELINGS[feel][1], "|" );
        if( FEELINGS[feel][0] == 0 && !towho ) 
                mstr = temp[0];
        else mstr = temp[1];
    }
    else mstr = FEELINGS[feel][1];
    if( strstr( "!?.", mstr[<1..<1] ) == -1 )
        mstr+=".";
    mstr = implode( explode( mstr, "~" ), " "+feel );
    mstr = implode( explode( mstr, "@A" ), adverb[0] );
    ostr = TPCN + implode( explode( mstr, "$$" ), "es" );
    ostr = implode( explode( ostr, "$" ), "s" );
    ostr = implode( explode( ostr, "@S" ), " "+TP->QPOS );
    ostr = implode( explode( ostr, "@O" ), " "+TP->QOBJ );
    ostr = implode( explode( ostr, "@R" ), " "+TP->QPRO );
    mstr = "you" + implode( explode( mstr, "$" ), "" );
    mstr = implode( explode( mstr, "@S" ), " your" );
    mstr = implode( explode( mstr, "@O" ), " your" );
    mstr = implode( explode( mstr, "@R" ), " you" );
    if( sscanf( mstr, "%s>%s:%s<%s", ustr, a, b, c ) == 4 ) {
        mstr = implode( explode( mstr, "<>"+a+":"+b+"<>" ), " "+a );
        ostr = implode( explode( ostr, "<>"+a+":"+b+"<>" ), " "+b );
    }
    if( towho != 0 ) {
        ustr = implode( explode( ostr, "@P" ), " you" );
        ostr = implode( explode( ostr, "@P" ), " "+CAP( towho->RNAME ) );
        mstr = implode( explode( mstr, "@P" ), " "+CAP( towho->RNAME ) );
    }
    if( !towho ) 
        towho = TP;
    if( ENV( towho ) == ENV( TP ) ) {
        TOB( CAP( mstr ), TP );
        inv = all_inventory( ENV( TP ) );
        inv = del_array( inv, member_array( TP, inv ) );
        if( towho != TP ) {
            inv = del_array( inv, member_array( towho, inv ) );
            TOB( ustr, towho );
        }
        if( ALONE && towho != TP) 
            TOB( "(And you are the only one seeing it! 8*) )", towho );
        else for( i=sizeof( inv )-1; i>=0; i-- )
                 TOB( ostr, inv[i] );
    }
    else {
        TOB( "From afar, "+ustr, towho );
        TOB( "From afar, "+mstr, TP );
    }
    return 1;
}

status feelhelp() {
    int     i, sz;
    string *tarr, feels;
    feels = "All the known feelings to you are: \n\n";
    for( i = 0, sz=sizeof( tarr = 
                   sort_array( m_indices( FEELINGS ), #'> ) ); i<sz-1; i++ ) 
        feels += tarr[i]+", ";
    TOB( ( feels += tarr[sz-1]+".\n" ), TP );
    return 1;
}

status adverbhelp() {
    int     i, sz;
    string *tarr, feels;
    feels = "All the known adverbs to you are: \n\n";
    for( i = 0, sz=sizeof( tarr = sort_array( ADVERBS, #'> ) ); i<sz-1; i++ )
        feels += tarr[i]+", ";
    TOB( ( feels += tarr[sz-1]+".\n" ), TP );
    return 1;
}

status addfeeling( string arg ) {
    int    i, sz;
    string file, *feelings, format;
    file = "/players/shadowmonk/inherit/feelings/" + TPN + ".feeling";
    feelings = ({});
    if( !arg ) {
        TOB( "Give an argument you DumbAss!", TP );
        TOB( "usage> verb type format adverb", TP );
        return 1;
    }
    if( sizeof( feelings = explode( arg, " " ) ) < 4 ) {
        TOB( "Can't parse '" + arg + "'.", TP );
        return 1;
    }
    if( member_array( feelings[0], m_indices( FEELINGS ) ) != -1 ) {
        TOB( "That feeling already exists!", TP );
        return 1;
    }
    if( strstr( feelings[1], "012" ) != -1 || strlen( feelings[1] ) != 1 ) {
        TOB( "Type should be 0, 1 or 2!", TP );
        return 1;
    }
    if( member_array( feelings[(sz=sizeof(feelings))-1], ADVERBS) == -1 ){
        TOB( "The standard adverb should be an existing one!", TP );
        return 1;
    }
    format = feelings[2];
    for( i=3; i<sz-1; i++ )
        format += " " + feelings[i];
    if( file_size( file ) > 0 )
        write_file( file, "@@" );
    write_file(file,feelings[0]+" "+feelings[1]+" "+
                                format+" "+feelings[sz-1]);
    do_mapping( ({ feelings[0], feelings[1], format, feelings[sz-1] }) );
    TOB( "Added feeling '" + feelings[0] + "'.", TP );
    add_action( "feelings", feelings[0] );    
    add_action( "feelings", CAP(feelings[0]) );    
    return 1;
}

status addadverb( string arg ) {
    string file, *adverbs;
    file = "/players/shadowmonk/inherit/feelings/" + TPN + ".adverb";
    adverbs = ({});
    if( !arg ) {
        TOB( "Give an argument you DumbAss!", TP );
        return 1;
    }
    if( sizeof( adverbs = explode( arg, " " ) ) != 1 ) {
        TOB( "Can't parse '" + arg + "'.", TP );
        return 1;
    }
    if( member_array( arg, ADVERBS ) != -1 ) {
        TOB( "That adverb already exists!", TP );
        return 1;
    }
    if( file_size( file ) > 0 )
        write_file( file, " " );
    write_file( file, arg );
    adverbs += ({ arg });
    ADVERBS += ({ arg });
    TOB( "Added adverb '" + arg + "'.", TP );
    return 1;
}

status delfeeling( string arg ) {
    int    i, sz;
    string file, *feelings, *fnames;

    file = "/players/shadowmonk/inherit/feelings/" + TPN + ".feeling";
    if( file_size( file ) <= 0 ) {
        TOB( "There are no deletable feelings for you!\n", TP );
        return 1;
    }
    feelings = explode( read_file( file ), "@@" );
    for( i = 0, sz=sizeof( feelings ), fnames = ({}); i<sz-1; i++ ) 
         fnames += ({ explode( feelings[i], " " )[0] });
    if( !arg ) {
        arg = "All the deletable feelings for you are: \n\n";
        for( i = 0, sz=sizeof( fnames ); i<sz-1; i++ ) 
             arg += fnames[i];
        TOB( ( arg + fnames[sz-1] +" "+sz+".\n" ), TP );
        return 1;
    }
    if( i = member_array( arg, fnames ) == -1 ) {
        TOB( "That feeling does not exists!", TP );
        return 1;
    }
    FEELINGS = m_delete( FEELINGS, arg );
    feelings = del_array(feelings, i );
    if( file_size( file ) > 0 )
        rm( file );
    write_file( file, implode( feelings, "@@" ) );
    TOB( "Deleted feeling '" + arg + "'.", TP );
    return 1;
}

status deladverb( string arg ) {
    int     i, sz;
    string file, *adverbs;

    file = "/players/shadowmonk/inherit/feelings/" + TPN + ".adverb";
    if( file_size( file ) <= 0 ) {
        TOB( "There are no deletable adverbs for you!\n", TP );
        return 1;
    }
    adverbs = explode( read_file( file ), " " );
    if( !arg ) {
        arg = "All the deletable adverbs for you are: \n\n";
        for( i = 0, sz=sizeof( adverbs ); i<sz-1; i++ ) 
             arg += adverbs[i]+", ";
        TOB( ( arg + adverbs[sz-1]+" " + sz + ".\n" ), TP );
        return 1;
    }
    if( i = member_array( arg, adverbs ) == -1 ) {
        TOB( "That adverb does not exists!", TP );
        return 1;
    }
    adverbs = del_array( adverbs, i );
    ADVERBS = del_array( ADVERBS, member_array( arg, ADVERBS ) );
    if( file_size( file ) > 0 )
        rm( file );
    write_file( file, implode( adverbs, " " ) );
    TOB( "Deleted adverb '" + arg + "'.", TP );
    return 1;
}
