inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc=("On top of a mountain");
long_desc=("There is nothing much on this part of the mountain, save\n"+
           "a bunch of rocks. The only thing of notice in this area is\n"+
           "the view you get of the world below.\n");
items=({"view", "You see a world being destroied"});
dest_dir=({"players/akira/vag/m3","east" });
property=({"vag_quest", "no_teleport"});
}
