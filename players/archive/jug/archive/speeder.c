/*
 *
 * Typing Speeder another utility from JUG (28 March 1992)
 *
 */

#define FILENAME "/players/jug/obj/speeder:"
#define MAX_NICK_NAMES  20
#define MAX_ALIAS       25
#define MAX_HISTORY     20
#define COUNT_UNTIL_REFRESH 40
#define MAX_DO_CMDS     10
#define MAX_FORBID		20

string  owner;
object  list_alias;
object  list_cmd;
object  list_history;
object org_name, nick_name;
object list_forbid;

int noOffnick;
int noOfforbid;
int history_pos;
int history_offset;
int no_history_add;

int refreshing;
int needs_refresh;
int old_init;

object ob;

int add_history(string verb, string str);

reset(arg)
{
    if (arg) return;
	
	if (this_player())
	    owner = capitalize(this_player()->query_real_name());
    
    if(!list_history)
        list_history = allocate(MAX_HISTORY + 1);
    if (!org_name)
        org_name = allocate(MAX_NICK_NAMES + 1);
    if (!nick_name)
        nick_name = allocate(MAX_NICK_NAMES + 1);
    if (!list_forbid)
    	list_forbid = allocate(MAX_FORBID + 1);
}

init_alias_list()
{
    object  obj;
    
    if(!list_alias && this_player()) {
	    obj = first_inventory(this_player());
	    while(obj) {
    	    if(obj->query_quicktyper(0)) {
		        /* retrieve alias from an existing quicktyper */
		        
		        list_alias = obj->query_quicktyper(0);
		        list_cmd = obj->query_quicktyper(1);
		        write("Quicktyper replaced by Typing Speeder, aliases copied !!!\n");
		        destruct(obj);
		        break;
		        }
	        obj = next_inventory(obj);
		    }
	    if(!list_alias) {
    	    list_cmd = 0;
		    }
	    if(!list_cmd) {
	        list_alias = 0;
    		}
	    }
    if(!list_alias) {
	    list_alias = allocate(MAX_ALIAS);
	    }
    if(!list_cmd) {
	    list_cmd = allocate(MAX_ALIAS);
    	}
}

init(arg)
{
    int i;
    object  obj;
    
    if (this_player())
/*		owner = capitalize(this_player()->query_real_name()); */
		owner = this_player()->query_real_name(); 
    init_alias_list();
    
    if(environment(this_object()) == this_player()) {
        add_action("alias", "alias");
        add_action("do_cmd", "do");
        add_action("history", "history");
        add_action("do_refresh", "refresh");
        add_action("help", "help");
        add_action("nick", "nick");
        add_action("forbid", "forbid");
        add_action("allow", "allow");
        add_action("dest", "destruct");
/*        add_action("history_add", "", 1); */
        add_action("do_it", "", 1);
    
    	if (!refreshing && !old_init) {
	        write("Your typing speeder activates itself.\n");
	        old_init = 1;
	    }
        if(!needs_refresh && !refreshing)
            call_out("refresh", 20, this_player());
        }
}

short()
{
    return(owner + "'s typing speeder");
}

long()
{
    write("Typing Speeder utility from JUG, use `help speeder` to get help on it.\n");
}

id (str) 
{
    return ((str == "speeder") || (str == "typing speeder"));
}

query_speeder(arg)
{
    if (arg == 0)
        return list_alias;
    if (arg == 1)
        return list_cmd;
    if (arg == 2)
        return list_history;
    if (arg == 3)
        return history_pos;
    if (arg == 4)
        return history_offset;
    if (arg == 5)
    	return org_name;
    if (arg == 6)
    	return nick_name;
    if (arg == 7)
    	return list_forbid;
    return 0;
}

do_nick(str)
{
    int i, j, n, changed;
    object params;

    if (!str) return 0;
    params = explode(str, " ");
    n = sizeof(params);
    while(i < n) {
        j = 0;
        while (j < noOffnick) {
            if (params[i] == nick_name[j]) {
                params[i] = org_name[j];
                j = noOffnick;
                changed = 1;
                }
            j++;
            }
        i++;
        }
    if (changed)
        return implode(params, " ");
    return str;
}

