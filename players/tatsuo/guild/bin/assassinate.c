// Mangla - I placed this in here to show you
// what happens when you do not use the sys defs
// and do not specifically set your begin and end
// on if/else statements. this is done from an
// auto-formatter.

#include "/include/defs.h"
#include "/players/tatsuo/guild/ndef.h"

int main(string arg) {

  int    failed, damage, chance, wc, oldMonstHP, newMonstHP, holdTime;
  object who;
  string oppoName;

  failed = 0; // Initializing the variable

  if(ENV(TP)->query_property("no_fight")) { 
    printf("This is not a place of violence.\n");
    return 1;
  }

  if(TPL < 22) {
    printf("You lack the knowledge to accomplish this.\n");
    return 1;
  }

  if(!arg) {
    write( "Assassinate whom?\n" );
    return( 1 );
  }

  who = present(arg, ENV(TP));

  if(!who || !living(who) || who->query_ghost()) {
    write("You only can assassinate somebody, who you can see and who is alive.\n" );
    return(1);
  }

  if(TP->SP < ASSASS_COST) {
    printf("You are too weakened to attempt to assassinate.\n");
    return 1;
  }

  if(!(TP->is_invis_for(who))) {
    write("Bad timing!!! You are not camouflaged, this might end bad !!!\n" );
    failed = 1;
  }
  else {
    if(who->query_attack(TP) == TP) {
      write("You try to assassinate " + CAP(who->NAME) +
        ", but " + who->PRO + " remembers your\n" +
        "last attempt, so you fail !!!\n");
      failed = 1;
    }
    else {
      if ((TP->query_attack() && present(TP->query_attack(), ENV(TP)))) {
        write("Assassinate while fighting!? Strange.\n");
        failed = 1;
      }
      else {
        if(!(TP->query_wielded())) {
          write("Without a weapon ? Strange concept ...\n");
          failed = 1;
        }
      }
      if(failed) {
        write("You make some noise and run unprotected into the enemies " +
          "attack !!!\n");
        who->attack_object(TP);
        TP->set_vis();
        return( 1 );
      }

      if(random(who->LEVEL * 2) < ASSASSKILL) {
        oldMonstHP = who->HP;
        wc = TP->query_wielded()->weapon_class();
        oppoName = who->NAME;
        damage = 0;
        if(ASSASSKILL < random(1000)) {
          damage = who->hit_player(who->MAXHP - 1, 2, 13);
        }
        else {
          damage = wc * random((wc + 1) / 2) + TP->DEX * 2 + TP->STR;
          if(damage > who->MAXHP) {
            damage = who->MAXHP - 1;
          }
        }
        if(objectp(who)) {
          damage += who->hit_player(damage, 2);
        }
        TP->restore_spell_points(-ASSASS_COST);
        TP->add_exp(damage);
        TP->set_vis();
        if(TP->query_immortal()) {
          write("----- effective damage of assassinate: " + damage + "\n");
        }

        if(!who) {
          write("You place your weapon in the back of your opponent,\n" +
                "resulting in a strange noise, a lot of gore and a CORPSE !\n");
          say("You suddenly hear a strange noise, blood spilling around and\n" +
              oppoName + " lies in a flat position, unmoving.\n");
          return( 1 );
        }
        write("You move behind your opponent and ASSASSINATE this creep!!!\n");
        TELL(who, "You feel a piercing pain in your spine !!!\n");
        say(TP->NAME + " moves behind " + who->NAME + " and " +
            "ASSASSINATES this creep !!!\n", who );

        // --- handle the stun
        newMonstHP = who->query_hp();
        holdTime   = ((oldMonstHP - newMonstHP) * 10) / oldMonstHP;
        if(holdTime > 0) {
          holdTime = holdTime > 5 ? 5 : holdTime;
          holdTime++;
          who->hold(TO, holdTime );
          write(who->NAME + " is STUNNED by the sheer power of your hit !!!\n" );
          tell_object(who, "You are stunned by the sheer power of the hit!\n");
          say(who->NAME + " is STUNNED by the sheer power of the hit !\n", who );
          who->stop_fight();
          who->stop_fight();
        }
        "/players/tatsuo/guild/soul"->rm_invis();
        return( 1 );
      }
      else {
        write("You try to assassinate your enemy, but in the last second " + 
          who->PRO + " recognizes you and can avoid the hit.\n"); 
        tell_object(who, CAP(TP->RNAME) + " tried to assassinate you.\n" +
          "But you recognize the attempt and can avoid the hit.\n" );

        who->attack_object(TP);
        TP->set_vis();
        destruct(present("camouflager",TP));
        return( 1 );
      }
      return 1;
    }
  }
}
