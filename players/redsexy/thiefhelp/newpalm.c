/*================================ Palm ====================================*/

int main (string arg){
  object item;
  int success, noticed;

  if(!arg){
    write("What would you like to palm?\n");
    return 1;
  }
  if(item=present(arg,environment(this_player()))){
    if(!living(item)){
      success=transfer(item,this_player());
      if(!success&&random(this_player()->query_dex())<random(10)){
        success=-1;
      }
      switch(success){
      case -1:{
        write("You try to palm the "+arg+
              " but you think someone might have noticed.\n");
	say(this_player()->query_name()+" tries to sneak "+arg+
            " into "+this_player()->
        return 1;
      }
      case 0:{
        write("You palm the "+arg+" while no one is looking.\n");
        return 1;
      }
      case 1:{
        write("That is too heavy to pick up right now.\n");
        return 1;
      }
      case 2..6:{
        write("You cannot get that.\n");
        return 1;
      }
      }
    }
    else{
      write("You cannot palm monsters or players!\n");
      return 1;
    }
  }
  else{
    write(capitalize(arg)+" is not present!\n");
    return 1;
  }
  return 1;
}
        



