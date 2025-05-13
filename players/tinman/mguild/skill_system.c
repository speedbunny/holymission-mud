
/* skill system */

#define _gm "/guild/master"

closure call;

void skill_reset(int flag)
{
     if (flag == 0)
         call = #'call_other;
}

/* skilltype : skillname min_skill max_skill  costfactor */

#define SKILLS ([ \
        "monk_meditate":   ({"meditate",1,100,120}),    \
        "monk_attack":     ({"attack",1,100,300}),      \
        "monk_blink":      ({"blink",1,100,200}),       \
        "monk_aikido":     ({"aikido",1,100,20}),       \
        "monk_bless":      ({"bless",1,100,75}),        \
        "monk_cure":       ({"cure",1,100,150}),        \
        "monk_grill":      ({"grill",1,100,2}),         \
        "monk_scan":       ({"scan",1,100,30}),         \
        "monk_death":      ({"death",1,100,200}),       \
        "monk_damage":     ({"damage",1,100,300}),      \
        "monk_choke":      ({"choke",1,100,40}),        \
        "monk_smash":      ({"smash",1,100,300}),       \
        "monk_disarm":     ({"disarm",1,100,90}),       \
        "monk_block":      ({"block",1,100,40}),        \
        "monk_rescue":     ({"rescue",1,100,15}),       \
        "monk_feet":       ({"feet",1,100,14}),         \
        "monk_springleap": ({"springleap",1,100,150}),  \
        "monk_hide":       ({"hide",1,100,200}),        \
        "monk_dead":       ({"dead",1,100,50}),         \
        "monk_dodge":      ({"dodge",1,100,300}),       \
        ])
  
/*
  Function: query_skill(object, skill)
  Returns: 0 or the actual skill of the monk 
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
  Function: query_all_skills()
  Returns: an array of all skills a monk can learn !
                                                   */

