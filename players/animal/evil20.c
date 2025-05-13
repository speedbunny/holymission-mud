object bobcat, money, armour;
 
init()
{
    add_action("east"); add_verb("east");
    add_action("west","west");
}
 
short() { return"The bobcat's guard outpost"; }
 
long() {
         write("The outpost\n" +
         "\n" +
         "    This looks like a guard outpost.\n" +
         "    The guard looks like he does a good job\n" +
         "    as there are bones lying all over the room.\n" +
         "    The tunnel continues to the east here.\n" +
         "    The patch from which you came leads west.\n" +
         "\n");
}
 
extra_reset() {
 
      if (!bobcat || !living(bobcat)) {
         bobcat = clone_object("obj/monster");
         call_other(bobcat, "set_name", "bobcat");
         call_other(bobcat, "set_alias", "cat");
         call_other(bobcat, "set_race", "cat");
         call_other(bobcat, "set_level", 12);
         call_other(bobcat, "set_hp", 275);
         call_other(bobcat, "set_al", -400);
         call_other(bobcat, "set_short", "A wily bobcat");
         call_other(bobcat, "set_ac", 6);
         call_other(bobcat, "set_wc", 16);
         call_other(bobcat, "set_aggressive", 0);
         armour = clone_object("obj/armour");
         call_other(armour, "set_name", "hide");
         call_other(armour, "alt_name", "cat hide");
         call_other(armour, "set_short", "Cat hide");
         call_other(armour, "set_long",
           "This hide looks extremely tough.\n");
         call_other(armour, "set_ac", 2);
         call_other(armour, "set_type", "armor");
         call_other(armour, "set_value", 500);
         call_other(armour, "set_weight", 3);
         transfer(armour, bobcat);
            money = clone_object("obj/money");
            call_other(money, "set_money", random(200));
            transfer(money, bobcat);
         move_object(bobcat, this_object());
            call_other(bobcat, "init_command", "wear armor");
     }
}
 
east()
{
    if (present("bobcat")) {
     write("The bobcat hisses 'make my day punk!'\n");
     return 1;
    }
    call_other(this_player(), "move_player", "east#players/animal/evil2");
    return 1;
}
 
west() {
  call_other(this_player(),"move_player","west#players/animal/evil19");
  return 1;
}
 
reset(arg) {
        extra_reset();
        if(arg) return;
        set_light(1);
}
 
