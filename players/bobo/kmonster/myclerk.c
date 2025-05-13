inherit "obj/monster";
int pressed;
reset(arg) {
  ::reset(arg);
  if (arg) return;
set_name("armourer");
  set_alias("myclerk");
  set_short("A man");
  set_long("He's the owner of this shop. Maybe you can ask him about his wages.\n");
  set_race("human");
  set_male();
  set_size(3);
  set_level(15);
  set_al(100);
  pressed = 0;
}
init() {
  ::init();
  add_action("ask","ask");
}

ask(str) {
  if(!id(str)) return;
  if(attacker_ob==this_player()) {
     write("The man grin ironically and says: I won't tell you anything.\n");
     say("The man grin ironically and says: I won't tell you anything.\n");
   return 1;
    }
   if(attacker_ob) {
    write("The man says: Sorry, "+this_player()->query_name()+", but I'm busy at the moment. Could you come back later?\n");
  say("The man says: Sorry, "+this_player()->query_name()+", but I'm busy at the moment. Could you come back later ?\n");
    return 1;
  }
  say(this_player()->query_name()+" is talking to the man.\n");
  write("You talk to the man.\nHe replies:\n"+
        "Listen fellow: I can repair boots and gloves and change the size of your armour.\n"+
        "I can tell you my wage when i've done the work.\n"+
        "But it won't be more than 5000 coins.\n");
  return 1;
}

attack() {
  ::attack();
  if(!attacker_ob || pressed) return;
  pressed = 1;
  "players/kelly/rooms/vill/police_office"->alarm("e,n,n,e,e",attacker_ob->query_real_name());
  write("The shopkeeper presses a button under the counter.\n");
  say("The shopkeeper presses a button under the counter.\n");
  return 1;
}

