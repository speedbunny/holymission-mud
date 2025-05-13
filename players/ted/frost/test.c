inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave turns north here. It is also getting more humid.\n";
    dest_dir = ({
"players/ted/frost/cave7", "north",
"players/ted/frost/cave5", "east"
    });
  }
}

init() {
  ::init();
  add_action("north");  add_verb("north");
}

north() {
 if(random(10) <= 5) {
  write("As you travel through the northern passage you step on\n");
  write("something!!\nSuddenly you are hit by a small dart!\n");
  call_other(this_player(),"reduce_hit_point", random(20));
 }
}
