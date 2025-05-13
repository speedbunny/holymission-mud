inherit "/obj/thing";

#include <lw.h>
#include "/players/matt/defs.h"

int voted;
string sender,topic,*choice_array,choice;
object master;

status read(string arg) {
  int i;
  if(id(arg)) {
    write("You read the ballot. It says:\n\n");
    printf("This is a ballot, sent to you by %s.\n",CAP(sender));
    write("The issue to be voted on is as follows: \n");
    writelw(sprintf("%s\n",topic));
    if(sizeof(choice_array)) {
      write("Possible choices are:\n");
      for(i=0;i<sizeof(choice_array);i++)
        printf("  #%d - %s\n",(i+1),choice_array[i]);
    }
    if(!voted) {
      write("To vote on your choice, just type \"vote <choice>\"\n");
      if(sizeof(choice_array))
        write("or \"vote #<number>\".\n");
      write("To abstain but still hear the results, type \"abstain\".\n");
      write("To destroy the ballot, type \"rip ballot\".\n");
      printf("You have %d seconds left to vote.\n",master->query_time());
    }
    else
      printf("You have chosen %s.\n",choice);
    return 1;
  }
}

status vote(string arg) {
  int which;
  if(!voted) {
    if(sizeof(choice_array)) {
      if(sscanf(arg,"#%d",which) &&
         (which<=sizeof(choice_array)) &&
         (which>=1))
        arg=choice_array[which-1];
      else if(member_array(arg,choice_array)==-1) {
        write("That is not one of the choices.\n");
        return 1;
      }
    }
    master->set_vote(arg);
    master->add_hearer(TP->RNAME);
    printf("You choose %s.\n",arg);
    write("Please rip up the ballot if you're done with it.\n");
    voted=1;
    choice=arg;
  }
  else
    printf("You've already chosen %s.\n",choice);
  return 1;
}

status abstain(string arg) {
  if(!arg) {
    if(!voted) {
      write("You abstain.\n");
      write("Please rip the ballot if you're done with it.\n");
      master->set_vote();
      master->add_hearer(TP->RNAME);
      voted=1;
      choice="to abstain";
    }
    else
      printf("You've already chosen %s.\n",choice);
    return 1;
  }
}

int rip(string arg) {
  if(id(arg)) {
    write("You rip up the ballot.\n");
    say(sprintf("%s rips up a ballot.\n",TP->SNAME));
    if(!voted)
      master->set_vote();
    destruct(TO);
    return 1;
  }
}

int dest(string arg) {
  if(id(arg) && !voted && TP->query_immortal())
    master->set_vote();
  return 0;
}

int drop() {
  write("You drop the ballot; it disintegrates.\n");
  say(sprintf("%s drops a ballot, which disintegrates.\n",TP->SNAME));
  if(!voted)
    master->set_vote();
  destruct(TO);
  return 1;
}

int set_choices(string *arg) {
  choice_array=arg;
  return 1;
}

int set_topic(string arg) {
  topic=arg;
  return 1;
}

int set_sender(string str,object obj) {
  sender=str;
  master=obj;
  return 1;
}

int query_vote() {
  return voted;
}

void notify_destruct() {
    if(!voted)
      master->set_vote();
}

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("ballot");
  set_alias("paper");
  set_short("Ballot");
  set_long("This is a voting ballot. You can probably read it.\n");
  set_weight(0);
}

void init() {
  ::init();
  add_action("read",    "read");
  add_action("vote",    "vote");
  add_action("abstain", "abstain");
  add_action("rip",     "rip");
}
