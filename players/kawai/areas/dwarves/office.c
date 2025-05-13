inherit "room/room";

void reset(int arg)
  {clone_list=({1,1,0,"obj/money",({"set_money",7000}),
  2,1,"troll","/players/kawai/monst/cboss",0});
  set_light(1);
  short_desc = "Office";
  long_desc = "This is the lavishly decorated office of the Casino's "+
  "not so popular owner.  Various portraits adorn the "+
  "walls, and random piles of gold litter the floor.  In "+
  "the center of it all is his desk--and being a troll, there "+
  "is nothing on it (well, a few bones, but nothing of "+
  "interest.\n";
  smell = "The air is foul."; 
  dest_dir = ({"players/kawai/areas/dwarves/bossroom","west"});
  items = ({"paintings","Various paintings of relatives...most are ugly",
  "portraits","Paintings of distant (and still ugly) family members",
  "portrait","You're not sure if it is a grandmother or an uncle..",
  "office","Take a look around..",
  "desk","A bare desk...only a few bones and food scraps on it",
  "painting","This one is of himself....ugly bastard",
  "bones","Bones!","bone","What did you expect?",
  "gold","It's all over! (Well, if not, there WAS plenty)"});
  ::reset(arg);
  replace_program("room/room");}

