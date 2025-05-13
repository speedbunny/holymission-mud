#ifndef __P_SCORE_C__

#define __P_SCORE_C__

#include "player_condition.h"
#include "player_defs.h"
#include "player_description.h"
#include "player_general.h"
#include "player_guild.h"
#include "player_score.h"

/*--------------------------------------------------------------------------*/
/* Print out the score of the player. Lists most vital stats.               */
/* Mangla: No masked this becuase I want control! Sounds bad eh?            */
/*--------------------------------------------------------------------------*/
nomask int show_score() {
  int    qexp, exp, adv, aexp;
  string tmp;

  exp = funcall(call, TO, "query_exp_perc_lev");
  if(exp > 99)
    exp = 100;

  write(" " + (short() ? short() : "(" + RNAME + ")") + "\n");
  write(" -------------------------------------------------\n");
  write(" Level                 : " + level + "\n" );
  write(" Experience [% advance]: " + experience + "[" + exp + "]\n");
  write(" Money                 : " + money + " gold coins\n");
  write(" Alignment             : " + al_title +"\n");
  write(" Religion              : " + religion + "\n");
  write(" Guild                 : " + guild_name + "\n");
  write(" Race                  : " + real_race + "\n");
  write(" Size                  : " + sizes[real_size] + "\n");
  if(!attacker_ob) {
    write(" Hit points(max)       : " + hit_point + "("+
                                   TO->query_maxhp() + ")\n");
    write(" Spell points(max)     : " + spell_points + "("+
                                   TO->query_maxsp() + ")\n");
  }
  if(hunter)
    write(" Hunted by             : " + hunter->NAME + ".\n");
  write(" Str: " + TO->STR + " Int: " + TO->INT + " Wis: " + TO->WIS +"\n");
  write(" Dex: " + TO->DEX + " Con: " + TO->CON + " Chr: " + TO->CHR +"\n");

  if(intoxicated || stuffed || soaked || poisoned) {
    tmp = " You are ";

    if(intoxicated) {
      tmp += "intoxicated";
      if(stuffed && soaked)
        tmp += ", ";
      else {
        if(stuffed || soaked || poisoned)
          tmp += " and ";
        else
          tmp += ".\n";
      }
    }

    if(stuffed) {
      tmp += "satiated";

      if(soaked || poisoned)
        tmp += " and ";
      else
        tmp += ".\n";
    }

    if(soaked) {
      tmp += "not thirsty";

      if(poisoned)
        tmp += " and ";
      else
        tmp += ".\n";
    }

    if(poisoned)
      tmp += poisonname[poisoned < MAX_POISON ?
             (poisoned * sizeof(poisonname) / MAX_POISON) :
             sizeof(poisonname) - 1] + " poisoned.\n";
    write(tmp);
  }

  if(whimpy < 0)
    write(" Brave mode!");
  else
    write(" Wimpy : " + whimpy + "%");
  write(env_var["WIMPYDIR"] ? " (" + env_var["WIMPYDIR"] + ")\n " : "\n ");

  write(" ");
  show_age();
  if(query_guild()) {
    write(" Try 'help guild' to get a list of your special abilities.\n");
  }
  return 1;
}

#endif // __P_SCORE_C__
