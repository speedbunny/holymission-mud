#include "/players/tamina/defs.h"
#include "/obj/adjust.h"

string totalidle;

void reset(int arg) 
{
  if (arg) return;
}

id (string str) 
{
  return str == "glass" || str == "castle" || str == "looking glass";
}

string short()
{
  return "A strange Looking Glass"; 
}

void long()
{
   write("This is Tamina's Looking Glass.\n"+
         "It has been fashioned by the experts of elemental crafting\n"+
         "so that anyone can 'peer' through the Glass, and look in \n"+
         "on the castle, Camelot, which Tamina has created.\n"+
         "There may also be other functions that you might have to\n"+ 
         "discover for your self  ;-)\n"); 
}

int get()
{ 
  return 0;
}

int drop()
{
  return 0;
}

int no_clean_up()
{
  return 1;
}

void init()
{
  add_action("enter",         "enter");
  add_action("help_me",       "tamhelp");
  add_action("who",           "peer");
  add_action("who",           "twho");
  add_action("idle",          "idle");
  add_action("where",         "where");
  add_action("tamina_people", "tpe");
  add_action("seek",          "seek");
}
 
int enter (string str) 
{
  if (!id(str)) return 0;
  
  if (str == "glass" || str == "castle") 
  {
    write("You feel the mesmerizing gaze of the Looking Glass pull\n"+
          "you into Tamina's realm, the wondrous Castle of Camelot!\n");

    MPL("into the Looking Glass#/players/tamina/castle/rooms/draw_bridge");

    return 1;
  }
}

help_me() 
{
  write(
    "The limited abilities of the who currently include:\n"+
    "      peer           -- Will show players currently in your realm.\n"+
    "      twho <wizard>  -- Will show the players in <wizard>'s realm.\n"+
    "      twho mud       -- Will show the players in /room rooms.\n"+
    "      idle           -- Will show all idle times.\n"+
    "      idle <player>  -- Will show idle time of <player>.\n"+
    "      where <player> -- Will show the player's current location.\n"+
    "      tpe            -- Will show a modified `people'.\n"+
    "           Format: ip, Name, Level, WC, AC, Location.\n");
  return 1;
}

who(str) 
{
  object list, myself;
  string name, File, ip_thing, env;
  string file1, file2, file3;
  int i, a, p_on;

  if (str) myself = lower_case(str);
  else 
    myself = TPRN;
  list = users();
  p_on = 0;     
  for(i = 0; i < sizeof(list); i++) 
  {
    env = E(list[i]);
    name = list[i]->RNAME;
    if(env) 
    {  
      if ((creator(env) == myself) ||
	 (!creator(env) && (str == "mud" || str == "0"))) 
      {
	name = CAP(name);
        if (list[i]->SHT == 0) 
          name = "(" + name + ")";
        ip_thing = extract(query_ip_name(list[i]),0,19);
        ip_thing = ip_thing+extract("                     ",0,21-strlen(ip_thing));
        name = name+extract("            ",0,12-strlen(name));
        write(ip_thing+name+"     "+list[i]->LVL+" \t");
        if (query_idle(list[i]) >= 5 * 60) 
          write("Idle  ");
        else 
          write("      ");
        File = file_name(E(list[i]));  
        if (sscanf(File, "%s/%s/%s", file1, file2, file3) == 3) 
        {
  	  if (file1 == "players" && file2 == myself) 
            File = file3;
      }
        write(File);
        write("\n");
        p_on++;
      }
    }
  }
  if (str == "mud" || str =="0")
    write("There are currently "+p_on+" out of "+sizeof(list)+
          " players in /room-files.\n");
    else 
      if (str) 
        write("There are currently "+p_on+" out of "+sizeof(list)+
	      " players in "+CAP(myself)+"'s realm.\n");
      else 
        write("There are currently "+p_on+" out of "+sizeof(list)+
	      " players in your realm.\n");
  return 1;
}

