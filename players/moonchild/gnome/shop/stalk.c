#define TR(x) tell_room(environment(),x)
#define DELAY 30

int age,watered;

reset(arg) {
  if(arg) return;
  if(file_name()!="players/moonchild/gnome/shop/stalk")
    call_out("grow",DELAY,0);
}

water_me() { watered=1; }

id(str) { return str=="stalk" || str=="beanstalk" || str=="bean stalk"; }

short() {
  switch(age) {
    case 0..1:
	return 0;
	break;
    case 2..3:
	return "A small bean stalk";
	break;
    case 4..5:
	return "A moderate-sized bean stalk";
	break;
    default:
	return "A massive bean stalk, at least 50 feet high";
	break;
  }
}

long() {
  if(age<2) return;
  write(short() + ".\n");
  return;
}

init() { add_action("climb", "climb"); }

climb(str) {
  if(!id(str)) return;
  if(age<6) {
    write("It's not thick enough to climb yet!\n");
    return 1;
  }
  if(file_name(environment())!="players/moonchild/gnome/wroad3") {
    write("You climb up the bean stalk, see there's nothing to see, and climb back down.\n");
    say(this_player()->query_name() + " climbs up and down the beanstalk.\n");
  }
  else {
    write("You climb up the beanstalk.\n");
    this_player()->move_player("up#players/moonchild/gnome/ledge");
  }
  return 1;
}

grow() {
  if(!set_light(0)) {
    if(age>1) die();
    else destruct(this_object());
    return;
  }
  switch(age++) {
    case 1:
	TR("Suddenly a small bean stalk grows out of the ground.\n");
	break;
    case 2..4:
	TR("The bean stalk continues to grow.\n");
	break;
    case 5:
	if(!watered) {
	  TR("The bean stalk seems to have got dried out and ...\n");
	  return die();
	}
	TR("The bean stalk suddenly shoots about fifty feet into the air!\n");
	break;
    case 20:
	return die();
	break;
  }
  call_out("grow",DELAY,0);
}

die() {
  TR("Suddenly the bean stalk magically withers and dies.\n");
  destruct(this_object());
}
