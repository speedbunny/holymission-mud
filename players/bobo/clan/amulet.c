
#include "/players/bobo/clan/defines.h"

int chat_status;

void reset(int arg);

int query_chat_off() { return chat_status; }

string query_auto_load() { return "/players/bobo/clan/amulet:"; }

int id(string str) { return (str == "amulet" || str == "clanobj"); }

int query_prevent_shadow() { return 1;}

string short()



{
  if(environment(TO))
  return environment(TO)->query_name() + "'s Golden Amulet";
}

void long()
{
   printf("This is the amulet of the Worshippers of the Sun.  It\n"+
	  "is made of ornate gold and is triangular in shape\n"+
	  "with a big sun in the center.  It reflects the sun\n"+
	  "so that your head is bathed in a halo of light.\n"+
	  "Perhaps you can question it on its abilities.\n");
}

string extra_look()
{

  string rname, guild, mesg;

  rname = environment(this_object())->query_real_name();
  guild = MEMBERS[rname];
  if (!guild || guild == " ")  guild = "Heleolite";

  mesg = sprintf("%s is %s in BOBO's Clan",
         capitalize(PPRON), capitalize(guild));
  return (mesg);
}

int query_value() { return (0); }
int query_weight() { return (0); }
int drop() { return (1); }
int get() { return (1); }
int query_no_steal() { return (1); }

void init(){
  add_action ("actions"); add_xverb("");

}

int actions ( string str )
{
  if ( str == "dest" && TP->query_is_wiz())
  {
    SERVER->remove_clan(RNAME);
    destruct(TO);
    write ("Your amulet implodes.\n");
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
     write("Your Clan line is now on.\n");
    chat_status = 1;
   }
   else 
   {
     write("Your Clan line is now off.\n");
     chat_status = 0;
   }
}

void reset(int arg)
{
  if (!clonep() || arg) return;
  SERVER->add_clan(TO, RNAME);
  chat_status = 1;
}

