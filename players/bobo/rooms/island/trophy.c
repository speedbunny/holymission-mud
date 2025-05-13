/*	I don't want players entering this area through the ring, that's
	why there isn't an exit to here from the ring.  it's there to 
	get combatants to the ring w/o going through the entire place */
inherit "room/room";
string pressed;
string LONG;
reset (arg) {
if (arg) return;
set_light(1);
pressed=0;
short_desc="The trophy room.";
LONG=
"This is a large impressive room with many stuffed and mounted animals\n"+
"both on the wall and in cases placed around the room.  These animals\n"+
"are not just normal animals, they are known for their skill and\n"+
"agility in killing their prey.  But it is obvious someone bested\n"+
"them, animals like the tiger, puma, bear, wolf, mountain lion,\n"+
"and wolverine.  Also in cases spaced around the room there are\n"+
"ancient oriental melee weapons.  The one that really catches your\n"+
"eye however is not some conventional weapon but instead a claw of\n"+
"some sort.  To the north there is an exit going to the ring.\n";
   no_obvious_msg="";
items=({
	"tiger","A large stuffed tiger in a glass case",
	"puma","Just a head mounted on a plaque",
	"bear","An overtwhelmingly large animal standing on it's cack legs",
	"wolf","Cold lifeless eyes stare at you from the head on the wall",
	"mountain lion","A large cat sitting in the sentinal position",
	"wolverine","Though dead this animal still looks dangerous",
	"weapons","Besides the claw there are various others around",
	"others","Weapons including swords, tonfa, nunchuku and sais",
	"swords","Mostly oriental, including a katana and a wooden one",
	"katana","Very ornate, it would probably break in battle",
	"wooden one","A simple wooden sword",
	"tonfa","These rice beaters make excellent weapons",
	"nunchuku","More for show than purpose, this set is very old",
	"sais","Tied around two sais are red and black ribbon",
	"claw","A curious looking weapon.  There is something under it..",
});
}
init () {
::init();
add_action("push","push");
add_action("search","search");
add_action("_out","out");
add_action("_south","south");
   if(pressed) {
      long_desc=LONG+
         "    There are three obvious exits: out, south, and west\n";
      add_action("_west","west");
   }
   else long_desc=LONG+
      "    There are two obvious exits: out and south\n";
}

_west() { 
   this_player()->move_player("west#players/bobo/rooms/island/m2.c");
   return 1;
}

_out() {
   this_player()->move_player("out#players/bobo/rooms/island/ring");
   return 1;
}

_south() {
   this_player()->move_player("south#players/bobo/rooms/island/hall2");
   return 1;
}

push(str) {
if(str=="button" && !pressed) {
write("A panel opens up in the west wall.\n");
say("A panel slides open in the west wall, revealing an exit.\n");
pressed=1;
init();
return 1;
}
if(str=="button" && pressed) {
   write("You press the button but nothing happens.\n");
   return 1;
}
}
search(arg) {
if(arg !="claw") return 0;
write("There is a button under the claw.\n");
   say(this_player()->query_name()+" searches the room.\n");
return 1;
}
