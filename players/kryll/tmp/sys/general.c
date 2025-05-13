#ifndef __P_GENERAL_C__

#define __P_GENERAL_C__

#include "player_defs.h"
#include "player_description.h"
#include "player_general.h"
#include "player_guild.h"
#include "player_prompt.h"
#include "/sys/levels.h"

/*--------------------------------------------------------------------------*/
/* Some functions to access the user_status variable                        */
/* please use the defined variables in /obj/user_status.h                   */
/*--------------------------------------------------------------------------*/
nomask int query_user_status(int stat) {
  return user_status & stat;
}

nomask int set_user_status(int stat) {
  return user_status |= stat;
}

nomask int clear_user_status(int stat) {
  return user_status &= (!stat);
}

nomask int toggle_user_status(int stat) {
  return user_status ^= stat;
}

/*--------------------------------------------------------------------------*/
/* General functions for accessing player variables.                        */
/*--------------------------------------------------------------------------*/
nomask int may_not_be_snooped() {
  return 0;
}

nomask int query_prevent_shadow() {
  return 0;
}

nomask int query_linkdeath() {
  return is_linkdead;
}

nomask int query_link_return() {
  return link_return;
}

// Define this after it was used.
nomask string version() {
  return __VERSION__;
}

nomask void save_me(int val) {
  if(val)
    tot_value = compute_values(first_inventory(T0));
  else
    tot_value = 0;
  compute_auto_str();

  save_object("p/" + to_string(({name[0]})) + "/" + name);
}

/*--------------------------------------------------------------------------*/
/* Called by the bin command 'save'                                         */
/*--------------------------------------------------------------------------*/
nomask int save_character() {
  save_me(1);
  write("Ok.\n");
  return 1;
}

/*--------------------------------------------------------------------------*/
/* Set the race of the player. If the setter is not an arch then do not     */
/* allow it. Otherwise log the set.                                         */
/*--------------------------------------------------------------------------*/
nomask void set_race(string str) {
  if(real_race && level<L_APPR && TP->LVL<L_ARCH && !TO->TESTC)
    return;
  ::set_race(str);
  fix_short();
  if(name != TP->RNAME) {
    log_file("RACE", ctime() + " " + name + " patched by " +
             TP->RNAME + " race " + str + "\n");
  }
  return;
}
/*
 * Recursively compute the values of the inventory.
 * Beware that object may selfdestruct when asked for query_value().
 */
static int compute_values(object ob) {
  int v, tmp;
  object next_ob;

  while(ob) {
    next_ob = next_inventory(ob);
    tmp = ob->query_value();
    if(ob->query_auto_load())
      tmp = 0;
    if(tmp > 1000)
      tmp = 1000;
    v += tmp;
    if(ob && first_inventory(ob))
      v += compute_values(first_inventory(ob));
    ob = next_ob;
  }
  return v;
}

