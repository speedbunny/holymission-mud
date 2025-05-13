/*
--- nutshell.c ---

A quicktyping utility that stores a list of command aliases and
keeps a history of the last command given by the player
and let you put several commands on a single line.

do get more information do "help nutshell"

Amylaar's nutshell.c

this file requires the debug.h file

and it also requires LPC version 2.3


*/

#include "host_mud.h"

#define DEBUG 1

#ifdef GENESIS
#define PREFIX(x) (x)
#endif

#ifdef MISSION
#define PREFIX(x) (x)
#endif
#ifdef TUBMUD
#define PREFIX(x) (x)
query_nutshell() { return 1; }
#endif
#ifdef NANNY
#define PREFIX(x) (x)
#endif
#ifdef NEMESIS
#define PREFIX(x) ("/."+x)
#endif
#ifdef PADERMUD
#define PREFIX(x) ("/."+x)
#endif
#define BannQuicktyper
/*
#define LOGFILE "nutshell.log"
/**/

#define VERSION         "0.07"
#define VERSION_DATE    "910709"
#define NEWS_START      20



inherit "obj/player"; /* It would be nonsense to copy the functions needed */
                     /* Note that we musn't inherit the reset routine     */

#ifdef DEBUG

#include "../../obj/debug.h"
#endif

int     snoop_notify_level,snoop_level,patch_level;
string  short_desc,hist_name;
string  list_ab;
string  list_cmd;
object  hist;

#define MAX_ABBREV      12
#define GROW_NUM        3


#define SIL_REFRESH if(hist!=first_inventory(ob)||oldenv!=environment(ob)){     move_object(hist,ob);\
        oldenv=environment(ob);\
}
#define FORCE_REFRESH move_object(hist,ob)

int refreshing; /* only used for removing alias */

string  logging;

int     can_drop;


object ob; /* used to hold the owner object */

#ifdef BannQuicktyper
refresh(){refreshing=1;move_object(this_object(),ob);refreshing=0;FORCE_REFRESH;}
#endif
query_info()
{
    return "A magic quick typing utility.";
}

/*
  make it possible to retrieve information from the nutshell
 */
query_quicktyper(arg)
{
    if ( patch_test() ) return;
    if(arg == 0) {
        return list_ab;
    } else if(arg == 1) {
        return list_cmd;
    } else if (hist) return hist->query_history(arg);
    return 0;
}

id(str) 
{
    if(str && (str == "nutshell" || str == short_desc || str == "amylaar_nutshell")) {
        return 1;
    }
    return 0;
}

object  oldenv;

    
reset(arg)
{    
#ifdef DEBUG
    if (!arg) is_debug=DEBUG +0;
    if(is_debug) {
        write("reset(" + arg + ")\n");
        write("VERSION "+VERSION + "\n");
        
        write("this_object()="); write(this_object()); write("\n");

        write("environment(this_object())="); write(environment(this_object())); write("\n");
        write("this_player()="); write(this_player()); write("\n");

        write("environment(this_player())="); write(environment(this_player())); write("\n");
    }
#endif
if (arg) return;
#ifdef LOGFILE
    logging=LOGFILE;
#endif
/* herp 
    ob=hist=this_object();
*/
    ob=this_object();
    hist=this_object();
    short_desc="a brand new nutshell";
    enable_commands();
/*
    refreshing=0;
*/
}

init_alias_list() {
    object      obj;
    string      s;
    
#if 1
    if(!list_ab) { if(this_player()==environment(this_object())) {
        set_owner(this_player());
#ifdef DEBUG
        write("init_alias_list with :");write(ob);write("\n");
#endif
        obj = first_inventory(ob);
        while(obj) {
            if(obj->query_quicktyper(0) && !list_ab ) {
                write("retrieving alias from existing "+obj->short()+" ");
                write(obj); write ("\n");
                /* retrieve alias from an existing quicktyper */
                sscanf(obj->query_auto_load(),"%s:%s",s,s);
                init_arg(s);
            }
            if(obj->id("amylaar_nutshell") && obj!=this_object() ) {
                destruct(obj);
                write("Old nutshell destructed\n");
                break;
            }
            obj = next_inventory(obj);

        }
    }
    if( !list_ab || !list_cmd ) {
        list_ab = allocate(MAX_ABBREV);
        list_cmd= allocate(MAX_ABBREV);
    }
    }
#else
    if(!list_ab) {
        list_ab = allocate(MAX_ABBREV);
    }
    if(!list_cmd) {
        list_cmd = allocate(MAX_ABBREV);
    }
#endif
}
xxxx() { save_object("players/amylaar/nutshell"); return 1; }
init(arg)

