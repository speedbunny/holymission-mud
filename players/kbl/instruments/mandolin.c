inherit "players/kbl/inherit/music";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("mandolin");
    set_short("A strong mandolin");
    set_long("This is a sturdy, well crafted mandolin.\n");
    set_write_snd("You strum an accord on your mandolin.\n");
    set_say_snd("strums a couple of strings on a mandolin.\n");
    set_2nd_com("strum");
    set_spell(60,15);
    set_value(100);
    set_weight(3);
  }
}

spell_target(who) {
object kamer;

  if(who==this_player()) return;
  transfer(who,"players/kbl/guild/dream");
  say(who->query_name()+" leaves to the land of dreams.\n");
  tell_object(who,"You're taken away by the music to the land of dreams.\n");
  write(who->query_name()+" falls away into a dream.\n");
  kamer=environment(this_player());
  call_out("re_turn",this_player()->query_level(),({who,kamer}));
}

re_turn(objects) {
  tell_object(objects[0],"You feel yourself wake up again.\n");
  tell_room(objects[1],objects[0]->query_name()
          + " awakes from the land of dreams.\n");
  move_object(objects[0],objects[1]);
}
