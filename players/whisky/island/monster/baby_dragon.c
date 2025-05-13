
inherit "obj/monster"; 

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {
    set_name("baby dragon");
    set_alias("dragon");
    set_race("dragon"); 
    set_short("A baby Dragon"); 
    set_long("You see a little baby dragon\n"+ 
               "happily playing around.\n");
    set_level(10);
    set_hp(120);
    load_a_chat(20,({
      "The little dragon hits you with its claw\n", 
      "The dragon cries: Papa help me\n"}));
    set_dead_ob(this_object()); 
    move_object(clone_object("players/whisky/island/obj/tail"),
    this_object()); 
    move_object(clone_object("players/whisky/island/obj/baby_skin"),
    this_object());
    init_command("wield tail"); 
}
}

monster_died(ob) {   
  tell_room(environment(),"Suddenly you feel a strong wind, and the sky gets dark.\n"+
        "You feel that you should now leave that place as fast as you can.\n");
  move_object(clone_object("players/whisky/island/monster/lord"),
            environment(this_object()));
  return 0;
 }
init() {
  ::init();
   add_action("fear","fear");
  }

fear(str) {
  write("You make BOOO but nothing happens.\n");
    return 1;
   }
