

inherit "room/room";
object o1;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/monsters/monk");move_object(o1,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "hut";
    long_desc = 
        "This is the hut of an old monk. He is pretty busy.\n"
        + "You think the hut is too barren for your taste.\n";
items=({"hut","The hut is very barren with only a cot and a dirt floor",
"cot","This is obviously where the monk sleeps at night",
});
    dest_dir = 
        ({
        "players/warlord/road1", "west",
        });
}

init() {
add_action("backstab","backstab");
::init();
}
backstab(str) {
if(str=="monk") {
write("The monk it too wise to be backstabbed. He hits you hard for it.\n");
this_player()->hit_player(100);
return 1;
}
}
