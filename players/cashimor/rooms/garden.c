inherit "room/room";

object gardener;
int food;

reset(arg) {
  if(!arg) {
    short_desc="Japanese garden";
    long_desc="This is a japanese garden. There is a pond here, and a bread\n"
            + "dispenser.\n";
    set_light(1);
    call_out("next_tell",60+random(60));
    items=({"pond","It's a beautiful pond. There are fishes swimming in it",
            "dispenser","It has a little button on it",
            "button","Maybe you can press it..",
            "fishes","Various types of goldfishes"});
  }
  make_gardener();
}

long(str) {
  ::long(str);
  if((str)&&(str=="pond")) {
    if(!food) return;
    if(food==1) {
      write("There's a little bread floating on the surface.\n");
      return;
    }
    if(food<4) {
      write("There's some bread floating on the surface.\n");
      return;
    }
    if(food<9) {
      write("There's bread floating on the surface.\n");
      return;
    }
    write("The pool is covered with bread!\n");
  }
}

make_gardener() {
object rake;

  if(present("gardener",this_object())) return;
  gardener=clone_object("obj/monster");
  gardener->set_name("gardener");
  gardener->set_level(5);
  gardener->set_short("A gardener");
  gardener->set_long("This is a gardener taking well care of Akasha's\n"
                   + "japanese garden.\n");
  gardener->set_gender(1);
  gardener->load_chat(1,({"The gardener tidies some part of the garden.\n",
                          "The gardener whistles to himself.\n",
                          "The gardener walks around.\n"}));
  gardener->load_a_chat(10,({"The gardener looks at you in outrage.\n",
                             "The gardener spits at you.\n"}));
  rake=clone_object("obj/thing");
  rake->set_name("rake");
  rake->set_short("A rake");
  rake->set_long("This is the rake belonging to the gardener.\n");
  rake->set_weight(2);
  rake->set_class(7);
  transfer(rake,gardener);
  move_object(gardener,this_object());
  gardener->init_command("wield rake");
  tell_room(this_object(),"Gardener arrives in a puff of smoke.\n");
}

next_tell() {
  switch(random(2)) {
    case 0: 
      tell_room(this_object(),"The water of the ponds ripples a little.\n");
      break;
    case 1:
      if(food>0) {
        tell_room(this_object(),"The fishes eat some of the bread.\n");
        food--;
      }
      break;
  }
  call_out("next_tell",60+random(60));
}

init() {
  ::init();
  add_action("dismiss_it","dismiss");
  add_action("enter_it","enter");
  add_action("dive_it","dive");
  add_action("press_it","press");
  add_action("press_it","push");
  add_action("feed_it","feed");
}

feed_it(str) {
object bread;

  if((!str)||(str!="fishes")) {
    notify_fail("Feed what?\n");
    return 0;
  }
  if(!bread=present("bread",this_player())) {
    notify_fail("You're not carrying any bread!\n");
    return 0;
  }
  write("You pull the bread into little pieces and throw them into the\n"
      + "pond.\n");
  say(this_player()->query_name()+" throws some pieces of bread in the\n"
      + "pond.\n");
  food++;
  return 1;
}

press_it(str) {
  if((!str)||((str!="dispenser")&&(str!="button"))) {
    notify_fail("Press what?\n");
    return 0;
  }
  write("You press the button of the dispenser.\n");
  say(this_player()->query_name()+" presses the button on the dispenser.\n");
  call_out("bread_out",1);
  return 1;
}

bread_out() {
object bread;

  bread=clone_object("obj/food");
  bread->set_name("bread");
  bread->set_short("A piece of bread");
  bread->set_long("This is a piece of bread. It doesn't look very tasteful,\n"
                + "it's more for feeding animals.\n");
  bread->set_weight(1);
  bread->set_strength(1);
  bread->set_eater_mess("It tastes awful!\n");
  bread->set_eating_mess(" looks disgusted, eating a piece of old bread.\n");
  bread->set_value(10);
  move_object(bread,this_object());
  tell_room(this_object(),"A piece of bread falls out of the dispenser.\n");
}

dive_it() {
  return enter_it("pond");
}

enter_it(str) {
  if((!str)||(str!="pond")) {
    notify_fail("Enter what?\n");
    return 0;
  }
  write("It's too small!\n");
  return 1;
}

dismiss_it(str) {
  if((!str)||(str!="gardener")) {
    notify_fail("Dismiss who?\n");
    return 0;
  }
  if(!gardener) {
    notify_fail("There is no gardener here!\n");
    return 0;
  }
  write("You dismiss the gardener!\n");
  say(this_player()->query_name()+" dismisses the gardener.\n");
  call_out("gardener_leaves",1);
  return 1;
}

gardener_leaves() {
object rake;

  rake=present("rake",gardener);
  destruct(rake);
  tell_room(this_object(),"The gardener leaves is a puff of smoke.\n");
  destruct(gardener);
}


