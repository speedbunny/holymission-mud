/* Galadriel: 110893: removed command completion. */
/* Matt AUG-31-94: Reduced max # of commands from 20 to 10 */
#define MAX_CMD  7
#define MAX_HIST 10

#define SEPERATOR	";"


mixed *alias_list,*nick_list;
static string *history_list;
static int alias_flag; 
static int phist;
static int hist_faktor;
static int in_process;
static string last_error;
string sep;

/* Prototype */
string expand(string str,string cverb);
void reset_prompt();

reset_expander(arg) {
  if(arg) return;
  set_modify_command(this_object());
#if 0
  set_prompt("@@refresh_prompt:"+file_name(this_object())+"@@");
#else
  reset_prompt();
#endif
  if (!alias_list) {
      alias_list=allocate(2);
      alias_list[0]=allocate(0);
      alias_list[1]=allocate(0);
  }
  else alias_list=order_alist(alias_list);
	
  if (!nick_list) {
      nick_list=allocate(2);
      nick_list[0]=allocate(0);
      nick_list[1]=allocate(0);
  }
  else nick_list=order_alist(nick_list);
  
  if(!history_list) {
      history_list=allocate(MAX_HIST);
      hist_faktor=0; 
      phist=-1;
  }
  in_process=0;
  if(!sep) sep=SEPERATOR;
}

static clear_all_nick() {
  nick_list=allocate(2);
  nick_list[0]=allocate(0);
  nick_list[1]=allocate(0);
  return 1;
}

static clear_all_alias() {
  alias_list=allocate(2);
  alias_list[0]=allocate(0);
  alias_list[1]=allocate(0);
  return 1;
}

int help_expander() {
    write("Your Expander commands: \n");
    write("alias                    - show the list of current alias\n");
    write("alias command what to do - make \"command\" an alias for the \"what to do\"\n");
    write("  NEW a leading * in a command will prevent it fom being resolved\n");
    write("alias command            - remove alias for \"command\"\n");
    write("cmd1"+sep+"cmd2"+sep+"..."+sep+"cmd" + MAX_CMD
        + "   - does a series of commands (MAX: " + MAX_CMD + ")\n");
    write("seperator <pattern>      - change the seperator-pattern for \n");
    write("                           command sequences\n");
    write("history                  - give a list of previous commands\n");
    write("possible history commands:\n");
    write("%%                       - last command\n");
    write("%nnn                     - command number nnn\n");
    write("%<pattern>               - last command starting with pattern\n");
    write("%% <text>                - last command + text\n");
    write("%nnn <text>              - command number nnn + text\n");
    write("<pattern> <text>         - last command starting with pattern\n");
    write("%%<text>                 - same as above without seperating space\n");
    write("%nnn<text>               - same as above without seperating space\n");
    write("%<pattern>%<text>        - same as above without seperating space\n");
    write("nick                     - shows a list of all nicknames\n");
    write("nick <nickname> <name>   - sets a nickname for name\n");
    write("nick <nickname>          - removes nickname from list\n");
    write("help expander            - this helptext\n");
    
    write("\nType return for next help page (q<return> - quits: ");
    input_to("help_page2");
    return 1;
}

help_page2(string arg)
{
    if (arg == "q" || arg == "Q")
        return 1;

    write("\nThis typing speeder alows you to introduce alias (short commands) or\n");
    write("nicknames (short names for something), which are expanded by the Expander.\n");
    write("\nexamples:\n");
    write("     'alias l look at watch'\n      enables you to write l to look at your watch.\n");
    write("     'smile"+sep+"look"+sep+"laugh'\n      will first make you smile then look and laugh.\n");
    write("     doing '%%' will then repeat this three commands again.\n");
    write("     doing '%say' will repeat your last 'say' commando.\n");
    write("     'nick dra dragon'\n      enables you to write look at dra instead of look at dragon.\n");
    write("\nThis wonderful tool is brought to you by Herp and Llort {=O) \n");
}

init_expander() {
  add_action("process","",1);
  add_action("add_alias","alias");
  add_action("add_nick","nick");
  add_action("history","history");
  add_action("history",":h");
  add_action("clear_all_alias","clear_all_alias");
  add_action("clear_all_nick","clear_all_nick");
  add_action("toggle_debug","toggle_debug");
  add_action("seperator","seperator");
  add_action("substitute",":s");
  add_action("append",":a");
  add_action("last_cmd",":l");
}

