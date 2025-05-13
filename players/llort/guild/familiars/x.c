inherit "secure/valid";
 
#define WIZ 1
#define ARCH 0
#define CName   (this_object()->query_name())
#define RM      "race/master"
#define RLM     "religion/master"
#define QR      "room/quest_room"
#define SM	"obj/skill_master"
#define CD	"sys/chatd"

#define DEF_START       "room/church"
#define MAX_POISON      40      
#define POISON_STATES   "barely/very weak/weakly/medium/strong/very strong/critical"
#define myself	this_object()
#define DEF_PROMPT ({ 0,0,0,0,0,0,0,1 })

#include "lw.h"
#include "log.h"
#include "levels.h"
#include "living.h"
#include "expander.c"
#include "who.c"
#include "env_var.c"
#include "mylook.c"
#ifdef MULTIGUILD
#include "guildspells.c"
#endif

 /* prototyping */
void set_cap_name();
static int quest_points;        /* calculated at login */
string pretitle;        /* Our official title. Wiz's can change it. */
string title;           /* Our official pretitle. Wiz's can change it. */
string al_title;
string real_al_title;
int is_linkdead;        /* The player is currently linkdead */
int intoxicated;        /* How many ticks to stay intoxicated. */
int stuffed;            /* How many ticks to stay stuffed */
int soaked;             /* How many ticks to stay soaked */
int poisoned;           /* How many ticks to stay poisoned */
static int ldead;       /* Checking if the player is linkdead -> destruct */
static string poisonname;  /* name of the poisonlevels */

int headache, max_headache;
int user_status;           /* a general use var. to remember certain stati */
	/* the usage is defined in /obj/user_status.h, please talk
	   to an archwiz if you need a bit in here */
static string guild_name,guild_wiz,guild_room;
static int apwz,fwz;    /* level of app.wiz, level of full.wiz */
string called_from_ip;  /* IP number was used last time */
string quests;          /* A list of all quests */
mixed *needed_quests;   /* A list of the quests we have to solve */
static int time_to_save;        /* Time to autosave. */
static object guild_soul;       /* Pointer to the guild soul if present */
 
static string saved_where;     /* Temp... */
static string link_return;      /* Where to return after a link fail */
string start_where;     /* room where to start from */
static string mailaddr;        /* Email address of player */
static string it;               /* Last thing referenced. */
int tot_value;          /* Saved values of this player. */
int stats_is_updated;
int *prompt;            /* how do we like the prompt? */
int bug_file_size;      /* Used to check if there are new reports waiting */
static int grouped;	/* are we grouped ? */
static string level_changed;

string religion; /* Cashimor, 250193, This could be interesting */
string explored; /* Cashimor, 030393, For alternative XP receiving */

static int actionVerb;     /* pat: which skill-action to performe */
static string actionArg;   /* pat: which argument for the action  */
static int releaseTime;    /* pat: when to perform the action     */
object oldie;

int incognito;

/* Some functions to access the user_status variable */
/* please use the defined variables in /obj/user_status.h */

query_user_status(stat) { return user_status & stat; }
set_user_status(stat) { user_status|=stat; }
clear_user_status(stat) { user_status &= (!stat); }
toggle_user_status(stat) { user_status ^= stat; }
 
query_msgin() { return "comes"; }
query_msgout() { return "goes"; }
query_mmsgin() { return "flips"; }
query_mmsgout() { return "flops"; }

logon(n) {
string fn;
int lv;
    oldie = this_player();
    write(exec(this_object(),this_player()));
    name = n;
    set_level(100);
    move_player_to_start3(start_where);
}
 
#define	CHUNK	(16)

static string more_file;	/* used by the more-command */
static int more_line;

more(str) {
    if (!str)
	return 0;
    if(str[0]=='~') str="/players/"+name+str[1..strlen(str)-1];
    more_file = str;
    more_line = 1;
    if (cat(more_file, more_line, CHUNK) == 0) {
	write("No such file\n");
	return 1;
    }
    input_to("even_more");
    write("More: (line " + (CHUNK + 1) + ") [u|d|q|enter] ");
    return 1;
}
 
static even_more(str) {
    if (str == "" || str == "d")
	more_line += CHUNK;
    else if (str == "q") {
	write("Ok.\n");
	return;
    } else if (str == "u") {
	more_line -= CHUNK;
	if (more_line < 1)
	    more_line = 1;
    }
    if (cat(more_file, more_line, CHUNK) == 0) {
	more_file = 0;
	write("EOF\n");
	return;
    }
    write("More: (line " + (more_line + CHUNK) + ") [u|d|q|enter] ");
    input_to("even_more");
}

/*
 * more_string
 * new routine to allow simple more'ing of a string e.g. bulletin boards
 * moonchild 210693
 */

static string *more_txt;
static int more_line;

more_string(str) {
  more_txt=explode(str, "\n");
  more_txt=more_txt[0..sizeof(more_txt)-2];
  more_line=0;
  more_string2();
}

static more_string2(str) {
  int i;
  if(str && lower_case(str[0..0])=="q") {
    more_txt=0;
    return;
  }
  if(sizeof(more_txt)>more_line+CHUNK) {
    for(i=more_line;i<more_line+CHUNK;i++)
      write(more_txt[i] + "\n");
    write("More? [q to quit] ");
    more_line+=CHUNK;
    input_to("more_string2");
    return;
  }
  else {
    for(i=more_line;i<sizeof(more_txt);i++)
      write(more_txt[i] + "\n");
    more_txt=0;
    return;
  }
}

reset(arg) 
{
    ::reset(arg);

    if (arg) return;
/*
 *   With arg = 0 this function should only be entered once!
 */
    level = 100;
    name = "logon";
    prompt=DEF_PROMPT;
}

short(list) 
{
    if(list) return("Hansi");
    return name+" the mighty tester";
}

query_presentation(list) {
    return short(1); 
}

long() {
    string cap_pronoun;
 
    cap_pronoun = capitalize(query_pronoun());
    write(short() + ".\n");
    write(tell_health(this_object()));
}
 
score()
{
    string tmp;
 
    write(" "+(short() ? short() : "("+query_real_name()+")")+"\n");
    write(" -------------------------------------------------\n");
    write(" Level            : " + level + "\n");
    write(" Experience       : " + experience + "\n");
    write(" Money            : " + money + " gold coins\n");
    write(" Alignment        : " + al_title +"\n");
    write(" Religion         : " + religion + "\n");
    write(" Guild            : " + guild_name + "\n");
    write(" Race             : " + real_race + "\n");
    write(" Size             : " + sizes[real_size] + "\n");
if(!attacker_ob) {
    write(" Hitpoints(max)   : " + hit_point + "("+ max_hp + ")\n");
    write(" Spellpoints(max) : " + spell_points + "("+ max_sp + ")\n");
}
    if (hunter)
    write(" Hunted by        : " + hunter->query_name() + ".\n");
    write(" Str: " + Str + " Int: " + Int + " Wis: " + Wis +"\n");
    write(" Dex: " + Dex + " Con: " + Con + " Chr: " + Chr +"\n");
 
   if (intoxicated || stuffed || soaked || poisoned)
    {
    tmp = " You are ";
 
	if (intoxicated)
	{
	    tmp += "intoxicated";
	    if (stuffed && soaked)
		tmp += ", ";
	    else
	    {
		if (stuffed || soaked || poisoned)
		    tmp += " and ";
		else
		    tmp += ".\n";
	    }
	}
 
	if (stuffed)
	{
	    tmp += "satiated";
 
	    if (soaked || poisoned)
		tmp += " and ";
	    else
		tmp += ".\n";
	}
 
	if (soaked)
	{
	    tmp += "not thirsty";
 
	    if (poisoned)
		tmp += " and ";
	    else
		tmp += ".\n";
	}
 
	write(tmp);
    }
 
    show_age();
    if(query_guild()) {
      write(" Try 'help guild' to get a list of your special abilities.\n");
    }
  return 1;
}
 
