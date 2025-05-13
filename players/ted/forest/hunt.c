inherit "room/room";

object hunt1, hunt2, glove, boot;

reset(arg) {
  int i;
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Hunters Camp";
    long_desc =
"A small cooking fire is the only sign that any one\n"+
"was ever here at all.\n";
    dest_dir = ({
"players/ted/forest/forest24", "west"
    });
  }
  if(!present("hunter")) {
    i = 0;
    while(i < 2) {
      i ++;
      hunt1 = clone_object("players/ted/monsters/hunter");
      move_object(hunt1, this_object());
      glove = clone_object("players/ted/armors/leather_gloves");
      move_object(glove, hunt1);
      call_other(hunt1, "init_command", "wear gloves");
    }
    i = 0;
    while(i < 2) {
      i ++;
      hunt2 = clone_object("players/ted/monsters/hunter");
      move_object(hunt2, this_object());
      boot = clone_object("players/ted/armors/leather_boots");
      move_object(boot, hunt2);
      call_other(hunt2, "init_command", "wear boots");
    }
  }
}
