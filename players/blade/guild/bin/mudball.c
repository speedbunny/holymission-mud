#define DIR "/players/blade/guild"
/* =============================== Mudball ================================ */
int main(string arg){
  object victim, thief;
  int hit;

  thief=this_player();
  if(thief->query_level()<25){
    write("You do not have the aim required to attempt this trick.\n");
    return 1;
  }

  if(!arg || !(victim = present(arg, environment(thief))) || !living(victim)) {
    write("Mudball whom?\n");
    return 1;
  }  
  if(victim->query_immortal() && thief->query_real_name()!="blade") {
    write("You cannot mudball immortals.\n");
    return 1;
  }
  if(victim->query_mudballed()) {
    write(victim->query_name() + " is already covered with mud.\n");
    return 1;
  }
  
  if(thief->query_spell_points()<150){
    write("You dont have the energy.\n");
    return 1;
  }
  
  hit = thief->query_level()+thief->query_legend_level()*3+thief->query_dex();

  if(random(hit) > 25) {
    clone_object(DIR +"/mudball_shadow")->start_shadow(victim,hit);
    write("You throw a ball of mud at " + victim->query_name() + "!\n");
    tell_object(victim,thief->query_name() +
                " throws a ball of mud at you!\n");
    say(thief->query_name() + " throws a ball of mud at " +
        victim->query_name() + "!\n");
    thief->restore_spell_points(-150);
    return 1;
  }
  else {
    write("You throw a ball of mud at " + victim->query_name() +
          ", but miss!\n");
    tell_object(victim,thief->query_name() +
                " throws a ball of mud at you, but misses!\n");
    say(thief->query_name() + " throws a ball of mud at " +
        victim->query_name() + " but misses!\n");
    return 1;
  }
}









