inherit "room/room";

void reset(int arg){
if (arg) return;
set_light(2);
short_desc="Throne Room";
long_desc=("You have entered the throne room of the mystical Prince of Insufficient Light.\
  The room is decorated lavishly.  A golden chandelier sway slowly over The Prince's thron\
e.  Many animal heads are hanging on the walls.\n\n");
dest_dir=({"players/iishima/area/rooms/cave10","up"});
items=({"heads","These are heads of many exotic beasts which are now extinct",
"walls", "You see many animal heads hanging on the walls",
"room", "The room is lavishly decorated.  It must be part of the Prince's throne room",
"decor", "The decor in this room is of exquisit taste",
"decorations", "The decor of this room is very elegant",

        "head","This is he head of one of the last Yazokins. They are now extinct",
        "throne","The throne is solid gold and is decorated with rubies and emeralds",
        "chandelier","This chandelier looks like it is made of pure diamond",
        "bell","This bell is made of solid gold"});

clone_list = ({ 1, 1, "prince", "players/iishima/area/monsters/prince", 0,
                2, 1, "cauldron", "players/iishima/quest/cauldron", 0 });
::reset(arg);
replace_program("room/room");
} 
