inherit "room/room";
 
#define TP   this_player()
 
int called_men;
 
void reset(int arg) {
  called_men = 0;
  ::reset(arg);
  if(arg) return;
 
  set_light(1);
  no_castle_flag = 1;
  short_desc = "Police quarters";
 
  long_desc =
    "Your in the sleeping quarters of the local police station.  This "+
    "is a place where the police coming off shift can catch a couple hours "+
    "rest, have some doughnuts or just hang out for a while.  There are "+
    "few furnishings in this room but they include three beds, a couch, "+
    "and a table.  You also notice something is different about this "+
    "room as it has a pole leading through a hole in the floor.\n";
 
  items = ({
    "pole","If there's an alarm, the policemen can slide down this pole. "+
      "Perhaps you can too",
    "wardrobe","Maybe another entrance to fairyland? Or something else",
    "hole","The pole leads through this hole down",
    "beds","The beds are not much more than cots with pillows on them",
    "couch","An old beat up couch.  It looks like a second hand "+
      "store wouldn't buy it",
    "table","A surprisingly good looking table considering the rest "+
      "of the furnishings",
  });
 
  dest_dir = ({
    "players/bobo/krooms/vill/wardrobe","north",
  });

  hidden_dir = ({
    "players/bobo/krooms/vill/police_office","down",
  });
}
 
void init() {
  ::init();
  add_action("_slide","slide");
  add_action("_enter","enter");
}
 
status move(string str) {
  if(!str)
    str = query_verb();
 
  switch(str) {
    case "down" :
      tell_object(TP,
                  "You grasp the pole and slide down.\nA funny feeling.\n");
      say(TP->query_name() + " slides down the pole.\n");
      tell_room("players/bobo/krooms/vill/police_office",
                TP->query_name() + " slides down the pole.\n");
      break;
  }
  return ::move(str);
}
 
alarm(direction,criminal) {
  object man,leader;
  int    i;
 
  if(called_men > 2) return;
  called_men++;
  leader = clone_object("players/bobo/kmonster/policeleader");
  move_object(leader, this_object());
  leader->set_criminal(criminal);
  leader->set_direction(direction);
  for(i=1; i<3; i++) {
    man = clone_object("players/bobo/kmonster/policeman");
    man->set_leader(leader);
    man->set_criminal(criminal);
    move_object(man, this_object());
    man->init_command("down");
  }
  leader->init_command("down");
  leader->start_walking();
}
 
status _slide(string str) {
  switch(str) {
    case "down":
    case "pole":
    case "down pole":
    case "on pole": {
      write("You grasp the pole and slide down.\n");
      say(TP->query_name() + " slides down the pole.\n");
      tell_room("players/bobo/krooms/vill/police_office",
                TP->query_name() + " slides down the pole.\n");
      move_object(TP, "players/bobo/krooms/vill/police_office");
      TP->look();
      return 1;
    }
    default: {
      notify_fail("Slide down what?\n");
      return 0;
    }
  }
}
 
status _enter(string str) {
  if(str != "wardrobe") {
    notify_fail("Enter what?\n");
    return 0;
  }
 
  write("You enter the wardrobe.\n");
  TP->move_player("into the wardrobe#players/bobo/krooms/vill/wardrobe");
  return 1;
}
