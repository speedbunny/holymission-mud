/*================================ SLIP ====================================*/

int main (string arg){
  object item, victim;
  int success;
  string what, whom;

success=1;

if (!arg || !(sscanf(arg, "%s to %s",what,whom) == 2))
    return command("help slip");

write("what= "+what+"\nwhom= "+whom);
if(!victim=present(whom,environment(this_player()))){
  write(whom+" is not here.\n");
  return 1;
}

	
  if(item=present(what,this_player())){
    if(!living(item)){
      if(!success&&random(this_player()->query_dex())<random(10)){
        success=-1;
      }
      if(success)
        success=transfer(item,victim); 
        
      switch(success){
      case -1:{
        write("You try to slip the "+what+
              " into "+whom+"'s pocket, but someone might have noticed.\n");
        victim->write("You feel a soft touch on your body.\n"); 
        return 1;
      }
      case 0:{
        write("You slip the "+arg+" into "+whom+"'s pocket quietly.\n");
        return 1;
      }
      case 1:{
        write("You think "+whom+" might notice if you do that.\n");
        return 1;
      }
      case 2..6:{
        write("You cannot slip that into anyone's pocket.\n");
        return 1;
      }
      }
    }
    else{
      write("You cannot slip monsters or players into pockets!\n");
      return 1;
    }
  }
  else{
    write("You don't have a "+ arg +"!\n");
    return 1;
  }
  return 1;
}
