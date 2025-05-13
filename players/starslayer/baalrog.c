/* The Baal-Rog, Prince of Demons 
   Created by Airborne  */

#define TP this_player()
#define TN this_player()->query_name()
#define TRN this_player()->query_real_name()

inherit "obj/monster";

object axe,bad,gem;

reset(arg){
 ::reset(arg);
  if (arg) return 1;
  set_name("baal-rog");
  set_short("Baal-Rog the Demon Lord");
  set_long("The Baal-Rog, Prince of Demons.\n"+
	"It towers over you in a awesome pose. The blood dripping from\n"+      
	"its open maw reeks of pain. Somehow you know that its last meal\n"+
 	"did not die a pleasant death. And you are most certain that neither\n"+
        "will you!\n");
   set_race("demon");
   set_alias("baalrog");
   set_alt_name("lord");
   add_money(3000+random(5000));
   set_aggressive(1);
   set_hp(5000);
   set_no_ears(1);
   set_prevent_poison(1);
   set_level(50);
   set_ac(22);
   set_wc(50);
   set_size(5);
   set_gender(1);
   set_dead_ob(this_object());
    axe=transfer(clone_object("players/airborne/weapons/hellfire"),this_object());
    gem=transfer(clone_object("players/airborne/obj/gem"),this_object());
    init_command("wield axe");
}
 
monster_died(ob){
  if(this_player()->query_immortal()) return;
    shout(this_player()->query_name()+" killed the Baal-Rog.\n");
    if(present("badge", this_player())) return;
      bad = clone_object("players/airborne/obj/badge");
      transfer(bad, this_player());
      write("A badge mystically finds its way to you.\n");
      return 0;
}

attack(){

object *here;
int shit, i;
  
  if(::attack() && (random(100)<25)){
    here=all_inventory(environment());
    tell_room(environment(), "The Demon Lord reaches into the depths of the hells and unleashes\nits hellfire about you.\n");
    for(shit = sizeof(here), i=0; i < shit; i++){
      if(living(here[i]) && here[i]->query_race()!="demon"){
        if(here[i] && here[i]->query_invis()) here[i]->set_vis();
        here[i]->catch_tell("You are blasted by hellfire.\n");
        here[i]->hit_player(50+random(51));
      }
    }
   return 1;
   }
 return;
}

hit_player(dam){
  if(random(100) < 30){
    tell_room(environment(),"The Baal-Rog knocks "+TN+" aside with great ease!\n");
    return;
  }  
  else if(random(100) < 50){
    tell_room(environment(),"The Demon Lord parries the attack of "+TN+"\n     with a massive swipe of his claw.\n");
    return;
  }
  else if(random(100) < 70){
    tell_room(environment(),"The Prince of Demons blinds "+TN+" momentarily\n    with a storm of debris kicked up by the wind from its wings.\n");
    return;
  }
  return ::hit_player(dam);
}

init(){
::init();

  add_action("stop_ass", "assassinate");  add_action("stop_ass", "backstab");
  add_action("stop_hold", "freeze");      add_action("stop_hold", "hold");
  add_action("stop_hold", "timestop");    add_action("stop_butt", "headbutt");
  add_action("stop_that", "fireshuriken");
 return;
}

stop_that(who){
  write("The fireshuriken bounces off the Baal-Rog and hits you.\n");
  TP->hit_player(random(20)+10);
  say(TN+" is blasted by "+TP->query_possessive()+" own fireshuriken.\n");
  return 1;
}

stop_ass(who){
  if(id(who)){
    say(environment(), TN+" foolishly tried to sneak an attack at the Baal-Rog.\n");
    write("The Baal-Rog is too big for that.\n");
    return 1;
  }
}

stop_hold(who){
  if(id(who)){
    write("The Baal-Rog resists!\n");
    say("The Baal-Rog laughs at "+TN+".\n");
    return 1;
  }
}

stop_butt(blah){
  if(id(blah)){
    say(environment(), TN+" foolishly tried to head-butt the Baal-Rog.\n");
    write("You head burns as it makes contact.\n");
    this_player()->hit_player(random(5)+1);
    return 1;
  }
}
