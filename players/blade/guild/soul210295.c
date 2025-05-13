
/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+= The Thief Soul=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

#define GM             "guild/master"
#define CD             "sys/chatd"

#define TOTAL_HIDDEN      (dex * 45)   /*        max time hidden  */
#define ROOM              "/players/blade/guild/room"

#define AL_STEALMONEY  -10                        /*  alignment: steal money */
#define AL_STEALITEM   -50                        /*             steal item  */
#define LV_STBAG        25                        /* level for stealing bags */

#define CHK_ATT(); \
if ((att=thief->query_attack()) &&\
    present(att,environment(thief))) {\
   write("You are much too busy to do that.\n");\
   return 1;\
}

#include <lw.h>

object   thief;
int      dex;
int      max_stats;
status   immortal;                                     /* immortal or not   */
status   stashed;                                      /* soul hidden       */
string   th_xlook;	                               /* extra_look string */
string   gm_id;                                        /* soul id from GM   */
string   dir;		                               /* guild directory   */
int      gd;                                           /* guild number      */
string   helpdir;	                               /* guild helpdir     */
string   hideout;	                               /* guild hideout     */
object   att;		                               /* attacker          */
int      remain_hidden;
int      dont_hide;
status   rv_lock;                                   /*    reveal delay   */
status   has_stolen;                               /*      steal delay  */
object   hide;                                    /*  the room we left */

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int drop()
{
    return 1;
}

int get()
{

    if (this_player() && !this_player()->query_immortal())
// call_out("go_to_guild",1);
        {}
    return 1;
}
go_to_guild()
{
    move_object(this_player(),ROOM);
    return;
}

int id(string arg)
{
    return arg == gm_id || arg == "tools" || arg == "case";
}

int long()
{
    if (!stashed) 
    {
	write("This case contains some tools you need.\n");
	return 1;
    }
}

string short()
{
    if (!stashed)
	return "A small, slim case";
}

string extra_look()
{
    return th_xlook;
}

/*=+=+=-+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

void reset(int arg)
{
    if (!arg)
    {
	gd        = GM->query_number("thief");
	dir       = GM->query_dir(gd);
	helpdir   = "/" + dir + "/help";
	hideout   = dir + "/hideout";
	gm_id     = GM->query_id(gd);
	max_stats = GM->query_levels(gd);
	//thief     = environment();
	thief     = this_player();
        if(thief)			// master-object has no TP - Llort
	{
            dex       = thief->query_dex();
	    immortal  = thief->query_immortal();
        }
    }
}

void init()
{
    object shad;

    if (!thief)
	return 0;


      this_player()->set_n_ac(1 + this_player()->query_dex()/3);
    if (!(dont_hide = thief->queryenv("TH_DHIDE")))
	dont_hide = 0;
    else thief->unsetenv("TH_DHIDE");

    if (!(remain_hidden = thief->queryenv("TH_RHIDDEN")))
	remain_hidden = TOTAL_HIDDEN;
    else thief->unsetenv("TH_RHIDDEN");

    stashed = thief->queryenv("TH_STASHED");

    if (!(th_xlook = thief->queryenv("TH_XLOOK")))
    {
	th_xlook = capitalize(thief->query_pronoun())
	+ " slips through the shadows with a remarkable grace";
	thief->setenv("TH_XLOOK",  th_xlook);
    }

    if (!thief->crit_shadow())
    {
     shad = clone_object("/players/blade/guild/crit_shadow");
      shad->start_shadow(thief,0,"crit_shadow");
    }

    if (!thief->dodge_shadow())
    {
	shad = clone_object(dir + "/dodge_shadow");
	shad->start_shadow(thief,0,"dodge_shadow");
    }


    add_action("backstab", "backstab");
    add_action("disguise", "disguise");
    add_action("guild_line", "thief");
    add_action("guild_line", "thief/");
    add_action("help", "help");
    add_action("hide", "hide");
    /*    add_action("hideout", "hideout");
	add_action("leave", "leave"); */
    add_action("picklock", "picklock");
    add_action("poison", "poison");
    add_action("quit","quit");
    add_action("reveal", "reveal");
    add_action("sneak", "sneak");
    add_action("steal", "steal");
    add_action("unhide", "unhide");
}

