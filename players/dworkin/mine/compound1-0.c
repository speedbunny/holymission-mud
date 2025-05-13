inherit "/room/room.c";

#define GATEMAX 15
int gate_position;

int query_door_state();
int query_door_open();  
void set_door_state(int s);
void update_door();


void reset(int arg) {
  ::reset(arg);
    if (arg) return;

    set_light(1);
    short_desc="In the mine compound";
    update_door();
    
    // Set up the gate (only when gate_position > GATEMAX will the gates open)

      gate_position = 0;

      items = ({
	"mist", "It swirls and moves like it was alive",
	"cobbles", "Standard stone cobbles. They've been rubbed smooth by the amount of traffic and, what with the dampness and the dirt, look quite slippy",
	"building", "The building looks like it might house the lifts to the mine. Originally built with red sandstone, the combination of dust and dirt have turned the stones black",
	"forecourt", "Now that the mine has been closed, the foreground is largely empty, save for the occasional mound of muck",
	"muck", "Yuck! The muck is black and slimy.",
	"dirt", "Yuck! The muck is black and slimy.",
	"gates", "The wrought iron gates, although rusted in parts, still look fairly strong. Standing about 8 feet tall they look like they could repel all but the largest beasts", 
	"gate", "The wrought iron gates, although rusted in parts, still look fairly strong. Standing about 8 feet tall they look like they could repel all but the largest beasts", 
	"fence", "Like the gates, the fence has been made out of wrought iron, and is around 8 feet tall",
      });
    
    dest_dir=({
      "players/dworkin/mine/start", "south",
      "players/dworkin/mine/compound1-2", "north",
      "players/dworkin/mine/compound0-0", "west",
      "players/dworkin/mine/compound2-0", "east"
    });
    
    //  replace_program("room/room");
}

void init() {
  ::init();
  add_action("open_gate","open");
  add_action("trap_south","south");
}

int trap_south(string arg) {
  if (!query_door_open()) {
    write("You bang your head off the metal gates.\n");
    return 1;
  }
}

static int open_gate(string arg) {
  int movement;

  if (arg == "gate" || arg = "gate") {
    // If we're already open, don't continue
    if (query_door_open()) {
      write ("The gate is already open.\n");
      return 1;
    }

    // else try and open the door
    movement = random(this_player()->query_str()/2+1)+1;
    set_door_state(movement);

    if ( query_door_open() ) {
      write ("With a final push the gate opens with a sickening screech...\n");
      say("There is a sickening screech as "+capitalize(this_player()->query_real_name())+" opens the gate.\n",this_object()); 

      update_door();
    } else {
      write ("The gate moves slightly, but not enough to get through.\n");
    }
    return 1;
  }
  return 0;
}

int query_door_state() { return "/players/dworkin/mine/start"->query_door_state(); }
int query_door_open()  { return "/players/dworkin/mine/start"->query_door_open(); }
void set_door_state(int s) { return "/players/dworkin/mine/start"->set_door_state(s); }

void update_door() {
  long_desc="The mist swirls around coating everything with a damp glaze. To the northwest, a large red stone building can be seen. To the north, west and east, the cobbled forecourt continues. Southwards, the large iron gates are "+ (query_door_open() ? "open": "closed")+".\n";
}




