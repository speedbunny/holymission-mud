//      /adm/daemon/skills_d.c
//      from the Nightmare mudlib
//      contains code that would be very memory wasteful if in the user object
//      created by Descartes of Borg 14 february 1993
//      added all the skills to the races so they would have all of them at
//      some sort of default - tempus
//	removed cases for classes that have their own /adm/daemon/skills file -=- Klamar 960212

#include <skills.h>

init_skills(string rac) {
  mapping skills;
  if(!skills) skills = ([]);
  seteuid(getuid());
  if(rac == "0") {
    // weapon skills
    skills["blunt"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["dagger"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["mech. proj."] = ([ "level": 0, "points": 0, "max": 100]);
    skills["misc"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["polearm"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["sword"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["thrown"] = ([ "level": 0, "points": 0, "max": 100]);
    // combat skills
    skills["defense"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["double wield"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["melee"] = ([ "level": 1, "points": 0, "max": 100 ]);
    // deception
    skills["locks/traps"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["murder"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["stealth"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["stealing"] = ([ "level": 0, "points": 0, "max": 100]);
    // magic
    skills["air"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["chi"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["earth"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["fire"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["healing"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["necromancy"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["sorcery"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["water"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["wrath"] = ([ "level": 0, "points": 0, "max": 100]);
    // knowledges
    skills["bargaining"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["education"] = ([ "level": 0, "points": 0, "max": 100]);
    skills["forestry"] = ([ "level": 0, "points": 0, "max": 100]);
  }
  else {
    //	 init_skills(0);
    switch(rac) {
    case "centaur":
	 skills["blunt"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["mech. proj."] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["thrown"] = ([ "level":1, "points": 0, "max": 100 ]);
	 skills["double wield"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["melee"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["forestry"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["defense"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["bargaining"] = ([ "level":1, "points":0, "max":100 ]);
	 break;
    case "drow":
	 skills["blunt"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["dagger"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["mech. proj."] = ([ "level": 1, "points": 0, "max":100 ]);
	 skills["sword"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["melee"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["necromancy"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["defense"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["bargaining"] = ([ "level":1, "points":0, "max":100 ]);
	 break;
    case "drider":
	 skills["dagger"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["mech. proj."] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["sword"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["thrown"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["melee"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["murder"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["bargaining"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["defense"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 break;
    case "human":
	 skills["blunt"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["dagger"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["polearm"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["sword"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["melee"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["education"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["defense"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["bargaining"] = ([ "level":1, "points":0, "max":100 ]);
	 break;
    case "giant":
	 skills["blunt"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["melee"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["defense"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["bargaining"] = ([ "level":1, "points":0, "max":100 ]);
	 skills["thrown"] = ([ "level":1, "points":0, "max":100 ]);
	 skills["polearm"] = ([ "level":1, "points":0, "max":100 ]);
	 skills["sword"] = ([ "level":1, "points":0, "max":100 ]);
	 break;
    case "elf":
	 skills["mech. proj."] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["melee"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["healing"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["forestry"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["defense"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["bargaining"] = ([ "level":1, "points":0, "max":100 ]);
	 skills["sorcery"] = ([ "level":1, "points":0, "max":100 ]);
	 break;
    case "halfling":
	 skills["dagger"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["thrown"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["defense"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["melee"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["stealth"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["stealing"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["bargaining"] = ([ "level":1, "points":0, "max":100 ]);
	 break;
    case "gnome":
	 skills["blunt"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["melee"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["earth"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["defense"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["bargaining"] = ([ "level":1, "points":0, "max":100 ]);
	 skills["education"] = ([ "level":1, "points":0, "max":100 ]);
	 skills["dagger"] = ([ "level":1, "points":0, "max":100 ]);
	 break;
    case "dwarf":
	 skills["blunt"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["sword"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["melee"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["defense"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["bargaining"] = ([ "level":1, "points":0, "max":100 ]);
	 skills["polearm"] = ([ "level":1, "points":0, "max":100 ]);
	 skills["thrown"] = ([ "level":1, "points":0, "max":100 ]);
	 break;
    case "sidhe":
	 skills["defense"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["melee"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["stealth"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["air"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["forestry"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["bargaining"] = ([ "level":1, "points":0, "max":100 ]);
	 skills["dagger"] = ([ "level":1, "points":0, "max":100 ]);
	 break;
    case "doppleganger":
	 skills["dagger"] = ([ "level": 1, "points": 0, "max": 100]);
	 skills["defense"] = ([ "level": 1, "points": 0, "max": 100]);
	 skills["melee"] = ([ "level": 1, "points": 0, "max": 100]);
	 skills["bargaining"] = ([ "level": 1, "points": 0, "max": 100]);
	 skills["murder"] = ([ "level": 1, "points": 0, "max": 100]);
	 skills["stealth"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 skills["stealing"] = ([ "level": 1, "points": 0, "max": 100 ]);
	 break;
    case "ogre":
	 skills["bargaining"] = ([ "level":1, "points":0, "max":100 ]);
	 skills["blunt"] = ([ "level":1, "points":0, "max":100 ]);
	 skills["polearm"] = ([ "level":1, "points":0, "max":100 ]);
	 skills["defense"] = ([ "level":1, "points":0, "max":100 ]);
	 skills["melee"] = ([ "level":1, "points":0, "max":100 ]);
	 skills["misc"] = ([ "level":1, "points":0, "max":100 ]);
	 skills["fire"] = (["level":1, "points":0, "max":100 ]);
    }
    return skills;
  }
}

int training_formula_race(string rac, int lvl, string skill) {
  int num;
  if(rac == "centaur") {
    switch(skill) {
    case "blunt":
    case "mech. proj.":
    case "sword":
    case "melee":
    case "forestry":
	 num = FORM1; break;
    case "polearm":
    case "misc":
    case "defense":
    case "education":
    case "thrown":
    case "double wield":
	 num = FORM2; break;
    case "locks/traps":
    case "dagger":
    case "healing":
    case "stealth":
    case "earth":
    case "water":
	 num = FORM3; break;
    case "chi":
    case "bargaining":
    case "air":
    case "fire":
    case "stealing":
    case "murder":
	 num = FORM4; break;
    case "necromancy":
    case "sorcery":
    case "wrath":
	 num = FORM5; break;
    }
  }
  else if(rac == "doppleganger") {
    switch(skill) {
    case "murder":
    case "stealth":
    case "defense":
    case "stealing":
    case "dagger":
	 num = FORM1; break;
    case "thrown":
    case "locks/traps":
    case "bargaining":
    case "blunt":
    case "misc":
	 num = FORM2; break;
    case "melee":
    case "double wield":
    case "education":
    case "sorcery":
    case "sword":
	 num = FORM3; break;
    case "air":
    case "earth":
    case "fire":
    case "healing":
    case "water":
    case "mech. proj.":
	 num = FORM4; break;
    case "chi":
    case "polearm":
    case "necromancy":
    case "wrath":
    case "forestry":
	 num = FORM5;
    }
  }
  else if(rac == "drider") {
    switch(skill) {
    case "sword":
    case "mech. proj.":
    case "melee":
    case "dagger":
    case "thrown":
    case "murder":
	 num = FORM1; break;
    case "blunt":
    case "necromancy":
    case "defense":
    case "stealth":
    case "double wield":
	 num = FORM2; break;
    case "sorcery":
    case "locks/traps":
    case "stealing":
    case "misc":
	 num = FORM3; break;
    case "wrath":
    case "polearm":
    case "bargaining":
    case "education":
    case "earth":
	 num = FORM4; break;
    case "air":
    case "chi":
    case "fire":
    case "healing":
    case "water":
    case ":forestry":
	 num = FORM5; break;
    }
  }
  else if(rac == "drow") {
    switch(skill) {
    case "sword":
    case "mech. proj.":
    case "dagger":
    case "necromancy":
    case "murder":
	 num = FORM1; break;
    case "locks/traps":
    case "melee":
    case "stealth":
    case "defense":
    case "double wield":
	 num = FORM2; break;
    case "blunt":
    case "misc":
    case "thrown":
    case "sorcery":
    case "education":
    case "wrath":
    case "stealing":
	 num = FORM3; break;
    case "bargaining":
    case "earth":
    case "air":
    case "polearm":
	 num = FORM4; break;
    case "chi":
    case "fire":
    case "water":
    case "healing":
    case "forestry":
	 num = FORM5; break;
    }
  }
  else if(rac == "dwarf") {
    switch(skill) {
    case "blunt":
    case "melee":
    case "sword":
    case "locks/traps":
    case "defense":
    case "misc":
	 num = FORM1; break;
    case "education":
    case "thrown":
    case "mech. proj.":
	 num = FORM2; break;
    case "double wield":
    case "polearm":
    case "stealth":
    case "bargaining":
    case "dagger":
    case "earth":
	 num = FORM3; break;
    case "chi":
    case "forestry":
    case "murder":
    case "stealing":
    case "healing":
	 num = FORM4; break;
    case "air":
    case "fire":
    case "necromancy":
    case "sorcery":
    case "water":
    case "wrath":
	 num = FORM5; break;
    }
  }  	
  else if(rac == "elf") {
    switch(skill) {
    case "mech. proj.":
    case "sword":
    case "forestry":
    case "thrown":
    case "dagger":
	 num = FORM1; break;
    case "defense":
    case "healing":
    case "stealth":
    case "melee":
    case "wrath":
	 num = FORM2; break;
    case "education":
    case "stealing":
    case "misc":
    case "double wield":
    case "sorcery":
	 num = FORM3; break;
    case "locks/traps":
    case "blunt":
    case "bargaining":
    case "polearm":
    case "water":
	 num = FORM4; break;
    case "murder":
    case "air":
    case "earth":
    case "fire":
    case "necromancy":
	 num = FORM5; break;
       }
  }
  else if(rac == "giant") {
    switch(skill) {
    case "blunt":
    case ":melee":
    case "thrown":
    case "polearm":
    case "misc":
	 num = FORM1; break;
    case "defense":
    case "earth":
    case "fire":
    case "sword":
	 num = FORM2; break;
    case "murder":
    case "double wield":
    case "bargaining":
    case "forestry":
	 num = FORM3; break;
    case "chi":
    case "dagger":
    case "mech. proj.":
    case "stealth":
    case "healing":
    case "wrath":
	 num = FORM4; break;
    case "locks/traps":
    case "stealing":
    case "air":
    case "necromancy":
    case "sorcery":
    case "water":
    case "education":
	 num = FORM5; break;
    }
  }
  else if(rac == "gnome") {
    switch(skill) {
    case "blunt":
    case "melee":
    case "earth":
    case "dagger":
    case "water":
	 num = FORM1; break;
    case "mech. proj.":
    case "air":
    case "fire":
    case "stealing":
    case "locks/traps": 
	 num = FORM2; break;
    case "sword":
    case "thrown":
    case "defense":
    case "stealth":
    case "wrath":
    case "bargaining":
	 num = FORM3; break;
    case "misc":
    case "sorcery":
    case "healing":
    case "education":
    case "double wield":
    case "forestry": 
	 num = FORM4; break;
    case "chi":
    case "polearm":
    case "murder":
    case "necromancy":
	 num = FORM5; break;
    }
  }
  else if(rac == "halfling") {
    switch(skill) {
    case "dagger":
    case "thrown":
    case "defense":
    case "stealth":
    case "stealing":
    case "bargaining":
	 num = FORM1; break;
    case "double wield":
    case "locks/traps":
    case "blunt":
	 num = FORM2; break;
    case "forestry":
    case "education":
    case "misc":
    case "healing":
    case "sorcery":
	 num = FORM3; break;
    case "chi":
    case "mech. proj.":
    case "sword":
    case "murder":
    case "air":
    case "water":
	 num = FORM4; break;
    case "polearm":
    case "earth":
    case "fire":
    case "necromancy":
    case "wrath":
	 num = FORM5; break;
    }
  }
  else if(rac == "human") {
    switch(skill) {
    case "melee":
    case "murder":
    case "sorcery":
    case "necromancy":
    case "wrath":
    case "sword": 
	 num = FORM1; break;
    case "air":
    case "earth":
    case "fire":
    case "healing":
    case "water":
    case "polearm":
    case "dagger":
  case "wrath":
	 num = FORM2; break;
    case "blunt":
    case "chi":
    case "mech. proj.":
    case "misc":
    case "thrown":
    case "defense":
    case "double wield":
    case "bargaining":
    case "stealing":
	 num = FORM3; break;
    case "locks/traps":
    case "stealth":
    case "forestry":
    case "education":
	 num = FORM4; break;
    }
  }
  else if(rac == "sidhe") {
    switch(skill) {
    case "defense":
    case "stealth":
    case "stealing":
    case "forestry":
    case "air":
	 num = FORM1; break;
    case "earth":
    case "fire":
    case "water":
    case "locks/traps":
    case "dagger":
	 num = FORM2; break;
    case "bargaining":
    case "education":
    case "misc":
    case "thrown":
    case "melee":
	 num = FORM3; break;
    case "double wield":
    case "sword":
    case "blunt":
    case "murder":
    case "mech. proj.":
	 num = FORM4; break;
    case "chi":
    case "polearm":
    case "healing":
    case "necromancy":
    case "sorcery":
    case "wrath":
	 num = FORM5; break;
    }
  }
  return num;
}

int training_formula_class(string rac, string *cl, int lvl, string skill) {

  int i,num = 0;

  if(sizeof(cl))
    for(i = 0;i<sizeof(cl);i++) {
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
	   num += (int)find_object_or_load(""+CLASS_DIR+cl[i]+"")->get_skill_cost(skill,lvl);
	   break;
	 }
    }

  if(num) num /= sizeof(cl);

  if(!sizeof(cl) || cl == ({"adventurer"}))
    num = FORM5*2000;

  return to_int((num * CLASS_FRACT) + (training_formula_race(rac,lvl,skill) * RACE_FRACT));

}
