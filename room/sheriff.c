#define WARNING "/players/acdc/sheriff/warning/"

inherit "room/room";

void reset(int arg) {
  object board;
  if(arg) return;
  set_light(1);
  short_desc="Wiz Sheriff's Office";
  long_desc=
    "You are in the Wizard's Sheriff office.  Post all your questions\n"
      +"and arguements about rules.  If you have a more serious problem\n"
      +"mail the Sheriff and Arches!\n";
  dest_dir=
   ({
      "players/acdc/office/player_office","up",
   });
  move_object("/players/acdc/office/wiz_rulebook",this_object());
  board=clone_object("/obj/board");
  board->set_file("/players/acdc/office/wiz_problems");
  board->set_name("bulletin");
  move_object(board,this_object());
}

int allowed_use() {
  string* sheriffs;
  sheriffs = ({ "muzmuz", "haplo" });
  if(member_array(this_interactive()->query_real_name(), sheriffs) != -1) return 1;
  return 0;
}

void init() {
  add_action("do_banish", "banish");
  add_action("do_unbanish", "unbanish");
}

int do_banish(string str) {
  string name, reason, plfile;
  object pl;
  if(!allowed_use()) {
    printf("The deputy reports you to the sheriff for illegal attempt to banish.\n");
    write_file(WARNING + this_interactive()->query_real_name(), ctime(time())
      + " Tried to use banisher to banish " + str + "\n");
    return 1;
  }
  if(sscanf(str, "%s for %s", name, reason) != 2) return 0;
  name = lower_case(name);
  if(!strlen(plfile = read_file("/p/"+name[0..0]+"/"+name+".o"))) {
    notify_fail("There is no player called "+capitalize(name)+" in Holy Mission.\n");
    return 0;
  }
  if(file_size("/banish/"+name+".o") > 0) {
    notify_fail("That player is already banished.\n");
    return 0;
  }
  "/banish/banisher"->do_banish(str, this_player());
  printf("You banish "+capitalize(name)+".\n");
  return 1;
}

int do_unbanish(string str) {
  string name, reason, plfile;
  if(!allowed_use()) {
    printf("The deputy reports you to the sheriff for illegal attempt to banish.\n");
    write_file(WARNING + this_interactive()->query_real_name(), ctime(time())
      + " Tried to use banisher to unbanish " + str + "\n");
    return 1;
  }
  if(sscanf(str, "%s for %s", name, reason) != 2) return 0;
  name = lower_case(name);
  if(!strlen(plfile = read_file("/p/"+name[0..0]+"/"+name+".o"))) {
    notify_fail("There is no player called "+capitalize(name)+" in Holy Mission.\n");
    return 0;
  }
  if(file_size("/banish/"+name+".o") == -1) {
    notify_fail("That player was not banished.\n");
    return 0;
  }
  "/banish/banisher"->do_unbanish(str, this_player());
  printf("You unbanish "+capitalize(name)+".\n");
  return 1;
}
