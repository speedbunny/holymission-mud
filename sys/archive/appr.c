/* Changed by Ethereal Cashimor: Earmuffs repaired, 260393 */
/* Changed by Ethereal Cashimor: Home() repaired for testcharacters, 290393 */
/* Added by Herp: imp-support, 100493 */
/* Improved wizline efficiency, Moonchild 040793 */
/* Varying workroom file: Moonchild 260793 */
// Added /doc/efun/NEWPARSER to manpath: Moonie 110893

/* mud@mud.edvz.uni-linz.ac.at Herp aka Herbert Rosmanith */

/*-------------------------*
 * Using object oriented   *
 * class concept           *
 *-------------------------*/

inherit "/sys/player";

#include "/sys/levels.h"

#define	CD	"/sys/chatd"
#define APPR	"/sys/bin/appr/"

static int is_not_wizlisten;	/* Listens to wizline 0=NO, 1=YES */
static int noshouts;		/* Listens to shouts */

/* add_chat() will be called from secure/master::valid_exec() */

void add_chat() {
  CD->add_chat(this_object(),-1);	/* add to wiz-line */
  ::add_chat();				/* add to guild-line */
}

static void awiz_commands() {
  add_action("_filter","",1);
  add_action("busy","busy");
  add_action("cat_file", "cat");
  add_action("cd", "cd");
  add_action("do_man","man");
  add_action("earmuffs", "earmuffs");
  add_action("echo_wiz", "wiz");
  add_action("echo_wiz", "wiz/");
  add_action("emote", "emote");
  add_action("finger", "finger");
  add_action("gtell", "gtell");
  add_action("home", "home");
  add_action("list_files", "ls");
  add_action("list_files2", "dir");
  add_action("more", "more");
  add_action("peace","peace");
  add_action("ping", "ping");
  add_action("pwd", "pwd");
  add_action("review", "review");
  add_action("rpeer", "rpeer");
  add_action("rpeers", "rpeers");
  add_action("rwho", "rwho");
  add_action("set_pretitle","pretitle");
  add_action("set_alignment","alignment");
  add_action("setmmin", "setmmin");
  add_action("setmmout", "setmmout");
  add_action("setmin", "setmin");
  add_action("setmout", "setmout");
  add_action("tail_file", "tail");
  add_action("toggle_noshouts","listen");
}

int _filter(string str) {

  string theverb;

  theverb=(string)query_verb();

  if(theverb[0..0]=="'" || member(theverb,'.')!=-1)
    return 0;

  if(file_size(APPR+theverb+".c")>0) 
    if((APPR+theverb)->main(str))
      return 1;

  return ::_filter(str);
}

void logon(string n,int quiet) {
  ::logon(n,quiet);
  awiz_commands();
  CD->add_chat(this_object(),-1);	/* wiz-line */
}

static int busy(string str) {
  int lvl;

  if(!str || str=="on")
    listen_to_shouts_from_level=level;
  else if(str=="off")
    listen_to_shouts_from_level=0;
  else {
    lvl=to_int(str);
    listen_to_shouts_from_level=(lvl<=level?lvl:level);
  }

  printf("Earmuffs at level %d.\n",listen_to_shouts_from_level);

  return 1;
}


static int cat_file(string path) {
  if(!path)
    return 0;
  if(path[0]=='~')
    path="/players/"+name+path[1..<1];
  if(!cat(path))
    write("No such file.\n");
  return 1;
}

int cd(string str) {
  string *parts,ba;
  int fs,i,bs;

  if(!str || str=="")
    str="~";
  if(str[0..0]=="~")
    str="/players/"+name+str[1..<1];
  if(str[0..0]!="/")
    str=current_path+"/"+str;
  if(current_path!="" && str[0..0]!="/")
    str="/"+str;
  str=clean_path(str); 
  if(str) {
    fs=file_size(str);
    if(fs==-1) {
      write(str+": No such file or directory.\n");
      return 1;
    }
    else if(fs!=-2) {
      write(str+": Not a directory.\n");
      return 1;
    }
    else if(!valid_read(str)) {
      write(str+": Access denied!\n");
      return 1;
    }
  } 
  current_path=str[1..<1];
  if(!(this_player()->conf_prompt())[8])
    write("/"+current_path+"\n");
  return 1;
}

int do_man(string str) {
  int i;
  string *manuals; 
  manuals=({
    "/doc","/doc/efun/NEWPARSER","/doc/efun","/doc/lfun",
    "/doc/build","/doc/w","/doc/LPC","/doc/rules",
    "/open","/doc/guild","/doc/magik","/doc/abilities",
    "/doc/helpdir",          // keep this last in order...
  });
  if(!str) {
    write("Topics:\n");
    for(i=0;i<sizeof(manuals);i++)
      write(manuals[i]+" ");
    write("\n");
    return 1;
  }
  str="/"+str;
  i=0;
  while(i<sizeof(manuals)) {
    if(file_size(manuals[i]+str)==-2) {
      write("Sub topics "+manuals[i]+str+":\n");
      ls(manuals[i]+str+"/.");
      return 1;
    }
    if(file_size(manuals[i]+str)>0) {
      write(manuals[i]+str+":\n");
      this_player()->more(manuals[i]+str);
      return 1;
    }
    i++;
  }
  write("Not found.\n");
  return 1;
}

