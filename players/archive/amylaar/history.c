/*
--- history.c ---

this should be considered as an integral part of the nutshell.
keeps a history of the last command given by the player. 
also contains the execution parts of command-sequence evaluation.

do get more information do "help history"

Amylaar's history.c

this file requires the debug.h file


and it also requires LPC version 2.3


*/


/*

#define DEBUG 0
/**/
#include "host_mud.h"
#ifdef GENESIS
#define BannQuicktyper  if (first_inventory(ob)->id("tech_quicktyper")) first_inventory(ob)->switch(0);
#else
#define BannQuicktyper  if (first_inventory(ob)->id("tech_quicktyper")) shell->refresh();
#endif
#define MAXCOST         150

#define VERSION         "0.04"
#define VERSION_DATE    "910325"

#ifdef DEBUG
#include "../../obj/debug.h"
#endif

object  shell,list_history;
string  short_desc;

#define MAX_HISTORY     22

#define SIL_REFRESH if(this_object()!=first_inventory(ob)||oldenv!=environment(ob))\
{\
        BannQuicktyper\
        move_object(this_object(),ob);\
        oldenv=environment(ob);\
}

#define XsyntaxTest {\
        head=extract(str,0,3);\
        if(head=="all ")return VerbAll(verb,str);\
        if(head=="oute")return VerbOuter(verb,str);\
}

int     history_pos;
int     history_offset;
int     no_history_add;

int     command_cost;

query_name() {
        if (shell) return shell->query_name();
}

query_short() {
        return short_desc;
}

/*
  return some info for the interested
 */

query_info()

{
    return "The history for the nutshell";
}

/*

  make it possible to retrieve information from the nutshell
 */
query_history(arg)
{
/* pointers can be used to change history! */
    if (shell->patch_test()) return;
    if(arg == 2) {
        return list_history;
    }
    if(arg == 3) {
        return history_pos;
    }

    if(arg == 4) {
        return history_offset;
    }
    return 0;
}

id(str) 
{
    if(str && (str == "history" || str == short_desc || str == "amylaar_nutshell_history")) {
        return 1;
    }
    return 0;
}

set_name(s) { if ( !shell->patch_test() ) short_desc=s; }

object  ob;     /* used to hold the owner object */
object  oldenv;
    
start(nutshell,player,n)
{    
#ifdef DEBUG
    if(is_debug) {
        write("start(" + player + ")\n");
        write(VERSION + "\n");
        
        write("this_object()="); write(this_object()); write("\n");
        write("environment(this_object())="); write(environment(this_object())); write("\n");
        write("this_player()="); write(this_player()); write("\n");
        write("environment(this_player())="); write(environment(this_player())); write("\n");
    }
    is_debug=DEBUG +0;
#endif
    if (ob) return shell->patch_test();
    shell=nutshell;
    ob=player;
    oldenv=environment(ob);
    if ( n ) short_desc=n;

    else short_desc=ob->query_real_name()+"'s history";
/*
    no_history_add=0;

    command_cost=0;
*/
    list_history = allocate(MAX_HISTORY);

    move_object(this_object(),ob);
}

init(arg)
{
#ifdef DEBUG
    if(is_debug) {
        write("init(" + arg + ")\n");

        write("this_object()="); write(this_object()); write("\n");
        write("environment(this_object())="); write(environment(this_object())); write("\n");
        write("this_player()="); write(this_player()); write("\n");
        write("environment(this_player())="); write(environment(this_player())); write("\n");
    }
#endif
    if ( ob == this_player() ) {
#ifdef DEBUG
        add_action("debug","debug");
#endif
        add_action("history_add","",1);
    }
}


int     wrapped;

fetch_old(str) {

        if ( this_player() != ob && shell->snoop_test() ) return;
        return get_old(str);
}