/* Identify ourself. */
id(str, lvl) {
  /*
   *  Some wizzies make invisibility items useable by
   *  players , and this will prevent cheating.
   */
	if(str == name || str == "ghost of " + name)
	    return 1;
  /*
   *  I think this looks stupid. When I am invisible it is
   *  because I want to work in PEACE.
   */
    if (str == name ) return 1;
}

int query_player() { return 1; }

string query_title() { return "testtitle"; }
 
string query_pretitle() { return "testpretitle"; }
 
set_level(lev) 
{
	 stats=({ lev,lev,lev,lev,lev,lev });
    max_hp=hit_point=15*lev+30;
    max_sp=spell_points=15*lev+30;
    return level = lev;
}

int query_party_member(object mem) 
{
    object a;
    if(!grouped) return 0;
    if(follow_whom) 
        return ((mem==follow_whom && mem->query_grouped()) || 
                member_array(mem,follow_whom->query_followers())!=-1);
    else return (follow_obj && member_array(mem,follow_obj)!=-1);
}

grmems_in_room() 
{
    object *mems,*folls;
    int i,sz;

    if(grouped) 
	{ 
        mems=({});
        if(!follow_whom)  /* we are the leader */
		{    
            mems+=({ this_object() }); 
            folls=query_followers();
        } else 
		{
            if(follow_whom->query_grouped() &&
               environment(follow_whom)==environment())
                mems+=({ follow_whom });
            folls=follow_whom->query_followers();
        }
        if(folls) for(sz=sizeof(folls),i=0;i<sz;i++) 
            if(folls[i]->query_grouped() &&
               environment(folls[i])==environment())
                mems+=({ folls[i] });
    } else mems=({ this_object() });
    return mems;
}

query_grouped() { return grouped; }

show_group() 
{
    int i,sz;
    write("Current group members:\n----------------------\n");
    if(grouped)
        write(query_name()+" [level "+query_level()+"] (leader)\n");
    if(query_followers())
        for(sz=sizeof(follow_obj),i=0;i<sz;i++) {
            if(follow_obj[i]->query_grouped())
                write(follow_obj[i]->query_name()+" [level "+
                      follow_obj[i]->query_level()+"]\n");
    }
}

int group(string arg) {
    object groupee;

    if(!stringp(arg)) 
	{
        if(!grouped) {
            write("You are not member of a group!\n");
            return 1;
        }
        if(!follow_whom) show_group();
        else follow_whom->show_group();
        return 1;
    }
    if(follow_whom) {
        write("You have to be the leader to group someone!\n");
        return 1;
    }
    if(!(groupee=present(arg,environment())) || !interactive(groupee)) { 
        write("There is no such player here!\n");
        return 1;
    }
    if(groupee!=this_object() && 
       (!follow_obj || member_array(groupee,follow_obj)==-1)) {
        write("That players isn't following you!\n");
        return 1;
    }
    if(groupee->query_immortal()) {
        write("You are not allowed to group immortals!\n");
        return 1;
    }
    if(groupee->query_ghost()) {
        write("You can't group with dead creatures.\n"); 
        return 1;
    }
    groupee->toggle_grouped();
    return 1;
}

toggle_grouped() 
{
    grouped=!grouped;
    if(grouped) tell_room(environment(this_player()),
        this_object()->query_name()+" has been grouped.\n");
    else tell_room(environment(this_player()),
        this_object()->query_name()+" has been kicked out of the group.\n");
}

int rid(string arg) 
{
    int i,sz;
    if(!stringp(arg)) {
        write("Whom want you to get rid of ?\n");
        return 1;
    }
    if(rid_whom) {
        write("You already try to get rid of "+rid_whom->query_name()+".\n");
        return 1;
    }
    if(follow_obj) 
        for(sz=sizeof(follow_obj),i=0;i<sz;i++) 
            if(follow_obj[i]->id(arg)) { rid_whom=follow_obj[i]; break; }
    if(!rid_whom) write("No such living is following you!\n");
    else write("From now on you try to get rid of "+
               rid_whom->query_name()+".\n");
    return 1;
}

int follow(string arg) 
{
    object whom;

    if(!stringp(arg)) 
	{
        if(!follow_whom) 
		{
            write("Follow whom?\n");
            return 1;
        }
	if (follow_whom==this_player()) {
	   switch(random(2)) {
	   case 0:write("You don't have enough selfdiscipline.\n"); break;
	   case 1:write("You are spinning around for a while ...\n"); break;
	   }
	   return 1;
	}
        write("You stop following "+follow_whom->query_name()+".\n");
        tell_object(follow_whom,query_name()+" stops following you.\n");
        follow_whom->rem_follower(this_object());
        follow_whom=grouped=0;
        return 1;    
    }
    if(!environment() || !(whom=present(arg,environment())) ||
       !living(whom)) {
        write("There is no such living here!\n");
        return 1;
    }
    if(whom->query_rid_whom()==this_object()) {
        write("You can't refollow at the moment.\n");
        return 1;
    }
    if(!query_ip_number(whom)) {
        write("You can only follow players!\n");
        return 1;
    }
    if(!whom->set_follower(this_player())) {
        write("Sorry, following in loops is not allowed!\n");
    } else {
        write("You start following "+whom->query_name()+".\n");
        tell_object(whom,query_name()+" starts following you.\n");
        follow_whom=whom;
    }
    return 1;
}

#define SHOUT(x) shout(x)

static string gTellstring;
static int listen_to_shouts_from_level;
static string frog_who_shouts; 

filter_tell(ob) {
    if (ob == this_player()) return 0;
    return ob->catch_shout(gTellstring);
}
 
/* This is called for every shouted string to this player.
*/
int catch_shout(string str)
{
	tell_object(this_object(),str);
   return 1;
}

listen_shout(lev)
{
  if(!lev || (lev=="off")) 
  {
    listen_to_shouts_from_level=0;
    return listen_to_shouts_from_level;
   }
  if (lev && lev <= level+1) listen_to_shouts_from_level=lev;
  return listen_to_shouts_from_level;
}
 
static line_format(str,arg,w1,w2,indent,explo,delim,lastchar)
{

    string arr;
    int    i,j;

    arr=explode(str,explo);

    if (sizeof(arr) < 2) return arr[0]+lastchar;

    str="";

    for (i=0; i<sizeof(arr)-1; i++)
    {
	str += arr[i]+delim;
	if (strlen(str + arr[i+1])>(arg - w1))
	{
	   str += "\n";
	   if (!indent) indent="";
	   w1 = -strlen(str);
	   str += extract(indent+"                     ",0,w2);
	}
    }
    return str + arr[i]+lastchar;
}

static quit(silent) {
string str;

  drop_all(1);
  if(!silent) write("Goodbye, friend .. Come back soon!\n");
  say(CName + " left the game.\n");
  if(!oldie) 
  {
    write("Sorry, no oldie!\n");
  }
  else
  {
    exec(oldie,this_object());
    oldie->fix(); 
  }
  destruct(this_object());
  return 1;
}
 
int kill(string str) 
{
    object ob,room;
    if (ghost)
	return 0;
    if (!stringp(str)) 
	{
	write("Kill what ?\n");
	return 1;
    }
    ob = present(lower_case(str), environment(this_player()));

    if (!objectp(ob)) 
	{
	write("No " + str + " here !\n");
	return 1;
    }
    if (!living(ob)) {
	write(str + " is not a living thing !\n");
	/*
	say(this_object()->query_name() +
            " tries foolishly to attack " + str + ".\n");
			*/
	return 1;
    }
    if (attacker_ob == ob) {
	write("Yes, yes.\n");
	return 1;
    }
    if (ob==this_player()) {
	write("What ??? Attack yourself ?\n");
	return 1;
    } 

	/* Moonchild 021192 */
    if (room=environment())
       if(room->query_property("no_fight")) {
         write("You are not allowed to fight here.\n");
         tell_object(ob,query_name() + " tried to attack you.\n");
         room->try_attack(this_object());
         return 1;
    }
    attack_object(ob);
    return 1;
}

