//  NINJA GUILD OF HOLY MISSION

// Original Concept -  Patience
// Guild Master - Tatsuo
// Past Active GMs - Dice, Patience
// Current Access - Wilbie, Bobo, Tatsuo
// Guild restored by - Tatsuo, Wilbie, Darastor, Bobo, Tinman
//  PLEASE NOTE ANY CHANGES TO SOUL BELOW THIS LINE



inherit "obj/armour";


#include "/players/tatsuo/guild/move_blocked.h"  /* used at throwing   */
#include "/players/tatsuo/guild/bin/camouflage.c"

#include "/players/tatsuo/guild/ndef.h"      /* the global defines      */
#include "/players/tatsuo/guild/ncommu.h"    /* communicate-functions   */

#define SHADOW "/players/tatsuo/guild/ninja_shadow"
#define BIN "/players/tatsuo/guild/bin/"

/* ----- global vars -------------------------------------------------------- */

object myself;                                       /* the owner of the soul */
status alreadyDone;                                  /* already done the init?*/

/* --- the id of the guild soul ---------------------------------------------- */

status id(string str)
{
    return( str=="ninja_soul" || str=="ninjasoul" || str == "robe" || 
      str == "ninja-robe" );
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

status query_ninja_wear()
{
    return 1;
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
        
    if(theverb == "ninja/" || theverb == "n/")
    {
      (BIN+"nemote")->main(str);
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
    set_name( "robe" );
    set_alias( "ninja_soul" );
    set_short( "A black ninja-robe" );
    set_long("A black ninja-robe, which covers all his body,\n" +
      "except of his brown eyes.\n");
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

    myself = TP;

    if ( myself->query_real_name() == "tatsuo" ) {
        set_short( "The Golden Ninja Robe of the Ninja Shogun" );
        set_long( "The Golden Ninja Robe of the Ninja Shogun, which covers all\n" +
          "except his brown eyes.\n" );
    }
    else if (myself -> query_real_name() == "wilbie") {
        set_short("A purple ninja robe with a Yak patch");
        set_long("A deep purple ninja robe, with a neat little\n" +
          "yak patch on the left breast.\n");
    }
    
     else if (myself -> query_real_name() == "darastor") {
        set_short("A bright yellow ninja robe");
        set_long("A bright yellow ninja robe, which covers all his body,\n" +
          "except his green-grey eyes.\n");
    }
    else if ( myself->query_immortal() ) {
        set_short( "A white ninja-robe" );
        set_long( "A white ninja-robe, which covers all the body,\n" +
          "except of the blue eyes.\n" );
    }
    else if ( myself->query_female() ) {
        set_short( "A black-reddish ninja-robe" );
        set_long( "A black-reddish ninja-robe, which covers all her body,\n" +
          "except of her blue eyes.\n" );
    }

    if (!(myself -> ninja_shadow()))

    {
        if(this_player() -> query_real_name() == "tatsuo")
            write("Starting shadow.\n");

        shadow = clone_object(SHADOW);
        shadow -> start_shadow(myself,0,"ninja_shadow");
    }

    set_size( TP->query_size() );
    if ( !worn && !TP->query_wizard() )
        command( "wear ninja-robe",TP );  

mod=TP->query_level()/25;
TP->set_n_ac( (TP->query_dex()/5)+TP->query_level()/(5+(int)mod) );

    if ( !TP->query_immortal() ) {
        TP->setmmin( "jumps in from nowhere" );
        TP->setmmout( "vanishes" );
        TP->setmin("sneaks");
        TP->setmout("sneaks");
    }

    alreadyDone = TRUE;

    TP->set_language_skill(1,100);              // remove this again
    TP->set_infravision();
}


/* --- leaving the guild -------------------------------------------------- */
void guild_changes()
{
    if ( !TP->query_immortal() ) {
        TP->setmmin( "arrives in a puff of smoke" );
        TP->setmmout( "disappears in a puff of smoke" );
    }


    if (myself -> ninja_shadow())
    {
        if (myself -> query_immortal())
            tell_object(myself, "Destructing the ninja shadow.\n");
        destruct (myself -> ninja_object());
    }

    if ( !(TP->query_immortal()) ) {
        "/players/tatsuo/guild/room"->commune_ninja(
          "[*Yoshihiro-San*] "+TP->query_name_true()+
          " just left the guild !!!\n   Let's fling "+TP->query_possessive()+" corpse "+
          "to the dogs and hang "+TP->query_possessive()+" head on the wall "+
          "as traitor !!!\n" );
    }

    write( "Well, then leave the ninjas !!!\n" );
}

/* --- the extra-look ------------------------------------------------------- */
extra_look()
{
    string text;

    if ( myself == TP ) {
        text = "You wear the robe of the Ninja Clan of Ezo";
    }
    else {
        if ( TP->query_gender() == myself->query_gender() ) {
            if ( myself->query_gender() == 2 )
                text = "She wears the robe of the Ninja Clan of Ezo";
            else
                text = "He wears the robe of the Ninja Clan of Ezo";
        }
        else {
            if ( myself->query_gender() == 2 )
                text = "She wears the robe of the Ninja Clan of Ezo";
            else
                text = "He wears the robe of the Ninja Clan of Ezo";
        }
    }
     return text;
}

/* --- allowed to wield the weapon (living.c) ------------------------------- */
dont_wield( weapon, hand )
{
    if ( weapon && weapon->query_info() == "ninja_weapon" ) {
        if ( !(TP->query_wielded_weapon(0)) ) {
            if ( TP->query_level() < weapon->query_needed_lvl_fst() ) return( 1 );
            return( 0 );
        }
        else if ( !(TP->query_wielded_weapon(1)) ) {
            if ( TP->query_level() < weapon->query_needed_lvl_sec() ) return( 1 );
            return( 0 );
        }
        return( 1 );
    }
    return( 0 );
}

/* ----- the helpdir of the ninjas ---------------------------------------- */
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

    if ( str == "spell" )
        str = "spells";
    else if ( str == "class" ) {
        write( "The class-system has been removed !\n" );
        return( 1 );
    }

    path = "/players/tatsuo/guild/helpdir/"+str;
    if ( file_size(path) > 0 ) {
        cat( path ); 
        return( 1 );
    }

    return( 0 );
}

_mhelp(str)
{
    string path;

    if ( !str )
        return;

    if ( sizeof( explode(str, " ") ) == 1 ) {
        if ( str == "spell" )
            str = "spells";
        else if ( str == "class" ) {
            write( "The class-system has been removed !\n" );
            return( 1 );
        }

        path = "/players/tatsuo/guild/helpdir/"+str;
        if ( file_size(path) > 0 ) {
            TP->more( path );
            return( 1 );
        }
    }

    return( 0 );
}

// ----- BANISHED -----------------------------------------------------------
 
int _banished( )
{
    write( BANISHED->banish_info( TP->query_real_name() ) );
    return( 1 );
}