idle(str) 
{
  int idletime;
  object person;
  string name;
  int i;
  object list;
  list = users();

  if (!str) 
  {
    for(i = 0; i < sizeof(list); i++)
    {
      idletime = query_idle(list[i]);
      name = CAP(list[i]->RNAME);
      person = extract("              ",0,14-strlen(name))+name;
      if (idletime) 
      {
        go_figure(idletime);
        write(person+" Idle-> "+totalidle);
        totalidle = 0;
      }
    }
    return 1;
  }
  person = find_player(LOW(str));
  if (!find_living(LOW(str))) 
  {
    write(CAP(str)+" is not on right now.\n");
    return 1;
  }
  if (!person->query_npc() && !query_ip_number(person)) 
  {
    write(CAP(person->RNAME)+" is linkdead.\n");
    return 1;
  }
  idletime = query_idle(person);
  if (!idletime) 
  {
    write(CAP(person->RNAME)+" is not idle.\n");
    return 1;
  }
  go_figure(idletime);
  write(CAP(person->RNAME)+" has been idle for"+totalidle);
  return 1;
}

go_figure(idletime) 
{
  totalidle = " ";
  if ((idletime/86400) > 0) 
  {
    if ((idletime/86400) == 1) totalidle += (idletime/86400)+" day ";
    else totalidle += (idletime/86400)+" days ";
    idletime = idletime - ((idletime/86400)*86400);
  }
  if ((idletime/3600) > 0) 
  {
    if ((idletime/3600) == 1) totalidle += (idletime/3600)+" hour ";
    else totalidle += (idletime/3600)+" hours ";
    idletime = idletime - ((idletime/3600)*3600);
  }
  if ((idletime/60) > 0) 
  {
    if ((idletime/60) == 1) totalidle += (idletime/60)+" minute ";
    else totalidle += (idletime/60)+" minutes ";
    idletime = idletime - ((idletime/60)*60);
  }
  if (idletime > 0) 
  {
    if (idletime == 1) totalidle += idletime+" second";
    else totalidle += idletime+" seconds";
  }
  totalidle += ".\n";
  return 1;
}

where(str) 
{
  object player;
  if (!str) 
  {
    write("You are in "+file_name(E(TP))+".\n");
    return 1;
  }
  player = find_living(LOW(str));
  if (!player) 
  {
    write(CAP(str)+" is not currently on the mud.\n");
    return 1;
  }
  write(CAP(player->RNAME)+" is currently found in "+file_name(E(player))+", which is:\n"+
        (E(player))->SHT+".\n");
  return 1;
}

tamina_people() 
{
  string name, ip, File, level, idle, WC, AC;
  object list;
  string file1, file2;
  int i, Level;
  list = users();

  write(
"\n-=-=-=-=-=-=-=- Holy Mission -=-=- at "+ctime(time())+" -=-=-=-=-=-=-=-\n\n");
  for(i = 0; i < sizeof(list); i++) 
  {
    if (E(list[i])) 
    {
      name = CAP(list[i]->RNAME);
      Level = list[i]->LVL;

      if (Level > 99) 
        level = "(**)";
      else 
        if (Level < 10) 
          level = "("+Level+") ";
        else 
          level = "("+Level+")";

      if (list[i]->query_invis())
        name = ladjust("<"+name+">", 13);
      else
        name = ladjust(name, 13);

      WC = list[i]->query_wc();
      AC = list[i]->query_ac();

      if (WC > 9)
      {
        WC = ladjust(WC, 3);
        if (AC > 9)
          AC = ladjust(AC, 4);
        else
          AC = ladjust(" "+AC, 4);
      }
      else
      {
        WC = ladjust(" "+WC, 3);
        if (AC > 9)
          AC = ladjust(AC, 4);
        else
          AC = ladjust(" "+AC, 4);
      }
      if (query_idle(list[i]) >= 5 * 60) 
        idle = "Idle";
      else 
        idle = "    ";

      ip = ladjust(query_ip_number(list[i]), 15);

      File = file_name(E(list[i]));  
      if (sscanf(File, "%s/%s", file1, file2) == 2) 
      {
	if (file1 == "players") 
          File = "&/"+ladjust(file2, 30);
      }
      write(level+" "+name+WC+" "+AC+idle+" "+ip+" "+File+"\n");
    }
  }
  write(
"            There are currently "+sizeof(list)+" players on the mud.\n");
  write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
  return 1;
}
