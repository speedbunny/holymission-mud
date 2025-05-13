//----------------------------------------------------------------------------
// Title:						Author:
//	Monk's guild skill handling file.			Sauron.
//
// File:						Started:
//	/players/sauron/guild/include/cmd_functions.c		230696.
//
// Purpose:
//	This skill file contains set_guild_skill(), improve_guild_skill() 
//	learn_guild_skill() and query_guild_skill() (called in the soul via 
//	the guild shadow), and some defs needed for the skill_master 
//	(guild/secure/skill_master.c). Also inherited by the bin modules.
//
// History of revisions/fixes:
//
// 230696: Sauron: Created from part of skill.h.
//
//----------------------------------------------------------------------------

#ifndef __GUILD_CMD_FUNCTIONS_C__

#define __GUILD_CMD_FUNCTIONS_C__

// Preprocessor directives:

#include "/players/sauron/guild/include/include.h"

// End preprocessor directives.


// Prototypes:

private void check_guild_skills();
int set_guild_skill(int skill,mixed val);
int improve_guild_skill(int skill);
int learn_guild_skill(int skill);
mixed query_guild_skill(int skill);
mixed query_guild_cmd_skill(string cmd);
int guild_skill_roll(object ob,mixed skill,int type,int diff);

// End prototypes.


// Global variables:

// Non-static variables - saved in/restored from the player's guild file.
mapping guild_skills;

// End global variables.


/* USERDOC:
check_guild_skills
Format: check_guild_skills()

Initialises and checks guild skill mapping.
*/

private void check_guild_skills() {
  int *key,i;

  if(!guild_skills)
    guild_skills=([]);

  key=m_indices(guild_skills);
  for(i=0;i<sizeof(key);i++) {
    if((int)G_SM->assoc_guild_skill(key[i])==-1)
      guild_skills=m_delete(guild_skills,key[i]);
    else if(guild_skills[key[i]]>MAX_SKILL_VAL)
      guild_skills[key[i]]=MAX_SKILL_VAL;
    else if(guild_skills[key[i]]<0)
      guild_skills[key[i]]=0;
  }
}

/* USERDOC:
set_guild_skill
Format: set_guild_skill(s,v)

Sets the skill s in the mapping guild_skills to v. Returns the new skill 
level for success, -2 for failure, -3 for an illegal call. 
Not normally used.
*/

int set_guild_skill(int skill,int val) {
  object soul;

  soul=query_tmp("guild_soul");
  if(!soul)
    return -2;
  else if(TO!=soul)
    return (int)soul->set_guild_skill(skill,val);

  check_guild_skills();

  if(!TP || !query_GM(TP))
    return -3;				// Security...

  if(!intp(skill) || (int)G_SM->assoc_guild_skill(skill)==-1 || !intp(val)
                  || val<0 || val>MAX_SKILL_VAL)
    return -2;				// Not a valid skill/skill value.

  guild_skills[skill]=val;
  TO->do_save();
  return val;
}

/* USERDOC:
improve_guild_skill
Format: improve_guild_skill(s)

Improves the skill s by v in the mapping guild_skills. Returns 1 if 
the skill was successfully raised, 0 if the player failed to raise 
the skill, -1 if the skill is not in guild_skills, -2 for other 
failure, -3 for an illegal call.
*/

int improve_guild_skill(int skill) {
  object soul;

  soul=query_tmp("guild_soul");
  if(!soul)
    return -2;
  else if(TO!=soul)
    return (int)soul->improve_guild_skill(skill);

  check_guild_skills();

  if(!TP || (TP!=query_tmp("owner") && !query_GM(TP) && VERB!="teach"))
    return -3;				// Security...

  if(!intp(skill) || (int)G_SM->assoc_guild_skill(skill)==-1)
    return -2;				// Not a valid skill.

  if(query_guild_skill(skill)==-1)
    return -1;				// Skill has to be learnt first.

  if((int)G_SM->improve_skill(query_tmp("owner"),skill)) {
    guild_skills[skill]=guild_skills[skill]+1;
    TELLO(query_tmp("owner"),
          sprintf("You feel that your knowledge of %s improved slightly.\n",
                  (string)G_SM->assoc_guild_skill(skill)));
    TO->do_save();
    return 1;
  }
  else
    return 0;
}

