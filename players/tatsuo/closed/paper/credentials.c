
#include "/players/tatsuo/closed/paper/defines.h"

int chat_status;

void reset(int arg);

int query_chat_off() { return chat_status; }

string query_auto_load() { return "/players/tatsuo/closed/paper/credentials:"; }

int id(string str) { return (str == "credentials" || str == "paperobj"); }

int query_prevent_shadow() { return 1;}

string short()
{
  if(environment(TO))
  return environment(TO)->query_name()+"'s Coding Credentials";
}

void long()
{
   printf("This really incredibly groovy badge signifies your\n"
         "membership is the Holy Mission Preservation Society.\n");
          "Type 'MS' for all the cool shit you can do!\n");
}

string extra_look()
{
  string rname, guild, mesg;

  rname = environment(this_object())->query_real_name();
  guild = MEMBERS[rname];
  if (!guild || guild == " ")  guild = "Intruding Bastard";

  mesg = sprintf("%s holds the job of %s for Mission Statements.\n",
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
    SERVER->remove_paper(RNAME);
    destruct(TO);
    write ("Your credentials implode.\n");
    return (1);
  }
  else if(str == "quit")
  {
    SERVER->remove_paper(RNAME);
    return 0;
  }

 
  if(str == "refix") return reset(0),1;
  return ((ACTION)->actions(str, TO));
}

void toggle_chat()
{
   if (chat_status == 0)
   {
     write("Your Statments line is now on.\n");
     chat_status = 1;
   }
   else 
   {
     write("Your Statments line is now off.\n");
     chat_status = 0;
   }
}

void reset(int arg)
{
  if (!clonep() || arg) return;
  SERVER->add_paper(TO, RNAME);
  chat_status = 1;
}





