#include "/players/waldo/defs.h"
inherit "obj/thing";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    set_name("toy");
    set_short("Waldo's who toy");
    set_long("Waldo's who toy. To use type 'wwho help'\n");
    set_value(0);
    set_weight(0);
    }
  }

init()
{
  ::init();
  AA("_wwho","wwho");
  return 1;
  }

drop()
{
  ME("As you drop the toy, it bounces off the ground and lands");
  ME(" back in your inventory.\n");
  return 1; // CANT DROP IT :-)
  }
query_auto_load()
{
  return "/players/waldo/mywho:";
  }

_wwho(str)
{
int i,j;
object u;
mixed lou;

  if (str=="help")
  {
    ME("Waldo's who help page\n");
    ME("---------------------\n");
    ME("This will allow you to have more informed who command.\n");
    ME("Usage : wwho <option>\n");
    ME("where option is one of the following:\n");
    ME("invis        for those people how are invisible\n");
    ME("<GUILD_NAME>  list of guild players.\n");
    return 1;
    }

  if (!str)
  {
    command("wwho help",TP);
    return 1;
    }

  if (str=="invis")
  {
    u=sort_array(users(),"level_desc",TO);
    ME("\n");

    ME("Invisible people on Holy Mission\n");
    ME("--------------------------------\n");
    for (i=0; i<sizeof(u);i++)
    {
      if (u[i]->QINV)
      {
         ME(CAP(u[i]->QRNAM));
         ME("\t");
         ME(file_name (ENV(u[i]) ) );
         ME("\n");
        }
      }
    return 1;
    }
  if ( (str=="adventurer") || (str=="thief") || (str=="druid")
      ||(str=="fighter") || (str=="jedi") || (str=="mage")
      ||(str=="bard") || (str=="monk") || (str=="ninja")
      ||(str=="summoner") || (str=="vagabond") || (str=="barbarian") )
  {
    j=0;
    ME("\n"+CAP(str)+"'s online\n");
    lou = sort_array(users(),"level_desc",TO);
    for (i=0;i<sizeof(lou);i++)
    {
      if (lou[i]->QGUILD=="guild/master"->query_number(str))
      {
        j++;
        ME("["+lou[i]->QLVL+"] "+CAP(lou[i]->QRNAM)+"\n");
        }
      }
    ME("There are "+j+" "+CAP(str)+"'s online.\n");
    return 1;
    }
  }

int level_desc(object a, object b)
{
  return (a->QLVL<=b->QLVL);
  }
