nomask inherit "secure/valid";


int ftp_user;           /* ftp only, no login. *anonymous* */

#define WIZ 1
#define ARCH 0
#define CName          (this_object()->query_name())
#define TName          (this_object()->query_name_true())
#define IName          "Someone"
#define RM             "race/master"
#define RLM            "religion/master"
#define QR             "room/quest_room"
#define SM  	       "obj/skill_master"
#define CD  	       "sys/chatd"
#define SPELL_MASTER   "/spells/master"
#define ABILITY_MASTER "/abilities/master"
#define SOCIAL_MASTER  "/masters/feelings"
#define SKILL_MASTER   "/masters/skills"

#define DEF_START       "room/church"
#define MAX_POISON      40      
#define POISON_STATES   "barely/very weak/weakly/medium/strong/very strong/critical"
#define myself	this_object()
#define TP	this_object()
#define DEF_PROMPT ({ 0,0,0,0,0,0,0,1 })
#define ARENA            "/players/patience/arena/prep_room"

#define NO_OF_LANG     3         // take care: defined in living too !!!

#include "lw.h"
#include "log.h"
#include "levels.h"
#include "/sys/living.h"
#include "expander.c"
#include "who.c"
#include "env_var.c"
/*#include "raceline.c"*/		/*HERP: obsolete */
#include "mylook.c"
//#include "/players/whisky/mylook.c"
#include "smell.c"
#ifdef MULTIGUILD
#include "guildspells.c"
#endif

#include "/sys/quest_sys.c" 
#include "/spells/spell.h"

/* prototyping */
void set_cap_name();
static fix_short();


string pretitle;        /* Our official title. Wiz's can change it. */
string title;           /* Our official pretitle. Wiz's can change it. */
string al_title;
string real_al_title;
int is_linkdead;        /* The player is currently linkdead */
int intoxicated;        /* How many ticks to stay intoxicated. */
int stuffed;            /* How many ticks to stay stuffed */
int soaked;             /* How many ticks to stay soaked */
int poisoned;           /* How many ticks to stay poisoned */
int is_resting;         /* does the player rest ? */
static int ldead;       /* Checking if the player is linkdead -> destruct */
static string poisonname;  /* name of the poisonlevels */

static closure call;

int headache, max_headache;
int user_status;           /* a general use var. to remember certain stati */
/* the usage is defined in /obj/user_status.h, please talk
   to an archwiz if you need a bit in here */
static string guild_name,guild_wiz,guild_room;
static int apwz,fwz;    /* level of app.wiz, level of full.wiz */
string called_from_ip;  /* IP number was used last time */
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
#if 0
int race_is_updated;    /* No longer needed */
#endif
string description;	/* Extra_look for player */
int *prompt;            /* how do we like the prompt? */
int bug_file_size;      /* Used to check if there are new reports waiting */
static int grouped;	/* are we grouped ? */
static string level_changed;

string religion; /* Cashimor, 250193, This could be interesting */
string explored; /* Cashimor, 030393, For alternative XP receiving */

static int actionVerb;     /* pat: which skill-action to performe */
static string actionArg;   /* pat: which argument for the action  */
static int releaseTime;    /* pat: when to perform the action     */

int incognito;
int start_at_guild;
int is_pk;
int legend_level;
int practice_sess;         // remaining practice sessions
int last_practice_level;   // last level we got sessions for

#include "std_features.c"   /* some additional commands :) Llort 22.10.94 */

/* Some functions to access the user_status variable */
/* please use the defined variables in /obj/user_status.h */

query_user_status(stat) { return user_status & stat; }
set_user_status(stat) { user_status|=stat; }
clear_user_status(stat) { user_status &= (!stat); }
toggle_user_status(stat) { user_status ^= stat; }

query_msgin() { return msgin; }
query_msgout() { return msgout; }
query_mmsgin() { return mmsgin; }
query_mmsgout() { return mmsgout; }


/* Define this after it was used. */
version() {
    return __VERSION__;
}

query_link_return() { return link_return; }
object other_copy;

static try_throw_out(str)
{
    object ob;
    string link_return;
    if (!other_copy || str == "" || (str[0] != 'y' && str[0] != 'Y')) {
	write("Welcome another time then !\n");
	destruct(this_object());
	return;
    }
#ifdef LOG_ENTER
    log_file("ENTER", " (throw)\n");
#endif
    if(query_ip_number(other_copy) && other_copy!=this_object()) {
	tell_object(other_copy,"Session called by another connection.\n");
	remove_interactive(other_copy);
	exec(other_copy,this_object());
	other_copy->fix();
    } else {
	if (other_copy!=this_object()) exec(other_copy,this_object());
	other_copy->fix();
	if ((link_return=other_copy->query_link_return())) {
	    catch(call_other(link_return,"???"));
	    ob=find_object(link_return);
	    tell_room("room/purgatory","Suddenly, life appears in "+other_copy->query_name()+"'s face.\n"+other_copy->query_name()+" disappears.\n");
	}
	if (!ob) ob = find_object(DEF_START);
	other_copy->move_player("X",ob);
    }
    other_copy->notify_reconnect();		/* 921120 Herp */

    if (other_copy!=this_object()) destruct(this_object());
    return 1;
}

/* logon() is called when the players logges on. */

logon(n,quiet) {
    string fn;
    int lv;

    fn=file_name(previous_object());
    if (fn[0..12]!="secure/login#" && fn[0..3]!="sys/") {
	write("illegal logon: "+fn+"\n");
	log_file("ILLEGAL","logon != secure/login from "+
	  previous_object()->query_real_name()+" at "+ctime(time())+".\n");
	destruct(this_object());
	return;
    }
    name=n;
#if 0
    call_out("logon2",0);
}

logon2() {
#endif

    restore_object("/p/"+to_string(({name[0]}))+"/"+name);
    if(lv=master_object()->get_wiz_level(name)) {
	if(level==-1) {
	    write("Invalid name.\n");
	    log_file("LOSTWIZ","missing playerfile for wiz "+name+
	      ", call from "+query_ip_name()+", at "+
	      ctime(time())+".\n");
	    destruct(this_object());
	    return;
	}
	if(level!=lv) {
	    level_changed=
	    "Your level has changed during your absence!\n"+
	    "You have been "+(level<lv?"pro":"de")+
	    "moted to level "+lv+".\n";
	    level=lv;
	}
    } else if(level>L_PLAYER) {
	level_changed=
	"Your level has changed during your absence!\n"+
	"You have been demoted to player!\n";
	level=L_PLAYER;
    }
    if (lv) is_wizard=1; else is_wizard=0;
    if (level==0) level=-1;
    time_to_save = age + 500;
    /*
     * Don't do this before the restore !
     */
    /* Matt 1-28-93: Commented out, so that player incognito restores from .o
	if (!is_wizard) incognito=1;
    */
    dead = ghost;
    set_cap_name();

    local_weight = 0;
    armour_class = 0;
#if 0                               /* not needed at the new system */
    name_of_weapon = 0;
    weapon_class = 0;
#endif

    /* If this is a new character, we call the adventurers guild to get
     * our first title !
     */
    if (level == -1) {
	apwz=GM->query_levels(0);
	fwz=apwz+1;
	call_other("room/adv_guild", "advance", 0); /* Adventurers guild */
	set_level(1); set_str(1); set_con(1); set_int(1); set_dex(1);
	set_wis(1); set_chr(1);
	hit_point = max_hp;
	spell_points = -30;
    }
    else set_savings(level,1);

    move_player_to_start2(start_where);
    attacker_ob = 0;
}

/* Called by command 'save' */
save_character() {
    save_me(1);
    write("Ok.\n");
    return 1;
}

#define	CHUNK	(env_var["LINES"] ? env_var["LINES"] : 16)

set_line_number(i) {
    int no;
    if(!i)
	write("Your screen is currently set at " + CHUNK + " lines.\n");
    else {
	sscanf(i, "%d", no);
	if(!no)
	    write("You can't set the number of lines to that!\n");
	else {
	    env_var["LINES"]=no;
	    write("Your screen is currently set at " + CHUNK + " lines.\n");
	}
    }
    return 1;
}

/*HERP: this is the only file-function for player.c ! */

static string more_file;	/* used by the more-command */
static int more_line;

