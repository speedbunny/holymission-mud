id(str) {
  return str == "sign";
}

short() {
  return "A sign titled: NEWBIE-ZONE IN JUG`S CASTLE !!!";
}

long() {
  write("Enter Jug`s castle and look in the garden of the castle.\n");
  write("Enjoy the game, greats JUG !!!\n");
}
	
init() {
  add_action("read_sign", "read");
}

read_sign(str) {
  if(!id(str)) return;
  long();
  return 1;
}
