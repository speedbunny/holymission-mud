/* Ridge Crystal */

int h;
int tim;

reset(arg)
{
  if(arg)
   return;
}

short()
{
  return "Dark Crystal";
}

long()
{
  write("This " +short()+ " has a shiny black surface. It feels light and\n");
  write("useful in some certain way. Demons Of Chaos LOVE " + short() + ".\n");
}

id(str)
{
  return str == "dark crystal" || str == "Dark Crystal";
}

init()
{
  add_action("use","use");
}

use(str)
{
  if(!str)
   return;
  if (str == "to exit" || str == "for exit")
  {
    if (tim > 0)
    {
     this_player()->move_player("using Dark Crystal#players/kbl/chaos/cho1");
     tim-=1;
     return 1;
    }
    else
     {
      write("Dark Crystal's power has been drained\n");
      return 1;
    }
  }
}

get()
{
  return 1;
}

query_weight()
{
  return 1;
}

query_value()
{
  return 250 * tim;
}

query_name()
{
  return short();
}

query_alias()
{
  return "crystal";
}

query_alt_name()
{
  return "crystal";
}

set_tim(h)
{
  tim = h;
}