int communicate(string str) 
{
    string verb, syn;
 
    verb = query_verb();
    if (str == 0)
	str = "";
    if (verb[0] ==39) 
       str = extract(verb, 1) + (str?" ":"")+ str;
    syn=this_player()->query_name();
    
    say(lw(syn+ " says: " + str + "\n"));
    writelw("You say: " + str + "\n");
    return 1;
}

/* 161093 HERP: centralized chat daemon */

guild_line(str) {
string gnam,msg,v;

    if (this_object()!=this_interactive()) return 0; /* faked call */

    if (!str) {
	write("Guild members online:\n\n");
	return CD->print_line(guild);
    }
    if (str=="on" || str=="off")
	return CD->set_line(this_object(),guild,str=="on"?1:0);
    gnam = capitalize(GM->query_name(guild));
    v=query_verb();
    if (v[strlen(v)-1]=='/') msg = "[*"+gnam+"*] "+cap_name+" "; /* emote .. */
    else msg = "[*"+gnam+" "+cap_name+"*] ";
    return CD->do_chat(guild,msg+str+"\n");
}

static heart_beat() 
{
    age += 1;
 
    if (intoxicated && random(40) == 0) {
	int n;
	n = random(7);
	if (n == 0) {
	    say(CName + " hiccups.\n");
	    write("You hiccup.\n");
	}
	if (n == 1) {
	    say(CName + " seems to fall, but takes a step and recovers.\n");
	    write("You stumble.\n");
	}
	if (n == 3) {
	    write("You feel drunk.\n");
	    say(CName + " looks drunk.\n");
	}
	if (n == 5) {
	    say(CName + " burps.\n");
	    write("You burp.\n");
	}
    }
 
    /* No obvious effects of being stuffed or soaked */
 
    if (hit_point < max_hp || spell_points < max_sp || intoxicated || headache || poisoned)
    {
	time_to_heal -= 1;
	if (time_to_heal < 0) {
	    if (headache) {
		headache -= 1;
		if (headache == 0)
		    tell_object(myself, "You no longer have a headache.\n");
	    }
	    if ((hit_point < max_hp) && !poisoned) {
		hit_point += 1;
		if (intoxicated)
		    hit_point += 100;
		if (hit_point > max_hp)
		    hit_point = max_hp;
	    }
	    if ((spell_points < max_sp) && !poisoned) {
		spell_points += 1;
		if (intoxicated && !poisoned)
		    spell_points += 100;
		if (spell_points > max_sp)
		    spell_points = max_sp;
	    }
	    if (intoxicated) {
		intoxicated -= 1;
		if (intoxicated == 0) {
		    headache = max_headache;
		    max_headache = 0;
		    tell_object(myself,
		       "You suddenly without reason get a bad headache.\n");
		    hit_point -= 5;
		    if (hit_point < 0)
			hit_point = 0;
		}
	    }
	    if (poisoned) {
		poisoned -= 1;
		if (poisoned == 0) {
		    tell_object(myself,
		       "You feel much better now.\n");
		} else {
		    if(hit_point >= 0) hit_point -= poisoned;
		    if(spell_points >= 0) spell_points -= poisoned;
		    tell_object(myself,
		       "You suffer from being poisoned.\n");
		    if(hit_point < 0) hit_player(1,7);
		}
	    }
	    time_to_heal = INTERVAL_BETWEEN_HEALING;
	}
    }
 
    if (stuffed)
	stuffed--;
 
    if (soaked)
	soaked--;
 
#if 1
    /* this function can be used to time the guild commands .. Llort */
    if(guild_soul) guild_soul->time_guild_soul();

    
    if ( releaseTime > -1 )
        perform_sk_action();

    /* pat (0806'93): once again me, skill-spell - performance   */
    /* temporary, should be changed as soon as possible          */
    handle_spell();

    /* HERP */
    if (attacker_ob) {
	if (guild_soul)
	    guild_soul->recognize_fight();
        write("\n"+get_prompt_str(prompt[7])+"\n");
	this_object()->attack();
    }   
#else
    if (attacker_ob)
	this_object()->attack();
    if (attacker_ob && hit_point < max_hp/5)
      run_away();
#endif
    if(!query_editing(myself))
	reset_prompt();
}
 
/*
 * Update our aligment.
 */
/* Kelly, changed at 921116 */
#if 1 
add_alignment(a) {
  if (!intp(a)) {
    write("Bad type argument to add_alignment.\n");
    return;
  }
  alignment = alignment*9/10 +a;
  al_title = query_al_string(); 
  if(level<apwz) real_al_title = al_title;
}

set_al(a) {
    if (!intp(a))
	return;
    alignment = a;
    al_title = query_al_string();
}
#endif
 
set_alignment(al) {
    if (!al) {
	if (real_al_title) write("Your alignment is "+real_al_title+".\n");
	else write("You don't have an alignment.\n");
	return 1;
    }
    if (al=="none") real_al_title=0;
    else real_al_title = al;
    return 1;
}

query_alignment_title() { return real_al_title; }
 
test_dark() {
    if (set_light(0) <= 0) {
	write("It is too dark.\n");
	return 1;
    }
    return 0;
}
 
put(str) {
    int i;
  string item,only_for;
    string container;
    object item_o;
    object container_o;
 
    if (!str)
	return 0;
    if (test_dark())
	return 1;
    if (sscanf(str, "%s in %s", item, container) != 2) {
	write("put what ?\n");
	return 1;
    }
    container = lower_case(container);
    container_o = present(container, this_player());
    if (!container_o)
	container_o = present(container, environment(this_player()));
    if (!container_o) {
	write("There are no " + container + "s here!\n");
	return 1;
    }
    switch (container_o->can_put_and_get()) {
      case 0:
	write("You can't do that.\n");
      case -1:                  /* for open/close containers. Llort */
	return 1;
    }
    item = lower_case(item);
    item_o = present(item, this_player());
    if (!item_o) {
	write("You have no " + item + "!\n");
	return 1;
    }
    if (item_o == container_o)
	return 0;
    if (item_o->prevent_insert())
	return 1;
    if (item_o->drop())
	return 1;
    /* To allow containers to contain only one kind of object */
    only_for=container_o->query_only_for();
    if(only_for) {
      if(!item_o->id(only_for)) {
        write("The "+container+" isn't made to contain the "+item+"!\n");
        return 1;
      }
    }
    i = item_o->query_weight();
    if (container_o->add_weight(i)) {
	/* Remove the weight from us. */
	if(container_o->query_container() &&
	  this_object()==environment(container_o))
	  environment(item_o)-> add_weight(container_o->update_weight(-i));
	else 
	  environment(item_o)-> add_weight(-i);
	move_object(item_o, container_o);
	say(CName + " puts the " + item + " in the " + container + ".\n");
	write("Ok.\n");
	it = item;
	return 1;
    }
    write("There is not room for more.\n");
    return 1;
}
 
