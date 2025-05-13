/*-------------------------------------------------------------------------*/
/* FILE : shout.c                                                          */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              shout to all players who are set to listen. Both versions  */
/*              are currently in here and also an alternative version      */
/*              using social points instead of spell points to avoid       */
/*              useless shouts.                                            */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"
#define USE_SPELL_PTS 1

#ifdef USE_OLD_SHOUT
#define SHOUT_OLD(x) shout(x)
#define SHOUT(x) global_msg = x;\
                 filter_array(users(), "filter", TP)
#endif

#define FROG_SHOUT(frog_name, x) frog_who_shouts = frog_name;\
                                 global_msg = x;\
                                 filter_array(users(), "frog_filter", TP)

private static string global_msg;
private static string frog_who_shouts;

/*--------------------------------------------------------------------------*/
/* filter      will determine if the shout should go through or not         */
/* and is called for every shouts                                           */
/* catch_shout will deliver the message                                     */
/*--------------------------------------------------------------------------*/
int catch_shout(string str) {
  if(TP->LVL >= TO->query_earmuff_level()) {
    TELL(TO, str);
    return 1;
  }
  return 0;
}

string filter(object ob) {
  if(ob == TP)
    return 0;
  if(ob->IMM && ob->query_noshouts())
    return 0;
  return ob->catch_shout(global_msg);
}

/*--------------------------------------------------------------------------*/
/* Wolfi: 20.9.92                                                           */
/* frogs should be able to understand stuff shouted by frogs.               */
/*--------------------------------------------------------------------------*/
int catch_shout_frog(string frog_name, string str) {
  if(TP->LVL >= TO->query_earmuff_level()) {
    if(TO->query_frog())
      TELL(TO, frog_name + " the frog shouts: " + str + ".\n");
    else
      TELL(TO, frog_name + " the frog shouts: Hriibit! Hriibit!\n");
    return 1;
  }
  return 0;
}

string frog_filter(object ob) {
  if(ob == TP)
    return 0;
  return ob->catch_shout_frog(frog_who_shouts, global_msg);
}

-----------

int shout_filter(object ob) {
  if(ob == TP)
    return 0;
  if(ob->query_earmuff_level() > TO->LVL)
    return 0;
  return 1;
}

/* shout_hook! Llort */
void shout_hook(string str) {
  if(TP != this_interactive())
    return;
  log_file("PLAYSHOUTS", CAP(TP->RNAME) + ": " + str + "\n");
  if(!TP->query_frog()) {
#ifdef USE_OLD_SHOUTS
    SHOUT(str);
#endif
  }
  return;
}

int shout_to_all(string str) {
  int i, count, sz;
  object *players;
  string lo_msg, hi_msg;

#if USE_SPELL_PTS
  if(!TP->IMM)
    count = 10;
  if(level > 10)
    count += 10;
  if(level > 20)
    count += 20;
  if(count > max_sp/5)
    count = max_sp/5;
  TP->restore_spell_points(-count);
#else
  TP->restore_social_points(-50);
#endif
  log_file("PLAYSHOUTS", CAP(TP->RNAME) + ": " + str + "\n");
  if(!TP->query_frog()) {
#ifdef USE_OLD_SHOUTS
    SHOUT(TP->NAME + " shouts: " + str + "\n");
#else
    lo_msg = lw(TP->NAME + " shouts: " + str + "\n");
    hi_msg = lw(CAP(TP->RNAME) + " shouts: " + str + "\n");
    players = filter_array(users(), "shout_filter", TP);
    for(i=0, sz=sizeof(players); i<sz; i++) {
      if(players[i] != TP) {
        if(players[i]->LVL < TO->LVL)
          TELL(players[i], lo_msg);
        else
          TELL(players[i], hi_msg);
      }
    }
/*      shout(lw(TP->NAME + " shouts: " + str + "\n")); */
#endif
    writelw("You shout: " + str + "\n");
  }
  else {
    FROG_SHOUT(TP->NAME, str);
    writelw("You shout to all frogs: " + str + "\n");
  }
  return 1;
}

void l_shout(string str) {
#if USE_SPELL_PTS
  if(!IMM)
    TP->restore_spell_points(-20);
#else
  if(!MM)
    TP->restore_social_points(-50);
#endif
  log_file("PLAYSHOUTS", CAP(TP->RNAME) + ": " + str + "\n");

  lshout("shouts:", str + "\n", TP);
  writelw("You shout: " + str + "\n");
  return 1;
}

int main(string str) {
  if(!str) {
    write("Shout what ?\n");
    return 1;
  }

  if(TP->query_ghost()) {
    write("You have no body to shout.\n");
    return 1;
  }

#if USE_SPELL_PTS
  if(TP->query_spell_points() < 0) {
#else
  if(TP->query_social_points() < 50) {
#endif
    write("You are too low on power.\n");
    return 1;
  }

#if 0
  shout_to_all(str);
#else
  l_shout(str);
#endif
  return 1;
}

