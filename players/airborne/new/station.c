inherit "room/room";

reset(arg) {
    if(!arg) {
        set_light(1);
	short_desc="Central point";
        long_desc=
"This is the central point. A lot of traffic seems to have passed through "+
"here. If you just wait long enough, some transport might pick you up. "+
/*
"The complete newbie area is to the east and there is a sign above a small "+
"crack to the south. \n";
*/
"The complete newbie area is to the east.\n";
	dest_dir = ({"room/vill_road2", "up", 
		"players/airborne/new/newbie1", "east", });

/*
	items= ({"crack", "A small crack in the wall surrounded by a strange glow",
	"sign", "A colorful sign with instructions on it. Maybe you should read it", });
*/

    }
}

init(){
 ::init();
/*
	add_action("read","read"); add_action("enter", "enter");
*/
	add_action("east", "east");
	}


/*
read(){
     write("The sign reads:\n");
     write("\n");
     write("Welcome to the home of the Trogs!\n");
     write("A long time ago, one of our greatest wizards placed a spell over\n");
     write("this entrance to keep out people who would pick on us. If you are too\n");
     write("powerful, you will not be able to enter. Peaceful folk are welcome at\n");
     write("all times.\n");
	return 1;
	}
enter(str){
  if(str!="crack") return;
	this_player()->move_player("through the crack#players/airborne/new/cave1");
	return 1; }
 else {
	write("Enter what?\n");
	return ;
	}
}
*/
east(){
  if((this_player()->query_level()<=5)||(this_player()->query_newwiz())){
   this_player()->move_player("east#players/airborne/new/newbie1");
	return 1; }
  if(this_player()->query_real_name()=="nokey"){
    write("You did it. You won your bet with Airborne, and thus you are\n"+
          "able to enter the Complete Newbie Area without being a newbie.\n");
    say(this_player()->query_name()+" enters the Complete Newbie Area.\n");
    this_player()->move_player("east#players/airborne/new/newbie1");
    return 1;
  }
  if(this_player()->query_immortal() && !this_player()->query_newwiz()) {
    this_player()->move_player("east#players/uglymouth/appr/appr1");
    return 1;
  }
   else {
	write("You are too powerful to enter such a newbie area.\n");
	return 1; }
}
