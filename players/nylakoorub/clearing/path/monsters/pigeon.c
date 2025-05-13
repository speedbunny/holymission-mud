inherit "obj/monster";

int count;

move_env();

reset(arg) {
    ::reset(arg);
    if (arg) return 1;

    set_name("pigeon");
    set_alt_name("bird");
    set_level(4);
    set_al(10);
    add_money(20);
    set_short("A cute little pigeon");
    set_long("This is a pigeon, which is common to find one of them \n"+
      "in these parts.\n");

    load_chat(5,
      ({
	"The pigeon stops in front of you, stares at you for second, \n"+
	"and then continues on its way.\n",
	"The pigeon walks up to your shoes, stops and looks up to you for \n"+
	"a second and then walks away, leaving a white spot on your shoe.\n",
	"The pigeon walks along the path bobbing its head.\n",
	"The pigeon pecks along the ground looking for food.\n",

      }));

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
      " flies "+
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

