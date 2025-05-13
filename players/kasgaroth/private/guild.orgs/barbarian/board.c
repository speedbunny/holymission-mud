inherit "obj/board";

int id(string str) {
  return str=="walls" || str=="messages";
}

void reset(int arg) {
  set_file("players/moonchild/save/guild_board");
}

void short() {
  return;
}

void long() {
  string tmp;
  int i;
  tmp="There are " + msg_num + " messages on the walls.\n"
	+ "Usage: note <headline>, read/remove <message number>\n";
  for(i=0;i<msg_num;i++)
    tmp+=i + 1 + ":\t" + headers[i] + "\n";
  this_player()->more_string(tmp);
}
