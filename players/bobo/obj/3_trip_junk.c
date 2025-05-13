/* cargo junk */
// debugged version Whisky, old version gave still problems
// hint: check with the mistletoe and mcall if the object works
// Description redone by Gambit 170195
// Updated by Bobo December '96

#define START    "/room/sea"
#define ISL      "/players/tatsuo/ezo/coast/c1"
#define ISL2     "/players/bobo/rooms/island/enter"

#define TO       this_object()
#define TP       this_player()
#define ENV      environment
#define NAME     query_name()

int pos;

int query_pos() {
  return pos;
}

void reset(int arg) {

  if(arg) return;

  pos = 0;
  set_light(1);
  call_other(START,"???");
  call_other(ISL,"???");
  call_other(ISL2,"???");
  move_object(TO,START);
  tell_room(ENV(),"A cargo junk arrives at the shore.\n");
  call_out("start_tour",4);
  return;
}

void start_tour() {

  tell_room(ENV(),
            "The captain of the cargo junk shouts: We are leaving " +
            "in 30 seconds.\n");
  tell_room(TO,
            "The captain of the cargo junk shouts: We are leaving " +
            "in 30 seconds.\n");
  call_out("on_sea",30);
  return;
}

void trip_start() {
  pos = 0;
  tell_room(TO, "The cargo junk arrives at the shore.\n");
  move_object(TO, START);
  tell_room(ENV(), "A cargo junk arrives at the shore.\n");
  call_out("start_tour", 60);
}

void trip_isl() {
  pos = 2;
  tell_room(TO, "The cargo junk arrives at Ezo.\n");
  move_object(TO, ISL);
  tell_room(ENV(), "A cargo junk arrives at the shore.\n");
  call_out("start_tour", 60);
}

void trip_isl2() {
  pos = 4;
  tell_room(TO, "The cargo junk arrives at a strange island.\n");
  move_object(TO, ISL2);
  tell_room(ENV(), "A cargo junk arrives at the shore.\n");
  call_out("start_tour", 60);
}

void on_sea() {

  tell_room(ENV(), "A cargo junk leaves the shore.\n");
  tell_room(TO,    "The cargo junk leaves the shore.\n");
  move_object(TO,  "/room/troom");
  pos++;
  call_out("message1", 10);
  return;
}

void message1() {
  tell_room(TO,"The junk slowly gains speed as the wind catches the sails.\n");
  call_out("message2",10);
  return;
}

void message2() {
  tell_room(TO, "Sharks slowly circle around in the sea.\n");
  call_out("message3",10);
  return;
}

void message3() {
  tell_room(TO, "The Captain mumbles something about Pirates.\n");
  call_out("message4",10);
  return;
}

void message4() {
  tell_room(TO, "You can see the shoreline in the distance.\n");
  call_out("message5",10);
  return;
}

void message5() {
  tell_room(TO, "The Captain puts down the anchor.\n");
  switch(pos) {
    case 1:
      trip_isl();
      break;
    case 3:
      trip_isl2();
      break;
    case 5:
      trip_start();
      break;
    default:
      trip_start();
      break;
  }
  return;
}

string short() {
  return "A cargo junk";
}

string query_name() {
  return short();
}

int no_clean_up() {
  return 1;
} 

void long(string arg) {
  if (!arg)
    write(
          "You are on a cargo junk that tours between the islands. " +
          "Passage is free, but\n" +
          "slow. Looking around you notice many things about the junk. " +
          "Solid wooden \n" +
          "construction holds this craft together, giving you a feeling of " +
          "safety as you\n" +
          "cross the seas. In the center, a large mast holds the linen " +
          "sail to propel \n" +
          "the ship along the way.\n" +
          "On the sail you notice a heraldic from the island of Ezo.\n");
  else if (arg == "captain")
    write("The Captain stands here smoking his pipe.\n");
  else if (arg == "mast")
    write("A small oak wooden mast.\n");
  else if (arg == "sail")
    write("A dirty white linen sail displaying the heraldic of Ezo.\n");
  else if (arg == "heraldic")
    write("You see a Ninja fighting a big dragon.\n");
}

int id(string arg) {
  return (member_array(arg,
          ({ "cargo junk", "junk",     "mast",
             "sail",       "heraldic", "captain" })) != -1);
}


int query_weight() {
  return 20000;
}

void init() {
  add_action("do_enter", "enter");
  add_action("do_leave", "leave");
}

int do_enter(string arg) {

  object env;

  if(id(arg) && ENV(TP) == ENV(TO)) {
    tell_object(TP, "You board the junk.\n");
    env = ENV(TP);
    move_object(TP, TO);
    tell_room(env,TP->NAME + " enters the cargo Junk.\n");
    TP->command("look");
    return 1;
  }
  return 0;
}

int do_leave(string arg) {

  if(ENV(TP)!=TO)
    return 0;
  else if(!id(arg)) {
    notify_fail("If you wanna leave the cargo junk type 'leave junk'\n");
    return 0;
  }
  else if (pos%2) {
    notify_fail("As you try to jump into the sea the captain " +
                "holds you back,\n"+
                "and shows you the sharks circling the cargo junk.\n");
    return 0;
  }
  write("You leave the cargo junk.\n");
  say(TP->NAME + " leaves the cargo junk.\n", TP);
  tell_room(ENV(), TP->NAME + " leaves the cargo junk.\n");
  move_object(TP, ENV());
  command("look", TP);
  return 1;
}

