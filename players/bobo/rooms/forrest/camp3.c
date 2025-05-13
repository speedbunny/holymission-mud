inherit "room/room";
object tender, jack;
reset (arg) {
::reset(arg);
if (arg) return;
jack = clone_object("/players/bobo/monsters/jack");
transfer(jack,this_object());
jack = clone_object("/players/bobo/monsters/jack");
transfer(jack,this_object());
jack = clone_object("/players/bobo/monsters/jack");
transfer(jack,this_object());
tender = clone_object("/players/bobo/monsters/tender");
transfer(tender,this_object());
set_light(1);
short_desc="The lumberman's bar.";
long_desc=
"You have entered a small hut that has been converted into a tavern for the\n"+
"settlement.  The odd thing is however that only the lumberjacks make use of\n"+
"it.  The place looks seedy and it is very smoky.  There are tables set up\n"+
"all over the place, not all of them on their legs.  There are various\n"+
"liquids covering the floor.\n";
dest_dir=({
	"players/bobo/rooms/forrest/camp.c","out",
});
}
init() {
	add_action("order","order");
	add_action("order","buy");
	add_action("read","read");
::init();
}
read(str) {
   if (str=="sign") {
write("you look at the big menu on the wall, it reads:\n"+
"1.  Milk--for all the little girlies out there		15 coins \n"+
"2.  Coffee--It's a great little pick me up		40 coins\n"+
"3.  Beer--Now you're starting to become a real man.	80 coins\n"+
"4.  Wine--For all you wierdos who like it		200 coins\n"+
"5.  Hard liquor--Now you're talking.  Be a real man	1000 coins\n"+
"Now that you have read the menu buy something or leave.\n");
return 1;
}
}
order (str) {
	string name, short_desc, art, mess;
	int value, cost, strength, heal, i;
	object dummy;
if(!str) {
	write("The bartender mutters something about stupid people.\n");
	return 1;
	}
if (str == "milk" || str =="1") {
	mess="Alright firlie.  Have your milk.";
	heal=5;
	strength=1;
	value=15;
	art="alco";
}
else if(str == "coffee" || str == "2") {
	mess="Ah just what you needed; a hot cup of Joe.";
	heal=5;
	strength=-2;
	art="alco";
	}
else if(str == "beer" || str == "3") {
	mess="Time to tip a cool one back and relax.";
	heal=24;
	strength=8;
	value=80;
	art="alco";
	}
else if(str == "wine" || str=="4") {
	mess="About the best wine you can find...in the middle of nowhere.";
	heal=96;
	strength=15;
	value=200;
	art="alco";
	}
else if(str == "hard liquor" || str=="5") {
	mess="Now you're drinking with the big boys.  Can you handle it?";
	heal=175;
	strength=25;
	value=1000;
	art="alco";
	}
write("You pay " + value + " coins.\n");
this_player()->add_money(-value);
if(art=="alco") this_player()->heal_self(heal);
write(mess + "\n");
if(strength==50) say(this_player()->query_name()+" stumbles around for a bit.\n");
return 1;
}
