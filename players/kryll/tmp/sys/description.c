#ifndef __P_DESCRIPTION_C__

#define __P_DESCRIPTION_C__

#include "player_defs.h"
#include "player_description.h"
#include "player_general.h"
#include "/sys/levels.h"

string query_msgin() {
  return msgin;
}

string query_msgout() {
  return msgout;
}

string query_mmsgin() {
  return mmsgin;
}

string query_mmsgout() {
  return mmsgout;
}

/*--------------------------------------------------------------------------*/
/* Get the short ofthe player and display it.                               */
/* Some rules follow:                                                       */
/*     If invis to the person then do not return anything.                  */
/*     If linkdead then return short as "A statue of stone..."              */
/*     If frog or ghost the list as such                                    */
/*     If they are afk then show it                                         */
/*     If inputting then show that one also                                 */
/*--------------------------------------------------------------------------*/
varargs string short(string str) {
  string s, *ex, func;
  int    i;

  if(!str) {
    if(!TP || TO->is_invis_for(TP))
      return 0;
    if(is_linkdead)
      return "A statue made of stone, in memoriam " + CAP(TO->RNAME);
    if(ghost)
      return "Ghost of " + CAP(TO->RNAME);
    if(frog)
      return TO->NAME + " the frog";
    if(is_afk())
      return(env_var["SHORT"] + " (afk)");
    else if(query_input_pending(TO) || query_editing(TO))
      return(env_var["SHORT"] + " (input)");
  }
  return env_var["SHORT"];
}

nomask int set_description(string str) {
  if(!str) return 0;
  description = str;
  return 1;
}

nomask void write_description() {
  if(!description)
    write("You have no description.\n");
  else
    writelw("Your description currently is: " + description + "\n");
  return;
}

/*--------------------------------------------------------------------------*/
/* Set the title of the player - Set to nomask to prevent cheating          */
/*--------------------------------------------------------------------------*/
nomask int set_title(string str) {
  if(!stringp(str)) {
    if(stringp(title))
      write("Your title is " + title + ".\n");
    else
      write("You don't have a title.\n");
    return 1;
  }
  if(arg == "none")
    title = "";
  else
    title = str;

  fix_short();
  return 1;
}

/*--------------------------------------------------------------------------*/
/* Set the pre-title for the player, changed to varargs and silent to       */
/* accomodate the replace_it object in the church.                          */
/* Set to nomask to prevent cheating                                        */
/*--------------------------------------------------------------------------*/
nomask varargs int set_pretitle(string str, int val) {
  if(!stringp(str)) {
    if(stringp(pretitle))
      if(!val)
        write("Your pretitle is " + pretitle + ".\n");
    else
      if(!val)
        write("You don't have a pretitle.\n");
    return 1;
  }
  if(str == "none")
    pretitle = "";
  else
    pretitle = str;
  set_cap_name();
  if(!val)
    if(TO->RNAME != TP->RNAME) {
      log_file("Pretitle", ctime() + " " + name + " got pretitle " +
                str + " by " + TP->RNAME + "\n");
    }
  fix_short();
  return 1;
}

/*--------------------------------------------------------------------------*/
/* Show the long desc of the player. If they are a frog, linkdead, or       */
/* a ghost then just show short, else show health, sex, scars               */
/*--------------------------------------------------------------------------*/
nomask void long() {
  string cap_pronoun;

  cap_pronoun = CAP(query_pronoun());
  write(short() + ".\n");
  if(ghost || frog || is_linkdead)
    return;
  if(description)
    writelw(cap_pronoun + " " + description + "\n");
  show_scar();
  write(tell_health(TO) );
  return;
}

string query_al_title() {
  if(stringp(al_title))
    return al_title;
  return "neutral";
}

string query_title() {
  return title;
}

string query_pretitle() {
  return pretitle;
}

/*--------------------------------------------------------------------------*/
/* Update our aligment.                                                     */
/*--------------------------------------------------------------------------*/
nomask void add_alignment(int val) {
  if(!intp(val)) {
    write("Bad type argument to add_alignment.\n");
    return;
  }
  alignment = alignment * 9 / 10 + val;
  al_title  = query_al_string();
  if(level < apwz)
    real_al_title = al_title;
  return;
}

nomask void set_al(int val) {
  if(!intp(val))
    return;
  alignment = val;
  al_title  = query_al_string();
  return;
}

nomask int set_alignment(string str) {
  if(!str) {
    if(real_al_title)
      write("Your alignment is " + real_al_title + ".\n");
    else
      write("You don't have an alignment.\n");
    return 1;
  }
  if(str == "none")
    real_al_title = 0;
  else
    real_al_title = str;
  return 1;
}

nomask string query_alignment_title() {
  return real_al_title;
}

nomask int query_brief() {
  return brief;
}

nomask int toggle_brief() {
  brief = !brief;
  if(brief)
    write("Brief mode.\n");
  else
    write("Verbose mode.\n");
  return 1;
}

/* Here are the routines for handling religion. I hope one likes them */
/* Cashimor, 250192 */
string query_religion() {
  return religion;
}

nomask string query_real_religion() {
  return religion;
}

nomask void set_religion(string str) {
  religion = str;
  return;
}

static void make_scar() {
  if(level < 10)
    return;
  scar |= 1 << random(MAX_SCAR);
  return;
}

static void show_scar() {
  int i, j, first, old_value;
  string *scar_desc, tmp;

  scar_desc = ({ "left leg", "right leg", "nose", "left arm", "right arm",
                 "left hand", "right hand", "forehead", "left cheek",
                 "right cheek" });
  j = 1;
  first = 1;
  old_value = scar;
  while(i < MAX_SCAR) {
    if(scar & j) {
      old_value &= ~j;
      if(first) {
        tmp = TO->NAME + " has a scar on " + POS + " " + scar_desc[i];
        first = 0;
      }
      else if(old_value) {
        tmp+=", " + POS + " " + scar_desc[i];
      }
      else {
        tmp+=" and " + POS + " " + scar_desc[i];
      }
    }
    j *= 2;
    i += 1;
  }
  if(!first)
    writelw(tmp + ".\n");
  return;
}

void set_cap_name() {
  cap_name = CAP(name);
  if(!incognito && pretitle!="")
    cap_name = pretitle + " " + cap_name;
}

nomask void set_incognito(status val) {
  incognito = val;
  fix_short();
  return;
}

nomask status query_incognito() {
  return incognito;
}

static void fix_short() { /* Moonchild 290793 */
  if(incognito)
    env_var["SHORT"]=CAP(name) + (real_race ? " the " +
                     CAP(real_race) : "");
  else
    /* 28-APR-94 Galadriel: added '!= ""' to fix the who list bug */
    env_var["SHORT"]=(pretitle != "" ? pretitle + " " : "") +
                     CAP(name) +
                     (level < L_APPR ? " the " +
                      CAP((string)RM->query_adverb(real_race)) : "") +
                     (title ? " " + title : "");
  return;
}

#endif // __P_DESCRIPTION_C__