nick(str)
{
    object params;
    int n, i, found;
    string out;

    if (!str) {
        i = 0;
        write("Nicknames until now:\n");
        while (i < noOffnick) {
            write(extract(nick_name[i] + "         ", 0, 9) + org_name[i] + "\n");
            i++;
            }
        return 1;
        }
    params = explode(str, " ");
    n = sizeof(params);
    if (n == 1) {
        i = 0;
        found = 0;
        while (i < noOffnick) {
            if (params[0] == nick_name[i]) {
                found = 1;
                while (i < noOffnick-1) {
                    org_name[i] = org_name[i+1];
                    nick_name[i] = nick_name[i+1];
                    i++;
                    }
                write("Nickname removed.\n");
                noOffnick--;
                }
            i++;
            }
        if (!found)
        	write(params[0] + " is no nick-name !!!\n");
        return 1;
        }
    if (n != 2) {
        write("USAGE: nick <nickname> <name>\n");
        return 1;
        }
    if (noOffnick >= MAX_NICK_NAMES) {
        write("Maximal number off nicknames exceeded.\n");
        return 1;
        }
    i = 0;
    while (i < noOffnick) {
    	if (params[0] == nick_name[i]) {
    		/* change a nickname */
    		org_name[i] = params[1];
    		write("Nick-name changed.\n");
    		return 1;
    		}
    	i++;
    	}
    	
    nick_name[noOffnick] = params[0];
    org_name[noOffnick] = params[1];
    noOffnick++;
    write("Ok.\n");
    return 1;
}

do_refresh()
{
    write("Refreshing Typing speeder ... ");
    refresh(this_player());
    write("Done.\n");
    return 1;
}

refresh(obj)
{
	refreshing = 1;
    if(first_inventory(obj) != this_object()) {
    	move_object(this_object(), "/players/jug/store");
	    move_object(this_object(), obj);
/*	    write("Typing speeder ...\n"); */
	    }
    needs_refresh = 0;
    refreshing = 0;
    
    return 1;
}

int wrapped;

do_old(string verb, string str)
{
    int pos, i, j, ok;
    string  temp;
    
    if(strlen(verb) <= 1 || verb[0] != '%') {
        return 0;
        }
    
    if(verb == "%%") {  
        if(history_pos == 0) {
            if(!wrapped) {
                write("No history!\n");
                return 1;
                }
            pos = MAX_HISTORY -1;
            }
        else {
            pos = history_pos -1;
            }
    
        if(str && str != "") {
            write(list_history[pos] + " " + str + "\n");
            command(list_history[pos] + " " + str, this_player());
            }
        else {
            write(list_history[pos] + "\n");
            command(list_history[pos], this_player());
            }
        return 1;
        }
    if(sscanf(verb, "%%d%s", pos, temp) >= 1) {
        if(temp == 0) {
            temp = "";
            }
        if(pos < 1 || pos <= history_offset) {
            write("History position " + pos + " is not available!\n");
            return 1;
            }
        if(!wrapped && (pos-1) >= history_pos) {
            write("History position " + pos + " is not available!\n");
            return 1;
            }
        if(pos > MAX_HISTORY + history_offset - 1) {
            write("History position " + pos + " is not available!\n");
            return 1;
            }
        if(!wrapped) {
            if(str && str != "") {
                write(list_history[pos-1] + temp + " " + str + "\n");
                command(list_history[pos-1] + temp + " " + str, this_player());
                }
            else {
                write(list_history[pos-1] + temp + "\n");
                command(list_history[pos-1] + temp, this_player());
                }
            return 1;
            }
        else {
            pos -= history_offset;
            pos += history_pos;
            if(pos >= MAX_HISTORY) {
                pos -= MAX_HISTORY;
                }
            if(str && str != "") {
                write(list_history[pos] + temp + " " + str + "\n");
                command(list_history[pos] + temp + " " + str, this_player());
                }
            else {
                write(list_history[pos] + temp + "\n");
                command(list_history[pos] + temp, this_player());
                }
            return 1;
            }
        }
    if(sscanf(verb, "%%s", temp) == 1) {
        pos = history_pos - 1;
        if (pos < 0)
            pos = 0;
        j = 0;
        ok = 0;
        while(!ok && (j < sizeof(list_history)) && list_history[pos]) {
            i = 0;
            ok = 1;
            while(ok && (i < strlen(temp))) {
                if (temp[i] != list_history[pos][i])
                    ok = 0;
                i++;
            }
            if (!ok)
                if (pos <= 0)
                    pos = sizeof(list_history) - 1;
                else
                    pos--;
            j++;
        }
        if (ok) {
            if(str && str != "") {
                write(list_history[pos] + " " + str + "\n");
                command(list_history[pos] + " " + str, this_player());
                }
            else {
                write(list_history[pos] + "\n");
                command(list_history[pos], this_player());
                }
            return 1;
        }
        write("No previous '"+ temp + "' command found!\n");
        return 1;
    }
    return 0;
}

