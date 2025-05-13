#define PATH "/players/whisky/seaworld/room/"
#define OB "/players/whisky/seaworld/obj/"
inherit "players/whisky/water";
object shell, beer;

reset(arg) {
  ::reset(arg);
if(!shell) { shell = clone_object(OB+"shell");move_object(shell,this_object());}
if(!beer) { beer = clone_object(OB+"beer");move_object(beer,this_object()); }
  if (arg) return;

  set_light(1);
  short_desc = "In the sea";
  long_desc =
  "\n\n" +
  "S P L A S H  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n" +
    "You are landing in the sea. You are lucky that you aren't hurt.\n" +
    "There is a rope hanging down the rock to climb up.\n" +
    "A little river flows into the sea to the southwest.\n"+
    "Sometimes there are some shells lying on the bottom.\n";

  items = ({
    "rope","You see a big brown rope hanging down from a rock",
    "bottom","A stony sea bottom",
    "rock","A big black rock standing in the sea" });
  dest_dir = ({
  "players/whisky/lake/room/river21","southwest",
  PATH+"sw3", "north", });

 }

init() {
  ::init();
    add_action("climb","climb");
  }

climb(str) {
    if(str!="rope" && str!="up the rope" && str!="up rope" && str!="up") {
    write("You should better try to climb up the rope.\n");
    say(this_player()->query_name()+" tries to climb up the rope but fails.\n");
    return 1; }

    else {
      write("U F F F you are climbing up the long brown rope.\n\n\n");
      write("U F F F you are climbing up the long brown rope.\n\n\n");
      write("U F F F you are climbing up the long brown rope.\n\n\n");
      write("U F F F you are climbing up the long brown rope.\n\n\n");
    this_player()->move_player("up#players/whisky/seaworld/room/rock");
  return 1; }
}