{
    int i;
    object      obj;
/* herp */
add_action("xxxx","xxxx");    
#ifdef DEBUG
    if(is_debug) {
        write("init(" + arg + ")\n");

        write("this_object()="); write(this_object()); write("\n");
        write("environment(this_object())="); write(environment(this_object())); write("\n");
        write("this_player()="); write(this_player()); write("\n");
        write("environment(this_player())="); write(environment(this_player())); write("\n");

        write("ob=");write(ob);write("\n");
        write("ob->query_real_name()="+ob->query_real_name()+".\n");
    }
#endif
    if( this_player() == ob ) {
        add_action("alias", "alias");
        add_action("do_cmd", "do");
        add_action("sequence", ",",1);
        add_action("history", "history");
        add_action("resume", "resume");
        add_action("help", "help");
        add_action("tell","tell");
        /*
          add_action("drop_object", "drop");
         */
        /* let wizards have some additional information commands */

        level=this_player()->query_level();
        if(level > 19) {
            add_action("log_toggle","log");
            add_action("version", "ver");
#ifdef DEBUG
            add_action("debug_toggle", "debug");     /* declared in debug.h */
#endif
            add_action("rename","rename");
            add_action("loosen","loosen");
            add_action("set","set");
            add_action("wiz_score_list","wizlist");

            add_action("force_player","force");
            add_action("heal","heal");
            add_action("update_object","update");
            add_action("shut_down_game","shutdown");
            add_action("stat","stat");
            add_action("emote","emote");
	    add_action("people","people");
            add_action("trans","trans");
	    add_action("invis","invis");
	    add_action("vis","vis");
            add_action("teleport","goto");
            add_action("show_file_size","file_size");
        }
        if ( level > 20 )
        {
            add_action("echo","echo");
            add_action("echo_all","echoall");
            add_action("home","home");
	    if ( 1&& valid_read(mkpath2("~/castle.c")) ) {
	        add_action("more","more");
		add_action("list_files","ls");
	        add_action("cat_file","cat");
	        add_action("tail_file","tail");
	    } else {
	        add_action("file_cmd","more");
		add_action("list_files2","ls");
	        add_action("file_cmd","cat");
	        add_action("file_cmd","tail");
	    }
            add_action("clone","clone");
            add_action("destruct_local_object","destruct");
            add_action("load","load");
            add_action("cd","cd");
            add_action("nut_cd","nut_cd");
            add_action("nut_pwd","nut_pwd");

            add_action("own_pwd","own_pwd");
        }
        if ( level > 24 || name == "amylaar" )
        {
            add_action("remove_file","rm");
        }
        i = 0;
        while(i < sizeof(list_ab)) {
            if(list_ab[i] && list_ab[i] != "" && list_cmd[i] && list_cmd[i] != "") {
                add_action("do_it", list_ab[i]);
            }
            i += 1;
        }
    } else if ( !this_player()->query_real_name() ) {
        return;
    } else if ( !refreshing && environment() == this_player() ) {
        if ( name != this_player()->query_real_name() ) {
            init_alias_list();
            set_owner(this_player());
        }
        set_owner(this_player());
        write("Nutshell....\n");
        move_object(hist,this_object());
        while(obj=present("amylaar_nutshell_history",ob)) {
                destruct(obj);
                write("Old history destructed\n");
        }
        move_object(this_object(),ob);
        move_object(hist,ob);
    } else if ( ob==this_object() && this_player()->query_real_name() ) {
        short_desc=lower_case(this_player()->query_real_name())+"'s nutshell";
    }
}

