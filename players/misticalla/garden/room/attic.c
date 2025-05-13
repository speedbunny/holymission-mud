#define	TP	this_player()
#define TPP     TP->query_possessive()
#define	TPN	TP->query_name() 
 
inherit "room/room";
 
reset(arg) {
object ob;

  if (!(ob=present("spider")) || !living(ob))
     move_object(clone_object("players/whisky/garden/monster/spider"),
	this_object());
  if (arg) return;
 
  set_light(0);
  property = "no_teleport";
  short_desc = "attic";
  no_castle_flag = 0;
  long_desc = 
  "You have entered the attic of the strange building. "+
  "The air here smells very musty. "+
  "There are spider webs hanging down the wall "+
  "and a strange door leads north. A little exit leads to "+
  "the roof. A wooden stairway leads downwards to a hotter "+
  "place where danger lurks.\n";

  dest_dir = ({ "players/whisky/garden/room/house2", "down", });
  items = ({"wall","You see dirty red bricks",
            "sign","You see: ENTRANCE strongly forbidden!!!",
            "webs","You see big grey spiderwebs hanging down the wall",
            "exit","It's so small that only a little animal can enter it",
            "door","You see an iron door without a keyhole"});
}
 
 
init() {
  ::init();
  add_action("read","read");
  add_action("open","open");
  add_action("leave","leave");
  add_action("unlock","unlock");
  add_action("enter","enter");
  add_action("enter","pass");
  add_action("search","search");
  add_action("north","north");
}
north() {
  write("You bang your had against the closed door.\n");
  say(TPN+" bangs "+TPP+" head against the closed wooden door.\n");
  TP->hit_player(random(2));
  return 1;
 }
enter(str) {
 if (str!="exit") return;
  if (this_player()->query_frog()) {
  write("You crawl trough the little exit.\n");
  TP->move_player("through a little exit#players/whisky/garden/room/roof2");
  return 1;
 }
  else {
  write("You fail. You are not a small animal that could enter here.\n");
  say(TPN+" tries to enter the exit, but fails.\n");
  return 1;
  } 
 return 1; } 
search(str) {
 if (str=="pocket") { return; }
 write("You search and search and found nothing.\n");
 return 1;
}
leave(str) {
  if (str=="exit") {
    write("You are no little mouse (*laugh*).\n");
    say(TPN+" wants to leave through the exit but fails.\n");
    return 1;
  }
}

read(str) {
  if (str=="sign") {
     write("You read: ENTRANCE strongly forbidden!!!\n");
     say(TPN+" reads the sign, but doesn't look happier.\n");
     return 1;
  }
}

open(str) {
  if (str!="door") {
     write("You seem to get a bad headache.\n");
  } else {
     say(TPN+" tries to open the door but fails.\n");
     write("You try to open the door but the door is locked.\n");
  }
  return 1;
}

unlock(str) {
  if (str=="door") {
     write("You fail, the door has no keyhole.\n");
     say(TPN+" tries to unlock the door but fails.\n");
     return 1;
  }
}
