#pragma strict_types
#define CP(x) capitalize(x)
#define TO this_object()
#define TP this_player()
#define TPQL TP->query_level()
#define CTPRN CP((string)TP->query_real_name())
#define TPQG TP->query_guild()
#define TPGN guilds[(int)TPQG]
#define TPQR TP->query_race()

/* Prototypes */

void set_acts();
void filter_it(string type,string str);

int set_up;
string *chans;
string *guilds;

void reset(int arg)
{
  if(!arg)
  {
    set_up = 0;
    chans = ({
          "wiz",
          "wiz/",
          "guild",
          "guild/",
         });
    guilds = ({
               "adventurer",
               "thief",
               "druid",
               "fighter",
               "jedi",
               "mage",
               "bard",
               "monk",
               "ninja",
               "summoner",
               "vagabond",
               "barbarian",
              });
  }
}

int id(string str)
{
  return str == "channel" || str == "chatline";
}

void init()
{
  if(!set_up)
   set_acts();
}

void set_acts()
{
  int i;

  for(i=0;i<sizeof(chans);i++)
   add_action("proc",chans[i]);
  set_up = 1;
}

int proc(string str)
{
  switch(query_verb())
  {
    case "wiz":
         if(!str)
         {
           write("Usage: wiz <string>\n");
           return 1;
         }
         str = "[wiz] "+CTPRN+" says: "+str+"\n";
         filter_it("wizline_filter",str);
         return 1;
    case "wiz/":
         if(!str)
         {
           write("Usage: wiz/ <string>\n");
           return 1;
         }
         str = "[wiz] "+CTPRN+" "+str+"\n";
         filter_it("wizline_filter",str);
         return 1;
    case "guild":
         str = "["+TPGN+"] "+CTPRN+" says: "+str+"\n";
         filter_it("guild_filter",str);
         return 1;
    case "guild/":
         str = "["+TPGN+"] "+CTPRN+" "+str+"\n";
         filter_it("guild_filter",str);
         return 1;
  }
}

void filter_it(string type,string str)
{
  object *u;
  int    i;

  u = filter_array(users(),type,TO);
  for(i=0;i<sizeof(u);i++)
   tell_object(u[i], str);
}

status wizline_filter(object ob) {
  return (status)ob->query_wizline();
}

status guild_filter(object ob) {
  if(ob->query_guild() == TPQG &&
      ob->query_earmuff_level() < TPQL)
     return 1;
    return 0;
}


status get() {
  return 1;
}

status drop() {
  return 1;
}

string query_auto_load()
{
  return "players/kbl/objs/gchan:";
}
