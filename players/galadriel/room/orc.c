/* 130593: Ethereal Cashimor: Maybe useful, a default orc... */
inherit "obj/monster";

reset(arg) {
object weapon;
string w_name,alt_name;
int class,value,weight,type;

  ::reset(arg);
  if(!arg) {
    set_name("orc");
    set_alias("dirty crap");
    set_race("orc");
    set_size(3);
    set_level(random(2)+1);
    set_hp(30);
    set_ep(1014);
    set_al(-60);
    set_short("An orc");
    set_long("This is one of the great mass of orcs that swarm this world.\n");
    set_ac(0);
    set_aggressive(1);
    weapon=clone_object("obj/weapon");
    switch(random(3)) {
      case 0:
        w_name="knife";
        class=5;
        value=8;
        weight=1;
        type=2;
        break;
      case 1:
        w_name="curved knife";
        class=7;
        value=15;
        weight=1;
        alt_name="knife";
        type=2;
        break;
      case 2:
        w_name="hand axe";
        class=9;
        value=25;
        weight=2;
        type=1;    
        alt_name="axe";
    }
    weapon->set_name(w_name);
    weapon->set_class(class);
    weapon->set_value(value);
    weapon->set_weight(weight);
    weapon->set_alt_name(alt_name);
    weapon->set_type(type);
    weapon->set_long("This is a real orc "+w_name+", black and blooded.\n");
    transfer(weapon,this_object());
    init_command("wield "+w_name);
  }
}

do_objective() {
object who;
string result;

  who=query_attack();
  if(who) result=who->query_objective();
  if(!result) result="it";
  return(result);
}

do_pronoun() {
object who;
string result;

  who=query_attack();
  if(who) result=who->query_pronoun();
  if(!result) result="it";
  return(result);
}

do_possessive() {
object who;
string result;

  who=query_attack();
  if(who) result=who->query_possessive();
  if(!result) result="its";
  return(result);
}

do_race() {
object who;
string result;

  who=query_attack();
  if(who) result=who->query_race();
  if(!result) result="thing";
  return(result);
}

do_races() {
string tmp,result;

  tmp=do_race();
  result="race/master"->query_plural(tmp);
  if(!result) result="things";
  return(result);
}






