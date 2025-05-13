/* Edited by Ethereal Cashimor, 190393, includes racemotes...
   260393, Cashimor: with echo *sigh */
/* 300794 Whisky put this soul to strict_types */

#include "includes.h"
 
object TP;
string race;
int toggletalk;
 
int get() 
{ 
   return 1; 
}
 
int drop() 
{ 
     return 1; 
}
 
int id(string arg) 
{ 
     return arg=="racesoul"; 
}
 
void long() 
{
  write("It's your racesoul.\n");
}
 
void reset(int flag) 
{
  if(flag == 0) 
  {
     race="norace";
     toggletalk=1;
  }
}
 
void init() 
{
  TP=ENV();
  race=TP->query_race();
  add_action("race_talk","race");
  add_action("race_emote","racem");
}
 
string extra_look() 
{
  return (CAP(TP->REALNAME))+" is a "+TP->GENDER+" "+CAP(race);
}

/* ???? Whisky */ 
help(str) {
  string path;
}

int query_hear() 
{
  return toggletalk; 
}

/* changed by Kelly 930526,plural in topline of race-list */

int race_talk(string arg) 
{
  string msg;
  object *u,s;
  int i, sz;
 
  u=users();
 
  if(!arg) 
  {
    write(CAP(RM->query_plural(race))+" online :\n");
    for(i=0;i<sizeof(u);i++)
      if(u[i]->query_race()==race) {
        s=present("racesoul",u[i]);
        if(s && s->query_hear())
          write("     ");
        else
          write(" OFF ");
        write(CAP(u[i]->REALNAME)+"\n");
      }
      return 1;
  }
  else
    switch(arg) 
    {
      case "off": 
        toggletalk=0;
        write("Race off.\n");
        break;          
      case "on": 
        toggletalk=1;
        write("Race on.\n"); 
        break;
      default:
        for(sz = sizeof(u), i=0;i < sz;i++) 
        {
          s=present("racesoul",u[i]);
          if(u[i]->query_race()==race && u[i]!=TP && s && s->query_hear())
            tell_object(u[i],"<*"+CAP(race)+"*> "+CAP(TP->REALNAME)+
            " says: "+arg+"\n");
        }
        write("<*"+CAP(race)+"*> You say: "+arg+"\n");
    }
  return 1;
}
 

int race_emote(string arg) 
{
  string msg;
  object *u,s;
  int i, sz;
  u=users();
  if(!arg) 
  {
    notify_fail("Racem what?\n");
    return 0;
  }
  for(sz = sizeof(u), i=0; i < sz ;i++) 
  {
    s=present("racesoul",u[i]);
    if(u[i]->query_race()==race && u[i]!=TP && s && s->query_hear())
    tell_object(u[i],"<*"+CAP(race)+"*> "+CAP(TP->REALNAME)+" "+arg+"\n");
  }
  write("<*"+CAP(race)+"*> "+CAP(TP->REALNAME)+" "+arg+"\n");
  return 1;
}
