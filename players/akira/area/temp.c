inherit "room/room";
reset(tick){
if(tick)return;
set_light(1);
short_desc= ("In a Very Old Temple");
long_desc= ("This room ih huge! The walls are covered with many differnt "+
            "pictures. The pillars are set up so they form a large circle "+
            "in the center of the room. A thick layer of dust coverd just "+
            "about everything, and the air is very dry. You can tell that "+
            "no one has stepped foot in this temple in many years.\n");
items= ({ "pictures", "The pictures tell the story of a great battle. "+
                      "Near the end of the great summoner war, a young "+
                      "summoner chanced to open a rift, hoping to call "+
                      "forth a great monsters so he might gain power. "+
                      "The pictures then show a Greater god stepping "+
                      "out of the rift, and then killing the summoner. "+
                      "The next pictures show mages and fighters working "+
                      "together to stop this god. In a great battle "+
                      "the mages with the help of the fighters and other "+
                      "guilds, banished the god to a dimentional prison "+
                      "With this the great was was ended.",
         "pillars", "They seem to make a circle, maybe you could "+
                    "try to enter the circle?\n" });
dest_dir= ({ "/players/akira/area/temp1", "up" });
}
init(){
::init();
add_action("_enter", "enter"); }
_enter(str){
if(!str){
notify_fail("Enter what?\n");
return 0; }
if(str== "circle" ){
this_player()->move_player("up#players/akira/area/ryu1");
return 1;
}
}
