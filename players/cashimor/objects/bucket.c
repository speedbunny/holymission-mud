inherit "obj/thing";

int filled;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("bucket");
    set_short("A metal bucket");
    set_long("This bucket is used to hold water and heat it over a fire.\n");
    set_value(25);
    set_weight(3);
  }
  if(filled==2) filled--;
}

init() {
  ::init();
  add_action("fill_it","fill");
  add_action("heat_it","heat");
  add_action("empty_it","empty");
}
  
empty_it(str) {
  if((!str)||(str!="bucket")) {
    notify_fail("Empty what?\n");
    return 0;
  }
  if(!filled) {
    notify_fail("But it's not filled!\n");
    return 0;
  }
  write("You empty the bucket.\n");
  say(this_player()->query_name()+" empties the bucket.\n");
  filled=0;
  return 1;
}

prevent_insert() {
  if(filled) {
    write("You can't put a filled bucket into something!\n");
    return 1;
  }
}

fill_it(str) {
object bath;

  if(!str) {
    notify_fail("Fill what?\n");
    return 0;
  }
  if(str=="tub") {
    if(!bath=present("bath",environment(this_player()))) {
      notify_fail("But there is no bath here!\n");
      return 0;
    }
    if(!filled) {
      notify_fail("There is no water in the bucket!\n");
      return 0;
    }
    if(bath->query_filled()) {
      notify_fail("But there is already water in the tub.\n");
      return 0;
    }
    write("You pour the water into the tub.\n");
    bath->set_filled(filled);
    filled=0;
    say(this_player()->query_name()+" pours water into the bath.\n");
    return 1;
  }
  if(str!="bucket") {
    notify_fail("Fill what?\n");
    return 0;
  }
  if(filled) {
    notify_fail("But the bucket is already filled with water!\n");
    return 0;
  }
  if(environment(this_player())->query_env_name()!="water") {
    notify_fail("There is no water here!\n");
    return 0;
  }
  write("You fill the bucket with water.\n");
  say(this_player()->query_name()+" fills a bucket with water.\n");
  filled=1;
  return 1;
}

long() {
  ::long();
  switch(filled) {
    case 0: write("It's empty.\n"); break;
    case 1: write("It's filled with cold water.\n"); break;
    case 2: write("It's filled with hot water.\n"); break;
  }
}

heat_it(str) {
  if((!str)||((str!="bucket")&&(str!="water"))) {
    notify_fail("Heat what?\n");
    return 0;
  }
  if(!environment(this_player())->query_property("has_fire")) {
    notify_fail("There's not enough heat in this room.\n");
    return 0;
  }
  if(filled==2) {
    notify_fail("But the water is already hot!\n");
    return 0;
  }
  if(!filled) {
    notify_fail("But there is no water in the bucket.\n");
    return 0;
  }
  filled=2;
  write("You heat the water in the bucket.\n");
  say(this_player()->query_name()+" heats water in a bucket.\n");
  return 1;
}  




