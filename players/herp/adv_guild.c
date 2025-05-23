#define GUILD	0				/* adventurers guild */
#define GM	"guild/master"
#define TP	this_player()

#include "std.h"
#include "tune.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define SAY(x); tell_room(environment(this_player()),x+"\n");

int guild;
extra_reset(arg) {
    object ob;
    if (arg)
	return;
    guild=GUILD;
    move_object("obj/book", this_object());
    move_object(clone_object("obj/bull_board"), this_object());
    ob = clone_object("obj/quest_obj");
    call_other(ob, "set_name", "orc_slayer");
    call_other(ob, "set_hint",
"Retrieve the Orc slayer from the evil orc shaman, and give it to Leo.\n");
    move_object(ob, "room/quest_room");
}

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("cost_for_level", "cost");\
    add_action("advance", "advance");\
    add_action("south", "south");\
    add_action("banish", "banish");\
    add_action("list_quests", "list");

ONE_EXIT("room/vill_road2", "north",
	 "The adventurers guild",
	 "You have to come here when you want to advance your level.\n" +
	 "You can also buy points for a new level.\n" +
	 "Commands: cost, advance [level, str, dex, int, con], list (number).\n" +
	 "There is an opening to the south, and some shimmering\n" +
	 "blue light in the doorway.\n", 1)

int next_level;
int next_exp;
int this_exp;
int level;
int exp;
string title;         /* now with arrays. :) */
object player_ob;
string banished_by;

/* some minor changes by Iggy. */
/* get level asks get_next_exp() and  get_next_title() */

get_level(str)
{
	level = str;
 
	if (level<=1) this_exp=0;
	else this_exp=get_next_exp(level-1);
 
	next_exp   = get_next_exp(level);
	next_level = level + 1 ;   
	title      = get_new_title(level);
}    

string male_title_str, fem_title_str, neut_title_str;
/*xxx  return title */
get_new_title(str)
{
    if (!male_title_str){
	male_title_str = allocate(20);
	
	male_title_str[19]	="the apprentice Wizard";
	male_title_str[18]	="the grand master sorcerer";
	male_title_str[17]	="the master sorcerer";
	male_title_str[16]	="the apprentice sorcerer";
	male_title_str[15]	="the warlock";
	male_title_str[14]	="the enchanter";
	male_title_str[13]	="the magician";
	male_title_str[12]	="the apprentice magician";
	male_title_str[11]	="the conjurer";
	male_title_str[10]	="the champion";
	male_title_str[9]	="the warrior";
	male_title_str[8]	="the great adventurer";
	male_title_str[7]	="the experienced adventurer";
	male_title_str[6]	="the small adventurer";
	male_title_str[5]	="the experienced fighter";
	male_title_str[4]	="the small fighter";
	male_title_str[3]	="the master ranger";
	male_title_str[2]	="the lowrank ranger";
	male_title_str[1]	="the simple wanderer";
	male_title_str[0]	="the utter novice";

	fem_title_str = allocate(20);

	fem_title_str[19]	="the apprentice Wizard";
	fem_title_str[18]	="the grand master sorceress";
	fem_title_str[17]	="the master sorceress";
	fem_title_str[16]	="the apprentice sorceress";
	fem_title_str[15]	="the witch";
	fem_title_str[14]	="the enchantress";
	fem_title_str[13]	="the magicienne";
	fem_title_str[12]	="the apprentice magicienne";
	fem_title_str[11]	="the conjuress";
	fem_title_str[10]	="the deadly amazon";
	fem_title_str[9]	="the amazon";
	fem_title_str[8]	="the great adventuress";
	fem_title_str[7]	="the experienced adventuress";
	fem_title_str[6]	="the small adventuress";
	fem_title_str[5]	="the charming siren";
	fem_title_str[4]	="the siren";
	fem_title_str[3]	="the master ranger";
	fem_title_str[2]	="the lowrank ranger";
	fem_title_str[1]	="the simple wanderer";
	fem_title_str[0]	="the utter novice";

	neut_title_str = allocate(20);

	neut_title_str[19]	="the apprentice Wizard";
	neut_title_str[18]	="the ferocious tyrannosaur";
	neut_title_str[17]	="the small tyrannosaur";
	neut_title_str[16]	="the vicious dragon";
	neut_title_str[15]	="the devious dragon";
	neut_title_str[14]	="the small dragon";
	neut_title_str[13]	="the powerful demon";
	neut_title_str[12]	="the small demon";
	neut_title_str[11]	="the beholder";
	neut_title_str[10]	="the great monster";
	neut_title_str[9]	="the experienced monster";
	neut_title_str[8]	="the medium monster";
	neut_title_str[7]	="the small monster";
	neut_title_str[6]	="the threatening shadow";
	neut_title_str[5]	="the shadow";
	neut_title_str[4]	="the wraith";
	neut_title_str[3]	="the bugbear";
	neut_title_str[2]	="the furry creature";
	neut_title_str[1]	="the simple creature";
	neut_title_str[0]	="the utter creature";
    }
    if (!player_ob || !player_ob->query_gender())
	return neut_title_str[str];
    else if (player_ob->query_gender() == 1)
	return male_title_str[str];
    else
	return fem_title_str[str];
}


