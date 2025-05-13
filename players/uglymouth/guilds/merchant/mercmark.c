IN: soul.c

mixed *marklist;

reset(arg) {
  update_marks();
  if(!arg) return;
  marklist = ({ });
}

void init() {
  add_skill_cmd("guildsigns", "add_mark", "mark");
  add_skill_cmd("guildsigns", "read_mark", "read");
  add_action("look", "look");
  add_action("look", "l");
  send_marks();
}

void *send_marks() {
  int so, i;
  object *members, ms;
  members = filter_array(users(), "guild_filter", this_object());
  so = sizeof(members);
  for(i=0; i<so; i++) {
    ms = present("merchantsoul", members[i]);
    ms->set_marks(marklist);
  }
}

int guild_filter(object ob) {
  return ob->query_guild() == 12;
}

int add_mark(string mark) {
  if(!mark) return 0;
  if(!valid_mark(mark)) {
    notify_fail("You can only use valid guild marks.\n");
    return 0;
  }
  string room;
  room = file_name(environment(this_player()));
  marklist += room;  
  marklist += mark;
  marklist += 0;
  send_marks();
}

void set_marks(mixed *list) {
  marklist = list;
}

update_marks() {
  if(!marklist) return;
  int i, so;
  so = sizeof(marklist) - 1;
  for(i=so; i>=0; i-3) {
    marklist[i]++; 
    if(marklist[i] == 2) {
      del_array(marklist, marklist[i]);
      del_array(marklist, marklist[i-1]);
      del_array(marklist, marklist[i-2]);
      i-3;
    }
  }
  send_marks();
}

/*type?*/ look(str) {
  if(TP->test_dark()) return 1;
  if(str) return TP->look(str);
  string fn;
  int nr;
  fn = filename(ENV(TP));
  if(nr = member_array(fn, marklist) != -1)
    write("You notice a guildmark hidden in this room.\n");
  return TP->mylook(0);
}

int valid_mark(string str) {
  /* here must come a list with valid guild texts */
  return 1;
}

int read_mark(string str) {
  if(str != "guildmark") return 0;
  int nr;
  string fn;
  fn = file_name(ENV(TP));
  nr = member_array(fn, marklist);
  if(nr+2) write("The mark is rather worn away and hard to read.\n");
  else write("The mark was put here recently and is clearly visible.\n");
  write("You try to decipher the guildmark.\n");
    + "It says: " + (nr + 1) + "\n");
  return 1;
}

