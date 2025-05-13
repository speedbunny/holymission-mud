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
/* 121293 Galadriel: dont show invis ppl in print_line */

/* #pragma	strict_types */

#define	GM	"guild/master"

mixed *cusers;		/* a matrix line X users X switch */

/*
    struct line_entry {
	object ob;
	int is_line_listen;
    }
*/

short() { return "The Chat Daemon"; }

long() { printf("%s.\nIt's very noisy here.\n",short()); }

void init() { add_action("dump","dump"); }

int dump() {
int i,j;

    j=sizeof(cusers);	
    printf("Nr of lines: %d\n",j);
    for (i=0;i<j;i++) {
	printf("Line %d(#%d): ",i,sizeof(cusers[i]));
	map_array(cusers[i],"dump_line",this_object(),i);
	printf("\n");
    }
    return 1;
}

private void dump_line(mixed *ob,int i) {

    printf(" %s",ob[0]->query_real_name());
}

void reset(int arg) {
object *u;
int i;

    if (arg) return;	/* only needed at load time */
    set_light(1);	/* oh well ... */

    cusers=allocate(GM->query_nog()+1);
    for (i=0;i<sizeof(cusers);i++) cusers[i]=allocate(0);
    map_array(users(),"init_chat",this_object());
}

private void init_chat(object ob) {
    cusers[ob->query_guild()+1] += ({ ({ ob, 1 }) });
    if (ob->query_immortal() || ob->query_testchar())
	cusers[0] += ({ ({ ob, 1 }) });
}

int print_line(int line) {

    line++;
    if (line>=sizeof(cusers)) return 0;
    map_array(cusers[line],"print_name",this_object(),line);
    return 1;
}

private int find_chat(object ob,int line) {
int i,j;

    /* damn, can't avoid a for loop here */

    j=sizeof(cusers[line]);
    for (i=0;i<j;i++)
	if (cusers[line][i][0]==ob) return i;
    return -1;
}

private void print_name(mixed *ob,int line) {

    if(ob[0] == 0)
      return;
    if ((interactive(ob[0])) &&     /* only when not linkdead */
        !ob[0]->is_invis_for(this_player())) /* Galadriel: and visible */
	printf("%s %s\n",
	    ob[1]?"     ":"OFF: ",
	    line?ob[0]->query_name():
	         capitalize(ob[0]->query_real_name())
    );
}

int add_chat(object ob,int guild) {

    guild++;
    if (find_chat(ob,guild)>=0) return 0;	/* allready there */
    cusers[guild] += ({ ({ ob, 1 }) });		/* add to line */
    return 1;
}

int remove_chat(object ob,int guild) {
int i;

    guild++;
    if ((i=find_chat(ob,guild))==-1) return 0;	/* not there */
    cusers[guild]=del_array(cusers[guild],i);
    return 1;
}

void remove_chat_ob(object ob) {

    remove_chat(ob,ob->query_guild());
    if (ob->query_immortal() || ob->query_testchar())
	remove_chat(ob,-1);
}

int map_chat(int line,string fun,object ob,mixed extra) {
    line++;
    if (line>=sizeof(cusers)) return 0; /* illegal index */
    map_array(cusers[line],fun,ob,extra);
    return 1;
}

int do_chat(int line,string msg) {

    line++;
    if (line>=sizeof(cusers)) return 0;	/* illegal index */

    /*map_array(cusers[line],#'tell_object,msg);*/	/* too bad ... */
    map_array(cusers[line],"tell_chat",this_object(),msg);
    return 1;
}

private int tell_chat(mixed *ob,string msg) {

    if (ob[1] && ob[0]->query_earmuff_level()<this_player()->query_level())
	tell_object(ob[0],msg);
}

int set_line(object ob,int line,int s) {
int i;

    line++;
    if (this_interactive()==ob) {
	if (line>=sizeof(cusers) ||
	    (i=find_chat(ob,line))==-1) return 0;
	cusers[line][i][1]=s;	/* change status */
	return 1;
    }
    return 0;	/* faked call */
}
