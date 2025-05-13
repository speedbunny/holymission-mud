/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Steal +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

/*
int set_contest(int conflag) {
  contest=conflag;
  return 1;
}

int query_contest() { return contest; }
     
     int contest() {
       
       object tempobj;
       
       if(contest) {
         tempobj = find_object(PROOM);
         tempobj->contest_status();
         return 1;
       }
       
       else {
         return 0;
    }
}
*/


int main(string arg) {
  
  string          what, whom;
  object          obji, objp, vat_cont, thief;
  int             i, j, ddex, no_steal_level;
  int             coins;
  int             thief_ll;  //thieves legend level
  
/*  if (has_stolen)
    return 1; */
  
  thief=this_player();
  thief_ll = thief->query_legend_level();
  if (thief->query_ghost()) {
    write("You are no longer interested in the material world.\n");
    return 1;
  }
  
  if(thief->query_attack())
    if(present(thief->query_attack(),thief)){
      write("You are much too busy to do that right now.\n");
      return 1;
    }
  
  if (!arg || !(sscanf(arg, "%s from %s", what, whom) == 2))
    return command("help steal");
  if (!(objp = present(whom, environment(thief)))) {
    write("There is no " + whom + " present.\n");
    return 1;
  }
  if (!living(objp)) {
    write("You attempt to steal "+arg+" but aren't very "
          + "effective.\n"); 
    return 1;
  }
  
  if (what == "money")
    what == "coins";
  if (what != "coins" && !(obji = present(what, objp))){
    write(capitalize(whom) + " doesn't posses such an item.\n");
    return 1;
  }
  if (objp->query_immortal()){
    write("You cannot steal from wizards.\n");
    return 1;
  }
  if (objp->query_linkdeath()){
    write("You cannot steal from " + objp->query_name() + ", " +
          objp->query_pronoun() + " is stoned.\n");
    return 1;
  }
  if (what == "bag" && thief->query_dex() <= 25 ){ /* ok if high enough */
    write(objp->query_name()+" would notice if you stole that.\n");
    return 1;
  }
  if (environment(thief)->query_property("no_steal")){
    write("Your stealing would be recognized in this room.\n");
    return 1;
  }
  if (no_steal_level=objp->query_no_steal()){
    if((thief->query_level()+1)/3<no_steal_level){
      write(objp->short() + 
            " doesn't look like one whom you can steal from.\n");
      return 1;
    }
  }
  
    /*
    * Compute the random value according to the following rules: if two
    * players are of the same level, the thief gets a change of 50:50 that
    * he can success in stealing. if the thief is GM->max_levels - 1
    * dex-levels above his victim, he gets a chance of 99 % that he will
    * succeed in stealing.
    */

/*  has_stolen = 1; */
  ddex = (thief->query_dex() - objp->query_dex()) * 50 / 
    ("guild/master"->query_levels(1) - 1) + 50;
  if (random(101) >= ddex){            /* Steal fails */
    say(thief->query_name() + " tried to steal " + what + 
        " from " + objp->query_name() + ".\n", objp);
    write(objp->query_name() + " notices your attempt!\n");
    if (objp->query_npc()){
      write(objp->query_name() + " attacks!\n");
      objp->attack_object(thief);
      return 1;
    }
    tell_object(objp, thief->query_name() + " tried to steal " + 
                what + " from you!\n");
    return 1;
  }
    

// This stays just as it is.  Players have abused a bug long enough,
// now the bug starts abusing them.

  if (what == "back_check"){
   write("You cannot steal the " + what + " from " +
            objp->query_name() + ".\n");
   thief->add_experience( - (2000* ( thief->query_level() +
				    thief->query_legend_level() )));
  return 1;
  }

/* =+= =+= =+= =+= =+= =+= =+= =+= Coins =+= =+= =+= =+= =+= =+= =+= =+= =+= */
  
  if (what == "coins"){
    coins = objp->query_money();
    if (coins > thief->query_level() * 100 + 
        thief->query_legend_level()* 200)
      coins = thief->query_level() * 100 + thief->query_legend_level() * 200;
    if (!coins){
      write(objp->query_name() + " doesn't posess a single coin.\n");
      return 1;
    }
    
    coins = random(coins) + 1;
    thief->add_money(coins);
    objp->add_money(-coins);
    write("You have stolen " + coins + " coins from " + 
          objp->query_name() + ".\n");
    i = random(4);
    if (!thief->query_invis())
      switch (i)
        {
        case 0:
          tell_object(objp, "There is a rustling noise in your purse.\n");
          break;
        case 1:
          tell_object(objp, "You feel your purse getting lighter.\n");
          break;
        case 2:
          tell_object(objp, "You feel a hand in your pocket.\n");
          break;
        case 3:
          tell_object(objp, "You feel a soft touch in your pocket.\n");
          break;
        }
    thief->add_alignment(-25);        /* Thieves are nasty */
    return 1;
  }
    
/* =+= =+= =+= =+= =+= =+= =+= =+= Objects =+= =+= =+= =+= =+= =+= =+= =+= */
  
  if (obji->query_wielded(obji)){
    write("You can't steal wielded stuff.\n");
    return 1;
  }
  
  if (obji->query_worn(obji)){
    if(thief->query_legend()==0){
    write("You can't undress " + objp->query_name() + ".\n");
    return 1;
    }
    if(obji->query_weight() > 2){
      write("This object is far to large to steal without being noticed.\n");
      return 1;
    }
  }
  
  if (!(j = transfer(obji, thief))){
    i = random(4);
    if (!thief->query_invis())
      switch (i){
      case 0:
        tell_object(objp, "You feel like you might missing something.\n");
        break;
      case 1:
        tell_object(objp, "You seem to have lost a " + what + ".\n");
        break;
      case 2:
        tell_object(objp, "You feel a soft touch on your body.\n");
        break;
      case 3:
        tell_object(objp, "You are missing a " + what + ".\n");
        break;
      }
    if(obji->query_worn(obji)){
      write("You have slipped "+what+" off of " + objp->query_name()+".\n");
    }
    else
      write("You have stolen " + what + " from " + objp->query_name() + ".\n");
    
/*
    if(contest){
      write(capitalize(what)+" dissapears in a puff of smoke.\n");
      vat_cont= present((thief->query_real_name()+" barrel"),
                find_object(PROOM));
      write(thief->query_real_name()+" barrel\n");
      if(vat_cont){
        write("object moved\n");
        move_object(obji,vat_cont);
      }
    }
*/

    thief->add_alignment(-50);    /* They ARE nasty ... */
    return 1;
  }
  else{
    if (j == 1)
      write("You can't carry any more.\n");
    else
      write("You cannot steal the " + what + " from " + 
            objp->query_name() + ".\n");
    return 1;
  }
}

