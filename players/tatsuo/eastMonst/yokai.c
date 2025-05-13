// 3-26-97 Kryll : Fixed to work
inherit "obj/monster";
 
object weapon;
#define AO attacker_ob
#define TELL tell_object
#define BS(x)  break_string(x, 79, 0)
 
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
 
  set_name("Hengeyokai");
  set_alias("hengeyokai");
  set_alt_name("cat");
  set_short("Hengeyokai");
  set_long("The Hengeyokai is a person who is cursed with "+
    "the ability to change into a certain animal. This curse "+
    "has been going on for ages and has lasted on certain families "+
    "only.  The Hengeyokai is an average looking man but has "+
    "a appearance that makes him stand out from the rest of "+
    "whiskers growing out of his face and sharp claws on the "+
    "ends of his finger tips. He is a constant wanderer of the lands "+
    "always looking for a cure for his curse.\n");
  set_level(12);
  add_money(300);
  set_hp(400);
  set_wc(10);
  set_gender(1);
  set_ac(6);
  set_ep(85000);
  weapon = clone_object("/players/tatsuo/guild/nweap/kama");
  transfer(weapon,this_object());
  init_command("wield kama");
}
 
init(){
  ::init();
  set_heart_beat(1);
}
 
heart_beat(){
  ::heart_beat();
  if(AO && present(AO, environment()) ) {
    if(!random(5)) {
      TELL(AO, BS("The Hengeyokai hisses very loud and transforms "+
           "into a cat, scratching you into two pieces!"));
      say(BS("The Hengeyokai hisses very loud at "+AO->query_name()+
          " and transforms into a cat, scratching the hell out of "+
          this_player()->query_objective()+"!"),AO);
      AO->hit_player(10);
    }
    else if(!random(6)) {
      TELL(AO, BS("The Hengeyokai moves with lightning speed as a "+
           "cat, and slams into you!"));
      say(BS("The Hengeyokai runs past "+AO->query_name()+" and slams "+
          "into "+this_player()->query_objective()+"!"),AO);
      AO->hit_player(20);
    }
  }
}
