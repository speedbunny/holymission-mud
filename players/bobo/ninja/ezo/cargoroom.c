inherit "/room/room";
#define TP this_player()
#define BOAT "players/tatsuo/ezo/cargoJunk"
object talk;
query_long(){
    return 
    ("You are on a cargo junk. The junk is made of wood and it is in a good\n" +
      "condition. In the middle of the junk can you see the mast with big yards,\n" +
      "great sails and strong shroud. Many sailors are running around and\n" +
      "are busy doing something and at the back of the ship stands the captain.\n"+
      "Cargo Junk is : "+(BOAT->query_boat_environment())->short()+".\n");
    return 1;
}

void reset(int arg){
    if (!talk){
	talk=clone_object("/players/tatsuo/ezo/cargo_talker");
	transfer(talk,this_object());
    }
    if (!arg){
	set_light(1);
	short_desc=("A cargo junk");
	long_desc="@@query_long@@";
	no_obvious_msg="";
	property=({"no_fight"});
	items = ({ "junk", long_desc,
	  "cargo junk", long_desc,
	  "wood", "The wood seems to be in a good condition, too",
	  "ground", "The ground is made of wood",
	  "mast", "It is a massive wooden mast, on which the yards are fixed",
	  "yard", "The yard is made of wood and the sail is fixed on it",
	  "yards", "The yards are mode of wood and the sails are fixed on them",
	  "sail", "The sail is made of cloth and it is dirt-white colored",
	  "sails", "The sails are made of cloth",
	  "cloth", "It seems, that they are very hard to tear",
	  "shroud", "The shroud are made of natureal fibre. They are very thick",
	  "fibre", "One fibre is very tiny, but all in all they are very strong",
	  "sailor", "The sailor is busy running around",
	  "sailors", "The sailors are busy running around",
	  "sea", "Water...water...everywhere and not a drop to drink",
	  "water", "The water is salty",
	});
    }
    ::reset(arg);
}

init(){
    ::init();
    add_action("qdw","qdw");
    add_action("do_leave_boat","leave");
}

int do_leave_boat(string str){
    notify_fail("Leave what?\n");      
    if (BOAT->id(str)){
	if (BOAT->query_is_harbour()){    
	    this_player()->move_player(BOAT->query_name()+"#"
	      +file_name(BOAT->query_boat_environment()));
	    return 1;
	}
	write("You don't dare to leave the junk at the open sea.\n" );
	return 1;                            
    }
}
