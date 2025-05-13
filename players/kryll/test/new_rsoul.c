/*-------------------------------------------------------------------------*/
/* FILE : rsoul.c                                                          */
/*                                                                         */
/* Description : This is the file that contains all the rsoul and finger   */
/*               commands for now.                                         */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Jun 12 1997  Kryll        Cleaned up this file. Removed extraneous comments.
 
*/

#include "/sys/defs.h"
#include "/obj/lw.h"

#define RSOUL   "/players/moonchild/misc/rsoul_cmds"
#define RWHERE  "/players/sauron/sys/rwhere/rwhere"
#define SAVEDIR "/players/kryll/test/fingerdata/"
#define FINGER  "/players/kryll/test/read_finger"
 
string real_life_name;
string last_ip_name;
string last_login_time;
string plan_msg;
int allow_show_ip;
static string plan_tmp;
static string tpn, rpath;
 
int id(string str) {
  return str=="rsoul" || str=="remote soul" || str=="remotesoul";
}
 
int get() {
  return 1;
}
 
int drop() {
  return 1;
}
 
void long() {
  write("Your remote soul is invisible. Type <help rsoul> for help.\n");
}
 
void init() {
  if(TP != ENV())
    return;
  add_action("do_rcmd", "r", 1);
  add_action("rwhere", "rwhere");
  add_action("rsoul_help", "help");
  add_action("finger_player", "finger");
  add_action("plan_msg", ".plan");
  add_action("do_chfn", "chfn");

  tpn = (string)TP->RNAME;
  rpath = sprintf("%s%c/%s", SAVEDIR, tpn[0], tpn);
  if(!restore_object(rpath))
    real_life_name = "-";
  last_ip_name = query_ip_name(TP);
  last_login_time = ctime(time());
  save_object(rpath);
}
 
int finger_player(string str) {
  if(!str) {
    write(TP->IMM ? "Usage: finger <player> / <wiz@mud>.\n" :
                    "Usage: finger <player>.\n");
    return 1;
  }
  return (int)FINGER->read_finger(str);
}
 
int do_chfn() {
  write("Changing finger information for " + CAP(tpn) + "@HolyMission.\n"
        "The old values will be shown inside of [].\n"+
        "To use the old value, just type <return>.\n"+
        "Name (in real life) [" + real_life_name + "] ");
  input_to("chfn2");
  return 1;
}
 
void chfn2(string str) {
  if(!str || str=="")
    write("Name left as: " + real_life_name + ".\n");
  else {
    real_life_name = str;
    write("Name changed to: " + real_life_name + ".\n");
  }
  write("Do you want other people to see your site name? ["
        + (allow_show_ip ? "y" : "n") + "] ");
  input_to("chfn3");
  return;
}
 
void chfn3(string str) {
  if(str && str!="") {
    if(lower_case(str[0..0]) == "n")
      allow_show_ip = 0;
    else
      if(lower_case(str[0..0]) == "y")
        allow_show_ip = 1;
    else {
      write("Please answer \"y\" or \"n\". ");
      input_to("chfn3");
      return;
    }
  }
  write("Other people are " + (allow_show_ip ? "" : "not ")
        + "allowed to see your site name.\n");
  save_object(rpath);
  return;
}
 
int plan_msg() {
  plan_tmp = "";
  write("Changing your plan message. To keep the old one, enter ~q at the\n"
        "beginning of a line. To finish, enter ** at the beginning "+
        "of a line.\n]");
  input_to("plan_line");
  return 1;
}
 
void plan_line(string str) {
  if(str == "~q") {
    write("Plan message change aborted.\n");
    return;
  }
  if(str == "**") {
    write("Plan message changed.\n");
    plan_msg = plan_tmp;
    save_object(rpath);
    return;
  }
  plan_tmp += str + "\n";
  write("]");
  input_to("plan_line");
}
 
mixed *return_all_rsoul_info() {
  return ({ real_life_name, last_login_time, last_ip_name,
        allow_show_ip, plan_msg });
}
 
int do_rcmd(string str) {
  return (int)RSOUL->rsoul_cmd(query_verb(), str);
}
 
int rwhere(string str) {
  return (int)RWHERE->main(str);
}
 
int rsoul_help(string str) {
  if(id(str)) {
    RSOUL->get_verb_list();
    return 1;
  }
  if(str == "rsoul-adverbs") {
    RSOUL->get_adverb_list();
    return 1;
  }
  return 0;
}

