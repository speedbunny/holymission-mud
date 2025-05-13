/*-------------------------------------------------------------------------*/
/* FILE : read_finger.c                                                    */
/*                                                                         */
/* Description : This is the file that is called to read the finger info   */
/*               of a player.                                              */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Jun 12 1997  Kryll        Cleaned up this file. Removed extraneous comments.
 
*/

#include "/sys/levels.h"
#include "/sys/defs.h"
#include <lw.h>
 
#define RM     "race/master"
#define WED    "players/moonchild/wedding/replace_it"
#define FINGER "/players/kryll/test/fingerdata/"
#define ADV    CAP((string)RM->query_adverb(real_race))
 
// prototypes
string lev_title(int val);

// global variables
string   last_ip_name,
         real_life_name,
         plan_msg,
         last_login_time;
string   pretitle,
         title,
         real_al_title,
         race,
         real_race;
int      gender,
         guild,
         level,
         new_mail;
status   allow_show_ip,
         incognito;
status   tp_imm;
 
status read_finger(string str) {
  string m;
  object ob, temp, rsoul;
  int    disguise, disguised;
  mixed  *tmp;
 
  if(strstr(str, "@") != -1)
    return 0;
 
  disguise = 0;
  disguised = 0;
  ob = 0;
  real_life_name = "-";
  plan_msg = 0;
  last_ip_name = "[unknown]";
  last_login_time = "[unavailable]";
  guild = 0;
  allow_show_ip = 0;
  pretitle = title = real_al_title = race = real_race = 0;
  new_mail = 0;

  if(ob = find_player(str)) {
    incognito = ob->query_incognito();
    if(rsoul = present("rsoul", ob)) {
      tmp = (mixed *)rsoul->return_all_rsoul_info();
      real_life_name = tmp[0];
      last_login_time = tmp[1];
      last_ip_name = tmp[2];
      allow_show_ip = tmp[3];
      plan_msg = tmp[4];
    }
  }
  else {
    if(file_size(sprintf("/banish/%s.o", str)) != -1
          || file_size(sprintf("/banish2/%s.o", str)) != -1) {
      printf("The name %s has been banished from Holy Mission.\n", CAP(str));
      return 1;
    }
    restore_object(sprintf("%s%c/%s", FINGER, str[0], str));
  }

  if(!restore_object(sprintf("p/%c/%s", str[0], str))) {
    write("No such player.\n");
    return 1;
  }

  if(!ob)
    restore_object(sprintf("room/post_dir/%s", str));
 
  if(guild == 1){
    if(!read_file("/players/blade/guild/thieves/" + str));
    else {
      sscanf(read_file("/players/blade/guild/thieves/" + str),
             "%s", temp);
      sscanf(temp, "disguised_as= %d\n%s\n", disguise, temp);
      if(disguise != 1)
        disguised = 1;
    }
  }
 
  tp_imm = TP->IMM;
 
  if(!real_race)
    real_race = (race ? race : "unknown");

#if 1
  if(incognito)
    printf("%s the %s\n", CAP(str), CAP(real_race));
  else if(level > L_PLAYER) {
    if(pretitle) {
      if(title)
        printf("%s %s %s\n", pretitle, CAP(str), title);
      else
        printf("%s %s\n", pretitle, CAP(str));
    }
    else if(title)
      printf("%s %s\n", CAP(str), title);
    else
      printf("%s\n", CAP(str));
  }
  else if(pretitle) {
    if(title)
      printf("%s %s the %s %s\n", pretitle, CAP(str), ADV, title);
    else
      printf("%s %s the %s\n", pretitle, CAP(str), ADV);
  }
  else if(title)
    printf("%s the %s %s\n", CAP(str), ADV, title);
  else
    printf("%s the %s\n", CAP(str), ADV);
#else
  writelwnl(incognito
              ? sprintf("%s the %s", CAP(str), CAP(real_race))
              : level > L_PLAYER
              ? pretitle
              ? title
              ? sprintf("%s %s %s", pretitle, CAP(str), title)
              : sprintf("%s %s", pretitle, CAP(str))
              : title
              ? sprintf("%s %s", CAP(str), title)
              : sprintf("%s\n", CAP(str))
              : pretitle
              ? title
              ? sprintf("%s %s the %s %s", pretitle, CAP(str), ADV, title)
              : sprintf("%s %s the %s", pretitle, CAP(str), ADV)
              : title
              ? sprintf("%s the %s %s", CAP(str), ADV, title)
              : sprintf("%s the %s", CAP(str), ADV));
#endif

#if 1
  printf("Race:        %-:14s In real life: %s\n", CAP(real_race),
         real_life_name);
  if(incognito && !tp_imm)
    printf("Level:       %-:14s Guild:        %s\n", "Incognito",
           "Incognito");
  else if(disguised) {
    if(tp_imm) {
      printf("Level:       %-:14s Guild:        %s\n", lev_title(level),
             (CAP((string)GM->query_name(disguise)) + "(Thief)"));
      printf(" Wizzes:  Please do not disclose the identity of\n"+
             "          disguised thieves. Thanks. :) -- Blade.\n");
    }
    else
      printf("Level:       %-:14s Guild:        %s\n", lev_title(level),
             CAP((string)GM->query_name(disguise)));
  }
  else
    printf("Level:       %-:14s Guild:        %s\n", lev_title(level),
           CAP((string)GM->query_name(guild)));
  printf("%s is %s.\n", ({ "It", "He", "She" })[gender],
         ((m=(string)WED->get_spouse(CAP(str))) ?
          sprintf("married to %s", m) : "unmarried"));
  printf("%s mail.\n", (new_mail ? "Unread" : "No unread"));
  printf("%s %s from %s\n", (ob ? "On since" : "Last on at"),
         last_login_time, ((allow_show_ip || tp_imm) ? last_ip_name :
         "Suppressed"));
#else
/* Matt 6-19-94: Changed slightly so wizzes can see hidden info */
  printf("Race:        %-:14s In real life: %s\n"
         "Level:       %-:14s Guild:        %s\n"
         "%s.\n"
         "%s mail.\n"
         "%s\n",
         CAP(real_race), real_life_name,
         (incognito && !tp_imm) ? "Incognito" : lev_title(level),
         (incognito && !tp_imm) ? "Incognito"
            : ((disguised)
            ? ((tp_imm)
            ? (capitalize((string)GM->query_name(disguise))+
                          " (Thief)\n"+ 
                          " Wizzes:  Please do not disclose the identity of\n"
                          "          disguised thieves.  Thanks. :)  -- Blade.")
            : capitalize((string)GM->query_name(disguise)))
            : capitalize((string)GM->query_name(guild))), 
         sprintf("%s is %s", ({ "It", "He", "She" })[gender],
                (m=(string)WED->get_spouse(CAP(str)))
                ? sprintf("married to %s", m)
                : "unmarried"),
         new_mail ? "Unread" : "No unread",
         sprintf("%s %s from %s", ob ? "On since" : "Last on at",
                                  last_login_time,
                                  (allow_show_ip || tp_imm)
                                  ? last_ip_name
                                  : "Suppressed")
                );
#endif
 
  if(ob) {
    if(!interactive(ob))
      printf("Currently netdead.\n");
    else {
      int idl;
      if(idl = (query_idle(ob)/60)) {
        if(idl > 60)
          printf("Idle for %i %s %i %s.\n", idl/60,
                 (idl>119 ? "hours" : "hour"), idl%60,
                 (idl==1 ? "minute" : "minutes"));
        else
          printf("Idle for %i %s.\n", idl, (idl==1 ? "minute" : "minutes"));
      }
    }
    ob->show_age();
  }
  if(plan_msg)
    printf("Plan:\n%s", plan_msg);
  else
    printf("No plan.\n");
  return 1;
}
 
string lev_title(int val) {
  switch(val) {
    case -1..L_PLAYER:         return (string)val;
    case L_APPR..L_NEWWIZ-1:   return "Appr";
    case L_NEWWIZ..L_WIZ-1:    return "NewWiz";
    case L_WIZ..L_SAGE-1:      return "Wizard";
    case L_SAGE..L_RETD-1:     return "Sage";
    case L_RETD..L_ELDER-1:    return "Retd";
    case L_ELDER..L_ARCH-1:    return "Elder";
    case L_ARCH..L_GOD-1:      return "ArchWiz";
    case L_GOD:                return "God";
    default:                   return "Unknown";
  }
}