update_history(pos, com)
{
	int i;
    
    if (pos == history_pos - 1)
		return;   /* first command in history don`t need move */

	if (pos >= history_pos) {
		i = pos;
		while (i < MAX_HISTORY - 1) {
			list_history[i] = list_history[i+1];
			i++;
			}
		list_history[i] = list_history[0];
		pos = 0;
		}
    i = pos;
    while(i < history_pos - 1) {
        list_history[i] = list_history[i+1];
        i++;
        }
    list_history[i] = com;
    return;
}

history()
{
    int i;
    int number;
    
    if(wrapped) {
        number = history_offset + 1;
        i = history_pos + 1;
        while(i < MAX_HISTORY) {
            write("%" + number + "\t" + list_history[i] + "\n");
            i += 1;
            number += 1;
            }
        }
    else
        number = 1;
    i=0;
    while(i < history_pos) {
        write("%" + number + "\t" + list_history[i] + "\n");
        i += 1;
        number += 1;
        }
    return 1;
}

string  last_cmd_added;
string  last_str_added;

int counter;

add_history(verb, str)
{
    string  com;
    int i;
    
    if(!needs_refresh)
        counter += 1;
    
/*    if(counter >= COUNT_UNTIL_REFRESH || verb == "get" || verb == "take") {*/
    if(first_inventory(this_player()) != this_object()) {
        counter = 0;
        if(!needs_refresh) {
            needs_refresh = 1;
            call_out("refresh", 10, this_player());
            }
        }
        
    i = 0;
    while (i < noOfforbid) { /* check for forbidden commands */
    	if (list_forbid[i] == verb)
    		return 0;
    	i++;
    	}
    	
    if(verb == 0 ||  verb =="" || verb == "history")
        return 0;
    
    if((verb == last_cmd_added) && (!str || (str == last_str_added)))
        return 0;
    
    if(no_history_add) {
        no_history_add = 0;
        return 0;
        }
    
    if(strlen(verb) < 3) /* too short to be stored you`re faster typing it */
    	return 0;
    	
    last_cmd_added = verb;
    last_str_added = str;
    
    i = 0;
    while(i < sizeof(list_alias)) {
        if(list_alias[i] == verb) {
            return 0;   /* dont add aliases to the list */
            }
        i += 1;
        }
    
    if(str && str != "")
        com = verb + " " + str;
    else
        com = verb;

    /* check if the command is in the history */
    i = 0;
    while(i < sizeof(list_history) && list_history[i]) {
    	if (list_history[i] == com) {
    		update_history(i,com);
    		return 0;
    		}
    	i++;
    	}
    	
    list_history[history_pos] = com;
    history_pos += 1;
    if(history_pos >= MAX_HISTORY) {
        history_pos = 0;
        wrapped = 1;
        }
    if(wrapped) {
        history_offset += 1;
        }
    return 0;
}

alias(str)
{
    int i;
    string  ab, cmd;
    
    if(!str || str == "") {
        write("The aliases in your typing speeder are:\n");
        i = 0;
        while(i < sizeof(list_alias)) {
            if(list_alias[i]) {
                write(extract(list_alias[i] + "         ", 0, 9) + list_cmd[i] + "\n");
                }
            i += 1;
            }
        return 1;
        }
    if(sscanf(str, "%s %s", ab, cmd) == 2) {
        /* adding a new alias */
        i = 0;
        while(i < sizeof(list_alias)) {
            if(list_alias[i] == ab) {
                /* replace old definition */
                list_cmd[i] = cmd;
                write("Ok.\n");
                return 1;
                }
            i += 1;
            }
        i = 0;
        while(i < sizeof(list_alias)) {
            if(!list_alias[i]) {
                list_alias[i] = ab;
                list_cmd[i] = cmd;
                write("Ok.\n");
                return 1;
                }
            i += 1;
            }
        write("Sorry the typing speeder is full!\n");
        return 1;
        }
    if(sscanf(str, "%s", ab) == 1) {
        /* removing an alias */
        i = 0;
        while(i < sizeof(list_alias)) {
            if(list_alias[i] && list_alias[i] == ab) {
                list_alias[i] = 0;
                list_cmd[i] = 0;
                write("Removed alias for " + ab + ".\n");
                return 1;
                }
            i += 1;
            }
        write(ab + " didn't have an alias!\n");
        return 1;
        }
    write("This can't happen!\n");
    return 0;
}

