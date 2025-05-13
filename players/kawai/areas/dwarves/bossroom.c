inherit "room/room";

void reset(int arg)  
  {set_light(1);
  short_desc = "Lobby";
  long_desc = 
  "You are in a small waiting room that separates "+
  "the Boss' office from the rest of the Casino.  The office "+
  "is to the east, and you can slip out to the Casino through "+
  "a small panel to the south.\n";
  smell = "The air is foul.";
  dest_dir = ({"players/kawai/areas/dwarves/casino","south",
  "players/kawai/areas/dwarves/office","east"});
  items=({"panel","A secret panel...what else do you need to know?",
  "office","You can't see all that much, but you notice some bones on the floor", 
  "bones","They look like human bones",
  "bone","The bone is nice and clean, as if somebody really enjoyed eating all that meat..", 
  "casino","You hear the screams and laughters of the patrons.  As you peak through\n"+
  "the panel, you get a glimpse of two Trolls kicking a gnome out the door.."});
  ::reset(arg);
  replace_program("room/room");}




