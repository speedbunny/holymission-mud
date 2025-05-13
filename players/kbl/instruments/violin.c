inherit "players/kbl/inherit/music";

int ready,damage;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("violin");
    set_short("A small violin");
    set_weight(1);
    set_value(50);
    set_long("It's beautifully red/brown.\n");
    set_write_snd("You make a sharp tone with the violin.\n");
    set_say_snd("makes a sharp tone using a violin.\n");
    set_spell(20,8);
  }
}

spell_target(who) {
  if((who==this_player())||(who->query_wizard())) return;
  if(!damage) return;
  write("It hurts the ears of "+who->query_name()+"!\n");
  say("It hurts the ears of "+who->query_name()+"!\n");  
  who->hit_player(random(50)+1);
  damage=0;
  return;
}

preprocess_spell() {
  if(ready) {
    return;
  }
  ready=1;
  damage=1;
  call_out("unready",1);
  ::preprocess_spell();
}

unready() {
  ready=0;
}
