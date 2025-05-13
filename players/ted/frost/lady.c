inherit "room/room";
object lady, bottle, crown;
int got_box;

id(str) {
  if(::id(str)) return 1;
  return (str=="box" || str == "dresser");
}

long(str) {
  ::long(str);
  if(str=="dresser") {
    write("This is a huge teakwood dresser, covered with perfume bottles\n");
    write("makeup and other knick-knacks. There must be 30 or 40 drawers\n");
    write("and just as many cabinets. All in all it must weight at least\n");
    write("4000 pounds or more.\n");
    if(!got_box) write("There is a box sitting on a stand on the dresser.\n");
  }
  if(str == "box" && !got_box) {
    write("This small gold box is sitting all alone on a kind of\n");
    write("stand in the middle of the dresser.\n");
  }
}

init() {
  ::init();
 add_action("do_get"); add_verb("take");
 add_action("do_get"); add_verb("get");
}

reset(arg) {
  got_box = 0;
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Bed Room";
    long_desc =
"This is obviously a ladies bedroom. A large canopy bed takes up\n"+
"the entire northern wall, while a huge dresser and mirror fill\n"+
"the western and southwestern portions of the room. The smell\n"+
"of perfume still lingers in the air......\n";
    dest_dir = ({
"players/ted/frost/cave10", "southeast"
    });
    items = ({
"bed","This is a large canopy bed. The frame is carved rose wood and\n"+
      "the sheets are made of silk. It looks very comfortable",
"canopy","This canopy acts like a second ceiling to give the bed a\n"+
         "cozy feeling. The side drapes can also be drawn to give\n"+
         "added privacy",
"mirror","You see someone looking back at you!!!!!\n"+
         "\n\nYou realize it is yourself.....",
"drawers", "They seem to be full of clothes and stuff",
"cabinets", "They seem to be full of clothes and stuff",
"stand", "It is just a stand made of wood"
    });
  }
  if(!present("frost giant queen")) {
    lady = clone_object("players/ted/monsters/frost_giant_queen");
    move_object(lady, this_object());
    crown = clone_object("obj/armour");
    call_other(crown, "set_name", "the Frost Giant Queen's Crown");
    call_other(crown, "set_alias", "crown");
    call_other(crown, "set_type", "helmet");
    call_other(crown, "set_short", "The Frost Giant Queen's Crown");
    call_other(crown, "set_long",
"This is a pearl and platinum crown. It is very light and very expensive\n"+
"looking. It is also much too large for you to wear properly.\n");
    call_other(crown, "set_ac", 1);
    call_other(crown, "set_weight", 3);
    call_other(crown, "set_value", 3000);
    move_object(crown, lady);
    bottle = clone_object("obj/treasure");
    call_other(bottle, "set_id", "perfume bottle");
    call_other(bottle, "set_alias", "bottle");
    call_other(bottle, "set_short", "A Massive Bottle of Perfume");
    call_other(bottle, "set_long",
"This huge bottle of perfume is almost full. It also smells so strong\n"+
"monsters should be able to smell you coming a mile away.\n");
    call_other(bottle, "set_weight", 3);
    call_other(bottle, "set_value", 1250);
    move_object(bottle, lady);
    call_other("players/ted/random_magic","make_item",lady,19);
  }
}

do_get(str) {
 object box_obj, jewel, note;
 if(str == "box" && !got_box) {
  box_obj = clone_object("obj/container");
  call_other(box_obj, "set_name", "jeweled box");
  call_other(box_obj, "set_alias", "box");
  call_other(box_obj, "set_short", "A Jeweled Box");
  call_other(box_obj, "set_long",
"This gold inlayed box is set with gems and precious stones.\n");
  call_other(box_obj, "set_value", 750);
  call_other(box_obj, "set_weight", 2);
  call_other(box_obj, "set_max_weight", 4 );
  call_other(box_obj, "set_can_open", 1 );
  if(transfer(box_obj, this_player())) {
    write("You are carrying too much.\n");
    destruct(box_obj);
    return 1;
  }
  write("The box rattles as you lift it from the stand.\n");
  say(this_player()->query_name()+" takes the box from the dresser\n");
  got_box = 1;
  jewel = clone_object("obj/treasure");
  call_other(jewel, "set_id", "Jewels");
  call_other(jewel, "set_alias", "jewels");
  call_other(jewel, "set_short","The Frost Giant Queen's Jewels");
  call_other(jewel, "set_long",
"This set of jewels is fit to grace the neck and wrist of only\n"+
"the most elegant and beautiful.\n");
  call_other(jewel, "set_weight", 3);
  call_other(jewel, "set_value", random(1000)+2000);
  transfer(jewel, box_obj);
  note = clone_object("obj/treasure");
  call_other(note, "set_id", "note");
  call_other(note, "set_alias", "short note");
  call_other(note, "set_short","A short note");
  call_other(note, "set_read",
"Lovely Vivian,\nI love you with all my heart and all my soul.\n"+
"You are my life, my breath, my love....\n"+
"(and it keeps going like this for half a page)\n"+
"       With Love,\n             Thomes\n\n"+
"ps          Remember, the pen is mightier than the sword.\n"+
"(a hint: DON'T be greedy before you get what you want, be greedy after)\n");
  call_other(note, "set_weight", 1);
  call_other(note, "set_value", 0);
  transfer(note, box_obj);
  return 1;
 }
}