pick_up(str) {
    string item;
    string container;
    object item_o;
    object container_o;
    int weight;
 
    if (!str) {
	write("What ?\n");
	return 1;
    }
    if (ghost) {
	write("Your incorporeal hand passes right through it.\n");
	return 1;
    }
    if (test_dark())
	return 1;
    if (str == "all") {
	get_all(environment());
	return 1;
    }
    if (sscanf(str, "%s from %s", item, container) != 2) {
	pick_item(str);
	return 1;
    }
    container_o = present(lower_case(container));
    if (!container_o) {
	write("There is no " + container + " here.\n");
	return 1;
    }
    switch (container_o->can_put_and_get()) {
	case 0:
	  write("You can't do that!\n");
	case -1:
	  return 1;
    }
    if (item=="all") {
	get_all(container_o);
	return 1;
    }
    item_o = present(item, container_o);
    if (!item_o) {
	write("There is no " + item + " in the " + container + ".\n");
	return 1;
    }
    if (!item_o->get(item)) {
	write("You can not take " + item + " from " +
	      container + ".\n");
	return 1;
    }
    weight = item_o->query_weight(); 
    if(container_o->query_container() && 
       this_object()==environment(container_o)) 
	weight=-container_o->update_weight(-weight);
    
    if (!add_weight(weight)) {
	write("You can not carry more.\n");
	return 1;
    }
    container_o->add_weight(-item_o->query_weight());
    move_object(item_o, myself);
    write("Ok.\n");
    say(CName + " takes " + item + " from " + container + ".\n");
    return 1;
}
 
static pick_item(obj) {
    object ob;
    int i;
    obj = lower_case(obj);
    if (environment(this_player())->id(obj)) {
	write("You can't take that.\n");
	return 1;
    }
    ob = present(obj, environment(this_player()));
    if (!ob) {
	write("That is not here.\n");
	return 1;
    }
    if (ghost) {
	write("You fail.\n");
	return 1;
    }
    if (environment(ob) == myself) {
	write("You already have it!\n");
	return 1;
    }
    if (call_other(ob, "get", 0) == 0) {
	write("You can not take that!\n");
	return 1;
    }
    i = call_other(ob, "query_weight", 0);
    if (add_weight(i)) {
	move_object(ob, myself);
	say(CName + " takes " + obj + ".\n");
	it = obj;
	write("Ok.\n");
	return 1;
    }
    write("You can't carry that much.\n");
    return 1;
}
 
drop_thing(obj) {
    string tmp;
    string tmp2;
    int i;
    object ob;

    if (!obj) {
	write("What ?\n");
	return 1;
    }
    if (obj == "all") {
	drop_all(1);
	return 1;
    }
    if (sscanf(obj, "%s in %s", tmp, tmp2) == 2) {
	put(obj);
	return 1;
    }

    if (sscanf(obj,"%d coins",i)==1 || sscanf(obj,"%d coin",i)==1) {
       if (money<i) {
	  write("You don't have that much money.\n");
	  return 1;
       }
       if (i<1) return;
       money-=i;
       ob=clone_object("obj/money");
       ob->set_money(i);
       move_object(ob,environment(this_object()));
       tmp=CName+" drops "+i+" gold coin";
       if (i>1) tmp+="s";
       tmp+=".\n";
       say(tmp);
       write("Ok.\n");
       return 1;
    }

    if (obj == "money" || obj == "all money") {
	write("You don't want to do that.\n");
	/* drop_all_money(1); */
	return 1;
    }
    tmp = obj;
    obj = present(lower_case(obj), this_player());
    if (!obj) {
	write("That is not here.\n");
	return 1;
    }
    if (drop_one_item(obj)) {
	it = tmp;
	write("Ok.\n");
	say(CName + " drops the " + tmp + ".\n");
    }
    return 1;
}
 
add_weight(w) {
    int i,max;
 
    max = (level + query_str())/2 + 10;

    /* if (frog)
	max = max/2; */

    i=w+local_weight;
    if (!is_wizard && (i>max || i<0 || ghost)) return;
    local_weight += w;
    return 1;
}
 
/*
 * Temporary move the player to another destination and execute
 * a command.
 */
 
static in_room(str)
{
    object room;
    object old_room;
    string cmd;
    if (!str)
	return 0;
    if (sscanf(str, "%s %s", room, cmd) != 2) {
	write("Usage: in ROOM CMD\n");
	return 1;
    }
    room = valid_read(room, WIZ);
    if (!room) {
	write("Invalid file name.\n");
	return 1;
    }
    old_room = environment();
    move_object(myself, room);
    command(cmd);
    if (old_room)
	move_object(myself, old_room);
    else
	write("Could not go back again.\n");
    return 1;
}
 
shout_to_all(str) {
    if (spell_points < 0) {
	write("You are low on power.\n");
	return 1;
    }
    if (!query_immortal())
	spell_points -= 20;
    if (!str) {
	write("Shout what ?\n");
	return 1;
    }
    if (ghost) {
	write("You fail.\n");
	return 1;
    }
    if (!frog) {
#ifdef USE_OLD_SHOUTS
	SHOUT(query_name() + " shouts: " + str + "\n");
#else
	shout(lw(query_name()+" shouts: "+str+"\n"));
#endif
	writelw("You shout: " + str + "\n");
    }
    else {
     /* Wolfi: 20.9.92 */ 
        FROG_SHOUT(CName,str);
	write("You shout to all frogs: " + str + "\n");
    }
    return 1;
}

/* shout_hook! Llort */
shout_hook(string str) {
    if(this_object()!=this_interactive()) return; /* NO WAY */
    if (!frog) { SHOUT(str); }
}
 
inventory() {
    object ob;
    if (test_dark())
	return 1;
    ob = first_inventory(myself);
    while(ob) {
	string str;
	str = call_other(ob, "short", 0);
	if (str) {
	    write(capitalize(str) + ".\n");
	    it = str;
	}
	ob = next_inventory(ob);
    }
    say(CName+" checks "+query_possessive()+" inventory.\n",0,this_object());
    return 1;
}
 
static examine(str) {
    if(str) return look("at " + str);
}
 
look(str) {
object ob, ob_tmp;
string item,short_str,msg,position;
int max;

    if (test_dark())
	return 1;
    if (!str) {
	if(is_invis<L_APPR) say(CName+" looks around.\n");
        return mylook(0);
    }
    if (sscanf(str, "at %s", item) == 1 || sscanf(str, "in %s", item) == 1) {
	int weight;
	item = lower_case(item);
	ob = present(item, this_player());
	if (!ob && call_other(environment(this_player()), "id", item))
	    ob = environment(this_player());
	if (!ob)
	    ob = present(item, environment(this_player()));
	if (!ob) {
	    write("There is no " + item + " here.\n");
	    return 1;
	}
	it = item;
	call_other(ob, "long", item);
	weight = ob->query_weight();
	if (ob->can_put_and_get(item)<1)   /* <1 for container */
	    return 1;
	if (living(ob)) {
	    object special;
	    special = first_inventory(ob);
	    while(special) {
		string extra_str;
		extra_str = call_other(special, "extra_look");
		if (extra_str)
		    write(extra_str + ".\n");
		special = next_inventory(special);
	    }
	}
	ob_tmp = first_inventory(ob);
	while(ob_tmp && call_other(ob_tmp, "short") == 0)
	    ob_tmp = next_inventory(ob_tmp);
	if (ob_tmp) {
	   if (living(ob)) {
		write("\t" + capitalize(item) + " is carrying:\n");
	    } else
		write("\t" + capitalize(item) + " contains:\n");
	}
	max = MAX_LIST;
	msg = "";
	ob = first_inventory(ob);
	while(ob && max > 0) {
	    if (short_str=ob->short())
		msg += capitalize(short_str) + ".\n";
	    ob = next_inventory(ob);
	    max -= 1;
	}
	if (ob && !max) msg+="*** TRUNCATED ***\n";
	write(msg);
	if (is_invis<L_APPR && (ob=find_player(item)) && ob!=this_object()) {
	   tell_object(ob,CName+" looks at you.\n",this_object());
	   say(CName+" looks at "+ob->query_name()+".\n",ob,this_object());
	}
	return 1;
    }
    write("Look AT something, or what ?\n");
    return 1;
}
 
