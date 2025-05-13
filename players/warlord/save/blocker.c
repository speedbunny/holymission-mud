

#define COMS ({"say","monk","tell","ring","help","mt","who","score","look",\
               "rwhere","alias","monkey","ering","i","mood","l","exa","sc",\
               "mskills","smile","finger","attr"})

#define LEG  (environment()->query_property("monk_legend")+ 1)
#define FORM ((100 + LEG * 15) / (100 + LEG))
#define RATE ((3 + environment()->query_wis()/3) + FORM)

int heal;

int id(string arg)
{
    return arg == "blocker";
}

void reset(int flag)
{
    if (flag == 0)
        enable_commands();
}

int drop(string arg) 
{ 
   if (id(arg))
       return 1; 
   return 0;
}

int get(string arg)
{
    return 1;
}

int query_weight()
{
    return 0;
}


void init() 
{
  if (this_player())
      this_player()->set_meditating();
  add_action("check_allowed","",1);
  set_heart_beat(1);
}

void remove_me()
{
   if (environment() && environment()->query_player())
   {
       say(environment()->query_name()+" stops meditating.\n",environment());
       tell_object(environment(),"You stop meditating.\n");
   }
   destruct(this_object());
}

int check_allowed(string arg) 
{ 
    if (objectp(environment()) && environment()!=this_player())
        return 0;
    else if (query_verb() == "wake" || query_verb() == "wakeup")
    {
        remove_me();
        return 1;
    }
    else if (this_player()->query_level() > 29 
        || member_array(query_verb(),COMS)!=-1)
    return 0;
    write("You can't do that while meditating, type 'wakeup' to stop.\n");
  return 1;
}

void heart_beat()
{
   object ob;


    if ( objectp(environment()) && living(environment()) )
    { 
       if (ob = environment()->query_attack());
       if(  environment()->query_hp() >= environment()->query_max_hp() &&
            environment()->query_sp() >= environment()->query_max_sp() ) 
          remove_me();
       else if (ob && environment(environment())==environment(ob) )
          remove_me();
       else 
       {
         if (!heal)
             heal = 1;
         if (random(100) < heal)
            environment()->heal_self( RATE );
         environment()->heal_self(1);
      } 
    }
    else 
      remove_me();
}

int add_heal(int h)
{
   heal = h;
}