int exp_str;

/*  returns the next_exp. */
get_next_exp(str) {
int lvl;

#if 1
  if (intp(str)) lvl=str;
  else if (strinp(str)) sscanf(str,"%d",lvl);
  else lvl=0;
  lvl++;
/*
  return GM->query_exp(GUILD,++lvl);
*/
  SAY("adv: guild "+GUILD+" lvl "+lvl);
  SAY("GM says: "+GM->query_exp(GUILD,lvl));
#endif

/* This is obsolete, we now call the guild/master */

#if 0
    if(!exp_str){
	exp_str = allocate(20);
	
	exp_str[19]	= 1000000;
	exp_str[18]	=  666666; 
	exp_str[17]	=  444444;
	exp_str[16]	=  296296;
	exp_str[15]	=  197530;
	exp_str[14]	=  131687;
	exp_str[13]	=   97791;
	exp_str[12]	=   77791;
	exp_str[11]	=   58527;
	exp_str[10]	=   39018;
	exp_str[9]	=   26012;
	exp_str[8]	=   17341;
	exp_str[7]	=   11561;
	exp_str[6]	=    7707;
	exp_str[5]	=    5138;
	exp_str[4]	=    3425;
	exp_str[3]	=    2283;
	exp_str[2]	=    1522;
	exp_str[1]	=    1014;
	exp_str[0]	=     676;
    }
    if (str>19) str=19;
 SAY("ADV says: "+exp_str[str]);
    return exp_str[str];
#endif
}

/*
 * This routine is called by monster, to calculate how much they are worth.
 * This value should not depend on the tuning.
 */
query_cost(l) {
    player_ob = this_player();
    level = l;
    if (level >= 20)
	return 1000000;
    get_level(level);
    return next_exp;
}

/*
* Special function for other guilds to call. Arguments are current level
 * and experience points.
 */
query_cost_for_level(l, e) {
    level = l;
    exp = e;
    get_level();
    if (next_exp <= exp)
	return 0;
    return (next_exp - exp) * 1000 / EXP_COST;
}

cost_for_level()
{
    int cost;

    player_ob = this_player();
    level = call_other(player_ob, "query_level", 0);

    cost = raise_cost(player_ob->query_str());
    if (cost)
	write("Str: " + cost + " experience points.\n");
    else
	write("Str: Not possible.\n");

    cost = raise_cost(player_ob->query_con());
    if (cost)
	write("Con: " + cost + " experience points.\n");
    else
	write("Con: Not possible.\n");

    cost = raise_cost(player_ob->query_dex());
    if (cost)
	write("Dex: " + cost + " experience points.\n");
    else
	write("Dex: Not possible.\n");

    cost = raise_cost(player_ob->query_int());
    if (cost)
	write("Int: " + cost + " experience points.\n");
    else
	write("Int: Not possible.\n");

    cost = raise_cost(player_ob->query_wis());
    if (cost)
	write("Wis: " + cost + " experience points.\n");
    else
	write("Wis: Not possible.\n");

    cost = raise_cost(player_ob->query_chr());
    if (cost)
	write("Chr: " + cost + " experience points.\n");
    else
	write("Chr: Not possible.\n");

    if (level >= 20) {
	write("You will have to seek other ways.\n");
	return 1;
    }
    exp = call_other(player_ob, "query_exp", 0);
    get_level(level);
    if (next_exp <= exp) {
	write("It will cost you nothing to be promoted.\n");
	return 1;
    }
    write("It will cost you "); write((next_exp - exp) * 1000 / EXP_COST);
    write(" gold coins to advance to level "); write(next_level);
    write(".\n");
    return 1;
}