static get_old(verb, str) {
    int pos;
    int numflag;
    string      comm,temp;
    
#ifdef DEBUG
    if(is_debug) {
        write("verb=" + verb + "\n");
        write("arg=" + str + "\n");
    }
#endif
    if ( str && str != "" )
        verb=verb+" "+str;
#ifdef DEBUG
    if(strlen(verb) <= 1 || verb[0] != '%') {
        write("get_old: return 0\n");
        return 0;
    }
#endif
    if( verb[1] == '%' ) {      
#ifdef DEBUG
        if(is_debug) {
            write("last command\n");
        }
#endif
        pos=-1;
        temp=extract(verb,2);
        numflag=1;
    }else if(sscanf(verb,"%%d%s",pos,temp)>0){
#ifdef DEBUG
        if(is_debug) {
            write("old command\n");
        }

#endif
        if(temp == 0) {
            temp = "";
        }

        numflag=1;
    } else if ( verb[1] == '^' ) {

        if ( !temp ) temp="";
        temp=explode( extract(verb,2)+" "+temp+" ", " " );
        for(pos=0;pos<sizeof(temp);pos++) {

#ifdef DEBUG
            if ( is_debug ) {
                write("%^: checking word '"+temp[pos]+"'\n");
            }
#endif
            if ( strlen(temp[pos]) > 1 && temp[pos][0] == '%' ) {
                if ( !stringp( temp[pos]=get_old(temp[pos]) ) ) return 1;
            }
        }
        return implode(temp," ");
    } else if ( strlen(verb) > 1 ) {
        string pattern;
        int len;

        temp=pattern="";
        for(pos=1;verb[pos];pos++) {
            if ( verb[pos] == 92 ) {pos++;pattern=pattern+extract(verb,pos,pos);}
            else if ( verb[pos] == ':' ) { temp=extract(verb,pos);break; }
            else
            {
                pattern=pattern+extract(verb,pos,pos);
            }
#ifdef DEBUG
        if (is_debug ) {
            write("pattern is now '"+pattern+"'.\n");
        }
#endif
        }
#ifdef DEBUG
        if ( is_debug ) {
            write("searching for pattern '"+pattern+"'\n");
        }
#endif
        len=strlen(pattern);
        for(pos=history_pos-1;pos>=0;pos--) {
#ifdef DEBUG
            write("checking '"+list_history[pos]+"'.\n");
#endif
            if ( extract(list_history[pos],0,len-1) == pattern )
                { pattern=0;break; }
        }
        if ( pattern && wrapped ) for(pos=MAX_HISTORY-1;pos>=0;pos--) {
#ifdef DEBUG
            write("checking '"+list_history[pos]+"'.\n");
#endif
            if ( extract(list_history[pos],0,len-1) == pattern )
                { pattern=0;break; }
        }
        if ( pattern )
        {
            write("get_old: pattern not found\n");
            return 1;
        }
        numflag=0;
    } else {
        write("get_old: unrecognised syntax");

        return 1;
    }
    if (numflag) {

        if(pos<0) {
            if(wrapped) pos+=history_offset+MAX_HISTORY;
            else pos+=history_pos+1;
            if ( no_history_add ) pos--;
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
#ifdef DEBUG
            if(is_debug) {
                write("Not wrapped.\n");
            }
#endif
            pos--;
        } else {
#ifdef DEBUG
            if(is_debug) {
                write("pos=" + pos + "\n");
                write("history_offset=" + history_offset + "\n");
                write("history_pos=" + history_pos + "\n");
            }
#endif
            pos -= history_offset;
#ifdef DEBUG
            if(is_debug) {
                write("pos-history_offset=" + pos + "\n");
            }
#endif
            pos += history_pos;
#ifdef DEBUG
            if(is_debug) {
                write("pos-history_offset+history_pos=" + pos + "\n");
            }
#endif
            if(pos >= MAX_HISTORY) {
                pos -= MAX_HISTORY;
            }
        }
    }

#ifdef DEBUG
    if(is_debug) {
        write("pos-history_offset+history_pos=" + pos + "\n");
    }
#endif
    comm=list_history[pos];
    while( strlen(temp) > 1 && temp[0] == ':' ) {
        string fun;

        if ( temp[1] == '<' ) {

                temp=extract(temp,2);
                break;
        }
        fun=extract(temp,1,1);
        if ( fun=="$" ) fun="dollar";
        if ( fun=="*" ) fun="star";
        comm = call_other(this_object(),"modX"+fun,comm,temp);
        if ( !comm ) {
                write("Bad modifier '"+extract(temp,1,1)+"' !\n");
                return 1;
        }
        if ( pointerp(comm) ) {
                temp=comm[1];
                comm=comm[0];
        } else temp=extract(temp,2);
    }
    return comm+temp;
}

modXdollar(c) {
        c=explode(c+" "," ");
        return c[sizeof(c)-1];
}


modXstar(c) {
        string trash;


        if ( sscanf(c,"%s %s",trash,c) < 2 ) c = "";
        return c;
}


history() {
    int i;
    int number;
    

    if ( shell->snoop_test() ) return 1;
    if(wrapped) {
        number = history_offset + 1;
        i = history_pos + 1;
        while(i < MAX_HISTORY) {
#ifdef DEBUG
            if(is_debug) {
                write(i + " ");
            }
#endif
            write("%" + number + "\t" + list_history[i] + "\n");
            i += 1;
            number += 1;
        }
    } else {
        number = 1;
    }
    i=0;
    while(i < history_pos) {
#ifdef DEBUG
        if(is_debug) {
            write(i + " ");
        }
#endif
        write("%" + number + "\t" + list_history[i] + "\n");
        i += 1;
        number += 1;
    }
    return 1;
}

string  last_cmd_added;
string  last_str_added;

