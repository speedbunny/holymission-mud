#ifndef __P_HEARTBEAT_C__

#define __P_HEARTBEAT_C__

#include "player_condition.h"
#include "player_defs.h"
#include "player_general.h"
#include "player_group.h"
#include "player_guild.h"
#include "player_heartbeart.h"
#include "player_prompt.h"
#include "player_start.h"

static void heart_beat() {
  int i, achk, sec_att;

  if(ghost)
    return;
  age += 1;
  if(lock_time > 0)
    lock_time--;
  if(age > time_to_save) {
    if(!brief && !is_wizard)
      write("Autosave.\n");
    save_me(1);
    time_to_save = age + 500;
  }
  funcall(call, TO, "chk_all_shadows");

// HERP: Check if the player's link broke
  if(!is_linkdead) {
    if(!interactive(TO)) {
      say("Linkdeath arrives and turns " + TO->RNAME +
          " into a statue of stone.\n", 0, TP,
          "Linkdeath arrives and turns " + INVNAME +
          " into a statue of stone.\n");
      is_linkdead = 1;
      link_return = file_name(ENV(TP));
      TP->MOVEP("into purgatory#room/purgatory");
      CD->do_chat(-3, sprintf("\n%s just went linkdead.\n", CAP(name)));
      set_heart_beat(0);
      ldead = 1;
      return; /* Dont do anything, if linkdead */
    }
  }
  else
    if(query_ip_number()) {
      is_linkdead = 0;
    }
    else
      return; /* Linkdead, don't do any action */
// ende HERP

  if(intoxicated && random(40)==0) {
    switch(random(7)) {
      case 0:
        say(TO->RNAME + " hiccups.\n", 0, TP, INVNAME + " hiccups.\n");
        write("You hiccup.\n");
        break;
      case 1:
        say(TO->RNAME + " seems to fall, but takes a step and recovers.\n", 0,
            TP, INVNAME + " seems to fall, but takes a step and recovers.\n");
        write("You stumble.\n");
        break;
      case 3:
        write("You feel drunk.\n");
        say(TO->RNAME + " looks drunk.\n", 0, TP, INVNAME + " looks drunk.\n");
        break;
      case 5:
        say(TO->RNAME + " burps.\n", 0, TP, INVNAME + " burps.\n");
        write("You burp.\n");
        break;
    }
  }

// No obvious effects of being stuffed or soaked
  if(hit_point<max_hp || spell_points<max_sp || intoxicated
                      || headache || poisoned) {
    time_to_heal -= 1;
    if(time_to_heal < 0) {
      if(headache) {
        headache -= 1;
        if(headache == 0)
          TELL(TO, "You no longer have a headache.\n");
      }
      if((hit_point < max_hp) && !poisoned) {
        hit_point += 1;
        if(intoxicated)
          hit_point += 5;
        if(hit_point > max_hp)
          hit_point = max_hp;
      }
      if((spell_points < max_sp) && !poisoned) {
        spell_points += 1;
        if(intoxicated && !poisoned)
          spell_points += 5;
        if(spell_points > max_sp)
          spell_points = max_sp;
      }
      if(intoxicated) {
        intoxicated -= 1;
        if(intoxicated == 0) {
          headache = max_headache;
          max_headache = 0;
          TELL(TO, "You suddenly get a bad headache for no reason.\n");
          hit_point -= 5;
// Mangla: changed so the headache will not kill you!
          if(hit_point < 0)
            hit_point = 1;
        }
      }
      if(poisoned) {
        poisoned -= 1;
        if(poisoned == 0) {
          TELL(TO, "You feel much better now.\n" +
               "Your system has been cleared of the poison.\n");
        }
        else {
          if(hit_point > 0)
            hit_point -= poisoned;
          if(spell_points > 0)
            spell_points -= poisoned;
          TELL(TO, "You suffer from being poisoned.\n");
          if(hit_point < 0)
            hit_player(1, 7, 0);
        }
      }
      time_to_heal = INTERVAL_BETWEEN_HEALING;
    }
  }

  if(stuffed) {
    if(hit_point < max_hp)
      hit_point++;
    if(spell_points < max_sp)
      hit_point++;
    stuffed--;
  }

  if(soaked)
    if(hit_point < max_hp)
      hit_point++;
    if(spell_points < max_sp)
      hit_point++;
    soaked--;
  }

  if(attacker_ob && ENV(attacker_ob)==ENV(TO)) {
    if(guild_soul)
      guild_soul->recognize_fight();
    write("\n" + get_prompt_str(prompt[7]) + "\n");

    if((achk = TO->attack(hands[0], 0))) {
      i = 1;
      while(i<number_of_arms && achk) {
        if(hands[i]) {
          achk = TO->attack(hands[i], i);
          if(achk && random(200)<Dex+Str)
            achk = TO->attack(hands[0], 0);
        }
        i++;
      }
    }
  }

// this part of code remains for monsters who TOTALY overwrite attack()
  check_wimpy(attacker_ob);

  if(!achk) {           // opponent died or fled !
    attacker_ob = 0;    // no hunter for players !
  }
  if(!query_editing(TO))
    reset_prompt();
}

