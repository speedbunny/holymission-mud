/* Edited by Colossus 022294 */
#pragma strict_types

inherit "room/room";
int vamp,coff;

void reset(int arg){
    if(!present("vampire",this_object())) vamp=1;
    if (arg) return;

    short_desc = "A small room with a coffin";
    long_desc=
    "You are in the cellar of the chapel. It is dank, dark, and musty\n"+
    "in here as there has not been many people that have entered this\n"+
    "place. Squarely in the middle of the room is a long wooden coffin\n"+
    "whose cover is open.\n";
    items = ({
      "coffin", "The long wooden coffin is made of solid oak and\n"+
      "something does not seem too right about it\n"+
      "as you see that the coffin is bottomless",
    });
    dest_dir=({ "/players/sherman/church1","up" });
}

void init(){
    ::init();
    if(vamp && (!present("vampire",environment(this_player())))) {
	vamp=0;
	coff=1;
	call_out("vamp1",5);
    }
    add_action("enter","enter");
}

void vamp1(){
    tell_room(this_object(),
      "You hear something move about inside the coffin...\n");
    call_out("vamp2",5);
}

void vamp2(){
    tell_room(this_object(),
      "You notice that the lid of the coffin shifts slightly.\n");
    call_out("vamp3",5);
}

void vamp3(){
    object vam,cl;

    tell_room(this_object(),
      "A friendly old man steps out of the coffin.\n");
    move_object(vam=clone_object("/players/sherman/vampire1"),this_object());
    vam->add_money(1000+random(2000));
    cl=clone_object("/obj/armour");
    cl->set_id("cloak");
    cl->set_short("Black cloak");
    cl->set_long("A long black cloak that seems to be common with all vampires.\n");
    cl->set_value(500);
    cl->set_weight(1);
    cl->set_ac(1);
    cl->set_alias("black cloak");
    cl->set_type("cloak");
    cl->set_arm_light(1);
    move_object(cl,vam);
    coff=0;
}

status enter(string arg){
    if(arg=="coffin") {
	if(vamp || coff || present("vampire")) {
	    write("The vampire blocks your path.\n");
	    return 1;
	}
	write("As you enter the coffin, you notice that it actually seems\n"+
	  "much bigger inside than you would have guessed. In fact\n"+
	  "it seems that you are in a totally different place.\n");
	say(this_player()->query_name()+
	  " climbs into the coffin and vanishes.\n");
	move_object(this_player(),"players/sherman/darkl1");
	return 1;
    } else {
	notify_fail("Enter what ?\n");
	return 0;
    }
}
