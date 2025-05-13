// Ninja soul - originally by Patience.

// Darastor 111197: Added filter function for bin soul support
// Darastor 121197: Removed all code for clean spirit - now
//                  handled by the bin system
// Darastor 131197: Added new description for my own robe
// Darastor 131197: Moved nshake out into bin system and removed the
//                  code for it from this file
// Darastor 141197: Fixed typo in call to set_infravision in init()
// Darastor 141197: Removed references to GuildNo - don't think it's needed
//                  since it isn't checked anywhere
// Darastor 141197: Removed add_action for get which had been commented out anyway
//                  since there was no function for it to call
// Darastor 161197: Brought drop() into line with the lfun documentation
// Darastor 191197: Commented out shock, missile and fireball, which I think are
//                  unnecessary actions. Will remove after testing
// Darastor 290198: Added creation of shadow and starting it for ninja weapon
//                  parrying (in the init routine)

inherit "obj/armour";


#include "/players/patience/GenObj/move_blocked.h"  /* used at throwing   */

#include "/players/patience/guild/ndef.h"      /* the global defines      */
#include "/players/patience/guild/ncommu.h"    /* communicate-functions   */

// Darastor: Next lines added 11/11/97 - may want to move into a general
// ninja guild defs file in future
#define SHADOW "/players/patience/guild/ninja_shadow"
#define BIN "/players/patience/guild/bin/"

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

// Darastor 11/11/97: Next function is the filter function for the
// bin system
// Stolen from the jedi code, with appropriate modifications
// - thanks Mangla!
// NB For Warlord: the emote command syntaces are specified in this
// function!

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
        (BIN+"ninja")->main(str);
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

    
    // Darastor: Next line added 11/11/97 - filter function for
    // bin system
    add_action("_filter","",1);

    if ( alreadyDone )                             /* if already init, abort */
	return;

    myself = TP;

    if ( myself->query_real_name() == "warlord" ) {
	set_short( "A light-blue ninja-robe" );
	set_long( "A light-blue ninja-robe, which covers all the body,\n" +
	  "except of his green-grey eyes.\n" );
    }
    else if (myself -> query_real_name() == "darastor") {
        set_short("A deep blue ninja-robe");
        set_long("A deep blue ninja robe, which covers all his body,\n" +
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
	"/players/patience/guild/room"->commune_ninja(
	  "[*Yoshihiro-San*] "+TP->query_name_true()+
	  " just left the guild !!!\n   Flung "+TP->query_possessive()+" corpse "+
	  "to the ravens and hang "+TP->query_possessive()+" head on the wall "+
	  "as traitor !!!\n" );
    }

    write( "Well, then leave the ninjas !!!\n" );
}

/* --- the extra-look ------------------------------------------------------- */
extra_look()
{
    string text;

    if ( myself == TP ) {
	text = "You can be really proud of your body:\n";
    }
    else {
	if ( TP->query_gender() == myself->query_gender() ) {
	    if ( myself->query_gender() == 2 )
		text = "She is about your age and has a body worth of envy:\n";
	    else
		text = "He is about your age and has a body worth of envy:\n";
	}
	else {
	    if ( myself->query_gender() == 2 )
		text = "She is about your age and has a very pretty body:\n";
	    else
		text = "He is about your age and has a very pretty body:\n";
	}
    }

    if ( myself->query_gender() == 2 )
	text += "tall and well-built, with wide shoulders, a generous\n" +
	"bosom, slim waist, and long, tawny legs";
    else
	text += "tall and well-built, with wide shoulders, massive\n" +
	"pectorals, and thick, tawny legs";

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

    path = "/players/patience/guild/helpdir/"+str;
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

	path = "/players/patience/guild/helpdir/"+str;
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

