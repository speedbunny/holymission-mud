inherit "obj/player.c";
 
reset(arg) {
    if (arg)
     return;
    set_heart_beat(1);
cap_name = "Bobcat";
msgin = "leaps into the room";
msgout = "leaps out of the room";
    max_hp = 30;
    hit_point = 30;
    level = 3;
    experience = 2500;
    weapon_class = 5;
    armor_class = 0;
    alignment = 200;
    is_npc = 1;
    enable_commands();
}
 
short() { return name;}
 
long() {
 write("A small bobcat\n");
}
 
id(str) {
    return str == name;
}
 
catch_tell(str) {
    string who, what;
}
 
heart_beat()
{
    age += 1;
    attack();
}