get()
{
    if(present("speeder", this_player())) {
        return 0;
        }
    return 1;
}

drop()
{
    return 1;   /* can`t drop ! */
}

query_value()
{
    return 0;
}

query_auto_load()
{
    string  temp, nicks, forbids;
    int i, count;
    
    nicks = "";
    forbids = "";
    i = 0;
    while (i < noOffnick) {
        nicks = nicks + org_name[i] + " " + nick_name[i] + ";";
        i++;
        }
    i = 0;
    while (i < noOfforbid) {
        forbids = forbids + list_forbid[i] + ";";
        i++;
        }
    i = 0;
    count = 0;
    while(i < sizeof(list_alias)) {
        if(list_alias[i] && list_cmd[i]) {
            count += 1;
            }
        i += 1;
        }
    temp = FILENAME + nicks + "#" + forbids + "#" + count + ";";
    i = 0;
    while(i < sizeof(list_alias)) {
        if(list_alias[i] && list_cmd[i]) {
            temp += list_alias[i] + " " + list_cmd[i] + ";.X.Z;";
            }
        i += 1;
        }
    
    return temp;    
}

init_arg(arg) {
    int temp;
    int count, place;
    string  ab, cmd;
    string  the_rest;
    int i, n;
    string name, nick, rest;

	if (sscanf(arg, "%s#%s#%s", name, nick, rest) != 3)
		return;
    i = 0;
    rest = arg;
    while ((rest[0] != '#') &&
           (sscanf(rest, "%s %s;%s", name, nick, rest) > 1)) {
        org_name[i] = name;
        nick_name[i] = nick;
        i++;
        }
    noOffnick = i;
    
    sscanf(rest, "#%s", rest);
    i = 0;
    while ((rest[0] != '#') &&
           (sscanf(rest, "%s;%s", name, rest) > 1)) {
        list_forbid[i] = name;
        i++;
        }
    noOfforbid = i;
    
    sscanf(rest, "#%s", arg);
    if(arg) {
        the_rest = "";
        if(sscanf(arg, "%d;%s", count, the_rest) == 2) {
            init_alias_list();
        
            while(the_rest && the_rest != "" && place < sizeof(list_alias)) {
                arg = the_rest;
                if(sscanf(arg, "%s %s;.X.Z;%s", ab, cmd, the_rest) >= 2) {
                    if(ab && ab != "" && cmd && cmd != "") {
                        list_alias[place] = ab;
                        list_cmd[place] = cmd;
                        place += 1;
                        }
                    }
                }
            }
        }
}

do_it(arg)
{
    int i;
    string  verb, str;
    
    verb = query_verb();
    if(!verb) return 0;
    
    str = do_nick(arg);
    if(strlen(verb) > 1 && verb[0] == '%')
        return do_old(verb, str);
    
    i = 0;
    while(i < sizeof(list_alias)) {
        if(list_alias[i] == verb) {
            if(list_cmd[i] == 0) {
                list_alias[i] = 0;
                }
            else {
                if(str && str != "") {
                    /*
                      no_history_add = 1;
                     */
                    command(list_cmd[i] + " " + str, this_player());
                    no_history_add = 0;
                    }
                else {
                    /*
                      no_history_add = 1;
                     */
                    command(list_cmd[i], this_player());
                    no_history_add = 0;
                    }
                add_history(list_cmd[i], str);
                return 1;
                }
            }
        i += 1;
        }
    /* not found */
    
    if (str != arg && verb != "nick") {	/* nickname changed arguments */
    	command(verb + " " + str, this_player());
    	add_history(verb, str);
    	return 1;
    }

    add_history(verb, str);
    return 0;
}


/* do one ore more commands */

