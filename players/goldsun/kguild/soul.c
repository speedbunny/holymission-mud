
/* knightsoul */

#define SKILLS  "/players/goldsun/guild/skills/"
#define HELPDIR "/players/goldsun/guild/help/"
#define _gm "/guild/master"

fcn_skills(arg);

inherit "obj/armour";

#include "/obj/descs.h"
#include "lw.h"
#include "levels.h"
#include "/players/goldsun/guild/timer.h"
#include "/players/goldsun/guild/extra_look.h"

int timer;

/* prototyping */

void timer_zero(string *arr);

void reset(int flag) 
{
  string col;

    ::reset(flag);
    if(flag == 0) 
    {
       switch(this_player()->query_level())
       {
        case 1..5:   col = "copper";  break;
        case 6..10:  col = "iron";  break;
        case 11..15: col = "bronze";  break;
        case 16..20: col = "silver"; break;
        case 21..25: col = "golden";   break;
        case 26..32: col = "platinum";    break;
        default:     col = "diamond"; break;
       }
       set_name("spurs");
       timer = 0;
       set_type("guild");   
       set_alias(col+" spurs");
       set_ac(1);
       set_short("Dusty "+col+" spurs");
       set_long("The spurs of the Knights.\n");
       set_weight(0); 
    }
}

int id(string arg)
{
  return arg == "spurs" || arg == "knightsoul";
}
   
int drop(string arg)
{ 
  return 1;
} 

int remove(string arg) 
{
    if(id(arg)) 
    {
   	write("You can't remove your spurs !\n");
	   return 1;
   }
   return 0;
}

void init() 
{
  object shad, shad2, shad3;
  int lev;

   if (!this_player()->query_immortal() &&
       this_player()->query_level()> 25 && 
       this_player()->query_age()> 500000 && 
       (lev = this_player()->query_exp())> 2000000)
   {
       lev = lev / 500000 - 3;
       this_player()->add_property("knight_legend",lev);
   }


    ::init();

    add_action("fcn_help","help");
    add_action("fcn_skills","",1);
    if (this_player() && interactive(this_player()))
        command("wear spurs",this_player());
}

fcn_skills(arg)
{
    write(timer+"\n\n");
    if (member(TIME,query_verb())!=1)
        return 0;
 
   if (timer == 1)
   {
       notify_fail(">>");
       return 0;
   }
   else 
   {
     timer = 1;
     if (TIME[query_verb()][0]==-1)
         timer_zero(({ query_verb(), arg }));
     else 
     {
         call_out("timer_zero",TIME[query_verb()][0],({ query_verb(), arg }));
         write(TIME[query_verb()][1]);
     }
     return 1; 
   }
}

void timer_zero(string *arr)
{
     if (stringp(arr[1]))
         call_other(SKILLS+arr[0],arr[0],arr[1]);
     else 
         call_other(SKILLS+arr[0],arr[0]);
     timer = 0;
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



