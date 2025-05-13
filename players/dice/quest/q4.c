inherit "room/room";
object branch,branch2;
string tree_desc;
int has_drunk;
reset(arg) {
    if (arg) return;
    tree_desc = "A old tree standing beside the river.\nA branch is hanging on one side";
    set_light(1);
    property = "no_teleport";
    short_desc = "River";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc=
    "You are standing in front of a small river which is flowing here. \n"+
    "The water is crystal clear, and you can see right through it.\n"+
    "At the bottom you see a few fish happily swimming around.\n"+
    "A huge tree is standing near the shore of the river.\n";
    items = ({
      "water","Crystal clear water",
      "river","A small river, the water flows really fast here.\nYou don't think you can swim across",
      "fish","Fish swimming in the river",
      "shore","The shore of the river",
      "tree","@@query_tree_desc@@",
      "branch","A nearly broken branch hanging off the tree",
      "grave","A stinking big grave",
      "bottom","The bottom of the river",
    });

    smell ="The smell is really fresh here.";
}
init(){  
    ::init(); 
    has_drunk = 0;
    add_action("swim","swim"); add_action("swim","dive");
    add_action("swim","jump"); add_action("swim","walk");
    add_action("swim","enter");
    add_action("feel_water","feel");
    add_action("feel_water","touch"); add_action("tear_branch","break");
    add_action("tear_branch","tear"); add_action("tear_branch","pull");
    add_action("tear_branch","get"); add_action("tear_branch","take");
    add_action("drink_water","drink");
    add_action("catch_fish","catch");
    add_action("climb_tree","climb");
}
swim(str){
    if(!str){
	notify_fail("Swim where ?\n");
	return 0;
    }
    if((str=="in river")||(str=="river")||(str=="in water")||(str=="water")){
	write("You jump in the water, not realising that you should first\n"+
	  "have felt how cold the water is.\n"+
	  "You jump out of the water and dry yourself as fast as you can.\n");
	say(this_player()->query_name()+" jumps in and out the water.\n");
	this_player()->hit_player(30,3);
	this_player()->show_hp();
	if(this_player()->query_ghost()){
	    write("You were warned not to jump into the water.\n"+
	      "You feel lousy, and something strange is happening ..\n"+
	      "You are transferred somewhere ....\n");
	    this_player()->move_player("up in the sky#room/church");
	    return 1;
	}
	return 1;
    }
}
feel_water(str){
    if(!str){
	notify_fail("Feel what ??\n");
	return 0;
    }
    if((str=="river")||(str=="water")){
	write("You put you fingers in the water.\n"+
	  "Feeling the terrible cold you decide not to swim across the river.\n");
	say(this_player()->query_name()+" feels the temperature of the water.\n");
	return 1;
    }
}
tear_branch(str){
    if(!str){
	notify_fail("Tear what ?\n");
	return 0;
    }
    if((str=="branch")||(str=="broken branch")||(str=="branch from tree")){
	branch2 = present("dice_branch_2",this_object());
	if(branch||branch2){
	    write("There has already a branch been torn off of the tree.\n"+
	      "You don't want to destroy our whole forest.\n");
	    return 1;
	}
	if(!branch){
	    write("You tear a branch from the tree.\n");
	    say(this_player()->query_name()+" tears off a branch from the tree.\n");
	    branch=clone_object("/players/dice/quest/branch");
	    move_object(branch,this_object());
    items -= ({ "branch", });
	    return 1;
	}
    }
}
drink_water(str){
    if(!str){
	notify_fail("Drink what ?\n");
	return 0;
    }
    if((str=="water")||(str=="water from river")){
	if(has_drunk == 0){
	    write("You bend over and drink from the river.\n"+
	      "The fresh cold water really tastes good.\n");
	    this_player()->heal_self(20);
	    this_player()->show_hp();
	    say(this_player()->query_name()+" drinks from the water.\n");
	    has_drunk = 1;
	    return 1;
	}
	else{
	    write("The water is too cold to drink more.\n");
	    return 1;
	}
    }
}
catch_fish(str){
    if(!str){
	notify_fail("Catch what ?\n");
	return 0;
    }
    if((str=="fish")||(str=="fish from river")){
	write("You reach out and attempt to catch the fish from the river.\n"+
	  "But the fish are too fast for you, and they slip through your\n"+
	  "fingers. The fish return to a safe distance from your fingers.\n");
	return 1;
    }
}
climb_tree(str){
    if(!str){
	notify_fail("Climb where ?\n");
	return 0;
    }
    if((str=="tree")||(str=="huge tree")||(str=="up")){
	write("With great effort you climb up in the tree.\n\n\n\n");
	this_player()->move_player("up in the tree#players/dice/quest/tr1");
	return 1;
    }
}
query_tree_desc() {
    branch2 = present("dice_branch_2",this_object());
    if(branch||branch2){
	return "A huge tree standing next to the river";
    }
    else
	return tree_desc;
}
