#include "/players/sauron/guild/include/skill_functions.c"

status init_check(object who,string verb,string str) {
  if(!check_dark(who) || !check_ghost(who) || !check_cost(who,verb))
    return 0;
  if(str)
    sscanf(str,"at %s",str);

  if(!check_target(who,verb,str))
    return 0;
  else {
    write("You start to concentrate.\n");
    return 1;
  }
}

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
    res=monk_skill_roll("fart",STRESS,60);
    switch(res) {
      case SUCCESS:
        WRITE(sprintf("You successfully fart%s.\n",str?" at "+CAP(str):""));
        break;
      case FAILURE:
        WRITE(sprintf("You fail to fart%s.\n",str?" at "+CAP(str):""));
        break;
      case BOTCH:
        WRITE(sprintf("You poop %s.\n",str?"over "+CAP(str):"your pants"));
        break;
      default:
        WRITE("Hmm weird.\n");
        break;
    }
    return 1;
  }
}
