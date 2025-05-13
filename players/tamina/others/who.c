string totalidle;

short() { 
  return "A pair of Spectacles"; 
}

long(str) {
  write("These are a pair of powerful Specs which have many properties.\n"+
        "To see what they can do, type \"tamhelp\".\n"); }

id(str) {
  return str == "who" || str == "spectacles";
}

reset(arg) {
  if(arg) return;
}

drop() { 
  return 1;
}

get() {
  return 1;
}

query_auto_load() {
  return "/players/tamina/others/who:";
}

init() {
  add_action("help_me","tamhelp");
  add_action("who","twho");
  add_action("idle","idle");
  add_action("where", "where");
  add_action("tamina_people", "tpe");
  if(environment(this_object()) != this_player()) return;
  tell_object(this_player(), "Slartibartfast!\n");
}

help_me() {
  write("The limited abilities of the who currently include:\n"+
	"       twho -- Will show players currently in your realm.\n"+
	"       twho <wizard> -- Will show the players in <wizard>'s realm.\n"+
        "       twho mud -- Will show the players in /room rooms.\n"+
        "       idle -- Will show all idle times.\n"+
	"       idle <player> -- Will show idle time of <player>.\n"+
	"       where <player> -- Will show the player's current location.\n"+
        "       tpe -- Will show a modified `people'.\n"+
        "              Format: ip, name, level, wc, ac, location.\n");
  return 1;
}

who(str) {
  object list, myself;
  string name, File, ip_thing, ENV;
  string spam1, spam2, spam3;
  int i, a, drokk_it;
  if (str) myself = lower_case(str);
  else myself = this_player()->query_real_name();
  list = users();
  drokk_it = 0;     
  for(i = 0; i < sizeof(list); i++) {
    ENV = environment(list[i]);
    name = list[i]->query_real_name();
    if(ENV) {   /* Logon has no environment. Big bug. */
      if((creator(ENV) == myself) ||
	 (!creator(ENV) && (str == "mud" || str == "0"))) {
	name = capitalize(name);
	if (list[i]->short() == 0) name = "(" + name + ")";
	ip_thing = extract(query_ip_name(list[i]),0,19);
	ip_thing=ip_thing+extract("                     ",0,21-strlen(ip_thing));
	name = name+extract("            ",0,12-strlen(name));
	write(ip_thing + name + "     " +
	      list[i]->query_level() + " \t");
	if (query_idle(list[i]) >= 5 * 60) write("Idle  ");
	else write("      ");
	File = file_name(environment(list[i]));  
/* If your system is set up differently, this shouldn't be hard to change. */
	if(sscanf(File, "%s/%s/%s", spam1, spam2, spam3) == 3) {
	  if(spam1 == "players" && spam2 == myself) File = spam3;
	}
	write(File);
	write("\n");
	drokk_it++;
      }
    }
  }
  if(str == "mud" || str =="0")
    write("There are currently "+drokk_it+" out of "+sizeof(list)+
          " players in /room.\n");
  else if(str) write("There are currently "+drokk_it+" out of "+sizeof(list)+
		" players in "+capitalize(myself)+"'s realm.\n");
  else write("There are currently "+drokk_it+" out of "+sizeof(list)+
	     " players in your realm.\n");
  return 1;
}

idle(str) {
  int idletime;
  object person;
  string name;
  int i;
  object list;
  list = users();
  if(!str) {
    for(i = 0; i < sizeof(list); i++) {
      idletime = query_idle(list[i]);
      name = capitalize(list[i]->query_real_name());
      person = extract("              ",0,14-strlen(name))+name;
      if(idletime) {
        go_figure(idletime);
        write(person+" Idle-> "+totalidle);
        totalidle = 0;
      }
    }
    return 1;
  }
  person=find_player(lower_case(str));
  if(!find_living(lower_case(str))) {
    write(capitalize(str)+" is not on right now.\n");
    return 1;
  }
  if(!person->query_npc() && !query_ip_number(person)) {
    write(capitalize(person->query_real_name())+" is linkdead.\n");
    return 1;
  }
  idletime=query_idle(person);
  if(!idletime) {
    write(capitalize(person->query_real_name())+" is not idle.\n");
    return 1;
  }
  go_figure(idletime);
  write(capitalize(person->query_real_name())+" has been idle for"+totalidle);
  return 1;
}

go_figure(idletime) {
  totalidle = " ";
  if ((idletime/86400) > 0) {
    if ((idletime/86400) == 1) totalidle += (idletime/86400)+" day ";
    else totalidle += (idletime/86400)+" days ";
    idletime = idletime - ((idletime/86400)*86400);
  }
  if ((idletime/3600) > 0) {
    if ((idletime/3600) == 1) totalidle += (idletime/3600)+" hour ";
    else totalidle += (idletime/3600)+" hours ";
    idletime = idletime - ((idletime/3600)*3600);
  }
  if ((idletime/60) > 0) {
    if ((idletime/60) == 1) totalidle += (idletime/60)+" minute ";
    else totalidle += (idletime/60)+" minutes ";
    idletime = idletime - ((idletime/60)*60);
  }
  if (idletime > 0) {
    if (idletime == 1) totalidle += idletime+" second";
    else totalidle += idletime+" seconds";
  }
  totalidle += ".\n";
  return 1;
}

where(str) {
  object player;
  if(!str) {
    write("You are in "+file_name(environment(this_player()))+".\n");
    return 1;
  }
  player = find_living(lower_case(str));
  if(!player) {
    write(capitalize(str)+" is not currently on the mud.\n");
    return 1;
  }
  write(capitalize(player->query_real_name())+" is currently found in "+
	file_name(environment(player))+".\n");
  return 1;
}

tamina_people() {
  string name, ip_thing, File, level, idle, WC, AC;
  object list;
  string spam1, spam2;
  int i, Level;
  list = users();
  for(i = 0; i < sizeof(list); i++) {
    if(environment(list[i])) {
      name = capitalize(list[i]->query_real_name());
      Level = list[i]->query_level();
      if(Level > 99) level = "[**]";
    /* Intigers and strings don't mix. */
      else if(Level < 10) level = "["+Level+"] ";
      else level = "["+Level+"]";
      ip_thing = extract(query_ip_name(list[i]),0,19);
      ip_thing=ip_thing+extract("                    ",0,20-strlen(ip_thing));
      name = name+extract("            ",0,12-strlen(name));
      name += level;
      File = file_name(environment(list[i]));  
      if(sscanf(File, "%s/%s", spam1, spam2) == 2) {
	if(spam1 == "players") File = "~"+spam2;
      }
      if(query_idle(list[i]) >= 5 * 60) idle = " I";
      else idle = "  ";
      WC = " ("+list[i]->query_wc()+")";
      AC = "("+list[i]->query_ac()+")";
      WC = WC+extract("   ",0,3-strlen(WC));
      AC = AC+extract("  ",0,2-strlen(AC));
      write(ip_thing+name+idle+WC+AC+File+"\n");
    }
  }
  write("There are currently "+sizeof(list)+" players on the mud.\n");
  return 1;
}
