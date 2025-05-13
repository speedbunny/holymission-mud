inherit "obj/weapon";

object darth;

reset(arg) {
  ::reset();
  if(arg) return;
  set_name("longsword");
  set_alias("sword");
  set_id("sword");
  set_alt_name("sword");
  set_short("Just an ordinary sword, or so it appears.");
  set_long("This is an ordinary looking sword but you feel there\n"+
           "is something special about it.\n");
  set_class(15);
  set_weight(4);
  set_value(10000);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  if(attacker->id("darth")) {
    if(random(40)) {
      write("The sword buries itself into Darth.\n");
      return 10000;
    }
    else {
    darth=attacker;
    call_out("dest",1,0);
    return 0;
    }
  }
}

dest() {
  darth->hit_player(1000000, 5);
  tell_room(environment(this_player()),"The sword launches itself at\n"+
        "Darth Vader before mysteriously vanishing through a rift in the\n"+
        "fabric of space.\n");
  call_out("dest2",1,0);
}

dest2() {
  wielded_by->stop_wielding();
  destruct(this_object());
}
