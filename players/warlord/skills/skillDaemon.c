#include <skills.h>

init_skills(string sRace) {
  mapping skills;
  if(!skills) skills = ([]);
  if(!sRace) {
// Example skill set 
   skills["skillname"] = ([ "level": 0, "points": 0, "max": 100]);
  }
  else {
    //  init_skills(0);
    switch(sRace) {
       case "human":
        skills["skillname"]=([ "level":1, "points":0, "max":100]);
       break;  
    }
    return skills;
  }
}

int trainingFormulaRace(string sRace, int iLevel, string sSkill) {
  int iNum;
    if(sRace == "human") {
    switch(sSkill) {
    case "skillname":    
	iNum = FORM1; break;
  }
  return num;
}

int trainingFormulaGuild(string sRace, string *sGuild, int iLevel, string
sSkill) {

  int iTmp,num = 0;

  if(sizeof(sGuild))
    for(iTmp = 0;iTmp<sizeof(sGuild);iTmp++) {
        switch(sGuild[iTmp]) {
        case "mage":
        case "barbarian":
        case "monk":
        case "druid":
        case "ninja":
        case "jedi":
        case "bard":
        case "fighter":
        case "thief":
          num +=
(int)find_object_or_load(""+GUILDDIR+sGuild[i]+"")->getSkillCost(sSkill,iLevel);
          break;
        }
    }

  if(num) num /= sizeof(sGuild);

  if(!sizeof(sGuild) || sGuild == ({"adventurer"}))
    num = FORM5*2000;

  return to_int((num * GUILDFRACT) +(trainingFormulaRace(sRace,iLevel,sSkill) *RACE_FRACT));

}

