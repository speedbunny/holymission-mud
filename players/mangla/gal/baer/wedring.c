
// 240794 Muzmuz && Whisky deleted the bug in the remove of the ring 
// 250794 completly debugged in all functions Whisky

// (pat) removed the title-set, do NOT reinstall it !

#include "lw.h"

inherit "obj/armour";

string name1,name2;

void reset(int arg) 
{
  ::reset(arg);
  if(!arg) 
   {
     set_name("ring");
     set_alias("wedding ring");
     set_short("A white gold wedding ring");
     set_type("wedding_ring");
   }   
}

void init() 
{
  ::init();
  add_action("ring", "ring");
  add_action("ring", "ringem");
  add_action("ring", "rem");
  add_action("fiddle", "fiddle");
  add_action("correct", "correct");
  add_action("ringhelp", "ringhelp");
}

void notify(object p,string str) 
{ 
   if (objectp(p) && stringp(str))
   {
     tell_object(p,lw(str)); 
     write(lw(str)); 
   }
}

int ringhelp() 
{
  write("Use \"ring <message>\" to say a message to your spouse.\n"
	+ "Use \"ringem <message>\" or just \"rem\" to send an emote message to them.\n"
	+ "Use \"fiddle ring\" to fiddle with your wedding ring.\n"
	+ "If you want to correct your title, use \"correct title\".\n");
  return 1;
}

int ring(string str) 
{
  object p;

  if(!stringp(str)) 
      return 0;

  if (environment()->ring(str))
      return 1; 

  if (stringp(name1))
     p=find_player(lower_case(name1));

  if(!objectp(p)) 
     return 0;

  if(!interactive(p)) 
  {
    write(name1 + " is linkdead.\n");
    return 1;
  }
  if(query_verb()=="ring") notify(p,"[*] " + name2 + " says: " + str + "\n");
  else notify(p,"[*] " + name2 + " " + str + "\n");
  return 1;
}

int fiddle(string str) 
{
  if(!id(str)) 
      return 0;
  write("You fiddle with your wedding ring.\n");
  say(this_player()->query_name() + " fiddles with "
	+ this_player()->query_possessive() + " wedding ring.\n");
  return 1;
}

void title_set() 
{
  object p;

  p=environment(this_object());
  if(!objectp(p)) 
      return;
  p->set_title("loves " + name1 + " very much");
}

void start() 
{
  object p;

  write("Type \"ringhelp\" for use of your wedding ring.\n");
  wear("wedding ring");
  if (stringp(name1))
      p=find_player(lower_case(name1));
  if(objectp(p)) 
  {
    tell_object(p, "[*] " + name2 + " enters the game.\n");
    write("[*] " + name1 + " is currently logged on.\n");
  }
  if(!this_player()->query_immortal()) title_set();
}

int correct(string str) 
{
  if(str!="title") 
     return 0;
  title_set();
  write("Your title has been corrected.\n");
  return 1;
}

int remove(string arg) 
{
  if (id(arg))
  {
     write("Why would you want to remove your wedding ring?\n");
   return 1;
  }
 return 0;
}

long() 
{
  write(
  "A beautiful white gold wedding ring, in the shape of two roses entertwined.\n"
+ "The inscription reads: " + name1 + " and " + name2 + " - In love forever.\n");
}

void extra_look() 
{ 
    write(name2 + " is very happily married to " + name1 + ".\n"); 
}

int query_weight() 
{ 
     return 0; 
}

void name1(string str) 
{ 
      name1=str; 
}

void name2(string str) 
{ 
      name2=str; 
}

string query_spouse() 
{ 
  if (stringp(name1))
      return name1; 
  return "";
}

string query_auto_load() 
{ 
     return "players/moonchild/wedding/ring:"+name1+" "+name2; 
}

void init_arg(string str) 
{

   sscanf(str,"%s %s",name1,name2);
   call_out("start",2,this_object());
}

void dest() 
{ 
    destruct(this_object()); 
}

int drop(string arg) 
{
  if(query_verb()=="sell") {
    write("Sell your wedding ring? Never!\n");
    return 1;
  }
  else if(query_verb()=="give") {
    write("Give your wedding ring away? Never!\n");
    return 1;
  }
  else if(query_verb()=="quit") {
    object ob;
    if(stringp(name1) && (ob=find_player(lower_case(name1))))
      tell_object(ob, "[*] " + name2 + " leaves you all alone.\n");
  }
  else write("Drop your wedding ring? Never!\n");
  return 1;
}