int do_unhide()
{
    thief->set_vis();
    move_object(thief, environment(thief));
    tell_room(environment(thief),
      thief->query_name() + " " +
      thief->query_msgin() + ".\n");
    return 1;
}

void time_guild_soul()
{
    has_stolen = 0;

    if (dont_hide)
	dont_hide--;

    else
    {
	if (!immortal && thief->query_invis())
	    remain_hidden--;
	if (remain_hidden == 30|| remain_hidden == 28)
	    tell_object(thief,"You feel your concentration slipping.\n");
	if (remain_hidden < 0)
	{
	    remain_hidden = TOTAL_HIDDEN;
      dont_hide = remain_hidden / 20;
	    do_unhide();
	}
    }
}

void guild_changes()
{
    if (thief->crit_shadow())
    {
	if (immortal)
	    write("Destructing the crit_shadow.\n");
	destruct(thief->crit_object());
    }
    thief->set_n_ac(0);

    if (thief->dodge_shadow())
    {
	if (immortal)
	    write("Destructing the dodge_shadow.\n");
	destruct(thief->dodge_object());
    }

    if (!immortal)
    {
	thief->unsetenv("TH_XLOOK");
	thief->unsetenv("TH_STASHED");
    }
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int guild_line(string arg)
{
    return thief->guild_line(arg);
}

int help(string arg)
{
    if (arg == "levels")
    {
	GM->list_levels(gd);
	return 1;
    }

    if (arg == "guild")
	arg = "thief";

    if (!cat(helpdir + "/" + arg))
	return 0;

    return 1;
}

int fail_spell()
{
    help("spell");
    return 1;
}

void recognize_fight()
{
    if (thief->query_invis()) 
    {
	write("You come out of the shadows.\n");
	do_unhide();
    }

    // Thieves have a chance at multiple attacks due their natural speed.
    if (random(80) < dex)
	thief->attack();
    if (random(50) < dex)
	thief->attack();
    if (random(25) < dex)
	thief->attack();
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Backstab +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int backstab(string arg)
{
    object victim, weapon;

    weapon = thief->query_wielded();

    if (!arg) 
	return help("backstab");

    if (!(victim = present(arg, environment(thief))) || !living(victim))
    {
	write("Backstab whom?\n");
	return 1;
    }

    if (!(objectp(weapon)))
    {
	write("Your attack would be more potent with a weapon in hand.\n");
	return 1;
    }

    CHK_ATT();

    if (victim->query_attack(thief))
    {
	write(victim->query_name()
	  + " is obviously much too wary for that attack.\n");

	if (thief->query_invis())
	    return 1;
	else
	    victim->attack_object(thief);
    }

    if (!thief->query_invis())
    {
	write("You move carefully toward " + victim->query_name()
	  + " but " + victim->query_objective() + " notices your approach!\n");
	victim->attack_object(thief);
	victim->attack();
	return 1;
    }

   if (thief->query_sp() < (thief->query_level()*2)) {
     write("You are too weak to backstab "+victim->query_name()+".\n");
     return 1;
   }

    write("You carefully move behind " + victim->query_name() + ".\n");
    disable_interactive(thief,2);
    call_out("backstab_it",2,victim);
    return 1;
}

int backstab_it(object victim)
{
    int dam;

    enable_interactive(thief);
    if (victim && environment(victim)==environment(thief))
    {
    thief->reduce_spell_points(thief->query_level()*2);
	write("You find a vulnerable spot and strike swiftly.\n");
        dam = (600*thief->query_level() * 3 * (dex/10+1)/320);
	if ( (victim->query_hp() / 4) > dam )
      dam = (victim->query_hp() * 2 / 5);
	thief->add_exp(victim->hit_player(dam, 7));
	return 1;
    }
    write("You can't backstab someone who is not here !\n");
    return 1;
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Disguise +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int disguise(string arg)
{
    string option, option2; 

    if (thief->query_invis())
    {
	write("You must be able to see yourself to put on an "
	  + "adequate disguise.\n");
	return 1;
    }

    if (!arg || sscanf(arg, "%s %s", option, option2) != 2
      || (option != "appearance" && option != "title"))
	return help("disguise");

    if (option == "appearance")
    {
	th_xlook = option2;
	thief->setenv("TH_XLOOK", th_xlook);
    }

    if (option == "title") 
    {
	int             gn, lev, gender;
	string          pretitle, title;

	gn = GM->query_number(option2);
	lev = thief->query_level();
	gender = thief->query_gender();

  if (gn==-1 || gn==2 || gn==13)
	{
	    write("What guild?\n");
	    return 1;
	}

	if (!(pretitle = GM->query_pretitle(gn, lev, gender)))
	    pretitle = "none";
	if (!(title = GM->query_title(gn, lev, gender)))
	    title = "none";

	thief->set_pretitle(pretitle);
	thief->set_title(title);
    }

    write("You pull some supplies from your case, then apply some make-up,\n"
      + "adjust your stance, and change your mannerisms.\n");
    say(lw(thief->query_name() + " applies some make-up and stands "
	+ "differently.  You can barely recognize " 
	+ thief->query_objective()) + ".\n");
    return 1;
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Hide =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int hide(string arg)
{
    object          ob, en, sh;
    int inv_lvl;

    if (arg) 
    {			                              /*     Hide an object. */
	if (this_object()->id(arg))                  /* Hide the guild soul. */
	{              
	    if (stashed)
		write("Your tools are safely hidden already.\n");
	    else
	    {
		write("You hide your tools from prying eyes.\n");
		stashed = 1;
		thief->setenv("TH_STASHED", stashed);
	    }
	    return 1;
	}

	if (!(ob = present(arg, thief)) &&
	  !(ob = present(arg, environment(thief))))
	{
	    write("Hide what ?\n");
	    return 1;
	}

	if (living(ob))                            /* Don't hide the living. */
	{
	    write(ob->short() + " moves too much to be hidden.\n");
	    return 1;
	}

	if (ob->id("castle") || ob->query_property("no_hide"))
	{
	    write(ob->short() + " is too big to be hidden.\n");
	    return 1;
	}

	if (environment(ob)==thief && (en=environment(thief)))
	    transfer(ob, en);	                                  /* drop it */

	sh = clone_object(dir + "/hide_shadow");
	sh->start_shadow(ob,0,"hide_shadow",arg);

	say(thief->query_name() + " hides something.\n");
	write("Ok.\n");
	return 1;
    }

    /* hide yourself */

    if (environment(thief)->query_property("no_hide"))
    {
	write("You can't find a place to hide here.\n");
	return 1;
    }

    if (thief->query_invis())
    {
	write("You're already hidden in the shadows.\n");
	return 1;
    }

    if (thief->query_ghost())
    {
	write("You're already pretty well hidden.\n");
	return 1;
    }

    CHK_ATT();

    if (dont_hide)                                     /* for backstab */
    {
	write("You must wait for a while.\n");
	return 1;
    }

    write("You hide in the shadows.\n");
    say(thief->query_name() + " leaves suddenly.\n");

    inv_lvl = (thief->query_level() + dex)/2 + random(10) - 5;
    if (inv_lvl < 5)
	inv_lvl = 5;
    if (!random(60 - inv_lvl))
	thief->set_invis();
    else
	thief->set_invis(inv_lvl);
    return 1;
}

int reveal(string arg)
{
    if (!arg)
	return help("reveal");

    if (this_object()->id(arg))
    {
	if (!stashed)
	    write("Your tools are already in plain sight.\n");
	else {
	    write("You put your tools in plain sight.\n");
	    stashed = 0;
	    thief->setenv("TH_STASHED", stashed);
	}
	return 1;
    }

    CHK_ATT();

    if (rv_lock) 
    {
	write("You continue searching.\n");
	return 1;
    }

    write("You start searching ...\n");
    say(thief->query_name() + " searches the room.\n");
    rv_lock = 1;		                     /* searching takes time */
    call_out("reveal_item", 3, arg);
    return 1;

}

/*
 * with full dexterity, the probabilty to find an item is 50 %, but there's a
 * check against charisma (used as luck) also.
 */

int reveal_item(string arg)
{
    object          ob, sh;
    int             i, chr;

    rv_lock = 0;

    ob = present(arg + "__hidden__", environment(thief));
    if (!ob || environment(thief) != environment(ob))
    {
	write("You found nothing.\n");
	return 1;
    }

    chr = thief->query_chr();
    i = random(2 * max_stats);
    if (i > dex)
    {		/* check for luck */
	if (i <= 2)
	{
	    i = random(100);	/* 30% max chance */
	    if (i < chr)
		i = 1;
	    else
		i = 0;
	} else
	    i = 0;
    } else
	i = 1;

    if (i)
    {
	if (ob->hide_shadow())
	    ob->end_shadow();
	write("You found " + ob->short() + ".\n");
	say(thief->query_name() + " found something.\n");
	return 1;
    }

    write("You found nothing.\n");
    return 1;
}

int unhide()
{
    if (thief->query_ghost())
    {
	write("You try to show yourself to mortal men.\n");
	return 1;
    }

    if (!thief->query_invis())
    {
	write("You are not hiding.\n");
	return 1;
    }

    do_unhide();
    return 1;
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Hideout =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/
/*
int hideout()
{
    if (file_name(environment(thief)) == hideout) 
    {
	write("Your keen thief senses compel you to examine your "
	  + "surroundings.\n");
	return 1;
    }

    if (environment(thief)->has_drink(thief))
    {
	write("You are not allowed to leave with drinks!\n");
	return 1;
    }

    if (environment(thief)->query_property("no_teleport"))
    {
	write("As you try to leave this place you run into an " +
	  "invisible barrier.\n");
	return 1;
    }

    hide = environment(thief);
    thief->move_player("X#" + hideout);
    return 1;
}
*/
/*
int leave()
{
    if (file_name(environment(thief)) != hideout)
    {
	write("You don't want to go quite yet.\n");
	return 1;
    }

    if (objectp(hide))
	thief->move_player("X", hide);
    else   
	thief->move_player("X#" + GM->query_room(gd));	
    write("You have returned.\n");
    return 1;
}
*/

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Picklock +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int picklock(string arg)
{
    object          pl, door;
    int             i, num_doors;
    string          dest;

    if (thief->query_ghost())
    {
	write("You could probably move right through that keyhole.\n");
	return 1;
    }
    CHK_ATT();

    if (!arg)
	return help("picklock");
    if (arg != "door" && sscanf(arg, "%s door", dest) != 1)
	return 0;
    if (!(pl = present("picklock", thief)))
    {
	write("You don't have a picklock.\n");
	return 1;
    }
    if (pl->query_broken())
    {	/* It was broken ... get the next one */
	pl = next_inventory(pl);
	while (pl)
	{
	    if (pl->id("picklock") && !pl->query_broken())
		break;		/* unbroken */
	    pl = next_inventory(pl);
	}
	if (!pl)
	{
	    write("Your picklock is broken.\n");
	    return 1;
	}
    }
    if (!(door = present(arg, environment(thief))))
	return 0;
    if (arg == "door" && (num_doors = door->number_of_doors()) != 1)
    {
	door->which_door();
	return 1;
    }
    if (!door->query_locked())
    {
	write("You wisely decide not to waste your picklock on an unlocked door.\n");
	return 1;
    }
    i = dex * 100 / max_stats;
    if (random(101) >= i)
    {
	pl->set_broken();
	write("CRACK! You break the picklock with your bumbling fingers.\n");
	return 1;
    }
    write("You work the wire into the lock and after a few moments of"
      + " careful probing ...\nYou are met with success.");
    door->set_locked(0);
    door->query_partner_door()->set_locked(0);
    if (random(101) >= i)
    {
	pl->set_broken();
	write("But your picklock broke.\n");
    }
    else write("\n");
    return 1;
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Poison =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int poison(string arg)
{
    string          weap, with, pois;
    object          weap_ob, pois_ob, shad;
    int             i;

    if (!arg)
	return help("poison");

    if (sscanf(arg, "%s %s %s", weap, with, pois) != 3 || with != "with")
    {
	write("Poison what with what?\n");
	return 1;
    }

    if (!(weap_ob = present(weap)))
    {
	write("You have no " + weap + ".\n");
	return 1;
    }

    if (!(pois_ob = present(pois)))
    {
	write("You have no " + pois + ".\n");
	return 1;
    }

    if (!pois_ob->query_poison())
    {
	write("The " + pois_ob->query_name() + " is no poison.\n");
	return 1;
    }

    if (weap_ob->poison_shadow())
    {
	write("You fumble, and pour the " + pois_ob->query_name() 
	  + " on the ground.\n");
	return 1;
    }

    write("You pour " + pois_ob->query_name() + " over " + weap_ob->short() + ".\n");
    say(capitalize(thief->query_name()) + " pours " + pois_ob->query_name()
      + " over " + weap_ob->short() + ".\n");
    pois_ob->dec_doses();

    if (weap_ob->query_weapon())
    {
	i = pois_ob->query_strength();
	shad = clone_object(dir + "/poison_shadow");
	shad->start_shadow(weap_ob, i * 600 / 50, i);
    }
    return 1;
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Sneak =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int sneak(string arg)
{
    object          ob;

    if (thief->query_ghost())
    {
	write("You could move through walls, you don't need to sneak.\n");
	return 1;
    }

    CHK_ATT();

    if (!arg)
	return help("sneak");

    switch (arg)
    {
    case "n":	arg = "north";	     break;
    case "s":	arg = "south";       break;
    case "w":	arg = "west";        break;
    case "e":	arg = "east";	     break;
    case "u":	arg = "up";	     break;
    case "d":	arg = "down";	     break;
    case "nw":	arg = "northwest";   break;
    case "ne":	arg = "northeast";   break;
    case "sw":	arg = "southwest";   break;
    case "se":	arg = "southeast";   break;
    }

    if (!thief->query_invis())
    {
	write("You would be noticed.\n");
	return 1;
    }

    if (environment(thief)->move(arg))
	return 1;

    ob = present("castle", environment(thief));
    if (ob = present("castle", environment(thief)) && ob->move(arg))
	return 1;
    write("You bang your head.\n");
    thief->reduce_hit_point(random(20) + 1);
    return 1;
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Steal +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int steal(string arg)
{
    string          what, whom;
    object          obji, objp;
    int             i, ddex;
    int             coins;

    if (has_stolen)
	return 1;

    if (thief->query_ghost())
    {
	write("You are no longer interested in the material world.\n");
	return 1;
    }

    CHK_ATT();

    if (!arg || !(sscanf(arg, "%s from %s", what, whom) == 2))
	return help("steal");
    if (!(objp = present(whom, environment(thief))))
    {
	write("There is no " + whom + " present.\n");
	return 1;
    }
    if (!living(objp))
    {
	write("You attempt to steal "+arg+" but aren't very "
	  + "effective.\n"); 
	return 1;
    }
    if (what == "money")
	what == "coins";
    if (what != "coins" && !(obji = present(what, objp)))
    {
	write(capitalize(whom) + " doesn't posses such an item.\n");
	return 1;
    }
    if (objp->query_immortal()) /* changed by Moonchild, could steal from 31 */
    {
	write("You cannot steal from wizards.\n");
	return 1;
    }
    if (objp->query_linkdeath())
    {
	write("You cannot steal from " + objp->query_name() + ", " +
	  objp->query_pronoun() + " is stoned.\n");
	return 1;
    }
    if (what == "bag" && dex <= LV_STBAG)/* Ok if high enough */
    {
	write(objp->query_name()+" would notice if you stole that.\n");
	return 1;
    }
    if (environment(thief)->query_property("no_steal"))
    {
	write("Your stealing would be recognized in this room.\n");
	return 1;
    }
    if (objp->query_no_steal())
    {
	write(objp->short() + " doesn't look like one whom you can steal from.\n");
	return 1;
    }

    /*
    * Compute the random value according to the following rules: if two
    * players are of the same level, the thief gets a change of 50:50 that
    * he can success in stealing. if the thief is GM->max_levels - 1
    * dex-levels above his victim, he gets a chance of 99 % that he will
    * succeed in stealing.
    */

    has_stolen = 1;
    ddex = (dex - objp->query_dex()) * 50 / 
    (max_stats - 1) + 50;
    if (random(101) >= ddex)
    {	                              /* Steal fails */
	say(thief->query_name() + " tried to steal " + what + " from " + objp->query_name() + ".\n", objp);
	write(objp->query_name() + " notices your attempt!\n");
	if (objp->query_npc())
	{
	    write(objp->query_name() + " attacks!\n");
	    objp->attack_object(thief);
	    return 1;
	}
	tell_object(objp, thief->query_name() + " tried to steal " + what + " from you!\n");
	return 1;
    }

    /* =+= =+= =+= =+= =+= =+= =+= =+= Coins =+= =+= =+= =+= =+= =+= =+= =+= =+= */

    if (what == "coins")
    {
	coins = objp->query_money();
	if (coins > thief->query_level() * 100)
	    coins = thief->query_level() * 100;
	if (!coins)
	{
	    write(objp->query_name() + " doesn't posess a single coin.\n");
	    return 1;
	}

	coins = random(coins) + 1;
	thief->add_money(coins);
	objp->add_money(-coins);
	write("You have stolen " + coins + " coins from " + objp->query_name() + ".\n");
	i = random(4);
	if (!thief->query_invis())
	    switch (i)
	{
	case 0:
	    tell_object(objp, "There is a rustling noise in your purse.\n");
	    break;
	case 1:
	    tell_object(objp, "You feel your purse getting lighter.\n");
	    break;
	case 2:
	    tell_object(objp, "You feel a hand in your pocket.\n");
	    break;
	case 3:
	    tell_object(objp, "You feel a soft touch in your pocket.\n");
	    break;
	}
	thief->add_alignment(AL_STEALMONEY);	/* Thieves are nasty */
	return 1;
    }

    /* =+= =+= =+= =+= =+= =+= =+= =+= Objects =+= =+= =+= =+= =+= =+= =+= =+= */

    if (obji->query_wielded(obji))
    {
	write("You can't steal wielded stuff.\n");
	return 1;
    }

    if (obji->query_worn(obji))
    {
	write("You can't undress " + objp->query_name() + ".\n");
	return 1;
    }

    if (!(i = transfer(obji, thief)))
    {
	i = random(4);
	if (!thief->query_invis())
	    switch (i)
	{
	case 0:
	    tell_object(objp, "You feel like you might missing something.\n");
	    break;
	case 1:
	    tell_object(objp, "You seem to have lost a " + what + ".\n");
	    break;
	case 2:
	    tell_object(objp, "You feel a soft touch on your body.\n");
	    break;
	case 3:
	    tell_object(objp, "You are missing a " + what + ".\n");
	    break;
	}
	write("You have stolen " + what + " from " + objp->query_name() + ".\n");
	thief->add_alignment(AL_STEALITEM);/* They ARE nasty ... */
	return 1;
    } else {
	if (i == 1)
	    write("You can't carry any more.\n");
	else
	    write("You cannot steal the " + what + " from " + objp->query_name() + ".\n");
	return 1;
    }
}

void quit()
{
    if (dont_hide)
	thief->setenv("TH_DHIDE", dont_hide);
    else
	thief->setenv("TH_RHIDDEN", remain_hidden);
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int dump_vars()
{
    write(thief);
    write("\n" + 
      "dex:           "           + dex + "\n" + 
      "max_stats:     "     + max_stats + "\n" + 
      "stashed:       "       + stashed + "\n" + 
      "th_xlook:      "      + th_xlook + "\n" + 
      "gm_id:         "         + gm_id + "\n" +    
      "dir:           "           + dir + "\n" + 	
      "gd:            "            + gd + "\n" +        
      "helpdir:       "       + helpdir + "\n" + 
      "hideout:       "       + hideout + "\n" + 
      "att:           "           + att + "\n" + 		
      "remain_hidden: " + remain_hidden + "\n" + 
      "dont_hide:     "     + dont_hide + "\n" +  
      "rv_lock:       "       + rv_lock + "\n" +  
      "has_stolen:    "    + has_stolen + "\n");
    return 1;
}

