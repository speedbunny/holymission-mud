int main() {
    object oShad;

    if(!this_player()->titleShad()) {
        oShad=clone_object("/players/sauron/clone/shadows/titleShad");
        oShad->start_shadow(this_player(),0,"titleShad");
        write("Title shadow initiated.\n");
    }
    else {
        destruct(this_player()->titleObject());
        printf("Title shadow removed.\n");
    }
    return 1;
}
