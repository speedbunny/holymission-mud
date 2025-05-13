inherit "obj/armour";

#include "/obj/descs.h"

#include "/players/patience/GenObj/move_blocked.h"  /* used at throwing               */

#include "/players/dice/guild/ndef.h"           /* the global defines             */

#include "/players/patience/guild/nskill.h"
#include "/players/patience/guild/nmess.h"          /* the combat_messages of the nin */
#include "/players/dice/guild/ncommu.h"        /* communicate-functions          */
#include "/players/dice/guild/special.h"        /* camouflage, assassinate */

/* ----- defines -------------------------------------------------------- */

int    GuildNo;                                      /* guild-number      */
object secWielded;                                   /* sec. wielded weap */
object fullAttack;                                   /* NULL, if not      */

object myself;                                       /* the owner of the soul */

int    attackCon;                                    /* attack-condition  */
int    attackConHeal;                                /* act. con-heal-stat*/

status meditate;                                     /* just meditating    */

string attack_func;                                  /* next called attack */
string attack_arg;                                   /* the arg for it     */
status attack_blocked;                               /* is the att. blocked*/

status alreadyDone;                                  /* already done the init?*/

int    HealPerHB;                                    /* HP/heartbeat (medita) */

#include "/players/patience/guild/nspells.h"         /* ninja-spells        */
#include "/players/patience/guild/npriest.h"        /* priest-spells        */
#include "/players/patience/guild/nsorcerer.h"       /* sorcerer-spells     */



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

/* --- the void reset ---------------------------------------------------------- */
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
    set_ac(0);

}