string strip(string buff) {
  int i;
  i=0;
  while(buff[i++]==' ');
  return buff[i-1..strlen(buff)-1];
}

greater_fun(p1,p2) { return (p1>p2); }

static add_alias(str) {
  string *cmds;
  string cmd,hstr0,hstr1,hstr2,verb,tmp,tmp2,tmp3; /* Moonchild tmp 281092 */
  int i,l,pos;

  if(!str) {
    write("Your aliases:\n-------------\n");
    hstr0=sort_array(alias_list[0],"greater_fun",this_object());
    for(i=0;i<sizeof(alias_list[0]);i++)
        write(hstr0[i]+" ---> "+assoc(hstr0[i],alias_list)+"\n");
    return 1;
  }
  cmds=explode(str," ");

  if (cmds[0]=="alias") {
     write("It's illegal to have an alias for alias !\n");
     return 1;
  }
  /* Matt SEP-03-94: Don't allow blank aliases...! */
  if(cmds[0] == "") return 0;

  /* alias loeschen */

  if(sizeof(cmds)<2) {
    if((pos=assoc(cmds[0],alias_list[0]))==-1) {
      write("No such alias defined!\n");
      return 1;
    }
    l=sizeof(alias_list[0]);
    if (pos==0) {
	hstr0=alias_list[0][1..l-1];
	hstr1=alias_list[1][1..l-1];
    }
    else if (pos==l-1) {
	hstr0=alias_list[0][0..l-2];
	hstr1=alias_list[1][0..l-2];
    }
    else {
	hstr0=alias_list[0][0..pos-1] + alias_list[0][pos+1..l-1];
	hstr1=alias_list[1][0..pos-1] + alias_list[1][pos+1..l-1];
    }
    alias_list[0]=hstr0;
    alias_list[1]=hstr1;
    alias_list=order_alist(alias_list);
    write("Alias for "+cmds[0]+" removed.\n");
    return 1;
  }

  /* Check for recursive aliases */

  hstr0=explode(str," ");
  verb=hstr0[0];
  hstr0[0]=0;			/* delete the alias pattern */
  hstr0=implode(hstr0," "); 
  if (!expand(hstr0,verb)) {
     write("You must not define your aliases recursively!\n");
     return 1;
  }

  /* Check for use of \ , [ and ] - Moonchild 281092 */

  tmp="." + str + ".";
  if(sscanf(tmp,"%s\\%s",tmp2,tmp3)==2) {
    write("You may not use \"\\\" in an alias.\n");
    return 1;
  }
  if(sscanf(tmp,"%s[%s",tmp2,tmp3)==2) {
    write("You may not use \"[\" in an alias.\n");
    return 1;
  }
  if(sscanf(tmp,"%s]%s",tmp2,tmp3)==2) {
    write("You may not use \"]\" in an alias.\n");
    return 1;
  }

  /* alias einfuegen */
  cmd=cmds[0]; cmds[0]=0; str=implode(cmds," ");
  alias_list=insert_alist(cmd,str,alias_list);
  write("Ok.\n");
  return 1;
}

static add_nick(str) {
  string *cmds;
  string cmd,hstr0,hstr1,tmp,tmp2,tmp3; /* Moonchild 281092 */
  int i,l,pos;

  if(!str) {
    write("Your nicknames:\n---------------\n");
    hstr0=sort_array(nick_list[0],"greater_fun",this_object());
    for(i=0;i<sizeof(nick_list[0]);i++)
        write(hstr0[i]+" ---> "+assoc(hstr0[i],nick_list)+"\n");
    return 1;
  }
  cmds=explode(str," ");

  /* alias loeschen */

  if(sizeof(cmds)<2) {
    if((pos=assoc(cmds[0],nick_list[0]))==-1) {
      write("No such nickname defined!\n");
      return 1;
    }
    l=sizeof(nick_list[0]);
    if (pos==0) {
	hstr0=nick_list[0][1..l-1];
	hstr1=nick_list[1][1..l-1];
    }
    else if (pos==l-1) {
	hstr0=nick_list[0][0..l-2];
	hstr1=nick_list[1][0..l-2];
    }
    else {
	hstr0=nick_list[0][0..pos-1] + nick_list[0][pos+1..l-1];
	hstr1=nick_list[1][0..pos-1] + nick_list[1][pos+1..l-1];
    }
    nick_list[0]=hstr0;
    nick_list[1]=hstr1;
    nick_list=order_alist(nick_list);
    write("Nickname for "+cmds[0]+" removed.\n");
    return 1;
  }

  /* Check for use of \ , [ and ] - Moonchild 281092 */

  tmp="." + str + ".";
  if(sscanf(tmp,"%s\\%s",tmp2,tmp3)==2) {
    write("You may not use \"\\\" in a nickname.\n");
    return 1;
  }
  if(sscanf(tmp,"%s[%s",tmp2,tmp3)==2) {
    write("You may not use \"[\" in a nickname.\n");
    return 1;
  }
  if(sscanf(tmp,"%s]%s",tmp2,tmp3)==2) {
    write("You may not use \"]\" in a nickname.\n");
    return 1;
  }

  /* nick einfuegen */
  cmd=cmds[0]; cmds[0]=0; str=implode(cmds," ");
  nick_list=insert_alist(cmd,str,nick_list);
  write("Ok.\n");
  return 1;
}

