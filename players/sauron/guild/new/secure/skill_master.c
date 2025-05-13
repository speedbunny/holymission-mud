//----------------------------------------------------------------------------
// Title:						Author:
//	Monk's guild skill master.				Sauron.
//
// File:						Started:
//	/players/sauron/guild/secure/skill_master.c		220696.
//
// Purpose:
//
// History of revisions/fixes:
//
// 220696: Sauron: Started programming.
// 240696: Sauron: Added race boni for skill rolls.
//
//----------------------------------------------------------------------------

#ifndef __GUILD_SKILL_MASTER_C__

#define __GUILD_SKILL_MASTER_C__

// Preprocessor directives:

#include "/players/sauron/guild/include/include.h"


// Skill definitions.

#define BURPING		0
#define FARTING		1


// Guild skill information:
// <def> : ({ <name>,<type>,<subtype>,<boni>,<learn>,<raise> })
// eg A_SKILL:({"skill",SKILL,PHYSICAL,B_STR,7,75})
// eg A_TALENT:({"talent",TALENT,MENTAL,B_NON,5,45})

#define GUILD_SKILLS ([ \
                      BURPING:({"burping",SKILL,1,B_NON,5,60}), \
                      FARTING:({"farting",TALENT,0,B_NON,7,80}), \
                    ])


// Guild command information:
// <name> : ({ <skill>,<specialisation>,<type>,<time>,<level>,
//             <cost>,<learn>,<raise> })
// eg "hit":({A_SKILL,MONK,AGGR_CMD,1,L_PR,10,7,75})
// eg "locate":({A_TALENT,DRUID,PEACE_CMD,2,L_PL,50,5,45})

#define GUILD_CMDS ([ \
                    "burp":({ \
                      BURPING,GENERAL,PEACE_CMD,0,L_PR,0,1,1 \
                    }), \
                    "fart":({ \
                      FARTING,GENERAL,NON_AGGR_CMD,1,L_LDR,0,1,1 \
                    }), \
                  ])


// <race> : ({ <boni> })
// NB. The order of the boni should correspond to the subtype defs in
// skill_defs.h

#define RACE_BONI ([ \
                     "human":({0,0,0,0,0,0,0,0,0,0}), \
                     "elf":({0,0,0,0,0,0,0,0,0,0}), \
                     "half-elf":({0,0,0,0,0,0,0,0,0,0}), \
                     "hobbit":({0,0,0,0,0,0,0,0,0,0}), \
                     "gnome":({0,0,0,0,0,0,0,0,0,0}), \
                     "dwarf":({0,0,0,0,0,0,0,0,0,0}), \
                  ])

// End preprocessor directives.


// Prototypes:

private void init_guild_skills();
varargs mixed assoc_guild_skill(mixed skill,object ob);
varargs mixed assoc_guild_cmd(mixed arg,object ob);
mixed assoc_stat(mixed stat);
int query_av_stat(object ob,int stat);
mixed query_skill_info(int skill,int i);
mixed query_cmd_info(int skill,int i);
int query_cmd_cost(string cmd,object ob);
int improve_skill(object ob,int skill);
int learn_skill(object ob,int skill);
int simple_roll();
int stress_roll(int rec);
int skill_filter(mixed arg);
int skill_roll(object who,string cmd,int roll,int difficulty);
int no_clean_up();
void reset(int arg);

// End prototypes.


// Global variables:

// Static variables.
static string *skill_strs,*cmd_strs;
static int MAX_SKILL,MAX_CMD;
static mapping all_guild_skills,all_guild_cmds;

// End global variables.


/* USERDOC:
init_guild_skills
Format: init_guild_skills()

Initialises and checks skill mappings.
*/

