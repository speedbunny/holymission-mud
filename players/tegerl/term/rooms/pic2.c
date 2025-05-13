
inherit "room/room";
#define PATH "players/tegerl/term/rooms/"

void reset(int arg) {
if (!arg);
{
    set_light (1);
short_desc="In the green";
long_desc=
      "You are, well you are at a very odd place. The grass is that big, "+
      "that even palms would be smaller than this. There is a big mountain "+
      "and there is a big hole on the foot of that mountain. You realize "+
      "another and very odd object here. It is some kind of giant wooden square. "+      
      "You think that this object could be the leg of a huge table. "+
      "Next to the square wood lies some cake.\n";
  

items=({ 
        "grass", "The grasshalms are even bigger than palms",
        "grasshalm", "There are so many, you almost think it is a forest",
        "grasshalms", "There are so many, you almost think it is a forest",
        "mountain", "This mountain seems to be a giant termites-hill",
        "termites-hill", "This mountain seems to be a giant termites-hill",
        "hill", "This mountain seems to be a giant termites-hill",
        "wooden square", "Seems to be a giant leg of a table",
        "square", "Seems to be a giant leg of a table",
        "leg", "Seems to be a giant leg of a table",
        "hole", "You see a hole at the foot of the hill. It looks like an entrance of some kind.",
        "cake", "The cake looks tasty and the label says:\n "+
           "EAT ME",
});

dest_dir=({
   "players/tegerl/term/rooms/path1", "north",
 });

}
}

init() {
  ::init();
   add_action("do_get","get");
   add_action("do_get","take");
   add_action("do_eat","eat");
   add_action("do_enter","enter");
}

int do_get(string str){
  if (str == "all"){
write("You can't take the cake, try to eat it.\n");
return 0;}
  if (str == "cake"){
  if (!present("cake",this_object())){
write("You can't take the cake, try to eat it.\n");
return 1;}
return 0;}
return 0;
}

int do_eat(string str){
 if (str == "cake" || !str){
write("You eat a piece of the cake.\n");
write("Suddenly you start to grow!!!!!!.\n");
say(this_player()->query_name()+" eats a piece of the cake.\n");
say("Suddenly "+this_player()->query_caps_name()+" starts to grow!!!!!!.\n");
this_player()->move_player(" #/players/tegerl/term/rooms/pic1");
return 1;}
return 0;
}
    
int do_enter(string str){
 if (str == "hole"){
write("You enter the hole.\n");
say(this_player()->query_caps_name()+" leaves into the hole.\n");
this_player()->move_player(PATH+"way1");
return 1;}
return 0;
}