query_mailaddr() {
  return mailaddr;
}
move_player_to_start3(where) {
int tmp_size;
    object ob,purg;
    object soul;
    string nam;
    int has_soul;
     
    enable_commands();
    /*
     * Now we can enter the game. Check tot_value if the game
     * crashed, and the values of the player was saved.
     */

    if(!race && !real_race) { 
      where=RM->query_room();
    }
    add_standard_commands();
    SM->skill_commands();

    
    move_object(clone_object("obj/rsoul"), myself);
    move_object(clone_object("tools/tool"), myself);
    load_auto_obj(auto_load);

/* New Soul-checking code by Bonzo. 7/7/94. */
  soul = first_inventory(myself);
  while(soul)
  {
    nam = file_name(soul);
    if(nam[0..8]=="obj/soul#")
      has_soul = 1;
    soul = next_inventory(soul);
  }
  if(!has_soul)
    move_object(clone_object("obj/soul"), myself);
/* End of soul-checking code. */
    /* Herp 920703 */
    set_guild(5);

    /* Herp expander/speeder/oderwieauchimmer */
    reset_expander();

    set_living_name(name);

    set_heart_beat(1);
    move_object(myself, DEF_START);
}

fix() {
  set_heart_beat(1);
  reset_expander();
  if(!prompt || sizeof(prompt)!=sizeof(DEF_PROMPT))
      prompt=DEF_PROMPT;
  return 1;
}

help(what) {
  string dummy;
    notify_fail("No help available!\n");

    if (!what) {
       cat("/doc/help");
       return 1;
    }

/* Herp: for guilds, the adv-levels are not valid */
    if (( what=="levels") && guild) return;

    what=do_fit(({ "wizard", "testplayer", "expander",
                   "quicktyper" }), what);

    if (what) {
	if(sscanf(what,"%s..%s",dummy)==1) return 0;
/* Herp: maybe there's help available in the guild file. */
        what=do_fit(get_dir("/doc/helpdir/*"),what); /**/
        write("Help on "+what+":\n");

	if (sizeof(explode(what," "))>1 || !cat("/doc/helpdir/" + what) && 
            guild) ;
        else return 1;
    }

    if (what == "wizard" && query_immortal()) {
	cat("/doc/wiz_help");
	return 1;
    }
    if (what == "testplayer" && (query_immortal())) {
	cat("/doc/testplayer");
	return 1;
    }
    if ( what == "summon wind" || what=="fireshuriken" || what== "earthgrip"
         || what == "freeze" ) {
       "/players/patience/guild/sorcerer_spells/help_skills"->help_skills(what);
        return( 1 );
    }
    if(what == "expander" || what == "quicktyper") return help_expander();
    return 0;
}
 
tell_player(str) {
object ob;
string who,msg;

  if(ghost) {
    write("You fail.\n");
    return 1;
  }
  if(!str||sscanf(str,"%s %s",who,msg)!=2) {
    write("Tell what ?\n");
    return 1;
  }
  it=lower_case(who);
  ob=find_living(it);
  if(spell_points<0) {
     write("You are low on power.\n");
     return 1;
  }
  if(!ob) {
    write("No player with that name.\n");
    return 1;
    }
  if(ob==myself) {
    write("You talk with yourself, looking quite insane.\n");
    say(CName+" talks with "+myself->query_objective()+"self"
      + ", and looks quite insane.\n");
    return 1;
  }
  if(query_editing(ob)) {
    write("The poor wizard is using ed. right now. Try later.\n");
    return 1;
  }
  if(ob->query_earmuff_level() > level) {
    write("That wizard is busy right now, try again later.\n");
    return 1;
  }
/* 21-SEP-93 Galadriel: quick fix, check if its an npc like Yorel etc */
  if((int)query_ip_number(ob))
  if(ob->query_linkdeath()) {
    write("The player is currently linkdead.\n");
    return 1;
  }
  if(query_input_pending(ob)) {
    write("That player is writing something. Message sent anyway.\n");
  }
/* 21-SEP-93 Galadriel: quick fix, check npc or query_idle will bug */
  if((int)query_ip_number(ob))
  if(query_idle(ob)>300) write("That player is idle. Message sent anyway.\n");
  if (!query_immortal() && !ob->query_immortal()) spell_points-=5;
  tell_object(ob, lw(query_name() + " tells you: " + msg + "\n"));
  writelw("You tell " + capitalize(it) + ": " + msg + "\n");
  return 1;
}
 
whisper(str)
{
    object ob;
    string who;
    string msg;
    if (ghost) {
	write("You fail.\n");
	return 1;
    }
    if (!str || sscanf(str, "%s %s", who, msg) != 2) {
	write("Whisper what ?\n");
	return 1;
    }
    it = lower_case(who);
    ob = find_living(it);
    if (!ob || !present(it, environment(this_player()))) {
	write("No player with that name in this room.\n");
	return 1;
    }
    tell_object(ob, lw(CName + " whispers to you: " + msg + "\n"));
    writelw("You whisper to " + capitalize(it) + ": " + msg + "\n");
    say((CName + " whispers something to " + who + ".\n"), ob);
    return 1;
}
 
/*
 * This routine is called from other routines to drop one specified object.
 * We return true if success.
 */
 
drop_one_item(ob)
{
    int weight;
 
    if (call_other(ob, "drop", 0))
	return 0;
    weight = call_other(ob, "query_weight", 0);
    if (!weight)
	weight = 0;
    if(!add_weight(-weight)) {
	write("You have to drop something else first!\n");
	return 0;
    }
    move_object(ob, environment(myself));
    return 1;
}
 
drop_all(verbose)
{
    object ob;
    object next_ob;
    if (!myself || !living(myself))
	return;
    ob = first_inventory(myself);
    while(ob) {
	string out;
	next_ob = next_inventory(ob);
	it = call_other(ob, "short", 0);
	if (drop_one_item(ob) && verbose) {
	    out = it + ".\n";
	    say(CName + " drops " + out);
	    tell_object(myself, "drop: " + out);
	}
	ob = next_ob;
    }
}
 
query_brief() { return brief; }
 
toggle_brief()
{
    brief = !brief;
    if (brief)
	write("Brief mode.\n");
    else
	write("Verbose mode.\n");
    return 1;
}

/* Here are the routines for handling religion. I hope one likes them */
/* Cashimor, 250192 */ 
query_religion() {
  return religion;
}

set_religion(str) {
  religion=str;
}

add_exp(e) {
    experience += e;
}

/* This routine is needed when one wants to circumvent the alignment
   restrictions by religion, this function may only be called by other
   wizards, and never from objects. */

add_experience(e) {
    experience += e;
}

/* Ethereal Cashimor, here are the 'secretxp' routines. I hope they work...
   030393 */

query_has_been_here(str) {
string junk1,junk2;

  if(!str) return 0;
  if(!explored) return 0;
  return(sscanf(explored,"%s#"+str+"#%s",junk1,junk2));
}

set_has_been_here(str) {
string new;
int i;

  if(!str) return;
  if(!explored) {
    explored="#"+str+"#";
    return;
  }
  explored+=str+"#";
}
    
add_intoxination(i) {
    if(i < 0)
    {
	if (-i > intoxicated / 10)
		i = -intoxicated / 10;
    }
    intoxicated += i;
    if(intoxicated < 0)
	intoxicated = 0;
}
 
add_stuffed(i)
{
    if(i < 0)
    {
	if (-i > stuffed / 10)
		i = -stuffed / 10;
    }
    stuffed += i;
    if (stuffed < 0)
	stuffed = 0;
}
 
