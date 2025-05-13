
/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+= The Thief Soul=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

#define GM             "guild/master"
#define CD             "sys/chatd"
#define GUILD          "thief"

#define MAX_HIDDEN     900                                     /* 15 minutes */
#define BE_HIDDEN      (MAX_HIDDEN * this_player()->query_dex())

#define POISON         dir + "/poison_shadow"

#define AL_STEALMONEY  -10                        /*  alignment: steal money */
#define AL_STEALITEM   -50                        /*             steal item  */
#define LV_STBAG        25                        /* level for stealing bags */

#define CHK_ATT(); \
if ((att=this_player()->query_attack()) &&\
    present(att,environment(this_player()))) {\
   write("You are much too busy to do that.\n");\
   return 1;\
}

#include "/obj/lw.h"

int             stashed;
static int      max_stats;
static int      gd;

string          extra_look_str;	                        /* extra_look string */
static string   id;                                     /*        guild soul */
static string   dir;		                        /*   guild directory */
static string   helpdir;	                        /*     guild helpdir */
static string   hideout;	                        /*     guild hideout */

static object   att;		                        /*  Global: attacker */

int             disguises;
static int      max_disguises;

static int      is_hidden;
static int      stay_hidden;
static int      dont_hide;
static int      rv_lock;                	        /*    to lock reveal */

static int      has_stolen;

static object   hide;                                   /*      room we left */

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

drop()
{
    return 1;
}

extra_look()
{
    if (!extra_look_str)
	set_extra_look(capitalize(this_player()->query_pronoun())
	  + " slips through the shadows with a remarkable grace");
    return extra_look_str;
}

get()
{
    return 1;
}

id(str)
{
    if (str == id || str == "tools" || str == "case")
	return 1;
}

long()
{
    if (!stashed) {
	write("This case contains some tools you need.\n");
	return 1;
    }
}

