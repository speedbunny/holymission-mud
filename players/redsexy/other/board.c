inherit "/obj/board";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_file("players/redsexy/other/board");
  set_name("Redsexys Ideas and Commincation Board");
  set_short("Redsexy's Personal Board");
}
