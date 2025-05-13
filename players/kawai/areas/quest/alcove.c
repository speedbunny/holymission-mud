inherit "room/room";

void reset(int arg) 
  {clone_list=({1,5,"fungus","obj/food",({"set_name","fungus",
  "set_short","A strange fungus",
  "set_long","It looks edible, although rather disgusting.\n",
  "set_eater_mess","Yummie Mushrooms!!\n",
  "set_eating_mess"," eats some fungus.\n",
  "set_strength",75,
  "set_value",500,
  "set_weight",1})});
  set_light(1);
  short_desc = "Alcove";
  long_desc ="You are in a small alcove that provides a safe haven from the "+
  "rest of the world.\n";
  smell = "The air smells of death and decay.";
  dest_dir = ({"players/kawai/areas/quest/inner","northwest"});
  items = ({"cave","It is cold and damp",
  "alcove","The small hole is dark and damp, but seems like a good hiding spot should\n"+
  "trouble arise",
  "hole","You are in it!",
  "passage","It is cold and damp"});
  ::reset(arg);
  replace_program("room/room");}
