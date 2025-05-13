inherit "obj/monster";

int count;

move_env();

reset(arg) {
    ::reset(arg);
    if (arg) return 1;

    set_name("ferret");
    set_level(3);
    set_dex(6);
    set_al(50);
    add_money(30);
    set_short("A cunning little ferret");
    set_long(
      "A ferret is a skinny looking creature.  It has cunny like \n"+
      "wits, so keep on yours on your inventory.\n"
    );


}
heart_beat() {
    if(++count>24) {
	move_env();
	count = 0;
    }
    return ::heart_beat();
}

move_env() {
    string *dirs;
    int direction;
    object old_env;
    string room_name,*parts;
    old_env = environment(this_object());
    dirs = environment()->query_dest_dirs();
    direction = random(sizeof(dirs)/2);
    tell_room(environment(),"The "+
      "ferret "+
      "sneaks "+
      dirs[(direction*2)+1] +
      ".\n");
    move_object(this_object(),dirs[direction*2]);
    room_name = file_name(environment(this_object()));
    room_name = "/" + room_name;
    parts = explode(room_name,"/");
    if(member_array("clearing",parts) == -1) {
	move_object(this_object(),old_env);
	return 0;
    }
    return 1;
}

init() {
    ::init();
    set_heart_beat(1);
}

