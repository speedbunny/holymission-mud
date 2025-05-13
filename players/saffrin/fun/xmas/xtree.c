inherit "/obj/thing";

#include "/players/saffrin/fun/xmas/tree.h"
#define FILE  "/players/saffrin/fun/xmas/tree_names"
#define FILE2 "/players/saffrin/fun/xmas/card_names"
string *names, *cards;

void get_card(object ob) {
  object card;
  if(interactive(ob)) {
    if(file_size(FILE2)!=-1)
      cards=explode(read_file(FILE2),"\n");
    else 
      cards=({});
    if(member_array(CRNAME(ob),cards)==-1) {
      write_file(FILE2,CRNAME(ob)+"\n");
      card=CO(MSCOBJ+"xmas_card");
      MOVE(card,ob);
      TELLO(ob,lw("You are given a Christmas card from The Dark Lord"
                 +" Sauron. Remember to thank him!\n"));
    }
  }
}

void catch_tell(string str) {
  string x;
  if(sscanf(str,"%s enters the game.",x)==1)
    call_out("get_card",1,TP);
}

int decorate_tree(string str) {
  if(file_size(FILE)!=-1)
    names=explode(read_file(FILE),"\n");
  else 
    names=({});
  if(!str || str!="decoration on tree")
    return (int)NF("Hang what on what?\n");
  else if(member_array(CRNAME(TP),names)!=-1) {
    WRITE("You've already hung a decoration on the tree.\n");
    return 1;
  }
  else if(RNAME(TP)=="sauron" || RNAME(TP)=="shaitan" || RNAME(TP)=="saffrin") {
    WRITE("You've already hung a decoration on the tree.\n");
    return 1;
  }
  else {
    write_file(FILE,CRNAME(TP)+"\n");
    WRITE("You select a nice decoration from the box at the foot of the \
tree and hang it on a branch.\n");
    say(lw(CRNAME(TP)+" takes a decoration from the box at the foot of the \
tree and hangs it from a branch.\n"));
    return 1;
  }
}

int kill_tree(string str) {
  if(str=="tree") {
    WRITE("Leave the poor Christmas tree alone - what has it done to you?"
         +" If you want to take out your aggression on something, go kill"
         +" a monster.\n");
    return 1;
  }
}

void long() {
  string l;
  int i;
  l="Before you stands a large Christmas tree. It has a plethora"
   +" of green branches, all covered with sparkling baubles, shiny"
   +" tinsle and many other beautiful decorations. There is a long"
   +" string of multi-coloured, flashing lights wrapped several"
   +" times around the tree from top to bottom. You notice that"
   +" several players have added a decoration to the tree. Each"
   +" one has their name on it: there is one each for ";
  if(file_size(FILE)!=-1)
    names=explode(read_file(FILE),"\n");
  else 
    names=({});
  for(i=0;i<sizeof(names)-1;i++) {
    l+=(string)names[i];
    l+=", ";
  }
  l+="Shaitan and Sauron. At the foot of the"
    +" tree there is a box full of decorations. Maybe you could"
    +" 'hang decoration on tree' yourself.\n";
  WRITE(l);
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    id("xmas_tree");
    set_name("A tall Christmas Tree");
    set_alias("tree");
    set_short("A tall Christmas Tree");
    set_weight(1);
    set_value(0);
    set_can_get(0);
    MOVE(TO,"/room/church");
    enable_commands();
  }
}

void init() {
  ::init();
  add_action("decorate_tree","hang");
  add_action("kill_tree","crush");
  add_action("kill_tree","prison");
  add_action("kill_tree","death");
  add_action("kill_tree","fireshuriken");
}
