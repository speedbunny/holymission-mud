
#include "/players/tatsuo/closed/paper/defines.h"
int _bitch(string arg, object *credentials)
{
  string mesg, head;
  if (!arg)
    return printf("Usage: bitch <message>\n"),1;

  if (!credentials->query_chat_off())
    return printf("Your Enquirer line is off, dumbass.\n"),1;

  if(LVL < 100)  mesg = "("+capitalize(RNAME)+")";
  if(LVL >= 100) mesg = "Someone";
  
  if (LVL <= 100 && TP->short() == 0)
     head = sprintf("[*Enquirer %s*] ",mesg); 
  else
     head = sprintf("[*Enquirer %s*] ",NAME);

 /* arg = "/obj/cutter"->cut(head,arg);  */
  SERVER->paper_mesg(arg);
  return 1;
}

int query_prevent_shadow() { return 1; }


