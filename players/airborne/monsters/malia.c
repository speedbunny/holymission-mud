inherit "obj/monster";
object staff;

reset(arg) {
    ::reset(arg);
        if(arg) return 1;
    set_name("malia");
    set_level(12);
    set_al(100);
    set_race("human");
    set_gender(2);
    set_short("Malia the druid");
    set_alias("druid");
    set_long("Malia is a druid of the cats.  She is as worthy as she is pretty.\n" + "With her control over cats she will meet you at any task.\n");
    load_chat(8, ({
       "Malia says: I love my cat!\n",
       "Malia says: Be careful of the rest of them, they aren't that nice.\n"}));
   staff=clone_object("players/airborne/weapons/staff");
   move_object(staff,this_object());
   init_command("wield staff");
}

monster_died(ob) {
    say(""+this_players()->query_name()+" killed Malia.\n");
    return 0;
}

attacked_by(ob){
object cat;
    if(ob && (cat=present("teufel",environment())))
	    cat->attacked_by(ob);
    ::attacked_by(ob);
}
