inherit "obj/weapon";

object king;

reset(arg) {
  ::reset();
  if(arg) return;
  set_name("longsword");
  set_alias("trollslayer");
  set_id("trollslayer"); /* Airborne - Fix error in the quest. */
  set_alt_name("sword");
  set_short("The legendary longsword Trollslayer");
  set_long("This sword has carved runes all down its long blade.\n"
	+ "It is devastatingly powerful when used against trolls.\n");
  set_read("You cannot decipher the runes, but they look to be runes of power.\n");
  set_class(15);
  set_weight(4);
  set_value(10000);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  if(attacker->id("troll king")) {
    if(random(40)) {
      write("The sword bites deep into the trollish foe.\n");
      return 5 + random(11);
    }
    else {
    king=attacker;
    call_out("dest",1,0);
    return 0;
    }
  }
  if(attacker->id("troll") || attacker->query_race()=="troll" && attacker->query_npc()) {
    write("The sword bites deep into the trollish foe.\n");
    return 5 + random(6);
  }
  if(attacker->query_race()=="troll") {
    write("The sword bites deep into the trollish foe.\n");
    return random(6);
  }
}

dest() {
#if 1
    if(interactive(environment()) && environment()->query_immortal())
        tell_object(environment(), "king == /"+file_name(king)+"\n");
    while(king)
        king->hit_player(1000000);
  
    tell_room(environment(this_player()),
              "The sword launches itself at the Troll King, ripping \
its head off,\nbefore mysteriously vanishing through a rift in the \
fabric of space.\n");
    call_out("dest2", 1, 0);
#else
  king->hit_player(1000000);
  tell_room(environment(this_player()),"The sword launches itself at the Troll King, ripping its head off,\n"
	+ "before mysteriously vanishing through a rift in the fabric of space.\n");
  call_out("dest2",1,0);
#endif
}

dest2() {
  wielded_by->stop_wielding();
  destruct(this_object());
}

query_quest_item() { return 1; }
