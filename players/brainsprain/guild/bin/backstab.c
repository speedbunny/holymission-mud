// 181297: Sauron: Changed 2nd arg to hit_player() so that the
//                 hit is treated as a regular hit.
// Dec 21, 1997: Mangla: Fixed problems introduced by
//              changing the hit_player. Has proper args now and
//              damage is close to level of player on a monster.
//              DO NOT ADJUST THIS DAMAMGE AND HIT WITHOUT CHECKING
//              WITH ME OR TRYING IT OUT YOURSELF.
#include <defs.h>

int arch_exempt() {
  // Mangla placed this in.
  return 1;
}

int main(string arg) {

  object victim, check, thief;
  
  if (!arg) 
    return command("help backstab");

  thief=TP;
  if (!(victim = present(arg, ENV(thief))) || !living(victim)) {
    write("Backstab whom?\n");
    return 1;
  }

  if (victim == TP) {
    write("You should not try to backstab yourself.  " +
          "You might succeed!\n");
    return 1;
  }
  
  if (!(objectp(thief->query_wielded()))){
    write("Your attack would be more potent with a " +
          "weapon in hand.\n");
    return 1;
  }
  
  if(ENV(victim)->query_property("no_fight")) {
    write("You are not allowed to fight in here.\n");
    return 1;
  }
  
  if(thief->query_attack())
    if(present(thief->query_attack(), ENV(thief))){
      write("You are much too busy right now.\n");
      return 1;
    }
  
  if(check = present("thiefsoul",victim))
    if(check->query_righteous()){
      write("You move carefully toward " + victim->NAME +
            " but " + victim->PRO +
            " steps aside, and laughs!\n");
      TELL(victim, CAP(thief->RNAME)+
                  " attempts to sneak behind your back, " +
                  "but you step aside and laugh.\n");
      return 1;
    }
  
  if (!thief->query_invis()) {
    write("You move carefully toward " + victim->NAME +
          " but " + victim->OBJ +
          " notices your approach!\n");
    victim->attack_object(thief);
    victim->attack();
    return 1;
  }
  
  check = present("back_check",victim);
  if (check) {
    if (check->query_stab_it() >= (thief->LEVEL +
                                   thief->DEX)) {
      write(CAP(victim->NAME) +
            " would notice your attempt.\n");
      return 1;
    }
  }
  
  if(present("thiefsoul",thief)->is_busy(-1)){
    write("You are already trying to sneak behind your " +
          "victim's back.\n");
    return 1;
  }
  
  write("You carefully move behind " + victim->query_name() + ".\n");
  present("thiefsoul", thief)->is_busy(1);
  call_out("backstab_it", 0, victim);
  return 1;
}

int backstab_it(object victim) {

  int     dam, experience, vic_is_player;
  float   levs, divide;
  object  checker,thief;

  thief = TP;

  present("thiefsoul",thief)->is_busy(0);
  enable_interactive(thief);
  
  if(victim && ENV(victim) == ENV(thief)) {
    checker = clone_object("/players/brainsprain/guild/obj/back_check");
    checker->set_stab_it(thief->LEVEL + thief->DEX);
    MOVE(checker,victim);
    
    write("You silently strike your victim.\n");
    dam=(((thief->LEVEL + thief->query_legend_level()) *
           (thief->DEX + thief->STR)) +
           random(thief->LEVEL +
                  thief->query_legend_level() * 5) + 75);	
    if(dam >= victim->HP) {
      dam = victim->HP + 1;
/* testing ac is imperitive here, add at a later date */
      write("You plunge your weapon deep into the innards of " +
             victim->NAME + ", instantly killing " +
             victim->OBJ + ".\n");
      say(thief->NAME + " plunges " +
          thief->PRO + " weapon deep into the innards of " +
          victim->NAME + ", instantly killing " +
          victim->OBJ + ".\n");
      
/* Extra computations because misc_hit() doesnt award XP for kills */
/* these computations are straight out of player.c                 */
/* unfortunately, if you call misc_hit or hit_by_spell             */
/* it only awards for the damage done to the monster,              */
/* and not for the kill.                                           */
      
//      victim->misc_hit(dam,7);
//      victim->misc_hit(2,7);
      vic_is_player = victim->query_player();
      victim->hit_player(dam, 2, 13);
      if(vic_is_player)
        log_file("KILLS.PLAYER",
                 "                          command: backstab\n");
      return 1;
    }
    victim->hit_player(dam, 2, 13);
    thief->add_exp(dam);
    return 1;
  }
  write("You can't backstab someone who is not here!\n");
  return 1;
}
