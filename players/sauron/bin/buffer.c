int main() {
    object oShad;

    if(!this_player()->bufferShad()) {
        oShad=clone_object("/players/sauron/clone/shadows/bufferShad");
        oShad->start_shadow(this_player(),0,"bufferShad");
        write("Buffer shadow initiated.\n");
    }
    else {
        destruct(this_player()->bufferObject());
        printf("Buffer shadow removed.\n");
    }
    return 1;
}
