/* 161093 HERP: a centralized chat daemon.
   150495 LLORT: revamped for multi-lines

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

#define	GM	"guild/master"

mapping lines;         /* key = name_of_line, data = { line_members } */

private string get_line_members( string lin )
{
    int i, cnt;
    object *mem;
    string msg, *hlp;

    msg = "";
    if ( mem=lines[lin]-({0}) )
    {
        hlp = ({ });
        cnt = sizeof(mem);
	for(i=0;i<cnt;i++)
	{ 
            if(!(int)mem[i]->is_invis_for(this_player()))
            {
                hlp += ({ capitalize((string)mem[i]->query_real_name()) });
            };
        };
        if(sizeof(hlp))
            msg+=sprintf("%-=@20.19s\n",hlp);
    };

    return "  Members of line '" + lin + "':\n" + msg +
           "  There are "+sizeof(hlp)+" members on this line.\n\n";
}

varargs int show(string option)
{
    int i, cnt;
    string msg, *lnames;

    if ( !(this_player()->query_archwiz()) ) return( 0 );

    if ( !option ) option="";
    msg="SHOW CHAT '"+option+"'\n";
    switch ( option )
    {
        case "":                   /* info about the lines */
            msg+="The following lines are open at the moment:\n";
            msg+=sprintf("%-=@20.19s\n",m_indices(lines));
            msg+="Number of open lines: "+m_sizeof(lines)+"\n\n";
            break;
        case "members":            /* info about all members of all lines */
            cnt = m_sizeof(lines);
            lnames=m_indices(lines);
            msg+="The following lines are open at the moment:\n";
            for(i=0;i<cnt;i++)
            msg+=get_line_members(lnames[i]);
            msg+="Number of open lines: "+m_sizeof(lines)+"\n";
            break;
        default:                   /* info about members of given line */
            if(!lines[option])
            {
                msg+="No such open line!\n"+
                     "  show chat [ members | 'line-name' ]\n";
                break;
            }
            else
            {
                msg+=get_line_members(option);
                break;
            };
    };

    write(msg);

    return 1;
}

void reset(int arg) {
object *u;
int i;

    if (arg) return;	/* only needed at load time */

    lines=([]);
}

int open_line (string name)
{
    if (lines[name]) return -1;
    lines[name]=({});
    return 1;
}

int close_line (string name, int force)
{    
    object *hlp;
    hlp=lines[name];
    if(!hlp) return 2;                 /* was not even open -> ok */
    if(force || sizeof(hlp) == 0)
    {
        lines=m_delete(lines, name);
        return 1;
    };
    return -1;
}

mixed *compress_array(mixed *a)
{
    mixed *b;
    b = ({ });
    while (sizeof(a)) 
    {
        b += ({ a[0] });
        a -= ({ a[0] });
    };
    return a=b;
}

int add_member (string line, mixed mem)
{
    object *m;
    m=lines[line] - ({ 0 });

    if ( !m ) return -1;
    if(objectp(mem))
    {
        if ( member_array ( mem, m ) != -1 ) return 2; /* already in -> ok */
        lines[line] = m + ({ mem });
    }
    else
    {
        lines[line] = compress_array(m + mem);
    }
    return 1;
}

int remove_member (string line, mixed mem)
{
    object *m;
    m=lines[line];

    if ( !m ) return -1;
    if(objectp(mem))
    {
        if ( member_array ( mem, m ) == -1 ) return 2; /* not in -> ok */
        lines[line] -= ({ mem });
    }
    else 
    {
        lines[line] -= mem;
    };
    return 1;
}

nomask int tell_chat(object ob,string msg)
{
    tell_object(ob,msg);
}

int do_chat (string line, string text)
{
    object *m;
    m=lines[line];

    if ( !m ) return -1;
    m -= ({ 0 });
    map_array(m,"tell_chat",this_object(),text);
    
    return 1;
}

mapping dump () { return lines; }