advance(arg)
{
    string name_of_player;
    int cost;

    if (this_player()->query_guild()) {
        write("You don't belong to this guild, you may not advance here.\n");
        return 1;
    }

    if (arg == "con")
    {
	raise_con();
	return 1;
    }

    if (arg == "dex")
    {
	raise_dex();
	return 1;
    }

    if (arg == "int")
    {
	raise_int();
	return 1;
    }

    if (arg == "str")
    {
	raise_str();
	return 1;
    }

    if (arg == "wis")
    {
	raise_wis();
	return 1;
    }

    if (arg == "chr")
    {
	raise_chr();
	return 1;
    }

    if (arg && arg != "level")
	return 0;

    player_ob = this_player();
    name_of_player = call_other(player_ob, "query_name", 0);
    level = call_other(player_ob, "query_level", 0);
    if (level == -1)
	level = 0;
    exp = call_other(player_ob, "query_exp", 0);
    title = call_other(player_ob, "query_title", 0);
    if (level >= 20) {
	write("You are still "); write(title); write("\n");
	return 1;
    }
    get_level(level);
    if (next_level == 20 && call_other("room/quest_room", "count", 0))
	return 1;
    if (level == 0)
	next_exp = exp;
    cost = (next_exp - exp) * 1000 / EXP_COST;
    if (next_exp > exp) {
	if (call_other(player_ob, "query_money", 0) < cost) {
	    write("You don't have enough gold coins.\n");
	    return 1;
	}
        
        if (exp < this_exp + ((next_exp - this_exp) * 9) / 10) { /* 90% from diff  to next level needed */
	   write("You have to be closer to your next level.\n");
	   return 1;
	} 
        call_other(player_ob, "add_money", - cost);
    }
    say(call_other(player_ob, "query_name", 0) + " is now level " +
	next_level + ".\n");
    call_other(player_ob, "set_level", next_level);
    call_other(player_ob, "set_title", title);
    if (exp < next_exp)
        call_other(player_ob, "add_exp", next_exp - exp);
    if (next_level < 7) {
	write("You are now " + name_of_player + " " + title +
	      " (level " + next_level + ").\n");
	return 1;
    }
    if (next_level < 14) {
	write("Well done, " + name_of_player + " " + title +
	      " (level " + next_level + ").\n");
	return 1;
    }
    if (next_level < 20) {
	write("Welcome to your new class, mighty one.\n" +
	      "You are now " + title + " (level " + next_level + ").\n");
    }
    if (next_level == 20) {
	write("A new Wizard has been born.\n");
	shout("A new Wizard has been born.\n");
	return 1;
    }
    return 1;
}

raise_con()
{
    int lvl;

    if (too_high_average())
	return;
    lvl = this_player()->query_con();
    if (lvl >= 20) {
	alas("tough and endurable");
	return;
    }
    if (raise_cost(lvl, 1))
    {
	this_player()->set_con(lvl + 1);
	write("Ok.\n");
    }
    else
	write("You don't have enough experience.\n");
}

raise_dex()
{
    int lvl;

    if (too_high_average())
	return;
    lvl = this_player()->query_dex();
    if (lvl >= 20) {
	alas("skilled and vigorous");
	return;
    }
    if (raise_cost(lvl, 1))
    {
	this_player()->set_dex(lvl + 1);
	write("Ok.\n");
    }
    else
	write("You don't have enough experience.\n");
}

