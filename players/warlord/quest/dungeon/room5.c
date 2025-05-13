inherit"players/warlord/NEWSTUFF/room";
reset (arg) {
 if (arg) return 1;
set_light(1);
short_desc="Plush forest";
long_desc="This part of the forest is very dark and gloomy. You see\n"
         +"a strange looking tree too.\n";
items= ({
 "tree","The tree looks hollow, can you enter it?",
 "forest","The forest is very dense here",
        });
 dest_dir= ({
 "/players/warlord/quest/dungeon/room4","east",
           });
return 1;
}
init () {
add_action("enter","enter");
  ::init();
}
enter(str){
if (str=="tree"){
this_player()->move_player("into tree#players/warlord/quest/dungeon/below1");
return 1;
 }
}
