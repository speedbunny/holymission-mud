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
    short_desc="At the rusted gates";
    long_desc="The thick, cold mist continues to obscure all but the closest objects from view. Directly northwards, two closed rusted gates provide the only access to the fenced off area. Southwards, the access road vanishes into the mist.\n";
    
    // Set up the gate (only when gate_position > GATEMAX will the gates open)

      gate_position = 0;

      items = ({
	"mist", "It swirls and moves like it was alive",
	"gates", "The wrought iron gates, although rusted in parts, still look fairly strong. Standing about 8 feet tall they look like they could repel all but the largest beasts", 
	"gate", "The wrought iron gates, although rusted in parts, still look fairly strong. Standing about 8 feet tall they look like they could repel all but the largest beasts", 
	"fence", "Like the gates, the fence has been made out of wrought iron, and is around 8 feet tall",
      });
    
    dest_dir=({
      "players/dworkin/mine/compound1-0", "north",
      "players/dworkin/startroom", "south"
    });
    
    "/players/dworkin/mine/compound1-0"->update_door();

    //  replace_program("room/room");
}

void init() {
  ::init();
  add_action("open_gate","open");
  add_action("trap_north","north");
}

int trap_north(string arg) {
  if (!query_door_open()) {
    write("You bang your head off the metal gates.\n");
    return 1;
  }
}

static int open_gate(string arg) {
  int movement;

  if (arg == "gate" || arg = "gate") {
    // If we're already open, don't continue
    if (gate_position >= GATEMAX) {
      write ("The gate is already open.\n");
      return 1;
    }

    // else try and open the door
    movement = random(this_player()->query_str()/2+1)+1;
    gate_position += movement;

    if (gate_position >= GATEMAX) {
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

int query_door_state() { return gate_position; }
int query_door_open()  { return gate_position >= GATEMAX; }
void set_door_state(int s) { gate_position+=s; update_door();}

void update_door() {
  long_desc="The thick, cold mist continues to obscure all but the closest objects from view. Directly northwards, two "+ (query_door_open() ? "open" : "closed") +" rusted gates provide the only access to the fenced off area. Southwards, the access road vanishes into the mist.\n";
 "/players/dworkin/mine/compound1-0"->update_door();
}


