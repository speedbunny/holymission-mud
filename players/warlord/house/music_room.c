inherit"room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Music Room.\n";
long_desc="This is Skyler's music room, where she comes to relax and relieve stress.\n"+
"In one corner you see a beautiful baby grand piano.\n"+
"To the west you see a beautiful window with a great view.\n";
dest_dir=({
"players/warlord/house/foyer","east",
});
items=({
"window","You can see a beautiful garden from this window",
"view","You see a beautiful garden from this view",
"piano","It looks beautiful. Why not try to play it. There is some sheet music\n"+
"on the piano",
"music","It looks to be the music for Il Barbiere di Siviglia. It looks hard to play",
});
}
init() {
::init();
add_action("play","play");
}
play(str) {
if(!str) {
write("You can't play that.\n");
 return 1;
 }
if (this_player()->query_real_name()=="rachel") {
write("You start playing the piano beautifully.\n");
say("Skyler plays the piano beautifully.\n");
return 1;
}
else {
say(this_player()->query_name()+" starts to play the piano but is starting to hurt peoples ears.\n");
write("You start to play the piano, but you keep hitting bad notes and are \n"+
"hurting peoples ears.\n");
return 1;
}
}
