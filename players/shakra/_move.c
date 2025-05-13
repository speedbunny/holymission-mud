string s1,s2;
object ob,ob2;

int cmd_move(string str){

  if(!str){
    write("Usage: Move <object> to <wizard>  1  \n");
    return 1;
  }

  sscanf(str,"%s to %s",s1,s2);

  if(!s1){
    write("Usage: Move <object> to <wizard>  2  \n");
    return 1;
  }

  if(!s2){
    write("Usage: Move <object> to <wizard>  3  \n");

    return 1;
  }

  if(!(ob2=present(s1,this_player()))){
    write("Failed.\n");
    return 1;
  }

  ob = find_player(s2);

  if(!ob){
    write("That player is not currently loged on.\n");
    return 1;
  }

  if(ob && ob2){
    move_object(ob2,ob);
    write("Moved "+capitalize(s1)+" to "+capitalize(s2)+".\n");

    return 1;
  }

}
