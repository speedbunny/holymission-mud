/* ################################################################
   #								  #
   #    		Mage guild master                         #
   #                                          		          #
   ###############################################(C) Llort######## */

#include 	"spells/mage.h"
#include 	"tune.h"	/* for tuning the mages powers */

#define GM	"guild/master"
#define GUILD	"mage"

mapping xp_list;

init() {
    add_action("dump","dump");
}

/* #############	check if the spell fizzles	########### */

chk_fiz(lvl,pl) {
int i;
object ob;
/*
  if(TP->query_intoxination()>ALLOWED_INTOXINATION) {
    write("You cant do this while intoxicated.\n");
    return 1;
  }
*/
  ob=all_inventory(TP);
  for(i=0;i<sizeof(ob);i++) 
    if(ob[i]->query_worn()) {
      if(!(ob[i]->query_mage_wear() || (ob[i]->armour_class()==0))) {
        ME("The "+ob[i]->query_name()+" makes your spell fizzle.\n"+
           "Don't you know, you are not allowed to wear all armours.\n" +
 	   "(use check <armour> to be sure!)\n");
        return 1;
      }
    }
  if((!TP->query_immortal())&&(random(100)>CHK_FIZZEL)) {
    ME("Due to a lack of concentration the spell fizzels.\n");
    return 1;
  }
  return 0;
}

static int spells;					/* spell info */
static int max_stats;
static int gd;

static string dir;					/* guild directory */
static string helpdir;					/* guild helpdir */
static string chamber;					/* guild chamber */
static string shorttmp;				/* used in illusion */
static string longtmp;					/* deto */
static string nametmp;					/* deto */
static string med_title;

static object att;					/* Global: attacker */
static object owner;					/* Owner of the soul */

reset(arg) {
  if (arg)
  {
     save_object("players/llort/guild/magemaster");
     return;
  };
  gd=GM->query_number(GUILD);
  max_stats=GM->query_levels(gd);
  dir=GM->query_dir(gd);
helpdir="/players/saffrin/guild/oldhelp";
  chamber=dir+"/tower/chamber";
  set_light(1);
  spellcost(1);
  xp_list = ([ ]);
  restore_object("players/llort/guild/magemaster");
}

short() { return "The Heart of the magic planes"; }
long() { write("This is the Heart or the magic planes.\n"); }

spellcost(wis) {
spells= ({
	({ 0,	"staff",	STAFF_SP,	STAFF_LVL }),
/*      ({ 0,	"pose",		POSE_SP,	POSE_LVL }), */
/*   	({ 0,	"prison",      	PRISON_SP,	PRISON_LVL }), */
/*	({ 0,	"eye",		EYE_SP,		EYE_LVL }),  */
	({ 0,	"hold",		HOLD_SP,	HOLD_LVL }),
/*	({ 0,	"meditate",	MEDITATE_SP,	MEDITATE_LVL }), */
/*      ({ 0,   "fireshield",   FIRESHIELD_SP,  FIRESHIELD_LVL }), */
/*      ({ 0,   "strength",     STRENGTH_SP,    STRENGTH_LVL }), */
	({ 0,	"detect",	DETECT_SP,	DETECT_LVL }),
	({ 0,	"melt",		MELT_SP,	MELT_LVL }),
	({ 0,	"illusion",	ILLUSION_SP,	ILLUSION_LVL }),
/*	({ 1,	"missile",	MISSILE_SP,	MISSILE_LVL }), */
/*	({ 1,	"colorspray",	COLORSPRAY_SP,	COLORSPRAY_LVL }), */
/*	({ 1,	"crush",	CRUSH_SP,	CRUSH_LVL }), */
/*	({ 1,	"disintegrate",	DISINT_SP,	DISINT_LVL }),   */
/*	({ 1,	"fireball",	FIREBALL_SP,	FIREBALL_LVL }),  */
/*	({ 1,	"blast",	BLAST_SP,	BLAST_LVL }), */
	({ 0,	"locate",	LOCATE_SP,	LOCATE_LVL }),
/*	({ 0,	"tame",		TAME_SP,	TAME_LVL }),  */
/*	({ 0,	"gate",	       	GATE_SP,	GATE_LVL }),  */
/*	({ 0,	"teleport",	TELEPORT_SP,	TELEPORT_LVL }), */
/*	({ 0,	"memorize",	MEMORIZE_SP,	MEMORIZE_LVL }), */
/*	({ 0,	"fear",		FEAR_SP,	FEAR_LVL }),  */
/*	({ 0,	"invisible",	INVISIBLE_SP,	INVISIBLE_LVL }), */
/*	({ 0,	"visible",	VISIBLE_SP,	VISIBLE_LVL }), */
	({ 0,	"feeble",	FEEBLE_SP, 	FEEBLE_LVL }),
/*	({ 0,	"goguild",	GOGUILD_SP,	GOGUILD_LVL }), */
/*	({ 0,	"goback",	GOBACK_SP,	GOBACK_LVL }), */
/*	({ 0,	"mage",		MAGE_SP,	MAGE_LVL }),   */
	({ 0, 	"guild",	1,	 	1 }),
/*	({ 0,	"light",	LIGHT_SP,	LIGHT_LVL }),	*/
/*	({ 0,	"Knock", 	KNOCK_SP,	KNOCK_LVL }),   */
/*	({ 0,	"shield",	SHIELD_SP,	SHIELD_LVL }),  */
/*	({ 0,	"stoplight",	STOPLIGHT_SP,	STOPLIGHT_SP }),*/
/*	({ 0,   "lastlight",	LASTLIGHT_SP,	LASTLIGHT_LVL })*/
	});
} 

