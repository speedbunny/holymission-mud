#define PPATH "/players/patience/smilequest/"
inherit "room/room";
object *rat, shoes;

reset(arg) {
    if (!rat) {
	rat=clone_object("obj/monster");
	rat->set_name("rat");
	rat->set_alt_name("brown rat");
	rat->set_short("A little brown rat");
	rat->set_long("You see a little, sweet brown rat.\n");
	rat->set_level(2);
	rat->set_whimpy(90);
	rat->set_aggressive(1);
	move_object(rat,this_object());
    }
    if ( !shoes ) {
	shoes = clone_object( PPATH + "shoes" );
	move_object( shoes, this_object() );
    }

    ::reset(arg);

    if (arg) return;

    smell="The air smells very fouly here !";
    set_light(-1);
    short_desc="In a dark cellar";
    long_desc=
    "You are in the the dark cellar of the castle of sadness.\n"+
    "It's cold and wet. The vault smells a bit after bad wood.\n"+
    "There is a small corridor leading further to the east.\n";
    items = ({
      "corridor","You see a small dark corridor, leading to the east",
      "bottom","You see a oak-wooden bottom",
      "walls","You see dark brick-walls",
      "vault","You see an oak-wooden vault",
      "wood","You see just oak-wood",
    });

    dest_dir = ({
      PPATH+"cellar2","east",
    });


}

init() {
    if (present("rat",this_object())) {
      if(find_call_out("run_rat")== -1)
	call_out("run_rat",10);
    }
    add_action("search","search");
    ::init();
}

search(arg) {

    if (!arg) 
	return;
    write("You search and search, but find nothing.\n");
    say(this_player()->query_name()+" searches around.\n");
    return 1;
} 

run_rat() {
   if( rat && present("rat", this_object()) )
    rat->run_away();
}


