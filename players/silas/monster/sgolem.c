inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("stone golem");
  set_alias("golem");
  set_short("stone golem");
  set_long("This creature has lived here for many years, undisturbed until you decided to\ncome along. It looks as if he is guarding the western exit from intruders and\nit would be best if you just let him be.\n");
  set_level(15);
  set_al(100);
  set_hp(900);
  set_wc(15);
  set_ac(8);
  set_chance(33);
  set_spell_dam(40);
  set_spell_mess1("The golem smashes its fist upon your head.");
  set_spell_mess2("The golem knocks the wind out of your lungs with a swift punch.");
  set_aggressive(0);
  move_object(clone_object("players/silas/obj/sarundot"),
  this_object());
  init_command("wield sarundot");
  move_object(clone_object("players/silas/obj/diamond"),
  this_object());
  return 1;
}

init() {
 ::init();
 add_action("west","west");
}

west() {
   write("The golem firmly grips your shoulder and pulls you back.\n"+
         "It rumbles: 'Sorry, no adventurers allowed.'\n");
   return 1;
}


