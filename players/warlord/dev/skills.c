//	/std/living/skills.c
//	from the Nightmare mudlib
//	code for the Nightmare skill system
//	created by Descartes of Borg 1september 1992
//	recoded 14 february 1993

#include <daemons.h>
#include <skills.h>

string *classes;
mapping skills;
  static mapping skill_bonus;
  static mapping skill_bonus_duration;

void init_skills(string race_t);
int skill_cost(object tp, string skill);
void add_skill_points(string skill, int amount);
int add_skill(string type, int level, int max);
void reduce_skill_points(string skill, int amount);
void set_skill(string str, int x);
void set_max_skill(string str, int x);
void add_new_skill(string str, int x, int y);
int skill_exists(string str);
int query_max_skill(string str);
int query_skill(string str);
void set_class(string str);
string query_class();

void init_skills(string race_t)   {
  skills = (mapping)SKILLS_D->init_skills(race_t);
}

int skill_cost(object tp, string skill) {
  int temp, x, borg, max, lvl;

  temp = tp->query_true_race();
  
  x = skills[skill]["points"];
  lvl = skills[skill]["level"];
  if(lvl == 0)
    return 0;
  max = ((skills[skill]["max"])*((int)tp->query_level()))/20;
  if (tp->is_class("adventurer"))
    borg = (int)SKILLS_D->training_formula_race(temp, lvl, skill);
  else
    borg = (int)SKILLS_D->training_formula_class(temp, tp->query_all_classes(), lvl, skill);
  return (borg - x);
}

int query_skill_points(string skill) {
  return skills[skill]["points"];
  }

void add_skills(string cl)  {
  string *klf;
  mapping temp;
  int i;

  if(!(temp = (mapping)SKILLS_D->init_skills(cl))) return;
  klf = keys(temp);
  for(i=0; i<sizeof(klf); i++)  {
    if(temp[klf[i]]["max"] < query_max_skill(klf[i])) continue;
    if(!skill_exists(klf[i])) 
      add_skill(klf[i], temp[klf[i]]["points"], temp[klf[i]]["max"]);
    else
      set_max_skill(klf[i], temp[klf[i]]["max"]);
  }
}

void add_skill_points(string skill, int amount) {
  int x, max, borg, lvl;
  string temp;
    
  temp = (string)this_object()->query_true_race();
  if(!(this_object()->is_player())) return;
  if(!skills[skill]) return;
  if(amount<1) return;
  x = skills[skill]["points"];
  lvl = skills[skill]["level"];
  x += amount;
  max = ((skills[skill]["max"])*((int)this_object()->query_level()))/20;

  if (this_player()->is_class("adventurer")) {
    if(lvl == 0) {
	 if(x > (int)SKILLS_D->training_formula_race(temp, 9, skill)) {
	   lvl = 1;
	   x = 0;
	 }
    }
    else {
	 while( x > (borg = (int)SKILLS_D->training_formula_race(temp, lvl, skill)) ) {
	   x -= borg;
	   if(max > lvl) lvl ++;
	   else break;
	 }
    }
  }
  else {
    if(lvl == 0) {
	 if(x > (int)SKILLS_D->training_formula_class(temp, this_player()->query_all_classes(),9, skill)) {
	   lvl = 1;
	   x = 0;
	 }
    }
    else {
	 while( x > (borg = (int)SKILLS_D->training_formula_class(temp, this_player()->query_all_classes(), lvl, skill))) {
	   x -= borg;
	   if(max > lvl) lvl ++;
	   else break;
	 }
    }
  }
  
  skills[skill]["points"] = x;
  if(lvl != skills[skill]["level"]) {
    log_file("skills", (string)this_object()->query_name()+" advanced "+
		   skill+" from "+skills[skill]["level"]+" to "+lvl+" ("+
		   ctime(time())+")\n"
		   );
  }
  skills[skill]["level"] = lvl;
}

