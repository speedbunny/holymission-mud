#define DIR "/players/brainsprain/guild"
/* =============================== Mudball ================================ */
int main(string arg){
  object victim, thief;
  int hit;

  thief=this_player();
  if(!present("thiefsoul",thief)->query_righteous()){
    write("You do not have the aim required to attempt this trick.\n");
    return 1;
  }

  if(!arg || !(victim = present(arg, environment(thief))) || !living(victim)) {
    write("Curse whom?\n");
    return 1;
  }  
  if(victim->query_immortal() && thief->query_real_name()!="brainsprain") {
    write("You cannot curse immortals.\n");
    return 1;
  }
  present("thiefsoul",victim)->set_renegade(1);
  command("spit "+victim->query_real_name(),thief);
  return 1;
}
