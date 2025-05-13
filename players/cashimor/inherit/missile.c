inherit "obj/weapon";

string ammo_name,what,who;
object ammo,victim;
int firing,ammopower;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_alt_name("missile weapon");
    set_name("bow");
    set_value(50);
    set_weight(1);
    set_class(3);
    /* set_two_handed(); */
  }
}

init() {
  ::init();
  add_action("fire","fire");
}

fire(str) {
  if(firing) {
    write("You're already firing a missile!\n");
    return 1;
  }
  firing=1;
  if(!present(this_object(),this_player())) {
    firing=0;
    return 0;
  }
  if(!sscanf(str,"%s at %s",what,who)==2) {
    firing=0;
    return 0;
  }
  if(what!=ammo_name) {
    write("You can't fire that!\n");
    firing=0;
    return 1;
  }
  call_out("load_ammo",1);
  write("You start firing the bow...\n");
  return 1;
}

load_ammo() {
  if(!wielded) {
    write("You aren't wielding the "+name_of_weapon+"!\n");
    firing=0;
    return;
  }
  ammo=present(what,this_player());
  if(!ammo) {
    write("You don't have any "+ammo_name+"!\n");
    firing=0;
    return;
  }
  if(!ammo->query_number()) {
    write("That's not a good "+ammo_name+"!\n");
    firing=0;
    return;
  }
  call_out("aim_missile",1);
  write("You load the "+name_of_weapon+"...\n");
  say(this_player()->query_name()+" loads a "+name_of_weapon+".\n");
  ammopower = ammo->query_power();
  ammo->reduce_number();
  return;
}

aim_missile() {
  victim=present(who,environment(this_player()));
  if(!victim) {
    write("That person isn't here!\n");
    firing=0;
    return;
  }
  if(!living(victim)) {
    write("That thing isn't alive!\n");
    firing=0;
    return;
  }
  call_out("fire_missile",1);
  write("You aim the "+name_of_weapon+" at "+victim->query_name()+".\n");
  say(this_player()->query_name()+" aims the "+name_of_weapon+" at "
    + victim->query_name()+".\n");
  return;
}

fire_missile() {
  write("Your aim was true!\n");
  say(this_player()->query_name()+" fires the "+name_of_weapon+" at "
    + victim->query_name()+" and hits.\n");
  victim->hit_player(ammopower);
  firing=0;
  return;
}

set_ammo_name(s) {
  ammo_name=s;
}

query_ammo_name() {
  return ammo_name;
}
