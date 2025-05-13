inherit "obj/monster";

int count;

move_env();

reset(arg) {
    ::reset(arg);
    if (arg) return 1;

    set_name("gopher");
    set_race("rodent");
    set_level(4);
    set_al(150);
    add_money(40);
    set_short("A furry brown gopher");
    set_long(
      "This a cute little furry brown gopher.\n"
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
      "gopher "+
      "burrows "+
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

