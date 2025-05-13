int main(string arg) {
  object thief;

  thief=this_player();
  if (!arg){
    command("help reveal", thief);
    return 1;
  }
  
  if(thief->query_attack())
    if(present(thief->query_attack(),thief)){
      write("You are much too busy for that right now.\n");
      return 1;
    }
  
  if(present("thiefsoul",thief)->is_busy(-1)){
    write("You are much too busy for that right now.\n");
    return 1;
  }

  write("You start searching ...\n");
  say(thief->query_name() + " searches the room.\n");
  present("thiefsoul",thief)->is_busy(1);
  call_out("reveal_item", 3, arg, thief);
  return 1; 
}

/* with full dexterity, the probabilty to find an item is 50 %, but there's a
  check against charisma (used as luck) also. */

int reveal_item(string arg, object thief) {
  
  object          ob, sh;
  int             i, chr;

  present("thiefsoul",thief)->is_busy(0);  

  ob = present(arg + "__hidden__", environment(thief));
  if (!ob || environment(thief) != environment(ob)) {
    write("You found nothing.\n");
    return 1;
  }
  
  chr = thief->query_chr();
//  i = random(2 * max_stats);
  i = random(2 * "guild/master"->query_levels(1));
  if (i > thief->query_dex()) {
    /* check for luck */
    if (i <= 2) {
      i = random(100);
      /* 30% max chance */
      if (i < chr)
        i = 1;
      else
        i = 0;
    }
    else
      i = 0;
  }
  else
    i = 1;
  
  if (i) {
    if (ob->hide_shadow())
      ob->end_shadow();
    write("You found " + ob->short() + ".\n");
    say(thief->query_name() + " found something.\n");
    return 1;
  }
  
  write("You found nothing.\n");
  return 1;
}








