inherit "obj/monster";
reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("baby dragon");
    set_alias("dragon");
    set_race("dragon");
    set_short("A baby Dragon");
    set_alt_name("baby");
    set_size(2);
    set_long("You see a little baby dragon happily playing.\n");
    set_level(10);
    set_hp(120);
    load_a_chat(20,({
      "The little dragon hits you with its claw\n",
      "The dragon cries: Papa help me\n"}));
    set_dead_ob(this_object());
}

int monster_died(object ob) {
  tell_room(environment(),"Suddenly you feel a strong wind, and the sky "+
            "gets dark.\n"+
            "You think you should leave that place as fast as you can!\n");
  move_object(clone_object("players/emerald/island/obj/lord"),
            environment(this_object()));
  return 0;
}
