inherit "/obj/armour";
#include "/players/saffrin/guild/defs.h"
int guild, level, legend_level, intel, wis;
object thispl;
object location;

object prev_environment(object env){
  if(env)
    location = env;
  return location;
}

int get() 
{
  return 1;
}

int drop(object ob) 
{
  return 1;
}

int id(string str) 
{
  return (str=="magesoul" || str=="guildsoul" || str=="robe");
}

int _cast_(string str) 
{
  string *spellname;
  string newstr;
  int i, j;

  spellname = explode(str," ");
  i = sizeof(spellname);
  if( i > 1 )
    for(j=1;j<i;j++)
      if(j == 1) 
        newstr = spellname[j];
          else 
        newstr = newstr + " " + spellname[j];

  if(file_size(SPELL + spellname[0] + ".c") > 0)
    if ((SPELL + spellname[0])->main(newstr))
      return 1;
    write("You do not seem to know that spell!\n");
  return 1;
  }

int _cast(string str) 
{
  if(find_call_out("_cast_") != -1) 
  {
    write("You are already casting.\n");
    return 1;
    }
  call_out("_cast_",1,str);
  return 1;
  }

int _filter(string str) 
{
  string theverb;
  theverb = (string)query_verb();
  if(theverb[0] == 39) return 0;
  if(theverb == "quit" || theverb == "dest") return 0;
  if(file_size(BIN + theverb + ".c") > 0)
    return((BIN + theverb)->main(str));
  if(theverb == "mage/")
    return((BIN+"mage")->main(str));
  }

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

  set_id("mage robe");
  set_alias("robe");
  set_short("A dark green mage robe");
  set_long("This is the offical robe of the mage guild. Wear it "+
           "with pride.\n");
  set_size(0);
  set_ac(1);
  set_type("guild");
  guild = GM->query_number("mage");
  thispl = ENV();
  if(TP) 
  {
    level = TPL;
    legend_level = TP->query_legend_level();
    intel = TPI;
    wis = TPW;
    TP->set_n_wc(5);
    }
  }

void init() 
{
  ::init();
  add_action("_cast","cast");
  add_action("_filter","",1);

  if (!TP->query_invis())
      CD->do_chat(guild,"[* Mage *] "+CAP(TPRN)+
                        ", a powerful mage, rejoins our ranks.\n");
  }

