#if 0
REMOVED: patience

#include "/obj/adjust.h"
#include "/players/tamina/defs.h"

object who;
int i, exp, level;

string short() 
{
    return "Tamina's list of the top players" ;
}

long() 
{
  who = users();

  write(
"\n       Members of the Holy Mission at "+ctime(time())+"             \n"+
"     -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-  \n\n"+ 
"                     Best Fighters:\n\n"+
"  Level   NAME          EXP\n"+
" ------- ------        -----\n\n");
  for(i = 0; i < sizeof(who); i++)
  {
    level = who[i]->LVL;
    exp = who[i]->query_exp();
    if (exp)
    {
      go_figure(exp);
    }  
  }
  return 1;
}

go_figure(exp)
{
  if (!who[i]->query_immortal())
  {
    if (exp > 4000000)
      write("  "+level+"      "+ladjust(CAP(who[i]->RNAME), 10)+" has "+exp+" Exp\n");
    if (exp > 3500000 && exp < 3999999)
      write("  "+level+"      "+ladjust(CAP(who[i]->RNAME), 10)+" has "+exp+" Exp\n");
    if (exp > 3000000 && exp < 3499999)
      write("  "+level+"      "+ladjust(CAP(who[i]->RNAME), 10)+" has "+exp+" Exp\n");
    if (exp > 2500000 && exp < 2999999)
      write("  "+level+"      "+ladjust(CAP(who[i]->RNAME), 10)+" has "+exp+" Exp\n");
    if (exp > 2000000 && exp < 2499999)
      write("  "+level+"      "+ladjust(CAP(who[i]->RNAME), 10)+" has "+exp+" Exp\n");
    if (exp > 1500000 && exp < 1999999)
      write("  "+level+"      "+ladjust(CAP(who[i]->RNAME), 10)+" has "+exp+" Exp\n");
    if (exp > 1250000 && exp < 1499999)
      write("  "+level+"      "+ladjust(CAP(who[i]->RNAME), 10)+" has "+exp+" Exp\n");
    return 1;
  }
}

void init() 
{
    add_action("read", "read");
}

int id(string str) 
{
    return str == "list" || str == "top" || str == "top players" ||
	str == "list of top players" || str == "top list";
}

int read(string str) 
{
    if (!id(str))
      return 0;
    say(TPN+" reads the top list.\n");
    long();
    return 1;
}

int query_weight() { return 1; }
int get()          { return 1; }
int query_value()  { return 50; }

#endif