short()
{
    if (!stashed)
	return "A small, slim case";
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

reset(arg)
{
    if (!intp(is_hidden))
	is_hidden = 0;
    if (arg)
	return;
    gd = GM->query_number(GUILD);
    max_stats = GM->query_levels(gd);
    id = GM->query_id(gd);
    dir = GM->query_dir(gd);
    helpdir = "/" + dir + "/helpdir";
    hideout = dir + "/hideout";
    disguises = 0;
}

init()
{
    object shad;

    restore_object(dir + "/thieves/" + this_player()->query_real_name());

    if (!this_player())
	return;

    if (!this_player()->crit_shadow())
    {
	shad = clone_object(dir + "/crit_shadow");
	shad->start_shadow(this_player(),0,"crit_shadow");
    }

    if (!this_player()->dodge_shadow())
    {
	shad = clone_object(dir + "/dodge_shadow");
	shad->start_shadow(this_player(),0,"dodge_shadow");
    }

    stay_hidden = BE_HIDDEN;          /* max time allowed to hide 45 minutes */
    add_action("backstab", "backstab");
    add_action("disguise", "disguise");
    add_action("fail_spell","fireball");
    add_action("help", "help");
    add_action("hide", "hide");
    add_action("hideout", "hideout");
    add_action("leave", "leave");
    add_action("fail_spell","missile");
    add_action("picklock", "picklock");
    add_action("poison", "poison");
    add_action("reveal", "reveal");
    add_action("fail_spell","shock");
    add_action("sneak", "sneak");
    add_action("steal", "steal");
    add_action("guild_line", "thief");
    add_action("guild_line", "thief/");
    add_action("unhide", "unhide");
}

time_guild_soul()
{
    if (is_hidden == 1 && this_player()->query_invis())
	stay_hidden--;
    if (stay_hidden < 0)
    {
	stay_hidden = BE_HIDDEN;
	do_unhide();
    }
}

guild_changes()
{
    if (this_player()->crit_shadow())
    {
	if (this_player()->query_immortal())
	    write("Destructing the crit_shadow.\n");
	destruct(this_player()->crit_object());
    }

    if (this_player()->dodge_shadow())
    {
	if (this_player()->query_immortal())
	    write("Descructing the dodge_shadow.\n");
	destruct(this_player()->dodge_object());
    }
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

fail_spell()
{
    return help("spell");
}

guild_line(str)
{
    return this_player()->guild_line(str);
}

help(str)
{
    if (str == "guild")
	str = "thief";

    if (str == "levels")
	return list_levels();

    if (cat(helpdir + "/" + str))
	return 1;
    else
	return 0;
}

list_levels()
{
    GM->list_levels(gd);
    return 1;
}

recognize_fight()
{
    int dex;

    dex = this_player()->query_dex();


    if (this_player()->query_invis()) {
	write("You come out of the shadows.\n");
	this_player()->set_vis();
    }

    if (is_hidden == 1)
	is_hidden = 0;

    // thieves are quick
    if (random(80) < dex)
	this_player()->attack();
    if (random(50) < dex)
	this_player()->attack();
    if (random(25) < dex)
	this_player()->attack();
}

save_soul()
{
    save_object(dir + "/thieves/" + this_player()->query_real_name());
    return 1;
}

set_extra_look(str)
{
    extra_look_str = str;
    save_soul();
    return 1;
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Backstab +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

backstab(str)
{
    object ob, weapon;

    weapon = this_player()->query_wielded();

    if (!str) 
	return help("backstab");

    if (!(ob = present(str, environment(this_player()))) || !living(ob))
	return notify_fail("Backstab whom?\n");

    if (!(objectp(weapon)))
	return notify_fail("Your attack would be more potent with a weapon in hand.\n");

    CHK_ATT();

    if (ob->query_attack(this_player()))
    {
	write(ob->query_name()
	  + " is obviously much too wary for that attack.\n");

	if (this_player()->query_invis())
	    return 1;
	else
	    ob->attack_object(this_player());
    }

    if (!this_player()->query_invis()) {
	write("You move carefully toward " + ob->query_name()
	  + " but " + ob->query_pronoun() + " notices your approach!\n");
	ob->attack_object(this_player());
	ob->attack();
	return 1;
    }

    write("You carefully move behind " + ob->query_name() + ".\n");
    call_out("fcn_success",2,ob);

    return 1;
}

int fcn_success(object ob)
{
    int dam;

    if (!ob) return 0;
    write("You attack " + ob->query_objective() + " mercilessly.\n");
    dam = (600 * this_player()->query_level() * 3 * 
      (this_player()->query_dex()/10+1) /360);
    if ( (ob->query_hp() / 4) > dam )
	dam = ob->query_hp() / 4;
    this_player()->add_exp(ob->hit_player(dam, 7));
    return 1;
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Disguise +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

disguise(str)
{
    string          option, option2;

    max_disguises = (this_player()->query_chr() / 7) + 1;

    if (this_player()->query_invis())
	return notify_fail("You must be able to see yourself to put on an "
	  + "adequate disguise.\n");

    if (!str || sscanf(str, "%s %s", option, option2) != 2) 
	return help("disguise");

    if (disguises >= max_disguises)
	return notify_fail("Your supplies have been exhausted.\n");

    switch(option)
    {
	int             gn, lev, gender;
	string          pretitle, title;

    case "appearance":
	set_extra_look(option2);
	break;
    case "title":
	gn = GM->query_number(option2);
	lev = this_player()->query_level();
	gender = this_player()->query_gender();

	if (gn == -1)
	    return notify_fail("What guild?\n");
	if (!(pretitle = GM->query_pretitle(gn, lev, gender)))
	    pretitle = "none";
	if (!(title = GM->query_title(gn, lev, gender)))
	    title = "none";

	this_player()->set_pretitle(pretitle);
	this_player()->set_title(title);
	break;
    default:
	return help("disguise");
	break;
    }

    disguises += 1;
    write("You pull some supplies from your case, then apply some make-up,\n"
      + "adjust your stance, and change your mannerisms.\n");
    say(lw(capitalize(this_player()->query_name()) + " applies some make-up "
	+ "and stands differently.  You can barely recognize "
	+ this_player()->query_objective()) + ".\n");
    save_soul();
    return 1;
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Hide =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

hide(str)
{
    object          ob, en, sh;
    int inv_lvl;

    if (str) {			                           /* hide an object */

	if (this_object()->id(str))  {                /* hide the guild soul */
	    if (stashed)
		write("Your tools are safely hidden already.\n");
	    else {
		write("You hide your tools from prying eyes.\n");
		stashed = 1;
	    }
	    save_soul();
	    return 1;
	}

	if (!(ob = present(str, this_player())) &&
	  !(ob = present(str, environment(this_player()))))
	    return notify_fail("Hide what ?\n");

	if (living(ob))
	    return notify_fail(ob->short() + " moves too much to be hidden.\n");

	if (ob->id("castle") || ob->query_property("no_hide"))
	    return notify_fail(ob->short() + " is too big to be hidden.\n");

	if (environment(ob)==this_player() && (en=environment(this_player())))
	    transfer(ob, en);	                                  /* drop it */

	sh = clone_object(dir + "/hide_shadow");
	sh->start_shadow(ob,0,"hide_shadow",str);

	say(this_player()->query_name() + " hides something.\n");
	write("Ok.\n");
	return 1;
    }

    /* hide yourself */

    if (environment(this_player())->query_property("no_hide"))
	return notify_fail("You can't find a place to hide here.\n");

    if (is_hidden == 1 && this_player()->query_invis())
	return notify_fail("You're already hidden in the shadows.\n");

    if (this_player()->query_ghost())
	return notify_fail("You're already pretty well hidden.\n");

    CHK_ATT();

    if (stay_hidden < 0)                                     /* for backstab */
    {
	write("You must wait for a while.\n");
	if (!find_call_out("allow_hide"))
	    call_out("allow_hide",10);
	return 1;
    }

    write("You hide in the shadows.\n");
    is_hidden = 1;
    say(this_player()->query_name() + " leaves suddenly.\n");

    inv_lvl = (this_player()->query_level() + this_player()->query_dex())/2
    + random(10) - 5;
    if (inv_lvl < 5)
	inv_lvl = 5;
    if (!random(60 - inv_lvl))
	this_player()->set_invis();
    else
	this_player()->set_invis(inv_lvl);
    return 1;
}

void allow_hide()
{
    if (stay_hidden < 0)
	stay_hidden = this_player()->query_dex();
}

reveal(str)
{

    if (!str)
	return help("reveal");

    if (this_object()->id(str))  {
	if (!stashed)
	    write("Your tools are already in plain sight.\n");
	else {
	    write("You put your tools in plain sight.\n");
	    stashed = 0;
	}
	save_soul();
	return 1;
    }

    CHK_ATT();

    if (rv_lock) {
	write("You continue searching.\n");
	return 1;
    }
    write("You start searching ...\n");
    say(this_player()->query_name() + " searches the room.\n");
    rv_lock = 1;		                     /* searching takes time */
    call_out("reveal_item", 3, str);
    return 1;

}

/*
 * with full dexterity, the probabilty to find an item is 50 %, but there's a
 * check against charisma (used as luck) also.
 */

reveal_item(string str)
{
    object          ob, sh;
    int             i, dx, ch;

    rv_lock = 0;

    ob = present(str + "__hidden__", environment(this_player()));
    if (!ob || environment(this_player()) != environment(ob)) {
	write("You found nothing.\n");
	return;
    }
    dx = this_player()->query_dex();
    ch = this_player()->query_chr();
    i = random(2 * max_stats);
    if (i > dx) {		/* check for luck */
	if (i <= 2) {
	    i = random(100);	/* 30% max chance */
	    if (i < ch)
		i = 1;
	    else
		i = 0;
	} else
	    i = 0;
    } else
	i = 1;

    if (i) {
	if (ob->hide_shadow())
	    ob->end_shadow();
	write("You found " + ob->short() + ".\n");
	say(this_player()->query_name() + " found something.\n");
	return;
    }
    write("You found nothing.\n");
    return;
}

unhide()
{
    if (this_player()->query_ghost())
	return notify_fail("You try to show yourself to mortal men.\n");
    if (!this_player()->query_invis())
	return notify_fail("You are not hiding.\n");

    do_unhide();
    return 1;
}

int do_unhide()
{
    this_player()->set_vis();
    is_hidden = 0;
    move_object(this_player(), environment(this_player()));
    tell_room(environment(this_player()),
      this_player()->query_name() + " " +
      this_player()->query_msgin() + ".\n");
    return 1;
}

timer() {
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Hideout =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

hideout()
{
    if (file_name(environment(this_player())) == hideout) 
	return notify_fail("Your keen thief senses compel you to examine your "
	  + "surroundings.\n");
    if (environment(this_player())->has_drink(this_player()))
	return notify_fail("You are not allowed to leave with drinks!\n");
    if (environment(this_player())->query_property("no_teleport"))
	return notify_fail("As you try to leave this place you run into an " +
	  "invisible barrier.\n");

    hide = environment(this_player());
    this_player()->move_player("X#" + hideout);
    return 1;
}

leave(str)
{

    if (str)
	return;
    if (file_name(environment(this_player())) != hideout)
	return notify_fail("You don't want to go quite yet.\n");
    if (hide)
	this_player()->move_player("X", hide);
    else  /* object was destructed */
	this_player()->move_player("X#" + GM->query_room(gd));	
    write("You have returned.\n");
    return 1;
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Picklock +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

picklock(str)
{
    object          pl, door;
    int             i, num_doors;
    string          dest;

    if (this_player()->query_ghost())
	return notify_fail("You could probably move right through that keyhole.\n");

    CHK_ATT();

    if (!str)
	return help("picklock");
    if (str != "door" && sscanf(str, "%s door", dest) != 1)
	return;
    if (!(pl = present("picklock", this_player())))
	return notify_fail("You don't have a picklock.\n");
    if (pl->query_broken()) {	/* It was broken ... get the next one */
	pl = next_inventory(pl);
	while (pl) {
	    if (pl->id("picklock") && !pl->query_broken())
		break;		/* unbroken */
	    pl = next_inventory(pl);
	}
	if (!pl)
	    return notify_fail("Your picklock is broken.\n");
    }
    if (!(door = present(str, environment(this_player()))))
	return;
    if (str == "door" && (num_doors = door->number_of_doors()) != 1) {
	door->which_door();
	return 1;
    }
    if (!door->query_locked())
	return notify_fail("You wisely decide not to waste your picklock on an unlocked door.\n");
    i = this_player()->query_dex() * 100 / max_stats;
    if (random(101) >= i) {
	pl->set_broken();
	write("CRACK ! You brake the picklock with your bumbling fingers.\n");
	return 1;
    }
    write("You work the thin wire into the lock and after a few moments of"
      + " careful probing ...\nYou are met with success.");
    door->set_locked(0);
    door->query_partner_door()->set_locked(0);
    if (random(101) >= i) {
	pl->set_broken();
	write("  But your picklock broke.\n");
    }
    else write("\n");
    return 1;
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Poison =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

poison(str)
{
    string          wp, f, p;
    object          owp, ops, s, sh;
    int             i;

    if (!str)
	return help("poison");

    if (sscanf(str, "%s %s %s", wp, f, p) != 3 || f != "with")
	return notify_fail("Poison what with what?\n");

    if (!(owp = present(wp)))
	return notify_fail("You have no " + wp + ".\n");

    if (!(ops = present(p)))
	return notify_fail("You have no " + p + ".\n");

    if (!ops->query_poison())
	return notify_fail("The " + ops->query_name() + " is no poison.\n");

    if ((sh = shadow(owp, 0)) && explode(file_name(sh), "#")[0] = POISON)
	return notify_fail("You fumble, and pour the " + ops->query_name() 
	  + " on the ground.\n");

    write("You pour " + ops->query_name() + " over " + owp->short() + ".\n");
    say(capitalize(this_player()->query_name()) + " pours " + ops->query_name()
      + " over " + owp->short() + ".\n");
    ops->dec_doses();

    if (owp->query_weapon()) {
	i = ops->query_strength();
	s = clone_object(POISON);
	s->start_shadow(owp, i * 600 / 50, i);
    }
    return 1;
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Sneak =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

sneak(str)
{
    object          ob;

    if (this_player()->query_ghost())
	return notify_fail("You could move through walls, you don't need to sneak.\n");

    CHK_ATT();

    if (!str)
	return help("sneak");

    switch (str) {
    case "n":	str = "north";	     break;
    case "s":	str = "south";       break;
    case "w":	str = "west";        break;
    case "e":	str = "east";	     break;
    case "u":	str = "up";	     break;
    case "d":	str = "down";	     break;
    case "nw":	str = "northwest";   break;
    case "ne":	str = "northeast";   break;
    case "sw":	str = "southwest";   break;
    case "se":	str = "southeast";   break;
    }

    if (!this_player()->query_invis())
	return notify_fail("You would be noticed.\n");

    if (environment(this_player())->move(str))
	return 1;

    ob = present("castle", environment(this_player()));
    if (ob = present("castle", environment(this_player())) && ob->move(str))
	return 1;
    write("You bang your head.\n");
    this_player()->reduce_hit_point(random(20) + 1);
    return 1;

}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Steal +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

steal(str)
{
    string          what, whom;
    object          obji, objp;
    int             i, ddex;
    int             coins;

    if (has_stolen)
	return 1;

    if (this_player()->query_ghost())
	return notify_fail("You are no longer interested in the material world.\n");

    CHK_ATT();

    if (!str || !(sscanf(str, "%s from %s", what, whom) == 2))
	return help("steal");
    if (!(objp = present(whom, environment(this_player())))) {
	write("There is no " + whom + " present.\n");
	return 1;
    }
    if (!living(objp))
	return notify_fail("You attempt to steal "+str+" but aren't very "
	  + "effective.\n");
    if (what == "money")
	what == "coins";
    if (what != "coins" && !(obji = present(what, objp)))
	return notify_fail(capitalize(whom) + " doesn't posses such an item.\n");
    if (objp->query_immortal()) /* changed by Moonchild, could steal from 31 */
	return notify_fail("You cannot steal from wizards.\n");
    if (objp->query_linkdeath())
	return notify_fail("You cannot steal from " + objp->query_name() + ", " +
	  objp->query_pronoun() + " is stoned.\n");
    if (what == "bag" && this_player()->query_dex() <= LV_STBAG)/* Ok if high enough */
	return notify_fail(objp->query_name()+" would notice if you stole that.\n");
    if (environment(this_player())->query_property("no_steal"))
	return notify_fail("Your stealing would be recognized in this room.\n");
    if (objp->query_no_steal())
	return notify_fail(objp->short() + " doesn't look like one whom you can steal from.\n");

    /*
    * Compute the random value according to the following rules: if two
    * players are of the same level, the thief gets a change of 50:50 that
    * he can success in stealing. if the thief is GM->max_levels - 1
    * dex-levels above his victim, he gets a chance of 99 % that he will
    * succeed in stealing.
    */

    has_stolen = 1;
    call_out("has_stolen", 1, 0);	       /* Moonchild stop macro abuse */
    ddex = (this_player()->query_dex() - objp->query_dex()) * 50 / 
    (max_stats - 1) + 50;
    if (random(101) >= ddex) {	                              /* Steal fails */
	say(this_player()->query_name() + " tried to steal " + what + " from " + objp->query_name() + ".\n", objp);
	write(objp->query_name() + " notices your attempt!\n");
	if (objp->query_npc()) {
	    write(objp->query_name() + " attacks!\n");
	    objp->attack_object(this_player());
	    return 1;
	}
	tell_object(objp, this_player()->query_name() + " tried to steal " + what + " from you!\n");
	return 1;
    }

    /* =+= =+= =+= =+= =+= =+= =+= =+= Coins =+= =+= =+= =+= =+= =+= =+= =+= =+= */

    if (what == "coins") {
	coins = objp->query_money();
	if (coins > this_player()->query_level() * 100)
	    coins = this_player()->query_level() * 100;
	if (!coins)
	    return notify_fail(objp->query_name() + " doesn't posess a single coin.\n");

	coins = random(coins) + 1;
	this_player()->add_money(coins);
	objp->add_money(-coins);
	write("You have stolen " + coins + " coins from " + objp->query_name() + ".\n");
	i = random(4);
	if (!this_player()->query_invis())
	    switch (i) {
	case 0:
	    tell_object(objp, "There is a rustling noise in your purse.\n");
	    break;
	case 1:
	    tell_object(objp, "You feel your purse is getting lighter.\n");
	    break;
	case 2:
	    tell_object(objp, "You feel a hand in your pocket.\n");
	    break;
	case 3:
	    tell_object(objp, "You feel a soft touch in your pocket.\n");
	    break;
	}
	this_player()->add_alignment(AL_STEALMONEY);	/* Thieves are nasty */
	return 1;
    }

    /* =+= =+= =+= =+= =+= =+= =+= =+= Objects =+= =+= =+= =+= =+= =+= =+= =+= */

    if (obji->query_wielded(obji))
	return notify_fail("You can't steal wielded stuff.\n");

    if (obji->query_worn(obji))
	return notify_fail("You can't undress " + objp->query_name() + ".\n");

    if (!(i = transfer(obji, this_player()))) {
	i = random(4);
	if (!this_player()->query_invis())
	    switch (i) {
	case 0:
	    tell_object(objp, "You feel like you are missing something.\n");
	    break;
	case 1:
	    tell_object(objp, "You seem to have lost a " + what + ".\n");
	    break;
	case 2:
	    tell_object(objp, "You feel a soft touch on your body.\n");
	    break;
	case 3:
	    tell_object(objp, "You are just missing a " + what + ".\n");
	    break;
	}
	write("You have stolen " + what + " from " + objp->query_name() + ".\n");
	this_player()->add_alignment(AL_STEALITEM);	/* They ARE nasty ... */
	return 1;
    } else {
	if (i == 1)
	    write("You can't carry any more.\n");
	else
	    write("You cannot steal the " + what + " from " + objp->query_name() + ".\n");
	return 1;
    }
}

has_stolen() {   has_stolen = 0;  }

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

