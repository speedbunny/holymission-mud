inherit "/room/room";
 
#define NOISE ({ "Bulp.\n", "Glug.\n" })
#define NOISE_TIMER  5
 
private static object *locs;
private static int count, which_noise, num_of_rooms;
 
status list_rooms();
 
nomask status add_room(object ob) {
 
  if(!objectp(ob))
    return 0;
  if(!locs)
    locs = ({});
  if(member_array(ob, locs) != -1)
    return 0;
  locs += ({ ob });
  num_of_rooms++;
  return 1;
}
 
nomask status rem_room(object ob) {
  int tmp;
 
  if(!objectp(ob))
    return 0;
  if(!locs)
    locs = ({});
  if((tmp = member_array(ob, locs)) == -1)
    return 0;
  locs = del_array(locs, tmp);
  num_of_rooms--;
  return 1;
}
 
status list_rooms() {
  int i, sz;
 
  write("Rooms currently being sent messages: \n");
  if(num_of_rooms == 0) {
    write("     NONE\n");
    return 1;
  }
  for(i=0; i<num_of_rooms; i++) {
    write("     ");
    write(locs[i]);
    write("\n");
  }
  return 1;
}
 
private static void verify_rooms() {
  int i, j, all_sz, found;
  object *all_ob;
 
  if(num_of_rooms == 0)
    return;
  for(i=0; i<num_of_rooms; i++) {
    found = 0;
    all_ob = all_inventory(locs[i]);
    if((all_sz = sizeof(all_ob)) == 0)
      found = 0;
    else {
      for(j=0; j<all_sz; j++)
        if(call_other(all_ob[j], "query_player"))
          found = 1;
    }
    if(!found)
      rem_room(locs[i]);
  }
}
 
void do_tell_to_rooms() {
  int i, sz;
 
  if(num_of_rooms == 0)
    return;
  sz = sizeof(NOISE);
  if(which_noise >= sz)
    which_noise = 0;
  for(i=0; i<num_of_rooms; i++)
    tell_room(locs[i], NOISE[which_noise]);
}
 
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  count = 0;
  which_noise = 0;
  num_of_rooms = 0;
  enable_commands();
  set_light(1);
  short_desc = "Noise room";
  long_desc = "Global noise room\n";
  set_heart_beat(1);
}
 
void init() {
  ::init();
  add_action("list_rooms","dump");
}

heart_beat() {
  if(count == NOISE_TIMER) {
    count = 0;
    verify_rooms();
    do_tell_to_rooms();
    which_noise++;
  }
  else count++;
}
