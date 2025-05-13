
inherit "room/room";
#define PATH "/players/tegerl/term/rooms/"

void reset(int arg) {
if (!arg);
{
    set_light (1);
short_desc="Picnic place";
long_desc=
      "This is a lovely little place near a forest. You are under the "+
      "shadow of the trees, which are south and east from here. To the "+
      "west a little brook happily flows to a river. The water murmurs "+
      "quietly and you feel relaxed and happy.\n"+
      "It seems that you are not the first one who found this nice place "+
      "as someone already placed a table and benches here, just made to "+
      "picnic here. Near the table you see a termites-hill.\n";
  
dest_dir=({
    "/room/jetty", "north",
  });


items=({ 
       "forest", "The trees of the forest give shadow to this place.\n"+
                 "It is too tight to enter anyway",
       "tree", "There are many trees.....in the forest",
       "trees", "There are many trees.....in the forest",
       "brook", "This little brook's water murmurs quiet as it flows happily",
       "little brook", "This little brook's water murmurs quiet as it flows happily",
       "water" "This little brook's water murmurs quiet as it flows happily",
       "bench", "Wooden benches, sit down and rest",
       "benches", "Wooden benches, sit down and rest",
       "bottle", "The bottle is full and the label reads:\n"+
            "DRINK ME",
       "termites-hill", "Just an ordinary ant-hill",
       "hill", "Just an ordinary ant-hill",  
       "table", "This is a wooden table and there is a bottle standing on it",
});

}
}

init() {
  ::init();
   add_action("do_sit","sit");
   add_action("do_get","get");
   add_action("do_get","take");
   add_action("do_drink","drink");
}

int do_sit(string str){
   if (str == "bench" || str == "on bench" || str == "down"){
write("You sit down on the bench and enjoy the beauty of this place.\n");
say(this_player()->query_name()+" sits down on the bench and enjoys the beautiness of the place.\n");
return 1;}
return 0;
}

int do_get(string str){
  if (str == "all"){
write("You can't take the bottle, try to drink.\n");
return 0;}
  if (str == "bottle"){
   if (!present("bottle",this_object())) {
write("You can't take the bottle, try to drink.\n");
return 1;}
return 0;}
return 0;
}

int do_drink(string str){
 if (str == "bottle" || !str){
write("You take the bottle and drink.\n");
write("Suddenly you start to shrink!!!!!!.\n");
say(this_player()->query_name()+" takes the bottle and drinks.\n");
say("Suddenly "+this_player()->query_name()+" starts to shrink!!!!!!.\n");
this_player()->move_player(" #/players/tegerl/term/rooms/pic2");
return 1;}
return 0;
}