history_add(str) {
    
    string      verb,head;
    int i;
    
#ifdef DEBUG
    if(is_debug) { 

        write("history_add\n");
    }
#endif

    
    SIL_REFRESH
    if ( previous_object() && shell->patch_test() ) return;
    verb = query_verb();
    
/**/
#ifdef DEBUG
    if(is_debug) { 
        write("verb=" + verb + "\n");
        write("str=" + str + "\n");
    }

#endif

    if(verb == 0 ||  verb =="") {
        return 0;
    }
    
    if( ( verb[0]=='%' && strlen(verb)>1 ) ||
        ( str && str[0]=='%' && strlen(str) > 1 && (verb="%^"+verb) ) ){

#ifdef DEBUG
        if(is_debug) {
            write("calling get_old\n");
        }
#endif
        verb=get_old(verb,str);
        if ( !stringp(verb) ) return verb;
        write(verb+"\n");
        shell->exc(verb,this_player());
        return 1; /* one What ? is enough. */

    }
    if(no_history_add)
    {
        no_history_add--;
        if (str) XsyntaxTest
        return 0;

    }

    if(verb == last_cmd_added) {
        if(!str) {
            return 0;
        }
        if(str == last_str_added) {
            XsyntaxTest
            return 0;
        }
    }
    
    last_cmd_added = verb;
    last_str_added = str;

    
    if(str && str != "") {
        list_history[history_pos] = verb + " " + str;
    } else {
        list_history[history_pos] = verb;
    }
    command_cost=0;

    history_pos++;
    if ( history_pos >= MAX_HISTORY )

    {
        history_pos=0;
        wrapped = 1;
    }
    if(wrapped)
    {
        history_offset += 1;
    }
    if (str) XsyntaxTest
    return 0;
}

short()

{
        if (short_desc) return capitalize(short_desc);
}


long()

{
    write("This appendix of the nutshell contains a history of your commands.\n");
    write("Do \"help history\" to get more information about how to use this tool.\n");

    }

drop(){return 1;}

/* do one or more commands */

string  org_cmds;
string  more_cmds,cmd_sq;
int     first_call;
int     paused;

do_cmd(str)
{
    
    if ( previous_object() != shell && shell->patch_test() ) return;
    if(!str || str == "")  {
        if(more_cmds) {

            set_heart_beat(0);
            write("Paused. Use \"resume to continue\"\n");
            paused = 1;
        } else {
            write("usage: do cmd1,cmd2, cmd3,...\n");
        }
        return 1;
    }
    
    if(more_cmds && !paused) {
        write("Busy doing your commands:\n" + more_cmds + "\n");
        return 1;
    }
    if(paused) {
        write("Skipping paused commands:\n" + more_cmds + "\n");
        paused = 0;
    }
    more_cmds = str;
    first_call = 1;
    heart_beat();
    first_call = 0;
    set_heart_beat(1);

    return 1;
}

resume() {
    if ( previous_object() != shell && shell->patch_test() ) return;
    if(paused && ob && more_cmds && more_cmds != "") {
        paused = 0;
        first_call = 1;
        heart_beat();
        first_call = 0;
        set_heart_beat(1);

        return 1;
    }
    write("Nothing to resume.\n");
    return 1;
}


static heart_beat()
{
    string      the_rest;
    string      cmd;
    
    if(ob && more_cmds && more_cmds != "") {
        if(sscanf(more_cmds, "%s,%s", cmd, the_rest) == 2) {
            tell_object(ob, "doing: " + cmd + "\n");
            no_history_add++;
            command(cmd, ob);
            more_cmds = the_rest;
        } else {
            cmd = more_cmds;
            tell_object(ob, "doing: " + cmd + "\n");
            no_history_add++;
            command(cmd, ob);
            more_cmds = 0;
            if(!first_call) {
                set_heart_beat(0);
            }
            tell_object(ob, "Done.\n");
        }
        
    } else {
        more_cmds = 0;
        if(!first_call) {
            set_heart_beat(0);
        }
    }
}

one_command(cmds)
{
    string cmd;

    if ( previous_object() && previous_object() != shell ) return;
    if (cmd=cmds[cmds[0]++])
    {
        if (command_cost++ > MAXCOST)
        {

            tell_object(ob,short()+" : too long evaluation.\n");
            return;
        }
        tell_object(ob,"doing: "+cmd+"\n");
        no_history_add++;
        command(cmd,ob);
        call_out("one_command",0,cmds);
        return;
    }
    tell_object(ob,"done.\n");
    return;
}

enable(i){no_history_add-=i;}

disable_some(i){
  no_history_add+=i;

  if ( ob->query_level() < 20 ) {
    command_cost+=29*i;
    if ( command_cost > MAXCOST ) {
      tell_object(ob,"You are in such a hurry that you blunder.\n");
      call_out("clear_cost",1);
      return 1;

    }
  }

}

