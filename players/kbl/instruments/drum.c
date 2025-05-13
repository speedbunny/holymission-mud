inherit "players/kbl/inherit/music";

int ready;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("drum");
    set_short("A death drum");
    set_weight(2);
    set_value(75);
    set_long("This drum seems to be made of a corpse.\n");
    set_write_snd("You make some lugubrious noises.\n");
    set_say_snd("plays some lugubrious noises on a death drum.\n");
    set_2nd_com("bang");
    set_spell(50,5);
  }
}

spell_target(who) {
  if((who==this_player())||(who->query_wizard())) return;
  write("It hurts the ears of "+who->query_name()+"!\n");
  say("It hurts the ears of "+who->query_name()+"!\n");  
  who->hit_player(random(20)+1);
  return;
}

preprocess_spell() {
  if(ready) {
    return;
  }
  ready=1;
  call_out("unready",1);
  ::preprocess_spell();
}

unready() {
  ready=0;
}
