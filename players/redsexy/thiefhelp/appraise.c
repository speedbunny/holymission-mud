/*============================== Appraise ==================================*/

int main(string arg){

  object appraised_ob, thief;
  float mistake;
  int final, true_value;

  thief=this_player();

  if (!(appraised_ob = present(arg, thief))
      && !(appraised_ob = present(arg, environment(thief)))) {
    write("What would you like to appraise?\n");
    return 1;
  }
  
  if(living(appraised_ob)){
    true_value=appraised_ob->query_money();
  }
  else {
    true_value=appraised_ob->query_value();
  }
  mistake=random(40-thief->query_int()) / 100.0;
  final=3*((int)(true_value*mistake));
  final=random(final) - (final / 2);
  final+=true_value;
  
  if(!living(appraised_ob)) {
    write("You think its worth "+final+" coins.\n");
    return 1;
  }
  else {
    printf("You think %s has %d coins.\n",
           appraised_ob->query_pronoun(),final);
    return 1;
  }
}




