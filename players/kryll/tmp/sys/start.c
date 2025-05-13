#ifndef __P_START_C__

#define __P_START_C__

#include "player_defs.h"
#include "player_description.h"
#include "player_general.h"
#include "player_guild.h"
#include "player_start.h"
#include "/sys/levels.h"

/*--------------------------------------------------------------------------*/
/* If there is already another player by this name in the game then         */
/* If they are reconnecting throw the other out and exec this one else we   */
/* just start it up and go from there.                                      */
/*--------------------------------------------------------------------------*/
static int try_throw_out(string str) {
  object ob;
  string link_ret;

  if(!other_copy || str=="" || (str[0]!='y' && str[0]!='Y')) {
    write("Come back another time then!\n");
    destruct(T0);
    return 1;
  }
#ifdef LOG_ENTER
  log_file("ENTER", " (throw)\n");
#endif
  if(query_ip_number(other_copy) && other_copy!=TO) {
    TELL(other_copy, "Session called by another connection.\n");
    remove_interactive(other_copy);
    exec(other_copy, TO);
    other_copy->fix();
  }
  else {
    if(other_copy != TO)
      exec(other_copy, TO);
    other_copy->fix();
    if((link_ret = other_copy->query_link_return())) {
      catch(call_other(link_ret, "???"));
      ob = find_object(link_ret);
      TELLR("/room/purgatory", "Suddenly, life appears in "+
            other_copy->NAME + "'s face.\n" +
            other_copy->NAME + " disappears.\n");
    }
    if(!ob)
      ob = find_object(DEF_START);
    other_copy->move_player("X", ob);
  }
  other_copy->notify_reconnect();    /* 921120 Herp */

  if(other_copy != TO)
    destruct(TO);
  return 1;
}

/*--------------------------------------------------------------------------*/
/* This function does ALOT of things.                                       */
/*--------------------------------------------------------------------------*/
static void move_player_to_start3(string where) {
  string pt, *f;
  int    tmp_size, i;
  object ob, purg;

// Find out if there is a me already in the game
  other_copy = find_player(name);
  if(!other_copy && (purg = find_object("/room/purgatory"))) {
    other_copy = present(name, purg);
    if(other_copy) {
      if(!other_copy->LVL || other_copy->query_npc())
        other_copy = 0;
    }
  }
  enable_commands();
// If there is a me in the game then find out if I want to terminate
// the other session or this one
  if(other_copy) {
    write("other_copy: " + file_name(other_copy) +
          " this_object " + file_name(TO) + "\n");
    write("You are already playing!\n");
    write("Throw the other copy out? ");
    input_to("try_throw_out");
    return;
  }

// Initilize the character stats, if not already done.
  if(!stats_is_updated) {
    int tmp;
    tmp = level;
    if(tmp > apwz)
      tmp = apwz;
    set_str(tmp);
    set_int(tmp);
    set_con(tmp);
    set_dex(tmp);
    set_wis(tmp);
    set_chr(tmp);
    stats_is_updated = 1;
  }

// Now we can enter the game. Check tot_value if the game
// crashed, and the values of the player was saved.

  if(!race && !real_race) {
    where = RM->query_room();
  }
  add_standard_commands();

#if 0
  move_object(clone_object("obj/rsoul"), TO);
#endif

  if(tot_value) {
    login_msg += "You find " + tot_value + " coins of your lost money.\n";
    money += tot_value;
    tot_value = 0;
  }
  load_auto_obj(auto_load);

  set_guild(guild);
  if(!IMM) {
    title = GM->query_title(query_guild(), level, query_gender());
    pt = GM->query_pretitle(query_guild(), level, query_gender());
    if(pt && pt!="")
      pretitle = pt;
  }

// Herp expander/speeder/oderwieauchimmer
  reset_expander();
  std_fcn__reset(0);

// sets visibility of character and login message
  if(is_invis && level<apwz)
    set_vis();
  if(is_invis)
    login_msg += "You are invisible (level " + is_invis + ").\n";
  login_msg += (string)"/room/post"->query_mail_string();

// Check if there are new bugreports for this wizard, Cashimor
  if(level > apwz) {
    tmp_size = file_size("/log/" + name + ".rep");
    if(tmp_size > 0) {
      login_msg += "There are ";
      if(bug_file_size < tmp_size) {
        login_msg += "NEW ";
      }
      login_msg += "bug reports in /log/" + name + ".rep.\n";
    }
    bug_file_size = tmp_size;
  }
  if(query_ip_number() != called_from_ip && called_from_ip)
    login_msg += "Your last login was from " + called_from_ip + ".\n";
  called_from_ip = query_ip_number();
  if(!current_path)
    current_path = "players/" + name;
  set_living_name(name);
  fix_short();

  save_object("/p/" + name[0..0] + "/" + name);

  if(start_at_guild)
    where = guild_room;

// every important thing should be done before this one or in the
// check_start_pos func! maybe there is an error in loading the startroom
  call_out("check_start_pos", 1, TO);
  if(where) {
    catch(MOVE(TO, where));
  }
  else
    MOVE(TO, DEF_START);
  set_heart_beat(1);
  return;
}