static int earmuffs() {
  printf("Your earmuffs are at level %d.\n",listen_to_shouts_from_level);
  return 1;
}

static int echo_wiz(string str) {
  if(!str) {
    write("On the wiz-line:\n\n");
    return CD->print_line(-1);
  }

  if(str=="on" || str=="off") {
    CD->set_line(this_object(),-1,str=="on"?1:0);
    return 1;
  }

  str=line_format("\n[wiz] "+capitalize(query_real_name())
+(query_verb()=="wiz"?" says: ":" ")+str+"\n",78,5,5," "," "," ","");
  CD->do_chat(-1,str);
  return 1;
}

static int xx_echo_wiz(string str) {
  string msg;
  object *u;
  int i,j;

  if(!str) {
     write("On the wizline:\n\n");
     u=users();
     for (i=0;i<sizeof(u);i++)
	if (u[i]->query_immortal()) {
	   if (u[i]->query_wizline()) write("     ");
	   else write("OFF: ");
	   write(capitalize(u[i]->query_real_name())+"\n"); /* Moonchild - bug
							       "Someone"    */
	}
     return 1;
  }
  if (str=="on") {
     is_not_wizlisten=0;
     return 1;
  }
  if (str=="off") {
     is_not_wizlisten=1;
     return 1;
  }

#if 0
  u=users();
  for (i=0;i<sizeof(u);i++)
      if (u[i]!=this_player() && u[i]->query_immortal() && u[i]->query_earmuff_level() <= level && u[i]->query_wizline()) {
	 msg="[wiz] "+capitalize(query_real_name())+" says: "+str+"\n";
	 j=strlen(msg);
	 msg=line_format(msg,78,5,5," "," "," ","");
	 tell_object(u[i],msg);
  }
  write("Ok.\n");
#endif
  u=filter_array(users(), "wiz_line_filter", this_object());
  msg=line_format("[wiz] " + capitalize(query_real_name())
	+ (query_verb()=="wiz" ? " says: " : " ") + str + "\n",
	78,5,5," "," "," ","");
  for(i=0;i<sizeof(u);i++)
    tell_object(u[i], msg);
  return 1;
}

int wiz_line_filter(object ob) {
  return ob->query_immortal() && ob->query_wizline()
	&& ob->query_earmuff_level()<=level;
}

static int emote(string str) {
  if(!str) {
    write("emote what ?\n");
    return 1;
  }
  say(this_object()->query_name_true()+" "+str+"\n",0,this_object(),
      "Someone "+str+"\n");
  write("Ok.\n");
  return 1;
}

static int finger(string str) {
  string wiz,mud;

  if (!str || sscanf(str,"%s@%s",wiz,mud)!=2) {
    notify_fail("Usage: finger wiz@mud.\n");
    return 0;
  }
  if ((master_object()->send_gfinger_w(mud,wiz))<0) write("Fail.\n");
  else write("Ok.\n");
  return 1;
}

static gtell(str) {
string wiz,mud,msg;

  if (!str || sscanf(str,"%s@%s %s",wiz,mud,msg)!=3) {
    notify_fail("Usage: gtell wiz@mud message.\n");
    return 0;
  }
  if ((master_object()->send_gtell_w(mud,wiz,msg))<0) write("Fail.\n");
  else write("Ok.\n");
  return 1;
}

static home(string who) {
  string str,name_of_friend;
  
  if(who) {
    str="players/"+who+"/workroom";
    if(file_size("/"+str+".c")>0) {
      move_player("home#"+str);
      return 1;
    };
  };

  if(env_var["WORKROOM"])
    str=env_var["WORKROOM"];
  else if(name_of_friend=this_object()->query_testchar()) {
    str="players/"+name_of_friend+"/workroom";
  }
  else if(!this_player()->query_newwiz()) {
    str = "players/uglymouth/guilds/hall";
  }
  else {
    str="players/"+name+"/workroom";
  }
  if(file_size("/"+str+".c")<0) {
    write("You have no workroom.\n");
    return 1;
  }
  move_player("X#"+str);
  return 1;
}

static int list_files(string path) {
  if(!path)
    path="/"+current_path;
  if(path[0]!='/' && path[0]!='~')
    if(current_path=="")
      path="/"+path;
  else
    path="/"+current_path+"/"+path;
  if(path!="/")
    path=path+"/.";
  ls(path);
  return 1;
}

static int list_files2(string path) {
  if(!path)
    path="/"+current_path;
  if(path[0]!='/' && path[0]!='~')
    if(current_path=="")
      path="/"+path;
  else
    path="/"+current_path+"/"+path;
  if(path!="/")
    path=path+"/.";
  dir(path);
  return 1;
}

