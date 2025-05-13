#ifndef __P_GUILD_C__

#define __P_GUILD_C__

#include "player_defs.h"
#include "player_description.h"
#include "player_general.h"
#include "player_guild.h"
#include "/sys/levels.h"

int query_guild() {
  return guild;
}

nomask int query_real_guild() {
  return guild;
}

/*--------------------------------------------------------------------------*/
/* query_exp_perc_lev: will return the percentage you are to being able to  */
/*     advance to the next level.                                           */
/* query_exp_next_level: finds out how much is needed for the next level    */
/*--------------------------------------------------------------------------*/
nomask int query_exp_next_level() {
  int ne, rc;

  ne = 0;

  if(level < L_PLAYER)
    ne = funcall(call, GM, "query_exp", guild, level+1);
  if(ne <= 0)
    rc = funcall(call, GM, "query_exp", guild, L_PLAYER+1);
  else
    rc = ne;
  if(!rc)
    rc = 1;
  return rc;
}

nomask int query_exp_perc_lev() {
#if 0
  int exp, help;

  exp = TO->query_exp() ;
  if(exp > 20000000)
    help = to_int( (100.0*(float)exp)/(float)query_exp_next_level() );
  else
    help = (100 * exp) / query_exp_next_level();
#else
  int help;

  help = (100 * TO->query_exp()) / query_exp_next_level();
#endif
  return ((help < 1) ? 1 : help);
}

#if 0
// Mangla: I think this is legend level stuff. Will ahve ot check GM
nomask int query_perc_advance_lev() {
  int hc, hq, fu, fd, qmal;

  hc = query_exp_perc_lev();
  hq = query_qexp_perc_lev();

  qmal = ( 2 * (100 - hq) * level ) / 29;

  if ( hc > 1000 ) hc = 1000;
  if ( hq > 230 )  hq = 230;
  if ( hq < 1 )    hq = 1;

  fu = hc * hq * hq * 40;
  fd = (10000000 / (hc * hc)) * (hq * hq + hc * hc + 2 * hc * hq) / hq + 1;

  return( (fu/fd) - qmal );
}
#endif

nomask int set_guild(int val) {
  string str;
  int lvl, i;
  object ob;

#if 0
  write("set_guild " + val + "\n");
#endif

  if(!intp(val)) {
    write("Non numeric value to set_guild(): " + val + "\n");
    return 1;
  }
  if(i<0 || val>=GM->query_nog()) {
    write("illegal guild value to set_guild(): " + val + "\n");
    return 1;
  }

//new player
  if(level == -1)
    lvl = 1;
  else
    lvl = level;

// Calculate the quest points now
  convert_quests();
  calc_quests();

// Changing the guild requires to remove the old soul.
  if(guild && guild!=val && (ob=present(GM->query_id(guild), TO))) {
    ob->guild_changes();
    destruct(ob);
  }

// 161093 HERP: centralized chat daemon
  CD->remove_chat(TO, guild);           // remove old guild
  CD->add_chat(TO, val);          // add new guild

  if(name != TP->RNAME) {
    log_file("GP", ctime() + " " + name + " guild set to " + val +
                   " by " + TP->RNAME + "\n");
  }
  guild = val;
  guild_name = GM->query_name(val);
  guild_wiz = GM->query_wiz(val);
  guild_room = GM->query_room(val);
  guild_soul = GM->get_soul(val);

  apwz = L_APPR;        // Set wizard levels
  fwz = L_NEWWIZ;

// if (guild_wiz && !is_wizard) {
  if(!is_wizard) {
    str = GM->query_pretitle(guild, lvl, gender);       // pretile
    if(str)
      set_pretitle(str);
    else
      set_pretitle("none");
    str = GM->query_title(guild, lvl, gender);  // title
    if(str)
      set_title(str);
    else
      set_title("none");
  }

  for(i=0; i<NUM_STATS; i++)
    set_stats(i, query_r_stats(i));   /* Adjust max_hp/sp */

  return 1;
}

int add_chat() {
  if(guild)
    return CD->add_chat(TO, guild);
}

nomask object query_guild_soul() { 
  return guild_soul;
}

#endif // __P_GUILD_C__

