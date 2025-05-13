inherit "obj/thing";

object entered;
int installed;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("bed");
    set_short("A small but comfortable bed");
    set_long("This is a small but comfortable bed. It looks very inviting.\n");
    set_can_get(0);
    entered=allocate(2);
  }
}

init() {
string dest_dir;
int i;

  ::init();
  dest_dir=environment(this_object())->query_room("dest_dir");
  for(i=1;i<sizeof(dest_dir);i+=2) add_action("prevent_move",dest_dir[i]);
  add_action("sleep_here","sleep");
  add_action("enter_it","enter");
  add_action("leave_it","leave");
}

long() {

  ::long();
  if(correct_bed()==-1) {
    write(entered[0]->query_name()+" and "+entered[1]->query_name()+" are "
        + "lying in it.\n");
    return;
  }
  if(entered[0]) {
    write(entered[0]->query_name()+" is lying in it.\n");
    return;
  }
  if(entered[1]) {
    write(entered[1]->query_name()+" is lying in it.\n");
    return;
  }
  write("It's empty.\n");
}

prevent_move() {
  if(query_in_bed(this_player())) {
    write("You'll have to leave the bed for that!\n");
    return 1;
  }
  return 0;
}

leave_it(str) {
int place;

  if((!str)||(str!="bed")) {
    notify_fail("Leave what?\n");
    return 0;
  }
  if(!place=query_in_bed(this_player())) {
    notify_fail("But you're not lying in the bed!\n");
    return 0;
  }
  write("You leave the bed.\n");
  say(this_player()->query_name()+" leaves the bed.\n");
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

  if((!str)||(str!="bed")) {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(query_in_bed(this_player())) {
    notify_fail("But you are already lying in bed!\n");
    return 0;
  }
  if((place=correct_bed())==-1) {
    notify_fail("There is no room for more!\n");
    return 0;
  }
  entered[place]=this_player();
  write("You enter the bed.\n");
  say(this_player()->query_name()+" enters the bed.\n");
  return 1;
}
  
sleep_here() {
  if(!query_in_bed(this_player())) {
    notify_fail("But you're not lying in the bed!\n");
    return 0;
  }
  write("You fall asleep.\n");
  say(this_player()->query_name()+" falls asleep.\n");
  input_to("sleeping");
  write("> ");
  return 1;
}

sleeping(str) {
  if((str=="wake")||(str=="wake up")||(str=="awake")||(str=="get up")) {
    write("You wake up!\n");
    say(this_player()->query_name()+" wakes up from a deep sleep.\n");
    return 1;
  }
  write("You can't do that while you're sleeping!\n");
  say(this_player()->query_name()+" snores.\n");
  write("> ");
  input_to("sleeping");
}




