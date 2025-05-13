inherit"players/warlord/NEWSTUFF/room";
int i;
#define TP this_player()
#define TPN TP->query_name()
reset(arg) {
i=0;
if (arg) return;
short_desc="Under the forest";
long_desc="This room is dark but you can make out a little spring in the "+
          "corner.\n You hear noises coming from under you.\n";
set_light(0);
items=({
"spring","You see a spring of what looks like water flowing in it. Take a drink",
});
dest_dir=({
"/players/warlord/quest/dungeon/below3","west",
"/players/warlord/quest/dungeon/below8","down",
});
return 1;
}
init () {
::init ();
add_action("drink","drink");
}
drink(str) {
if (i<3) {
if (str=="from spring"||str=="water") {
write("You take a drink from the spring.\n");
say (TPN+" takes a drink from the spring.\n");
TP->heal_self(5);
i=i+1;
return 1;
}
return 1;
}
else {
write ("The spring has gone dry.\n");
return 1;
}
return 1;
}
