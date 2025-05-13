inherit "obj/treasure";

string *quests;

void init() {
  add_action("quest_grep", "quest-grep");
}

void reset(int arg) {
  object *ob;
  int i;
  if(arg)
    return;
  set_id("quest-grepper");
  set_short("quest-grepper");
  set_long("Usage: quest-grep.\n");
  ob=filter_array(all_inventory(find_object("room/quest_room")), "filt",
	this_object());
  quests=allocate(sizeof(ob));
  for(i=0;i<sizeof(ob);i++)
    quests[i]=(string)ob[i]->query_name() + " ";
}

int filt(object ob) {
  return (int)ob->id("quest");
}

int quest_grep() {
  string *FILE;
  int i;
  FILE=explode(read_file("/log/QUESTS"), "\n");
  write("Quests solved since /log/QUESTS began.\n\n");
  for(i=0;i<sizeof(quests);i++)
    write(quests[i] + ":  " + sizeof(regexp(FILE, quests[i])) + "\n");
  return 1;
}
