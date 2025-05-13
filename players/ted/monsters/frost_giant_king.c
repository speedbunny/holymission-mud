inherit "obj/monster";
 string chat_str, function, type, match; 
 int done;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  done = 0;
  if(!chat_str) {
   chat_str = allocate(1);
   chat_str[0] =
"The Frost King blows a smoke ring and sends it sailing up to the ceiling.\n";
   function = allocate(2);
   type = allocate(2);
   match = allocate(2);
   function[0] = "say_hello";
   type[0] = "arrives";
   function[1] = "gives";
   type[1] = "gives";
 }
 set_name("frost giant king");
 set_alias("king");
 set_short("Frost Giant King");
 set_race("giant");
 set_long("This is the Frost Giant King. He looks more like your typical father\n"+
"than a king. He is dressed is a bathrobe and is smoking a pipe.\n");
 set_level(19);
 set_ac(12);
 set_hp(1600);
 set_wc(35);
 set_al(-250);
 set_chance(80);
 set_spell_dam(60);
 set_spell_mess1("The Frost Giant King summons a blast of ice bolders!");
 set_spell_mess2("The Frost Giant King blasts you with a hail of ice bolders!");
 load_chat(10, chat_str);
 set_match(this_object(), function, type, match);
}

hit_player(dam) {
  if(file_name(environment(this_object())) == "players/ted/frost/study" && !done) {
    dam = 0;
    do_stuff();
  }
  return ::hit_player(dam);
}

heart_beat() {
  ::heart_beat();
  if(file_name(environment(this_object())) != "players/ted/frost/study"
     && !done && attacker_ob)
    do_stuff();
  if(file_name(environment(this_object())) != "players/ted/frost/false"
     && done && attacker_ob)
    move_object(this_object(), "players/ted/frost/false");
}

do_stuff() {
  object staff, bag, money;
  say("The Frost Giant King makes a magical gesture and disappears!\n");
  move_object(this_object(), "players/ted/frost/false");
  done = 1;
  "players/ted/frost/study"->fking_moved(1);
  set_aggressive(1);
  staff = clone_object("players/ted/weapons/staff_of_striking");
  move_object(staff, this_object());
  bag = clone_object("players/ted/items/bag_of_holding");
  move_object(bag, this_object());
  money = clone_object("obj/money");
  call_other(money, "set_money",random(2000)+3200);
  move_object(money, bag);
  move_object(clone_object("players/ted/items/regen_ring"), this_object());
}

gives(str) {
 string who, what, whom;
 object king_ob, ob;
 if(sscanf(str, "%s gives %s to %s.", who, what, whom) != 3)
   return 1;
 if(whom == "King" || whom == "Giant" || whom == "king" || whom == "giant")
 if (what == "key" ) {
       say("Frost Giant King says: Thank you very much!\n");
       say("Frost Giant King makes a magical gesture and the key is gone!\n");
       say("Frost Giant King says: However, this means you killed my messenger!\n");
       ob = present(what, this_object());
       if(ob) {
	 call_other(ob, "drop");
	 move_object(ob, "players/ted/storage");
       }
   do_stuff();
   return 1;
 }
 write("Frost Giant King says: Thank you.\n");
 return 1;
}

say_hello(str) {
 string who_say;
 if(sscanf(str, "%s arrives.", who_say) == 1) {
 say("The Frost Giant King says: Who are you and what do you want?\n");
 return 1;
 }
}

second_life() {
  "players/ted/frost/study"->fking_moved(0);
  return 0;
}
