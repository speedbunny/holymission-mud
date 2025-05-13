inherit "room/room";

void reset(int arg){
if (arg) return;
set_light(2);
short_desc="In a small town";
long_desc=("\
\n\
  This is the main part of the town.  Many people are strolling about. \n\
  Servants wander around doing their master's jobs.  Womem stroll the streets\n\
  buying fruit and eggs.  Stray cats walk down the alleys searching the\n\
  garbage cans for food. \n\
\n\
");
         
dest_dir=({"players/iishima/area/rooms/val11","west",
           "players/iishima/area/rooms/val9","northeast"});

items=({"cats","These cats look like they have not been fed in weeks",
       "cat","This cat is so skinny that you can see is skeleton comming through the skin",
       "women","These women are strolling about buying food for their family",
       "alley","The alleys are dark and damp. They are the main hideout for cats",
       "servants","These poor souls have the tough job of doing every thing their master says"});

clone_list = ({ 1, 3, "peasant", "players/iishima/area/monsters/zalpeas", 0,
               -1, 1, "shovel", "players/iishima/quest/shovel", 0 });
::reset(arg);
replace_program("room/room");
}
