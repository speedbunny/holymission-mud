inherit "obj/monster";
object real;

reset(arg){
    ::reset(arg);

    set_name("Moridin");
    set_alias("moridin");
    set_short("Moridin");
    set_long("This is Moridin the leader of the armies of the Dark\n"+
             "one. He looks like a normal man, not that big or strong,\n"+
             "but there is something about his eyes. They seem to have\n"+
             "black spots shooting across them. Something tells you\n"+
             "that running might be a good idea.\n");
    set_number_of_arms(2);
    set_race("darkfriend");
    set_aggressive(1);
    set_level(30);
    set_ac(20);
    set_wc(35);
    set_al(-1000);
    set_dead_ob( this_object() );
}



init () {
    ::init();
    add_action("block","timehold");
    add_action("block","timeburn");
}
block(arg){
    if(query_verb()=="timehold"){
        if(arg== "moridin" ){
    write("Moridin says: Did you really think that would work on me?\n");
	    return 1;
	}
    }
    if(query_verb()=="timeburn"){
        if(arg== "moridin" ){
     write("Moridin says: Nice trick, but I already know that one!\n");
	    return 1;
	}
    }
}


int monster_died(object ob) {
    write("Moridin falls to the ground and a small ball of light\n"+
          "shoots out of his body. The ball flies right into your\n"+
          "chest. You can feel it attach itself to your very reality!\n"+
          "The Cronus Sphere pulls you back threw time!\n");
    move_object(clone_object(
        "/players/akira/weapons/real"),
       this_player());
this_player()->move_player("up#players/akira/area/vault1");
    return 0;
}
