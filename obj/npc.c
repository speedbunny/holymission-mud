/*






         DO NOT USE THIS CODE ANY LONGER !!!!!!!!!!!

         IT IS BUGGY !!!   (pat)













*/
/* a standard npc 
   Usage: inherit this file and use it like the normal monster.c
          If you like you can set extra functions like:

          set_fol_change(int c)     [0..100] change to follow a player
          set_rid_change(int c)     [0..100] change to get rid of it
          set_dodge(int d)          [0..100] the change to dodge physical
                                             attacks.
          set_attacks(int a)        how many attacks the monster can do per
                                    round.
          set_attacks_change(int a) the change to get multible attacks

          add_property("has_answers",mapping questions&answers)
          
          EXAMPLE:

          add_property("has_answers",([
                       "elfcity":"the elfcity is to the north",
                       "tree":"the tree may be climbable",
                       "wuki":"wuki is one of the big monkmasters", ]));
                       

   Ps: please don't overdrive this (c) Whisky
                                                                      */

inherit "/obj/monster";
int dodge_change, attacks, attack_change, fol_change, rid_change;

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        dodge_change = 0;
        attacks = 0;
        attack_change = 0;
        fol_change = 0;
        rid_change = 0;
     }
}

int do_ask(string arg)
{
    string h1,h2,ans;
    mapping map;

    if (!arg) 
         return 0;
    if (sscanf(arg,"%s about %s",h1,h2)==2)
    {
        if (id(h1))
        {  
             map = funcall(call,this_object(),"query_property","has_answers");
             if (stringp(map[h2]))
                 command("say "+map[h2],this_object());
             else
                tell_room(environment(),query_name()+" shrugs helplessly.\n");
           return 1;
         }
      return 0;
     }
  return 0;
}

// the change to follow someone
void set_fol_change(int c)
{
     fol_change = c;
}
// the change to get rid of the mob
void set_rid_change(int c)
{
     rid_change = c;
}

// the change to dodge an attack [0..100]
void set_dodge(int d)
{
     dodge_change = d;
}

// the number of attacks per round
void set_attacks(int a)
{
     attacks = a;
}

// the change to get extra attacks
void set_attacks_change(int ac)
{
     attack_change = ac;
}


// follow change dont put it to high !!!!

void init()
{
#if 0
     if (this_player() && interactive(this_player()) 
         && random(100) < fol_change )
     {
         this_player()->set_follower(this_object());
     }
#endif
     if (funcall(call,this_object(),"query_property","has_answers")!=-1)
         add_action("do_ask","ask");
#if 0
     if (rid_change && random(100) < rid_change &&
         chk_follow(this_object(),this_player()) )
         funcall(call,this_player(),"rem_follower",this_object());
#endif
   ::init();
}

        
// attacks
#if 0
int attack()
{
   int num;
   
    if (::attack() && attack_change && attacks)
    {
        num = attacks;

        while(num)
        {
             num--;
             if (random(100) < attack_change)
                 ::attack();
         }
       return 1;
     }
    return 0;
}

varargs mixed hit_player(int dam,int kind,mixed elem)
{
        if (last_attacker && environment(last_attacker) == environment() &&
            kind==0 && random(100) < dodge_change)
        {
            say(query_name()+" makes a move and dodges the "+
                apply(call,last_attacker,"query_name")+"'s attack.\n",
                last_attacker);       
            tell_object(last_attacker,query_name()+
                        " dodges your lame attack !\n"); 
            return ::hit_player(0,kind,elem);
        }
   return ::hit_player(dam,kind,elem);
}
#endif