/* --- the init ------------------------------------------------------------ */
init( )
{
    if( !TP || TP!=environment()) return;

    ::init();
    /*  add_action( "_nothing","", 1 );*/

    add_action( "_wield",          "wield" );
    add_action( "_unwield",        "unwield" );
    add_action( "_throw",          "throw" );
    add_action( "_karate",         "karate" );
    add_action( "_start_meditate", "clean" );
    add_action( "_full_attack",    "fullattack" );
    add_action( "_intro",          "introduce" );

    add_action( "_stats",          "stats" );
    add_action( "_hp",             "hp"    );

    add_action( "_night_eyes",     "look" );              /* nspells.h */
    add_action( "_night_inv",      "i" );                 /* nspells.h */
    add_action( "_nshake",          "nshake" );
    add_action( "_night_get",      "get" );               /* nspells.h */
    add_action( "_night_get",      "take" );              /* nspells.h */
    add_action( "_check",          "check" );             /* nspells.h */
    add_action( "_warcry",         "warcry" );            /* nspells.h */
    add_action( "_spy",            "spy" );               /* nspells.h */

    add_action( "_shout",          "shout" );             /* ncommu.h */
    add_action( "_tell",           "tell" );              /* ncommu.h */
    add_action( "_ninja",          "ninja" );             /* ncommu.h */
    add_action( "_emote",          "ninja/" );             /* ncommu.h */
    add_action( "_say",            "say" );               /* ncommu.h */
   add_action ("_say","'");   /* ncommu.h */
    add_action( "_beep",           "beep" );              /* ncommu.h */
    add_action( "_help",           "help" );   
    add_action( "_mhelp",          "mhelp" ); 

    add_action( "_camouflage",     "camouflage" );        /* special.h */
    add_action( "_assassinate",    "assassinate" );       /* special.h */
    add_action( "_reveal",         "reveal" );            /* special.h */

    add_action("missile","missile");
    add_action("shock","shock");
    add_action("fireball","fireball");

    /*  add_action( "_get",            "get" );*/

    add_action( "_dump",           "dump" );
    add_action( "_dumpOther",      "dumpo" );
    add_action( "_set_skill",      "setskill" );
    add_action( "_set_skill_max",  "setskillmax" );

    if ( TP->query_real_name() == "dice" ||        /* priest-spells */
      TP->query_real_name() == "sourcer" )
    {
	add_action( "do_firstaid", "firstaid" );
	add_action( "do_cure", "cure" );
	add_action( "do_fear", "fear" );
	add_action( "do_resurrect", "resurrect" );
	add_action( "do_command", "command" );
    }

    if ( alreadyDone )                                   /* if already init, abort */
	return;

    myself = TP;

    if ( myself->query_real_name() == "patience" ) {
	set_short( "A light-blue ninja-robe" );
	set_long( "A light-blue ninja-robe, which covers all the body,\n" +
	  "except of his green-grey eyes.\n" );
    }
    else if ( myself->query_real_name() == "itzy" ) {
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

    secWielded = 0;                           /* default: no second wielded  */
    fullAttack = 0;
    attack_blocked = 0;

    attackConHeal = 0;

    meditate = FALSE;
    HealPerHB = HEAL_PER_HB;

    attackCon = MAX_ATTACK_CON;
    TP->set_n_ac( 0 );

    if ( !TP->query_immortal() ) {
	TP->setmmin( "jumps in from nowhere" );
	TP->setmmout( "vanishes" );
        TP->setmin("sneaks");
        TP->setmout("sneaks");
    }

    /* ----- loading the skills ----------------- */
    load_all_skills();

    alreadyDone = TRUE;
}


/* --- leaving the guild -------------------------------------------------- */
guild_changes()
{
    _unwield( "second" );
    if ( !TP->query_immortal() ) {
	TP->setmmin( "arrives in a puff of smoke" );
	TP->setmmout( "disappears in a puff of smoke" );
    }

    /* Uglymouth 150494: Added general way to leave religions
       TP->set_religion( "Illuvatar" );
    */

    write( "Well, then leave the ninjas, fool !!!\n" );
}

/* --- the extra-look ------------------------------------------------------- */
extra_look()
{
    string text;

    if ( myself == TP ) {
	text = "You can be really proud of your body:\n";
    }
    else {                                                       /* player looks at me */
	if ( TP->query_gender() == myself->query_gender() ) {        /* same gender     */
	    if ( myself->query_gender() == 2 )                        /* gender = female */
		text = "She is about your age and has a body worth of envy:\n";
	    else                                                      /* gender = male */
		text = "He is about your age and has a body worth of envy:\n";
	}
	else {                                                    /* different gender */
	    if ( myself->query_gender() == 2 )                        /* gender = female */
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

/* --- wielding ------------------------------------------------------------ */
_wield( arg )
{
    string what;
    object weapon;
    status secFlag;

    if ( !arg || arg == "second" ) {
	write( "Which weapon do you want to wield ?\n" );
	return( 1 );
    }

    if ( query_fullattack() ) {
	write( "You're in a fullattack, you are much too busy to do this !!!\n" );
	return( 1 );
    }   

    if ( sscanf( arg, "second %s", what ) ) {
	secFlag = TRUE;
	weapon = GetWeapon( what );
    }
    else {
	weapon = GetWeapon( arg );
	secFlag = FALSE;
    }

    if ( !weapon ) {
	write( "You don't have this item.\n" );
	return( 1 );
    }

    /* ----- as second weapon ----- */
    if ( secFlag ) {
	if ( weapon->query_weapon() ) {                      /* really a weapon? */
	    if ( weapon->query_two_handed() ) {               /* two-hander ?     */
		write( "You cannot wield a twohander as second weapon.\n" );
	    }
	    else if ( (this_player()->query_wielded_weapon()) &&
	      ((this_player()->query_wielded_weapon())->query_two_handed()) ) {
		write( "You cannot wield a second weapon, while wielding a twohander.\n" );
	    }
	    else {
		if ( weapon->query_info() == "ninja_weapon" ) {    /* ninja-weapon? */
		    if ( weapon->wield_second( weapon->query_name() ) )
			secWielded = weapon;
		    say(capitalize(TP->query_real_name()) + " wields " +
		      weapon->query_name() + ".\n");
		}
		else
		    write( "You only can use a Ninja-weapon, as second weapon.\n" );
	    }
	}
	else
	    write( "This is not a weapon.\n" );
	return( 1 );
    }

    /* ----- as first weapon ----- */
    if ( weapon->query_weapon() ) {                          /* really a weapon?*/
	if ( weapon->query_two_handed() && (secWielded) )     /* twohander  ?    */
	    write( "You have to remove your second weapon first, if you want " +
	      "to wield the twohander.\n" );
	else
	    weapon->wield( weapon->query_name() );
    }
    else
	write( "This is not a weapon.\n" );

    return( 1 );
}

/* --- unwielding the weapon ------------------------------------------------ */
_unwield( arg )
{
    object weapon;
    string sweapon, scommand;
    int    which;                                             /* 1=first,2=sec */

    if ( query_fullattack() ) {
	write( "You're in a fullattack, you are much too busy to do this !!!\n" );
	return( 1 );
    }   

    if ( !arg ) {                                             /* the first     */
	which = 1;
    }
    else if ( arg == "second" ) {                             /* the second    */
	which = 2;
    }
    else if ( sscanf( arg, "%s", sweapon ) == 1 ) {           /* name of weap   */
	weapon = present( sweapon, this_player() );
	if ( weapon ) {
	    if ( weapon == secWielded )
		which = 2;
	    else
		which = 1;
	}
    }
    else if ( sscanf( arg, "%s %s", scommand, sweapon ) == 2 ) { /* name sec weap */
	if ( scommand == "second" ) {
	    weapon = present( sweapon, this_player() );
	    if ( weapon )
		if ( secWielded == weapon )
		    which = 2;
	}
    }

    if ( which == 1 ) {
	weapon = this_player()->query_wielded_weapon();
	if ( weapon ) {
	    this_player()->stop_wielding();
	    weapon->un_wield();                                /* just to make sure */
	    write( "You unwield your first weapon.\n" );
	    say( this_player()->query_name() + " unwields " + TP_POSS + " weapon.\n" );
	}
    }
    else if ( which == 2 ) {
	if ( secWielded ) {
	    secWielded->un_wield();
	    write( "You unwield your second weapon.\n" );
	    say( this_player()->query_name() + " unwields " + TP_POSS + " weapon.\n" );
	}
    }
    else
	return( 0 );

    return( 1 );
}

/* --- allowed to wield the wapon (living.c) ----------------------------------- */
dont_wield( weapon )
{
    if ( weapon->query_weapon() ) {                          /* really a weapon?*/
	if ( weapon->query_two_handed() && (secWielded) ) {   /* twohander  ?    */
	    write( "You have to remove your second weapon first, if you want " +
	      "to wield the twohander.\n" );
	    return( 1 );
	}
    }
    else {
	write( "This is not a weapon.\n" );
	return( 1 );
    }

    return( 0 );                                             /* ok for wielding */
}

/* --- the weapon informs us, that the weapon is unwielded ------------------ */
unwield_second( weapon )
{
    if ( secWielded )
	if ( weapon == secWielded )
	    secWielded = 0;
}


/* --- the two-handed combat & the full-attack -------------------------------- */
recognize_fight( ob )
{
    int dead;

    if ( query_meditate() )
	present( "meditator", myself )->stop_meditate();

    if ( secWielded ) {
	if ( random(100) < actTHCSkill ) {
	    dead = _ninja_hit_player( secWielded );
	    if ( !dead ) {
		if ( secWielded->query_raise_block() < query_thc_skill() ) {
		    if ( MY_ATTACKER->query_level() < ALL_STAT_AV )
			advance_skill( TP, THC_SKILL, 1, 50 );
		    else
			advance_skill( TP, THC_SKILL, 1, 100 );
		}
	    }
	}
	else {
	    write( "You missed.\n" );
	    advance_skill( TP, THC_SKILL, 1, 20 );
	}
    }

    if ( TP->query_invis() )
	rm_invis();

    if ( (dead != -1) && query_fullattack() )
	_do_fullattack( );
}

/* --- prepares the next attack ------------------------------------------------ */
_do_attack( arg )
{
    if ( attack_func ) {
	write("You are busy doing another attack.\n");
	return( 1 );
    }

    attack_func = "_" + query_verb();
    attack_arg = arg;

    return( 1 );
}

/* --- timeing the guild-soul --------------------------------------------------- */
/* !!! NEVER CHANGE THIS ROUTINE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
time_guild_soul()
{
    if ( attack_blocked && attack_func ) {
	attack_blocked = FALSE;
	call_other( this_object(), attack_func, attack_arg );
	attack_func = 0;
    }

    /*  query_fullattack();    */               /* handles the full-attack-flag */

    attackConHeal = ( 1 + attackConHeal) * 2;
    if ( attackConHeal == 2 ) {
	if ( attackCon < MAX_ATTACK_CON )
	    attackCon++;
	attackConHeal = 0;
    }

    if ( query_meditate() ) {
	if ( (TP->query_max_hp() <= TP->query_hp()) &&
	  (TP->query_max_sp() <= TP->query_sp()) ) {
	    write( "You finished this chapter of ZEN-philosophy.\n" );
	    present( "meditator", myself )->stop_meditate();
	}
	this_player()->heal_self( HealPerHB );
    }

    if ( query_iscamou() && (!TP->query_immortal()) )
	dec_camou();
}

/* --- throws an item --------------------------------------------------------- */
_throw( arg )
{
    object ob, who, throw_dest, blocker;
    string what, swho, arr;
    int    i, damage, transRet;                              /* don-t change i !!! */

    if ( !arg )
	return;

    ob = who = 0;

    if ( query_fullattack() ) {
	write( "You're in a fullattack, you are much too busy to do this !!!\n" );
	return( 1 );
    }

    if ( attack_blocked ) {
	write( "Have patience, you are just preparing for an attack.\n" );
	return( 1 );
    }

    if ( this_player()->query_wielded_weapon() && secWielded ) {
	write( "You don't have a hand free to throw something !!!\n" );
	return( 1 );
    }

    if ( attackCon < MAX_ATTACK_CON/3 ) {
	write( "You are too exhausted to throw things.\n" );
	return( 1 );
    }

    if ( query_to_heavy() ) {
	write( "You feel too heavy to throw things.\n" );
	return( 1 );
    }

    if ( check_armour() ) {
	write( "Your unusual armour hinders you from throwing.\n" );
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

/* --- Karate the opponent ------------------------------------------------------ */
_karate( arg )
{
    object who;
    string att_obj_name;
    int    damage;

    if ( query_fullattack() ) {
	write( "You're in a fullattack, you are much too busy to do this !!!\n" );
	return( 1 );
    }

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

/* --- Full Attack ------------------------------------------------------------ */
_full_attack( arg )
{
    if ( query_to_heavy() ) {
	write( "You feel too heavy for a fullattack.\n" );
	return( 1 );
    }

    if ( check_armour() ) {
	write( "Your unusual armour hinders you to do a fullattack.\n" );
	return( 1 );
    }

    if ( query_fullattack() )
	write( "You are already doing a full attack to " + fullAttack->query_name() + ".\n" );
    else {
	if ( this_player()->query_attack() ) {
	    if ( attackCon < FULL_ATTACK_COST )
		write( "You are too exhausted for a fullattack.\n" );
	    else {
		tell_object(this_player(), "You jump at " + MY_ATTACKER->query_name() +
		  " and start your FULLATTACK.\n");
		tell_object(MY_ATTACKER, TPN + " jumps at you beats you with all his might !!!\n" );
		say( TPN + " jumps at " + MY_ATTACKER->query_name() + " and beats "+
		  MY_ATTACKER->query_pronoun() + " with all " + TP_POSS + " might !!!\n",
		  MY_ATTACKER);
		fullAttack = this_player()->query_attack();
		attackCon -= FULL_ATTACK_COST;
	    }
	}
	else
	    write( "You are not fighting !!!\n" );
    }

    return( 1 );
}

/* ----- makes the Full Attack ------------------------------------------------ */
_do_fullattack()
{
    int    weaponHit, tmp, i, count;
    object att_obj, firstWielded;
    string att_obj_name;

    if ( ALL_STAT_AV < 20 )
	count = 1;
    else
	count = 2;

    att_obj = MY_ATTACKER;
    att_obj_name = MY_ATTACKER->query_name();
    firstWielded = this_player()->query_wielded_weapon();

    for ( i = 0; i < count; i++ ) {
	if ( firstWielded ) {
	    if ( _ninja_hit_player( firstWielded ) == -1 )              /* dead ? */
		return;
	}
	if ( secWielded ) {
	    if ( _ninja_hit_player( secWielded ) == -1 )                /* dead ? */
		return;
	}
    }
}

/* --- hit the opponent in full_attack ---------------------------------------- */
_ninja_hit_player( weapon )
{
    object att_obj;
    string att_obj_name, *msg;
    int    weaponHit, tmp, bonus;

    if ( !MY_ATTACKER || !(living(MY_ATTACKER)) )             /* don't have an attacker */
	return( 1 );

    if ( environment( this_player() ) != environment( MY_ATTACKER ) )     /* not here */
	return( 1 );

    if ( query_to_heavy() ) {
	write( "You feel too heavy to hit your opponent.\n" );
	return( 1 );
    }

    att_obj = MY_ATTACKER;
    att_obj_name = MY_ATTACKER->query_name();
    weaponHit = weapon->magic_hit( att_obj );

    if ( weaponHit == "miss" )
	return(0);
    else {
	bonus = TP->stat_dam( weapon );
	if ( weapon->weapon_class() < bonus )
	    bonus = weapon->weapon_class() + (bonus - weapon->weapon_class())/2;
	if ( bonus < 0 ) bonus = 0;
	tmp = random(weapon->weapon_class() + bonus) + weaponHit;

	if ( !tmp )
	    tmp = 1;
	tmp = (att_obj)->hit_player( tmp );

	/* ----- messages defined in the weapon ------------------------------ */
	TP->add_exp( tmp );
	msg = weapon->query_hit_msg( tmp, att_obj_name, TP, att_obj );
	if ( !msg ) {
	    CalcDamage( att_obj, att_obj_name, tmp );
	    return( 1 );
	}
	else if ( (att_obj) && !(att_obj->query_ghost()) && living(att_obj) ) {
	    tell_object( TP, "You " + msg[0] + "\n");
	    tell_object( att_obj, capitalize( TP->query_real_name() ) + " " + msg[1] + "\n");
	    say( capitalize( TP->query_real_name() ) + " " + msg[2] + "\n",att_obj );
	}
	else {
	    write( "You killed " + att_obj_name + ".\n" );
	    say( capitalize( TP->query_real_name() ) + " " );
	}
    }

    if ( (att_obj) && !(att_obj->query_ghost()) && living(att_obj) )            
	return( 0 );                                     /* opponent survived */

    return( -1 );                                       /* opponent is dead */
}

/* --- the parry-function --------------------------------------------------------- */
/* !!! TAKE CARE - REVERSED VALUES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
hit_parry( damage )
{
    int    pc, monstLvl, parryChncPer, parryChnc;
    object monst, me;

    if ( query_fullattack() )
	return( damage );

    if ( query_to_heavy() ) {
	tell_object( myself, "Your heavy stuff hinders you from parrying the attack.\n" );
	return( damage );
    }

    if ( check_armour() ) {
	write( "Your unusual armour hinders you to parry the attack.\n" );
	return( damage );
    }

    monst = this_player();
    me    = monst->query_attack();

    if ( !me )
	return( damage );

    monstLvl = monst->query_level();
    parryChncPer = (actParrySkill * 2) / 6 + 2;
    parryChnc = (me->query_dex() + me->query_int() + me->query_wis() + 
      me->query_con()) / 4;

    if ( parryChnc > monstLvl )
	pc = parryChncPer*2 - ( monstLvl * parryChncPer ) / parryChnc;
    else
	pc = (parryChncPer * parryChnc) / monstLvl;

    /* old was pc > random(100) master parried nearly any hit 81 > rd(100) */
    if ( pc && ( (pc + random(20)) > random(200) ) )    /* reduced whisky to 55% change */
    {
	ParryMess( me, monst );
	if ( monstLvl < ALL_STAT_AV )
	    advance_skill( me, PARRY_SKILL, 1, 30 );
	else
	    advance_skill( me, PARRY_SKILL, 1, 100 );

	return( 0 );
    }

    advance_skill( me, PARRY_SKILL, 1, 15 );

    return( damage );
}

/* --- get something ---------------------------------------------------------- */
_get( arg )
{
    /* this should make the illusion now !!!!!!!!!!!! */

    /*   object ob;

       if ( !arg )
	  return;

       if ( MY_ATTACKER ) {
	  if ( !(present( arg, environment(this_player()) )) )
	     write( "Sorry, but that is not here.\n" );
	  else
	     write( MY_ATTACKER->query_name() + " hinders you from getting it !!!\n" );
	  return( 1 ); 
       }

       return( 0 );*/
}

/* --- meditating ------------------------------------------------------------- */
_start_meditate( arg )
{
    /* Galadriel 3-JAN-1994: can clean other things too! (key's etc.) */
    if ( arg != "spirit" ) return 0;
    if ( !present( "meditator", myself ) ) {
	transfer( clone_object( MEDITATOR ), myself );
	present( "meditator", myself )->start_meditate( "spirit" );
    }
    else
	write( "oops, there is something wrong. mail it the guild-wiz.\n" );

    return( 1 );
}

query_meditate()  { return( meditate ); }
set_meditate()    { meditate = TRUE; }
cancel_meditate() { meditate = FALSE; }

/* --- rearranges the inventory of the player --------------------------------- */
/*_rearrange( )
{
   if ( this_object() && environment(this_object()) )          
      if ( first_inventory(environment(this_object())) != this_object() )
	 move_object( this_object(), environment(this_object()) );
}*/

/* --- the NOTHING-function *grin* ---------------------------------------------- */
_nothing( arg )
{
    if ( query_fullattack() ) {
	if ( query_verb() == "peace" || query_verb() == "dump" )
	    return( 0 );

	write( "You are much too busy to do anything in fullattack !!!\n" );
	return( 1 );
    }

    return( 0 );
}


/* --- queries ------------------------------------------------------------------ */
query_secWielded( )   { return( secWielded ); }

query_fullattack( )
{
    return( 0 );                               /* no fullattack implemented */

#if 0
    if ( fullAttack )
	if ( fullAttack != 0 ) {
	    if ( MY_ATTACKER ) {
		if ( environment( this_player() ) == environment( MY_ATTACKER ) ) {
		    return( fullAttack );
		}
	    }
	    else {                                    /* preventing the LINK-DEAD trick */
		if ( present( fullAttack, environment(this_player()) ) ) {
		    fullAttack->hit_player( 1 );
		    return( fullAttack );
		}
	    }
	}

    fullAttack = 0;
    return( 0 );
#endif
}

query_accuracy( )   { return( actAccSkill ); }

query_to_heavy( )
{
    int max_weight;

    max_weight = (((myself->query_level() + TP->query_str()) / 2 + 10) * 4) / 4;
    return( myself->query_weight() > max_weight );
}

query_attackCon( )
{
    return( attackCon );
}

restore_attackCon( v )
{
    attackCon += v;
    if ( attackCon > MAX_ATTACK_CON )
	attackCon = MAX_ATTACK_CON;
}

check_armour()
{
    object arm;
    int    i;

    for ( i = 0; i < sizeof(TP->query_armour()); i++ ) {
	if ( (TP->query_armour())[i] && (TP->query_armour())[i]->armour_class() > 0 )
	    if ( !((TP->query_armour())[i]->query_ninja_wear()) )
		return( 1 );
    }

    return( 0 );
}


/* ----- supporting functions ------------------------------------------------------ */
weapon_hit( flag )
{
    if ( flag )
	advance_skill( myself, ACC_SKILL, 1, 100 );
    else
	advance_skill( myself, ACC_SKILL, 1, 30 );
}

missile()  { return 1; }
shock()    { return 1; }
fireball() { return 1; }

/* --- gets the object-pointer of a weapon --------------------------------------- */
GetWeapon( str )
{
    string which, arr;
    int    no, arrLen, i, count;
    object inv;

    if ( !str )
	return;

    arr = explode( str, " " );
    arrLen = sizeof( arr );
    if ( arrLen < 1 )
	return;

    if( arrLen > 1 )                                      /* there could be a number */
	if ( sscanf( arr[arrLen-1], "%d", no ) == 1 )                     /* number   */
	    if ( no > 0 )
		arrLen--;

    which = "";                                           /* cat it                  */
    for ( i = 0; i < arrLen; which += (arr[i++]+" ") );
    if ( strlen(which) < 1 )
	return( 0 );

    which = extract( which, 0, strlen(which)-2 );

    if ( no < 2 )
	return( present( which, this_player() ) );
    else {
	inv = all_inventory( this_player() );
	i = 0; count = 1;
	while ( i < sizeof(inv) ) {
	    if ( inv[i]->id( which ) ) {
		if ( count == no )
		    return( inv[i] );
		count++;
	    }              
	    i++;
	}
    }
    return( 0 );
}

/* --- stats of myself ------------------------------------------------------------ */
_stats( arg )
{
    int next;

    next=GUILD_MASTER->query_exp(TP->query_guild(),TP->query_level()+1)-TP->query_exp();

    write( "\n" );
    write( "You are physically " +
      health_desc( TP->query_maxhp(), TP->query_hp() ) +
      ",\nmentally " +
      mana_desc( TP->query_maxsp(), TP->query_sp() ) +
      " and\nattack-conditionally " +
      health_desc( MAX_ATTACK_CON, attackCon ) + ".\n\n" );

    write( "Actual experience:   "+TP->query_exp()+"\n" );
    write( "Exp. for next Level: "+next+"\n\n" );
    write( capitalize(NINJA_TITLES->get_skill_title(actThrowSkill)) + " in Throwing\n" );
    write( capitalize(NINJA_TITLES->get_skill_title(actKarateSkill)) + " in Karate\n" );
    write( capitalize(NINJA_TITLES->get_skill_title(actParrySkill)) +
      " in Yadomejutsu (self-defence)\n" );
    write( capitalize(NINJA_TITLES->get_skill_title(actAccSkill)) +
      " in Kenjutsu (critical hitting)\n" );
    write( capitalize(NINJA_TITLES->get_skill_title(actTHCSkill)) +
      " in Ni-To-Kenjutsu (two-handed-combat)\n" );
    write( capitalize(NINJA_TITLES->get_skill_title(actCamouSkill)) +
      " in Camouflage\n" );
    write( capitalize(NINJA_TITLES->get_skill_title(actAssassSkill)) +
      " in Assassination\n" );
    write( "\n" );

    return( 1 );
}

/* --- new HP-function ----------------------------------------------------------- */
_hp( arg )
{
    write( "Physically:           " + 
      health_desc( TP->query_maxhp(), TP->query_hp() ) + 
      "\nMentally:             " +
      mana_desc( TP->query_maxsp(), TP->query_sp() ) + 
      "\nAttack-conditionally: " +
      health_desc( MAX_ATTACK_CON, attackCon ) + "\n" );

    return( 1 );
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

    if ( sizeof( explode(str, " ") ) == 1 ) {
	if ( str == "spell" )
	    str = "spells";
	else if ( str == "class" ) {
	    write( "The class-system has been removed !\n" );
	    return( 1 );
	}

	path = GUILD_MASTER->query_dir(GUILD_MASTER->query_number(GUILD) );
	path = "/" + path + "/helpdir/" + str;
	if ( file_size(path) > 0 ) {
	    cat( path );
	    return( 1 );
	}
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

	path = GUILD_MASTER->query_dir(GUILD_MASTER->query_number(GUILD) );
	path = "/" + path + "/helpdir/" + str;
	if ( file_size(path) > 0 ) {
	    TP->more( path );
	    return( 1 );
	}
    }

    return( 0 );
}



_dumpOther( arg )
{
    object who, soul;

    if ( !arg )
	return;

    who = find_living( arg );
    if ( who ) {
	soul = present( "ninjasoul", who );
	if ( soul )
	    soul->_dump( "me" );
	else
	    write( arg + " is no ninja.\n" );
    }
    else
	write( "No player with that name (" + arg + ").\n" );

    return( 1 );
}

_dump( arg )
{
    mixed arr;
    int   i,j;

    if ( !arg )
	return;

    if ( !TP->query_newwiz() )
	return;

    if ( arg == "ninja" || arg == "soul" || arg == "me" ) {
	write( "Guild-No: " + GUILD_MASTER->query_number( "ninja" ) + "\n" );
	write( "First wielded: " );
	if ( myself->query_wielded_weapon() )
	    write( (myself->query_wielded_weapon())->short() );
	else
	    write( "none" );
	write( "\n" );

	write( "Second wielded: " );
	if ( secWielded )
	    write( secWielded->short() );
	else
	    write( "none" );
	write( "\n" );

	write( "Full Attack: " );
	if ( fullAttack )
	    write( fullAttack->short() );
	else
	    write( "nope" );
	write( "\n" );

	write( "AttackCon: " + attackCon + "\n" );

	write( "Just Meditating: " + meditate + "\n" );

	write( "skill:\n" );
	write( "ThrowSkill: " + actThrowSkill + " (" + maxThrowSkill + ")\n" );
	write( "KarateSkill: " + actKarateSkill + " (" + maxKarateSkill+")\n" );
	write( "ParrySkill: " + actParrySkill +" (" + maxParrySkill+ ")\n" );
	write( "THCSkill: " + actTHCSkill + " (" + maxTHCSkill + ")\n" );
	write( "AccSkill: " + actAccSkill + " (" + maxAccSkill+")\n" );
	write( "CamouSkill: " + actCamouSkill + " ("+maxCamouSkill+ ")\n" );
	write( "AssassSkill: " + actAssassSkill + " (" + maxAssassSkill+")\n" );

	/*     arr = TP->get_skill( GuildNo );
	     if ( arr ) {
		i = 0;
		while ( i < sizeof( arr ) ) {
		   j = 0;
		   while( j < sizeof( arr[0] ) ) {
		      write( " " + arr[i][j] );
		      j++;
		   }
		   write( "\n" );
		   i++;
		}
	     }*/

	write( "\n" );
	return( 1 );
    }

}

/* ------------------------------------------------------------------------- */
/*    setting the skills                                                     */
/* ------------------------------------------------------------------------- */
_set_skill( arg )
{
    string sk;
    int    v;

    if ( TP->query_real_name() != "dice" && TP->query_real_name() != "itzy"          && TP->query_real_name() != "sourcer" )
	return;

    if ( sscanf( arg, "%s %d", sk, v ) != 2 && ( v < 1 || v > 100 ) ) {
	write( "Error in argument\n" );
	return( 1 );
    }

    if ( sk == "karate" )
	advance_skill_absolut( TP, KARATE_SKILL, v - query_karate_skill()  );
    else if ( sk == "parry" )
	advance_skill_absolut( TP, PARRY_SKILL, v - query_parry_skill() );
    else if ( sk == "acc" )
	advance_skill_absolut( TP, ACC_SKILL, v - query_acc_skill() );
    else if ( sk == "thc" )
	advance_skill_absolut( TP, THC_SKILL, v - query_thc_skill() );
    else if ( sk == "throw" )
	advance_skill_absolut( TP, THROW_SKILL, v - query_throw_skill() );
    else if ( sk == "camouflage" )
	advance_skill_absolut( TP, CAMOU_SKILL, v - query_camou_skill() );
    else if ( sk == "assassination" )
	advance_skill_absolut( TP, ASSASS_SKILL, v - query_assass_skill() );
    else {
	write( "no such skill\n" );
	return( 1 );
    }

    write( sk + " setted to " + v + "\n" );
    return( 1 );
}

/* ------------------------------------------------------------------------- */
/*    setting the skills-max                                                 */
/* ------------------------------------------------------------------------- */
_set_skill_max( arg )
{
    string sk;
    int    v;

    if ( TP->query_real_name() != "dice" && TP->query_real_name() != "itzy"          && TP->query_real_name() != "sourcer" )
	return;

    if ( sscanf( arg, "%s %d", sk, v ) != 2 && ( v < 1 || v > 100 ) ) {
	write( "Error in argument\n" );
	return( 1 );
    }

    if ( sk == "karate" )
	advance_skill_max( TP, KARATE_SKILL, v, 1 );
    else if ( sk == "parry" )
	advance_skill_max( TP, PARRY_SKILL, v, 1 );
    else if ( sk == "acc" )
	advance_skill_max( TP, ACC_SKILL, v, 1 );
    else if ( sk == "thc" )
	advance_skill_max( TP, THC_SKILL, v, 1 );
    else if ( sk == "throw" )
	advance_skill_max( TP, THROW_SKILL, v, 1 );
    else if ( sk == "camouflage" )
	advance_skill_max( TP, CAMOU_SKILL, v, 1 );
    else if ( sk == "assassination" )
	advance_skill_max( TP, ASSASS_SKILL, v, 1 );
    else {
	write( "no such skill\n" );
	return( 1 );
    }

    write( sk + " maximum setted to " + v + "\n" );
    return( 1 );
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