/*--------------------------------------------------------------------------*/
/* This function is called using input_to, and sets the                     */
/* gender of this player.                                                   */
/*--------------------------------------------------------------------------*/
static void getgender(string str) {
  str = lower_case(str);
  if(str[0] == 'm') {
    write("Welcome, Sir!\n");
    set_male();
  }
  else if(str[0] == 'f') {
    write("Welcome, Madam!\n");
    set_female();
  }
/*
  else if(str[0] == 'o') {
    write("Welcome, Creature!\n");
    set_neuter();
  }
 */
  else {
    write("Sorry, but that is too weird for this game!\n");
    write("Are you, male, female (type m, f): ");
    input_to("getgender");
    return;
  }
  move_player_to_start3(saved_where);
}

/*--------------------------------------------------------------------------*/
/* If the player does not have a sex then let them choose one               */
/* else we will just more on to start position 3                            */
/*--------------------------------------------------------------------------*/
static void move_player_to_start2(string where) {
  if(gender == -1) {
    fix_short();
    write("Are you male or female? ");
    input_to("getgender", 0);
    return;
  }
  move_player_to_start3(where);
  return;
}

/*--------------------------------------------------------------------------*/
/* logon() is called when the players logs on                               */
/* First check where the exec is coming from is legal (secure/login || sys/)*/
/* and restore teh player file, then check to see if this is a wiz or not.  */
/* if I a new char then lets set them up and move them to start, otherwise  */
/* just move them to a start pos.                                           */
/*--------------------------------------------------------------------------*/
void logon(string n, int quiet) {
  string fn;
  int    lv;

// If it is not an exec from secure/login or sys/ then it is illegal
#if 0
  fn = file_name(PO);
  if(fn[0..12]!="secure/login#" && fn[0..3]!="sys/") {
    write("illegal logon: " + fn + "\n");
    log_file("ILLEGAL", "logon != secure/login from " +
             PO->RNAME + " at " + ctime() + ".\n");
    destruct(TO);
    return;
  }
#endif

// Got to have the name from teh login so that we know what player
// file to restore! -Mangla
  name = n;
  login_msg = "\n";

  restore_object("/p/" + name[0..0] + "/" + name);

// If they are a wiz then this will return 1 else they are not.
  if(lv = master_object()->get_wiz_level(name)) {
    if(level == -1) {
      write("Invalid name.\n");
      log_file("LOSTWIZ", "Missing playerfile for wiz " + name +
               ", call from " + query_ip_name() + ", at " +
               ctime() + ".\n");
      destruct(TO);
      return;
    }
    if(level != lv) {
      login_msg += "Your level has changed during your absence!\n"+
                   "You have been " + (level < lv ? "pro" : "de") +
                   "moted to level " + lv + ".\n\n";
      level = lv;
    }
  }
// There is no wiz by this name so must be a player
  else if(level > L_PLAYER) {
    login_msg += "Your level has changed during your absence!\n"+
                 "You have been demoted to player!\n\n";
    level = L_PLAYER;
  }
  if(lv)
    is_wizard = 1;
  else
    is_wizard = 0;
  if(level == 0)
    level = -1;

  time_to_save = age + 500;

  if(!is_wizard)
    incognito = 1;

  dead = ghost;
  set_cap_name();

  local_weight = 0;
  armour_class = 0;

// If this is a new character, we call the adventurers guild
// to get our first title !
  if(level == -1) {
    apwz = L_APPR;
    fwz  = L_NEWWIZ;
#if NEW_RACE
    call_other("room/adv_guild", "advance", 0);
    set_level(1);
    set_str(1);
    set_con(1);
    set_int(1);
    set_dex(1);
    set_wis(1);
    set_chr(1);
    hit_point = max_hp;
    spell_points = -30;
#else
    call_other(NEWBIE_GUILD, "advance", 0);
    set_level(1);
    set_str(18);
    set_con(18);
    set_dex(18);
    set_int(18);
    set_wis(18);
    set_chr(18);
    set_can_update(1);
    hit_point = max_hp;
    spell_points = -30;
#endif
  }

  move_player_to_start2(start_where);
  attacker_ob = 0;
  return;
}

