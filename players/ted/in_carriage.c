object ob, dest;
int test_time, castle, town, moving;
string what;

set_find(obj) { ob = obj; }

short() {
	return "Inside Carriage";
}

id(str) {
 return (str=="window" || str=="windows" || str=="cushion" || str=="cushions");
}

long(str) {
 if(str == "window" || str == "windows") {
	if(town) write("You see the village streets through the window.\n");
	if(castle) write("You see a cobblestone path through the window.\n");
	return 1;
  }
 if(str == "cushion" || str == "cushions") {
	write("They look quite comfortable. You lose interest in them.\n");
	return 1;
  }
 write("You are inside a plush carriage. Cushions and soft pillows make\n");
 write("the seats very comfortable. The windows let in enough light to\n");
 write("see by. The Driver is waiting for you to type 'ride'.\n");
 write("  The only exit is out.\n");
 return 1;
}

init() {
 add_action("ride"); add_verb("ride");
 add_action("out"); add_verb("out");
}

out() {
 if(!moving) {
  if(castle)
	call_other(this_player(),"move_player","out of the carriage#players/ted/path/path1");
  if(town)
	call_other(this_player(),"move_player","out of the carriage#room/vill_road1");
  return 1;
 }
 write("The carriage is moving right now!\n");
 return 1;
}

reset(arg) {
 if(arg) return 1;
 set_light(1);
 castle = 0;
 town = 1;
 moving = 0;
}

ride() {
 if(moving) {
	write("The Driver says: We are already on our way.\n");
	return 1;
  }
 write("The carriage lurches into motion.\n");
 say("The carriage lurches into motion.\n");
 test_time = 3;
 tell_room(environment(ob),"The horses pull the carriage away.....\n");
 move_object(ob, "room/void");
 moving = 1;
 set_heart_beat(1);
 return 1;
}


heart_beat() {
 if(!moving) {
	set_heart_beat(0);
	return 1;
  }
 if(test_time >= 0) {
	tell_room("players/ted/in_carriage", "The carriage continues....\n");
	test_time -= 1;
	return 1;
  }
 if(castle) {
	castle = 0;
	town = 1;
	moving = 0;
	tell_room("players/ted/in_carriage", "The carriage comes to a halt....\n");
 move_object(ob, "room/vill_road1");
 tell_room(environment(ob),"A horse drawn carriage arrives.....\n");
	tell_room("players/ted/in_carriage", "You see the village streets through the window.\n");
	set_heart_beat(0);
	return 1;
  }
 if(town) {
	castle = 1;
	town = 0;
	moving = 0;
	tell_room("players/ted/in_carriage", "The carriage comes to a halt....\n");
 move_object(ob, "players/ted/path/path1");
 tell_room(environment(ob),"A horse drawn carriage arrives.....\n");
	tell_room("players/ted/in_carriage", "You see a cobblestone path through the window.\n");
	set_heart_beat(0);
	return 1;
  }
}