raise_int()
{
    int lvl;

    if (too_high_average())
	return;
    lvl = this_player()->query_int();
    if (lvl >= 20) {
	alas("knowledgeable and wise");
	return;
    }
    if (raise_cost(lvl, 1))
    {
	this_player()->set_int(lvl + 1);
	write("Ok.\n");
    }
    else
	write("You don't have enough experience.\n");
}

raise_str()
{
    int lvl;

    if (too_high_average())
	return;
    lvl = this_player()->query_str();
    if (lvl >= 20) {
	alas("strong and powerful");
	return;
    }
    if (raise_cost(lvl, 1))
    {
	this_player()->set_str(lvl + 1);
	write("Ok.\n");
    }
    else
	write("You don't have enough experience.\n");
}

raise_wis()
{
     int lvl;
     if (too_high_average())
	return;
     lvl = this_player()->query_wis();
     if (lvl >= 20) {
	alas("wise and salomonic");
	return;
     }
     if (raise_cost(lvl, 1))
     {
	this_player()->set_wis(lvl + 1);
	write("Ok.\n");
     }
     else
	write("You don't have enough experience.\n");
}    

raise_chr()
{
     int lvl;
     if (too_high_average())
	return;
     lvl = this_player()->query_chr();
     if (lvl >= 20) {
	alas("charismatic and heroic");
	return;
     }
     if (raise_cost(lvl, 1))
     {
	this_player()->set_chr(lvl + 1);
	write("Ok.\n");
     }
     else
	write("You don't have enough experience.\n");
}

/* 
 * Compute cost for raising a stat one level. 'base' is the level that
 * you have now, but never less than 1.
 */
raise_cost(base, action)
{
    int cost, saldo;

    if (base >= 20)
	return 0;
    cost = (get_next_exp(base) - get_next_exp(base - 1)) / STAT_COST;
    saldo = this_player()->query_exp() -
	get_next_exp(this_player()->query_level()- 1);
    if (action == 0)
	return cost;
    if (saldo < cost)
	return 0;
    this_player()->add_exp(-cost);
    return cost;
}

/*
 * Banish a monster name from being used.
 */
banish(who) {
    level = call_other(this_player(), "query_level");
    if (level < 21)
	return 0;
    if (!who) {
	write("Who ?\n");
	return 1;
    }
    if (!call_other(this_player(), "valid_name", who))
	return 1;
    if (restore_object("players/" + who)) {
	write("That name is already used.\n");
	return 1;
    }
    if (restore_object("banish/" + who)) {
	write("That name is already banished.\n");
	return 1;
    }
    banished_by = call_other(this_player(), "query_name");
    title = call_other(this_player(), "query_title");
    if (banished_by == "Someone") {
	write("You must not be invisible!\n");
	return 1;
    }
    save_object("banish/" + who);
    return 1;
}

south() {
    if (!TP->query_wizard()) {
	write("A strong magic force stops you.\n");
	say(call_other(this_player(), "query_name", 0) +
	    " tries to go through the field, but fails.\n");
	return 1;
    }
    write("You wriggle through the force field...\n");
    call_other(this_player(), "move_player", "south#room/adv_inner");
    return 1;
}

list_quests(num)
{
    int qnumber;
    if (num && (sscanf(num, "%d", qnumber) == 1))
	call_other("room/quest_room", "list", qnumber);
    else
	call_other("room/quest_room", "count", 0);
    return 1;
}

query_drop_castle() {
    return 1;
}

alas(what) {
    write("Sorry " + gnd_prn() + ", but you are already as " + what +
	  "\nas any");
    if (this_player()->query_gender() == 0)
	write("thing could possibly hope to get.\n");
    else
	write("one could possibly hope to get.\n");
}

/*
 * Check that the player does not have too high average of the stats.
 */
too_high_average() {
    if ((this_player()->query_con() + this_player()->query_str() +
	 this_player()->query_int() + this_player()->query_dex()) / 4 >=
            this_player()->query_level() + 3) {
	write("Sorry " + gnd_prn() +
	      ", but you are not of high enough level.\n");
	return 1;
    }
    return 0;
}

gnd_prn() {
    int gnd;
    
    gnd = this_player()->query_gender();
    if (gnd == 1) 
	return "sir";
    else if (gnd == 2)
	return "madam";
    else 
	return "best creature";
}
