

inherit "room/room";

reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_light(1);
    short_desc = "Cabin";
    no_castle_flag = 0;
    long_desc = 
        "A feeling of claustrophobia overcomes you as you enter the cabin. The walls\n"
        + "are oppressingly close and you feel like a sardine in a tin. You can see a\n"
        + "panel with three buttons on the eastern wall and a small sign hanging directly\n"
        + "above it.\n";
    items = ({
         "panel","It contains a blue, a red and a purple button",
         "sign","A plain sign, maybe you should read it"
            });
    dest_dir = 
        ({
        "/players/silas/fghant/ledge", "out",
        });
    smell = "*cough* What a musty, dusty cabin this is!\n";
    smell = "*cough* What a musty, dusty cabin this is!\n";
}
init() {
  ::init();
  add_action("push","push");
  add_action("push","press");
  add_action("read","read");
}

push(str) {
  if (str=="blue button") {
     write("Nothing happens.\n");
     say(this_player()->query_player()+" pushes the blue button.\n");
  }
  if (str=="red button") {
     write("A red flash blinds you and you feel a strong earthward pull.\n");
     this_player()->move_player("fades away#players/silas/fghant/cabin2");
     return 1;
  }
  if (str=="purple button") {
     write("A purple flash blinds you and you feel a slight earthward pull.\n");
     this_player()->move_player("fades away#players/silas/fghant/cabin3");
     return 1;
  }
}
read(str) {
  if (str=="sign") {
     write("This is a magic transportation booth. Each button will transport\n");
     write("you to a different level of the mountain.\n");
     write("Blue: top of the mountain, ledge\n");
     write("Red: bottom of the mountain, chasm\n");
     write("Purple: middle of the mountain, sightseeing deck\n");
  return 1;
  }
}


