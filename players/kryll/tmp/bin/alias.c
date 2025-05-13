
#include "/sys/defs.h"

static private mixed  *list;
static private int    list_sz;
static private object caller;

greater_fun(p1,p2) { return (p1>p2); }
 
static private string expand(string buff,string cverb) {
  string *cmds,verb;
 
  buff = strip(buff);
  verb = explode(buff, " ")[0];
  if (verb==cverb && cverb)  return 0;
  if (verb=="alias" || verb=="nick") return buff; /* no nick/alias resolution*/
  cmds=explode(buff,sep);
  if(sizeof(cmds) > 1) {
    cmds = map_array(cmds, "expand", this_object(), cverb);
    if (cverb && member_array(0, cmds) != -1) return 0;
    buff = implode(cmds, sep);
  } else {
    if(buff[0] != '*')
        buff = alias(buff);
    else {
        buff = buff[1..strlen(buff)-1];
        alias_flag = 0;
    }
    if (alias_flag) buff = expand(buff, cverb);
    else buff = nick(buff);
  }
  return buff;
}

int main(string str) {
  caller = TP;
  list = caller->get_list();
  if(!list || sizeof(list) != 2)
    notify_fail("You have no aliases set.\n");
    return 0;
  }

  do_alias(str);
  return 1;
}

static private void do_alias(string str) {
  string *cmds;
  string cmd, hstr0, hstr1, hstr2, verb, tmp, tmp2, tmp3;
  int    i, pos, sz;

  sz = sizeof(list[0]);
  if(!str) {
    write("Your aliases:\n-------------\n");
    hstr0 = sort_array(list[0], "greater_fun", caller);
    for(i=0; i<sz; i++)
        write(hstr0[i] + " ---> " + assoc(hstr0[i], list) + "\n");
    write("You have " + sz + (sz==1 ? " alias" : " aliases") +
          ", the Maximum is " + MAX_ALIAS + ".\n");
    return 1;
  }

  cmds = explode(str, " ");
 
  if(cmds[0] == "alias") {
     write("It's illegal to have an alias for alias !\n");
     return 1;
  }

  /* Matt SEP-03-94: Don't allow blank aliases...! */
  if(cmds[0] == "") return 0;
 
  if(sizeof(cmds) < 2) {
    if((pos = assoc(cmds[0], list[0])) == -1) {
      write("No such alias defined!\n");
      return 1;
    }

    if(pos == 0) {
        hstr0 = list[0][1..sz-1];
        hstr1 = list[1][1..sz-1];
    }
    else if(pos == sz-1) {
        hstr0 = list[0][0..sz-2];
        hstr1 = list[1][0..sz-2];
    }
    else {
        hstr0 = list[0][0..pos-1] + list[0][pos+1..sz-1];
        hstr1 = list[1][0..pos-1] + list[1][pos+1..sz-1];
    }
    list[0] = hstr0;
    list[1] = hstr1;
    list = order_alist(list);
    write("Alias for " + cmds[0] + " removed.\n");
    return 1;
  }
 
  /* Check for recursive aliases */
 
  hstr0 = explode(str," ");
  verb = hstr0[0];
  hstr0[0] = 0;                   /* delete the alias pattern */
  hstr0 = implode(hstr0, " ");
  if(!expand(hstr0, verb)) {
     write("You must not define your aliases recursively!\n");
     return 1;
  }
 
  /* Check for use of \ , [ and ] - Moonchild 281092 */
 
  tmp="." + str + ".";
  if(sscanf(tmp, "%s\\%s", tmp2, tmp3) == 2) {
    write("You may not use \"\\\" in an alias.\n");
    return 1;
  }
  if(sscanf(tmp, "%s[%s", tmp2, tmp3) == 2) {
    write("You may not use \"[\" in an alias.\n");
    return 1;
  }
  if(sscanf(tmp, "%s]%s", tmp2, tmp3) == 2) {
    write("You may not use \"]\" in an alias.\n");
    return 1;
  }
 
  /* alias einfuegen */
  cmd = cmds[0]; cmds[0] = 0; str = implode(cmds, " ");
 
  write("You have " + (sizeof(list[0])+1) + " alias, the maximum is " +
        MAX_ALIAS + ".\n");
 
  if(sizeof(list[0]) > MAX_ALIAS) {
    write("Sorry, too many alias, remove some first.\n");
    return 1;
  }
  list = insert_alist(cmd, str, list);
  write("Ok.\n");
  return 1;
}

