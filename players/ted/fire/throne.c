inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Throne Room";
    long_desc =
"This is a large circular room with a high domed ceiling.\n"+
"A large ornate throne sits on a raised dais at the north\n"+
"end of the room. You can't tell if anyone is sitting in it,\n"+
"maybe you should take a closer look?\n";
    dest_dir = ({
"players/ted/fire/hell_hall", "south"
    });
    items = ({
"throne","The throne appears to be made of solid gold. You still can't\n"+
         "tell if it is occupied. May be you should climb up the stairs\n"+
         "leading up the dais to the throne",
"dais","As you look closer, you see that it is possible to climb up\n"+
       "the stairs leading to the throne"
    });
  }
}

init() {
  ::init();
  add_action("do_climb"); add_verb("climb");
}

do_climb(str) {
 call_other(this_player(),"move_player","up#players/ted/fire/king"); 
 return 1;
}
