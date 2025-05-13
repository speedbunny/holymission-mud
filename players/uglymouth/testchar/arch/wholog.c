// who() rewritten moonie 190893

#define FILTER(x) u=filter_array(users(), x, this_object()); break;

int who(string arg) {
  object *u;
  int i,l,pl,flag,j;
  string line,s,msg;
  if(!arg) {
    u=users();
    msg="====================================================================="
	"==========\n";
  }
  else {
    switch(arg) {
      case "mortal":    FILTER("_mortal");
      case "immortal":  FILTER("_immortal");
      case "male":      FILTER("_male");
      case "female":    FILTER("_female");
      case "incognito": FILTER("_incognito");
      default:          write("Usage: who [mortal/immortal/male/female/"
				"incognito]\n"); return 1; break;
    }
    if(!sizeof(u)) {
      printf("No %s players on Holy Mission currently.\n", arg);
      return 1;
    }
    msg=sprintf("%s players on Holy Mission:\n\n=============================="
	"==================================================\n",
	capitalize(arg));
  }
  u=sort_array(u, "whosort", this_object());
  j=sizeof(u);
  for(i=0;i<j;i++) {
    if(u[i]->query_incognito()) break;
    pl=l;
    l=(int)u[i]->query_level();
    if((pl > 29) && (l <= 29))
      msg+="------------------------------------------------------------------"
	"-------------\n";
    switch(l) {
      case -1..29      : { line = sprintf("[%i]", l); break; }
      case 30          : { line = "[Appr]";           break; }
      case 31..32      : { line = "[New]";            break; }
      case 33..34      : { line = "[Wiz]";            break; }
      case 35          :
      case 37..39      : { line = "[Senr]";           break; }
      case 36	       : { line = "[Retd]";           break; }
      case 40..49      : { line = "[Lord]";           break; }
      case 1000        : { line = "[God]";            break; }
      default          : { line = "[Arch]";           break; }
    }
    if(!(s=(string)u[i]->query_presentation(0)))
      s=capitalize((string)u[i]->query_real_name());
    msg+=sprintf("%-7=s%-72=s\n", line, s);
  }
  /*HERP: i already contains the index of the first incognito */
  if(i<=j)
    for(flag=arg=="incognito";i<j;i++) {
      if(!u[i]->query_incognito())
	continue;
      if(!flag)
	msg+="----------------------------------------------------------------"
	"---------------\nIncognito:\n";
      flag=1;
      msg=sprintf("%s       %s\n", msg, (string)u[i]->query_presentation(1));
    }
  msg=sprintf("%s============================== %i players online ============"
	"==================\n", msg, j);
/*
  write(msg);
*/
  write_file("/players/uglymouth/testchar/arch/wholog.log",
    ctime(time()) + " Log done by " + this_player()->query_short_name()
    + ".\n" + msg);
  write("Done.\n");
  return 1;
}

status _mortal(object ob)    { return (int)ob->query_level()<30;  }
status _immortal(object ob)  { return (int)ob->query_level()>29;  }
status _male(object ob)      { return (int)ob->query_gender()==1; }
status _female(object ob)    { return (int)ob->query_gender()==2; }
status _incognito(object ob) { return (int)ob->query_incognito(); }

status whosort(object p1, object p2) { 
  return p1->query_incognito() ? 1 : p2->query_incognito() ? 0 :
	(int)p1->query_level() < (int)p2->query_level();
}
