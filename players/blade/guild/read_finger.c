#include "/sys/levels.h"
#include <lw.h>

#define RM    "race/master"
#define GM    "guild/master"
#define WED   "players/moonchild/wedding/replace_it"
#define FINGER "players/moonchild/misc/fingerdata/"
#define C     capitalize
#define ADV   C((string)RM->query_adverb(real_race))

string last_ip_name,real_life_name,plan_msg,last_login_time;
string pretitle,title,real_al_title,race,real_race;
int gender,guild,level,new_mail;
status allow_show_ip,incognito;
/* Matt 6-19-94 */
status tp_imm;
string lev_title(int t);

status read_finger(string str) {
  string m;
  object ob, temp;
  int disguise, disguised;
  disguise=0;
  disguised=0;
  if(strstr(str, "@")!=-1)
    return 0;
  ob=0;
  real_life_name="-";
  plan_msg=0;
  last_ip_name="[unknown]";
  last_login_time="[unavailable]";
  guild=0;
  allow_show_ip=0;
  pretitle=title=real_al_title=race=real_race=0;
  new_mail=0;
  if(ob=find_player(str)) {
    object rsoul;
    mixed *tmp;
    /*Herp*/
    incognito=ob->query_incognito();
    if(rsoul=present("rsoul", ob)) {
      tmp=(mixed *)rsoul->return_all_rsoul_info();
      real_life_name=tmp[0];
      last_login_time=tmp[1];
      last_ip_name=tmp[2];
      allow_show_ip=tmp[3];
      plan_msg=tmp[4];
    }
  }
  else {
    if(file_size(sprintf("/banish/%s.o", str))!=-1) {
      printf("The name %s has been banished from Holy Mission.\n", C(str));
      return 1;
    }
    restore_object(sprintf("%s%s", FINGER, str));
  }
  if(!restore_object(sprintf("p/%c/%s", str[0], str))) {        /*931010 HERP*/
    write("No such player.\n");
    return 1;
  }
  if(!ob)

  restore_object(sprintf("room/post_dir/%s", str));

  if(guild == 1){
    if(!read_file("/players/blade/guild/thieves/"+str)) ;
    else{
      sscanf(read_file("/players/blade/guild/thieves/"+str),
             "%s",temp);
      sscanf(temp,"disguised_as= %d\n%s\n",disguise,temp);
      if(disguise!=1) disguised=1;
    }
  }

  /* Matt 5-20-94: Why is this line here??
     incognito=1;
     */
  /* Matt 6-19-94: Added so wizzes can see incognito stuff */
  tp_imm = this_player()->query_immortal();

  if(!real_race) real_race=race ? race : "unknown";
/*Herp's comment: this code is ugly bullshit ! but I guess Moonchild coded
                  it this way cuz he thinks it's cool. Merde ! It's bullshit!
*/

  writelwnl(incognito ? sprintf("%s the %s", C(str), C(real_race))
        : level > 29 ? pretitle ? title ? sprintf("%s %s %s", pretitle, C(str),
        title) : sprintf("%s %s", pretitle, C(str)) : title ? sprintf("%s %s",
        C(str), title) : sprintf("%s\n", C(str)) : pretitle ? title
        ? sprintf("%s %s the %s %s", pretitle, C(str), ADV, title)
        : sprintf("%s %s the %s", pretitle, C(str), ADV) : title
        ? sprintf("%s the %s %s", C(str), ADV, title) : sprintf("%s the %s",
        C(str), ADV));
#if 0
  printf("Race:        %-:14s In real life: %s\nLevel:       %-:14s Guild:"
        "        %s\n%s.\n%s mail.\n%s\n", C(real_race), real_life_name,
        incognito ? "Incognito" : lev_title(level), incognito ? "Incognito"
        : capitalize((string)GM->query_name(guild)), sprintf("%s is %s",
        ({ "It", "He", "She" })[gender], (m=(string)WED->get_spouse(C(str)))
        ? sprintf("married to %s", m) : "unmarried"), new_mail ? "Unread"
        : "No unread", sprintf("%s %s from %s", ob ? "On since" : "Last on at",
        last_login_time, allow_show_ip || this_player()->query_immortal()
        ? last_ip_name : "[suppressed]"));
/* Matt 6-19-94: Changed slightly so wizzes can see hidden info */
#else
  printf("Race:        %-:14s In real life: %s\nLevel:       %-:14s Guild:"
        "        %s\n%s.\n%s mail.\n%s\n", C(real_race), real_life_name,
         (incognito && !tp_imm) ? "Incognito" : lev_title(level),
         (incognito && !tp_imm) ? "Incognito"
         :((disguised)? 
           ((tp_imm)? (capitalize((string)GM->query_name(disguise))+
                       " (Thief)\n"+ 
                       " Wizzes:  Please do not disclose the identity of\n"
                       "          disguised thieves.  Thanks. :)  -- Blade.")
            : capitalize((string)GM->query_name(disguise)))
           : capitalize((string)GM->query_name(guild))), 
         sprintf("%s is %s",
        ({ "It", "He", "She" })[gender], (m=(string)WED->get_spouse(C(str)))
        ? sprintf("married to %s", m) : "unmarried"), new_mail ? "Unread"
        : "No unread", sprintf("%s %s from %s", (ob && !ob->query_implementor())
           ? "On since" : "Last on at",
        last_login_time, allow_show_ip || tp_imm
        ? last_ip_name : "[suppressed]"));
#endif

  if(ob && !ob->query_implementor()) {
    if(!interactive(ob))
      printf("Currently netdead.\n");
    else {
      int idl;
      if(idl=(query_idle(ob)/60)) {
        if(idl>60)
          printf("Idle for %i %s %i %s.\n", idl/60, idl>119 ? "hours" : "hour",
                idl%60, idl==1 ? "minute" : "minutes");
        else
          printf("Idle for %i %s.\n", idl, idl==1 ? "minute" : "minutes");
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

string lev_title(int i) {
  switch(i) {
    case -1..29: return (string)i; break;
    case L_APPR..L_NEWWIZ-1:   return "Appr";    break;
    case L_NEWWIZ..L_WIZ-1:    return "NewWiz";  break;
    case L_WIZ..L_SAGE-1:      return "Wizard";  break;
    case L_SAGE..L_RETD-1:     return "Sage";    break;
    case L_RETD..L_ELDER-1:    return "Retd";    break;
    case L_ELDER..L_ARCH-1:    return "Elder";   break;
    case L_ARCH..L_GOD-1:      return "ArchWiz"; break;
    case 1000:   return "God";     break;
    default:     return "Unknown"; break;
  }
}
