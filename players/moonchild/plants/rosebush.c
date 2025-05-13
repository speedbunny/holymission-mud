#pragma strict_types

#define TR(x) tell_room(environment(),x)
#define DELAY 120

int no,age;
string type;

void die();

void reset(int arg) {
  if(arg) return;
  if(file_name()!="players/moonchild/plants/rosebush")
	call_out("grow",DELAY,0);
}

status id(string str) {
  return str=="bush" || str=="rosebush" || str=="rose bush";
}

string short() {
  switch(age) {
    case 0..1:
	return 0;
	break;
    case 2..3:
	return "A small rose bush with no flowers on it";
	break;
    case 4..5:
	return "A moderate-sized rose bush with no flowers on it";
	break;
    default:
	if(age==6 || !no) return "A large rose bush with no flowers on it";
	if(no==1) return "A large rose bush with one flower on it";
	return "A large rose bush with " + no + " flowers on it";
	break;
  }
}

void long() {
  if(age<2) return;
  write(short() + ".\n");
}

void set_type(string str) { type=str; }

void set_no(int i) { no=i; }

void init() {
  object th;
  add_action("pick", "pick");
  if(!random(15) && age>1 && interactive(this_player())
	&& !this_player()->query_immortal()
	&& !present("rose_thorn", this_player())) {
    move_object(th=clone_object("players/moonchild/plants/rosethorn"),
	this_player());
    th->set_type(type);
    write("A thorn from the rose catches onto your clothing.\n");
  }
}

status pick(string str) {
  object rose;
  if(str!="rose" && str!="flower") return 0;
  if(!no || age<7) return 0;
  if(transfer(rose=clone_object("players/moonchild/plants/rose"),
	this_player())) {
    destruct(rose);
    write("You are carrying too much!\n");
  } else {
    no--;
    rose->set_up(type);
    say((string)this_player()->query_name() + " picks a rose.\n");
    write("You pick a rose.\n");
  }
  return 1;
}

void grow() {
  if(!set_light(0)) {
    if(age>1) die();
    else destruct(this_object());
    return;
  }
  switch(age++) {
    case 1:
	TR("Suddenly a small rose bush grows out of the ground.\n");
	break;
    case 2..5:
	TR("The rose bush continues to grow.\n");
	break;
    case 6:
	TR("The rose bush bursts into flower!\n");
	break;
    case 20:
	return die();
	break;
  }
  call_out("grow",DELAY,0);
}

void die() {
  TR("Suddenly the rose bush magically withers and dies.\n");
  destruct(this_object());
}
