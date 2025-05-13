/* mud@mud.edvz.uni-linz.ac.at Herp aka Herbert Rosmanith */

/*-------------------------*
 * Using object oriented   *
 * class concept           *
 *-------------------------*/

#include "levels.h"
#include "lw.h"
#include "/sys/defs.h"

#define NEWWIZ "/sys/bin/newwiz/"

string name_of_friend;  /* who is our testplayer */
inherit "sys/appr";

int _filter(string str) {

    string theverb;

    theverb = (string)query_verb();

    if(theverb[0] == 39) return 0;
    if(theverb == "quit" || theverb == "dest") return 0;

    if(file_size(NEWWIZ + theverb + ".c") > 0)
        if ((NEWWIZ + theverb)->main(str))
            return 1;

    return ::_filter(str);
}

static nwiz_commands() {

    add_action("clone", "clone");
    add_action("copyfile","cp");
    add_action("edit", "ed");
    add_action("makedir", "mkdir");
    add_action("movefile", "mv");
    add_action("removedir", "rmdir");
    add_action("remove_file", "rm");
    add_action("trace", "trace"); /* Moonchild 250693 */
    add_action("update_object", "update");
    add_action("_cd","cd");
    add_action("_cat_file","cat");
    add_action("list_files", "ls");
    add_action("list_files2", "dir");
    add_action("more", "more");
    add_action("pwd", "pwd");

/* added moonchild - wizzes may patch their environment variables 220693 */
    add_action("do_setenv","setenv");
    add_action("do_unsetenv","unsetenv");
    add_action("do_printenv","printenv");

    add_action("_filter","",1);
}

logon(n) {
  ::logon(n);
  nwiz_commands();
}

static _cat_file(path)
{
    if (!path)
        return 0;
    if(path[0]=='~') path="/players/"+name+path[1..strlen(path)-1];
    if (!cat(path))
        write("No such file.\n");
    return 1;
}

static _cd(str) {
    string *parts,ba;
    int fs,i,bs;

    if (!str || str=="") str="~";
    if (str[0]=='~') str="/players/"+name+str[1..strlen(str)-1];
    if (str[0]!='/') str=current_path+"/"+str;
    if (current_path!="" && str[0]!='/') str="/"+str;
    str=clean_path(str);
    if(str) {
        fs=file_size(str);
        if(fs==-1) {
            write(str+": No such file or directory\n");
            return 1;
        } else if(fs!=-2) {
            write(str+": Not a directory\n");
            return 1;
        } else if(!valid_read(str)) {
            write(str+": Access denied!\n");
            return 1;
        }
    }

    current_path=str[1..strlen(str)-1];
    write("/"+current_path + "\n");
    return 1;
}

static list_files(path)
{
    if (!path)
        path = "/" + current_path;
    if (path[0] != '/' && path[0] != '~')
        if(current_path=="") path="/"+path;
        else path = "/" + current_path + "/" + path;
    if(path!="/") path = path + "/.";
    ls(path);
    return 1;
}

static list_files2(path)
{
    if (!path)
        path = "/" + current_path;
    if (path[0] != '/' && path[0] != '~')
        if(current_path=="") path="/"+path;
        else path = "/" + current_path + "/" + path;
    if(path!="/") path = path + "/.";
    dir(path);
    return 1;
}

/* LLORT: resolve the currect path for wizards */
more(str) {
    if (!str)
        return 0;
    if(str[0]=='~') str="/players/"+name+str[1..strlen(str)-1];
    if(str[0]!='/') str=current_path+"/"+str;
    if(current_path!="" && str[0]!='/') str="/"+str;
    return ::more(str);
}

static pwd() {
    write("/" + current_path + "\n");
    return 1;
}


static copyfile(str) {
string src,dst;

  if (!str || sscanf(str,"%s %s",src,dst)!=2) return 0;
  if(str[0]=='~') str="/players/"+name+str[1..strlen(str)-1];
  if(dst[0]=='~') dst="/players/"+name+dst[1..strlen(dst)-1];
  if (!cp(src,dst)) write("Fail.\n");
  return 1;
}

static edit(file)
{
    string tmp_file;
    if (!file) {
        ed();
        return 1;
    }
    if(file[0]=='~') file="/players/"+name+file[1..strlen(file)-1];
    file = valid_write(file);
    if (!file) {
        write("You can only edit your own files.\n");
        return 1;
    }
    ed(file);
    return 1;
}

static makedir(str) {
    if (!str)
        return 0;
    if(str[0]=='~') str="/players/"+name+str[1..strlen(str)-1];
    if (!mkdir(str)) write("Fail.\n");
    return 1;
}

static movefile(str) {
string src,dst;
  if (!str || sscanf(str,"%s %s",src,dst)!=2) return 0;
  if(src[0]=='~') src="/players/"+name+src[1..strlen(src)-1];
  if(dst[0]=='~') dst="/players/"+name+dst[1..strlen(dst)-1];
  if (rename(src,dst)!=0) write("Fail.\n");
  return 1;
}

static removedir(str) {
    if (!str)
        return 0;
    if(str[0]=='~') str="/players/"+name+str[1..strlen(str)-1];
    if (rmdir(str))
        write("Ok.\n");
    else
        write("Fail.\n");
    return 1;
}

remove_file(str) {
    if (!str)
        return 0;
    if(str[0]=='~') str="/players/"+name+str[1..strlen(str)-1];
    rm(str);
    return 1;
}

static update_object(str) {
    object ob;
    if (!str) {
        write("Update what object ?\n");
        return 1;
    }
    if (!str) {
        write("Invalid file name.\n");
        return 1;
    }
    if(str[0]=='~') str="/players/"+name+str[1..strlen(str)-1];
    str = valid_read(str);
    ob = find_object(str);
    if (!ob) {
        write("No such object.\n");
        return 1;
    }
    destruct(ob);
    write(str + " will be reloaded at next reference.\n");
    return 1;
}

do_setenv(str) {
  string var,sval;
  int ival;
  if(!str)
    return;
  if((sscanf(str, "%s %d", var, ival))==2)
    setenv(var, ival);
  else if((sscanf(str, "%s %s", var, sval))==2)
    setenv(var, sval);
  else
    setenv(str);
  write("Ok.\n");
  return 1;
}

do_unsetenv(str) {
  write(unsetenv(str) ? "Ok.\n" : "No such environment variable.\n");
  return 1;
}

do_printenv(str) {
  if(!str) {
    write("Environment variables:\n\n");
    printenv();
  }
  else
    printenv(str);
  return 1;
}

static trace(arg) {
    int ex_time;
    if(!arg)
        write("Trace what?\n");
    else {
        ex_time=command(arg);
        write("Time: " + ex_time + " cycles.\n");
    }
    return 1;
}

score()
{
   ::score();
   if(is_invis) write(" You are invisible level "+is_invis+".\n");
   else write(" You are visible.\n");
   return 1;
}