private void init_guild_skills() {
  int i;

  if(!all_guild_skills) {
    all_guild_skills=GUILD_SKILLS;
    MAX_SKILL=m_sizeof(all_guild_skills);
    skill_strs=allocate(MAX_SKILL);
    for(i=0;i<MAX_SKILL;i++)
      skill_strs[i]=all_guild_skills[i][0];
  }

  if(!all_guild_cmds) {
    all_guild_cmds=GUILD_CMDS;
    MAX_CMD=m_sizeof(all_guild_cmds);
    cmd_strs=m_indices(all_guild_cmds);
  }
}

mapping query_skillmap() {
  return all_guild_skills;
}

mapping query_cmdmap() {
  return all_guild_cmds;
}

/* USERDOC:
assoc_guild_skill
Format: m=assoc_guild_skill(m,o)

Passing a string skillname to the function will return an int 
associated with that skill (as defined in skill.h). If you 
pass it an int (0 or higher) it will return you a string that 
is associated with that skill (as defined in skill.h) - the 
idea is so that we can pass it a number and it gives us in 
return, a nice looking skill string. If it doesnt find the entry 
that you pass it, it will return -1.

If you pass -1 to the function, it will return an array 
(string) of all skills in which the living 'o' has learnt. If 
you pass -2 to the function it will return an array (string) of 
all skills.

The function is varargs, so you dont have to pass it a reference 
to a living object 'o' unless you are passing the -1 value to 
return skilled skills for that living. In other cases leave out 
the who argument.
*/

varargs mixed assoc_guild_skill(mixed skill,object ob) {
  string *ret;
  int i,*tmp;

  if(intp(skill)) {
    switch(skill) {
      case -2:
        return skill_strs;
        break;
      case -1:
        tmp=(int *)ob->query_guild_skill(-1);
        ret=({});
        for(i=0;i<sizeof(tmp);i++)
          ret+=({skill_strs[tmp[i]]});
        return ret;
        break;
      default:
        if(skill>=0 && skill<MAX_SKILL)
          return skill_strs[skill];
        else
          return -1;
        break;
    }
  }
  else if(stringp(skill))
    return member_array(skill,skill_strs);
  else
    return -1;
}

/* USERDOC:
assoc_guild_cmd
Format: m=assoc_guild_cmd(i,o)

This function is the analogue of assoc_guild_skill(), but the 
only possible arguments are -1 and -2. Individual commands 
and their associated data are referenced via the use of 
query_verb().

If you pass -1 to the function, it will return an array (string) 
of all skill commands available to 'o'. If you pass -2, it will 
return an array of all skill commands.
*/

varargs mixed assoc_guild_cmd(mixed arg,object ob) {
  string *ret,cmd;
  int j;

  if(intp(arg)) {
    switch(arg) {
      case -2:
        return cmd_strs;
        break;
      case -1:
        ret=({});
        for(j=0;j<MAX_CMD;j++) {
          cmd=cmd_strs[j];
          if(query_guild_level(ob)>=all_guild_cmds[cmd][CMD_LEVEL])
            ret+=({cmd});
        }
        return ret;
        break;
      default:
        if(arg>=0 && arg<MAX_CMD)
          return cmd_strs[arg];
        else
          return -1;
        break;
    }
  }
  else if(stringp(arg))
    return member_array(arg,cmd_strs);
  else
    return -1;
}

/* USERDOC:
assoc_stat
Format: m=assoc_stat(m)

Returns a string for each stat, or the stat number from the string.
*/

mixed assoc_stat(mixed stat) {
  if(intp(stat)) {
    if(stat==-1)
      return STATS;
    if(stat>=0 && stat<NUM_STATS)
      return STATS[stat];
    else
      return -1;
  }
  else if(stringp(stat))
    return member_array(stat,STATS);
  else
    return -1;
}

/* USERDOC:
query_av_stat
Format: i=query_av_stat(o,s)

This function returns a player's stat relative to their stat average, 
or the stat average if s is -1.
*/

