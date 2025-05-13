 // see file's /players/jewel/quest/quest_changes/README and README.2nd DRAGONN
inherit "room/room";

#define TP this_player()
#define QN query_real_name()
int open;

reset(arg) {
  if (!arg) {
    set_light(1);
    short_desc="The vampire kings living room";
    items=({
      "pictures","You see some unknown vampires, but you also notice the \n"+
                 "picture of Dracula",
      "picture","The picture of Dracula. On a second look you notice \ntwo "+
                "glooming rubies instead of his eyes",
      "picture of dracula","The picture of Dracula. On a second look you"+
      " notice \ntwo glooming rubies instead of his eyes",
      "rubies","blood red rubies",
      "ruby","there are two rubies",
      "eye","Its made of a ruby",
      "eyes","They are made of rubies",
      "wall","There are pictures on the walls",
      "walls","There are pictures on the walls",
          });
    dest_dir=({
      "/players/jewel/quest/vtower8","west"
             });
    }
  long_desc=
    ("You are standing in the vampire kings living room. Many pictures\n"+
     "of former vampire kings are hanging here.\n");
  open=0;
  }

init() {
  ::init();
  add_action("press","press");
  add_action("press","push");
    add_action("enter","enter");
}

press(arg) {
  if(present("vampire king")) {
    write("You can't do that while the vampire king is here.\n");
    return 1;
  }
  if(arg=="eyes" || arg=="rubies") {
    if(open) write("Nothing happens.\n");
    else {
      tell_room(this_object(),"A secret door opens in the north wall.\n");
      open=1;
    long_desc=
      ("You are standing in the vampire kings living room. Many pictures\n"+
       "of former vampire kings are hanging here. You notice an opening\n" +
       "in the northern wall.\n");
     ::init();
    } 
  } else if(arg=="eye") {
    write("Which eye ?\n");
  } else if(arg="ruby") {
    write("Which ruby ?\n");
  } else write(query_verb()+" where ?\n");
  return 1;
}

enter(arg) {
  if(!open) {
    notify_fail("There is nothing oen here to enter.\n");
    return 1;
  }
if(arg=="opening" && this_player()->query_level()>14) {
    this_player()->move_player("north#players/jewel/quest/vtower10");
    return 1;
}
 else { write("You concentrate all powers, but you fail.\n");
 say(capitalize(this_player()->query_real_name())+" fail to enter in opening.\n");
return 1;
}
}
