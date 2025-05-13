
/* =============================================================== 
   Userdoc: monk_soul          /players/whisky/guild/monk_soul.c
   ---------------------------------------------------------------
   Art: The guildsoul of the monks included in ~warlord/guild/soul.c
   Special: This soul works skillbased. The skills which are used
            in the skill_master are overwritten, because the skill-
            system of the lib is much too slow and unflexible.
            The skills which are used by this soul can be found under
            ~whisky/guild/skills/ .
   =============================================================== */


#define SKILLS  "/players/whisky/guild/skills/"
#define HELPDIR "/players/whisky/guild/help/"
#define _gm "/guild/master"
#define _partner "/players/warlord/guild/room"

/* prototyping */
fcn_skills(arg);
inherit "obj/armour";

//#include "/obj/descs.h"    # not needed in this soul
//#include "lw.h"            # not needed in this soul

/* --------------------------------------------------------------
   Include Explanations in row:

   a) This guild has an own help levels system
   b) This guild sets the titles undepending from the guildmaster
   c) The file where the names of the protectors are stores
   d) The file where the skillmapping is stored + the executiontime
   e) The extra look of a monk
   f) The legend system of the monks guild
   -------------------------------------------------------------- */
   
#include "/players/whisky/guild/levels.h" 
#include "/players/whisky/guild/titles.h" 
#include "/players/whisky/guild/protectors.h"
#include "/players/whisky/guild/timer.h"     
#include "/players/whisky/guild/extra_look.h"
#include "/spells/spell.h"


int timer;         /* how fast is the skill in seconds ? */
int g_status;      /* is it a normal member, a protector or a wiz */ 
int first_init;    /* variable to check for the resistances */  
closure call, out; /* direct adress operator for faster speed */

/* prototyping */
void timer_zero(string *arr);

/* the reset is called any 45 minutes and when the player gets the soul */
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
       first_init = 1;
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

int get()
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

/*

void update_legends(int i)
{
    int lg_lev;

    if (apply(call,this_player(),"query_exp") > 2000000 &&
      apply(call,this_player(),"query_age") > 250000 && 
      apply(call,this_player(),"query_level") < 30 )
    {
	    lg_lev = (apply(call,this_player(),"query_exp")/500000 - 3);
	    if (lg_lev > 150)
	        lg_lev = 150;
    	apply(call,this_player(),"add_property","monk_legend",lg_lev);
	   apply(out,"extra_title",3,this_player());
    }
}
 */

void init() 
{
    object shad;
    int i, sz, mod_wis;
    string *skills, col;
    closure act;

    ::init();

    if (environment()!=this_player()) 
	     return;

    if (first_init) 
    {
//        update_legends(0);
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
                         !apply(call,this_player(),"query_immortal"))
	          apply(out,"query_own_titles",1);

         if (member(PROTECTORS,apply(call,this_player(),"query_real_name"))==1)
	          g_status = PROTECTORS[apply(call,this_player(),"query_real_name")];
         else
	          g_status = 0;

         if (g_status > 0 && 
             apply(call,this_player(),"query_property","monk_legend") < 1)
         {
	          apply(call,this_player(),"add_property","monk_legend",1); 
         }

        /* seting the natural resistances of the monk.
           Please don't use that for items or other guilds, without
           the allowance of an Archwiz. 
           Monks have naturally some better resistances.
           So please don't copy that  !
                                                                 */
         mod_wis =  1 + apply(call,this_player(),"query_wis") / 3;

// against nature, and not against acid !
         modify_resistance(FIRE, mod_wis );
         modify_resistance(COLD, mod_wis );
         modify_resistance(POISON, mod_wis );
         modify_resistance(ELECTRICITY, mod_wis );

// against mindeffectives
         modify_resistance(MINDEFFECTIVE, mod_wis);
         modify_resistance(ILLUSION, mod_wis);
         modify_resistance(PETRIFICATION, mod_wis);
    }
    if (apply(call,this_player(),"combat_shad")!=1)
    {
	     shad = clone_object("/players/whisky/guild/shadows/combat_shad");
	     apply(call,shad,"start_shadow",this_player(),0,"combat_shad");
    }
    /* setting the fighting values in the guild shadow */
    apply(call,this_player(),"recalc_fight");
    skills = m_indices(TIME);

    act = #'add_action;

    apply(act,"fcn_help","help");
    apply(act,"fix","fix");

    for (sz = sizeof(skills),i = 0; i < sz; i++)
	      apply(act,"fcn_skills",skills[i]);


    if (this_player() && interactive(this_player()))
	      command("wear belt",this_player());
}

int fcn_skills(string arg)
{
   object mob;

    if (timer == 1)
    {
        write("");
	     return 1;
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
        {
	         timer_zero(({ query_verb(), arg }));
            return 1;
        }
	     else 
	     {
// this is important so skill north don't work anymore
            if (arg && query_verb()!="teach" && query_verb()!="find")
           {
               mob = present(arg,environment(this_player()));
               if (!mob || environment(mob) != environment(this_player()))
               {
                   write("Never here when required !\n");
                   timer = 0;
                   return 1;
               }
           }
	        funcall(out,"timer_zero",
                        TIME[query_verb()][0],({ query_verb(), arg }));
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
//    update_legends(1);

    /* setting the fighting values */
    apply(call,this_player(),"recalc_fight");

    /* recalcing the legends for the combat shad */
    apply(call,this_player(),"update_values",this_player());

    /* checking bad armours */ 
    apply(call,this_player(),"fix_armours");

// # removed living_bug apply(call,this_player(),"update_weight");

    /* setting the heart beat again */
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
    else if (arg=="legendlevels")
    {
        funcall(call,_gm,"list_legend_levels",7,
                apply(call,this_player(),"query_gender"));
        return 1;
    }
    else if (file_size(HELPDIR+arg) > 0) 
    {
	    cat(HELPDIR+arg);
	    return 1;
    }
    return 0;
}


void extra_title(object mob)
{
    mob->set_title("Legend");
    if (mob->query_property("monk_legend") > 100)
    {
        mob->set_pretitle("Outer World Ruler");
    }
    return;
}

int query_monk_wear()
{
    return 1;
}

int query_guild_status()
{
    return g_status;
}

void guild_changes()
{
   object shad;

    apply(call,this_player(),"set_n_ac",0); 
    apply(call,this_player(),"set_n_wc",0); 
    apply(call,this_player(),"remove_property","monk_legend");
    if ( (shad = apply(call,this_player(),"combat_object")) )
          destruct(shad);
    return;
}

