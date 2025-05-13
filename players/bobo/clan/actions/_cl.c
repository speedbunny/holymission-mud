
#include "/players/bobo/clan/defines.h"

int _cl(string arg, object *amulet)
{
  string mesg, head;
  if (!arg)
    return printf("Usage: cl <message>\n"),1;

  if (!amulet->query_chat_off())
    return printf("Your Clan line is off, Worshipper.\n"),1;

  if(LVL < 100)  mesg = "("+capitalize(RNAME)+")";
  if(LVL >= 100) mesg = "Someone";
  
  if (LVL <= 100 && TP->short() == 0)
     head = sprintf("[-Worshippe Worshipper %s -] ",mesg);
  else
     head = sprintf("[- Worshipper %s -] " ,NAME);

  arg = head + arg +"\n";
  SERVER->clan_mesg(arg);
  return 1;
}

int query_prevent_shadow() { return 1; }


