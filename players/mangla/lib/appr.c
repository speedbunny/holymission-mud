#include "/sys/levels.h"

#define CD      "sys/chatd"
#define APPR    "/sys/bin/appr/"

inherit "sys/player";

static int is_not_wizlisten;    /* Listens to wizline 0=NO, 1=YES */
static int noshouts;            /* Listens to shouts */

logon(n) {
  ::logon(n);
  awiz_commands();
  CD->add_chat(this_object(),-1);     /* wiz-line */
}

/* add_chat() will be called from secure/master::valid_exec() */

int _filter(string str) {

    string theverb;

    theverb = (string)query_verb();

    if(theverb[0] == 39) return 0;
    if(theverb == "quit" || theverb == "dest") return 0;

    if(file_size(APPR + theverb + ".c") > 0)
        if ((APPR + theverb)->main(str))
            return 1;
    if(theverb == "wiz/" || theverb == "j/") {
        (APPR+"wiz")->main(str);
        return 1;
    }

    return 0;
}

add_chat() {
  CD->add_chat(this_object(),-1);     /* add to wiz-line */
  ::add_chat();                       /* add to guild-line */
}

static awiz_commands() {
    add_action("busy","busy");
    add_action("earmuffs", "earmuffs");
    add_action("echo_wiz", "wiz");
    add_action("echo_wiz", "wiz/");
    add_action("emote", "emote");
    add_action("set_pretitle","pretitle");
    add_action("set_alignment","alignment");
    add_action("setmmin", "setmmin");
    add_action("setmmout", "setmmout");
    add_action("setmin", "setmin");
    add_action("setmout", "setmout");
    add_action("tail_file", "tail");
    add_action("toggle_noshouts","listen");
}

static busy(str) {

  int lvl;

  if ( !str || str == "on" )
    listen_to_shouts_from_level = level;
  else if ( str == "off" )
    listen_to_shouts_from_level = 0;
  else {
    lvl = to_int( str );
    listen_to_shouts_from_level = lvl <= level ? lvl : level;
  }

  write("Earmuffs at level " + listen_to_shouts_from_level + ".\n");

  return( 1 );
}

static earmuffs(str) {

  write("Your earmuffs are at level " + listen_to_shouts_from_level + ".\n");
  return 1;
}

#if 0
static home(string who) {
string str,name_of_friend;
  
    if (who)
    {
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
#endif

static setmin(m) {
  msgin = m;
  return 1;
}

static setmout(m) {
  msgout = m;
  return 1;
}

static setmmin(m) {
  mmsgin = m;
  return 1;
}

static setmmout(m) {
  mmsgout = m;
  return 1;
}

static tail_file(path)
{
    if (!path)
        return 0;
    if(path[0]=='~') path="/players/"+name+path[1..strlen(path)-1];
    if (!tail(path))
        return 0;
    return 1;
}

static toggle_noshouts() {
    if(noshouts) write("You start listening to shouts again.\n");
    else write("You do not listen to shouts any further.\n");
    noshouts=!noshouts; 
    return 1;
}

/* promotion of wizards */

set_level(l) {
  if(master_object()->set_wiz_level(this_object()->query_real_name(),l)) {
     if(l<L_APPR) is_wizard=0; else is_wizard=1;
     return( ::set_level(l) );
  } else illegal_patch("set_level");
}

/* query functions for appr */

query_wizline() { return !is_not_wizlisten; }
query_noshouts() { return noshouts; }
query_earmuff_level() { return listen_to_shouts_from_level; }

