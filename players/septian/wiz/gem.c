/*181093 changed by herp*/

#define	CD	"sys/chatd"

#include "/obj/lw.h"

#define GM "guild/master"
#define TP this_player()
#define TPGLD environment(this_object())->query_guild()
#define CTPRN capitalize(this_player()->query_name())

int sh;
string me;

string query_auto_load()
  {return "players/kawai/personal/gem:"+sh;}

void init_arg(string arg)
  {sscanf(arg,"%d",sh);}

int drop()
  {return 1;}

int id(string str)
  {return str=="gem"||str=="guildemote";}

int get(string str)
  {return 1;}

void init()
  {if(!me)
    {me=CTPRN;}
  add_action("em","gem"); 
  add_action("hide","hide");
  add_action("show","show");
  add_action("give","givegem");}

string short()
  {if(sh)
    return "A Gem";
  return "";}

void long()
  {writelw("The gem is gives you the power to emote to your guild members.  "+
  "use the command: gem <message>\n"+
  "To keep the gem from showing in your inventory, type: hide gem\n"+
  "Or type 'show gem' to have it reappear.\n\n"+
  "You can insert an end-of-line by typing \\n\n");
  if(TP->query_level()>30)
    {write("\nWizards can dispense with: givegem <player>\n");}}

status em(string str)
  {int gd;
  string gn;
gd=TPGLD;
  gn="["+capitalize(GM->query_name(gd))+"] ";
  if(!str)
    {write("Guild Memebers Online:\n");
    write("========================================\n");
    return CD->print_line(gd);}
  if(str=="on"||str=="off")
    return CD->set_line(this_player(),gd,str=="on"?1:0);
  return CD->do_chat(gd,gn+CTPRN+" "+str+"\n");}

status hide(string str)
  {if(!id(str))
    {notify_fail("Hide what?\n");
    return 0;}
  sh=0;
  write("Ok.\n");
  return 1;}

status show(string str)
  {if(!id(str))
    {notify_fail("Show what?\n");
    return 0;}
  sh=1;
  write("Ok.\n");
  return 1;}

status give(string str)
  {object ob,x;
  if(this_player()->query_level()<30)
    {notify_fail("You are too low level!\n");
    return 0;}
  if(!str)
    {notify_fail("Give to who?\n");
    return 0;}
  if(!ob=find_player(str))
    {notify_fail("Can't find player.\n");
    return 0;}
  if(present("guildemote",ob))
    {notify_fail("Player already has one!\n");
    return 0;}
  transfer(x=clone_object("players/kawai/personal/gem"),ob);
  tell_object(ob,"You have been given a Gem by "+CTPRN+".\n");
  x->set_on();
  write("Ok.\n");
  write_file("/players/kawai/log/gems",CTPRN+" gave a gem to "+ob->query_real_name()+" on "+
  ctime(time())+"\n");
  return 1;}