clear_cost(){
	command_cost=0;
	no_history_add=0;
}

#ifdef DEBUG
debug(str) {
        if ( str == "history" )
        {
                is_debug=!is_debug;
                write(short_desc+" debugging turned o"+({"ff","n"})[is_debug]+".\n");
                return 1;
        }
}
#endif


static VerbAll(verb,str) {

  string container,thing;

  if (str) { if ( sscanf(str,"all from %s",container) ) {
    string ob_desc,words,ob_id,comm;
    object con,swap_bag,obj,nxt_obj;
    int i;

    if ( (con=present(container,this_player())) ||
        (con=present(container,environment(this_player()))) ||
        ( sscanf(container,"outer %s",container) &&
                (swap_bag=swap_out(container)) &&
                (con=present(container,environment(this_player()))) ) ) {

      for(obj=first_inventory(con);obj;obj=nxt_obj) {
        nxt_obj=next_inventory(obj);
        ob_id=obj->query_name();
        if ( !ob_id || !obj->id(ob_id) ) {

          ob_desc=obj->short();
          if ( ob_desc ) {

            words=explode(ob_desc+" "," ");
            ob_id=lower_case(words[(sizeof(words))-1]);
          } else {
            /* invisible, so continue silently */
            continue;
          }
        }
        if ( !ob_id || !obj->id(ob_id) ) {
          write("Failed to get name of "+lower_case(ob_desc)+"!\n");
          continue;

        }
        for ( i=1; present(ob_id+" "+i,con) != obj;  ) i++;
        if ( i>1 ) comm="get "+ob_id+" "+i+" from "+container;
	else comm="get "+ob_id+" from "+container;
        write(comm+"\n");

        no_history_add++;
        if ( !command(comm,this_player()) ) { write("You failed to "+comm+"\n"); continue; }
        if ( verb != "get" && verb != "take" ) {
          comm=verb+" "+ob_id;
          write(comm+"\n");
          no_history_add++;

          if ( !command(comm,this_player()) ) write("You failed to "+comm+"\n");
        }
      }
      write("All done.\n");

    } else {
      write("No "+container+" here!\n");

    }
    if ( swap_bag ) {
	restore_contents(swap_bag);
    }

    return 1;
    } else if ( sscanf(str,"all my %s",thing) && thing[strlen(thing)-1] == 's' )
        return AllThing(verb,extract(thing,0,strlen(thing)-2),ob,"You have no "+thing);
    else if ( sscanf(str,"all %ss from %s",thing,container) == 2 )
        return AllThing(verb,thing,
            present(container,ob)||present(container,environment(ob)) ||
                tell_object(ob,"No "+container+" here !\n"),
            "There is no "+thing+" in the "+container,container);
 }
}

static AllThing(verb,thing,con,mess,container) {
object  obj,next_obj;
int     i,any;

    if ( !con ) return 1;
    for(obj=first_inventory(con);obj;obj=next_obj) {
        next_obj=next_inventory(obj);
        if ( !obj->id(thing) ) continue;
        any++;
        for ( i=1; !( present(thing+" "+i,con) == obj ); i++ ) 0;
        if ( con != ob ) {
            shell->exc("get "+thing+" "+i+" from "+container);
            if ( environment(obj) != ob ) tell_object(ob,
                "You failed to get the "+thing+" !\n");
            else if ( verb != "get" && verb != "take" )
                shell->exc(verb+" "+thing);
        } else shell->exc(verb+" "+thing+" "+i);
    }
    if ( !any ) tell_object(ob,mess+"\n");
    return 1;
}

static VerbOuter(verb,str) {
  object bag;
  string obj_str,comm;

  if ( sscanf(str,"outer %s",obj_str) ) {
    if ( bag=swap_out(obj_str) ) {
      comm=verb+" "+obj_str;
      no_history_add++;
      if ( !command(comm,this_player()) ) write("You failed to "+comm+"\n");
      restore_contents(bag);
      return 1;
    }
  }
}

static swap_out(thing) {
        object bag,obj;

        bag=clone_object("obj/sing");
        while ( obj=present(thing,this_player()) ) {
                if ( obj->drop() ) {

			restore_contents(bag);
                        write("Nutshell: history: couldn't get "+thing+" from you!\n");
                        break;
                }

                transfer(obj,bag);
		this_player()->add_weight(obj->query_weight());
        }
        return bag;
}

restore_contents(bag) {
    object ob,nob;

    for(ob=first_inventory(bag);ob;ob=nob) {
	nob=next_inventory(bag);
	this_player()->add_weight(-ob->query_weight());
	transfer(ob,this_player());
    }
    destruct(bag);
}

/* --- end of history.c --- */