static string alias(string buff) {
  string *cmds;

  alias_flag=0;
  cmds=explode(buff," ");
  if (cmds[0]=assoc(cmds[0],alias_list)) {
     buff=implode(cmds," ");
     alias_flag=1;
  }
  return buff;
}

static string nick(string buff) {
  string *cmds;
  int i;

  cmds=explode(buff," ");

  for(i=1;i<sizeof(cmds);i++) 
    cmds[i]=assoc(cmds[i],nick_list,cmds[i]);
  buff=implode(cmds," ");

  return buff;
}

/* Nickname & alias Substitution */

string expand(string buff,string cverb) {
  string *cmds,verb;

  buff=strip(buff);
  verb=explode(buff," ")[0];
  if (verb==cverb && cverb)  return 0;
  if (verb=="alias" || verb=="nick") return buff; /* no nick/alias resolution*/
  cmds=explode(buff,sep);
  if(sizeof(cmds)>1) {
    cmds=map_array(cmds,"expand",this_object(),cverb);
    if (cverb && member_array(0,cmds)!=-1) return 0;
    buff=implode(cmds,sep);
  } else {
    if(buff[0]!='*')
        buff=alias(buff);
    else {
        buff=buff[1..strlen(buff)-1];
        alias_flag=0;
    }
    if (alias_flag) buff=expand(buff,cverb);
    else buff=nick(buff);
  }
  return buff;
}

strcmp(s1,s2) {
  int i,n;

  n=strlen(s1);
  if(strlen(s2)<n) return 0;
  for(i=0;i<n;i++) if(s1[i]!=s2[i]) return 0;
  return 1;
}

int match(string patt) {
  int i;
  for(i=phist;i>=0;i--) if(strcmp(patt,history_list[i])) return i;
  if(hist_faktor) for(i=sizeof(history_list)-1;i>phist;i--) 
    if(strcmp(patt,history_list[i])) return i;
  write("Pattern "+patt+" not found in history.\n");
  return -1;
}

static string get_history_cmd(string str) {
  int id1,id2;
  string sd1,sd2,sd3;
  string *chunk,cmd,arg;

  if(str[0]!=37) return str;
/* possible history commands:
	%% 			last command
	%nnn  			command number nnn
        %<pattern>      	last command starting with pattern
        %% <text>		last command + text
  	%nnn <text>     	command number nnn + text
        <pattern> <text> 	last command starting with pattern
        %%<text> 		same as above without seperating space
        %nnn<text>		same as above without seperating space
   	%<pattern>%<text>	same as above without seperating space
*/
  chunk=explode(str," ");
  cmd=chunk[0]; chunk[0]="";
  if(sizeof(chunk)>1) arg=implode(chunk," ");
  else arg=0;

  if(cmd=="%%") {
    if(arg) return history_list[phist]+arg;
    return history_list[phist];
  } else if(sscanf(cmd,"%%%s",sd1)==1) {
    if(arg) return history_list[phist]+sd1+arg;
    return history_list[phist]+sd1;
  } else if(sscanf(cmd,"%%d%s",id1,sd1)==2) {
    if(id1<0 || id1>hist_faktor*MAX_HIST+phist) {
      write("Number out of bounds.\n");
      return str;
    }
    if(arg) return history_list[id1 % MAX_HIST]+sd1+arg;
    return history_list[id1 % MAX_HIST]+sd1;
  } else if(sscanf(cmd,"%%s%%s",sd1,sd2)==2) {
    if((id1=match(sd1))==-1) return str;
    if(arg) return history_list[id1]+sd2+arg;
    return history_list[id1]+sd2;
  } else if(sscanf(cmd,"%%s",sd1)==1) {
    if((id1=match(sd1))==-1) return str;
    if(arg) return history_list[id1]+arg;
    return history_list[id1];
  } else return str;
}

