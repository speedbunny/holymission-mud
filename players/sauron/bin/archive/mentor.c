#include "/sys/levels.h"

int main(string str) {
  string tmp;
  int rd;
  object ob;

  if(!(ob=find_player(str))) {
    notify_fail(capitalize(str)+" is not playing at this time.\n");
    return 0;
  }

  else if((rd=ob->ready_to_wiz())!=ALREADY_WIZ && rd!=READY_TO_WIZ) {
    notify_fail(capitalize(str)+" has no need of a mentor at this \
time.\n");
    return 0;
  }

  else if((tmp=(string)ob->query_mentor())) {
    notify_fail(capitalize(str)+" already has a mentor ("
                               +capitalize(tmp)+").\n");
    return 0;
  }

  else if(!ob->set_mentor()) {
    notify_fail("Odd - that didn't work how it was supposed to.\n");
    return 0;
  }

  else {
    write("You are now the mentor of "+capitalize(str)+".\n");
    tell_object(ob,this_player()->query_real_name(1)+" just agreed to \
be your mentor.\n");
    return 1;
  }
}

string help() {
  return"\
Command:\tmentor <player>\n\
Arguments:\tan on-line player.\n\
See also:\tmentee\n\n\
The mentor command is used to set yourself as the mentor of a player \
who wants to advance to immortality and start coding.\n\
\n\
Be careful, as once set, this cannot be unset, and the setting of mentors \
is logged in /log/MENTOR.\n";
}
