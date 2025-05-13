inherit "obj/treasure";


reset(arg) {
 if (arg) return;
  set_id("liquid");
  set_alias("bottle");
  set_short("A bottle with a strange liquid");
  set_long("You can imagine that something strange could happen.\n"+
            "if you drink it.\n");
  }
 init() {
  ::init();
  add_action("drink","drink");
  }
 drink(str) {
  if (str=="vial" || str=="bottle") {
     write("\n\n\nSuddenly something strange happens.\n\n\n"+
           "You try to get air bit you can hardly breath.\n\n\n"+
           "You feel your body changing Arrrrrrrrggggggggg.\n\n\n");
    say(this_player()->query_name()+" drinks the vial and suddenly turns into a frog.\n");
    this_player()->frog_curse(1);
   shout(this_player()->query_name()+" shouts helplessly: QQQQQQAAAAAAAAAkkkkkkk.\n");
    move_object(clone_object("players/whisky/garden/obj/bottle2"),this_player());
  destruct(this_object());
  return 1;
  }
}

