

/* cleriksoul */

#define SPELLS  "/players/whisky/guild/spells/"
#define HELPDIR "/players/whisky/guild/chelp/"
#define _gm "/guild/master"

inherit "obj/armour";

#include "/obj/descs.h"
#include "lw.h"
#include "/players/whisky/guild/ctimer.h"

int timer;

/* prototyping */
int fcn_cast(string arg);
void timer_zero(string *arr);

void reset(int flag) 
{
    ::reset(flag);
    if(flag == 0) 
    {
       timer = 0;
    }
}

int id(string arg)
{
  return arg == "robe" || arg == "testclericsoul";
}
   
int drop(string arg)
{ 
  return 1;
} 

int remove(string arg) 
{
    if(id(arg)) 
    {
   	write("You can't remove your robe !\n");
	   return 1;
   }
   return 0;
}

void init() 
{
    string col;
    ::init();
    if (environment()!=this_player()) 
        return;

       switch(this_player()->query_level())
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

    set_name("robe");
    set_type("guild");   
    set_alias(col+" robe");
    set_ac(1);
    set_short("A strong "+col+" robe");
    set_long("The robe of the Clerics.\n");
    set_weight(0); 

    add_action("fcn_help","help");
    add_action("fix","fix");
    add_action("fcn_cast","cast");
    if (this_player() && interactive(this_player()))
        command("wear robe",this_player());
}

int fcn_cast(string arg)
{
  string spell, on_whom;

   if (!arg) 
       return 0;
   else if (sscanf(arg,"%s %s",spell,on_whom)!=2)
       spell = arg;

   if (member(TIME,spell)!=1)
       return 0;
       
   if (timer == 1)
   {
       notify_fail(">>");
       return 0;
   }
   else 
   {
     timer = 1;
     if (TIME[spell][0]==-1)
         timer_zero(({ spell, on_whom }));
     else 
     {
         call_out("timer_zero",TIME[spell][0],({ spell, on_whom }));
         write(TIME[spell][1]);
     }
     return 1; 
   }
}

void timer_zero(string *arr)
{
     if (stringp(arr[1]))
         call_other(SPELLS+arr[0],arr[0],arr[1]);
     else 
         call_other(SPELLS+arr[0],arr[0],arr[1]);
     timer = 0;
} 

void fix()
{
     if (find_call_out("timer_zero"))
     {
         remove_call_out("timer_zero");
         timer = 0;
     }
     this_player()->set_heart_beat(1);
     write("Ok.\n");
}

mixed fcn_help(string arg)
{
    if (!stringp(arg))
         return 0;
    else if (arg == "levels")
    {
   /*
         show_levels();
    */
         return 1;
    } 
    else if (file_size(HELPDIR+arg) > 0) 
    {
         cat(HELPDIR+arg);
         return 1;
    }
  return 0;
}