#define OUTSIDE(x) x(str){int i;refreshing=1;move_object(this_object(),environment(ob));i=:: x (str);move_object(this_object(),ob);refreshing=0;FORCE_REFRESH;return i;}
OUTSIDE( stat )
OUTSIDE( emote )
people() { return list_peoples(); }

trans(str)
{

    object obj;
    string out;

    if (!str)
        return 0;
    obj = find_living(str);
    if (!obj) {
        write("No such living thing.\n");
        return 1;
    }
    it = str;

    tell_object(obj, "You are magically transfered somewhere.\n");
    out = call_other(obj, "query_mmsgin", 0);
    if (!out)
        out = call_other(obj, "query_name", 0) +
            " arrives in a puff of smoke.\n";
    else
        out = call_other(obj, "query_name", 0) + " " + out + ".\n";
    tell_room(environment(ob),out);
    move_object(obj,environment(ob));
    return 1;

}

invis() {
	is_invis=1;
	cap_name="Someone";
}
vis() {
	is_invis=0;
	cap_name=capitalize(name);
}

OUTSIDE( echo )
destruct_local_object(str) {
	string	desc;

	desc = present(str,ob) || present(str,environment(ob)) ;
	if ( desc ) desc=desc->short();
	::destruct_local_object(str);
	if ( desc ) "players/amylaar/lib"->tell_others(
		desc+" is disintegrated by "+cap_name+".\n",ob);
	return 1;
}

home() {
    ob->move_player("home#players/" + name + "/workroom");
    return 1;

}

nut_cd(str)
{
if ( this_player() != ob )
{
        log_file(name+".rep",this_player()->query_real_name()+" tries a cd on you\n");
        return;

}

get_path();
return ::cd(str);
}

static cd(str)
{

        current_path=0;
        /* return 0 in order to call the cd of the player */
}

get_path() {
        if (!current_path) current_path=ob->query_path();

}


nut_pwd(str){ get_path();return ::pwd(str); }

own_pwd(str) { return ob->pwd(str); }

update_object(str)

{
        get_path();

        return ::update_object(str);
}

load(str)
{
        get_path();
        return ::load(str);
}

int     wrapped;

history() { return hist->history(); }

short()
{
        return capitalize(short_desc);
}

long()
{
    write("This is a typing aid to allow long commands to be replaced with short aliases.\n");
    write("It also contains a history of your commands\n");
    write("Do \"help nutshell\" to get more information about how to use this tool.\n");

    }
log_toggle(str)

{
    if (!id(str)) return 0;

    logging=!logging;
    write(short()+" logging turned o"+({"ff","n"})[logging]+".\n");
    if (logging ) logging=lower_case(this_player()->query_real_name())+".nut";
    return 1;
}


version(str) {
    if(!str || !id(str)) {
        return 0;
    }
    write("Amylaar's nutshell version " + VERSION + " created " + VERSION_DATE + "\n");
    return 1;
}

