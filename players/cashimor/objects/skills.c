/* SKILLS.C - Programmed by Maarten Hofman */
/* 290994: Made a start with programming it */
/* 300994: Added additional skills */
/* 051094: Prepared file for uploading */
/* 131094: Added additional skills */
/* 141094: Added additional skills */

#include "/players/cashimor/include/skills.h"

string skills;

inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    long_desc="This is the skill room. I hope you like it.\n";
    short_desc="Skill room";
    set_light(1);
    smell="The typical smell of Cashimor at work...";
    skills=({
             ({"agriculture",         SS_INT,SS_WIS,0 , SS_NO_GUILD,SS_NO_CLASS}),
             ({"ancient history",     SS_INT,SS_WIS,-5, SS_NO_GUILD,SS_PRIEST}),
             ({"animal handling",     SS_WIS,SS_STR,-5, SS_NO_GUILD,SS_NO_CLASS}),
             ({"animal lore",         SS_INT,SS_WIS,0,  SS_NO_GUILD,SS_WARRIOR}),
             ({"animal training",     SS_WIS,SS_CON,0,  SS_NO_GUILD,SS_NO_CLASS}),
             ({"appraising",          SS_INT,SS_WIS,0,  SS_NO_GUILD,SS_ROGUE}),
             ({"armourer",            SS_INT,SS_STR,-15,SS_NO_GUILD,SS_WARRIOR}),
             ({"artistic ability",    SS_WIS,SS_DEX,0,  SS_NO_GUILD,SS_NO_CLASS}),
             ({"astrology",           SS_INT,SS_WIS,-5, SS_NO_GUILD,SS_WIZARD}),
             ({"blacksmithing",       SS_STR,SS_CON,0,  SS_NO_GUILD,SS_NO_CLASS}),
             ({"blind-fighting",      SS_INT,SS_WIS,0,  SS_NO_GUILD,SS_WARRIOR}),
             ({"bowyer/fletcher",     SS_DEX,SS_INT,-5, SS_NO_GUILD,SS_WARRIOR}),
             ({"brewing",             SS_INT,SS_WIS,0,  SS_NO_GUILD,SS_NO_CLASS}),
             ({"carpentry",           SS_STR,SS_CON,0,  SS_NO_GUILD,SS_NO_CLASS}),
             ({"charioteering",       SS_DEX,SS_STR,10, SS_NO_GUILD,SS_WARRIOR}),
             ({"cobbling",            SS_DEX,SS_WIS,0,  SS_NO_GUILD,SS_NO_CLASS}),
             ({"cooking",             SS_INT,SS_DEX,0,  SS_NO_GUILD,SS_NO_CLASS}),
             ({"musical instrument",  SS_DEX,SS_CHR,-5, SS_NO_GUILD,SS_ROGUE}),
             ({"bend bars lift gates",SS_STR,SS_STR,0,  SS_NO_GUILD,SS_WARRIOR}),
             ({"dancing",             SS_DEX,SS_CHR,0,  SS_NO_GUILD,SS_NO_CLASS}),
             ({"direction sense",     SS_WIS,SS_INT,5,  SS_NO_GUILD,SS_NO_CLASS}),
             ({"etiquette",           SS_CHR,SS_WIS,0,  SS_NO_GUILD,SS_NO_CLASS}),
             ({"fire-building",       SS_WIS,SS_DEX,-5, SS_NO_GUILD,SS_NO_CLASS}),
             ({"fishing",             SS_WIS,SS_CON,-5, SS_NO_GUILD,SS_NO_CLASS}),
             ({"heraldry",            SS_INT,SS_WIS,0,  SS_NO_GUILD,SS_NO_CLASS}),
             ({"languages, modern",   SS_INT,SS_WIS,0,  SS_NO_GUILD,SS_NO_CLASS}),
             ({"leatherworking",      SS_INT,SS_DEX,0,  SS_NO_GUILD,SS_NO_CLASS}),
             ({"mining",              SS_WIS,SS_STR,-20,SS_NO_GUILD,SS_NO_CLASS}),
             ({"pottery",             SS_DEX,SS_WIS,-10,SS_NO_GUILD,SS_NO_CLASS}),
             ({"riding, airborne",    SS_WIS,SS_DEX,-15,SS_NO_GUILD,SS_NO_CLASS}),
             ({"riding, land-based",  SS_WIS,SS_DEX,15, SS_NO_GUILD,SS_NO_CLASS}),
             ({"rope use",            SS_DEX,SS_STR,0,  SS_NO_GUILD,SS_NO_CLASS}),
             ({"seamanship",          SS_DEX,SS_STR,5,  SS_NO_GUILD,SS_NO_CLASS}),
             ({"seamstress/tailor",   SS_DEX,SS_WIS,-5, SS_NO_GUILD,SS_NO_CLASS}),
             ({"singing",             SS_CHR,SS_CON,0,  SS_NO_GUILD,SS_NO_CLASS}),
             ({"stonemasonry",        SS_STR,SS_CON,-10,SS_NO_GUILD,SS_NO_CLASS}),
             ({"swimming",            SS_STR,SS_CON,0,  SS_NO_GUILD,SS_NO_CLASS}),
             ({"weather sense",       SS_WIS,SS_INT,-5, SS_NO_GUILD,SS_NO_CLASS}),
             ({"weaving",             SS_INT,SS_DEX,-5, SS_NO_GUILD,SS_NO_CLASS}),
             ({"engineering",         SS_INT,SS_STR,-25,SS_NO_GUILD,SS_PRIEST}),
             ({"healing",             SS_WIS,SS_INT,-15,SS_NO_GUILD,SS_PRIEST}),
             ({"herbalism",           SS_INT,SS_WIS,-20,SS_NO_GUILD,SS_WIZARD}),
             ({"languages, ancient",  SS_INT,SS_WIS,0,  SS_NO_GUILD,SS_PRIEST}),
             ({"local history",       SS_CHR,SS_WIS,0,  SS_NO_GUILD,SS_PRIEST}),
             ({"navigation",          SS_INT,SS_WIS,-10,SS_NO_GUILD,SS_PRIEST}),
             ({"reading/writing",     SS_INT,SS_DEX,5,  SS_NO_GUILD,SS_WIZARD}),
             ({"religion",            SS_WIS,SS_CHR,0,  SS_NO_GUILD,SS_PRIEST}),
             ({"spellcraft",          SS_INT,SS_WIS,-10,SS_NO_GUILD,SS_WIZARD}),
             ({"disguise",            SS_CHR,SS_INT,-5, SS_NO_GUILD,SS_ROGUE}),
             ({"forgery",             SS_DEX,SS_INT,-5, SS_NO_GUILD,SS_ROGUE}),
             ({"gaming",              SS_CHR,SS_CON,0,  SS_NO_GUILD,SS_WARRIOR}),
             ({"gem cutting",         SS_DEX,SS_INT,-20,SS_NO_GUILD,SS_ROGUE}),
             ({"juggling",            SS_DEX,SS_CON,-5, SS_NO_GUILD,SS_ROGUE}),
             ({"jumping",             SS_STR,SS_INT,0,  SS_NO_GUILD,SS_ROGUE}),
             ({"reading lips",        SS_INT,SS_WIS,-15,SS_NO_GUILD,SS_ROGUE}),
             ({"set snares",          SS_DEX,SS_WIS,-5, SS_NO_GUILD,SS_WARRIOR}),
             ({"tightrope walking",   SS_DEX,SS_WIS,0,  SS_NO_GUILD,SS_ROGUE}),
             ({"tumbling",            SS_DEX,SS_CON,0,  SS_NO_GUILD,SS_ROGUE}),
             ({"ventriloquism",       SS_INT,SS_CHR,-10,SS_NO_GUILD,SS_ROGUE}),
             ({"endurance",           SS_CON,SS_STR,-5, SS_NO_GUILD,SS_WARRIOR}),
             ({"hunting",             SS_WIS,SS_CON,-5, SS_NO_GUILD,SS_WARRIOR}),
             ({"mountaineering",      SS_STR,SS_CON,0,  SS_NO_GUILD,SS_WARRIOR}),
             ({"running",             SS_CON,SS_DEX,-30,SS_NO_GUILD,SS_WARRIOR}),
             ({"survival",            SS_INT,SS_CON,-5, SS_NO_GUILD,SS_WARRIOR}),
             ({"tracking",            SS_WIS,SS_CON,0,  SS_NO_GUILD,SS_WARRIOR}),
             ({"weaponsmithing",      SS_INT,SS_STR,-15,SS_NO_GUILD,SS_WARRIOR}),
             ({"open doors",          SS_STR,SS_STR,0,  SS_NO_GUILD,SS_WARRIOR}),
             ({"system shock",        SS_CON,SS_CON,0,  SS_NO_GUILD,SS_WARRIOR}),
             ({"poison save",         SS_CON,SS_CON,0,  SS_NO_GUILD,SS_WARRIOR}),
             ({"hide in shadows",     SS_CHR,SS_DEX,-5, SS_THIEF,SS_WARRIOR}),
             ({"move silently",       SS_DEX,SS_CHR,-5, SS_THIEF,SS_WARRIOR}),
             ({"pick pockets",        SS_DEX,SS_CHR,-5, SS_BARD,SS_ROGUE}),
             ({"open locks",          SS_DEX,SS_WIS,-10,SS_THIEF,SS_ROGUE}),
             ({"find/remove traps",   SS_DEX,SS_WIS,-10,SS_THIEF,SS_ROGUE}),
             ({"detect noise",        SS_WIS,SS_INT,-5, SS_BARD,SS_ROGUE}),
             ({"climb walls",         SS_DEX,SS_STR,-5, SS_BARD,SS_ROGUE})
           });
  }
}

