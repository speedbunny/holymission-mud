#include "/players/sauron/include/include.h"

int main(string str) {
  string *mentees;
  object ob;

  mentees=this_player()->query_mentees();
  if(!str || sscanf(str,"remove %s",str)!=1) {
    if(!sizeof(mentees))
      write("You don't have any mentees.\n");
    else
      printf("You are mentor to: %s\n",list_nicely(mentees,3));
    return 1;
  }
  else if(member_array(str,mentees)==-1) {
    notify_fail(capitalize(str)+" is not your mentee.\n");
    return 0;
  }
  if(!(ob=find_player(str))) {
    notify_fail(capitalize(str)+" is not playing at this time.\n");
    return 0;
  }
  else if((string)ob->query_mentor()==this_player()->query_real_name()) {
    notify_fail(capitalize(str)+" is still your mentee.\n");
    return 0;
  }
  else {
    this_player()->remove_mentee(str);
    return main((string)0);
  }
}

string help() {
  return "\
Command:\tmentee [remove <mentee>]\n\
Arguments:\tnone, or 'remove <mentee>'.\n\
See also:\tmentor\n\
\n\
This command displays a list of your mentees. The optional argument \
'remove <mentee>' can be used to remove a former mentee from your list. \
Please note however that this can only be done if the former mentee is \
online, and an arch has already removed you as their mentor.\n";
}
#include "/players/sauron/include/include.h"

int main(string str) {
  string *mentees;
  object ob;

  mentees=this_player()->query_mentees();
  if(!str || sscanf(str,"remove %s",str)!=1) {
    if(!sizeof(mentees))
      write("You don't have any mentees.\n");
    else
      printf("You are mentor to: %s\n",list_nicely(mentees,3));
    return 1;
  }
  else if(member_array(str,mentees)==-1) {
    notify_fail(capitalize(str)+" is not your mentee.\n");
    return 0;
  }
  if(!(ob=find_player(str))) {
    notify_fail(capitalize(str)+" is not playing at this time.\n");
    return 0;
  }
  else if((string)ob->query_mentor()==this_player()->query_real_name()) {
    notify_fail(capitalize(str)+" is still your mentee.\n");
    return 0;
  }
  else {
    this_player()->remove_mentee(str);
    return main((string)0);
  }
}

string help() {
  return "\
Command:\tmentee [remove <mentee>]\n\
Arguments:\tnone, or 'remove <mentee>'.\n\
See also:\tmentor\n\
\n\
This command displays a list of your mentees. The optional argument \
'remove <mentee>' can be used to remove a former mentee from your list. \
Please note however that this can only be done if the former mentee is \
online, and an arch has already removed you as their mentor.\n";
}
