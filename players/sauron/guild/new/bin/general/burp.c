#include "/players/sauron/guild/include/skill_functions.c"

status main(object who,string verb,string str) {
  int res;
  object target;

  if(!check_dark(who) || !check_ghost(who) || !check_cost(who,verb))
    return 1;
 
 if(str)
    sscanf(str,"at %s",str);

  target=check_target(who,verb,str);
  if(!target)
    return 1;

  else {
    res=monk_skill_roll("burp",SIMPLE,30);
    switch(res) {
      case SUCCESS:
        WRITE(sprintf("You successfully burp%s.\n",str?" at "+CAP(str):""));
        break;
      case FAILURE:
        WRITE(sprintf("You fail to burp%s.\n",str?" at "+CAP(str):""));
        break;
      case BOTCH:
        WRITE(sprintf("You throw up%s.\n",str?" over "+CAP(str):""));
        break;
      default:
        WRITE("Hmm weird.\n");
        break;
    }
    return 1;
  }
}
