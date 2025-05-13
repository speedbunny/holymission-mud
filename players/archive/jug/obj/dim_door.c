id(str) {
  return str == "hole";
}

short() {
  return "A hole in the ground";
}

long() {
  write("This seems to be the famous entrance to Jug`s domain.\n");
  write("Through it you can enter the WORLDS OF WONDER.\n");
  write("Try it !!!\n");
}
	
init() {
  add_action("enter", "enter");
}

enter(str) {
  if (!id(str)) return;
  this_player()->move_player("to the castle of Jug#" +
			     "/players/jug/castle");
  return 1;
}
