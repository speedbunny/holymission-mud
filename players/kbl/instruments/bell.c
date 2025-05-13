inherit "players/kbl/inherit/music";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("bell");
    set_short("A glass bell");
    set_long("This bell feels soft and nice.\n");
    set_write_snd("You sound the bell.\n");
    set_say_snd("sounds a beautiful bell.\n");
    set_2nd_com("sound");
    set_spell(40,4);
  }
}

spell_target(who) {
  who->restore_spell_points(-this_player()->query_level()*2);
  who->heal_self(this_player()->query_level()*2);
  tell_object(who,"You feel healthier now.\n");
}