add_soaked(i)
{
    if(i < 0)
    {
	if (-i > soaked / 10)
		i = -soaked / 10;
    }
    soaked += i;
    if (soaked < 0)
	soaked = 0;
}
 
query_intoxination() {
    return intoxicated;
}
 
query_stuffed()
{
    return stuffed;
}
 
query_soaked()
{
    return soaked;
}

second_life() {
#if 1
    object death_mark;
#endif
    int i,x,w;
    make_scar();
    ghost = 1;
    if (level > 1)
	level = level - 1;

    x=random(3)+2;
    for(i=0;i<x;i++) {
        w=random(6);
        if(stats[w]>RM->query_basic_stat(real_race,w) && stats[w]>1) stats[w]--;
    }

    msgin = "drifts around";
    msgout = "blows";
    headache = 0;
    intoxicated = 0;
    stuffed = 0;
    soaked = 0;
    hunter = 0;
    if(!attacker_ob) {
      switch(random(3)) {
        case 0: shout("A black hand takes "+capitalize(name)
                    + " with it to the regions of death.\n"); break;
        case 1: shout("A black shadow joins "+capitalize(name)
                    + " with the dead.\n"); break;
        case 2: shout("Evil laughter is heard as "+capitalize(name)
                    + " is taken from this world.\n"); break;
      }
    }
 
    attacker_ob = 0;
    grouped = 0;
    if(follow_whom) follow();
    if(query_followers()) 
        for(i=0;i<sizeof(follow_obj);i++) command("follow",follow_obj[i]);
    
    tell_object(myself, "\nYou die.\nYou have a strange feeling.\n" +
		"You can see your own dead body from above.\n\n");
 
    return 1;
}
 
remove_ghost() {
    if (!ghost)
	return 0;
    tell_object(this_object(),"You feel a very strong force.\n"
                            + "You are sucked away...\n"
                            + "You reappear in a more solid form.\n");
    /* write -> tell_object changed by Cashimor to be compatible
       with Ted's wand of raising, 111292 */
    say("Some mist disappears.\n");
    say(CName + " appears in a solid form.\n");
    ghost = 0;
    dead = 0;
    poisoned = 0;       /* we don't want him to die again */
    msgin = "arrives";
    msgout = "leaves";
    save_me(1);
    return 1;
}
 
/* 110892 by Dago */
is_hunted_by()
{
  if (hunter)
    return hunter->query_name();
  else
    return 0;
}

 
stop_hunting_mode()
{
}
 
drink_alcohol(strength)
{
    return drink_alco(strength);
}
 
drink_alco(strength)
{
	if (strength > 0 && intoxicated + strength > level * 3) {
            write("You fail to reach the drink with your mouth.\n");
            return 0;
	}
	intoxicated += strength;
 
	if (intoxicated < 0)
            intoxicated = 0;
	if (intoxicated == 0)
            write("You are completely sober.\n");
	if (intoxicated > 0 && headache) {
            headache = 0;
	    tell_object(myself, "Your headache disappears.\n");
	}
	if (intoxicated > max_headache)
            max_headache = intoxicated;
	if (max_headache > 8)
            max_headache = 8;
 
	return 1;
}
drink_soft(strength)
{
	if (soaked + strength > level * 3)
	{
		write("You can't possibly drink that much right now!\n" +
			"You feel crosslegged enough as it is.\n");
		return 0;
	}
 
	soaked += strength;
 
	if (soaked < 0)
		soaked = 0;
 
	if (soaked == 0)
		write("You feel a bit dry in the mouth.\n");
 
	return 1;
}
 
eat_food(strength)
{
	if (stuffed + strength > level * 3)
	{
		write("This is much too rich for you right now! Perhaps something lighter?\n");
		return 0;
	}
 
	stuffed += strength;
 
	if (stuffed < 0)
		stuffed = 0;
 
	if (stuffed == 0)
		write("Your stomach makes a rumbling sound.\n");
 
	return 1;
}
 
spell_missile(str)
{
    object ob;
    if (test_dark())
	return 1;
    if (level < 5)
	return 0;
    if (!str)
	ob = attacker_ob;
    else
	ob = present(lower_case(str), environment(this_player()));
    if (!ob || !living(ob)) {
	write("At whom ?\n");
	return 1;
    }
    if (ob == myself) {
	write("What ?");
	return 1;
    }
    missile_object(ob);
    return 1;
}
 
spell_shock(str)
{
    object ob;
    if (test_dark())
	return 1;
    if (level < 10)
	return 0;
    if (!str)
	ob = attacker_ob;
    else
	ob = present(lower_case(str), environment(this_player()));
    if (!ob || !living(ob)) {
	write("At whom ?\n");
	return 1;
    }
    if (ob == myself) {
	write("What ?");
	return 1;
    }
    shock_object(ob);
    return 1;
}
 
spell_fire_ball(str)
{
    object ob;
    if (test_dark())
	return 1;
    if (level < 15)
	return 0;
    if (!str)
	ob = attacker_ob;
    else
	ob = present(lower_case(str), environment(this_player()));
    if (!ob || !living(ob)) {
	write("At whom ?\n");
	return 1;
    }
    if (ob == myself) {
	write("What ?");
	return 1;
    }
    fire_ball_object(ob);
    return 1;
}
 
give_object(str) {
    string item, dest;
    object item_ob, dest_ob;
    int weight;
    int coins;
 
    if (!str)
	return 0;
    if (test_dark())
	return 1;
    if (sscanf(str, "%d coins to %s", coins, dest) == 2)
	item = 0;
    else if ( sscanf(str, "1 coin to %s", dest) == 1)
	coins = 1;
    else if ( sscanf(str, "coin to %s", dest) == 1)
	coins = 1;
    else if (sscanf(str, "one coin to %s", dest) == 1)
	coins = 1;
    else if (sscanf(str, "%s to %s", item, dest) != 2) {
	write("Give what to whom ?\n");
	return 1;
    }
    dest = lower_case(dest);
    if (item) {
	item = lower_case(item);
	item_ob = present(item, this_player());
	if (!item_ob) {
	    write("There are no " + item + " here.\n");
	    return 1;
	}
	it = item;
	if (environment(item_ob) == this_object() &&
	    call_other(item_ob, "drop", 0) == 1) {
	    return 1;
	} else {
	    if (!call_other(item_ob, "get")) {
		write("You can't get that !\n");
		return 1;
	    }
	}
    }
    dest_ob = present(dest, environment(this_player()));
    if (!dest_ob) {
	write("There is no " + capitalize(dest) + " here.\n");
	return 1;
    }
    if (!living(dest_ob)) {
	write("You can't do that.\n");
	return 1;
    }
    if (!item) {
	if (coins <= 0 && level < apwz)
	    return 0;
	if (money < coins) {
	    write("You don't have that much money.\n");
	    return 1;
	}
	money -= coins;
	/* Checkpoint the character, to prevent cheating */
	if (coins > 1000 && level < apwz)
	    save_me(1);
	tell_object(dest_ob, CName + " gives you " + coins +
	    " gold coins.\n");
        say(CName+" gives "+coins+" coins to "+dest_ob->query_name()+
            ".\n", dest_ob);
	dest_ob->add_money(coins);      /* revert the msg sequence */
	write("Ok.\n");
	return 1;
    }
    weight = call_other(item_ob, "query_weight", 0);
    if (!call_other(dest_ob, "add_weight", weight)) {
	write(capitalize(dest) + " can't carry any more.\n");
	return 1;
    }
    if (dest_ob->query_ghost()) {
	string na,it;
	object e;
	na=lower_case(dest_ob->query_name());
	it=item_ob->short();
	write("You toss "+it+" through "+na+".\n");
	say(CName+" tossed "+it+" through "+na+".\n",dest_ob);
	tell_object(dest_ob,CName+" tossed "+it+" through you.\n");
	tell_room(e=environment(this_object()),
		capitalize(it)+" falls on the floor.\n");
	move_object(item_ob,e);
	return 1;
    }
    add_weight(-weight);
    move_object(item_ob, dest_ob);
    say(CName + " gives " + item + " to " + capitalize(dest) + ".\n");
    write("Ok.\n");
/* Herp */
    dest_ob->enter_inventory(item_ob);
    return 1;
}
 
