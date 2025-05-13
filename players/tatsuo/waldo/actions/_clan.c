
#include "/players/bobo/clan/defines.h"

int _clan(string arg, object *hachimaka)
{
  string mesg, head;
  if (!arg)
    return printf("Usage: clan <message>\n"),1;

  if (!hachimaka->query_chat_off())
    return printf("Your Clan line is off, dumbass.\n"),1;

  if(LVL < 100)  mesg = "("+capitalize(RNAME)+")";
  if(LVL >= 100) mesg = "Someone";
  
  if (LVL <= 100 && TP->short() == 0)
     head = sprintf("[*Honorable %s-san *] ",mesg); 
  else
     head = sprintf("[*Honorable %s-san *] ",NAME);

  arg = head + arg +"\n";
  SERVER->clan_mesg(arg);
  return 1;
}

int query_prevent_shadow() { return 1; }