alias(str) {
    int i;
    string      ab, cmd;
    
    if(!str || str == "") {
        if ( snoop_test() ) return 1;
        write("The aliases in your nutshell are:\n");

        i = 0;
        while(i < sizeof(list_ab)) {
            if(list_ab[i]) {
                write(extract(list_ab[i] + "         ", 0, 9) + list_cmd[i] + "\n");
            }
            i += 1;
        }
        return 1;
    }
    if ( patch_test() ) return 1;
    if(sscanf(str, "%s %s", ab, cmd) == 2) {
        /* adding a new alias */
        i = 0;
        while(i < sizeof(list_ab)) {
            if(list_ab[i] == ab) {

                /* replace old definition */
                list_cmd[i] = cmd;
                write("Ok.\n");
                return 1;
            }
            i += 1;
        }
        i = 0;
        if ( ab=="alias" ) { write("This would be too dangerous.\n"); return 1; }

        while(i < sizeof(list_ab)) {
            if(!list_ab[i]) {
                list_ab[i] = ab;

                list_cmd[i] = cmd;
                add_action("do_it", list_ab[i]);
                FORCE_REFRESH;
                write("Ok.\n");
                return 1;
            }
            i += 1;
        }

        write("Your nutshell bulges as you add another alias\n");
        i=sizeof(list_ab)+GROW_NUM;
        ab =allocate(i);
        cmd=allocate(i);

        for(i=0;i<sizeof(list_ab);i++) {
            ab[i]=list_ab[i];
            cmd[i]=list_cmd[i];
        }
        list_ab =ab;
        list_cmd=cmd;
        return alias(str);
    }
    if(sscanf(str, "%s", ab) == 1) {
        /* removing an alias */

        i = 0;

        while(i < sizeof(list_ab)) {
            if(list_ab[i] && list_ab[i] == ab) {
                list_ab[i] = 0;
                list_cmd[i] = 0;
                write("Removed alias for " + ab + ".\n");
                refreshing=1;
                move_object(this_object(),ob);
                refreshing=0;
                FORCE_REFRESH;
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

cathelp(s,l){cat(PREFIX("/"+query_cloned_from()+".help"),s,l);}

help(str) {
    if (str) str=lower_case(str);
    if ( id(str) )
    {
        cathelp(1,15);
        if ( level > 19 ) 
write("help nutshell wizcommands - every wizard should read this\n");
        cathelp(16,8);
    } else if ( str == "history" ) cathelp(24,22);
    else if ( str == "xsyntax" ) cathelp(46,12);

    else if ( str == "nutshell wizcommands" && level > 19 ) {
#ifdef DEBUG
        cathelp(58,2);
#endif

        cathelp(60,24);
    }
    else return 0;
    return 1;

}

get()

{
#if 0
    if(contains("amylaars_nutshell", this_player())) {
        return 0;
    }
#endif

    return 1;
}

drop()
{
    if ( !can_drop ) return 1;
    if ( hist != this_object() ) destruct(hist);
    hist=ob=this_object();
}


/* no value ==> no query_value needed. */

query_cloned_from() {
	string	str;

	sscanf(file_name(this_object()),"%s#",str);

	return str;
}

query_auto_load()
{
    string      temp;
    int i, count;
    
    count = 0;
    temp = ";" ;
    for(i=0;i < sizeof(list_ab); i++) {
        if(list_ab[i] && list_cmd[i]) {
            temp += list_ab[i] + " " + list_cmd[i] + ";.X.Z;";
            count++;
        }
    }
    return query_cloned_from()+":VERSION"+VERSION+"^"+NEWS_START+"^"
        +"SET"+patch_level+"^"+snoop_level+"^"+snoop_notify_level+"^"
        +"NAME"+short_desc+"^X^"+hist->query_short()+"^X^"
        + count + temp ;
}

do_it(str)
{

    int i;
    string      verb;
    
#ifdef DEBUG
    if(is_debug) {
        write("query_verb=" + query_verb() + "\n");

        write("str=" + str + "\n");

    }
#endif
    verb = query_verb();
    if(verb == 0) return 0;
    
    i = 0;
    while(i < sizeof(list_ab)) {
        if(list_ab[i] == verb) {
            if(list_cmd[i] == 0) {
                list_ab[i] = 0;
            } else {
                if ( (verb=list_cmd[i])[0] == '%' )
                        command(hist->fetch_old(verb),(hist->enable(-1),ob));

                else {

                    hist->enable(-1);
#ifdef DEBUG
                    if(is_debug) {
                        if ( !str ) str ="";
                        write(verb + " " + str + "\n");
                    }
#endif
                    if (str) command(verb + " " + str, ob);
                    else command(verb,ob);
                }
                return 1;
            }
        }
        i += 1;
    }

    /* not found */
    write("spurious alias\n");
    return 0;
}

init_arg(arg) {
    int temp;
    int count, place;

    string      ab, cmd;
    string      the_rest;

#ifdef DEBUG
    if(is_debug) write("init_arg(" + arg + ")\n");
#endif
    
    if(arg) {
        the_rest = "";
        if( sscanf(arg,"VERSION%s^%d^%s",temp,count,the_rest) == 3 ) {
	    arg=the_rest;
	    if ( temp != VERSION ) write(
 "The nutshell has been updated since you last logged in.\n"
+"Your last version was " + temp + ".\n");
	} else {
	    temp=0;
	    count=1;
	    write("Welcome to Amylaar's nutshell.\n");
	}
        if( sscanf(arg,"SET%d^%d^%d^%s",patch_level,snoop_level,snoop_notify_level,the_rest) == 4 ) arg = the_rest;
            if ( temp != VERSION ) {
                write(
 "The current version is " + VERSION + " created " + VERSION_DATE +".\n"
                );
                cat(PREFIX("/"+query_cloned_from()+".news"),count,40);
            }
        if( sscanf(arg,"NAME%s^X^%s^X^%s",short_desc,hist_name,the_rest) == 3) {
            arg=the_rest;
        }
        if( sscanf(arg, "%d;%s", count, the_rest) == 2 ) {
#ifdef DEBUG
            if(is_debug) write("count=" + count + "\n");
#endif
            if ( !list_ab || sizeof(list_ab) < count ) {
                list_ab =allocate(count+GROW_NUM);
                list_cmd=allocate(count+GROW_NUM);
            }
            while(the_rest && the_rest != "" && place < sizeof(list_ab))
            {
                arg = the_rest;
                if(sscanf(arg, "%s %s;.X.Z;%s", ab, cmd, the_rest) >= 2) {
                    if(ab && ab != "" && cmd && cmd != "") {
                        list_ab[place] = ab;

                        list_cmd[place] = cmd;

                        place += 1;
                    }
                }
            }
        }
    }

}

catch_tell(str)
{
    SIL_REFRESH
    if ( logging )
        log_file(logging,ctime(time())+"\n"+str);
}

sequence(str)
{

    string cmd_sq;

    if (!str) str="";
    cmd_sq=explode("_"+query_verb()+" "+str+",_,",",");

    cmd_sq[0]=1;
    cmd_sq[sizeof(cmd_sq)-1]=0;
    if ( cmd_sq[1] == "" )
{
    string cmd;
    int i;

    if ( hist->disable_some(sizeof(cmd_sq)-3) ) return 1;
    for(i=2;cmd=cmd_sq[i++];) {
        write("@"+cmd+"\n");
        command(cmd,ob);
    }
    write("done\n");

}
    else
        hist->one_command(cmd_sq);
    return 1;

}

loosen(str)
{
    if ( !id(str) ) return 0;
    ob=this_object();
    can_drop=1;
    write("You can now give away "+short()+".\n");

    return 1;
}

do_cmd(str){ return hist->do_cmd(str); }
resume(){ return hist->resume(); }

mkpath(str) {
    if (!str) return;
    if ( str[0]=='/' ) return str;
    get_path();
    if ( str[0]=='~' ) return home_sub(str);
    if ( current_path == "" ) return "/"+str;
    return "/"+current_path+"/"+str;
}

mkpath2(str) {
    if (!str) return;
    return PREFIX(mkpath(str)) ;

}

home_sub(str) {
        if ( str[1] =='/' ) {
	    if ( ob->query_domain() )
		return "/players/"+ob->query_domain()+"/"+lower_case(name)+extract(str,1);
	    return "/players/"+lower_case(name)+extract(str,1);

	}
        return "/players/"+extract(str,1);
}


remove_file(str) { return ::remove_file(mkpath(str)); }

more(str) { return ob->more(mkpath2(str)); }


list_files(str) {

        if (str) return ::list_files(mkpath2(str));
        return ::list_files(mkpath2(""));
}

list_files2(str) {
        if (str) str = mkpath2(str);
        else str = mkpath2("");

	if ( extract(str,1,7) == "players" ) return;
	return ::list_files(str);
}


file_cmd(str) {
	if (!str||str[0]=='/') return;
	hist->enable(-1);
	command(query_verb()+" "+mkpath2(str),ob);
	return 1;
}

cat_file(str) { return ob->cat_file(mkpath2(str)); }

tail_file(str) { return ob->tail_file(mkpath2(str)); }

show_file_size(str) {
        write(file_size(mkpath2(str))+"\n");
        return 1;
}

mkpath3(str) {
int     i;

    if ( (str) && (i=strlen(str)) > 2 && extract(str,i-2,i-1) == ".c" )
        str=extract(str,0,i-3);
    if ( /*file_size*/( (str=mkpath2(str)) + ".c") /*> 0*/ ) {
        while ( str[1] == '.' ) str=extract(str,2);
        while ( str[0] == '/' ) str=extract(str,1);
        return str;

    }
}

clone(str) {
    object obj;
    if (str="/"+mkpath3(str)) {
        obj = clone_object(str);
        "players/amylaar/lib"->tell_others(
		cap_name + " fetches something from another dimension.\n",ob);
        move_object(obj, environment(ob));
        if ( obj->get() ) transfer(obj, myself);
        write("Ok.\n");

        return 1;
    }
}

teleport(dest) {
    if ( dest && !find_living(dest) && (dest=mkpath3(dest)) ) {
        this_player()->move_player("X#" + dest);
        return 1;
    }
}

snoop_test() {
        if ( ob == this_player() ) return;
        if ( this_player()->query_level() < snoop_notify_level || snoop_notify_level > 999999999 )
                tell_object(ob,capitalize(this_player()->query_real_name())+" tried to read the internals of your nutshell!\n");

        if ( this_player()->query_level() < snoop_level ) {
                write("You are struck by a mental bolt from the interior of the game.\n");
                return 1;
        }
}

patch_test() {
        if ( !previous_object()  || previous_object() == this_object() ||
            previous_object() == hist ) return;
        if ( extract(file_name(previous_object()),0,18) ==
                "players/amylaar/nut" &&
                previous_object()->query_real_name() == query_real_name() )

                        return;
        if ( this_player()->query_level() < patch_level || patch_level > 999999999 ) {
                tell_object(ob,this_player()->query_real_name()+" tried to patch your nutshell!\n");
                write("You are struck by a mental bolt from the interior of the game.\n");
                ob->add_exp(this_player()->hit_player(9999));
                return 1;
        }
}

static set_owner(obj) {
        if ( ob == obj ) return;
        ob=obj;
        name=lower_case(obj->query_real_name());
        cap_name=capitalize(name);
#ifdef GENESIS
	domain=obj->query_domain();
#endif
        level=obj->query_level();

        if ( level < 20 || patch_level < level || snoop_level < level )
                snoop_level=snoop_notify_level=patch_level=level;
        can_drop=0;
        oldenv=environment(ob);
        hist=clone_object("players/amylaar/history");
        if ( !hist_name ) short_desc=name+"'s nutshell";
        hist->start(this_object(),ob,hist_name);
        call_out("refresh",2);
        myself=ob;
write("set_owner:\n");
write(ob);write(" "+name+" "+cap_name+"\n");
write("history ");write(hist);write("\n");
}

set(str) {
        if (!str) { write(
                "snoop_notify_level: "+snoop_notify_level+
                "\nsnoop_level    : "+snoop_level+
                "\npatch_level    : "+patch_level+"\n");

                return 1;
        }
        patch_test();
        return  sscanf(str,"snoop_notify_level %d",snoop_notify_level) ||
                sscanf(str,"snoop_level %d",snoop_level) ||
                sscanf(str,"patch_level %d",patch_level) ;
}

exc(str) {
        if ( previous_object() != hist && patch_test() ) return 1;
        command(str,ob);
}

tell(str) {
string sd;

        if ( ob->query_spell_points() < 0 ) {
                tell_object(ob,"You are low on power.\n");
                return 1;
        }
        if ( (sd=ob->short()) && extract(sd,8) == "ghost of" ) {
                tell_object(ob,"You fail.\n");
                return 1;
        }
        spell_points+=5;
        if ( ob->query_level() < 20 ) ob->restore_spell_points(-5);
        return ::tell(str);
}

rename(str) {
        if ( patch_test() ) return 1;
        if ( sscanf(str,"nutshell %s",short_desc) ) return 1;
        if ( sscanf(str,"history %s",hist_name) ) {

                hist->set_name(hist_name);
                return 1;
        }
}

/* --- end of nutshell.c */
