// Mangla: moved because bugs were causing bigs in game.
inherit "/obj/thing";

_remove() {
    tell_object(this_player(),"Qmunicator is removed from the game.\n");
    destruct(this_object());
    return;
}

reset(int arg) {
    ::reset();
}

init() {
    call_out("_remove",5);
}
