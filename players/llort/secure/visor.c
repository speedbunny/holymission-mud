// Mangla: moved because bugs were causing bigs in game.
inherit "/obj/thing";

reset(int arg) {
    ::reset();
}

init() {
    tell_object(this_player(),"This item has been removed from the game.\n");
    destruct(this_object());
}
