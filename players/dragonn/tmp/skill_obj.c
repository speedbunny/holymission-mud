


/* =============================================================== 
   Userdoc: skill_obj.c          /players/whisky/guild/skill_obj.c
   ---------------------------------------------------------------
   Art: inherit file, is inherited in any skill
   Special: It handles the skilldepending things with the skillsystem.
            It is responsible to handle the timing of skillraise and
            to check if a living present or if the player is under 
            attack. 
   =============================================================== 


   Usage: Easy when you use the functions of /players/whisky/skill_system.
   Just inherit this file then like:

   inherit "/players/whisky/skill_obj";

   void reset(int flag)
   {
        ::reset(flag);
        if (!flag)
            set_partner("/players/warlord/guild/room");
   }
                                                                        */

/* the defines */

#define the_partner "/players/warlord/guild/room"

closure call;
string partner;

void reset(int flag)
{
    if (flag == 0)
    {
       call = #'call_other;
       if (!partner)
           partner = "/players/warlord/guild/room";
       catch(apply(call,partner,"???"));
    }
}


/*
   Functionname: set_partner(who)
   This function sets the partner of the object. The partner can be
   the guildroom or the guildsoul. The place where the player can
   raise or change her skill.
                                                                  */

void set_partner(string where)
{
     partner = where;
}


/* 
   Function: chk_ghost
   This function checks if the player is a ghost. If yes it writes a
   message and returns 1 else it returns 0.
                                                                   */

int chk_ghost(object player)
{
      if (apply(call,player,"query_ghost"))
      {
         write("Your ghostly body is not build for this attemt.\n");
         return 1;
      }
      return 0;
}

/*
   Function: chk_present(player,whom,skillcost)
   This function looks is the "who" is present in the environment of 
   the this_player() and if the this_player has enough spell_points
   to use this skill. If the skill costs nothing just use 0 for the 
   costs.
                                                                    */
varargs mixed chk_present(object player,string arg,int cost)
{
   object mob;

       if (chk_ghost(player))
           return 1;

       if (!stringp(arg) || !(mob = present(arg,environment(player))))
       {
           write("Whom ?\n");
           return 1;
       }
       else if (cost > apply(call,player,"query_sp"))
       {
          write("You are too low on power !\n");
          return 1;
       }
       else if (objectp(mob) && living(mob))
           return mob;
     write(
     capitalize(arg)+" is not a living !\n");
     return 1;
}

       
/*
   Function: chk_attack(player,whom,skillcost)
   This function looks is the "who" is present in the environment of 
   the this_player() and if the this_player has enough spell_points
   to use this skill. If the skill costs nothing just use 0 for the 
   costs. Its like the chk_present function, but if sucess the present
   arg will be attacked.
                                                                    */
varargs mixed chk_attack(object player,string arg,int cost)
{
   object victim;

       if (chk_ghost(player))
           return 1;

       if (!stringp(arg))
           victim = apply(call,player,"query_attack");
       else       
           victim = present(arg,environment(player));

       if (cost > apply(call,player,"query_sp"))
       {
          write("You are too low on power !\n");
          return 1;
       }
       else if (objectp(victim) && living(victim) && 
                environment(victim) == environment(player) )
       {
           if (victim == player)
           {
              write("You try to hit yourself, but you fall on your but !\n");
              return 1;
          }
          else 
           return victim;
       }
     write("You can't attack someone who is not here or already dead !\n");
     return 1;
}

/*
   Function: chk_skill(player, skilltype, how hard to advance)
   This function checks if the player has a sucessful skillroll.
   If yes it returns 1 if no it returns 0. Besides it checks if
   the player may advance the skill by training.
                                                              */

int chk_skill(object player,string sk,int diff)      
{
    mixed skill;

    skill = funcall(call,player,"get_skill",sk);

    if (!skill)
         skill = 1;
    else
       skill = skill[0];

    if (random(101) > skill)
    {
// skillfailure
        if (!random( (skill * diff) ) )
        {
            if (apply(call,player,"query_guild")==7)
            {
                tell_object(player,"You feel your skill raised !\n");
                apply(call,partner,"raise_skill",player,sk,1);
            }
         }
        return 0;
    }
    return 1;
}

       
