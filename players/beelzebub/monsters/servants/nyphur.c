
#define TN this_player()->query_name()

inherit "obj/monster";

object sword,ring;

reset(arg){
 ::reset(arg);
  if (arg) return 1;
  set_name("Nyphur");
  set_short("Nyphur, The Shapechanger");
  set_long("This shapechanging sorceror is the first guardian of the outer realms of\n"+
           "the Netherworld.  He usually takes the form of a giant spider with a human\n"+
           "head, an appearance which strikes fear into the hearts of his opponents.\n"+
           "A vein of pure cruelty makes him a cunning and slippery foe.\n");
  set_race("demon");
  set_alias("nyphur");
  set_alt_name("sorceror");
  set_level(10);
  set_ac(50);
  set_wc(30);
  set_hp(1000);
  set_size(4);
  set_aggressive(0);
  set_no_ears(1);
  set_prevent_poison(1);
  set_gender(1);
  set_no_steal();
  add_money(1000+random(1000));
  sword=transfer(clone_object("players/beelzebub/weapons/magic_weapons/fireball_sword"),this_object());
  ring=transfer(clone_object("players/beelzebub/obj/jade_ring"),this_object());
  init_command("wield sword");
}

detect_invis() { return 1; }

attack(){

object *here;
int sz, i;

  if(::attack() && (random(100)<25)){
    here=all_inventory(environment());
    tell_room(environment(), "Nyphur raises his sword to the heavens and summons a magic fireball against\n"+
                             "you.\n");
    for(sz = sizeof(here), i=0; i < sz; i++){
      if(living(here[i]) && here[i]->query_race()!="demon"){
        if(here[i] && here[i]->query_invis()) here[i]->set_vis();
        here[i]->catch_tell("You are burned by the fireball.\n");
        here[i]->hit_player(50+random(51));
      }
    }
   return 1;
   }
 return;
}

hit_player(dam){
  if(random(100) < 20){
    tell_room(environment(),"Nyphur swiftly evades the attack of "+TN+"!\n");
    return;
  }
  else if(random(100) < 30){
    tell_room(environment(),"Nyphur's magic shield deflects the attack of "+TN+"!\n");
    return;
  }
  else if(random(100) < 40){
    tell_room(environment(),"The attack of "+TN+" passes right through Nyphur!\n");
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
    write("Nyphur resists your feeble attempt!\n");
    say("Nyphur cackles at "+TN+".\n");
    return 1;
  }
}