void refresh_prompt() {
  int *s;
  string pr;

  s=(int *)this_player()->conf_prompt();
  pr=(string)get_prompt_str();
  return((s[3] ?"\n":"")+pr+(s[4] ? (pr!=""?"\n":"")+">> ":"> ")); 
}

void reset_prompt() {
  int *s;
  string pr;
  s=(int *)this_player()->conf_prompt();
  pr=(string)get_prompt_str();
  set_prompt(((s[3] ?"\n":"")+pr+(s[4] ? (pr!=""?"\n":"")+">> ":"> ")));
}

string modify_command(string str) {
  int pos,*s;
  string pr,*words,hlp;

  if (this_object()!=this_interactive())	/* We've been forced */
	return str;

  if (pr=master_object()->modify_command_global(str)) return last_cmd=pr;

  last_cmd=0;
  if (!str) return (string)0;
  if (str[0]==':') 
     return str;             /* leading : marks special history-ed commands */

  str=strip(str);
  str=get_history_cmd(str);
  str=expand(str,0);

/* Galadriel: 110893: call to do_fit removed. Too much cpu usage */

  if(str) last_cmd=str;
  if(!str || strlen(str)<3) return str;   /* not worth being put in history */
  if(in_process) return str;		  /* no doubly entries in history */

  phist++;
  if (phist==MAX_HIST) {
      phist=0;
      hist_faktor++;
  }
  history_list[phist]=str;
  return str;

}

static history() {
  int i;
  string str;

  if(phist==-1) {
    write("No History.\n");
    return 1;
  }
  if(hist_faktor) {
    for(i=phist+1;i<MAX_HIST;i++) 
      write("   "+(i+(hist_faktor-1)*MAX_HIST)+" "+history_list[i]+"\n");
    for(i=0;i<=phist;i++) 
      write("   "+(i+hist_faktor*MAX_HIST)+" "+history_list[i]+"\n");
  } else {
    for(i=0;i<=phist;i++) 
      write("   "+i+" "+history_list[i]+"\n");
  }
  return 1;
}

string *get_history() {
  return history_list;
}

static debug;

toggle_debug() {
  debug=!debug;
  return 1;
}

process(buff) {
  object cmds;
  int i,addh;
  string err_msg;

  if(debug) write(":");
  if(in_process) return;

  if (buff) buff=query_verb()+" "+buff;
  else buff=query_verb();

  if(debug) write(">>"+buff+"<<");

  if(!buff) return 1;
  cmds=explode(buff,sep);
  if(sizeof(cmds)>MAX_CMD) 
      write("Too much commands on line! Ignoring the additionals.\n");

  in_process=1;
  for(i=0;i<sizeof(cmds) && i<MAX_CMD;i++) {
      if(sizeof(cmds)>1) write("doing: "+cmds[i]+".\n");
      last_cmd=cmds[i];
      command(cmds[i],this_player());
  }
  in_process=0;
  if (sizeof(cmds)>1) write("Done.\n");
  return 1;
}

string query_last_error() { return last_error; }

seperator(arg) {
  if(!arg) 
      write("Your actual seperator-pattern is '"+sep+"'.\n");
  else {
      sep=arg; 
      write("Seperator changed to '"+sep+"'.\n");
  }
  return 1;
}

substitute(arg) {
  string term;
  string *hlp,res;
  if(!arg) return 1;
  if(phist==-1) write("No history!\n");
  else {
    term=arg[0..0];
    if(!(hlp=explode(arg,term))) return 1;
    if(sizeof(hlp)!=2) return 1;
    if(!(res=explode(history_list[phist],hlp[0]))) return 1;
    history_list[phist]=implode(res,hlp[1]);
    write("Last command:\n"+history_list[phist]+"\n");
  }
  return 1;
}

static append(arg) {
  if(!arg) return 1;
  if(phist==-1) write("No history!\n");
  else {
    history_list[phist]=arg+history_list[phist];
    write("Last command:\n"+history_list[phist]+"\n");
  }
  return 1;
}

last_cmd() {
  if(phist==-1) write("No history!\n");
  else write(history_list[phist]+"\n");
  return 1;
}

mixed *query_alias()
{
	return alias_list;
}