do_cmd(str)
{
    object do_cmd_list;
    int n, i;
    string verb, args;
    
    if (!str || str == "") {
        write("USAGE: do cmd1,cmd2,...,cmd" + MAX_DO_CMDS + "\n");
        return 1;
        }
    do_cmd_list = explode(str, ",");
    n = sizeof(do_cmd_list);
    if (n > MAX_DO_CMDS)
        write("More than " + MAX_DO_CMDS + " commands, doing the first " +
              MAX_DO_CMDS + ".\n");
    i = 0;
    while (i < MAX_DO_CMDS && i < n) {
    	if (sscanf(do_cmd_list[i], "do %s", args) < 1) {
	        write("doing: " + do_cmd_list[i] + "\n");
    	    command(do_cmd_list[i], this_player());
    	    }
    	else
    		write("cannot execute do-command in do-command !!!\n");
        i++;
        }
	return 1;    
}


forbid(str)
{
	int i;
	
	if (!str || str == "") {       /* put list on screen */
		write("Forbidden commands for history:\n");
		i = 0;
		while (i < noOfforbid) {
			write("  " + list_forbid[i] + "\n");
			i++;
			}
		return 1;
		}
		
	if (noOfforbid >= MAX_FORBID) {
		write("Maximum number of forbidden commands exceeded !!!\n");
		return 1;
	    }
	i = 0;
	while (i < noOfforbid) {   /* check if it is already in list */
		if (list_forbid[i] == str) {
			write("Command is already in list !!!\n");
			return 1;
			}
		i++;
		}
	list_forbid[noOfforbid] = str;
	noOfforbid++;
	write("Ok.\n");
	return 1;
}

allow(str)
{
	int i, found;
	
	if (!str || str == "")
		return 0;
	
	if (noOfforbid < 1) {
		write("No commands in forbid-list !!!\n");
		return 1;
		}

	i = 0;
	found = 0;
	while (i < noOfforbid) {
		if (list_forbid[i] == str) {
			found = 1;
			while (i < noOfforbid) {
				list_forbid[i] = list_forbid[i+1];
				i++;
				}
			write("Forbidden command removed.\n");
			noOfforbid--;
			}
		i++;
		}
	if (!found)
		write(str + " no command in the forbid-list !!!\n");
	else
		write("Ok.\n");
	return 1;
}

dest(str)
{
	if (!str || !id(str))
		return 0;
	write("I think that was no good idea, argh ...\nTyping speeder destructed.\n");
	destruct(this_object());
	return 1;
}

help(str)
{
    if (!str || !id(str)) return 0;
  
    write("Your Typing Speeder commands:\n");
    write("alias                    - show the list of current alias\n");
    write("alias command what to do - make \"command\" an alias for the \"what to do\"\n");
    write("alias command            - remove alias for \"command\"\n");
    write("do cmd1,cmd2,...,cmd" + MAX_DO_CMDS
        + "   - does a series of commands (MAX: " + MAX_DO_CMDS + ")\n");
    write("history                  - give a list of previous commands\n");
    write("%%                       - repeat last command\n");
    write("%n                       - repeat command number 'n'\n");
    write("%<str>                   - repeat last command beginning with 'str'\n");
    write("nick                     - shows a list of all nicknames\n");
    write("nick <nickname> <name>   - sets a nickname for name\n");
    write("nick <nickname>          - removes nickname from list\n");
    write("forbid                   - list of commands, which have no history\n");
    write("forbid <command>         - forbid <command> to be put in history-list\n");
    write("allow <command>          - allow <command> to be put in history-list\n");
    write("destruct speeder         - destruct`s this object\n");
    write("help speeder             - this helptext\n");
    
    write("\nType return for next help page (q<return> - quits: ");
    input_to("help_page2");
}

help_page2(string arg)
{
    if (arg == "q" || arg == "Q")
        return 1;

    write("\nThis typing speeder alows you to introduce alias (short commands) or\n");
    write("nicknames (short names for something), which are expanded by the Speeder.\n");
    write("\nexamples:    'alias l look at watch'\n     enables you to write l to look at your watch.\n");
    write("     'do smile,look,laugh'\n     will first make you smile then look and laugh.\n");
    write("     doing '%%' will then repeat this three commands again.\n");
    write("     doing '%say' will repeat your last 'say' commando.\n");
    write("     'nick dra dragon'\n     enables you to write look at dra instead of look at dragon.\n");
    write("\nThis object is brought to you by JUG, enjoy it.\n");
    write("(Error: messages that tell you that something is not found,\nis due to the LP-Mud security system and can not be avoided.)\n");
}
