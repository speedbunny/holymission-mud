inherit "room/room";

object ob;
int isbusy;
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Jug`s Workroom";
  long_desc = 
    "You have managed to enter Jug`s workroom !!    HOW DID YOU GET HERE !!!\n"+
    "If Jug is here, do NOT disturb him - he is busy.\n";
  dest_dir = ({
    "/players/jug/store", "store",
    "/players/jug/castle", "castle",
    "/room/shop", "shop",
    "/room/adv_guild", "guild",
    "/room/pub2", "pub",
    "/room/church", "church",
  });
  isbusy = 0;
}

init() {
  ::init();
  if(this_player()->query_real_name() != "jug" && isbusy) {
    write("Sorry JUG is working do not disturb him !!!\n\n");
    this_player()->move_player(" #/room/church");
    return 1;
  }
  if (this_player()->query_real_name() != "jug")
    this_player()->vis();

  add_action("is_busy", "isbusy");
  add_action("close_wr", "close");
  add_action("open_wr",  "open");
  add_action("clean_up", "cleanup");
  add_action("help", "help");
  add_action("depot", "depot");
  return 1;
}
 
is_busy() {
  if(this_player()->query_real_name() != "jug")
    return;
  if(isbusy)
    open_wr();
  else
    close_wr();
  return 1;
}

open_wr() {
  if(this_player()->query_real_name() != "jug")
    return;
  write("OK, you open your workroom for public.\n");
  isbusy = 0;
  return 1;
}

close_wr() {
  if(this_player()->query_real_name() != "jug")
    return;
  write("OK, your workroom is closed for public.\n");
  isbusy = 1;
  return 1;
}

clean_up(str) {
  int i;
  object iob;
  if(this_player()->query_real_name() != "jug")
    return;
  iob = all_inventory(this_object());
  for(i=0;i<sizeof(iob);i++)
    if((!living(iob[i]) || (str == "all")) && 
       (iob[i]->query_real_name() != "jug")) {
      move_object(iob[i], "/players/jug/store");
    }
  write("Ok, this room gleames of cleanness now.\n");
  return 1;
}

depot() {
  object iob;
  int i, sum;
  iob = all_inventory("/players/jug/store");
  for(i=0;i<sizeof(iob);i++) {
    write(iob[i]->short() + "\n");
    sum++;
  }
  write("\n" + sum + " objects are now in your store.\n");
  return 1;
}

help(str) {
  if (str != "workroom" && str != "wr")
    return;
  if (this_player()->query_real_name() != "jug") {
    write("I think that you should go elsewhere to do your job.\n");
    return 1;
  }
  write("Commands in this workroom:\n\n");
  write("isbusy   ...   turns your workroom-busy status\n");
  write("close    ...   closes your workroom to public\n");
  write("open     ...   opens your workroom for public\n");
  write("cleanup  ...   puts all objects from your workroom in your store\n");
  write("               use parameter `all` for clean objects and livings\n");
  write("depot    ...   list all objects in your depot\n");
  write("help wr  ...   this help-message\n\n");
  return 1;
}