/* USERDOC:
learn_guild_skill
Format: learn_guild_skill(s)

Adds a new skill to the mapping guild_skill and sets it to 0. Returns 1 
if the skill was successfully learnt, 0 if the player failed to learnt 
the skill, -1 if the skills is already in guild_skills -2 for other 
failure, -3 for an illegal call.
*/

int learn_guild_skill(int skill) {
  object soul;

  soul=query_tmp("guild_soul");
  if(!soul)
    return -2;
  else if(TO!=soul)
    return (int)soul->learn_guild_skill(skill);

  check_guild_skills();

  if(!TP || (TP!=query_tmp("owner") && !query_GM(TP) && VERB!="teach"))
    return -3;				// Security...

  if(!intp(skill) || (int)G_SM->assoc_guild_skill(skill)==-1)
    return -2;				// Not a valid skill.

  if(query_guild_skill(skill)!=-1)
    return -1;				// Skill already learnt.

  if((int)G_SM->learn_skill(query_tmp("owner"),skill)) {
    guild_skills[skill]=0;
    TELLO(query_tmp("owner"),
          sprintf("You feel that you gained some knowledge about %s.\n",
                  (string)G_SM->assoc_guild_skill(skill)));
    TO->do_save();
    return 1;
  }
  else
    return 0;
}

/* USERDOC:
query_guild_skill
Format: m=query_guild_skill(i)

Queries a skill from the mapping guild_skills. It searches for the skill 'i'. 
If 'i' is not found -1 is returned. If 'i' is -1, the indices of the mapping 
guild_skills are returned. See also assoc_guild_skill() in the skill_master.
*/

mixed query_guild_skill(int skill) {
  object soul;

  soul=query_tmp("guild_soul");
  if(!soul)
    return -2;
  else if(TO!=soul)
    return (mixed)soul->query_guild_skill(skill);

  check_guild_skills();

  switch(skill) {
    case -1:
      return m_indices(guild_skills);
      break;
    default:
      if(member(guild_skills,skill))
        return guild_skills[skill];
      else
        return -1;
      break;
  }
}

/* USERDOC:
query_guild_cmd_skill
Format: m=query_guild_cmd_skill(s)

Returns the average level of the skills associated with command 's'. 
If s is not found -1 is returned. If s is -1, an array of available 
commands is returned.
*/

mixed query_guild_cmd_skill(string cmd) {
  int i,tmp,ret,count;
  object soul;
  mixed skills;

  soul=query_tmp("guild_soul");
  if(!soul)
    return -2;
  else if(TO!=soul)
    return (mixed)soul->query_guild_cmd_skill(cmd);

  check_guild_skills();

  switch(cmd) {
    case -1:
      return (string *)G_SM->assoc_guild_cmd(-1,query_tmp("owner"));
      break;
    default:
      skills=(mixed)G_SM->query_cmd_info(cmd,CMD_SKILL);
      if(intp(skills))
        return query_guild_skill(skills);
      else if(pointerp(skills)) {
        ret=0;
        for(i=0;i<sizeof(skills);i++) {
          if((tmp=query_guild_skill(skills[i]))!=-1) {
            ret+=tmp;
            count++;
          }
        }
        if(count) {
          ret/=count;
          return ret;
        }
        else
          return -1;
      }
      break;
  }
}

/* USERDOC:
guild_skill_roll
Format: i=guild_skill_roll(o,s,i2,i3)

This function handles the skill roll from the skill_master and tries to 
improve the player's skill if they failed (but not botched). Returns the 
result of the skill roll. Used mainly (only?) by the skill command 
modules in the skill bin (guild/bin/skill/).
*/

int guild_skill_roll(object ob,mixed skill,int type,int diff) {
  int ret,rnd_skill;
  ret=(int)G_SM->skill_roll(ob,skill,type,diff);
  if(ret==FAILURE) {
    if(pointerp(skill))
      rnd_skill=skill[random(sizeof(skill))];
    else if(intp(skill))
      rnd_skill=skill;
    if(query_guild_skill(rnd_skill)==-1)
      learn_guild_skill(rnd_skill);
    else
      improve_guild_skill(rnd_skill);
  }
  return ret;
}

#endif // __GUILD_CMD_FUNCTIONS_C__