/*
 * Get all items here.
 */
static get_all(from)
{
    object ob, next_ob;
 
    ob = first_inventory(from);
    while(ob) {
	string item;
	next_ob = next_inventory(ob);
	item = ob->short();
	if (item && ob->get()) {
	    int weight;
	    weight = ob->query_weight();
	    if (from->query_container() &&
		this_object()==environment(from)) 
		weight = -from->update_weight(-weight);
	    if (add_weight(weight)) {
		from->add_weight(-ob->query_weight());
		write(item + ": Ok.\n");
		say(CName + " takes: " + item + ".\n");
		move_object(ob, this_object());
	    } else {
		write(item + ": Too heavy.\n");
	    }
	    it = item;
	}
	ob = next_ob;
    }
}

static pose() {
    if (level >= 15) {
	write("You send a ball of fire into the sky.\n");
	say(CName + " makes a magical gesture.\n");
	say("A ball of fire explodes in the sky.\n");
	return 1;
    }
    return 0;
}
 
/*
 * Recursively compute the values of the inventory.
 * Beware that object may selfdestruct when asked for query_value().
 */
compute_values(ob) {
    int v;
    while(ob) {
	int tmp;
	object next_ob;
 
	next_ob = next_inventory(ob);
	tmp = ob->query_value();
        if(ob->query_auto_load()) tmp=0;
	if(tmp > 1000)
	    tmp = 1000;
	v += tmp;
	if (ob && first_inventory(ob))
	    v += compute_values(first_inventory(ob));
	ob = next_ob;
    }
    return v;
}
 
load_auto_obj(str) {
    string file, argument, rest;
    object ob;
    mixed dum;
 
    while(str && str != "") {
	if (sscanf(str, "%s:%s^!%s", file, argument, rest) != 3) {
	    write("Auto load string corrupt.\n");
	    return;
	}
	str = rest;
/*	ob = find_object(file);
	if (!ob)
	    continue;
	ob = clone_object(file);
	if (argument)
	    call_other(ob, "init_arg", argument);
	transfer(ob, this_object()); */
	dum=catch(ob=clone_object(file));
	if(ob) {
	  ob->init_arg(argument);
	  move_object(ob,this_object());
          add_weight(ob->query_weight());
	}
	else if (level > 35) write(dum); /* Moonchild 081192 */
    }
}
 
compute_auto_str() {
    object ob;
    string str,tmp;
 
    auto_load = "";
    ob = first_inventory(this_object());
    while(ob) {
	str = call_other(ob, "query_auto_load");
	ob = next_inventory(ob);
	if (!stringp(str) || sscanf(str,"%s^!%s",tmp,tmp)==2) continue;
	auto_load = auto_load + str + "^!";
    }
}
 
smart_report(str) {
    string who;
    string current_room;
 
    current_room = file_name(environment(this_object()));
    if (sscanf(current_room, "players/%s/", who) != 1)
	return;
}
 
nsh_flag(ob) {
    if(!query_immortal()) return " ";
    return (ob->query_noshouts() ? "*" : " ");
}

show_hp() {
  write("\n"+get_prompt_str(1)+"\n");
  return 1;
}

#define MAX_SCAR        10
int scar;
 
static make_scar() {
    if (level < 10)
	return;
    scar |= 1 << random(MAX_SCAR);
}
 
static show_scar() {
    int i, j, first, old_value;
    string *scar_desc, tmp;
 
    scar_desc = ({ "left leg", "right leg", "nose", "left arm", "right arm",
		   "left hand", "right hand", "forehead", "left cheek",
		   "right cheek" });
    j = 1;
    first = 1;
    old_value = scar;
    while(i < MAX_SCAR) {
	if (scar & j) {
	    old_value &= ~j;
	    if (first) {
		tmp=CName + " has a scar on " + query_possessive() +
		      " " + scar_desc[i];
		first = 0;
	    } else if (old_value) {
		tmp+=", " + query_possessive() + " " + scar_desc[i];
	    } else {
		tmp+=" and " + query_possessive() + " " + scar_desc[i];
	    }
	}
	j *= 2;
	i += 1;
    }
    if (!first)
	writelw(tmp + ".\n");
}
 
/* herp */

powerup() {
object *ob;
int i;

  ob=all_inventory(this_object());
  for (i=0;i<sizeof(ob);i++) {
    if (ob[i]->query_armour()) command("wear " + ob[i]->query_name()); else
    if (ob[i]->query_weapon()) command("wield "+ ob[i]->query_name());
  }
  write("Powerup complete.\n");
  return 1;
}
 

add_standard_commands() {
    if(!real_race) real_race=race;
    if(!real_size) real_size=size;
    add_action("toggle_brief", "brief");
    add_action("bug", "bug");
    add_action("process_spell","cast"); /* (pat) needed for multi-bug-system */
    add_action("converse", "converse");
    add_action("drop_thing", "drop");
    add_action("set_line_number", "lines"); /* Moonchild 220693 */
    add_action("examine", "exa", 1); // why changed to examine? moonchild 110893
    add_action("follow","follow");	/* following and grouping */
    add_action("spell_fire_ball", "fireball");
    add_action("fix","fix");
    add_action("pick_up", "get");
    add_action("give_object", "give");
    add_action("group","group");
    add_action("help", "help");
    add_action("show_hp","hp");
    add_action("inventory", "i");
    add_action("idea", "idea");
    add_action("incognito","incognito");
    add_action("kill", "kill");
    add_action("look", "l"); // moonchild 120893
    add_action("look", "look");
    add_action("spell_missile", "missile");
    add_action("put", "put");
    add_action("powerup","powerup");
    add_action("pose", "pose");
    add_action("c_prompt","prompt");
    add_action("pray_it","pray");
    add_action("quit", "quit");
    add_action("rid","rid");            /*  -- Llort 930123 */
    add_action("communicate", "say");
    add_action("save_character", "save");
    add_action("score", "score");
    add_action("search_it", "search");  /* Moonchild 150793 */
    add_action("stop_hunting_mode", "stop");
    add_action("shout_to_all", "shout");
    add_action("spell_shock", "shock");
    add_action("smell_it", "smell");    /* Moonchild 140793 */
    add_action("tell_player", "tell");
    add_action("pick_up", "take");
    add_action("typo", "typo");
    add_action("who", "who");
    add_action("whisper", "whisper");
    add_action("toggle_whimpy", "wimpy");
    add_action("set_wimpydir", "wimpydir");
    add_action("communicate", "'", 1);

    add_action("show_spells", "_spells");
    init_expander();
}

query_prevent_shadow() { return 0; }	/* Herp: Shadowing is allowed */
query_invis() { return is_invis; }
query_vis() { return !query_invis(); }
query_guild() { return guild; }
query_quest_points() { return quest_points; }

conf_prompt() { 
    if(sizeof(prompt)!=sizeof(DEF_PROMPT)) 
        prompt=DEF_PROMPT;
    return prompt; 
}

