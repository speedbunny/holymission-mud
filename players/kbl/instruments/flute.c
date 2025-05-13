inherit "players/kbl/inherit/music";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("flute");
    set_short("A beautiful flute");
    set_long("This is a real Bard's Flute!\n");
    set_write_snd("You play on the flute.\n");
    set_say_snd("plays a beautiful tune on a flute.\n");
    set_2nd_com("blow");
    set_spell(50,10);
  }
}

spell_target(who) {

  if(!who->query_attack()) return;
  who->stop_fight();
  who->stop_fight();
  who->stop_hunter(1);
  say(who->query_name()+" suddenly looks very peaceful.\n");
  if(who!=this_player()) {
    write(who->query_name()+ " suddenly looks very peaceful.\n");
  }
}