void reduce_skill_points(string skill, int amount) {
  int x, lev;
  string temp;
  
  temp = this_object()->query_true_race();
  if(skills[skill]) x = skills[skill]["points"];
  else return;
  if(amount < 1) return;
  x -= amount;
  lev = skills[skill]["level"];
  
  if (this_player()->is_class("adventurer")) {
    while( x < 0) {
	 x += (int)SKILLS_D->training_formula_race(temp,skills[skill]["level"]-1, skill);
	 skills[skill]["level"] --;
    }
  }
  else {
    while( x < 0) {
	 x += (int)SKILLS_D->training_formula_class(temp, this_player()->query_all_classes(),skills[skill]["level"]-1, skill);
	 skills[skill]["level"] --;
    }
  }
  skills[skill]["points"] = x;
  if(skills[skill]["level"] != lev)
    log_file("skills", (string)this_object()->query_name()+" reduced "+
		   skill+" from "+skills[skill]["level"]+" to "+lev+" ("+
		   ctime(time())+")\n"
		   );
}

int query_max_skill(string skill) {
  if(!skills[skill]) return 0;
  else return skills[skill]["max"];
}

int skill_exists(string str) {
  string *vars;
  
  vars = keys(skills);
  if(str == "picking") return 0;
  if(member_array(str, vars) == -1) return 0;
  else return 1;
}

int query_skill(string skill) {
  int x;
  
  if(skill_bonus) x= skill_bonus[skill];
  else x = 0;
  if(skills[skill]) x+= skills[skill]["level"];
  else x+= 0;
  return x;
}

int query_base_skill(string skill) {
  if(!skills || !skills[skill]) return 0;
  else return skills[skill]["level"];
}

void set_skill(string str, int x) {
  if(!skills[str]) skills[str] = ([ "level":0 ]);
  skills[str]["level"] = x;
  if(!this_object()->is_player() || wizardp(this_object())) return;
  log_file("illegal", (string)this_object()->query_name()+
		 " was advanced in "+str+" artificially by "+
		 (this_player() ? this_player()->query_name() : previous_object()->query_name())+"\n");
  log_file("illegal", "file: "+file_name(previous_object())+" ("+
		 getuid(previous_object())+") "+ctime(time())+"\n");
}

void set_class(string str) { classes = ({ str }); }

void add_class(string str)  {
  if(classes && sizeof(classes) >= 3) return;
  if(query_class() == "adventurer")
    set_class(str);
  else
    classes += ({ str });
}

void remove_class(string str) {
  classes -= ({ str });
  if (sizeof(classes) == 0) {
    set_class("adventurer");
  }
}

//string query_class() { return (classes ? implode(classes,"/") : "adventurer"); }

string query_class() { return (classes ? classes[0] : "adventurer"); }

static void reduce_skills(int damage) {
  string *ind;
  int i;
  
  ind = keys(skills);
  for(i=0; i<sizeof(ind); i++) {
    if(!skills[ind[i]]) continue;
    if(query_skill(ind[i]) < 5) continue;
    if(random(101) > 50+damage/2) {
	 log_file("skills", this_object()->query_name()+" lost "+
			ind[i]+" through reduce_skills() "+ctime(time())+"\n");
	 skills[ind[i]]["level"] -= random(5)+1;
	 skills[ind[i]]["points"] = 0;
    }
  }
}

int add_skill(string type, int level, int max) {
  
  if(member_array(type,GLOBAL_SKILLS) == -1)
    return 0;
  
  if(skill_exists(type)) return 0;
  skills[type] = (["level" : level, "points": 0, "max": max]);
  return 1;
  
}

int delete_skill(string type) {
  if(!skill_exists(type)) return 0;
  map_delete(skills, type);
  return 1;
}

string *query_all_skills() { return keys(skills); }

varargs void add_skill_bonus(string skill, int amount, int duration) {
  if(!skill_bonus) skill_bonus = ([]);
  if(!skill_bonus[skill]) skill_bonus[skill] = amount;
  else skill_bonus[skill] += amount;
  if(!skill_bonus[skill]) map_delete(skill_bonus, skill);

  if(duration) {
    if(!skill_bonus_duration) skill_bonus_duration = ([]);
      if(skill_bonus_duration[skill])
        skill_bonus_duration[skill] += duration;
      else
        skill_bonus_duration[skill] = duration;
  }

}

int query_skill_bonus(string skill) {
  if(!skill_bonus) return 0;
  if(!skill_bonus[skill]) return 0;
  return skill_bonus[skill];
}

void set_max_skill(string str, int x)  {
  if(!skill_exists(str) || x < 0) return;
  else skills[str]["max"] = x;
}

int is_class(string str)  { 
  if(!classes) classes = ({ "adventurer" });
  return (member_array(str, classes) != -1);
}

string *query_all_classes() { return classes; }
