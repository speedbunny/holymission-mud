
/* skill system for the fighters */

#define _gm "/guild/master"

closure call;

void skill_reset(int flag)
{
     if (flag == 0)
         call = #'call_other;
}

/* skilltype : skillname min_skill max_skill  costfactor */

#define SKILLS ([ \
        "fighter_bludgeon":   ({"bludgeon",1,100,500}),    \
        "fighter_pierce":     ({"pierce",1,100,150}),      \
        "fighter_slash":      ({"slash",1,100,300}),       \
        "fighter_parry":      ({"parry",1,100,250}),       \
        ])
  
/*
  Function: query_skill(object, skill)
  Returns: 0 or the actual skill of the fighter 
                                                   */
int query_skill(object mob,string mskill)
{
   mixed skill;

   skill = funcall(call,mob,"get_skill",mskill);

   if ( sizeof(skill)  && member(SKILLS,mskill)==1)
      return skill[0];
   return 0;
}

/*
  Function: query_cost(object, skill)
  Returns: the actual costs of the skill 
                                                   */
int query_cost(object mob,string mskill)
{
   int cost;

    if (!mskill || member(SKILLS,mskill)!=1)
        return 0;

    cost = SKILLS[mskill][3] + SKILLS[mskill][3] * query_skill(mob,mskill);

    return cost;
} 

  
/*
  Function: list_skills(object, silence)
  Usage: silence 0 silence 1 skill display 2 full display 
                                                                        */
mixed list_skills(object mob,int silence)
{
    int i, sz;
    mixed skill;
    string *skills;
    string ret;

    ret = "";
    skills = m_indices(SKILLS);
    sz = sizeof(skills);

    if (silence==2)
    {
      ret+=sprintf("----------------------------------------------------------\n");
      ret+=sprintf("%-15s %-25s %-10s %-10s\n",
              "Skilltype:","Skilllevel:","Max.Skill:","Cost:");
      ret+=sprintf("----------------------------------------------------------\n");
    }
    else if (silence == 1)
    {
       ret+=sprintf("--------------------------------------\n");
       ret+=sprintf("%-15s %-25s\n",
              "Skilltype:","Skilllevel:");
       ret+=sprintf("--------------------------------------\n");
    }
    for (i = 0; i < sz; i++)
    {
       if (!funcall(call,mob,"get_skill",skills[i]))
       {
          funcall(call,"/guild/master","change_skill",
          mob,skills[i],SKILLS[skills[i]][1]+random(5),
                        SKILLS[skills[i]][2],3);
       }
       skill = funcall(call,mob,"get_skill",skills[i]);
       if (silence==2)
       {
         ret+=sprintf("%-15s %-25s %-10s %-10s\n",
         SKILLS[skills[i]][0],
         funcall(call,"/obj/skill_master","get_skill_title",skill[0]),
         "guru",
         to_string(query_cost( mob, skills[i])));
       }
       else if (silence == 1)
       {
         ret+=sprintf("%-15s %-25s\n",
         SKILLS[skills[i]][0],
         funcall(call,"/obj/skill_master","get_skill_title",skill[0]) );
       }
    }
  return ret;
}

/*
   Function: raise_skill ( object, skillid, boni)
   Returns: -1 if no fighter skill, 0 if not valid : the newskill
                                                                */    
int raise_skill(object mob,string mskill,int boni)
{
   int newskill;

    if (member(SKILLS,mskill)!=1)
        return -1;
   
    if (query_skill(mob,mskill)) 
        newskill = query_skill(mob,mskill) + boni;
    else 
       return 0;

    if (newskill > 100)
        newskill = 100;
    if (newskill < 1)
        newskill = 1;
   
      
    funcall(call,_gm,"change_skill",mob,mskill,newskill,SKILLS[mskill][2],3);

    return newskill;
}
    
 /* end */
