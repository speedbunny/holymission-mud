int main(string arg) {
  object ob, en, sh, thief;
  int inv_lvl;
  
  thief=this_player();
  if (arg)  {
    /* Hide an object. */
    /*    if (this_object()->id(arg)) {
          if (stashed)
          write("Your tools are safely hidden already.\n"); 
          else {
          write("You hide your tools from prying eyes.\n");
          stashed = 1;
          thief->setenv("TH_STASHED", stashed);
          } return 1;
          } 
          */
    
    if (!(ob = present(arg, thief))
        && !(ob = present(arg, environment(thief)))) {
      write("Hide what ?\n");
      return 1;
    }
    
    if (living(ob)) {
      /* Don't hide the living. */
      write(ob->short() + " moves too much to be hidden.\n");
      return 1;
    }
    
    if (ob->id("castle") /* || ob->query_property("no_hide") */ ) {
      write(ob->short() + " is too big to be hidden.\n");
      return 1;
    }
    
    if (environment(ob)==thief && (en=environment(thief)))
      transfer(ob, en);
    
    sh = clone_object("/players/brainsprain/guild/hide_shadow");
    sh->start_shadow(ob,0,"hide_shadow",arg);
    
    say(thief->query_name() + " hides something.\n");
    write("Ok.\n");
    return 1;
  }
  
  /* hide yourself */
  
  if (environment(thief)->query_property("no_hide")) {
    write("You can't find a place to hide here.\n");
    return 1;
  }
  
  if (thief->query_invis()) {
    write("You're already hidden in the shadows.\n");
    return 1;
  }
  
  if (thief->query_ghost()) {
    write("You're already pretty well hidden.\n");
    return 1;
  }
  
  if(thief->query_attack())
    if(present(thief->query_attack(),environment(thief))){
      write("You are too busy right now.\n");
      return 1;
    }
  
  if (!present("thiefsoul",thief)->able_to_hide()) {
    write("You must wait for a while.\n");
    return 1;
  }
  
  write("You hide in the shadows.\n");
  say(thief->query_name() + " leaves suddenly.\n");
  
  inv_lvl = thief->query_level() + 1;
             /* thief->query_dex())/2 + random(10) - 5; */
  if (inv_lvl < 5)
    inv_lvl = 5;
  if ((!random(60 - inv_lvl)) || (thief->query_legend_level()))
    thief->set_invis();
  else
    thief->set_invis(inv_lvl);
  return 1;
}