c_prompt(arg) {
    if(!prompt || sizeof(prompt)!=sizeof(DEF_PROMPT)) 
        prompt=DEF_PROMPT;
    if(!arg) {
        write("Your current prompt is:\n");
        write((prompt[3] ? "\n":""));
        write("HP:"+(prompt[0] ? "on ":"off "));
        write("SP:"+(prompt[1] ? "on ":"off "));
        write("<monster>:"+(prompt[2] ? "on ":"off "));
        write("<victim>:"+(prompt[5] ? "on ":"off "));
        write((prompt[4]? "\n>>\n":">\n"));
        if(prompt[7])
            write("The stats are always shown in a fight.\n");
        write("and you "+(prompt[6] ? "":"don't ")+"get the stats all the "+
              "time.\n");
        return 1;
    }
    switch(arg) {
        case "hp":  prompt[0]=!prompt[0];
                    write("HP turned "+(prompt[0] ? "on.\n":"off.\n")); 
                    break;
        case "sp":  prompt[1]=!prompt[1];
                    write("SP turned "+(prompt[1] ? "on.\n":"off.\n")); 
                    break;
        case "mon": prompt[2]=!prompt[2];
                    write("<monster> turned "+(prompt[2] ? "on.\n":"off.\n")); 
                    break;
        case "cr1": prompt[3]=!prompt[3];
                    write("Leading LF turned "+(prompt[3] ? "on.\n":"off.\n")); 
                    break;
        case "cr2": prompt[4]=!prompt[4];
                    write("Trailing LF turned "+(prompt[4]? "on.\n":"off.\n")); 
                    break;
        case "vic": prompt[5]=!prompt[5];
                    write("Victims HP turned "+(prompt[5]? "on.\n":"off.\n")); 
                    break;
        case "perm": prompt[6]=!prompt[6];
                    write("Permanent Stats turned "+
                          (prompt[6]? "on.\n":"off.\n")); 
                    break;
        case "fight": prompt[7]=!prompt[7];
                    write("Stats only in fights turned "+
                          (prompt[7]? "on.\n":"off.\n")); 
                    break;
        case "all": prompt=({ 1,1,1,1,1,1,1,1 });
                    write("All promptoptions set.\n");
                    break;
        case "none": prompt=({ 0,0,0,0,0,0,0,0 });
                    write("All promptoptions reset.\n");
                    break;
        case "default": prompt=DEF_PROMPT;
                    write("Prompt reset to default.\n");
                    break;
        default:
		notify_fail("Type 'help prompt' for more help on prompt.\n");
		return 0;
    }
    return 1;
}

incognito() {
   incognito=!incognito;
   if(incognito)
      write("Title now incognito.\n");
   else
      write("Title now visible.\n");
   set_cap_name();
   return 1;
}

set_invis(a) { 
    if (this_player()==this_object()) {
        if (!a) is_invis=L_PLAYER; 
        else is_invis=to_int(a);
        if((is_invis > level && (this_player()->query_immortal()) )
           || is_invis > L_PLAYER) is_invis=level;
        if(is_invis<0) is_invis=0;
    }
}
set_vis() { 
    if (this_player()==this_object() || this_player()->query_immortal())
        is_invis=0; 
}

set_guild(i) { 
object ob;
string str;
int lvl;

  if (!intp(i)) return write("Non numeric value to set_guild(): "+i+"\n");
  if (i<0 || i>GM->query_nog()) return write("illegal guild value to set_guild(): "+i+"\n");

  (level==-1?(lvl=1):(lvl=level));      /* new player */

  /* Changing the guild requires to remove the old soul. */
  if (guild && guild!=i && (ob=present(GM->query_id(guild),this_object()))) {
     ob->guild_changes();
     destruct(ob);
  }

  /*161093 HERP: centralized chat daemon */
  CD->remove_chat(this_object(),guild);	/* remove old guild */
  CD->add_chat(this_object(),i);	/* add new guild */

  guild=i; 
  guild_name=GM->query_name(i); 
  guild_wiz=GM->query_wiz(i);
  guild_room=GM->query_room(i);
  guild_soul=GM->get_soul(i);

  apwz=GM->query_levels(i);             /* Set wizard levels */
  fwz=apwz+1;

  for (i=0;i<NUM_STATS;i++) set_stats(i,query_stats(i)); /* Adjust max_hp/sp */

  /* Calculate the quest points now */

  if (quests) {
    object qr;

    /* 021092 Cashimor: quest_points to zero? */
    quest_points=0;
    call_other(QR, "????");
    qr=find_object(QR);      /* Supposed to be loaded */
    str=explode(quests,"#");
    for (i=0;i<sizeof(str);i++)
      if (qr && (ob=present(str[i],qr)))
	  quest_points+=ob->query_weight();
  }

  /*171093 HERP: set this for the adv.guild */

  if (!guild) {
      add_action("guild_line","guild");
      add_action("guild_line","guild/");
  }
}

add_chat() { if (guild) CD->add_chat(this_object(),guild); }
 
void set_cap_name()
{
  cap_name = capitalize(name);
  if (!incognito && pretitle) cap_name = pretitle + " " + cap_name; 
}

notify_reconnect(silent) {
  if(!silent) tell_object(this_object(),"Reconnect successful.\n");
  set_heart_beat(1);
  ldead = 0;
/*  remove_call_out("dest_ldead");  removed: whisky */
}

query_hit_msg(tmp,name,att,def) {
string *m;
  
    if (guild_soul)
        m=guild_soul->query_hit_msg(tmp,name,att,def);
    if (!m || sizeof(m)!=3) return ::query_hit_msg(tmp,name,att,def);
    else return m;
}

wield(w,h) {
  if(guild_soul)
    if(guild_soul->dont_wield(w,h)) return 0;
  return ::wield(w,h);
}

query_guild_soul() { return guild_soul; }

int add_skill_action(string action,int force) {
  if(file_name(previous_object())!=SM) return 0;
  if(!force) if(query_actions(this_object(),action)) return -1;
  add_action("process_skill",action);
  return 1; 
}

int process_skill(string arg) {
   return (int)SM->process_skill( arg );
}

pray_it(str) {
  return RLM->do_pray(religion,str);
}

/* pat (250593): the skill-actions */
prep_sk_action( arg, relTime )
{
   if ( releaseTime > -1 ) {
      write( "Have patience, you are already preparing an action ...\n" );
      return( 1 );
   }

   releaseTime = relTime;
   actionVerb = query_verb();
   actionArg = arg;

   if ( releaseTime > 0 )
      write( "You start to concentrate on this action ...\n" );

   return( 1 );
}

perform_sk_action()
{
   int    idx;
   mixed *actions;

   if ( releaseTime < 0 )
      return;

   if ( releaseTime > 0 ) {
      releaseTime--;
      return;
   }

   if ( !actionVerb || !strlen(actionVerb) )
      return;

   actions = SM->dump_actions();
   if ( actions && sizeof( actions ) ) {
      idx = member_array( actionVerb, actions[0] );
      if ( idx > -1 ) {
         call_other( actions[2][idx],actions[1][idx],actionArg );
      }
   }

   releaseTime = -1;
   actionVerb = "";
}

show_spells()
{
   mixed *arr, *hlp;
   int   i;

   arr = get_spell( -1 );
   if ( !arr ) return( 0 );

   printf( "\n%-20s %-20s %-20s %-5s\n", "Spell","Command","Mastery","Speed" );
   printf( "--------------------------------------------------------------------\n" );
   for ( i = 0; i < sizeof( arr[0] ); i++ ) {
      hlp = SM->get_spell( arr[0][i] );
      printf( "%-20s %-20s %-20s %4d\n",
              hlp[1]->query_name(),hlp[1]->query_command(),
              SM->get_skill_title(arr[1][i]), arr[3][i] );
   }
   printf( "--------------------------------------------------------------------\n" );

   return( 1 );
}

set_incognito(i) { incognito=i; }
query_incognito() { return incognito; }

query_wizard() { return 1; }
query_immortal() { return 1; }
query_arch() { return 1; }
query_lord() { return 1; }