void load_auto_obj(string str) {
  string file, argument, rest;
  object ob;
  mixed dum;

  while(str && str != "") {
    if(sscanf(str, "%s:%s^!%s", file, argument, rest) != 3) {
      write("Auto load string corrupt.\n");
      return;
    }
    str = rest;
    dum = catch(ob=clone_object(file));
#if 0
    if(ob) {
#else
    if(!dum) {             /*herp*/
#endif
      ob->init_arg(argument);
// transfer?
      MOVE(ob, TO);
      add_weight(ob->query_weight());
    }
    else if(level > L_SAGE)
      write(dum);
  }
  return;
}

nomask string nsh_flag(object ob) {
  if(!IMM)
    return " ";
  return (ob->query_noshouts() ? "*" : " ");
}

void reset(int arg) {
  int i;

  ::reset(arg);                       /* !!! HERP */

  call = #'call_other;

// Does this even work?
  if(arg!=0 && !interactive(TO) ) {
    if(ldead >= 2) /* 45 min - 1,5 hours */
      call_out("dest_ldead", 1, 0);    /* short call out to avoid bugs */
    else
      ldead = ldead + 1;
  }

// Mangla: What is temporary? I will comment out for now.
// Herp:   keep a log of reset with arg==0 temporarily ...
#if 0
  if(!arg && name) {
    log_file("RESET_P", name + " this_player(): ");
    if(TP)
      log_file("RESET_P", TP->NAME + " " + TP->short() + " ");
    else
      log_file("RESET_P", " unavail. ");
    if(PO)
      log_file("RESET_P", " previous_object " + PO->NAME + " " +
               PO->short() + "\n");
    else
      log_file("RESET_P", " unavail.\n");
  }
#endif

// With arg = 0 this function should only be entered once!
  if(arg) return;

  if(creator(TO)) {
    write("Cloned player\n");
    illegal_patch("Cloned player.c");
    destruct(TO);
    return;
  }
  level = -1;
  name = "logon";
  cap_name = "Logon";
  real_size = 0;
  real_race = 0;
  msgin = "arrives";
  msgout = "leaves";
  mmsgin = "arrives in a puff of smoke";
  mmsgout = "disappears in a puff of smoke";
  title = "the titleless";
  al_title = "neutral";
  real_al_title = al_title;
  gender = -1;         // Illegal value, so it will be changed!
  env_var = ([]);
  poisonname = explode(POISON_STATES,"/");
  incognito = 1;
  prompt = DEF_PROMPT;
  set_number_of_arms(2);
}

nomask int query_player() {
  return 1;
}

/*--------------------------------------------------------------------------*/
/* Identify ourself.                                                        */
/*--------------------------------------------------------------------------*/
nomask int id(string str, int lvl) {
// Some wizzies make invisibility items useable by
// players , and this will prevent cheating.
  if(!is_wizard)
    if(str == name || str == "ghost of " + name)
      return 1;

// Mangla: Who is I ?
// I think this looks stupid. When I am invisible it is
// because I want to work in PEACE.
  if(is_invis_for(TP))
    return 0;

  if(ghost)
    return str == "ghost of " + name;
  if(str == name)
    return 1;
  return (lower_case(str) == lower_case(query_name_rdr()));
}

/*--------------------------------------------------------------------------*/
/* Filter commands through here. This allows for binning commands and       */
/* easy adding and subtracting of them.                                     */
/*--------------------------------------------------------------------------*/
int _filter(string str) {
  string verb;

  verb = (string)query_verb();

  if(verb[0..0]=="'" || member(verb, '.')!=-1)
    return 0;

// quit is still an add_action
  if(verb == "quit")
    return 0;

  if(file_size(FEELINGS + verb + ".c") > 0)
    if((FEELINGS + verb)->main(str))
      return 1;

  if(file_size(PLAYER + verb + ".c")>0)
    if((PLAYER + verb)->main(str))
      return 1;

  return 0;
}

/*--------------------------------------------------------------------------*/
/* When we quit the game some things have to happen.                        */
/* If we are a wiz then lets get moved to our workroom.                     */
/* Drop all, save the player file, and reconnect to secure/login            */
/*--------------------------------------------------------------------------*/
nomask static int quit(int val) {
  string str, testchar;
  object login;

  if(interactive(TO) && query_input_pending(TO)) {
    notify_fail("You can't quit while entering text.\n");
    return 0;
  }
  save_me(0);
  if(level>apwz && !val && file_name(ENV(TO))!="players/"+name+"/workroom") {
    if(str = catch(home(0))) {
      write("You have no workfile or it is buggy.\n");
      write("Reason: " + str + "\n");
    }
  }
  else if((testchar=TO->TESTC) && !val &&
       file_name(ENV(TO))!="players/"+testchar+"/workroom") {
    printf("env %s\n", file_name(ENV(TO)));
    if(str = catch(home(0))) {
      write("You have no workfile or it is buggy.\n");
      write("Reason: " + str + "\n");
    }
  }
  drop_all(1);
  write("Saving " + cap_name + ".\n");
  if(!silent)
    write("Goodbye, friend .. Come back soon!\n");
  if((!is_linkdead)) {
    say(TO->RNAME + " left the game.\n", 0, TO, INVNAME + " left the game.\n");
    CD->do_chat(-3, sprintf("\n%s just logged off.\n", cap_name));
  }
  if(TP && login=clone_object("/secure/login")) {
    login->recon(name);
    exec(login, TO);
  }
  destruct(TO);
  return 1;
}

nomask string query_mailaddr() {
  return mailaddr;
}

int fix() {
  set_heart_beat(1);
  if(interactive(TO))
    enable_interactive(TO);
  reset_expander();
  if(!prompt || sizeof(prompt)!=sizeof(DEF_PROMPT))
    prompt = DEF_PROMPT;
  return 1;
}

int illegal_patch(string str) {
  write("You are struck by a mental bolt from the interior of the game.\n");
  log_file("ILLEGAL", ctime(time()) + ":\n");
  log_file("ILLEGAL", call_other(TP, "query_real_name") + " " + str + "\n");
  return 0;
}

int show_hp() {
  write("\n" + get_prompt_str(1) + "\n");
  return 1;
}

nomask void set_retell_message(string str) {
  if(!str)
    ret_msg = 0;
  else
    ret_msg = str;
  return;
}

nomask string query_retell_message() {
  return ret_msg;
}

int do_say(string str) {
  return ((PLAYER + "say")->main(str));
}

int guild_line(string str) {
  return ((PLAYER + "guild")->main(str));
}

void add_standard_commands() {
  if(!real_race)
    real_race = race;
  if(!real_size)
    real_size = size;

  add_action("_filter", "", 1);
  add_action("quit", "quit");
  add_action("do_say", "'", 1);
  add_action("guild_line", "guild/");

  init_expander();
  std_fcn__init();
}

string *query_hit_msg(int tmp, string name, object att, int def) {
  string *m;

  if(guild_soul)
    m=guild_soul->query_hit_msg(tmp, name, att, def);
  if(!m || sizeof(m)!=3)
    return ::query_hit_msg(tmp, name, att, def);
  else
    return m;
}

int wield(string str, int val) {
  if(guild_soul)
    if(guild_soul->dont_wield(str, val))
      return 0;
  return ::wield(str, val);
}

// kind: 1 = say, 2 = tell, 3 = shout, 4 = system
int lcatch_tell(string act, string msg, object who, int kind) {
  if(!who || !interactive(TO) || !ENV(TO)) {
    return 0;
  }

  if(query_editing(TO))
    return 0;
  if(kind != 1 && TO->query_earmuff_level()>who->LVL)
    return 0;
  if(kind == 3 && TO->query_noshouts())
    return 0;

  return (::lcatch_tell(act, msg, who, kind));
}

int allowed_attack(object at_whom) {
  if(funcall(call, at_whom, "query_player") && at_whom!=TO) {
    if(funcall(call, at_whom, "query_level")>5 && TO->LVL>5)
      return (::allowed_attack(at_whom));
    else
      return 0;
  }
  return (::allowed_attack(at_whom));
}

#endif // __P_GENERAL_C__