/* USERDOC:
open_ended_die
Format: i=open_ended_die()
See also: check_skill.

This function returns a value between -infinite and +infinite, with the
biggest chance of the value falling between 5 and 96. This is a 
simulated die-roll sequence of the Rolemaster system, for those 
that  are familiar with it, but with one or two derivations.
It's used by the check_skill() function.
*/
open_ended_die() {
int value;

  value=random(100);
  if(!value) value=100;
  if(value>95) value+=open_ended_die();
  if(value<6) value-=open_ended_die();
  return(value);
}

/* USERDOC:
check_skill
Format: i1=check_skill(o,i2,i3)
Example: if(check_skill(this_player(),SS_PLAY_INSTRUMENT,0)>SS_NEAR_SUCCESS) {
See also: open_ended_die, #players/cashimor/include/skills.h.

This function checks whether the player <o> succeeds in applying skill <i2>
with the penalty <i3>. The returned value can be SS_BLUNDER,
SS_ABSOLUTE_FAILURE, SS_FAILURE,SS_PARTIAL_SUCCESS,SS_NEAR_SUCCESS,
SS_SUCCESS,SS_ABSOLUTE_SUCCESS. These are ordered, and stand in the file 
/players/cashimor/include/skills.h. Normally one would check on 
>SS_NEAR_SUCCESS, but the other values are there to make interesting 
distinctions in the result. The penalty can be anything between +30 and -70, 
or one could use the definitions: SS_ROUTINE, SS_VERY_EASY, SS_EASY, 
SS_MEDIUM, SS_RATHER_HARD, SS_HARD, SS_VERY_HARD, SS_SHEER_FOLLY, SS_ABSURD. 
A list of skills is present in /players/cashimor/include/skills.h, these 
should be referred to using the #define, and not the number, because the 
number might ultimately change (if two skills are joined together in one, for
example). A small guild-dependent bonus is implemented, but learning skills 
isn't as yet.
*/
check_skill(who,which,difficulty) {
int value;

  value=10+difficulty+who->query_stats(skills[which][SS_1_STAT])*2;
  value+=skills[which][SS_MOD]+who->query_stats(skills[which][SS_2_STAT]);
  value+=open_ended_die();
  if(skills[which][SS_GUILD]==who->query_guild()) value+=10;
  if(value<-40) return(SS_BLUNDER);
  if(value<25) return(SS_ABSOLUTE_FAILURE);
  if(value<75) return(SS_FAILURE);
  if(value<90) return(SS_PARTIAL_SUCCESS);
  if(value<110) return(SS_NEAR_SUCCESS);
  if(value<175) return(SS_SUCCESS);
  return(SS_ABSOLUTE_SUCCESS);
}
