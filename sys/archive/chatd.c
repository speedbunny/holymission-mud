/* 161093 HERP: a centralized chat daemon.
   The chat daemon handles only guild and wizard line chat.
   No more chat lines are neccessary, anyway.

   user interface:

	add_chat	...	SYSTEM: called upon login
	remove_chat	...	SYSTEM: called upon guild-change
	remove_chat_ob	...	SYSTEM: called upon logout
	do_chat		...	sends a message to the line
	map_chat	...	similar to map_array
	set_line	...	switch on/off line
	print_line	...	print line users

  The user is, however, the mudlib only ...

  int do_chat(int guild,string msg);
  void map_chat(int guild,string fun,object ob);
  int set_line(object playetrint guild,status ,mixed extrai)
  int print_line(int guild);

  * do_chat sends the message [msg] over over the guild line.

  * map_chat calls function [fun] in object [ob], and passes
    the line-contents and the extra-argument
    basically this is a:

    foreach (index) (users[guild]) ob->fun(users[guild][index],extra)

    where users[guild][index][0] is the player object and
          users[guild][index][1] is the on/off switch


  * set_line switches on/offe extra-arg to that function.

  * print_line prints the guild members and their guild-line switch.

  guild is either a guild number, or -1 for the wizard line.
  a switch value of 0 means, line is off.
  a switch value of 1 means, line is on.

  return values are 0 or 1 for failure or succes, respectively.
*/

// 121293: Galadriel: dont show invis ppl in print_line
// 040295: Llort: wizards should get the Name of invis players
// 310796: Sauron: Added arch channel and more info in channel listing.

/* #pragma	strict_types */

#define	private
#define	GM	"guild/master"

mixed *cusers;		/* a matrix line X users X switch */

/*
    struct line_entry {
	object ob;
	int is_line_listen;
    }
*/

string short() {
  return "The Chat Daemon";
}

void long() {
  printf("%s.\nIt's very noisy here.\n",short());
}

void init() {
  add_action("dump","dump");
}

int dump() {
  int i,j;

  if(!(this_player()->query_archwiz()))
    return 0;

  j=sizeof(cusers);	
  printf("Nr of lines: %d\n",j);
  for(i=0;i<j;i++) {
    printf("Line %d(#%d): ",i,sizeof(cusers[i]));
#ifdef USE_CLOSURE
    map_array(cusers[i],#'dump_line,this_object(),i);
#else
    map_array(cusers[i],"dump_line",this_object(),i);
#endif
    printf("\n");
  }
  return 1;
}

private void dump_line(mixed *ob,int i) {
  if(ob[0])
    printf(" %s",ob[0]->query_real_name());
  else
    printf(" %O",ob);
}

void reset(int arg) {
  object *u;
  int i;

  if(arg)
    return;		/* only needed at load time */
  set_light(1);		/* oh well ... */

  cusers=allocate(GM->query_nog()+3);
  for(i=0;i<sizeof(cusers);i++)
    cusers[i]=allocate(0);
  map_array(users(),"init_chat",this_object());
}

private void init_chat(object ob) {
  cusers[ob->query_guild()+3]+=({({ob,1})});
  if(ob->query_archwiz()) {
    if(ob->query_real_name()=="sauron")
      cusers[0]+=({({ob,1})});
    else
      cusers[0]+=({({ob,0})});
    cusers[1]+=({({ob,1})});
  }
  if(ob->query_immortal() || ob->query_testchar())
    cusers[2]+=({({ob,1})});
}

int print_line(int line) {
  line+=3;
  if(line>=sizeof(cusers))
    return 0;
  map_array(cusers[line],"print_name",this_object(),line);
  return 1;
}

private int find_chat(object ob,int line) {
  int i,j;

// damn, can't avoid a for loop here

  j=sizeof(cusers[line]);
  for(i=0;i<j;i++)
    if(cusers[line][i][0]==ob)
      return i;
  return -1;
}

private void print_name(mixed *ob,int line) {
  string tmp,tmp2;
  int i,j;
  object tp;

  tp=this_player();

  if(ob[0]==0)
    return;
  if((interactive(ob[0])) &&     /* only when not linkdead */
     !ob[0]->is_invis_for(tp)) { /* Galadriel: and visible */

    i=query_idle(ob[0]);
    j=i/3600;
    if(j)
      tmp=j+"h";
    else {
      j=i/60;
      if(j)
        tmp=j+"m";
      else
        tmp=i+"s";
    }

    if(ob[0]->query_afk()) {
      if(tp->query_immortal() || tp->query_testchar())
        tmp2=sprintf(" (afk %s)",tmp);
      else
        tmp2=" (afk)";
    }
    else if(i>120) {
      if(tp->query_immortal() || tp->query_testchar())
        tmp2=sprintf(" (idle %s)",tmp);
      else
        tmp2=" (idle)";
    }
    else if(query_input_pending(ob[0]) || query_editing(ob[0]))
      tmp2=" (input)";
    else
      tmp2="";


    printf("%-5s %s%s\n",
           ob[1]?"":"OFF:",
           capitalize(ob[0]->query_real_name()),tmp2);
  }
}

int add_chat(object ob,int line) {
  line+=3;
  if(find_chat(ob,line)!=-1)
    return 0;	/* already there */
  cusers[line]+=({({ob,1})});		/* add to line */
  return 1;
}

int remove_chat(object ob,int guild) {
  int i;

/*
write("remove_chat("+file_name(ob)+")\n");
*/
  guild+=3;
  if((i=find_chat(ob,guild))==-1)
    return 0;	/* not there */
  cusers[guild]=del_array(cusers[guild],i);
  return 1;
}

void remove_chat_ob(object ob) {
  remove_chat(ob,ob->query_guild());
  if(ob->query_immortal() || ob->query_testchar())
    remove_chat(ob,-1);
  if(ob->query_archwiz()) {
    remove_chat(ob,-2);
    remove_chat(ob,-3);
  }
}

int map_chat(int line,string fun,object ob,mixed extra) {
  line+=3;
  if(line>=sizeof(cusers))
    return 0; /* illegal index */
  map_array(cusers[line],fun,ob,extra);
  return 1;
}

int set_line(object ob,int line,int s) {
  int i;

  line+=3;
  if(this_interactive()==ob) {
    if(line>=sizeof(cusers) || (i=find_chat(ob,line))==-1)
      return 0;
    if(cusers[line][i][1]==s)
      printf("Your %s-line is already %s.\n",query_verb(),s?"on":"off");
    else
      printf("You turn your %s-line %s.\n",query_verb(),s?"on":"off");
    cusers[line][i][1]=s;	/* change status */
    return 1;
  }
  return 0;	/* faked call */
}

private int tell_chat(mixed *ob,string msg) {
  if(ob[1] && ob[0] &&
     ob[0]->query_earmuff_level()<this_player()->query_level())
    tell_object(ob[0],msg);
}

int do_chat(int line,string msg) {
  int c;
  line+=3;
  if(line>=sizeof(cusers))
    return 0;	/* illegal index */

/*map_array(cusers[line],#'tell_object,msg);*/	/* too bad ... */
// If you're using the line, switch it on...
  if(this_player())
    c=find_chat(this_player(),line);
  else
    c=-1;
  if(c>=0 && (line!=0 || this_player()->query_archwiz()) &&
     !cusers[line][c][1])
    set_line(this_player(),(line-3),1);
  map_array(cusers[line],"tell_chat",this_object(),msg);
  return 1;
}
