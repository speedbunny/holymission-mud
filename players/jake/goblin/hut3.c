inherit "room/room";
reset (arg) {
if (arg) return;
set_light(3);
short_desc = "hut3";
long_desc = "You have entered an abandoned hut.\n"
+  "Some old furniture lies in a heap on the floor.\n"
+ "There appears to be a hole in the floor.\n";
items = ({
"furniture","Broken chairs and a table",
"hole","A dark hole in the floor.\nI wonder what lurks down there?",
});
dest_dir = ({
"players/jake/goblin/gob3","north",
});
}
init() {
::init ();
add_action("down");add_verb("down");
}
down(str) {
if (str != "hole") return;
call_other(this_player(),"move_player","down hole#/players/jake/goblin/hole");
return 1;
}
