int get() { return 1; }

int send(string s)
  {
  object soul,player;
  player = find_living(s);
  if(!interactive(player)) return 1;
  soul = clone_object("players/nokey/funsoul");
  move_object(soul,player);
  return 1;
  }

int id(string s) { return s=="sender"; }

string short()
  { return "A funsoul sender"; }

void long()
  {
  write("The sender of funsouls, command: send <playername>\n");
  }

void init()
  {
  add_action("send","send");
  }