int query_av_stat(object ob,int stat) {
  string race;
  int *stats;
  int all,av,lvl;

  race=RACE(ob);
  stats=allocate(6);
  stats[0]=STR(ob);
  stats[1]=DEX(ob);
  stats[2]=CON(ob);
  stats[3]=INT(ob);
  stats[4]=WIS(ob);
  stats[5]=CHR(ob);
  all=stats[0]+stats[1]+stats[2]+stats[3]+stats[4]+stats[5];

  if(stat==-2)
    return all/6;

  lvl=LEVEL(ob);
  av=lvl+2;

  if(av>MAX_STAT)
    av=MAX_STAT;

  if(member_array(race,RACES)!=-1)
    if(av>RM->query_max_stat(race,stat))
      av=(int)RM->query_max_stat(race,stat);

  if(stat==-1)
    return av;

  else if(stat>=0 && stat<6)
    return stats[stat]-av;

  else
    return 0;
}

int test(int stat) {
  return query_av_stat(this_player(),stat);
}

/* USERDOC:
query_skill_info
Format: i=query_skill_info(s,i)

This function returns information about 's' from the all_guild_skills 
mapping.
*/

mixed query_skill_info(mixed skill,int i) {
  if(assoc_guild_skill(skill)!=-1 && i>=0 && i<=SKILL_RAISE) {
    if(stringp(skill))
      skill=assoc_guild_skill(skill);
    return all_guild_skills[skill][i];
  }
}

/* USERDOC:
query_cmd_info
Format: i=query_cmd_info(s,i)

This function returns information about 's' from the all_guild_cmds 
mapping.
*/

mixed query_cmd_info(string cmd,int i) {
  if(member(all_guild_cmds,cmd) && i>=0 && i<=CMD_RAISE)
    return all_guild_cmds[cmd][i];
}

/* USERDOC:
query_cmd_cost
Format: i=query_cmd_cost(s,o)

This function returns the sp cost for command 's' for object 'o'.
*/

int query_cmd_cost(string cmd,object ob) {
  if(member(all_guild_cmds,cmd))
    return all_guild_cmds[cmd][CMD_COST];
}

/* USERDOC:
simple_roll
Format: i=simple_roll()
See also: stress_roll.

This function returns a random value between -24 and 25.
*/

int simple_roll() {
  return random(50)-24;
}

/* USERDOC:
stress_roll
Format: i=stress_roll(i)
See also: simple_roll.

This function returns a random value between -infinite and infinite. 
Usually it will be between -25 and 24, but the sky is the limit. If given 
with argument 1, it will usually return a value between -24 and 25. 
This optional argument is usually not used.
*/

int stress_roll(int rec) {
  int roll;

  roll=random(50)-25;
  if(roll==1)
    return 2*stress_roll(1);
  if(roll==-25 && rec)
    roll+=50;
  return roll;
}

/* USERDOC:
improve_skill
Format: i=improve_skill(o,s)

This function determines whether 'o' was successful in improving 's'.
Use only when trying to raise a skill by use.
*/

int improve_skill(object ob,int skill) {
/*
  int i2,i3,i4,i5;

  i2=(int)ob->query_guild_skill(skill);
  i3=(i2*(100-i2))*49/2500;
  i4=simple_roll();
  i5=all_guild_skills[skill][SKILL_RAISE];
  TELLO(ob,sprintf("skill = %d, mod_skill = %d, roll = %d, diff = %d\n",
                   i2,i3,i4,i5));

  return (i3+i4)>i5;
*/
  int sk_lvl,rnd,ease;

  sk_lvl=(int)ob->query_guild_skill(skill);
  rnd=gausian(1,(sk_lvl*(100-sk_lvl)),1,7);
  rnd=(100*rnd)/2500;
  ease=90+(all_guild_skills[skill][SKILL_RAISE]/10);

  TELLO(ob,sprintf("skill = %d, mod_skill = %d, diff = %d\n",
                   sk_lvl,rnd,ease));

  return rnd>ease;
}

