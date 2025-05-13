/* 920414 mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */

/* +++++++++++++++++++++
   + The gamblin' hall +
   +++++++++++++++++++++ */

#define PUB	"room/pub2"

inherit "room/room";

reset(arg) {
  tell_room(PUB,"You can hear laughter from the east.\n");
  if (!arg) {
     dest_dir=({ PUB,"west"});
     short_desc="The gambling hall";
     long_desc=
	"You are in the gambling hall.\n" +
	"People come here when they want to relax from fighting and\n" +
	"rather train their brain, instead of their muscles.\n";
     items=({"sign","A sign is hanging over the door"});
  }
}

init() {
  ::init();
  add_action("read","read");
  add_action("play","play");
}

read(str) {
  if (str=="sign") {
     write(
"Hello gambler !\n\n" +
"The gambling hall is closed at the moment. Come again later.\n");
     return 1;
  }
}








  
     
