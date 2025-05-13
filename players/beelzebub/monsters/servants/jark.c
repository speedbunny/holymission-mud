
#define TN this_player()->query_name()

inherit "obj/monster";

object sword,ring;

reset(arg){
 ::reset(arg);
  if (arg) return 1;
  set_name("Jark");
  set_short("Jark, The Hunter");
  set_long("To the manticores of The Black Plains, Jark is a god.  His control over the\n"+
           "beasts of his domain is such that they will die for him if he commands it.\n"+
           "He seeks neither greater power over nearby realms nor more favor with his\n"+
           "master, for his loyalty is unbounded.\n");
  set_race("demon");
  set_alias("jark");
  set_alt_name("demon");
  set_level(30);
  set_ac(50);
  set_wc(30);
  set_hp(3000);
  set_size(4);
  set_aggressive(0);
  set_no_ears(1);
  set_prevent_poison(1);
  set_gender(1);
  set_no_steal();
  add_money(1000+random(3000));
  sword=transfer(clone_object("players/beelzebub/weapons/magic_weapons/lightning_sword"),this_object());
  ring=transfer(clone_object("players/beelzebub/obj/gold_ring"),this_object());
  init_command("wield sword");
}

detect_invis() { return 1; }

attack(){

object *here;
int sz, i;

  if(::attack() && (random(100)<30)){
    here=all_inventory(environment());
    tell_room(environment(), "Jark raises his sword to the heavens and summons a lightning bolt against \n"+
                             "you.\n");
    for(sz = sizeof(here), i=0; i < sz; i++){
      if(living(here[i]) && here[i]->query_race()!="demon"){
        if(here[i] && here[i]->query_invis()) here[i]->set_vis();
        here[i]->catch_tell("You are electrocuted.\n");
        here[i]->hit_player(60+random(61));
      }
    }
   return 1;
   }
 return;
}

hit_player(dam){
  if(random(100) < 30){
    tell_room(environment(),"Jark swiftly evades the attack of "+TN+"!\n");
    return;
  }
  else if(random(100) < 40){
    tell_room(environment(),"Jarks's magic shield deflects the attack of "+TN+"!\n");
    return;
  }
  else if(random(100) < 50){
    tell_room(environment(),"The attack of "+TN+" passes right through Jark!\n");
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
    write("Jark resists your feeble attempt!\n");
    say("Jark cackles at "+TN+".\n");
    return 1;
  }
}

