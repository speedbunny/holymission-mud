inherit "obj/monster";

int count;

move_env();

reset(arg) {
    ::reset(arg);
    if (arg) return 1;

    set_name("earthworm");
    set_alt_name("worm");
    set_level(3);
    set_al(10);
    add_money(20);
    set_short("A long, fat Earthworm");
    set_long("This is a big fat long Earthworm, they live deep in the\n"+
      "mud of the Earth.\n");


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
// 6-6-97 Kryll - added check for no dirs in case monster gets
//                into a bugged room with no exits
    if(!dirs) return;
    direction = random(sizeof(dirs)/2);
    tell_room(environment(),"The "+
      this_object()->query_name()+
      " moves "+
      dirs[(direction*2)+1] +
      ".\n");
    move_object(this_object(),dirs[direction*2]);
    room_name = file_name(environment(this_object()));
    room_name = "/" + room_name;
    parts = explode(room_name,"/");
    if(member_array("path",parts) == -1) {
	move_object(this_object(),old_env);
	return 0;
    }
    return 1;
}

init() {
    ::init();
    set_heart_beat(1);
}

