/* KITCHEN.C, Programmed by Ethereal Cashimor */
/* 090693: Started programming */
/* 210793: Removed say bug */
/* 121093: Removed typo */
inherit "room/room";
#include "/obj/lw.h"

int fuel;

reset(arg) {
  if(!arg) {
    short_desc="The kitchen";
    long_desc="This is a small kitchen. There is a hearth here.\n";
    set_light(1);
    items=({"hearth","@@hearth_description@@",
            "kitchen","Clean, except for a black spot near the hearth"});
    smell="There is a clean smell here.";
    dest_dir=({"players/cashimor/extend/corridor","north"});
  }
  if(property) {
    tell_room(this_object(),lw("The fire in the hearth makes a cracking "
                             + "noise.\n"));
    fuel--;
    if(!fuel) {
      tell_room(this_object(),"The fire stops burning.\n");
      property=0;
    }
  }
}

hearth_description() {
string text;

  text="The hearth is small, and has a place to hang a kettle or bucket";
  if(property) text+=". There is a fire burning in the hearth";
  if(!fuel) text+=". The hearth is empty";
  if(fuel==1) text+=". There is only one piece of wood left in the hearth";
  if((fuel==2)||(fuel==3)) {
    text+=". There are a few pieces of wood in the hearth";
  }
  if((fuel>3)&&(fuel<8)) {
    text+=". There is a small amount of wood in the hearth";
  }
  if(fuel>7) text+=". The hearth is filled with wood";
  return lw(text);
}

init() {
  ::init();
  add_action("put_it","put");
  add_action("get_it","get");
  add_action("extinguish_it","extinguish");
  add_action("light_it","light");
}

extinguish_it(str) {
  if((!str)||(str!="hearth")) {
    notify_fail("Extinguish what?\n");
    return 0;
  }
  if(!property) {
    notify_fail("But the hearth isn't burning!\n");
    return 0;
  }
  write("You extinguish the hearth.\n");
  say(this_player()->query_name()+" extinguishes the hearth.\n");
  write("That was not very nice, you should better have left the fire on.\n");
  this_player()->add_alignment(-50);
  property=0;
  return 1;
}

light_it(str) {
  if((!str)||(str!="hearth")) {
    notify_fail("Light what?\n");
    return 0;
  }
  if(property) {
    notify_fail("But the hearth is already burning!\n");
    return 0;
  }
  if(!fuel) {
    notify_fail("There is nothing in the hearth to light!\n");
    return 0;
  }
  if(!present("lighted_torch",this_player())) {
    notify_fail("You don't have anything to light it with!\n");
    return 0;
  }
  property=({"has_fire"});
  write("You make a fire in the hearth.\n");
  say(this_player()->query_name()+" makes a fire in the hearth.\n");
  write("The warmth gives you a cosy and pleasant feeling.\n");
  this_player()->heal_self(
    (this_player()->query_max_hp()+this_player()->query_max_sp())/10);
  return 1;
}

get_it(str) {
string item;

  if(sscanf(str,"%s from hearth",item)!=1) {
    notify_fail("Get what from what?\n");
    return 0;
  }
  write("You don't want to dirty your hands in that hearth!\n");
  return 1;
}

put_it(str) {
string item;
object thing;

  if(sscanf(str,"%s in hearth",item)!=1) {
    notify_fail("Put what in what?\n");
    return 0;
  }
  if(!(thing=present(item,this_player()))) {
    notify_fail("You don't have that with you!\n");
    return 0;
  }
  if(!thing->id("can_light")) {
    notify_fail(lw("That is not something you would generally put in an "
                 + "hearth.\n"));
    return 0;
  }
  fuel++;
  write("You put the "+item+" into the hearth.\n");
  say(lw(this_player()->query_name()+" puts "+lower_case(thing->short())
       + " in the hearth.\n"));
  if(!property) {
    if(thing->query_is_lit()) {
      tell_room(this_object(),"A fire starts burning in the hearth!\n");
      property=({"has_fire"});
    }
  }
  destruct(thing);
  return 1;
}

door_knock() {
  tell_room(this_object(),"You hear someone knocking on the front door.\n");
}

light_text(str) {
  write("You hold the "+str+" in the hearth to light it.\n");
  say(lw(this_player()->query_name()+" lights a "+str+", using the fire in "
       + "the hearth.\n"));
}




