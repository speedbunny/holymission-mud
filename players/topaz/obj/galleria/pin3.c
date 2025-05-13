inherit "obj/treasure";

#include "/players/topaz/defs.h"

object busy;
reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("pinball machine");
    short_desc="A Pinball Machine";
    long_desc="This is a magically powered pinball machine.\n" +
             "To play it just type, 'play pinball'.\n" +
             "You can gain experience playing it, but it costs 5 coins\n" +
             "to play.\n";
    set_alt_name("machine");
    set_alias("pinball");
    set_weight(500);
    set_value(200);
  }
  return 1;
}

init() {
  ::init();
    add_action("_play","play");
}

_play(arg) {
  if(arg=="pinball") {
   if(!busy){
    busy=1;
    TP->add_money(-5);
    write("You drop 5 coins into the machine.\n");
    say(TP->query_name()+ " drops 5 coins into the pinball machine\n and begins "+
      "playing.\n");
    while(random(100)>7) {
      call_out("_noise", random(2), 0);
    }


    return 1;
    busy=0;
   }
   else{
    write("Someone is playing pinball already.  Sorry.\n"+
          "Please try again later.\n");
    return 1;
   }
  }
  else {
  write("Play what?\n");
  return 1;
  }
  return 1;
}

_noise() {
  int score;
    score=score+5;
    switch(random(6)) {
      case 0:
        write("Boink! ");
      case 1:
        write("Zink! ");
      case 2:
        write("Zap! ");
      case 3:
        write("Boooing! ");
      case 4:
        write("Zzzzzt! ");
      case 5:
        write("Buzzz! " );
    return 1;
    }
  return 1;
  }
  write("Plunk!\n");
  write("Game over.  You got " + score + " points!\n");
}