more(str) {
    if (!str)
	return 0;
    if(str[0]=='~') str="/players/"+name+str[1..strlen(str)-1];
    more_file = str;
    more_line = 1;
    if (cat(more_file, more_line, CHUNK) == 0) {
	write("No such file.\n");
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
	write("EOF.\n");
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
	    write( more_txt[i] + "\n");
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
    int i;

    ::reset(arg);                       /* !!! HERP */

    call = #'call_other;

    /*  destructing linkdead players: whisky */
    if (arg!=0 && !interactive(this_object()) )
    { 
	if (ldead >= 2) /* 45 min - 1,5 hours */
	    call_out("dest_ldead",1,0);    /* short call out to avoid bugs */
	else
	    ldead = ldead + 1;
    }

    /* HERP: wuss that bullshit ? */
#if 0
    /* removing the connection from idle players: whisky */
    if (interactive(this_object()) && (60 + query_idle(this_object())/60) > 19)
    {
	write(
	  "\n\n** You are moved into purgatory because of your excessive idleness. **\n\n");
	remove_interactive(this_object());
	ldead = 1;
    }
#endif

    /* Herp: keep a log of reset with arg==0 temporarily ... */
    if (!arg && name) {
	log_file("RESET_P",name+
	  " this_player(): ");
	if (this_player()) log_file("RESET_P",
	      this_player()->query_name()+" "+
	      this_player()->short()+" ");
	else log_file("RESET_P"," unavail. ");
	if (previous_object()) log_file("RESET_P",
	      " previous_object "+
	      previous_object()->query_name()+" "+
	      previous_object()->short()+"\n");
	else log_file("RESET_P"," unavail.\n");
    }
    if (arg)
	return;
    /*
     *   With arg = 0 this function should only be entered once!
     */
    if (creator(this_object())) 
    {
	write("Cloned player\n");
	illegal_patch("Cloned player.c");
	destruct(this_object());
	return;
    }
    level = -1;
    name = "logon";
    cap_name = "Logon";
    real_size=0; 
    real_race=0;
    msgin = "arrives"; msgout = "leaves";
    mmsgin = "arrives in a puff of smoke";
    mmsgout = "disappears in a puff of smoke";
    title = "the titleless";
    al_title = "neutral";
    real_al_title = al_title;
    gender = -1; /* Illegal value, so it will be changed! */
    env_var=([]);
    poisonname=explode(POISON_STATES,"/");
    incognito=1;
    prompt=DEF_PROMPT;

    releaseTime = -1;     /* pat (2505'93): no action to be released */
    actionVerb = "";      /* pat (2505'93): no action to be released */
    practice_sess=0;
    last_practice_level=0;
    set_number_of_arms(2);
}

/* 920605 Llort: removed nomask .. need it for guild purpose */ 
short(list) 
{
    string s,*ex,func;
    int i;

    /* 920228 Herp: player invis in der who list anzeigen */
    if(!list) { 
	if (!this_player() || 
	  this_object()->is_invis_for(this_player())) return 0;
	if (is_linkdead)
	    return "A statue made of stone, in memoriam " + 
	    capitalize(this_object()->query_real_name());
	if (ghost)
	    return "Ghost of " + capitalize(this_object()->query_real_name());
	if (frog)
	    return this_object()->query_name() + " the frog";
    }
    return env_var["SHORT"];
    /*
	s=query_presentation();
	if (is_invis) 
	  s+=" (invisible"+
	     (this_player()->query_immortal() ? " "+is_invis : "")+
	     ")";

	return s;
    */
}

query_presentation(list) {
    string s,*ex,func;
    int i;

    if(!list) { 
	if (!this_player() || 
	  this_object()->is_invis_for(this_player())) return 0;
    }
    if ( is_afk() ) {
       return( env_var["SHORT"]+ " (afk)" );
    }
    return env_var["SHORT"];
    /*
	s=cap_name;
	if(!incognito && query_immortal() && title && title!="") {
	  s=s+" "+title;
	} else if (real_race){
	  if (! incognito && title && title!="") {
	    s=s+" the "+ capitalize(RM->query_adverb(real_race));
	    s=s+" "+title;
	  } else
	    s=s+" the "+ capitalize(real_race);
	} else
	  if (! incognito && title) s=s+" "+title;

	return s;
    */
}

set_race(str) 
{ 
    if(real_race && level<30)
	return;
    ::set_race(str);
    fix_short();
    if (name != this_player()->query_real_name())
    {
    log_file("RACE",ctime(time())+" " + name + " patched by " 
              + this_player()->query_real_name() + " race " + str + "\n");
    }
}

/* whisky: better code */
int set_description(string str)  
{ 
    if(!stringp(str)) 
    {
	if(!description) write("You have no description.\n");
	else write("Your description currently is: " + description + "\n");
	return 1;
    }
    description=str;
    write("Description changed to: " + description + "\n");
    return 1;
}

int set_title(string arg) 
{
    if (!stringp(arg)) 
    {
	if (stringp(title)) 
	    write("Your title is " + title + ".\n");
	else 
	    write("You don't have a title.\n");
	return 1;
    }
    if (arg=="none") title = "";
    else             title = arg;

    fix_short();
    return 1;
}

int action_set_title( string arg )          // called by add action
{
   if ( !(this_object()->query_immortal() 
         || this_object()->query_legend_level() > 0) )
      return( 0 );
  if (this_object() != this_player())
    { 
      log_file("Title",ctime(time())+" "+this_object()->query_real_name()+
              " got title "+arg+" by "+this_player()->query_real_name()+
              "\n");
    }
   return( set_title(arg) );
}

int set_pretitle(string arg) 
{
    if (!stringp(arg)) 
    {
	if (stringp(pretitle)) 
	    write("Your pretitle is " + pretitle + ".\n");
	else 
	    write("You don't have a pretitle.\n");
	return 1;
    }
    if (arg=="none")  pretitle = "";
    else              pretitle = arg;
    set_cap_name();
    if (this_object()->query_real_name() != this_player()->query_real_name())
    {
    log_file("Pretitle",ctime(time())+" "+name+" got pretitle "+arg+
             " by "+this_player()->query_real_name()+"\n");
    }
    fix_short();
    return 1;
}

nomask long() {
    string cap_pronoun;

    cap_pronoun = capitalize(query_pronoun());
    write(short() + ".\n");
    if (ghost || frog || is_linkdead)
	return;
    if(description) writelw(cap_pronoun + " " + description + "\n");
    /* Moonchild 301092 */
    show_scar();
    write(tell_health(this_object()) );
}

string query_wimpydir()
{
    if (stringp(env_var["WIMPYDIR"]))
	return env_var["WIMPYDIR"];
    return "none";
}

string query_al_title()
{
    if (stringp(al_title))
	return al_title;
    return "neutral";
}

score()
{
    string tmp, qexp, exp, adv, aexp;

    if (ghost) 
    {
	     write("You are a ghost and therefore have no scores.\n");
	     return 1;
    }

    qexp = funcall(call,this_object(),"query_qexp_perc_lev");
    exp = funcall(call,this_object(),"query_exp_perc_lev");
    adv = funcall(call,this_object(),"query_perc_advance_lev");
    aexp = adv;

    if (aexp > 100)
        aexp = 100;

    if (adv > 99)
        adv = 1;
    else
        adv = 0;

    write(" "+(short() ? short() : "("+query_real_name()+")")+"\n");
    write(" -------------------------------------------------\n");
    if ( level == 29 && legend_level > 0 )
       write(" Legend Level          : " + legend_level + "\n" );
    else
       write(" Level                 : " + level + "\n" );
    write(" Exp. [combat%/quest%] : " + experience + " "+
          "["+to_string(exp)+"/"+to_string(qexp)+"]\n");
    write(" Rating to advance     : "+to_string(aexp)+"\n");
    write(" Money                 : " + money + " gold coins\n");
    write(" Alignment             : " + al_title +"\n");
    write(" Religion              : " + religion + "\n");
    write(" Guild                 : " + guild_name + "\n");
    write(" Race                  : " + real_race + "\n");
    write(" Size                  : " + sizes[real_size] + "\n");
    if(!attacker_ob) {
	 write(" Hit points(max)        : " + hit_point + "("+ 
                                        this_object()->query_maxhp() + ")\n");
	 write(" Spell points(max)      : " + spell_points + "("+
                                        this_object()->query_maxsp() + ")\n");
	 write(" Fatigue points(max)    : " + fatigue_points + "("+
                                        this_object()->query_maxfp() + ")\n");
    }
    if (hunter)
	write(" Hunted by             : " + hunter->query_name() + ".\n");
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

	if (poisoned)
	    tmp += poisonname[poisoned<MAX_POISON ? 
	      (poisoned*sizeof(poisonname)/MAX_POISON) : 
	      sizeof(poisonname)-1] +" poisoned.\n";

	write(tmp);
    }

    if(whimpy < 0) write(" Brave mode!"); 
    else write(" Wimpy : " + whimpy + "%");
    write(env_var["WIMPYDIR"] ? " (" + env_var["WIMPYDIR"] + ")\n " : "\n ");

    if ( is_pk )
        write ("You have a PK license.\n");
    if (adv && !funcall(call,this_object(),"query_immortal"))
        write(" You can already advance your level !\n"); 
    
    write(" "); show_age();
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
    if(!is_wizard)
	if(str == name || str == "ghost of " + name)
	    return 1;
	/*
	 *  I think this looks stupid. When I am invisible it is
	 *  because I want to work in PEACE.
	 */
    if (is_invis_for(this_player()))
	return 0;
    if (ghost)
	return str == "ghost of " + name;
    if (str == name )
	return 1;
#if 0
    if ( str == query_name_rdr() )                       /* added by pat */
	return 1;
    return 0;
#else
    return lower_case(str) == lower_case(query_name_rdr()); /* Moonchild */
#endif
}

int query_player() { return 1; }

string query_title() { return title; }

string query_pretitle() { return pretitle; }

set_level(lev) 
{
    object scroll;
    int i;
#if 0
    write("set_level ["+lev+"] fwz ["+fwz+"] apwz ["+apwz+"]\n");
#endif
    if ( !(master_object()->set_wiz_level(name,lev)) || to_int (lev) <-1 )
	return illegal_patch("set_level");              /* NOPE ! */
    if(lev<apwz) is_wizard=0;

    log_file("LEVEL",ctime(time())+" " + name +" (" + level +") " + lev +" patched by " + this_player()->query_real_name() + "(" + this_player()->query_level() + ")" + "\n");

    if ( lev < 29 ) set_legend_level( 0 );

    set_savings(lev, 1);
    return level = lev;
}

void set_legend_level( int ll )
{
   int i;

   if ( level < 29 ) return;
   if ( ll < 0 ) ll = 0;
   legend_level = ll;

   for ( i = 0; i < NUM_STATS; i++ ) set_stats(i,query_r_stats(i));  //adj hp/sp
}

int query_legend_level( )
{
   return( legend_level );
}

int query_exp_next_level()
{
   int ne;

   ne = 0;

   if ( level < 29 )
      ne = funcall( call, GM, "query_exp", guild, level+1, 0 );
   else if ( level == 29 )
      ne = funcall( call, GM, "query_exp", guild, level, legend_level+1 );
   return( (ne <= 0) ? funcall(call,GM,"query_exp",guild,30,0) : ne );
}

