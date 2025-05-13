inherit "obj/thing";

object entered;
int filled;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("tub");
    set_alias("bath");
    set_short("A wooden tub, used for bathing");
    set_long("It can probably hold two people.\n");
    set_can_get(0);
    entered=allocate(2);
  }
  if(filled==2) {
    tell_room(environment(this_object()),"The water in the tub cools down.\n");
    set_filled(1);
  }
}

init() {
string dest_dir;
int i;

  ::init();
  dest_dir=environment(this_object())->query_room("dest_dir");
  for(i=1;i<sizeof(dest_dir);i+=2) add_action("prevent_move",dest_dir[i]);
  add_action("enter_it","enter");
  add_action("leave_it","leave");
  add_action("empty_it","empty");
}

empty_it(str) {
  if((!str)||(str!="tub")) {
    notify_fail("Empty what?\n");
    return 0;
  }
  if(!filled) {
    notify_fail("But it's empty!\n");
    return 0;
  }
  write("You empty the tub. The water leaves through a hole in the floor.\n");
  say(this_player()->query_name()+" empties the tub. The water leaves \n"
    + "through a hole in the floor.\n");
  filled=0;
  return 1;
}

query_filled() {
  return filled;
}

set_filled(i) {
  filled=i;
  if(i==1) {
    correct_bed();
    if(entered[0]) command("shiver",entered[0]);
    if(entered[1]) command("shiver",entered[1]);
  }
}

long() {

  ::long();
  switch(filled) {
    case 0: write("There is no water in it.\n"); break;
    case 1: write("It's filled with cold water.\n"); break;     
    case 2: write("It's steaming with hot water.\n"); break;
  }
  if(correct_bed()==-1) {
    write(entered[0]->query_name()+" and "+entered[1]->query_name()+" are "
        + "sitting in it.\n");
    return;
  }
  if(entered[0]) {
    write(entered[0]->query_name()+" is sitting in it.\n");
    return;
  }
  if(entered[1]) {
    write(entered[1]->query_name()+" is sitting in it.\n");
    return;
  }
  write("Nobody sits in it.\n");
}

prevent_move() {
  if(query_in_bed(this_player())) {
    write("You'll have to leave the tub for that!\n");
    return 1;
  }
  return 0;
}

leave_it(str) {
int place;

  if((!str)||(str!="tub")) {
    notify_fail("Leave what?\n");
    return 0;
  }
  if(!place=query_in_bed(this_player())) {
    notify_fail("But you're not sitting in the tub!\n");
    return 0;
  }
  write("You leave the tub.\n");
  say(this_player()->query_name()+" leaves the tub.\n");
  entered[place-1]=0;
  return 1;
}

query_in_bed(obj) {
  if(entered[0]==obj) return 1;
  if(entered[1]==obj) return 2;
  return 0;
}

correct_bed() {
  if(!entered[0]) return 0;
  if(!present(entered[0],environment(this_object()))) {
    entered[0]=0;
    return 0;
  }
  if(!entered[1]) return 1;
  if(!present(entered[1],environment(this_object()))) {
    entered[1]=0;
    return 1;
  }
  return -1;
}

enter_it(str) {
int place;

  if((!str)||(str!="tub")) {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(query_in_bed(this_player())) {
    notify_fail("But you are already sitting in the tun!\n");
    return 0;
  }
  if((place=correct_bed())==-1) {
    notify_fail("There is no room for more!\n");
    return 0;
  }
  entered[place]=this_player();
  write("You enter the tub.\n");
  say(this_player()->query_name()+" enters the tub.\n");
  if(filled==1) command("shiver",this_player());
  return 1;
}




