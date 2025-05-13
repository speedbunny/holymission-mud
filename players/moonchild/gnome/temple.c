#define NUMBERS ({ "1", "2", "3", "4", "5" })
#define COLOURS ({ "blue", "red", "pink", "green", "turquoise" })

inherit "room/room";

int *types_here;
int *types_elsewhere;
int *crystals;

reset(arg) {
  tell_room(this_object(), "A small gnome walks in, dusts the pedestals, then leaves again.\n");
  crystals=allocate(5);
  types_here=random_array(5);
  if(arg) return;
  set_light(1);
  short_desc="Gnomish temple";
  long_desc="This is a gnomish temple. Five pedestals stand high above everything else in\n"
	+ "the room, while in the central point between them is a small lever.\n";
  dest_dir=({ "players/moonchild/gnome/gcent", "south" });
  items=({ "pedestal", "Call them pedestal 1, pedestal 2, pedestal 3, pedestal 4, or pedestal 5",
  	"pedestals", "Call them pedestal 1, pedestal 2, pedestal 3, or pedestal 4",
	"lever", "A lever is between two of the pedestals" });
  property=({ "no_teleport" });
  types_elsewhere=random_array(5);
}

query_prevent_shadow() {
  return 1;
}

clean_up() {
}

id(str) { return ::id(str) || str=="pedestal 1" || str=="pedestal 2"
		|| str=="pedestal 3" || str=="pedestal 4" || str=="pedestal 5";
}

long(str) {
  string no;
  int ped_no;
  if(!str || !sscanf(str,"pedestal %s",no)) return ::long(str);
  ped_no=member_array(no,NUMBERS);
  write(crystals[ped_no] ?
	"This is a strange, tall pedestal.\nOn it has been placed a " +
	COLOURS[types_here[ped_no]] + " crystal.\n" :
	"This is a strange, tall pedestal. It looks like you could put something on it.\n");
  return;
}

init() {
  ::init();
  add_action("_put", "put");
  add_action("_put", "place");
  add_action("_get", "get");
  add_action("_get", "take");
  add_action("_pull", "pull");
}

_put(str) {
  string clr,no,junk;
  int res,ped_no;
  object cr;
  if(!(res=sscanf(str,"%s crystal on pedestal %s",clr,no))) {
    if(sscanf("! " + str,"%s crystal on pedestal",junk)
	|| sscanf(str,"crystal on pedestal %s",junk)) {
      write("Put what colour of crystal on which pedestal?\n");
      return 1;
    }
    return;
  }
  if((ped_no=member_array(no, NUMBERS))==-1) {
    write("There isn't such a pedestal here.\n");
    return 1;
  }
  if(!(cr=present(clr + " crystal", this_player()))) {
    write("You don't have a " + clr + " crystal!\n");
    return 1;
  }
  if(crystals[ped_no]) {
    write("There is already a crystal on that pedestal.\n");
    return 1;
  }
  write("You place the crystal on the pedestal.\n");
  say(this_player()->query_name() + " places a " + clr
	+ " crystal on pedestal " + no + ".\n");
  if(!sscanf(file_name(cr),"players/moonchild/gnome/crystal#%s",junk)
	|| (member_array(clr, COLOURS)!=types_here[ped_no])) {
    tell_room(this_object(), "The crystal disappears in a flash of light!\n");
  }
  else crystals[ped_no]=1;
  destruct(cr);
  return 1;
}

_get(str) {
  string clr,no;
  int res,ped_no;
  str="! " + str;
  if(!(res=sscanf(str,"%s crystal from pedestal %s",clr,no))) {
    if(sscanf(str,"%s crystal from pedestal",clr)) {
      write("Which pedestal do you mean?\n");
      return 1;
    }
    return;
  }
  if((ped_no=member_array(no, NUMBERS))==-1) {
    write("There isn't such a pedestal here.\n");
    return 1;
  }
  write(crystals[ped_no] ?
	"You don't seem to be able to get your hand near enough to it!\n" :
	"There's no crystal on that pedestal!\n");
  return 1;
}

_pull(str) {
  if(str!="lever") return;
  write("You pull the lever.\n");
  say(this_player()->query_name() + " pulls the lever.\n");
  if(crystals[0] && crystals[1] && crystals[2] && crystals[3]
	&& crystals[4]) {
    object rm;
    write("You are thrown out of the room into somewhere different.\n");
    rm=clone_object("players/moonchild/gnome/comblock");
    rm->set_owner(this_player()->query_real_name());
    this_player()->move_player("X#" + file_name(rm));
  }
  crystals=allocate(5);
  types_here=random_array(5);
  return 1;
}

query_crystal_colour(arg) {
  int junk;
  if(!sscanf(file_name(previous_object()),
    "players/moonchild/gnome/crystal#%d", junk)) return random(5);
  return types_elsewhere[arg];
}

random_array(arg) {
  int *array;
  int i,l;
  status f;
  array=allocate(arg);
  i=-1;
  while(i<arg) {
    i+=!f;
    f=(i==arg);
    if(!f) array[i]=random(arg);
    l=-1;
    while(!f && l++<i-1) f=(array[i]==array[l]);
  }
  return array;
}
