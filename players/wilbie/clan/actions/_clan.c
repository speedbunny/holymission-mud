
#include "/players/wilbie/clan/defines.h"

int _clan(string arg, object *pendant)
{
  string mesg, head;
  if (!arg)
    return printf("Usage: clan <message>\n"),1;

  if (!pendant->query_chat_off())
    return printf("Your Cult line is silenced, fool.\n"),1;

  if(LVL < 100)  mesg = "("+capitalize(RNAME)+")";
  if(LVL >= 100) mesg = "Someone";
  
  if (LVL <= 100 && TP->short() == 0)
     head = sprintf("[*Dark %s *] ",mesg);
  else
     head = sprintf("[*Dark %s *] ",NAME);

  arg = head + arg +"\n";
  SERVER->clan_mesg(arg);
  return 1;
}

int query_prevent_shadow() { return 1; }


