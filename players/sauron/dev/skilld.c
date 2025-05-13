//      /adm/daemon/skills_d.c
//      from the Nightmare mudlib
//      contains code that would be very memory wasteful if in the user object
//      created by Descartes of Borg 14 february 1993
//      added all the skills to the races so they would have all of them at
//      some sort of default - tempus
//      removed cases for classes that have their own /adm/daemon/skills file
//      -=- Klamar 960212

//      290797: Sauron: Partially rewritten and slimmed down for HM.

//#include <skills.h>

#define GM		"/guild/master"

string *skill_list;
mapping skills,race_boni_skills;

mapping init_skills(string rac) {
  string *ind;
  int i;
  mapping ret;

  if(!skills)
    skills=([]);

  for(i=0;i<sizeof(skill_list);i++)
    skills[skill_list[i]]=(["level":0,"points":0,"max":100]);

  if(rac && member(race_boni_skills,rac)!=-1) {
    ret=skills;
    ind=m_indices(race_boni_skills[rac]);
    for(i=0;i<sizeof(ind);i++)
      ret[ind[i]]["level"]=1;
    return ret;
  }
  else
    return skills;
}

int training_formula_race(string rac,int lvl,string skill) {
  int num;
  mapping map;

  map=race_boni_skills[rac];
  if(!map)
    return 0;
// Temp:
  return map[skill];

  switch(map[skill]) {
    case 1:
//      num=FORM1;
      break;
    case 2:
//      num=FORM2;
      break;
    case 3:
//      num=FORM3;
      break;
    case 4:
//      num=FORM4;
      break;
    case 5:
//      num=FORM5;
      break;
  }
  return num;
}

int training_formula_class(string rac,string *cl,int lvl,string skill) {
  int i,num;

  if(sizeof(cl)) {
    for(i=0;i<sizeof(cl);i++) {
       switch(cl[i]) {
         case "assassin":
         case "barbarian":
         case "cleric":
         case "druid":
         case "elementalist":
         case "knight":
         case "mercenary":
         case "merchant":
         case "monk":
         case "necromancer":
         case "ranger":
         case "rogue":
         case "samurai":
         case "sorcerer":
           num++;
//           num+=(int)GM->get_skill_cost(cl[i],skill,lvl);
           break;
       }
    }
  }
  if(num)
    num/=sizeof(cl);

//  if(!sizeof(cl) || cl==({"adventurer"}))
//    num=FORM5*2000;

//  return to_int((num*CLASS_FRACT)
//                +(training_formula_race(rac,lvl,skill)*RACE_FRACT));
  return num+training_formula_race(rac,lvl,skill);
}

void reset(int arg) {
  if(!arg) {
// I'll make defs for these two vars and put them in skills.h eventually.
// This is the list of skills available... just names.
    skill_list=({
      "brawl",
      "alertness",
      "perception",
      "stealth",
      "agility",
      "quickness",
      "striking-sword",
      "parry-sword",
      "strength",
    });

// This is the list of bonus skills for each race... names and formulae to use.
    race_boni_skills=([]);
    race_boni_skills["human"]=([
      "brawl":1,
    ]);
    race_boni_skills["half-elf"]=([
      "alertness":1,
    ]);
    race_boni_skills["elf"]=([
      "perception":1,
    ]);
    race_boni_skills["hobbit"]=([
      "stealth":1,
    ]);
    race_boni_skills["gnome"]=([
      "agility":1,
    ]);
    race_boni_skills["dwarf"]=([
      "quickness":1,
    ]);
    race_boni_skills["orc"]=([
      "striking-sword":1,
    ]);
    race_boni_skills["troll"]=([
      "parry-sword":1,
    ]);
    race_boni_skills["giant"]=([
      "strength":1,
    ]);
    init_skills(0);
  }
}
