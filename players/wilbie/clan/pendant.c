
#include "/players/wilbie/clan/defines.h"

int chat_status;

void reset(int arg);

int query_chat_off() { return chat_status; }

string query_auto_load() { return "/players/wilbie/clan/pendant:"; }

int id(string str) { return (str == "pendant" || str == "clanobj"); }

int query_prevent_shadow() { return 1;}

string short()
{
  if(environment(TO))
  return environment(TO)->query_name() + "'s Pendant";
}

void long()
{
   printf("This tiny pendant is made of a dark, metallic material.\n"+
          "Engraved in the center is a depiction of the moon.\n"+
          "The pendant is attached to a leaden chain.\n\n"
          "Type 'SH' for a list of powers!\n");
}

string extra_look()
{
  string rname, guild, mesg;

  rname = environment(this_object())->query_real_name();
  guild = MEMBERS[rname];
 if (!guild || guild == " ") guild = "Initiate";

  mesg = sprintf("%s ranks as %s in the Cult of the Dark Moon",
         capitalize(PPRON), capitalize(guild));
  return (mesg);
}

int query_value() { return (0); }
int query_weight() { return (0); }
int drop() { return (1); }
int get() { return (1); }
int query_no_steal() { return (1); }

void init()
{
  add_action ("actions"); add_xverb("");

}

int actions ( string str )
{
  if ( str == "dest" && TP->query_is_wiz())
  {
    SERVER->remove_clan(RNAME);
    destruct(TO);
    write ("Your pendant rots away.\n");
    return (1);
  }
  else if(str == "quit")
  {
    SERVER->remove_clan(RNAME);
    return 0;
  }

 
  if(str == "clanfix") return reset(0),1;
  return ((ACTION)->actions(str, TO));
}

void toggle_chat()
{
   if (chat_status == 0)
   {
     write("The Cult is listening...\n");
     chat_status = 1;
   }
   else 
   {
     write("The Cult will leave you to yourself.\n");
     chat_status = 0;
   }
}

void reset(int arg)
{
  if (!clonep() || arg) return;
  SERVER->add_clan(TO, RNAME);
  chat_status = 1;
}