/* #######	get spellnr of the spell sp 	######## */

spellnr(sp) {
int i;
  for(i=0;i<sizeof(spells);i++) if (spells[i][1]==sp) return i;

  return -1;
}

chk_spell(sp) {
  return spellnr(sp) == -1 ? 0 : 1;
}

/* ######	try to wear the armour	    ##### */

check(arg,pl) {
object ob; 

  if(!arg) {
    ME("Check what ?\n");  
    return 1;
  }

  if(ob=present(arg,TP)) {
    if(!ob->query_type()) {
      ME("That is no armour.\n");
      return 1;
    }
    ME("After a closer examination of the "+ob->short()+",\n"+
          "you think you are ");
    if(!(ob->query_mage_wear() || (ob->armour_class()==0))) ME("not ");
    ME("allowed to wear this armour.\n");
    OTHERS(({ TP }),TPN+" examines an armour.\n");
  } else ME("That is not present.\n");
 return 1;
}

/* ####################	help #################### */

help(str,pl) {

  if (str=="spells" || str=="spell" ) str="guild";

  if ((str!="levels")&&(str!="knock")&&
      (str!="check")&&(spellnr(str)<0)) return 0;
  if (str!="levels") cat(helpdir+"/"+str);
  else list_levels(pl);
  return 1; 
}

/* ##########	list_levels	############# */

list_levels(pl)
{
    if(pl->query_legend_level())
        return GM->list_legend_levels(gd,TP->query_gender());
    return GM->list_levels(gd,TP->query_gender());
}

/* ########### 	query party member 	########### */

query_party_member(str,pl) {
object ob,p;
int i;

  if((!str) || (!(p=present("party",TP)))) return 0;

  ob=all_inventory(p->query_party());
  for(i=0;i<sizeof(ob);i++) {
    if(ob[i]->query_player()==str) return 1;
  }

  return 0;
}

/* ##########	call the spell   ########### */

do_spell(arg,pl,v) {
  if(!v) v=query_verb(); 
  if(v=="guild") return 0;
  call_other(dir+"/spells/"+v,"set_robe",previous_object());
  return(call_other(dir+"/spells/"+v,"doit",arg,pl));
}

/* ###### get some info about the spell ####### */

spell_info(x,y) { return spells[x][y]; }

/* ###### whats our chamber ? ####### */

query_chamber() { return chamber; }

query_max_stats() { return max_stats; }

query_guild_nr() { return gd; }

query_spells() {
  string sp;
  int i;
 
  sp=allocate(0);
  for(i=0;i<sizeof(spells);i++) sp+=({ spells[i][1] });
  return sp;
}

query_id() { return GM->query_id(gd); }

query_attack_spell() { return spells[spellnr(query_verb())][0]; }

/* Lets try some general skills here */
/* first for 'lore' */
do_lore(arg) {
    if(!arg) {
        write("Identify what?\n");
        return 1;
    }
    write("------------------\n");
    return this_player()->look("at "+arg);
}

dump() {
    int i;
    if(!this_player()->query_immortal()) return;
    printf("%|15s%|5s%|5s\n","Spellname","Level","SP");
    for (i=0;i<sizeof(spells);i++)
        printf("%-15s%|5 d%|5 d%10s\n",spells[i][1],spells[i][3],spells[i][2],
                                     (spells[i][0]?"timed":"not timed"));
    return 1;
}

report_xp(name, xp)
{
   xp_list[name]=xp;
}

dump_xp()
{
   return xp_list;
}
