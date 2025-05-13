//  Priest Guild, by Tatsuo
inherit "obj/armour";


#include "/players/tatsuo/guild2/pdefs.h"


#define BIN "/players/tatsuo/guild2/bin/" 
 
status alreadyDone;                                  /* already done the init?*/

/* --- the id of the guild soul ---------------------------------------------- */

status id(string str)
{
    return( str=="priest_amulet" || str=="priest_object" || str == "amulet" || 
      str == "guild_object" );
}

/* --- can-t drop and can get it ---------------------------------------------- */

int get()
 
{
    return( 1 );
}

status drop(status silent)
{
    if(!silent)
        tell_object(this_player(), "You have to leave the guild for that.\n" );
    return( 1 );
}




int _filter(string str)
{
    string theverb;

    theverb = (string)query_verb();

    if(theverb[0] == 39 || theverb[0] == 46) return 0;
    if(theverb[strlen(theverb)-1] == '.') return 0;

    if(theverb == "quit" || theverb == "dest") return 0;
    
    if(file_size(BIN + theverb + ".c") > 0)
        if ((BIN + theverb)->main(str))
            return 1;
        else return 0;
        
    if(theverb == "priest/" || theverb == "p/")
    {
        (BIN+"priest")->main(str);
        return 1;
    }
    
    return 0;
}
 
/* --- the void reset ------------------------------------------------------- */

void reset(int arg)
{
    ::reset(arg);
    if(arg)
            return;

    set_type( "guild" );
    set_name( "symbol" );
    set_alias( "priest_soul" );
    set_short( symbol_id(); );
    set_long("It is the holy symbol of "+TPREL+"\n");
    set_weight(0);
}

/* --- the init ------------------------------------------------------------ */

void init( )
{
    int mod;
    object shadow;

    ::init();
    if( !TP || TP!=environment()) return;

    
       add_action("_filter","",1);

    if ( alreadyDone )                             /* if already init, abort */
        return;

   
    if ( TP->query_real_name() == "tatsuo" ) {
        set_short( "The Djed Pillar of Osiris" );
        set_long( "A small amulet in the shape of a pillar, The Holy Symbol of Osiris.\n" );
    }
    else if (TPREL == "illuvatar") {
        set_short("The holy amulet of Illuvatar");
        set_long("A golden amulet in the shape of a triangle.\n");
    }
    else if ( TPREL == "amaterasu" ) {
        set_short( "A white amulet of Amaterasu" );
        set_long( "A white amulet in the shape of a sun disk.\n" );
    }
    else if ( TPREL == "crom"  ) {
        set_short( "A minature black sword on a necklace" );
        set_long( "A black minature sword, the Symbol of Crom\n");   
    }
    
        set_size( TP->query_size() );
    if ( !worn && !TP->query_wizard() )
        command( "wear amulet",TP );  

    
       }

    alreadyDone = TRUE;

   }


/* --- leaving the guild -------------------------------------------------- */
void guild_changes()
{
   
         
    write( "Well, then leave the ninjas !!!\n" );
    destruct(this_object());

}

/* ----- the helpdir of the preists ---------------------------------------- */
_help(str)
{
    string path;

    if ( !str )
        return;

    if ( str== "level" || str == "levels" ) {
        GUILD_MASTER->list_levels( GUILD_MASTER->query_number(GUILD), 0 );
        return( 1 );
    }

    else if ( str == "legendlevels" || str == "legendlevel" ) {
        GUILD_MASTER->list_legend_levels( 8, 0 );
        return( 1 );
    }

   
    path = "/players/tatsuo/guild2/helpdir/"+str;
    if ( file_size(path) > 0 ) {
        cat( path );
        return( 1 );
    }

    return( 0 );
}

 

