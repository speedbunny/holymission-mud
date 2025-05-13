#ifndef __P_CONDITION_C__

#define __P_CONDITION_C__

#include "player_condition.h"
#include "player_defs.h"
#include "/sys/levels.h"

nomask int query_invis() {
  return is_invis;
}

int query_vis() {
  return !query_invis();
}

nomask int query_earmuff_level() {
  return earmuff_level;
}

/*--------------------------------------------------------------------------*/
/* This is the earmuff hook. You can set the level of the players to which  */
/* you want to listen to, to one more than your own.                        */
/* This means you can not stop higher level players from shouting to you,   */
/* but you can stop lower levels and your own level.                        */
/* Changed by Ethereal Cashimor for the improved busy function in appr.c    */
/*--------------------------------------------------------------------------*/
nomask int listen_shout(string str) {
  int intlev;

  if(!str || (str=="off")) {
    earmuff_level = 0;
    return earmuff_level;
  }
  intlev = to_int(str);
  if(intlev && intlev<=level+1)
    earmuff_level = intlev;
  return earmuff_level;
}

nomask int test_darkness() {
  if(set_light(0) <= 0)
    return 1;
  return 0;
}

nomask int test_dark() {
  int i;

  if(TP->infravision())
    return 0;
  if(set_light(0) <= 0)
    return 1;
  return 0;
}

nomask int add_weight(int val) {
  int i, max;

  max = (level + query_str()) / 2 + 10;

  i = val + local_weight;
  if(!is_wizard && (i>max || i<0 || ghost))
    return 0;
  local_weight += val;
  return 1;
}

nomask void add_intoxication(int val) {
  if(val < 0) {
    if(-val > intoxicated / 10)
      val = -intoxicated / 10;
  }
  intoxicated += val;
  if(intoxicated < 0)
    intoxicated = 0;
  return;
}

nomask void add_stuffed(int val) {
  if(val < 0) {
    if(-val > stuffed / 10)
      val = -stuffed / 10;
  }
  stuffed += val;
  if(stuffed < 0)
    stuffed = 0;
  return;
}

nomask void add_soaked(int val) {
  if(val < 0) {
    if(-val > soaked / 10)
      val = -soaked / 10;
  }
  soaked += val;
  if(soaked < 0)
    soaked = 0;
}

nomask void add_poison(int val) {         // (pat) consider savings
  if(val <= 0) {         // always allow lowering poison
    poisoned += val;
    if(poisoned < 0)
      poisoned = 0;
  }
  else {
    if(this_interactive())
    log_file("POISON", TO->RNAME + " was poisoned by " +
             this_interactive()->NAME + " (" +
             this_interactive()->RNAME + ") on\n" +
             ctime(time()) + " with value " + val + ".\n");
    switch(do_save(AGGRESSIVE, POISON, 0, 0, 0)) {
      case SAVED:
        if(poisoned >= val)
          poisoned++;
        else
          poisoned = (val/2 > 0 ? val/2 : val);
        break;
      case SAVE_FAILED:
        if(poisoned >= val)
          poisoned += (val>2 ? 2 : val);
        else
          poisoned = val;
        break;
    }
  }
  return;
}

nomask int query_intoxication() {
  return intoxicated;
}

nomask int query_stuffed() {
  return stuffed;
}

nomask int query_soaked() {
  return soaked;
}

nomask int query_poisoned() {
  return poisoned;
}

nomask string is_hunted_by() {
  if(hunter)
    return hunter->NAME;
  else
    return 0;
}

int drink_alcohol(int val) {
  return drink_alco(val);
}

int drink_alco(int val) {
  if(val>0 && intoxicated+val>level*3) {
    write("You fail to reach the drink with your mouth.\n");
    return 0;
  }
  intoxicated += val;

  if(intoxicated < 0)
    intoxicated = 0;
  if(intoxicated == 0)
    write("You are completely sober.\n");
  if(intoxicated > 0 && headache) {
    headache = 0;
    TELL(TO, "Your headache disappears.\n");
  }
  if(intoxicated > max_headache)
    max_headache = intoxicated;
  if(max_headache > 8)
    max_headache = 8;

  return 1;
}

int drink_soft(int val) {
  if(soaked + val > level * 3) {
    write("You can't possibly drink that much right now!\n" +
          "You feel crosslegged enough as it is.\n");
    return 0;
  }

  soaked += val;
  if(soaked < 0)
    soaked = 0;
  if(soaked == 0)
    write("You feel a bit dry in the mouth.\n");

  return 1;
}

int eat_food(int val) {
  if(stuffed + val > level * 3) {
    write("This is much too rich for you right now! " +
          "Perhaps something lighter?\n");
    return 0;
  }

  stuffed += val;
  if(stuffed < 0)
    stuffed = 0;
  if(stuffed == 0)
    write("Your stomach makes a rumbling sound.\n");

  return 1;
}

nomask void set_invis(int val) {
  if(TP == TO) {
    if(!val)
      is_invis = L_PLAYER;
    else
      is_invis = val;
    if(is_invis>level-1 && !TP->query_archwiz())
      is_invis = level - 1;
    if(is_invis < 0)
      is_invis = 0;
  }
  return;
}

void set_vis() {
  if(TP==TO || TP->IMM)
    is_invis = 0;
  return;
}


#endif // __P_CONDITION_C__
