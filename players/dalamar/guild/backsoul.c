inherit "obj/armour";

//#include "/obj/descs.h"

//#include "/players/tatsuo/GenObj/move_blocked.h"  /* used at throwing   */

#include "/players/tatsuo/guild/ndef.h"      /* the global defines      */

#include "/players/tatsuo/guild/ncommu.h"    /* communicate-functions   */

/* ----- defines -------------------------------------------------------- */

int    GuildNo;                                      /* guild-number      */
object myself;                                       /* the owner of the soul */
status alreadyDone;                                  /* already done the init?*/

//#include "/players/tatsuo/guild/nspells.h"         /* ninja-spells        */



/* --- the id of the guild ---------------------------------------------- */ 
id(str)
{
    return( str=="ninja_soul" || str=="ninjasoul" || str == "robe" || 
      str == "ninja-robe" );
}

/* --- can-t drop and get it ---------------------------------------------- */ 
get()
{
    return( 1 );
}

drop()
{
    write( "You have to leave the guild for that.\n" );
    return( 1 );
}

query_ninja_wear( ) { return( 1 ); }

/* --- the void reset ------------------------------------------------------- */
reset(arg)
{
    ::reset( arg );
    if( arg )
	return;

    GuildNo = GUILD_MASTER->query_number(GUILD);

    set_type( "guild" );
    set_name( "robe" );
    set_alias( "ninja_soul" );
    set_short( "A black ninja-robe" );
    set_long("A black ninja-robe, which covers all his body,\n" +
      "except of his brown eyes.\n");
    set_weight(0);
}

/* --- the init ------------------------------------------------------------ */
init( )
{
    if( !TP || TP!=environment()) return;

    ::init();

//    add_action( "_throw",          "throw" );
//    add_action( "_intro",          "introduce" );

    add_action( "_ninja",          "ninja" );             /* ncommu.h */
    add_action( "_emote",          "ninja/" );             /* ncommu.h */
    add_action( "_beep",           "beep" );              /* ncommu.h */
    add_action( "_help",           "help" );   

    add_action( "_banished",       "banished" );

    if ( alreadyDone )                             /* if already init, abort */
	return;

    myself = TP;

    if ( myself->query_real_name() == "tatsuo" ) {
	set_short( "A light-blue ninja-robe" );
	set_long( "A light-blue ninja-robe, which covers all the body,\n" +
	  "except of his green-grey eyes.\n" );
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

    set_size( TP->query_size() );
    if ( !worn && !TP->query_wizard() )
	command( "wear ninja-robe",TP );  

    TP->set_n_ac( 0 );

    if ( !TP->query_immortal() ) {
	TP->setmmin( "jumps in from nowhere" );
	TP->setmmout( "vanishes" );
        TP->setmin("sneaks");
        TP->setmout("sneaks");
    }

    alreadyDone = TRUE;

    TP->set_language_skill(1,100);              // remove this again
    TP->set_inravision();
    

   if ( TP->query_real_name() == "lamorack" )
      transfer( clone_object("/players/tatsuo/guild/spec_weap/lamorack"),TP);
   if ( TP->query_real_name() == "prince" )
      transfer( clone_object("/players/tatsuo/guild/spec_weap/prince"),TP);

/*
   if ( !(TP->query_immortal()) ) {
      write( 
   "------------------------------------------------------------------------\n"+
   "ATTENTION: THIS IS ONLY A TEST-OBJECT OF THE NINJA-SOUL !!!!\n\n"+
   "THE ORIGINAL FILE HAS BEEN DELETED BY A WIZARD, ABUSING A SECURITY-LEAK\n"+
   "YOU HAVE 2 POSSIBILITES:\n"+
   "1. CHANGE THE GUILD\n"+
   "2. STAY A NINJA AND WAIT UNTIL THE GUILD IS RECODED (this should be by \n"+
   "   the end of march)\n"+
   "IF YOU WANT TO STAY A NINJA, PLEASE QUIT NOW, OTHERWISE TALK TO A WIZARD\n"+
   "\ntatsuo\n"+
   "-------------------------------------------------------------------------\n"
   );
   }
*/
}


/* --- leaving the guild -------------------------------------------------- */
guild_changes()
{
    if ( !TP->query_immortal() ) {
	TP->setmmin( "arrives in a puff of smoke" );
	TP->setmmout( "disappears in a puff of smoke" );
    }

    if ( !(TP->query_immortal()) ) {
       "/players/tatsuo/guild/room"->commune_ninja(
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

/* --- allowed to wield the wapon (living.c) ------------------------------- */
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

#if 0 //throw: need to code it as an ability
/* --- throws an item ------------------------------------------------------ */
_throw( arg )
{
    object ob, who, throw_dest, blocker;
    string what, swho, arr;
    int    i, damage, transRet;                       /* don-t change i !!! */

    if ( !arg )
	return;

    ob = who = 0;

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
	    if ( !attack_blocked && attack_func != "_throw" ) {     /* atta in this hb ? */
		attack_func = "_throw";
		attack_arg = arg;
		attack_blocked = TRUE;
		return( 1 );
	    }

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

	    if ( (random(100) >= actThrowSkill) ) {                 /* too unskillfull ? */                             /* miss              */
		damage = 0;
	    }

	    transRet = move_blocked( ob, throw_dest, blocker );     /* transfer object   */
	    if ( transRet == 2 || transRet == 3 || transRet < 0 ) {
		write( "Somehow you don't manage it to throw this item.\n" );
		return( 1 );
	    }
	    else if ( transRet )
		transfer( ob, environment( this_player() ) );

	    attackCon -= THROW_COST;

	    if ( who->query_level() < ALL_STAT_AV )
		advance_skill( TP, THROW_SKILL, 1, 50 );
	    else
		advance_skill( TP, THROW_SKILL, 1, 100 );

	    CalcThrowDam( who, who->query_name(), ob, damage );

	    if ( damage > 0 ) {         
		damage = who->hit_player( damage );
	    }
	    else {
		who->attacked_by( myself );
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
	    advance_skill( TP, THROW_SKILL, 1, 30 );
	}
    }
    else {
	if ( transfer( ob, environment(this_player()) ) ) {
	    write( "Somehow you don't manage it to throw this item.\n" );
	    return( 1 );
	}
	write( "You throw the " + ob->query_name() + " high up in the air.\n" );
	say( TPN + " throws a " + ob->query_name() + " high up in the air.\n" );
	advance_skill( TP, THROW_SKILL, 1, 10 );
    }

    return( 1 );
}
#endif

missile()  { return 1; }
shock()    { return 1; }
fireball() { return 1; }

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

   path = "/players/tatsuo/guild_help/"+str;
   if ( file_size(path) > 0 ) {
      cat( path );
      return( 1 );
   }

    return( 0 );
}

/* ------------------------ secret ninja shake ------------------------ */
_nshake(arg)
{
    object mob;

    mob = present(arg,environment(this_player()) );

    if (!arg) return 0;

    if (mob && interactive(mob))
    {
	if (mob->query_guild()==this_player()->query_guild())
	{
	    tell_object(mob,"Ninja "+capitalize(this_player()->query_real_name())+
	      " gives you a secret Ninja handshake.\n");
	    write("You give "+capitalize(mob->query_real_name())+" a secret Ninja handshake.\n");
	} else
	    write("This person isn't member of your great guild.\n");
	return 1;
    }
    return 0;
}


// ----- BANISHED -----------------------------------------------------------
int _banished( )
{
   write( BANISHED->banish_info( TP->query_real_name() ) );
   return( 1 );
}
