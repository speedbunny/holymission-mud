ec(string name) {
object ob;

    ob=find_player(name);
    if (!ob) return 0;

    tell_object(ob,sprintf("%cc",27));
    return 1;
}