int query_exp_perc_lev()
{
   int exp, help;

   exp = TO->query_exp() ;
   if ( exp > 20000000 )
      help = to_int( (100.0*(float)exp)/(float)query_exp_next_level() );
   else
      help = (100 * exp) / query_exp_next_level();
   return( (help < 1) ? 1 : help );
}

int query_perc_advance_lev()
{
   int hc, hq, fu, fd, qmal;

   hc = query_exp_perc_lev();
   hq = query_qexp_perc_lev();
   
   qmal = ( 2 * (100 - hq) * level ) / 29;

   if ( hc > 1000 ) hc = 1000;
   if ( hq > 230 )  hq = 230;
   if ( hq < 1 )    hq = 1;

   fu = hc * hq * hq * 40;
   fd = (10000000/(hc*hc)) * (hq*hq+hc*hc+2*hc*hq) / hq + 1;

   return( (fu/fd) - qmal );
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

int group(string arg) 
{
    object groupee;

    if(!stringp(arg)) 
    {
	if(!grouped) {
	    write("You are not a member of a group!\n");
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
	write("That player isn't following you!\n");
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
	write("Who want you to get rid of ?\n");
	return 1;
    }
    if(rid_whom) {
	write("You try to get rid of "+rid_whom->query_name()+".\n");
	return 1;
    }
    if(follow_obj) 
	for(sz=sizeof(follow_obj),i=0;i<sz;i++) 
	    if(follow_obj[i]->id(arg)) { rid_whom=follow_obj[i]; break; }
    if(!rid_whom) write("No such living thing is following you!\n");
    else write("From now on you'll try to get rid of "+
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
	/* moved out for debugging
		     if (follow_whom==this_player()) 
		{
			 switch(random(2)) 
		    {
			    case 0:write("You don't have enough self-discipline.\n"); break;
			    case 1:write("You spin around for a while ...\n"); break;
		      }
		      return 1;
		     }
	 end comment */
	write("You stop following "+follow_whom->query_name()+".\n");
	tell_object(follow_whom,query_name()+" stops following you.\n");
	follow_whom->rem_follower(this_object());
	follow_whom=grouped=0;
	return 1;    
    }
    if(!environment() || !(whom=present(arg,environment())) ||
      !living(whom)) 
    {
	write("There is no such living thing here!\n");
	return 1;
    }
    if(whom->query_rid_whom()==this_object()) 
    {
	write("You can't refollow at the moment.\n");
	return 1;
    }
    if(!query_ip_number(whom)) 
    {
	write("You can only follow players!\n");
	return 1;
    }
    if(!whom->set_follower(this_player())) 
    {
	write("Sorry, following in loops is not allowed!\n");
    } else if ( !(this_player()->query_wizard()) )
    {
	write("You start following "+whom->query_name()+".\n");
	tell_object(whom,query_name()+" starts following you.\n");
	follow_whom=whom;
    }
    return 1;
}

#ifdef USE_OLD_SHOUT
#define SHOUT_OLD(x) shout(x)
#define SHOUT(x) gTellstring=x; filter_array(users(),"filter_tell",this_object())
#endif

/* Wolfi: 20.9.92 Frogs understand Frogish */
#define FROG_SHOUT(frog_name,x) frog_who_shouts=frog_name; gTellstring=x; filter_array(users(),"filter_tell_frog",this_object()) 

static string gTellstring;
static int listen_to_shouts_from_level;
static string frog_who_shouts; 

filter_tell(ob) {
    if (ob == this_player())
	return 0;
    /* I want to be able to turn off shouts .. Llort */
    if (ob->query_immortal() && ob->query_noshouts())
	return 0;
    return ob->catch_shout(gTellstring);
}

/* This is called for every shouted string to this player.
*/
int catch_shout(string str)
{
    if (this_player()->query_level() >= listen_to_shouts_from_level) 
    {
	tell_object(this_object(),str);
	return 1;
    }
    return 0;
}

/*   Wolfi: 20.9.92 */

filter_tell_frog(ob) {
    if (ob == this_player())
	return 0;
    return ob->catch_shout_frog(frog_who_shouts,gTellstring);
}

/* This is called for every string that is shouted by a frog.
*/
catch_shout_frog(frog_name,str)
{

    if (this_player()->query_level() >= listen_to_shouts_from_level) {
	if (frog) 
	    tell_object(this_object(),frog_name+" the frog shouts: "+str+ ".\n");
	else
	    tell_object(this_object(),frog_name+" the frog shouts: Hriibit! Hriibit!\n");

	return 1;
    }
    return 0;
}

/* This is the earmuff hook. You can set the level of the players to which
   you want to listen to, to one more than your own.
   This means you can not stop higher level players from shouting to you,
   but you can stop lower levels and your own level.
   Changed by Ethereal Cashimor for the improved busy function in appr.c */

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
    object login;

    if(interactive(this_object()) && query_input_pending(this_object())) {
	notify_fail("You can't quit while entering text.\n");
	return 0;
    }
    save_me(0);
    if(((level>apwz)||(this_object()->query_testchar()))&&(!silent)) {
	if(str=catch(home())) {
	    write("You have no workfile or it is buggy.\n");
	    write("Reason: "+str+"\n");
	}
    }
    drop_all(1);
    write("Saving "+capitalize(name)+".\n"); 
    if(!silent) write("Goodbye, friend .. Come back soon!\n");
    if((!is_linkdead)) {
	say(TName + " left the game.\n",0,this_object(),
	  IName + " left the game.\n");
    }
    if((this_player())&&(login=clone_object("secure/login"))) {
	login->recon(name);
	exec(login,this_object());
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
	say(this_object()->query_name() +
	    " tries foolishly to attack " + str + ".\n");
	return 1;
    }

    if (attacker_ob) {
	write("You are already busy fighting !\n");
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
    string verb;

    verb = query_verb();
    if (str == 0)
	str = "";
    if (verb[0] ==39) 
	str = extract(verb, 1) + (str?" ":"")+ str;

    say(lw(TName+ " says: " + str + "\n"),0,TP,
      lw(IName+ " says: " + str + "\n"));
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
    int i, achk, sec_att;
/*
    if ( this_object()->query_implementor() ) {
       if ( attacker_ob )
          tell_object(this_object(), "HBE: attacker_ob = SET\n" );
       else
          tell_object(this_object(), "HBE: attacker_ob = NONE\n" );
    }
*/
    if (ghost)
	     return;
    if (is_resting)
        heal_self(funcall(call,this_object(),"query_heal_if_rest"));
    age += 1;
    if(lock_time>0) lock_time--;
    if (age > time_to_save) {
	if (!brief && !is_wizard)
	    write("Autosave.\n");
	save_me(1);
	time_to_save = age + 500;
    }
    funcall(call,this_object(),"chk_all_shadows");


    /* HERP: Check if the player's link broke */

    if (!is_linkdead) {
	/*if (!query_ip_number()) {*/
	if (!interactive(this_object())) {
	    say("Linkdeath arrives and turns "+TName+
	      " into a statue of stone.\n",0,TP,
	      "Linkdeath arrives and turns "+IName+
	      " into a statue of stone.\n");
	    is_linkdead=1;
	    link_return=file_name(environment(this_player()));
	    this_player()->move_player("into purgatory#room/purgatory");
	    set_heart_beat(0);
	    ldead = 1;
	    /* call_out("dest_ldead",3600,0); removed this call_out Whisky !!! */
	    return; /* Dont do anything, if linkdead */
	}
    }
    else
    if (query_ip_number()) {
	/* say("Suddenly "+CName+" forms out of a statue of stone.\n"); */
	is_linkdead=0;
    }
    else return; /* Linkdead, don't do any action */

    /* ende HERP */

    if (intoxicated && random(40) == 0) {
	int n;
	n = random(7);
	if (n == 0) {
	    say(TName + " hiccups.\n",0,TP,
	      IName + " hiccups.\n");
	    write("You hiccup.\n");
	}
	if (n == 1) {
	    say(TName+" seems to fall, but takes a step and recovers.\n",0,TP,
	      IName+" seems to fall, but takes a step and recovers.\n");
	    write("You stumble.\n");
	}
	if (n == 3) {
	    write("You feel drunk.\n");
	    say(TName + " looks drunk.\n",0,TP,
	      IName + " looks drunk.\n");
	}
	if (n == 5) {
	    say(TName + " burps.\n",0,TP,
	      IName + " burps.\n");
	    write("You burp.\n");
	}
    }

    /* No obvious effects of being stuffed or soaked */

    if (hit_point < max_hp || spell_points < max_sp || fatigue_points < max_fp
        || intoxicated || headache || poisoned)
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
		    hit_point += 5;
		if (hit_point > max_hp)
		    hit_point = max_hp;
	    }
	    if ((spell_points < max_sp) && !poisoned) {
		spell_points += 1;
		if (intoxicated && !poisoned)
		    spell_points += 5;
		if (spell_points > max_sp)
		    spell_points = max_sp;
	    }
	    if ((fatigue_points < max_fp) && !poisoned) {
		fatigue_points += 1;
		if (intoxicated && !poisoned)
		    fatigue_points += 5;
		if (fatigue_points > max_fp)
		    fatigue_points = max_fp;
	    }
	    if (intoxicated) {
		intoxicated -= 1;
		if (intoxicated == 0) {
		    headache = max_headache;
		    max_headache = 0;
		    tell_object(myself,
                      "You suddenly get a bad headache for no reason.\n");
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

    /* this function can be used to time the guild commands .. Llort */
    if(guild_soul) guild_soul->time_guild_soul();


    if ( releaseTime > -1 )
	perform_sk_action();

    nhandle_spell();
/*
    if ( this_object()->query_implementor() ) {
       if ( attacker_ob )
          tell_object(this_object(), "HBC: attacker_ob = SET\n" );
       else
          tell_object(this_object(), "HBC: attacker_ob = NONE\n" );
    }
*/
    if ( attacker_ob && environment(attacker_ob)==environment(this_object()) )
    {
        if (guild_soul) guild_soul->recognize_fight();
        write("\n"+get_prompt_str(prompt[7])+"\n");
       
        if ( (achk=this_object()->attack(hands[0],0)) )
        {
           sec_att = get_skill_value("second-attack");
           if ( sec_att && random(100) < sec_att )
              achk=this_object()->attack(hands[0],0);
           i = 1;
           while ( i < number_of_arms && achk ) {
              if ( hands[i] && random(100) < get_skill_value("multi-wield") ) {
                 achk=this_object()->attack(hands[i],i);
                 if ( achk && sec_att && random(100) < sec_att )
                    achk=this_object()->attack(hands[0],0);
              }
              i++;
           }
        }
    }   

    // this part of code remains for monsters who do TOTALY overwrite attack()
    check_wimpy( attacker_ob );

    if ( !achk ) {                                 // opponent died or fled !
       attacker_ob = 0;                            // no hunter for players !
    }

    if(!query_editing(myself))
	reset_prompt();
}

int check_wimpy( object attacker_ob )
{
    object here;

    here=environment(this_object());

    if (attacker_ob && hit_point < max_hp*whimpy/100) {

	/* Moonchild, wimpydir */
	if(env_var["WIMPYDIR"]) {
	    string *qdd;
	    /* changed by James 6/25/93
		    qdd=here->query_dest_dir();
	    */
	    qdd=(string *)here->query_room("dest_dir");
	    if((pointerp(qdd) && member_array(env_var["WIMPYDIR"], qdd)!=-1)
	      || member_array(env_var["WIMPYDIR"], ({ "north", "northeast",
		  "east", "southeast", "south", "southwest", "west",
		  "northwest", "up", "down", "out", "enter" }))!=-1) {
		command(env_var["WIMPYDIR"], this_object());
		if(environment()!=here) {
		    tell_object(this_object(),"Your legs run away with you!\n");
                    tell_room( here, TName+" runs away in sheer terror !!!\n" );
		    return( 0 );
		}
	    }
	}

	/* Allow shadowing of run_away(), Ethereal Cashimor */
	this_object()->run_away();
	if(environment() != here) { 
           return( 0 );
        }
    }

    return( 1 );
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

test_darkness() 
{
    if ( set_light(0) <= 0 )
	return 1;
    return 0;
}

test_dark() 
{
    int i;
    if (set_light(0)+this_player()->infravision() <= 0)
	return 1;
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
	write("Put what ?\n");
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
	say(TName+" puts the "+item+" in the "+container+".\n",0,TP,"");
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
	write("You cannot carry more.\n");
	return 1;
    }
    container_o->add_weight(-item_o->query_weight());
    move_object(item_o, myself);
    write("Ok.\n");
    say(TName + " takes " + item + " from " + container + ".\n",0,TP,"");
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
	write("You cannot take that!\n");
	return 1;
    }
    i = call_other(ob, "query_weight", 0);
    if (add_weight(i)) {
	move_object(ob, myself);
	say(TName + " takes " + obj + ".\n",0,TP,
	  IName + " takes " + obj + ".\n");
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
	say(TName+" drops "+i+" gold coin"+(i>1 ? "s.\n" : ".\n"),0,TP,
	  i+" gold coin"+(i>1 ? "s":"")+" appear out of thin air.\n");
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
	say(TName + " drops the " + tmp + ".\n",0,TP,
	  capitalize(tmp)+" appears out of thin air.\n");
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
    int i;
    object *players;
    string lo_msg;
    string hi_msg;

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
    log_file("PLAYSHOUTS", capitalize(name) + ": " + str + "\n"); /*Moonchild*/
    if (!frog) {
#ifdef USE_OLD_SHOUTS
	SHOUT(query_name() + " shouts: " + str + "\n");
#else
	/* Matt 8-4-94: Should not be "Someone" to higherups */
	lo_msg = lw(query_name() + " shouts: " + str + "\n");
	hi_msg = lw(capitalize(name) + " shouts: " + str + "\n");
	players = filter_array(users(), "shout_filter", this_object());
	for(i = 0; i < sizeof(players); i++) {
	    if(players[i] != this_object()) {
		if(players[i]->query_level() < level)
		    tell_object(players[i], lo_msg);
		else tell_object(players[i], hi_msg);
	    }
	}
	/*	shout(lw(query_name()+" shouts: "+str+"\n")); */
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

int shout_filter(object ob) {
    if(ob == this_player()) return 0;
    if(ob->query_earmuff_level() > level) return 0;
    return 1;
}

/* shout_hook! Llort */
shout_hook(string str) {
    if(this_object()!=this_interactive()) return; /* NO WAY */
    log_file("PLAYSHOUTS", capitalize(name) + ": " + str + "\n");
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
    say(TName+" checks "+query_possessive()+" inventory.\n",0,TP,"");
    return 1;
}

static examine(str) {
    if(str) return look("at " + str);
}


look(str) 
{
    object ob, ob_tmp, *all, *inv;
    string item,short_str,msg,position;
    int max,i,sz;

    if (test_dark())
    {
	write("It's too dark.\n");
	return 1;
    }
    if(!str) return mylook(0);
    if (sscanf(str, "at %s", item) == 1 || sscanf(str, "in %s", item) == 1) 
    {
	int weight;
	item = lower_case(item);
	ob = present(item, this_player());
	if (!ob && call_other(environment(this_player()), "id", item))
	    ob = environment(this_player());
	if (!ob)
	    ob = present(item, environment(this_player()));
	if (!ob) 
	{
	    notify_fail("You see nothing of interest.\n");
	    return 0;
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

	// only thiefes and wizards see the full inventory of a player

	if ( !living(ob) || ob->query_npc() 
	  || this_object()->query_immortal() || this_object()->query_guild()==1)
	{
	    max = MAX_LIST;
	    msg = "";
	    ob = first_inventory(ob);

	    while(ob && max > 0) 
	    {
		if (short_str=ob->short())
		    msg += capitalize(short_str) + ".\n";
		ob = next_inventory(ob);
		max -= 1;
	    }
	    if (ob && !max) msg+="\n";
	    write(msg);
	}
	else 
	{
	    // lightsources
	    inv = all_inventory(ob);
	    all = ({});
	    all += filter_objects(inv,"query_is_lit");
	    inv = inv - all;
	    // worn armour
	    all += filter_objects(inv,"query_worn");
	    inv = inv - all;
	    // wielded weapons
	    all += filter_objects(inv,"query_wielded");
	    msg = "";
	    for(sz=sizeof(all),i=0; i < sz; i++)
	    {
		if (short_str = all[i]->short())
		    msg += capitalize(short_str)+"\n";
	    }
	    if (strlen(msg) > 1)
		write(msg);
	}
	if (is_invis<L_APPR && (ob=find_player(item)) && ob!=this_object()) 
	{
	    tell_object(ob,CName+" looks at you.\n",this_object());
	    say(TName+" looks at "+ob->query_name()+".\n",ob,TP,"");
	}
	return 1;
    }
    write("Look AT something, or what ?\n");
    return 1;
}

query_mailaddr() {
    return mailaddr;
}

static move_player_to_start2(where) {
    if (gender == -1) {
	fix_short();
	write("Are you, male, female : ");
	input_to("getgender", 0);
	return;
    }
    move_player_to_start3(where);
}

/*  This function is called using input_to, and sets the
 *  gender of this player.
 */
static getgender(gender_string) {

    gender_string = lower_case(gender_string);
    if (gender_string[0] == 'm') {
	write("Welcome, Sir!\n");
	set_male();
    }
    else if (gender_string[0] == 'f') {
	write("Welcome, Madam!\n");
	set_female();
    }
    /*
      else if (gender_string[0] == 'o') {
	  write("Welcome, Creature!\n");
	  set_neuter();
      }
    */
    else {
	write("Sorry, but that is too weird for this game!\n");
	write("Are you, male, female (type m, f): ");
	input_to("getgender");
	return;
    }
    move_player_to_start3(saved_where);
}

/* if it is a new player-give him a racesoul */

static get_racesoul() {
    object ob;

    enable_commands();
    /*
     * Initilize the character stats, if not already done.
     */
    if (!stats_is_updated) {
	int tmp;
	tmp = level;
	if (tmp > 30)
	    tmp = 30;
	set_str(tmp); set_int(tmp); set_con(tmp); set_dex(tmp);
	set_wis(tmp); set_chr(tmp);
	stats_is_updated = 1;
    }
    /*
     * Now we can enter the game. Check tot_value if the game
     * crashed, and the values of the player was saved.
     */

    /*init_race_line();*/		/*HERP: obsolete*/
    add_standard_commands();
#ifdef MULTIGUILD
    add_spell_comands();
#endif

    move_object(clone_object("obj/soul"), myself);
    move_object(clone_object("obj/rsoul"), myself); 


    /* Here a player gets his race-soul */
    move_object(myself,RM->query_room());

    set_heart_beat(1);		/*HERP: don't do until move_object */

    called_from_ip = query_ip_number();
#if 0
    environment()->long();
    ob = first_inventory(environment());
    while(ob) {
	if (ob != this_object()) {
	    string sh;
	    sh = call_other(ob, "short");
	    if (sh)
		write(sh + ".\n");
	}
	ob = next_inventory(ob);
    }
#endif
    mylook(0);
    current_path = "players/" + name;
    set_living_name(name);
}

static move_player_to_start3(where) {
    int tmp_size, i;
    object ob,purg;
    string pt, *f;

    other_copy = find_player(name);
    if(!other_copy && (purg=find_object("/room/purgatory"))) {
	other_copy=present(name,purg);
	if(other_copy) {
	    if(!other_copy->query_level() || other_copy->query_npc())
		other_copy=0;
	}
    }
    enable_commands();
    if (other_copy) {
	write("other_copy: "+file_name(other_copy)+
	  " this_object "+file_name(other_copy)+"\n");
	write("You are already playing !\n");
	write("Throw the other copy out ? ");
	input_to("try_throw_out");
	return;
    }
    /*
     * Initilize the character stats, if not already done.
     */
    if (!stats_is_updated) {
	int tmp;
	tmp = level;
	if (tmp > apwz)
	    tmp = apwz;
	set_str(tmp); set_int(tmp); set_con(tmp); set_dex(tmp);
	set_wis(tmp); set_chr(tmp);
	stats_is_updated = 1;
    }
    /*
     * Now we can enter the game. Check tot_value if the game
     * crashed, and the values of the player was saved.
     */

    /*set_heart_beat(1);*/

    if(!race && !real_race) { 
	where=RM->query_room();
    }
#if 0
    else {
	if(!present("racesoul",myself)) 
	    move_object(clone_object(RM->query_soul()),myself);
    } 
#endif
    /*init_race_line();*/	/*HERP: obsolete*/
    add_standard_commands();
#ifdef MULTIGUILD
    add_spell_commands();
#endif
    SM->skill_commands();

    // ----- languages
    if ( !languages ) {                     // ----- create new array
       languages = allocate( NO_OF_LANG );
       for ( i = 1; i < NO_OF_LANG; i++ ) languages[i] = 0;
       languages[0] = 100;                    // always can speak common
    }
    else if ( NO_OF_LANG > sizeof(languages) ) {     // ----- expand the array
       int *tmp_arr, len;
       len = NO_OF_LANG - sizeof(languages);
       tmp_arr = allocate(len);
       for ( i = 0; i < len; i++ ) tmp_arr[i] = 0;
       languages += tmp_arr;
       languages[0] = 100;
    }
    languages[0] = 100;

    init_abilities();

    // init the feelings
    f = "masters/feelings"->all_feelings();
    i = sizeof( f );
    for ( --i; i >= 0; i-- )
       add_action( "exec_feeling", f[i] );

    move_object(clone_object("obj/rsoul"), myself);

    if (tot_value) {
	write("You find " + tot_value + " coins of your lost money!\n");
	money += tot_value;
	tot_value = 0;
    }
    load_auto_obj(auto_load);

    /* Herp 920703 */
    set_guild(guild);
    if(!query_immortal()) {
	title=GM->query_title(query_guild(),level,query_gender());
        pt=GM->query_pretitle(query_guild(),level,query_gender(),legend_level );
        if ( pt && pt != "" ) pretitle = pt;
    }

    /* Herp expander/speeder/oderwieauchimmer */
    reset_expander();
    std_fcn__reset(0);

    if (is_invis && level < apwz) set_vis();
    if (is_invis) write("YOU ARE INVISIBLE (level "+ is_invis+")!\n\n");
    "room/post"->query_mail();
    /* Check if there are new bugreports for this wizard, Cashimor */
    if(level>apwz) {
	tmp_size=file_size("/log/"+name+".rep");
	if((bug_file_size)&&(tmp_size>0)) {
	    if(bug_file_size!=tmp_size) {
		write("There are NEW bug reports in /log/"+name+".rep!\n");
		bug_file_size=tmp_size;
	    }
	}
	else {
	    bug_file_size=tmp_size;
	}
    }
    if (query_ip_number() != called_from_ip && called_from_ip)
	write("Your last login was from " + called_from_ip + "\n");
    called_from_ip = query_ip_number();
    if(!current_path) current_path = "players/" + name;
    set_living_name(name);
    fix_short();

    /*931010-HERP: new player.o file directory */
    /*save_object("/players/"+name);*/

    save_object("/p/"+to_string(({name[0]}))+"/"+name);

    if(start_at_guild) where = guild_room; 
    /* every important thing should be done before this one or in the 
       check_start_pos func! maybe there is an error in loading the startroom */
    call_out("check_start_pos",1,myself);
    if (where) {
	move_object(myself, where);
    } else move_object(myself, DEF_START);
    set_heart_beat(1);
}

check_start_pos(me) {
    object ob;
    if(!environment(me)) {
	write("\n\nError in loading start room: '"+start_where+"'.\n\n");
	move_object(me, DEF_START);
    }
    if (!is_linkdead)
	say(TName + " enters the game.\n",0,TP,""); /* Moonchild 031192 */
#if 0
    environment(me)->long(); /* Moonchild 081192 */
    ob = first_inventory(environment());
    while(ob) {
	if (ob != this_object()) {
	    string sh;
	    sh = call_other(ob, "short");
	    if (sh)
		write(sh + ".\n");
	}
	ob = next_inventory(ob);
    }
#endif
    mylook(0);
    if(level_changed) write(level_changed);
}

fix() {
    set_heart_beat(1);
    if (interactive(this_object())) enable_interactive(this_object());
    reset_expander();
    if(!prompt || sizeof(prompt)!=sizeof(DEF_PROMPT))
	prompt=DEF_PROMPT;
    return 1;
}

reconnect() {	/* like try_throw_out, but with no other_copy */
    object ob;

    if (link_return) {	/* do we have one anyway ? */
	catch(call_other(link_return,"???"));
	ob=find_object(link_return);
    }
    if (!ob) ob = find_object(DEF_START);
    tell_room("room/purgatory","Suddenly life returns to "+query_name()+"'s face.\n"+query_name()+" disappears.\n");
    move_player("X",ob);
    notify_reconnect(1);	/* silent */
    fix();
}

help(what) {
    string dummy;
    string keyword, help_file;
    mixed *spell_dat, *soc;
    int   i, max;

    notify_fail("No help available!\n");

    if (!what) {
	cat("/doc/help");
	return 1;
    }
  /* Airborne: logging for a while. */
    write_file("/log/HELP",
	this_player()->query_real_name() + " looked for help on: " +what+ "\n");

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
    if ( what == "social" || what == "socials" ) {
        SOCIAL_MASTER->show_feelings();
        return( 1 );
    }
    if ( what == "adverb" || what == "adverbs" ) {
        SOCIAL_MASTER->show_adverbs();
        return( 1 );
    }
    if(what == "expander" || what == "quicktyper") return help_expander();
    if(sscanf(what,"%s %s",keyword, what) == 2)
    {
	keyword = lower_case(keyword);
	switch(keyword)
	{
        case "spell":
            dummy = SPELL_MASTER->get_spell( what );
            if ( dummy ) write( dummy->spell_help() );
            else         write( "There is no such spell.\n" );
            return( 1 );
        case "ability":
            dummy = ABILITY_MASTER->get_ability( what );
            if ( dummy ) write( dummy->ability_help() );
            else         write( "There is no such special ability.\n" );
            return( 1 );
	default:;
	}
    };
    return 0;
}

all_spells( int arg )
{
   if ( !arg )
      SPELL_MASTER->all_spells( this_object(), -1 );
   else if ( GM->query_number( arg ) > 0 )
      SPELL_MASTER->all_spells( this_object(), GM->query_number( arg ) );
   else
      write( "This guild does not have spells.\n" );

   return( 1 );
}

all_abilities( int arg )
{
   if ( !arg )
      ABILITY_MASTER->all_abilities( this_object(), -1 );
   else if ( GM->query_number( arg ) > 0 )
      ABILITY_MASTER->all_abilities( this_object(), GM->query_number( arg ) );
   else
      write( "This guild does not have special abilities.\n" );

   return( 1 );
}

all_skills( int arg )
{
   if ( !arg )
      SKILL_MASTER->all_skills( this_object(), -1 );
   else if ( GM->query_number( arg ) > 0 )
      SKILL_MASTER->all_skills( this_object(), GM->query_number( arg ) );
   else
      write( "This guild does not have special skills.\n" );

   return( 1 );
}

tell_player(str) {
    object ob;
    string who,msg;
    string myname;

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
	write("That person is busy right now, try again later.\n");
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

    /* Matt 6-12-94: tell should not say "Someone" to higherups */
    if(ob->query_level() >= level) myname = capitalize(name);
    else myname = query_name();
    tell_object(ob, lw(myname + " tells you: " + msg + "\n"));

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
    say((TName + " whispers something to " + who + ".\n"), ob,TP,
      (capitalize(who) + " seems to listen carefully.\n"));
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
	    say(TName + " drops " + out,0,TP,
	      capitalize(it)+" appears from thin air.\n");
	    tell_object(myself, "drop: " + out);
	}
	ob = next_ob;
    }
}

static bug(str)
{
    if (!str) {
	write("Give an argument.\n");
	return 1;
    }
    log_file("BUGS", "\n");
    log_file("BUGS",capitalize(name)+" "+ctime(time())+" ("
      + file_name(environment(this_object())) + "):\n");
    log_file("BUGS", str + "\n");
    smart_report("Bug "+capitalize(name)+"\n"+str);
    write("Thank you!\n");
    return 1;
}

static typo(str)
{
    if (!str) {
	write("Give an argument.\n");
	return 1;
    }
    log_file("TYPO",capitalize(name)+" "+ctime(time())+" ("
      + file_name(environment(this_object())) + "):\n");
    log_file("TYPO", str + "\n");
    smart_report("Typo " +capitalize(name)+ "\n" + str);
    write("Thank you!\n");
    return 1;
}

static idea(str)
{
    if (!str) {
	write("Give an argument.\n");
	return 1;
    }
    log_file("IDEA",capitalize(name)+" "+ctime(time())+":\n");
    log_file("IDEA", str + "\n");
    smart_report("Idea " +capitalize(name)+ "\n" + str);
    write("Ok.\n");
    return 1;
}

static converse()
{
    write("Give '**' to stop.\n");
    write("]");
    input_to("converse_more");
    return 1;
}

static converse_more(str)
{
    string cmd;
    if (str == "**") {
	write("Ok.\n");
	return;
    }
    if (str[0] == '!') {
	sscanf(str, "!%s", cmd);
	command(cmd);
    } else if (str != "") {
	say(lw(TName + " says: " + str + "\n"),0,TP,
	  lw(IName + " says: " + str + "\n"));
    }
    write("]");
    input_to("converse_more");
}

static toggle_whimpy(arg)
{
    int tmp,max;

    if(arg && arg=="brave") arg="-1";
    if (arg && sscanf(arg,"%d",tmp))
    {

	if(tmp < -1) tmp=-1;
	max = 20+2*this_player()->query_wis();
	if(tmp > max)
	{
	    tmp = max;
	    write ("Not even you are that wimpy!\n");
	}
	whimpy = tmp;

	if(tmp == -1)
	{
	    write("You are in brave mode now!\n");
	}
	else
	{
	    write("Wimpy changed to "+whimpy+"%\n");
	}
    }
    else write("Give an argument in percent.\n");
    return 1;
}

static set_wimpydir(arg) {
    if(arg) {
	switch(arg) {
	case "n":  arg="north"; break;
	case "nw": arg="northwest"; break;
	case "w":  arg="west"; break;
	case "sw": arg="southwest"; break;
	case "s":  arg="south"; break;
	case "se": arg="southeast"; break;
	case "e":  arg="east"; break;
	case "ne": arg="northeast"; break;
	case "u":  arg="up"; break;
	case "d":  arg="down"; break;
	case "off":
	case "none":
	    env_var["WIMPYDIR"]=0;
	    write("Wimpydir switched off.\n");
	    return 1;
	    break;
	}
	env_var["WIMPYDIR"]=arg;
    }
    write("Wimpydir set to: " + env_var["WIMPYDIR"] + ".\n");
    return 1;
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

add_exp(e) 
{
   int max;

// this are the max exp a player can get at once 
   max = funcall(call,this_object(),"query_level") * 1500;

#ifdef LOG_EXP
    if (this_player() && this_player() != this_object() &&
      query_ip_number(this_player()) && level < apwz && e >= ROOM_EXP_LIMIT)
	log_file("EXPERIENCE", ctime(time()) + " " + name + "(" + level +
	  ") " + e + " exp by " + this_player()->query_real_name() +
	  "(" + this_player()->query_level() + ")" +"\n");
#endif
    /* Effect of religion: if inappropriate alignment, no XP! */
    /* Uglymouth: but improvings stats and skills should still cost xp! */
    if(e>0 && !RLM->query_ok(religion,alignment)) return 1;

    if (e > max)
        e = max;
    experience += e;
}

/* This routine is needed when one wants to circumvent the alignment
   restrictions by religion, this function may only be called by other
   wizards, and never from objects. */

add_experience(e) {
#ifdef LOG_EXP
    if (this_player() && this_player() != this_object() &&
      query_ip_number(this_player()) && level < apwz && e >= ROOM_EXP_LIMIT)
	log_file("EXPERIENCE", ctime(time()) + " " + name + "(" + level +
	  ") " + e + " exp by " + this_player()->query_real_name() +
	  "(" + this_player()->query_level() + ")" +"\n");
#endif  
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

add_poison(i)           // (pat) consider savings
{
   if ( i <= 0 ) {         // always allow lowering poison
      poisoned += i;
      if ( poisoned < 0 )
         poisoned = 0;
   }
   else {
      switch( do_save( AGGRESSIVE, POISON, 0, 0, 0 ) ) {
         case SAVED:
            if( poisoned >= i ) poisoned++;
            else                poisoned = (i/2>0 ? i/2:i);
            break;
         case SAVE_FAILED:
            if( poisoned >= i ) poisoned += (i>2 ? 2:i);
            else                poisoned = i;
            break;
      }
   }
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

query_poisoned()
{  
    return poisoned;
}

second_life() {
#if 1
    object death_mark;
#endif
    int i,x,w,force_enter;
    string who_killed, env_kill;

    string tpn, pon, ek;

    if ( this_player() )     tpn = this_player()->query_real_name();
    else                     tpn = "NO TP";
    if ( previous_object() ) pon = file_name(previous_object());
    else                     pon = "NO PO";
    if ( environment(this_object()) ) ek=file_name(environment(this_object()));
    else                     ek = "NO ENV";
    
    log_file( "SECOND_LIFE", "PO: "+pon+", TP: "+tpn+", TO: "+query_real_name()+
                             ", ENV: "+ek+"\n" );

    if (level >= apwz) {
	return illegal_patch("second_life");
        return( 1 );
     }
    make_scar();
    ghost = 1;
    tell_object(myself, "\nYou die.\nYou have a strange feeling.\n" +
      "You can see your own dead body from above.\n\n");

    force_enter = level > 1 ? 1 : 0;
    while(query_perc_advance_lev()<0 || force_enter )
    {
        if ( legend_level > 0 ) legend_level--;   // consider legends too
        else                level--;
        x=random(3)+2;
        for(i=0;i<x;i++) {
            w=random(6);
	    if(stats[w]>RM->query_basic_stat(real_race,w) && stats[w]>1)
                stats[w]--;
        }
        tell_object(this_object(),"YOU LOSE A LEVEL!\n");
        force_enter = 0;
    }
    set_savings(level,1);

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
#ifdef LOG_KILLS
    if (attacker_ob)
    {
	who_killed = attacker_ob->query_name()+" ("+
                      attacker_ob->query_level()+") ";
    }
    else  if (this_player()) 
    {
	if (this_player() && interactive(this_player()) )
	{
	    who_killed = this_player()->query_real_name()+
	    " ("+this_player()->query_level()+") ";
	}
	else if (living(this_player()))
	{
	    who_killed = this_player()->query_name()+
	    " ("+this_player()->query_level()+") ";
	}
	else 
	    who_killed = file_name(this_player());
    }
    else if ( environment() )
       who_killed = file_name(environment());
    else
       who_killed = "UNDEFINED !!!";

    if (stringp(who_killed)) {
        if ( environment(this_object()) )
           env_kill = file_name(environment(this_object()));
        else env_kill = "no environment !";
	log_file("KILLS", name + "(" + level + ")" + " killed by " + who_killed+
	  "\nat "+ctime(time())+" in "+ env_kill +"\n");
    } 
    else 
    {
	object ob;
	log_file("KILLS", name + "(" + level + ")" + " died. "+
	  ctime(time())+"\n");
	log_file("KILLS.ODD", name + "(" + level + ")" + " died. ");
	log_file("KILLS.ODD", "Poison level: " + poisoned + ".\n");
	if(previous_object()) {
	    log_file("KILLS.ODD", "Previous object: "
	      + file_name(previous_object()) + ", ");
	    if(living(previous_object()) && !previous_object()->query_npc())
		log_file("KILLS.ODD", "(" + previous_object()->query_real_name()
		  + "), ");
	}
	else log_file("KILLS.ODD", "No previous object, ");
	log_file("KILLS.ODD", "Environment of player: "
	  + file_name(environment(myself)) + "\nObjects in environment:\n");
	ob=first_inventory(environment(myself));
	while(ob) {
	    log_file("KILLS.ODD", ob->short() + " [" + file_name(ob) + "]\n");
	    ob=next_inventory(ob);
	}
	log_file("KILLS.ODD", "Objects in player:\n");
	ob=first_inventory(myself);
	while(ob) {
	    log_file("KILLS.ODD", ob->short() + " [" + file_name(ob) + "]\n");
	    ob=next_inventory(ob);
	}
    }
#endif

    attacker_ob = 0;
    grouped = 0;
    if(follow_whom) follow();
    if(query_followers()) 
	for(i=0;i<sizeof(follow_obj);i++) command("follow",follow_obj[i]);

#if 0
    death_mark = clone_object("/room/death/death_mark");
    move_object(death_mark, myself);
#endif
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
    say(TName + " appears in a solid form.\n",0,TP,
      IName + " appears in a solid form.\n");
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


stop_hunting_mode()                // players do not hunt anymore ! (260295)
{
   write("You are not hunting anyone.\n");
   return 1;
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
	say(TName+" gives "+coins+" coins to "+dest_ob->query_name()+".\n",
	  dest_ob,TP,
	  IName+" gives "+coins+" coins to "+dest_ob->query_name()+".\n");
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
	say(TName+" tossed "+it+" through "+na+".\n",dest_ob,TP,
	  IName+" tossed "+it+" through "+na+".\n");
	tell_object(dest_ob,CName+" tossed "+it+" through you.\n");
	tell_room(e=environment(this_object()),
	  capitalize(it)+" falls on the floor.\n");
	move_object(item_ob,e);
	return 1;
    }
    add_weight(-weight);
    move_object(item_ob, dest_ob);
    say(TName + " gives " + item + " to " + capitalize(dest) + ".\n",0,TP,
      IName + " gives " + item + " to " + capitalize(dest) + ".\n");
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
		say(TName + " takes: " + item + ".\n",0,TP,
		  IName + " takes: " + item + ".\n");
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
	say(TName + " makes a magical gesture.\n",0,TP,"");
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

save_me(value_items)
{
    if (value_items)
	tot_value = compute_values(first_inventory(this_object()));
    else
	tot_value = 0;
    compute_auto_str();
    /*931010 HERP: new player.o directory */
    /*save_object("players/" + name);*/

    master_object()->set_guild_head(query_guild(), this_object());
    save_object("p/" + to_string(({name[0]})) +"/"+name);
}

illegal_patch(what) {
    write("You are struck by a mental bolt from the interior of the game.\n");
    log_file("ILLEGAL", ctime(time()) + ":\n");
    log_file("ILLEGAL",
      call_other(this_player(), "query_real_name") + " " +
      what + "\n");
    return 0;
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
#if 0
	if(ob) {
#else
	if (!dum) {		/*herp*/
#endif
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
    log_file(who+".rep",current_room+" "+ctime(time())+"\n"+str+"\n");
}

time_out() {
    write("Time out.\n");
    destruct(this_object());
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
//    add_action("process_spell","cast");  /* INVALID NOW: remove it ! */
    add_action("converse", "converse");
    add_action("drop_thing", "drop");
    add_action("set_description","describe"); /* Moonchild 301092 */
    add_action("set_line_number", "lines"); /* Moonchild 220693 */
    add_action("examine", "exa", 1); // why changed to examine? moonchild 110893
    add_action("follow","follow");	/* following and grouping */
    add_action("fix","fix");
    add_action("pick_up", "get");
    add_action("give_object", "give");
    add_action("group","group");
    add_action("help", "help");
    add_action("all_spells", "allspell", 8 );
    add_action("all_abilities", "allabilit", 9 );
    add_action("all_skills", "allskill", 8 );
    add_action("show_hp","hp");
    add_action("inventory", "i");
    add_action("idea", "idea");
    add_action("incognito","incognito");
    add_action("kill", "kill");
    add_action("look", "l"); // moonchild 120893
    add_action("look", "look");
    add_action("put", "put");
    add_action("powerup","powerup");
    add_action("pose", "pose");
    add_action("c_prompt","prompt");
    add_action("pray_it","pray");
    add_action("quit", "quit");
    add_action("rid","rid");            /*  -- Llort 930123 */
//    add_action("communicate", "say");        // pat (languages)
    add_action("save_character", "save");
    add_action("score", "score");
    add_action("search_it", "search");  /* Moonchild 150793 */
    add_action("stop_hunting_mode", "stop");
//    add_action("shout_to_all", "shout");     // pat (languages)
    add_action("smell_it", "smell");    /* Moonchild 140793 */
//    add_action("tell_player", "tell");       // pat (languages)
    add_action("pick_up", "take");
    add_action("typo", "typo");
    add_action("who", "who");
    add_action("whisper", "whisper");
    add_action("toggle_whimpy", "wimpy");
    add_action("set_wimpydir", "wimpydir");
//    add_action("communicate", "'", 1);       // pat (lanaguages)

    add_action("action_set_title", "title" );  // pat, enabled for legends
    add_action("arena", "arena" );             // the blood-bath !
    add_action("do_junk", "junk" );            // get rid of something

    add_action("prac_help", "prac", 4 );
    add_action("memorize","memorize");
    add_action("forget","forget");

    // ----- communication ---------------------------
    add_action( "l_say",   "say"   );
    add_action( "l_say",   "'", 1  );
    add_action( "l_tell",  "tell"  );
    add_action( "l_shout", "shout" );
    add_action( "l_speak", "speak" );

    // ----- spells/savings.... -----------------------
    add_action( "show_savings", "savings" );
    add_action( "nprocess_spell", "cast" );

    // ----- the rest ...------------------------------
    add_action("do_rest","rest");
    add_action("do_stand","stand");

    add_action("do_world","world");

    add_action("turn_visible","visible");

    init_expander();
    std_fcn__init();
}

/*   -------------------- the rest ------------------------------- */

// here to shadow for the meditation skills ect ...........
int query_heal_if_rest()
{
    if (query_con() < query_int())
        return 1 + query_max_sp()/100;
    return 1 + query_max_hp()/100;
}

string query_rest_obj_path()
{
    return "/sys/rest_obj";
}

int do_rest(string arg)
{
    object rest_obj, vic;

    if (arg)
        return 0;

    vic = funcall(call,this_object(),"query_attack");
    rest_obj = present("rest_obj",this_object());

    if (vic && environment()==environment(vic))
    {
        write("No way, you are fighting for your life !\n");
        return 1;
    }
    else if (objectp(rest_obj))
    {
       is_resting = 1;
       notify_fail("You are already resting.\n");  
       return 0;
    }
    write("You sit down to rest your tired bones.\n");
    say(query_name()+" sits down and rests.\n",this_object());
    rest_obj = clone_object(funcall(call,this_object(),"query_rest_obj_path"));
    is_resting = 1;
    move_object(rest_obj,this_object());
    return 1;
}

int do_stand(string arg)
{
    object rest_obj;

    if (arg)
        return 0;

    rest_obj = present("rest_obj",this_object());

    if (!objectp(rest_obj))
    {
       is_resting = 0;
       notify_fail("You are not resting.\n");  
       return 0;
    }
    write("You stop resting.\n");
    say(query_name()+" stands up.\n",this_object());
    destruct(rest_obj);
    is_resting = 0; 
    return 1;
}

varargs int attack( object weapon, int hands)
{
   object rest_obj;

   if (is_resting)
   {
       is_resting = 0;
       rest_obj = present("rest_obj",this_object());
       if (rest_obj)
           destruct(rest_obj);
       write("You stop resting.\n");
       say(query_name()+" stands up.\n",this_object());
   }
   return ::attack(weapon,hands);
}


string look_info(int flag)
{
    if (is_resting)
        return " (resting)";
    else 
        return "";
}

int query_is_resting()
{
    return is_resting;
}



         
query_prevent_shadow() { return 0; }	/* Herp: Shadowing is allowed */
query_linkdeath() { return is_linkdead; }
query_invis() { return is_invis; }
query_vis() { return !query_invis(); }
query_guild() { return guild; }

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
	write("Victim's HP turned "+(prompt[5]? "on.\n":"off.\n")); 
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
	write("All prompt options set.\n");
	break;
    case "none": prompt=({ 0,0,0,0,0,0,0,0 });
	write("All prompt options reset.\n");
	break;
    case "default": prompt=DEF_PROMPT;
	write("Prompt reset to default.\n");
	break;
    default:
	notify_fail("Type 'help prompt' for more help on prompts.\n");
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
    fix_short();
    return 1;
}

set_invis(a) { 
    if (this_player()==this_object()) {
	if (!a) is_invis=L_PLAYER; 
	else is_invis=to_int(a);
	if((is_invis > level && (this_player()->query_immortal()) )
	  || (is_invis > L_PLAYER && !this_player()->query_immortal()))
	    is_invis=level;
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

#if 0
    write("set_guild "+i+"\n");
#endif

    if (!intp(i)) return write("Non numeric value to set_guild(): "+i+"\n");
    if (i<0 || i>GM->query_nog()) return write("illegal guild value to set_guild(): "+i+"\n");

    (level==-1?(lvl=1):(lvl=level));      /* new player */

    /* Calculate the quest points now */

    convert_quests(); 
    calc_quests();

    /* Changing the guild requires to remove the old soul. */
    if (guild && guild!=i && (ob=present(GM->query_id(guild),this_object()))) {
	ob->guild_changes();
	destruct(ob);
    }

    /*161093 HERP: centralized chat daemon */
    CD->remove_chat(this_object(),guild);	/* remove old guild */
    CD->add_chat(this_object(),i);	/* add new guild */

   if (name != this_player()->query_real_name())
    {    
    log_file("GP",ctime(time())+ " " + name + " guild set to " + i + 
              " by " + this_player()->query_real_name() + "\n");
    }
    guild=i; 
    guild_name=GM->query_name(i); 
    guild_wiz=GM->query_wiz(i);
    guild_room=GM->query_room(i);
    guild_soul=GM->get_soul(i);

    apwz=GM->query_levels(i);             /* Set wizard levels */
    fwz=apwz+1;

    /* if (guild_wiz && !is_wizard) { */
    if (!is_wizard) {
	str=GM->query_pretitle(guild,lvl,gender);  /* pretile */
	if (str) set_pretitle(str);
	else set_pretitle("none");
	str=GM->query_title(guild,lvl,gender);     /* title */
	if (str) set_title(str);
	else set_title("none");
    }

    for (i=0;i<NUM_STATS;i++) set_stats(i,query_r_stats(i));/* Adjust max_hp/sp */

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
    /* 28-APR-94 Galadriel: added '!= ""' to fix bug */
    if (!incognito && pretitle != "") cap_name = pretitle + " " + cap_name; 
}

/* Moonchild 211092 */
/* 921119 Herp: some minor changes ... */

dest_ldead() {
    object *ob;
    int i;
/*
    if (query_ip_number(this_object())) {
	tell_object(this_object(),"LINKDEAD arrives and tries to kill you !\n"+
	  "Pray to Herp, he's blessing you !\n");
	log_file("LINKDEAD",file_name(this_object())+" "+ctime(time())+".\n");
	return;

    }
*/
    move_object(this_object(),"room/void");
    add_money(tot_value);
    "room/void"->clean_room(0);
    quit(1);
    /***
      ob=deep_inventory(find_object("room/void"));
      for (i=0;i<sizeof(ob);i++) if (!(interactive(ob[i]))) destruct(ob[i]);
    ***/

}

/* 921120 Herp: we have to remove the destruct-ldead call-out here */

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

/* 121292 Llort configerable add_actions required for the skill sys */
/* is function is only to be called from the skillmaster */

int add_skill_action(string action,int force) {
    if(file_name(previous_object())!=SM) return 0;
    if(guild != 7) return 0;
    if(!force) if(query_actions(this_object(),action)) return -1;
    add_action("process_skill",action);
    return 1; 
}

/* the following function is the link via the skill_master to the
   objects that process the action. */
/* removed the static, didn't worked at player (pat) */

int process_skill(string arg) {
    return (int)SM->process_skill( arg );
}

/* 160293: pray (for religion) by Ethereal Cashimor */

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

set_incognito(i) { incognito=i; fix_short(); }
query_incognito() { return incognito; }

static fix_short() { /* Moonchild 290793 */
    if(incognito)
	env_var["SHORT"]=capitalize(name) + (real_race ? " the " +
	  capitalize(real_race) : "");
    else
	/* 28-APR-94 Galadriel: added '!= ""' to fix the who list bug */
	env_var["SHORT"]=(pretitle != "" ? pretitle + " " : "") + capitalize(name)
	+ (level < 30 ? " the "
	  + capitalize((string)RM->query_adverb(real_race)) : "")
	+ (title ? " " + title : "");
}

nomask int query_immortal()     { return level>29; }
nomask int query_newwiz()       { return level>30; }
nomask int query_wizard()       { return level>32; }
nomask int query_lord()         { return level>39; }
nomask int query_archwiz()      { return level>49; }
nomask int query_implementor()  { return level>50; }

int memorize(string arg)
{
  mixed old;
  mapping memo;
  int i;
  string tmp,*names,*sites,sh;

  memo = this_object()->queryenv("MEMORIZE"); 
  if(!memo) memo=([]);
  if(!arg)
  { 
    if(!m_sizeof(memo))
    {
       write("You've got nothing memorized at all.\n");
    }
    else
    {
       names=m_indices(memo);
       sites=m_values(memo);
       tmp="Your memorized sites are:\n";
       for(i=0;i<m_sizeof(memo);i++)
       { 
          if(catch(sh=sites[i]->short()) || !sh)
            memo=m_delete(memo,names[i]);
          else
            tmp+=sprintf("%-10s  %s\n",names[i],sh);
       }
       write(tmp);
    }
  }
  else 
  {
     old = memo[arg];
     if(old)
     {
        memo[arg]=file_name(environment(this_player()));
        write("Site '"+arg+"' has been changed to this location.\n");
     }
     else
     {
	if(m_sizeof(memo)>=this_player()->query_int()/2+2)
	{
           write("You've already reached your mental limit.\n");
	} 
        else
        {
           memo[arg]=file_name(environment(this_player()));
           write("You'll remember this place as '"+arg+"'\n");
        }
     }
  } 
  this_player()->setenv("MEMORIZE",memo);
  return 1;
}

int forget(string arg)
{
  mapping memo;

  notify_fail("Forget what?\n");
  if(!arg) return 0; 

  memo=this_player()->queryenv("MEMORIZE");
  if(!memo) memo=([]);
  if(!m_sizeof(memo) || !memo[arg])
  {
    write("You didn't even know that place.\n");
  }
  else
  {
    memo=m_delete(memo,arg);
    write("You forgot that place.\n");
  }
  this_player()->setenv("MEMORIZE",memo);
  return 1;
}

// ------- the new commu-stuff, including languages (pat) --------------
int l_say( string str ) 
{
    string verb;

    verb = query_verb();
    if (str == 0)
	str = "";
    if (verb[0] ==39) 
	str = extract(verb, 1) + (str?" ":"")+ str;

    lsay( "says:", str + "\n", TP, TP );
    writelw("You say: " + str + "\n");

    return( 1 );
}

int l_tell( string str )
{
    object ob;
    string who,msg;
    string myname;

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
	write("That person is busy right now, try again later.\n");
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
//        return( 1 );
    }
    if ( funcall(call,ob,"is_afk") ) {
       write( "This player is afk.... message sent anyway...\n" );
    }
    /* 21-SEP-93 Galadriel: quick fix, check npc or query_idle will bug */
    if((int)query_ip_number(ob))
	if(query_idle(ob)>300) write("That player is idle. Message sent anyway.\n");
    if (!query_immortal() && !ob->query_immortal()) spell_points-=5;

    /* Matt 6-12-94: tell should not say "Someone" to higherups */
    if(ob->query_level() >= level) myname = capitalize(name);
    else myname = query_name();

    ltell( ob, "tells you:", msg + "\n", this_object() );
    writelw("You tell "+capitalize(it)+": "+msg+"\n");
    return 1;
}

int l_shout( string str )
{
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
    log_file("PLAYSHOUTS", capitalize(name) + ": " + str + "\n"); /*Moonchild*/

    lshout( "shouts:", str+"\n", this_object() );
    write( "You shout: "+str+"\n" );
    return 1;
}

int l_speak( string lang )
{
   int i;

   if ( !lang ) {
      write( "Languages:\n-------------------------------\n" );
      for ( i = 0; i < NO_OF_LANG; i++ )
         printf( "%-15s %15s\n", language_name(i),
                                 language_skill_name(language_skill(i)) );
      write( "\nYou are speaking in: "+language_name(speaks_in()) );
      write( "\n-------------------------------\n" );
      return( 1 );
   }

   if ( lang == "common" )         set_speaks_in( 0 );
   else if ( lang == "nihonese" )  set_speaks_in( 1 );
   else {
      write( "There is no such language.\n" );
      return( 1 );
   }

   write( "You will now speak in "+lang+".\n" );

   return( 1 );
}

// kind: 1 = say, 2 = tell, 3 = shout, 4 = system
int lcatch_tell( string act, string msg, object who, int kind )
{
   if ( !who || !interactive(this_object()) 
        || !environment(this_object()) )
   {
      return( 0 );
   }

   if ( query_editing(this_object()) ) return( 0 );
   if ( kind != 1 && this_object()->query_earmuff_level() > who->query_level() )
      return( 0 );
   if ( kind == 3 && this_object()->query_noshouts() )
      return( 0 );

//   if ( query_input_pending(this_object()) ) return(0);

   return( ::lcatch_tell( act, msg, who, kind ) );
}

int show_savings( string arg )
{
   write( base_savings_info() );
   return( 1 );
}


int start_in_guild(int bool)
{
    if(file_name(environment(this_object())) != guild_room) return -1;
    start_at_guild = bool;
    return bool;
}

int allowed_attack( object at_whom )
{
   if ( funcall(call,at_whom,"query_player") && at_whom != this_object() ) {
      if( is_pk && funcall(call,at_whom,"query_is_pk") )
         return( ::allowed_attack( at_whom ) );
      else if ( funcall(call,environment(this_object()),"query_arena") )
         return( ::allowed_attack( at_whom ) );
      else {
         return( 0 );
      }
   }
   return( ::allowed_attack( at_whom ) );
}

int query_is_pk() { return( is_pk ); }

nomask void set_pk()
{
   if ( is_pk ) {
      write( "This player is already pk.\n" );
      return;
   }

   if ( this_player()->query_archwiz() ) {
      is_pk = 1;
      write( "This player is now pk.\n" );
      tell_object( this_object(), "You now have a PK license.\n" );
      log_file( "PKS", this_player()->query_real_name()+" set pk at "+
                       this_object()->query_real_name()+"\n"+
                       ctime(time())+"\n" );
      save_me(1);
   }
   else {
      write( "You are not allowed to do this !!! (logged)\n" );
      log_file( "PKS", this_player()->query_real_name()+" TRIED TO SET pk at "+
                       this_object()->query_real_name()+" !!!!!!!!!!\n"+
                       ctime(time())+"\n" );
   }
}

nomask int add_practice_sessions(int s)
{
   if(level+legend_level <= last_practice_level) return -1;
   if(s<0) return -1;
   practice_sess+=s;
   last_practice_level=level+legend_level;
   return practice_sess;
}

nomask int practice_sessions()
{
   return practice_sess;
}

nomask int modify_practice(int mod)
{
   if(this_player()->query_real_name() != guild_wiz &&
      file_name(previous_object())!=guild_room) return -1;
   practice_sess=mod;
   return practice_sess;
}

nomask int update_practice()
{
   if(file_name(previous_object())!=guild_room) return -1;
   practice_sess=call_other(guild_room,"update_practice",this_object());
   return practice_sess;
}

nomask int decrease_practice_sessions()
{
   if(practice_sess < 1) return -1;
   return practice_sess--;
}

int practice_level()
{
   return last_practice_level;
}

int do_world()
{
   write(GM->world_data()); 
   return 1;
}

string start_where()
{
   return start_where;
}

int turn_visible()
{
   // this function is only the target for the 'visible' command
   // it is supposed to be shadowed
   return 0;
}

int arena( string arg )
{
   if ( arg == "enter" ) {
      if ( environment() && environment()->query_property("no_teleport") ) {
         write( "You cannot enter the arena from here.\n" );
      }
      else if ( ARENA->allow_enter( this_object() ) ) {
         ARENA->arena_shout( capitalize(query_real_name())+
                             " entered the bloodbath !\n" );
         TP->move_player( "to the arena#"+ARENA );
         hit_point = max_hp;
         spell_points = max_sp;
      }
      else
         write( "You are not allowed to join the bloodbath !\n" );
   }
   else if ( arg == "champions" )
      ARENA->do_show( "champions" );
   else if ( arg == "cheaters" )
      ARENA->do_show( "cheaters" );
   else
      ARENA->show_open( this_object() );

   return( 1 );
}

int do_junk(string arg)
{
    object item;
    int value;

    if ( !arg ) {
       notify_fail("Junk what ?");
       return( 0 );
    }

    item = present(arg,this_object());

    if ( !item || !stringp(item->short()) )
    {
        notify_fail("Junk what ?\n");
        return 0;
    }
    else if (objectp(item->query_wielded()))
    {
        notify_fail("First you have to unwield your "+arg+".\n");
        return 0;
    }
    else if (objectp(item->query_worn()))
    {
        notify_fail("First you have to remove your "+arg+".\n");
        return 0;
     }
     value = item->query_value();
     if ( value > 0 ) value /= 10;
     if (value > 100) value = 100;
     
     write("You junk the "+arg+".\n" );
     say(query_name()+" junks "+query_possessive()+ " "+arg+".\n");
     destruct(item);

     if ( value > 0 ) {
        write( "You are rewarded for keeping your environment tidy.\n");
        add_money( value );
     }

    return 1;
}

int exec_feeling( string arg )
{
   return( "/masters/feelings"->exec_feeling( query_verb(), arg ) );
}     


