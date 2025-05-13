// Guild Room.

#define NUM_STATS	6
#define TPG		this_player()->query_gender()
#define QR		"/room/quest_room"

#define LEGENDS		// Remove when the legends are removed.

inherit  "/room/room";

#include <sys_defs.h>
#include <sys_levels.h>
#include <tune.h>

string   *ds_stats;                
int      gd;                      // guild number

void set_guild(int n) { 
  gd=n; 
  return;
}

int query_guild() { 
  return gd; 
}

// Level advancement for guild members.
// Returns 2 for normal level advancement, 3 for legend level advancement,
// 4 for advancement to immortality, or 1 if advancement failed for any reason.

int do_advance(string arg) {
  string pretitle,title;
  int qneeded,qexp,tot_weight;

  if(gd!=TP->query_real_guild()) {
    write("You don't belong to this guild.\n");
    return 1;
  }
  else if(TP->query_immortal() || TP->LEVEL>L_PLAYER) {
    write("You will have to search for other ways.\n");
    return 1;
  }
  else if(TP->LEVEL>=GM->query_levels(gd)) {
    write("You will have to search for other ways.\n");
    return 1;
  }
  else if(TP->query_exp_perc_lev()<100 &&
          (arg!="wizard" || TP->LEVEL<WIZ_ADV_LVL)) {
    write("You are not ready to advance.\n");
    return 1;
  }

  if(!arg || TP->LEVEL<WIZ_ADV_LVL) {
#ifdef LEGENDS
    if(TP->LEVEL>=L_PLAYER) {
      write("You need to advance to 'wizard' or 'legend' now.\n");
      return 1;
    }
#endif
    TP->set_level(TP->LEVEL+1);

    if(!this_object()->query_own_titles()) {
      pretitle=GM->query_pretitle(gd,TP->LEVEL,TPG);
      if(!stringp(pretitle) || pretitle=="")
        pretitle="none";
      TP->set_pretitle(pretitle);
      title=GM->query_title(gd,TP->LEVEL,TPG);
      if(!stringp(title) || title=="")
        title="none";
      TP->set_title(title);
    }
    write("You are now: "+TP->SHORT+" (level "+TP->LEVEL+").\n");
    return 2;
  }

  switch(arg) {
//--------- legends ------------------------------------------
    case "legend":
#ifdef LEGENDS
      if(TP->LEVEL<L_PLAYER) {
        write("You need to improve your level first.\n");
        return 1;
      }
      else if(!TP->query_legend_level()) {
        TP->set_legend_level(1);
        write("You become legendary!\n");
        shout("A new legend is born!\n");
      }
      else if(TP->query_legend_level()<20) {  // already is a legend
        TP->set_legend_level(TP->query_legend_level()+1);
        write("You become even more legendary!\n");
      }
      else {
        write("You cannot become more legendary.\n");
        return 1;
      }
      pretitle=GM->query_pretitle(gd,TP->LEVEL,TPG,TP->query_legend_level());
      if(!pretitle)
        pretitle="none";
      TP->set_pretitle(pretitle);
      return 3;
#else
      write("We don't have a legend system anymore.\n");
      return 1;
#endif
      break;
//--------- wizards ------------------------------------------
    case "wizard":
      qneeded=QR->count(1);
      if(qneeded) {
        write("You still have to solve "+to_string(qneeded)+
              " compulsary quests.\n");
        return 1;
      }
// Kryll - 10/26/98
// made a change on how the check is made to determine if a player can wiz
//      else if(TP->query_cum_q_points()<600) {
      else if(!QR->query_wizard_quest(TP->query_cum_q_points())) {
        write("You need to quest to gain more knowledge.\n");
        return 1;
      }
      else if(TP->query_age()<518400) {
        write("You are not old enough.\n"+
              "You need to be 12 days old to become and immortal.\n");
        return 1;
      }
      else {
        TP->set_level(L_APPR);
        TP->set_pretitle("none");
        TP->set_title("none");
        write("You are now Appretice Wizard!\n");
        shout("A new wizard has been born!\n");
        log_file("PROMOTE",TP->query_real_name()+" advanced to level "
                           +L_APPR+" on "+ctime()+".\n");
        return 4;
      }
      break;
// -------- level == L_PLAYER but wrong argument -------------
    default:
#ifdef LEGENDS
      write("Do you want to advance to 'wizard' or 'legend'?\n");
#else
      write("Do you want to advance to 'wizard' or just advance?\n");
#endif
      return 1;
      break;
  }
}


/* Mangla: Changed to allow players to list the count instead of
 *         just long, all, and a particular quest.
 * Quest listing
 */

int do_list(string arg) {
  int i;
  if(arg=="all")
    QR->list_all(0);
  else if(arg=="long") 
    QR->list_all(1);
  else if((arg) && sscanf(arg,"%d",i)==1) 
    QR->list(i);
  else 
    QR->count();
  return 1;
}

// joining the guild

int do_join() {  // returns 1 on error, otherwise 0
  if(!gd) {
    write("You can't join the adventurers guild.\n");
    return 1;
  }
  else if(TP->query_real_name()=="guest") {
    write("Sorry, but you have to become a real player to join a guild.\n");
    return 1;
  }
  else if(TP->query_level()>10 && !TP->query_immortal()) {
    write("You cannot change guild over level 10.\n");
    return 1;
  }
  else if(TP->query_guild()==gd) {
    write("But you are already a member here.\n");
    return 1;
  }
  return 0;
}

int query_drop_castle() { 
  return 1; 
} 

void reset(int flag) { 
  ::reset(flag);
  if(!flag) {
    set_light(1);
    ds_stats=explode("Str/Dex/Con/Int/Wis/Chr","/");
  }
  return;
}

void add_init() {
  /* overwrite for extra add_actions */
  return;
}

void init() {
  ::init();
  add_init();
  add_action("do_advance",	"advance");
  add_action("do_list",		"list");
  add_action("do_join",		"join");
  return;
}
