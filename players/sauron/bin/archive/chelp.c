#include "/players/sauron/include/include.h"
#include "/sys/levels.h"

#define DIRS ([\
               "arch":WL_ARCH,\
               "wiz":WL_WIZ,\
               "newwiz":WL_NEWWIZ,\
               "testp":150,\
               "appr":WL_APPR,\
               "player":WL_PLAYER,\
               "personal":-100,\
             ])

string display_list(mixed *list,int flag) {
  string ret,*arr;
  int i;

  if(!flag)
    ret="Help available for "+list[0]+" commands:\n\n";
  else
    ret="Help available for your personal commands:\n\n";
  if(!list[1] || !pointerp(list[1]) || !sizeof(list[1]))
    arr=({"none"});
  else {
    arr=sort_array(list[1],#'>);
    arr=filter_array(arr,lambda(({'tmp}),
                                ({#'==,({#'extract,'tmp,-2}),".c"})));
    for(i=0;i<sizeof(arr);i++)
      arr[i]=arr[i][0..<3];
  }
  ret+=(list_nicely(arr)+"\n");
  return ret;
}

int main(string str) {
  string ret,*arr,file,which;
  int *list,i;
  object tp;
  mapping cmds;

  tp=this_player();
  cmds=(mapping)tp->query_cmd_list();
  list=m_indices(cmds);
  list=sort_array(list,#'<);


  if(!str) {
    ret="";
    for(i=0;i<sizeof(list);i++) {
      ret+=display_list(cmds[list[i]],(list[i]<0));
      ret+="\n";
    }
    tp->more_string(lw(ret[0..<2]));
    return 1;
  }
  else if(member_array(str,m_indices(DIRS))!=-1 &&
          member_array(DIRS[str],list)!=-1) {
    tp->more_string(lw(display_list(cmds[DIRS[str]],(DIRS[str]<0))));
    return 1;
  }
  else {
    str=tp->filter_alias(str);
    for(i=0;i<sizeof(list);i++) {
      if(member_array(str+".c",cmds[list[i]][1])!=-1) {
        if(cmds[list[i]][0][0..0]=="/") {
          file=cmds[list[i]][0]+str;
          which="your personal";
        }
        else {
          file="/sys/bin/"+cmds[list[i]][0]+"/"+str;
          which=cmds[list[i]][0];
        }
        break;
      }
      else
        continue;
    }
  }
  if(!file) {
    notify_fail("chelp: No such command ("+str+").\n");
    return 0;
  }
  else {
    if(!(ret=(string)file->help()))
      ret="No help available.\n";
    tp->more_string(sprintf("Help for %s command '%s':\n\n%s",
                            which,str,lw(ret)));
    return 1;
  }
}

string help() {
  return "\
Command:\tchelp <topic>\n\
Arguments:\tnone, or a command.\n\
See also:\thelp"+
(this_player()->query_immortal() || this_player()->query_testchar()?
   ", man":
   "")+"\n\
\n\
This command displays help about a command, or gives you a list of \
commands available to you, if no argument is supplied.\n";
}