/*--------------------------------------------------------------------------*/
/* compute the auto_load objects that the player has and make the string    */
/* save the player to the /p/<char> hierarchy                               */
/*--------------------------------------------------------------------------*/
void compute_auto_str() {
  object ob;
  string str,tmp;

  auto_load = "";
  ob = first_inventory(TO);
  while(ob) {
    str = call_other(ob, "query_auto_load");
    ob = next_inventory(ob);
    if(!stringp(str) || sscanf(str,"%s^!%s",tmp,tmp)==2)
      continue;
    auto_load = auto_load + str + "^!";
  }
  return;
}

void check_start_pos(object me) {
  object ob;

  if(!ENV(me)) {
    write("\n\nError in loading start room: '" + start_where + "'.\n\n");
    MOVE(me, DEF_START);
  }
  if(!is_linkdead) {
    say(TO->RNAME + " enters the game.\n", 0, TP, "");
    CD->do_chat(-3, sprintf("\n%s just logged on.\n", CAP(name)));
  }

#if 0
  ENV(me)->long();
  ob = first_inventory(ENV());
  while(ob) {
    if(ob != TO) {
      string sh;
      sh = call_other(ob, "short");
      if(sh)
        write(sh + ".\n");
    }
    ob = next_inventory(ob);
  }
#endif
  mylook(0);
  if(login_msg)
    write(login_msg);
  return;
}

void reconnect() {   /* like try_throw_out, but with no other_copy */
  object ob;

  if(link_return) {  /* do we have one anyway ? */
    catch(call_other(link_return, "???"));
    ob = find_object(link_return);
  }
  if(!ob)
    ob = find_object(DEF_START);
  TELLR("room/purgatory", "Suddenly life returns to " + NAME +
        "'s face.\n" + NAME + " disappears.\n");
  MOVEP("X", ob);
  notify_reconnect(1);        /* silent */
  fix();
  return;
}

void time_out() {
  write("Time out.\n");
  destruct(TO);
  return;
}

void dest_ldead() {
  int i;
  object *ob;

  MOVE(TO, "/room/void");
  add_money(tot_value);
  "/room/void"->clean_room(0);
  quit(1);
  return;
}

/* 921120 Herp: we have to remove the destruct-ldead call-out here */

void notify_reconnect(int val) {
  CD->do_chat(-3, sprintf("\n%s just reconnected.\n", CAP(name)));

  if(!val)
    TELL(TO, "Reconnect successful.\n");
  set_heart_beat(1);
  ldead = 0;
  return;
}

int start_in_guild(int val) {
  if(file_name(ENV(TO)) != guild_room)
    return -1;
  start_at_guild = val;
  return val;
}

string start_where() {
  return start_where;
}

#endif // __P_START_C__