string *query_all_skills()
{
       return m_indices(SKILLS);
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

mixed query_skill_title(int lv)
{
    if (!lv)
         return "not learned";
    return funcall(call,"/obj/skill_master","get_skill_title",lv);
}
  
/*
  Function: list_skills(object, silence)
  Usage: silence 0 silence 1 skill display 2 full display 
                                                                        */
mixed list_skills(object mob,int silence)
{
    int i, sz;
    mixed skill, skill2;
    string *skills;
    string ret;

    if (!silence) 
         return 0;

    ret = "";
    skills = m_indices(SKILLS);
    sz = sizeof(skills);

    if (silence==2)
    {
       ret+="----------------------------------------------------------\n";
       ret+=sprintf("%-15s %-25s %-10s %-10s\n",
              "Skilltype:","Skilllevel:","Max.Skill:","Cost:");
       ret+="----------------------------------------------------------\n";
    }
    else if (silence == 1)
    {
       ret+="---------------------------------------------------------------\n";
       ret+="                        MONK SKILLS                            \n";
       ret+="===============================================================\n";
       ret+=sprintf("%-11s %-22s %-11s %-22s\n",
              "Skilltype:","Skilllevel:","Skilltype:","Skilllevel:");
       ret+="---------------------------------------------------------------\n";
       ret+="\n";
    }
    i = 0;
    while(i < sz)
    {
       skill = funcall(call,mob,"get_skill",skills[i]);
       
       if (sizeof(skill))
           skill = skill[0];
       else 
            skill = 0;

       if (i+1 < sz)
       {
           skill2 = funcall(call,mob,"get_skill",skills[i+1]);

           if (sizeof(skill2))
               skill2 = skill2[0];
           else 
               skill2 = 0;
        }
        else 
           skill2 = 0;

       if (silence==2)
       {
            ret+=sprintf("%-15s %-25s %-10s %-10s\n",
            SKILLS[skills[i]][0],
            query_skill_title(skill),
            "guru",
            to_string(query_cost( mob, skills[i])));
            i++;
       }
       else if (silence == 1)
       {
           if ( (i+1) < sz)
           {
                ret+=sprintf("%-11s %-22s %-11s %-22s\n",
                SKILLS[skills[i]][0],
                query_skill_title(skill),
                SKILLS[skills[i+1]][0],
                query_skill_title(skill2) );
           }
           else 
           {
                ret+=sprintf("%-11s %-22s\n",
                SKILLS[skills[i]][0],
                query_skill_title(skill));
            }
            i = i + 2;
        }
    }
    return ret;
}

/*
  Function: raise_practice(object, boni)
  Returns: the new practice sessions of the monk
                                                   */
int raise_practice(object mob,int boni)
{
   int mbon;
   int act;
   object master;

   if (boni)
       mbon = boni;
   else 
       mbon = 0;

   if (!act = query_skill(mob,"monk_practice"))
   {
      if (mbon > 100)
          mbon = 100;
      funcall(call,_gm,"change_skill",mob,"monk_practice",mbon,100,7);
      return mbon;
    }
    if (act + mbon > 100)
       mbon = 100;
    else 
       mbon = act + mbon;
    funcall(call,_gm,"change_skill",mob,"monk_practice",mbon,100,7);
    return mbon;
}
    
/*
   Function: set_skill_time ( player, skill )
   Sets: The time the player raised her skill, the last time.
   Returns: -1 when she didn't raise a skill before
             0 when she didn't raise this skill before
            -2 when there is somehow a bug
          else it returns the time in players life when the new skill is set  
                                                                         */

int set_skill_time(object player,string skill)
{
    int age;
    mapping time;

    age = apply(call,player,"query_age");

    if ( (time = funcall(call,player,"query_property","ms_time"))==-1)
    {    
        funcall(call,player,"add_property","ms_time",([skill:age]));
        return -1;
    }
    else 
    {
         apply(call,player,"remove_property","ms_time");

         if (!time[skill])
         {
              time = time + ([skill:age]);
              funcall(call,player,"add_property","ms_time",time);
              return 0;
          }
          else 
          {
              time = m_delete(time,skill);  
              time = time + ([skill:age]);
              funcall(call,player,"add_property","ms_time",time);
              return age;
           }
      }
      return -2;
}

             
/*
   Function: query_skill_time ( player, skill)
   Returns: The last time the player raised her skill in heart_beats,
            -1 when the player has never raised skills or 0 when she
            she didn't raise the skill before;
                                                                */    
        
int query_skill_time(object player,string skill)
{
    mapping time;
    int res;
     
    if ((time = funcall(call,player,"query_property","ms_time"))==-1)
         return -1;
    else if (!(res = time[skill]))
         return 0;
     return res;
}

/*
   Function: raise_skill ( object, skillid, boni)
   Returns: -1 if no monk skill, 0 if not valid : the newskill
                                                                */    
int raise_skill(object mob,string mskill,int boni)
{
   int newskill;

    if (member(SKILLS,mskill)!=1)
        return -1;
   
    if ( (newskill = query_skill(mob,mskill)) ) 
        newskill = newskill + boni;
    else 
        newskill = boni;

    if (newskill > 100)
        newskill = 100;
    else if (newskill < 1)
        newskill = 1;
   
      
    funcall(call,_gm,"change_skill",mob,mskill,newskill,SKILLS[mskill][2],7);

    if (boni > 0)
        set_skill_time(mob,mskill);

    return newskill;
}

#define ACC ({"sauron","misticalla"})

/*
   Function: set_skills ( object, skillid, level)
   Returns: 0 if not valid setter, 1 for one skill, 
            the number of skills when the skillid was "all" 
                                                                */    
int set_skills(object mob,string mskill,int lv)
{
   string *skills;
   int sz;

    if (!interactive(this_player()) || 
         member_array(this_player()->query_real_name(),ACC)==-1)
         return 0;

    if (mskill=="all") 
    {
        skills = m_indices(SKILLS);
        sz = sizeof(skills);
       
        while(sz)
        {
           sz--;
           _gm->change_skill(mob,skills[sz],lv,
                             SKILLS[skills[sz]][2],7);
        }
        return 2;
     }
     _gm->change_skill(mob,mskill,lv,SKILLS[mskill][2],7);
     return 1;
}

 /* end */
