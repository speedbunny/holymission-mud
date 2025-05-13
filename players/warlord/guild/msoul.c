
/* monksoul */
/* new: only joinable for humans and hobbits */

#define SKILLS  "/players/whisky/guild/skills/"
#define HELPDIR "/players/whisky/guild/help/"
#define _gm "/guild/master"
#define _partner "/players/warlord/guild/room"

/* prototyping */
fcn_skills(arg);
inherit "obj/armour";

#include "/obj/descs.h"
#include "lw.h"
#include "/players/whisky/guild/levels.h"
#include "/players/whisky/guild/titles.h"
#include "/players/whisky/guild/protectors.h"
#include "/players/whisky/guild/timer.h"
#include "/players/whisky/guild/extra_look.h"


int timer;
int g_status;
closure call, out; /* direct adress operator for faster speed */

/* prototyping */
void timer_zero(string *arr);

void reset(int flag) 
{
  string col;
 
  if (objectp(environment()) && !interactive(environment()))
  {
      if (find_call_out("timer_zero"))
      {
          timer = 0;
          remove_call_out("timer_zero");
      }
  }

    ::reset(flag);
    if(flag == 0) 
    {
       call = #'call_other; /* getting the adress of call_other */
       out = #'call_out;    /* getting the adress of call_out */
       set_name("belt");
       timer = 0;
       set_type("guild");   
       set_ac(1);
       set_long("The belt of the Monks.\n");
       set_weight(0); 
    }
}

int id(string arg)
{
  return arg == "belt" || arg == "monksoul";
}
   
int drop(string arg)
{ 
  return 1;
} 

int remove(string arg) 
{
    if(id(arg)) 
    {
   	write("You can't remove your belt !\n");
	   return 1;
   }
   return 0;
}

void init() 
{
  object shad;
  int i, sz;
  string *skills, col;
  closure act;

    ::init();

    if (environment()!=this_player()) 
        return;

    /* setting the belt colours */
    switch(apply(call,this_player(),"query_level"))
    {
      case 1..3:   col = "white";  break;
      case 4..6:   col = "brown";  break;
      case 7..10:  col = "green";  break;
      case 11..14: col = "yellow"; break;
      case 15..18: col = "blue";   break;
      case 19..22: col = "red";    break;
      case 23..26: col = "silver"; break;
      default:     col = "golden"; break;
    }
     set_alias(col+" belt");
     set_short("A strong "+col+" belt");

    if (interactive(this_player()) && 
        !apply(call,this_player(),"query_immortal") )
         apply(out,"query_own_titles",1);

    if (member(PROTECTORS,apply(call,this_player(),"query_real_name"))==1)
       g_status = PROTECTORS[apply(call,this_player(),"query_real_name")];
    else
      g_status = 0;

    if (apply(call,this_player(),"combat_shad")!=1)
    {
        shad = clone_object("/players/whisky/guild/shadows/combat_shad");
        apply(call,shad,"start_shadow",this_player(),0,"combat_shad");
    }
    /* setting the fighting values */
    apply(call,this_player(),"recalc_fight");
    skills = m_indices(TIME);

    act = #'add_action;

    apply(act,"fcn_help","help");
    apply(act,"fix","fix");

    for (sz = sizeof(skills),i = 0; i < sz; i++)
         apply(act,"fcn_skills",skills[i]);

    /* the skillsystem */
    apply(out,"load_skills",2,this_player());

    if (this_player() && interactive(this_player()))
        command("wear belt",this_player());
}

int fcn_skills(string arg)
{
   if (timer == 1)
   {
       notify_fail("");
       return 0;
   }
   else 
   {
     timer = 1;
     if (TIME[query_verb()][2] > g_status)
     {
        write("Your guildstatus is too low for that feature !\n");
        timer = 0;
        return 1;
     }
     else if (TIME[query_verb()][0]==-1)
         timer_zero(({ query_verb(), arg }));
     else 
     {
         funcall(out,"timer_zero",TIME[query_verb()][0],({ query_verb(), arg }));
         write(TIME[query_verb()][1]);
     }
     return 1; 
   }
}

void timer_zero(string *arr)
{
     if (stringp(arr[1]))
         apply(call,SKILLS+arr[0],arr[0],arr[1]);
     else 
         apply(call,SKILLS+arr[0],arr[0]);
     timer = 0;
} 

void fix()
{
     if (find_call_out("timer_zero"))
     {
         remove_call_out("timer_zero");
         timer = 0;
     }
     /* setting the fighting values */
     apply(call,this_player(),"recalc_fight");
     /* checking bad armours */ 
     apply(call,this_player(),"fix_armours");
     apply(call,this_player(),"set_heart_beat",1);
     write("Ok.\n");
}
mixed fcn_help(string arg)
{
    if (!stringp(arg))
         return 0;
    else if (arg == "levels")
    {
         show_levels();
         return 1;
    } 
    else if (file_size(HELPDIR+arg) > 0) 
    {
         cat(HELPDIR+arg);
         return 1;
    }
  return 0;
}

void load_skills(object mob)
{
  if (!catch(apply(call,_partner,"???")) )
      apply(call,_partner,"list_skills",mob,0);
}

int query_monk_wear()
{
    return 1;
}

int query_guild_status()
{
    return g_status;
}
