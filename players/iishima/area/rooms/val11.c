inherit "room/room";

void reset(int arg){

if (arg) return;
set_light(2);
short_desc="In a small town";
long_desc=("\
\n\
  This is the main part of the town.  Many people are strolling about. \n\
  Servants wander around doing their master's jobs.  The smell of fresh\n\
  fruits and vegetables fill your nostrils as you stroll down the street. \n\
  Children run about playing their games and the elders of the village stand\n\
  and talk. \n\
\n\
");
         
dest_dir=({"players/iishima/area/rooms/val12","west",
           "players/iishima/area/rooms/val10","east"});

items=({"children","These children are playing their little child like games",
        "elders","These elders stand around all day speaking of news and weather",
        "town", "The town is very old and run down.  Most of the inhabitants have moved on",
        "street", "The street is old and cracked.  It burns your feet as you walk on it",
        "people", "There are a few people walking up and down the streets",
        "servants","These poor souls have the tough job of doing everything their masters want"});

clone_list = ({ 1, 3, "peasant", "players/iishima/area/monsters/zalpeas", 0, 
               -1, 1, "shovel", "players/iishima/quest/shovel", 0 });

::reset(arg);
replace_program("room/room");
}
