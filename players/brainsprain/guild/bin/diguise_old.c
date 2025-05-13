/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Disguise +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/
int do_disguise(string arg);

int main(string arg){
  string option, option2; 
  object thief;
  
  thief=this_player();
  if (thief->query_invis()){
    write("You must be able to see yourself to put on an "
          + "adequate disguise.\n");
    return 1;
  }

  if ((sscanf(arg, "%s %s", option, option2) != 2) ||
      ((option != "appearance") && (option != "title"))){ 
    command("help disguise", thief);
    return 1;
  }

  if (option == "appearance") {
    thief->setenv("th_xlook", option2);
  }
  
  if (option == "title") {
    if(do_disguise(option2)==2)
      return 1;
    present("thiefsoul",thief)->set_disguise("guild/master"->query_number(option2));
  }
  
  write("You pull some supplies from your case, then apply some make-up,\n"
        + "adjust your stance, and change your mannerisms.\n");
  say(capitalize(thief->query_name()) + 
      " applies some make-up and stands differently.\n"+
      "You can barely recognize "+thief->query_objective()+".\n");
  return 1;
}

int do_disguise(string arg) {
  int             gn, lev, gender;
  string          pretitle, title;
  object thief;
  
  thief=this_player();
  gn = "guild/master"->query_number(arg);
  lev = thief->query_level();
  gender = thief->query_gender();
  
  if (gn==-1 || gn==13){
    write("What guild?\n");
    return 2;
  }

  if (!(pretitle = ("guild/master"->query_pretitle(gn, lev, gender))))
    pretitle = "none";
  if (!(title = ("guild/master"->query_title(gn, lev, gender))))
    title = "none";
  
  thief->set_pretitle(pretitle);
  thief->set_title(title);
  return 1;
}





