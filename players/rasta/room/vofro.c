id(s) { return s=="booth" ||
		s=="voting booth" ||
		s=="small booth"; }
short() { return "There is a small booth to the west"; }
long() {
	write("You see a very small black booth to the west.\n"+
	"A sign on it says: 'Voting booth'.\n");
}
init(){add_action("enter", "enter");
add_action("west", "west");
}
enter(str)
{
if (id(str)) { west(); return 1; }
}
 
west(str)
{
if (str && str!="") return 0;
this_player()->move_player("west#wd/thorax/misc/voting");
return 1;
}
