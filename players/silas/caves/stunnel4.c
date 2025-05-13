inherit "room/room";
object doberman;
int i;

reset(arg) {
  if (!doberman) {
     for (i=0;i<4;i++) {
  doberman=clone_object("players/silas/monster/doberman");
  move_object(doberman,this_object());
     }
}
    if (arg) return;

    set_light(1);
    short_desc = "End of the Tunnel";
    no_castle_flag = 0;
    long_desc = 
        "The tunnel ends here. A shimmering blue portal lies to the east and it is\n"
        + "usually guarded. Blue light floods your surroundings and you find it hard to\n"
        + "see.\n";
    items = ({
         "portal","It radiates blue light through the tunnel; where could it lead?",
          });
    dest_dir = 
        ({
        "/players/silas/caves/stunnel3", "west",
        });
    smell = "The pungent smell of dog feces penetrates your nasal passages.\n";
}
init() {
  ::init();
  add_action("enter","enter");
}

enter(str) {
  if (str=="portal") {
     write("You enter the portal and emerge elsewhere.\n");
     this_player()->move_player("steps through the portal#players/silas/caves/hall1");
     return 1;
  }
  else {
   write("What do you want to enter?\n");
   return 1;
  }
}

query_light() {
    return 1;
}
