inherit "obj/monster";

reset(arg) {
    ::reset(arg);

    if (!arg) {

	set_name("major");
	set_alt_name("elf");
	set_short("A sad elf");
	set_long("You see the major of the Maria Wichteldorf. He is a thin\n"+
	  "and tall for an elf. He looks very friendly, but sad.\n"+             
	  "You can imagine he has a big problem.\n");
	set_level(20);
	set_gender(1);
	add_money(800);

    }
}

hit_player(dam) {
    if (dam>10) {
	write( "The major parries your attack and laughs at you.\n" );
	return;
    }
    return ::hit_player(dam);
}  

run_away() { return; }

catch_tell(arg) {
    object ob;
    string str1,str2;

    if (sscanf(arg,"%s arrives.",str1)==1) {
	call_out("sulk",2);
	return 1;
    }

    if ((sscanf(arg,"%s gives wolftail to Major.",str1)==1  ) ||  (sscanf(arg,"%s gives tail to Major.",str1)==1 )){
	ob = present("wolftail",this_object() );
	if (ob) {
	    destruct(ob);
	    this_player()->set_quest("starburst_quest");
	    write("The major says: Thank you so much , here are nice bracers as reward.\n");
	    move_object(clone_object("/players/whisky/quest/obj/bracers"),
	      this_player());
	    shout("The Major shouts: Thank you "+
	      this_player()->query_name()+" you have saved our city !!!!\n");

	    very_happy(); 
	}
    }
    else {
	write("The major shrugs helplessly.\n");
	return 1;
    }

    if (sscanf(arg,"%s curtseys %s",str1,str2)==2) {
	write("The major bows at you.\n");
	return 1;
    }
    if (sscanf(arg,"%s bows %s",str1,str2)==2) {
	write("The major bows at you.\n");
	return 1;
    }  
    if (sscanf(arg,"%s waves %s",str1,str2)==2) {
	write("The major waves at you.\n");
	return 1;
    }

    return 1;     
}

sulk() {
    write("The major sighs deeply.\n");
    call_out("sulk1",2);    
}

sulk1() {
    write("The major says: I hate this evil wolf.\n");
    call_out("sulk2",4);    
}

sulk2() {
    write("The major says: I would give nice magic bracers for that one who can bring me it's tail.\n");
}



very_happy() {
    write("The major hugs you.\n");
    call_out("very_happy2",2);
}

very_happy2() {
    write("The major says: Yeah, you got it !\n");
    call_out("very_happy3",3);
}

very_happy3() {
    write("The major flips head over heals !\n");
}