/* LLORT: resolve the currect path for wizards */
more(string str) {
  if(!str)
    return 0;
  if(str[0]=='~')
    str="/players/"+name+str[1..strlen(str)-1];
  if(str[0]!='/')
    str=current_path+"/"+str;
  if(current_path!="" && str[0]!='/')
    str="/"+str;
  return ::more(str);
}

static int peace() {
  int i;
  object *ob,env;
 
  ob=all_inventory(env=environment());
  for(i=0;i<sizeof(ob);i++)
    if(living(ob[i]) && ob[i]->query_attack()) {
      ob[i]->stop_fight();
      ob[i]->stop_fight();
      ob[i]->stop_hunter(1);
      tell_room(env,ob[i]->query_name()+" suddenly looks very peaceful.\n");
    }
  return 1;
}

static int ping(string str) {
  string ipnum,pp;
  int port_udp;

  if(!str || sscanf(str,"%s %s",ipnum,pp)!=2 || !(port_udp=to_int(pp))) {
    notify_fail("rping <ip> <port>\n");
    return 0;
  }
  master_object()->send_ping_q(ipnum,port_udp);
  write("Ok.\n");
  return 1;
}

static int pwd() {
  write("/"+current_path+"\n");
  return 1;
}

static int review() {
  write("mout:\t"+msgout+
        "\nmin:\t"+msgin+
        "\nmmout:\t"+mmsgout+
        "\nmmin:\t"+mmsgin+"\n");
  return 1;
}

static rpeer(str) {
  mapping imp_hosts;
  mixed *host;
  string s;

  if(str) {
    if(!(host=master_object()->query_imp_hosts()[str])) {
      notify_fail("No such peer.\n");
      return 0;
    }
    printf("Name:      %s\n",str);
    printf("Host:      %s\n",host[4]);
    printf("IP:        %s\n",host[0]);
    if (host[5]==-1) {
	printf("NEVER ACCESSED\n");
	return 1;
    }
    printf("Mud-Port:  %d\n",host[5]);
    printf("imp-Port:  %d\n",host[1]);
    printf("GameDrvr:  %s\n",((s=host[2])?s:"N/A"));
    printf("Mudlib:    %s\n",((s=host[3])?s:"N/A"));
    printf("Last acc:  %s\n",((s=host[6])?s:"N/A"));
    return 1;
  }
}

static int rpeers(string str) {
  mapping imp_hosts;
  mixed *mi,*mv;
  int i;

  if(str)
    return 0;
  if(!(imp_hosts=master_object()->query_imp_hosts())) {
    notify_fail("No known imp-hosts.\n"); 
    return 0;
  }
  mi=m_indices(imp_hosts);
  mv=m_values(imp_hosts);
  for(i=0;i<sizeof(imp_hosts);i++) {
				/* Name|IP */
    printf("%-15s %-15s",mi[i],mv[i][0]);
    if(mv[i][5]==-1)
      printf(" NEVER ACCESSED\n");
    else       /* PR  HS  */
      printf(" %4d (%s)\n",mv[i][5],mv[i][4]);
  }
  return 1;
}

static int rwho(string str) {
  mapping imp_hosts;
  mixed *mi;
  int i;

  if(!(imp_hosts=master_object()->query_imp_hosts())) {
    notify_fail("No known imp-hosts.\n");
    return 0;
  }
  if(str=="*") {
    mi=m_indices(imp_hosts);
    for(i=0;i<sizeof(mi);i++)
      master_object()->send_rwho_q(mi[i]);
    write("Ok.\n");
    return 1;
  }
  else if(imp_hosts[str]) {
    master_object()->send_rwho_q(str);
    write("Ok.\n");
    return 1;
  }
}

static int setmin(string m) {
  msgin=m;
  return 1;
}

static int setmout(string m) {
  msgout=m;
  return 1;
}

static int setmmin(string m) {
  mmsgin=m;
  return 1;
}

static int setmmout(string m) {
  mmsgout=m;
  return 1;
}

static int tail_file(string path) {
  if(!path)
    return 0;
  if(path[0]=='~')
    path="/players/"+name+path[1..<1];
  if(!tail(path))
    return 0;
  return 1;
}

static int toggle_noshouts() {
  if(noshouts)
    write("You start listening to shouts again.\n");
  else
    write("You do not listen to shouts any further.\n");
  noshouts=!noshouts;
  return 1;
}

/* promotion of wizards */

set_level(int l) {
  if(master_object()->set_wiz_level(this_object()->query_real_name(),l)) {
    if(l<L_APPR)
      is_wizard=0;
    else
      is_wizard=1;
    return ::set_level(l);
  }
  else
    illegal_patch("set_level");
}

int show_savings(string arg) {
  object who;

  if(!arg)
    return ::show_savings(arg);

  who=find_living(arg);
  if(who) {
    write("Base-saving-throws of "+who->query_name()+".\n\n");
    write(who->base_savings_info());
  }
  else
    write("No such player/monster online.\n");

  return 1;
}

/* query functions for appr */

int query_wizline() {
  return !is_not_wizlisten;
}

int query_noshouts() {
  return noshouts;
}

int query_earmuff_level() {
  return listen_to_shouts_from_level;
}

int query_is_pk() {
  return 0;
}
