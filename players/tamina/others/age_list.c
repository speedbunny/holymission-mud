#include "/obj/adjust.h"
#include "/players/tamina/defs.h"

object who;
int i, age;
string Age, day, minute, hour, second;

string short() 
{
    return "Tamina's list of the top players' ages";
}

int query_age(object ob)
{
  return ob->query_age();
}

long() 
{
  who = users();
 
  write(
"\n       Members of the Holy Mission at "+ctime(time())+"\n"+
"     -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-  \n\n"+ 
"    NAME        AGE\n"+
"   ------      -----\n\n");

  for(i = 0; i < sizeof(who); i++)
  {
    age = 2 * (query_age(who[i]));
    if (age)
    {    
      go_figure(age);
      write("  "+ladjust(CAP(who[i]->RNAME), 10)+" is "+Age+"old.\n");
    }
  }
  return 1;
}

go_figure(age)
{
  if ((age/86400) > 0)
  {
    if ((age/86400) == 1)
      day = (age/86400)+" day, ";
    else
      day = (age/86400)+" days, ";
    age = age - ((age/86400) * 86400);
  }
  if ((age/3600) > 0)
  {
    if ((age/3600) == 1)
      hour = (age/3600)+" hour, ";
    else
      hour = (age/3600)+" hours, ";
    age = age - ((age/3600) * 3600);
  }
  if ((age/60) > 0)
  {
    if ((age/60) == 1)
      minute = (age/60)+" minute, ";
    else
      minute = (age/60)+" minutes, "; 
    age = age - ((age/60) * 60);
  }
  if (age > 0)
  {
    if (age == 1)
      second = age+" second ";
    else
      second = age+" seconds ";
  }
  Age = " "+ladjust(day, 9) + ladjust(hour, 10) + ladjust(minute, 12) + ladjust(second, 11)+"";
  return 1;
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
