/*-------------------------------------------------------------------------*/
/* FILE : who.c                                                            */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              display the who list.                                      */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"
#include "/sys/levels.h"

#define FILTER(x) u = filter_array(users(), x, TP); break;

status _mortal(object ob) {
  return (int)ob->LVL < L_APPR;
}

status _immortal(object ob) {
  return (int)ob->LVL > L_PLAYER;
}

status _male(object ob) {
  return (int)ob->query_gender() == 1;
}

status _female(object ob) {
  return (int)ob->query_gender() == 2;
}

status _incognito(object ob) {
  return (int)ob->query_incognito();
}

status _pk(object ob) {
  return (int)ob->query_is_pk();
}

status _arena(object ob) { 
  return (int)(ENV(ob) && ENV(ob)->query_arena());
}

status whosort(object p1, object p2) { 
  int l1, l2;

/*
  return p1->query_incognito() ? 1 : p2->query_incognito() ? 0 :
        (int)p1->LVL < (int)p2->LVL;
*/
  if(p1->query_incognito())
    return 1;
  if(p2->query_incognito())
    return 0;
  l1 = p1->LVL;
  l2 = p2->LVL;
  if(p1->IMM)
    l1 += L_APPR;
  if(p2->IMM)
    l2 += L_APPR;
  return (l1 < l2);
}

int main(string str) {
  object *u;
  int    i, curr_level, prev_level, flag, sz, hlp;
  string line, pl_name, msg;

  if(!str) {
    u = users();
    msg = "================================================================="
          "==============\n";
  }
  else {
    switch(str) {
      case "mortal"    : FILTER("_mortal");
      case "immortal"  : FILTER("_immortal");
      case "male"      : FILTER("_male");
      case "female"    : FILTER("_female");
      case "incognito" : FILTER("_incognito");
//      case "pk"        : FILTER("_pk");
      case "legendary" : FILTER("_legendary");
      case "arena"     : FILTER("_arena");
      default          : 
        write("Usage: who [mortal/immortal/male/female/"
              "incognito/legendary/arena]\n");
        return 1;
    }

    if(!sizeof(u)) {
      printf("No %s players on Holy Mission currently.\n", str);
      return 1;
    }

    msg = sprintf("%s players on Holy Mission:\n\n"
                  "================================================="
                  "==============================\n", CAP(str));
  }
  u = sort_array(u, "whosort", TO);
  for(i=0, sz=sizeof(u); i<sz; i++) {
    if(u[i]->query_incognito())
      break;
    prev_level = curr_level;
    curr_level = (int)u[i]->LVL;
    if(prev_level>L_PLAYER && curr_level<=L_PLAYER)
      msg += "--------------------------------------------------------------"
             "-----------------\n";
    switch(curr_level) {
      case -1..L_PLAYER         :
        hlp = curr_level + u[i]->query_legend_level();
        if(hlp > L_PLAYER)
          line = sprintf("[L%i]", hlp-L_PLAYER);
        else
          line = sprintf("[%i]", curr_level);
        break;
      case L_APPR..(L_NEWWIZ-1) : line = "[Appr]"; break;
      case L_NEWWIZ..(L_WIZ-1)  : line = "[New]"; break;
      case L_WIZ..(L_SAGE-1)    : line = "[Wiz]"; break;
      case L_SAGE..(L_RETD-1)   : line = "[Sage]"; break;
      case L_RETD..(L_ELDER-1)  : line = "[Retd]"; break;
      case L_ELDER..(L_ARCH-1)  : line = "[Eldr]"; break;
      case L_ARCH               : line = "[Arch]"; break;
      case L_SPEC               : line = "[High Arch]"; break;
      case L_GOD                : line = "[God]"; break;
      default                   : line = "[Arch]"; break;
    }
    if(!(pl_name = (string)u[i]->short(0)))
      pl_name = CAP((string)u[i]->RNAME);
    msg += sprintf("%-7=s%-72=s\n", line, pl_name);
  }

  if(i <= sz) {
    for(flag=str=="incognito"; i<sz; i++) {
      if(!u[i]->query_incognito())
        continue;
      if(!flag)
        msg += "--------------------------------------------------------"
               "-----------------------\nIncognito:\n";
      flag = 1;
      msg = sprintf("%s       %s\n", msg, (string)u[i]->short(1));
    }
  }
  msg = sprintf("%s============================== %i players online "
                "==============================\n", msg, sz);
  write(msg);
  return 1;
}