int second_life() {
#if 1
  object death_mark;
#endif
  int i, x, w, force_enter, sz;
  string who_killed, env_kill;
  string tpn, pon, ek;
  object ob;

  if(TP)
    tpn = TP->RNAME;
  else
    tpn = "NO this_player()";
  if(PO)
    pon = file_name(PO);
  else
    pon = "NO previous_object()";
  if(ENV(TO))
    ek = file_name(ENV(TO));
  else
    ek = "NO environment";

  log_file("SECOND_LIFE", "PO: " + pon + ", TP: " + tpn + ", TO: " + RNAME +
                          ", ENV: " + ek + "\n");

  if(level >= apwz) {
    return illegal_patch("second_life");
    return 1;
  }
  make_scar();
  ghost = 1;
  TELL(TO, "\nYou die.\n" +
           "You have a strange feeling.\n" +
           "You can see your own dead body from above.\n\n");

  force_enter = level > 1 ? 1 : 0;
  while(query_exp_perc_lev()<0 || force_enter) {
    level--;
    x = random(3) + 2;
    for(i=0; i<x; i++) {
      w = random(6);
      if(stats[w]>RM->query_basic_stat(real_race, w) && stats[w]>1)
        stats[w]--;
    }
    TELL(TO, "YOU LOSE A LEVEL!\n");
    force_enter = 0;
  }
  set_savings(level, 1);

  msgin       = "drifts around";
  msgout      = "blows";
  headache    = 0;
  intoxicated = 0;
  stuffed     = 0;
  soaked      = 0;
  hunter      = 0;
  if(!attacker_ob) {
    switch(random(3)) {
      case 0: shout("A black hand takes " + CAP(name) +
                    " with it to the regions of death.\n");
              break;
      case 1: shout("A black shadow joins " + CAP(name) +
                    " with the dead.\n");
              break;
      case 2: shout("Evil laughter is heard as " + CAP(name) +
                    " is taken from this world.\n");
              break;
    }
  }
#ifdef LOG_KILLS
  if(attacker_ob) {
    who_killed = attacker_ob->RNAME + " (" + attacker_ob->LVL + ") ";
  }
  else if(TP) {
    if(TP && interactive(TP))
      who_killed = TP->RNAME + " (" + TP->LVL + ") ";
    else if(living(TP))
      who_killed = TP->NAME + " (" + TP->LVL + ") ";
    else
      who_killed = file_name(TP);
  }
  else if(ENV())
    who_killed = file_name(ENV());
  else
    who_killed = "UNDEFINED!!!";

  if(stringp(who_killed)) {
    if(ENV(TO))
      env_kill = file_name(ENV(TO));
    else env_kill = "no environment!";
      log_file("KILLS", name + "(" + level + ")" + " killed by " + who_killed +
                        "\nat " + ctime(time()) + " in " + env_kill + "\n");
  }
  else {
    log_file("KILLS", name + "(" + level + ")" + " died. " +
                      ctime(time()) + "\n");
    log_file("KILLS.ODD", name + "(" + level + ")" + " died. ");
    log_file("KILLS.ODD", "Poison level: " + poisoned + ".\n");
    if(PO) {
      log_file("KILLS.ODD", "Previous object: " + file_name(PO) + ", ");
      if(living(PO) && !PO->query_npc())
        log_file("KILLS.ODD", "(" + PO->RNAME + "), ");
    }
    else
      log_file("KILLS.ODD", "No previous object, ");
    log_file("KILLS.ODD", "Environment of player: " +
                          file_name(ENV(TO)) + "\nObjects in ENV:\n");
    ob = first_inventory(ENV(TO));
    while(ob) {
      log_file("KILLS.ODD", ob->short() + " [" + file_name(ob) + "]\n");
      ob = next_inventory(ob);
    }
    log_file("KILLS.ODD", "Objects in player:\n");
    ob = first_inventory(TO);
    while(ob) {
      log_file("KILLS.ODD", ob->short() + " [" + file_name(ob) + "]\n");
      ob = next_inventory(ob);
    }
  }
#endif

  attacker_ob = 0;
  grouped = 0;
  if(follow_whom)
    follow(0);
  if(query_followers())
    for(i=0, sz=sizeof(follow_obj); i<sz; i++)
      command("follow", follow_obj[i]);

  return 1;
}

int remove_ghost() {
  if(!ghost)
    return 0;
  TELL(TO, "You feel a very strong force.\n" +
           "You are sucked away...\n" +
           "You reappear in a more solid form.\n");
  /* write -> tell_object changed by Cashimor to be compatible
     with Ted's wand of raising, 111292 */
  say("Some mist disappears.\n");
  say(TO->RNAME + " appears in a solid form.\n",0,TP,
      INVNAME + " appears in a solid form.\n");
  ghost = 0;
  dead = 0;
  spell_points = 5;
  poisoned = 0;       /* we don't want him to die again */
  msgin = "arrives";
  msgout = "leaves";
  save_me(1);
  return 1;
}

#endif // __P_HEARTBEAT_C__