/* USERDOC:
learn_skill
Format: i=learn_skill(o,s)

This function determines whether '0' was successful in learning 's'.
Use only when trying to learn a skill by use.
*/

int learn_skill(object ob,int skill) {
  int i1,i2;

  i1=random(100);
  i2=10*all_guild_skills[skill][SKILL_LEARN];
  TELLO(ob,sprintf("random() = %d, '10*skill' = %d\n",i1,i2));

  return i1>=i2;
}

int skill_filter(mixed arg) {
  return intp(arg);
}

/* USERDOC:
skill_roll
Format: i1=skill_roll(o,i2,s,i3)
Example: if(G_SM->skill_roll(this_player(),ALERTNESS,SIMPLE,1)==SUCCESFUL)
See also: /include/skill.h.

This function performs a skill roll. A skill roll is to test the character 
if he/she succeeds in an action that he/she wants to undertake. 'o' is the 
character that wants to undertake the action. 'i2' is the skill that is used, 
you can use one of the defines from (skill.h). You can also pass an array of 
such definitions, in which case, the modification to the skill roll is an 
average of the modifications from the skills passed. If the player does not 
know any of the skills, the stat/race boni are not applied. 's' indicates 
if the roll is to be made in a stressful situation or not. If it is (eg 
combat), use STRESS, if it's not, use SIMPLE here. The last parameter 'i3' 
indicates the difficulty, ranging from 1 (the easiest) to 100 (the hardest). 
The result of this function is SUCCESFUL in case the skill roll is succesful. 
It's FAILURE in case of a failure, and if it was a STRESS roll, -1 can be 
returned. In this case , 'o' 'botched', and something terrible is about 
to happen.

The skill roll is weighted so that if the player's modification (skill + 
any stat boni + any race boni) equals the difficulty, they will succeed 
50% of the time. If their mod is 25 or more higher than the diff, they will 
always succeed, and if it is 25 or more lower, they will always fail.
*/

int skill_roll(object ob,string cmd,int roll,int difficulty) {
  string race;
  int res,i,j,mod,count,sb,sk;
  mixed skill;

  mod=0;
  race=(string)ob->query_race();
  skill=all_guild_cmds[cmd][CMD_SKILL];

  if(intp(skill)) {
    count=0;
    if((sk=(int)ob->query_guild_skill(skill))>=0) {
      mod+=sk;
      for(j=1;j<256;j*=2) {
        if(all_guild_skills[skill][SKILL_BONI]&j) {
          mod+=query_av_stat(ob,count);
        }
        count++;
      }
      sb=all_guild_skills[skill][SKILL_SUBTYPE];
      if(member_array(race,m_indices(RACE_BONI))!=-1) {
        mod+=RACE_BONI[race][sb];
      }
    }
  }
  else if(pointerp(skill)) {
    for(i=0;i<sizeof(skill);i++) {
      count=0;
      if((sk=(int)ob->query_guild_skill(skill[i]))>=0) {
        mod+=sk;
        for(j=1;j<256;j*=2) {
          if(all_guild_skills[skill[i]][SKILL_BONI]&j)
            mod+=query_av_stat(ob,count);
          count++;
        }
        sb=all_guild_skills[skill[i]][SKILL_SUBTYPE];
        if(member_array(race,m_indices(RACE_BONI))!=-1)
          mod+=RACE_BONI[race][sb];
      }
    }
    mod/=sizeof(skill);
  }

  res=(roll==STRESS)?stress_roll(0):simple_roll();

  TELLO(ob,sprintf("mod = %d, res = %d, difficulty = %d\n",
                   mod,res,difficulty));

  if(res==-25)
    return BOTCH;
  else if(res+mod>difficulty)
    return SUCCESS;
  else
    return FAILURE;
}

int no_clean_up() {
  return 1;
}

void reset(int arg) {
  if(!arg) {
    init_guild_skills();
  }
}

#endif // __GUILD_SKILL_MASTER_C__
