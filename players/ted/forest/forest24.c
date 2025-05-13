inherit "room/room";

object boar, tusk;


reset(arg) {
 int i;
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Dread Forest";
    long_desc =
"The undergrowth here has been rooted up and trampled.\n"+
"Gouge marks as if from large tusks score the ground\n"+
"and hoofprints can be seen in the softer soil.\n"+
"A small path leads off to the east\n";
    dest_dir = ({
"players/ted/forest/forest14", "north",
"players/ted/forest/forest34", "south",
"players/ted/forest/forest23", "west",
"players/ted/forest/hunt", "east"
    });
  }
  i = 0;
  if(!present("wild boar")) {
    while(i < 3) {
      i ++;
      boar = clone_object("players/ted/monsters/wild_boar");
      move_object(boar, this_object());
      tusk = clone_object("players/ted/weapons/tusk");
      move_object(tusk, boar); 
      call_other(boar, "init_command", "wield tusk");
    }
  }
}


init() {
  ::init();
  add_action("east"); add_verb("east");
}


east() {
 if(present("wild boar")) {
  write("A boar charges you....you can't get past!\n");
  return 1;
  }
 call_other(this_player(), "move_player","east#players/ted/forest/hunt");
 return 1;
}
