// ------------------------------------------------------------------------
// backstab
// used only by thieves
// kryll
// ------------------------------------------------------------------------

inherit "/abilities/ability";
#include "/spells/spell.h"

void reset(int tick) {
  ::reset(int tick);
  if (tick) return;

  set_name("backstab");
  set_syntax("backstab [opponent]");
  set_speed(NEXT_HB);
  set_guild_allowed(1,1);
  set_kind(AGGRESSIVE);
  set_cost(25);
  set_player_help(
    "This ability allows you to stab your opponent from behind while\n"+
    "you are hidden. It can only be used if you are hidden and if your\n"+
    "opponent isn't aware of the attack. If your attack is successful,\n"+
    "a large amount of damage will be inflicted.");
}

void release(string arg, int act_skill, int max_skill) {
  object oppo;
  int dam,wc;
  string oppo_name,tp_name;

  oppo=check_target(arg);
  if (!oppo)
    return;
  if (!valid_living(oppo))
    return;

  oppo_name=funcall(call,oppo,"query_name");
  tp_name=funcall(call,TP,"query_name");

  if (oppo->query_attack(TP)==TP) {
    write("You try to backstab "+oppo_name+", but "+TPPRO+" remembers your"+
      " last attack, and is on guard.\nYou failed.\n" );
    oppo->attacked_by(TP);
  }
  else if (TP->query_attack() &&
     environment(TP)==environment(TP->query_attack())) {
       write("You cannot backstab somebody while fighting.\n");
  }
  else if (!(TP->query_wielded_weapon(0))) {
    write("You need a weapon in your right hand to backstab somebody.\n" );
    oppo->attacked_by(TP);
  }
  else if (!(TP->is_invis_for(oppo))) {
    write("You opponent has seen you!!! This might end bad ...\n");
    oppo->attacked_by(TP);
  }
  else if (check_success(act_skill,max_skill)) {
    wc=(TP->query_wielded_weapon(0))->weapon_class();
    dam=wc*(random(wc)+1)+act_skill+TP->query_dex()+TP->query_level();
    dam=oppo->hit_player(dam,2);
    TP->add_exp(dam);
    if (TP->query_immortal())
      write("----- effective damage: "+dam+" -----\n");
    if (!oppo || oppo->query_ghost()) {
      write("You thrust your weapon in the back of your opponent,\n"+
        "piercig vital organs and creating a lot of gore and a CORPSE !!!\n");
      say("You suddenly hear a strange noise, blood spilling around and\n"+
        oppo_name+" lies flat on the ground, quivering in spasms.\n");
    }
    else {
      write("You move behind "+oppo_name+" and BACKSTAB "+oppo_name+" !\n");
      tell_object( oppo, "You feel a piercing pain in your spine !!!\n");
      say(tp_name+" BACKSTABS "+oppo_name+" !!!\n", oppo );
    }
  }
  else {
    write("You try to backstab "+oppo_name+", but in the last second\n"+
      oppo->query_pronoun()+" recognizes you and avoids the hit !\n");
    tell_object(oppo, tp_name+" tried to backstab you, but you can avoid"+
      " the hit !\n");
    oppo->attacked_by(TP);
  }
  TP->unhide();
}
// ------------------------------------------------------------------------
// backstab
// used only by thieves
// kryll
// ------------------------------------------------------------------------

inherit "/abilities/ability";
#include "/spells/spell.h"

void reset(int tick) {
  ::reset(int tick);
  if (tick) return;

  set_name("backstab");
  set_syntax("backstab [opponent]");
  set_speed(NEXT_HB);
  set_guild_allowed(1,1);
  set_kind(AGGRESSIVE);
  set_cost(25);
  set_player_help(
    "This ability allows you to stab your opponent from behind while\n"+
    "you are hidden. It can only be used if you are hidden and if your\n"+
    "opponent isn't aware of the attack. If your attack is successful,\n"+
    "a large amount of damage will be inflicted.");
}

void release(string arg, int act_skill, int max_skill) {
  object oppo;
  int dam,wc;
  string oppo_name,tp_name;

  oppo=check_target(arg);
  if (!oppo)
    return;
  if (!valid_living(oppo))
    return;

  oppo_name=funcall(call,oppo,"query_name");
  tp_name=funcall(call,TP,"query_name");

  if (oppo->query_attack(TP)==TP) {
    write("You try to backstab "+oppo_name+", but "+TPPRO+" remembers your"+
      " last attack, and is on guard.\nYou failed.\n" );
    oppo->attacked_by(TP);
  }
  else if (TP->query_attack() &&
     environment(TP)==environment(TP->query_attack())) {
       write("You cannot backstab somebody while fighting.\n");
  }
  else if (!(TP->query_wielded_weapon(0))) {
    write("You need a weapon in your right hand to backstab somebody.\n" );
    oppo->attacked_by(TP);
  }
  else if (!(TP->is_invis_for(oppo))) {
    write("You opponent has seen you!!! This might end bad ...\n");
    oppo->attacked_by(TP);
  }
  else if (check_success(act_skill,max_skill)) {
    wc=(TP->query_wielded_weapon(0))->weapon_class();
    dam=wc*(random(wc)+1)+act_skill+TP->query_dex()+TP->query_level();
    dam=oppo->hit_player(dam,2);
    TP->add_exp(dam);
    if (TP->query_immortal())
      write("----- effective damage: "+dam+" -----\n");
    if (!oppo || oppo->query_ghost()) {
      write("You thrust your weapon in the back of your opponent,\n"+
        "piercig vital organs and creating a lot of gore and a CORPSE !!!\n");
      say("You suddenly hear a strange noise, blood spilling around and\n"+
        oppo_name+" lies flat on the ground, quivering in spasms.\n");
    }
    else {
      write("You move behind "+oppo_name+" and BACKSTAB "+oppo_name+" !\n");
      tell_object( oppo, "You feel a piercing pain in your spine !!!\n");
      say(tp_name+" BACKSTABS "+oppo_name+" !!!\n", oppo );
    }
  }
  else {
    write("You try to backstab "+oppo_name+", but in the last second\n"+
      oppo->query_pronoun()+" recognizes you and avoids the hit !\n");
    tell_object(oppo, tp_name+" tried to backstab you, but you can avoid"+
      " the hit !\n");
    oppo->attacked_by(TP);
  }
  TP->unhide();
}
