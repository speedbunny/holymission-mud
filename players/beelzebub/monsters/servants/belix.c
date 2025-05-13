
#define TN this_player()->query_name()

inherit "obj/monster";

object staff,armor,ring;

reset(arg){
 ::reset(arg);
  if (arg) return 1;
  set_name("Belix");
  set_short("Belix, The Pitiless One");
  set_long("Belix was the first mage to serve the Demon Lord and was rewarded with spells,\n"+
           "powers and riches beyond the dreams of humankind.  Completley consumed by\n"+
           "greed and jealousy, Belix attempted to steal Prish for himself.  When his\n"+
           "master learned of his treachery, he ripped out Belix's eyes and tongue and\n"+
           "implanted a single magic eye in the wizard's forehead, so that he would, in\n"+
           "future, always see what Belix saw.\n");


  set_race("demon");
  set_alias("belix");
  set_alt_name("wizard");
  set_level(40);
  set_ac(44);
  set_wc(30);
  set_hp(4000);
  set_size(4);
  set_aggressive(0);
  set_no_ears(1);
  set_prevent_poison(1);
  set_gender(1);
  set_no_steal();
  add_money(1000+random(4000));
  staff=transfer(clone_object("players/beelzebub/weapons/magic_weapons/gravity_staff"),this_object());
  ring=transfer(clone_object("players/beelzebub/obj/silver_ring"),this_object());
  armor=transfer(clone_object("players/beelzebub/armor/nova_armor"),this_object());
  init_command("wield staff");
  init_command("wear armor");
}

detect_invis() { return 1; }

attack(){

object *here;
int sz, i;

  if(::attack() && (random(100)<30)){
    here=all_inventory(environment());
    tell_room(environment(), "Belix aims his staff at you and drains you of your life force.\n");
    for(sz = sizeof(here), i=0; i < sz; i++){
        if(living(here[i]) && here[i]->query_race()!="demon"){
        if(here[i] && here[i]->query_invis()) here[i]->set_vis();
        here[i]->catch_tell("You are drained.\n");
        here[i]->hit_player(60+random(61));
      }
    }
   return 1;
   }
 return;
}

hit_player(dam){
  if(random(100) < 30){
    tell_room(environment(),"Belix swiftly evades the attack of "+TN+"!\n");
    return;
  }
  else if(random(100) < 40){
    tell_room(environment(),"Belix's magic shield deflects the attack of "+TN+"!\n");
    return;
  }
  else if(random(100) < 50){
    tell_room(environment(),"The attack of "+TN+" passes right through Belix!\n");
    return;
  }
  return ::hit_player(dam);
}

init(){
::init();

  add_action("stop_that", "assassinate"); add_action("stop_that", "backstab");
  add_action("stop_that", "freeze");      add_action("stop_that", "hold");
  add_action("stop_that", "timehold");    add_action("stop_that", "headbutt");
  add_action("stop_that", "disarm");      add_action("stop_that", "melt");
 return;
}


stop_that(who){
  if(id(who)){
    write("Belix resists your feeble attempt!\n");
    say("Belix cackles at "+TN+".\n");
    return 1;
  }
}

