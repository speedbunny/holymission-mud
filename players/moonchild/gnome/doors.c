inherit "room/room";

int exit,liar;
string player,*chats;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="By two doorways";
  long_desc="You are standing by two large doorways in an otherwise bare room.\n"
	+ "A small decorative metallic plaque is affixed between the doors.\n";
  no_obvious_msg="";
  items=({ "plaque", "Perhaps you should read it",
	"door", "Which door, door 1 or door 2?",
	"doors", "Which door, door 1 or door 2?",
	"door 1", "It leads into darkness",
	"door 2", "It leads into darkness" });
  exit=random(2);
  liar=random(2);
  chats=allocate(10);
  chats[0]="Door 1 says: I am the way to "
	+ ({ "the treasury", "death" })[liar==exit];
  chats[1]="Door 2 says: I am the way to "
	+ ({ "the treasury", "death" })[liar==exit];
  chats[2]="Door 1 says: Door 2 is the way to "
	+ ({ "death", "the treasury" })[liar==exit];
  chats[3]="Door 2 says: Door 1 is the way to "
	+ ({ "death", "the treasury" })[liar==exit];
  chats[4]="Door 1 says: I always tell the truth";
  chats[5]="Door 2 says: I always tell the truth";
  chats[6]="Door 1 says: Door 2 always lies";
  chats[7]="Door 2 says: Door 1 always lies";
  chats[8]="Door 1 says: Door 2 will say that I am the way to "
	+ ({ "death", "the treasury" })[exit];
  chats[9]="Door 2 says: Door 1 will say that I am the way to "
	+ ({ "the treasury", "death" })[exit];
}

init() {
  ::init();
  add_action("read", "read");
  add_action("enter", "enter");
  if(this_player()->query_real_name()!=player
        && this_player()->query_level()<33)
                move_object(this_player(), "room/church");
  else
    set_heart_beat(1);
}

query_prevent_shadow() {
  return 1;
}

set_owner(str) {
  int junk;
  if(!sscanf(file_name(previous_object()), "players/moonchild/gnome/comblock#%d", junk)) return;
  player=str;
}

read(str) {
  if(str!="plaque") return;
  write("The plaque reads:\n\n");
  write("One of these doors leads to the Treasury.\n");
  write("The other leads to certain death.\n");
  write("Think before you enter the doors.\n");
  return 1;
}

enter(str) {
  if(!id(str) || str=="plaque") return;
  if(str=="door") {
    write("Which door?\n");
    return 1;
  }
  if((str=="door 1")==exit) {
    this_player()->move_player("X#players/moonchild/gnome/death");
  }
  else {
    "players/moonchild/gnome/treasury"->make_treasure(25);
    this_player()->set_quest("gnome_treasure");
    this_player()->move_player("X#players/moonchild/gnome/treasury");
    write("You've done it! You've broken into the Gnomes' Treasury!\n");
    write("You shout: I've broken into the Gnomes' Treasury!\n");
    shout(this_player()->query_name()
	+ " shouts: I've broken into the Gnomes' Treasury!\n");
  }
  return 1;
}

heart_beat() {
  if(!random(4))
    tell_room(this_object(), chats[random(10)] + ".\n");
}
