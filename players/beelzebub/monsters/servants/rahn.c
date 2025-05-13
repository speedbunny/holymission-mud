
#define TN this_player()->query_name()

inherit "obj/monster";

object staff,armor,ring;

reset(arg){
 ::reset(arg);
  if (arg) return 1;
  set_name("Rahn");
  set_short("Rahn, The Destructor");
  set_long("Anarchy and violence are the hallmarks of this reptilian wizard, ruler of\n"+
           "the outer realm of T'Klom.  His predilection for chaos make him destined to\n"+
           "remain near the bottom of the Netherworlds hierarchy.\n");
  set_race("demon");
  set_alias("rahn");
  set_alt_name("wizard");
  set_level(20);
  set_ac(44);
  set_wc(30);
  set_hp(2000);
  set_size(4);
  set_aggressive(0);
  set_no_ears(1);
  set_prevent_poison(1);
  set_gender(1);
  set_no_steal();
  add_money(1000+random(2000));
  staff=transfer(clone_object("players/beelzebub/weapons/magic_weapons/meteor_staff"),this_object());
  ring=transfer(clone_object("players/beelzebub/obj/titanium_ring"),this_object());
  armor=transfer(clone_object("players/beelzebub/armor/celestial_armor"),this_object());
  init_command("wield staff");
  init_command("wear armor");
}

detect_invis() { return 1; }

attack(){

object *here;
int sz, i;

  if(::attack() && (random(100)<25)){
    here=all_inventory(environment());
    tell_room(environment(), "Rahn raises his staff to the heavens and summons a meteor shower against\n"+
                             "you.\n");
    for(sz = sizeof(here), i=0; i < sz; i++){
      if(living(here[i]) && here[i]->query_race()!="demon"){
        if(here[i] && here[i]->query_invis()) here[i]->set_vis();
        here[i]->catch_tell("You are bombarded by meteors.\n");
        here[i]->hit_player(50+random(51));
      }
    }
   return 1;
   }
 return;
}

hit_player(dam){
  if(random(100) < 20){
    tell_room(environment(),"Rahn swiftly evades the attack of "+TN+"!\n");
    return;
  }
  else if(random(100) < 30){
    tell_room(environment(),"Rahn's magic shield deflects the attack of "+TN+"!\n");
    return;
  }
  else if(random(100) < 40){
    tell_room(environment(),"The attack of "+TN+" passes right through Rahn!\n");
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
    write("Rahn resists your feeble attempt!\n");
    say("Rahn cackles at "+TN+".\n");
    return 1;
  }
}

